// DrawDialog.h: interface for the CDrawDialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWDIALOG_H__1E7749DD_BEF9_4BC5_86BA_26B0BD9D4DE4__INCLUDED_)
#define AFX_DRAWDIALOG_H__1E7749DD_BEF9_4BC5_86BA_26B0BD9D4DE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000




#define fLeftBand     1
#define fLeftTitle    2
#define fRightTitle   4
#define fMidTitle     8
#define fRightBand    16
#define fBottomBand   32
#define fLeftBottom   64
#define fRightBottom  128
#define fMinButton    256
#define fMaxButton    512
#define fCloseButton  1024
#define fAll          2047


class CDrawDialog  
{
public:
	enum CButtonState{bsNone,bsIni,bsMin,bsMax,bsRes,bsClose};

public:
	WNDPROC		m_OldProc;			//记录窗口函数
	int			m_Flag;		
	CButtonState m_ButtonState;		//按钮状态
	BOOL m_IsMax;					//是否处于最大化状态
	CRect		m_IniRect,m_MinRect,m_MaxRect,m_CloseRect;//标题栏按钮的显示区域
	CRect		m_LTitleRc,m_MTitleRc,m_RTitleRc;			//左中右标题显示区域
	BOOL		m_IsDrawForm;		//是否需要绘制窗体
	int       m_TitleDrawHeight;	//标题栏实际的绘制高度
	int       m_BorderWidth;		//边框宽度
	int       m_BorderHeight;		//边框高度
	int       m_FrameWidth ;		//窗体3D宽度
	int       m_FrameHeight;		//窗体3D高度
	int       m_CaptionHeight;		//标题栏的高度
	CString   m_Caption;			//窗口标题
	COLORREF  m_CaptionColor;		//标题字体颜色
	CFont     m_CaptionFont;		//标题字体
	int       m_ButtonWidth;		//按钮位图宽度
	int       m_ButtonHeight;		//按钮位图高度
	CRgn      WndRgn,ClipRgn;		//创建显示和剪辑区域
	TCHAR		m_Text[MAX_PATH];	//记录控件文本
	BOOL		m_bGetText;			//是否已经获取了文本
	CBitmap		m_Bk;
	static BOOL	m_bFlushBk;			//是否需要刷新背景
public:
	void OnEraseBkgnd(HWND hWnd);
	void OnCtlColor(HWND hWnd);
	void SetDlgZone(HWND hWnd);
	void OnSize(HWND hWnd,UINT nType, int cx, int cy);
	void OnNcPaint(HWND hWnd);
	void OnNcLButtonDown(HWND hWnd,UINT nHitTest,CPoint  point);
	BOOL OnNcActivate(HWND hWnd,BOOL bActive);
	void OnNcMouseMove(HWND hWnd,UINT nHitTest, CPoint point) ;

	void OnPaint(HWND hWnd);
	void SkinDialog(HWND hWnd,UINT Flags=fAll);
	void OnMouseMove(HWND hWnd,UINT nFlags,CPoint point);
	void DrawDialogText(HWND hWnd);
	CDrawDialog();
	virtual ~CDrawDialog();

};




#endif // !defined(AFX_DRAWDIALOG_H__1E7749DD_BEF9_4BC5_86BA_26B0BD9D4DE4__INCLUDED_)
