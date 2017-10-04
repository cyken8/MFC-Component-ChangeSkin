// DrawEdit.h: interface for the CDrawEdit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWEDIT_H__F7D165F7_2177_422D_B6B6_CF50D2D0C214__INCLUDED_)
#define AFX_DRAWEDIT_H__F7D165F7_2177_422D_B6B6_CF50D2D0C214__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//用于关联每一个编辑框控件,CDrawEdit类的主要作用是提供CtrlColor方法绘制编辑框的绿色边框
class CDrawEdit  
{
public:
	WNDPROC m_OldProc;			//记录编辑框的窗口函数
	int m_Flag;					
public:
	HBRUSH CtlColor(HWND hWnd,HDC hDC,UINT nCtlColor);
	CDrawEdit();
	virtual ~CDrawEdit();

};



#endif // !defined(AFX_DRAWEDIT_H__F7D165F7_2177_422D_B6B6_CF50D2D0C214__INCLUDED_)
