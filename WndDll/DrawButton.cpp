// DrawButton.cpp: implementation of the CDrawButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WndDll.h"
#include "DrawButton.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int CDrawButton::m_Style=1;//可修改为1，按钮背景会改变


CDrawButton::CDrawButton()
{
	m_State=bsNormal;
	m_OldProc=NULL;
	m_Flag=0;
}

CDrawButton::~CDrawButton()
{
	m_State=bsNormal;
	m_OldProc=NULL;
}

LRESULT CDrawButton::OnPaint(HWND hWnd)
{
	CWnd* pWnd=CWnd::FromHandle(hWnd);
	CPaintDC	dc(pWnd);
	CString		Text;
	CRect		RC;
	CFont*		pOldFont;
	CFont		Font;
	CBrush		Brush;
	CBrush*		pOldBrush;
	CPoint		PT(2,2);
	
	dc.SetBkMode(TRANSPARENT);
	Font.CreateFont( 12, 0, 0, 0, FW_HEAVY, 0, 0, 0, ANSI_CHARSET, \
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, \
		VARIABLE_PITCH | FF_SWISS, "MS Sans Serif" );

	pOldFont=dc.SelectObject(&Font);
	if(m_State==bsNormal)
	{
		if(m_Style==2)
		{
			CBitmap bmp;
			bmp.LoadBitmap(IDB_BKBUTTON);
			Brush.CreatePatternBrush(&bmp);
		}
		else
			Brush.CreateSolidBrush(RGB(200,200,200));
		dc.SetTextColor(RGB(80,80,80));
	}
	else if(m_State==bsDown)
	{
		Brush.CreateSolidBrush( RGB( 160, 160, 160 ) );
		dc.SetTextColor( RGB( 50, 50, 250 ) );
	}
	else if(m_State==bsHot)
	{
		Brush.CreateSolidBrush( RGB( 100, 100, 180 ) );
		dc.SetTextColor( RGB( 250, 250, 0 ) );
	}
	pOldBrush=dc.SelectObject(&Brush);
	pWnd->GetClientRect(&RC);
	dc.RoundRect(&RC,PT);

	//设置按钮形状为圆角矩形
	HRGN hRgn=CreateRectRgn(RC.left,RC.top,RC.right,RC.bottom);
	pWnd->SetWindowRgn(hRgn,TRUE);
	DeleteObject(hRgn);

	pWnd->GetWindowText(Text);
	dc.DrawText(Text,&RC,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

	dc.SelectObject(pOldFont);
	dc.SelectObject(pOldBrush);
	return TRUE;
}

LRESULT CDrawButton::OnLButtonDown(HWND hWnd, UINT nFlags, CPoint point)
{
	m_State=bsDown;
	SetCapture(hWnd);
	SetFocus(hWnd);
	return TRUE;
}


LRESULT CDrawButton::OnLButtonUp(HWND hWnd, UINT nFlags, CPoint point)
{
	if(m_State!=bsNormal)
	{
		m_State=bsNormal;
		ReleaseCapture();
		InvalidateRect(hWnd,NULL,TRUE);
		SendMessage(GetParent(hWnd),WM_COMMAND,GetDlgCtrlID(hWnd),(LPARAM)hWnd);
	}
	return TRUE;
}

LRESULT CDrawButton::LoseFocus(HWND hWnd)
{
	m_State=bsNormal;
	InvalidateRect(hWnd,NULL,TRUE);
	SendMessage(hWnd,WM_KILLFOCUS,(long)hWnd,0);
	return TRUE;
}



LRESULT CDrawButton::OnMouseMove(HWND hWnd, UINT nFlags, CPoint point)
{
	HRGN hRgn=CreateRectRgn(0,0,0,0);
	GetWindowRgn(hWnd,hRgn);
	BOOL ret=PtInRegion(hRgn,point.x,point.y);
	if(ret)
	{
		if(m_State==bsDown)
			return TRUE;
		if(m_State!=bsHot)
		{
			m_State=bsHot;
			InvalidateRect(hWnd,NULL,TRUE);
			UpdateWindow(hWnd);
			SetCapture(hWnd);
		}
	}
	else
	{
		m_State=bsNormal;
		InvalidateRect(hWnd,NULL,TRUE);
		ReleaseCapture();
	}
	DeleteObject(hRgn);
	return TRUE;
}



