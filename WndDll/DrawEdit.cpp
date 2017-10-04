// DrawEdit.cpp: implementation of the CDrawEdit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WndDll.h"
#include "DrawEdit.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDrawEdit::CDrawEdit()
{
	m_OldProc=NULL;
	m_Flag=0;
}

CDrawEdit::~CDrawEdit()
{

}

HBRUSH CDrawEdit::CtlColor(HWND hWnd, HDC hDC, UINT nCtlColor)
{
	CDC* dc=CDC::FromHandle(hDC);
	CRect rect;
	::GetClientRect(hWnd,rect);
	rect.InflateRect(1,1,1,1);	//将客户区增大一个像素
	CPen pen(PS_SOLID,1,RGB(0,255,0));
	dc->SelectObject(&pen);
	CBrush brush(RGB(0,255,0));
	dc->FrameRect(rect,&brush);	//绘制边框
	return brush;
}



