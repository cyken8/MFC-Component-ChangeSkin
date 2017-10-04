// DrawButton.h: interface for the CDrawButton class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWBUTTON_H__4D44D86B_EEC9_4106_87C3_FD330A15FC0C__INCLUDED_)
#define AFX_DRAWBUTTON_H__4D44D86B_EEC9_4106_87C3_FD330A15FC0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawButton  
{
	enum ButtonState{bsNormal,bsHot,bsDown};
public:
	ButtonState m_State;	//按钮当前的状态
	WNDPROC		m_OldProc;	//记录按钮的窗口函数
	int			m_Flag;		//是否释放关联按钮的CDrawButton对象
	static int	m_Style;	//按钮风格
public:
	LRESULT OnMouseMove(HWND hWnd,UINT nFlags,CPoint point);
	LRESULT LoseFocus(HWND hWnd);
	LRESULT OnLButtonUp(HWND hWnd,UINT nFlags,CPoint point);
	LRESULT OnLButtonDown(HWND hWnd,UINT nFlags,CPoint  point);
	LRESULT OnPaint(HWND hWnd);
	CDrawButton();
	virtual ~CDrawButton();

};




#endif // !defined(AFX_DRAWBUTTON_H__4D44D86B_EEC9_4106_87C3_FD330A15FC0C__INCLUDED_)
