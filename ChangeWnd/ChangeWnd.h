// ChangeWnd.h : main header file for the CHANGEWND application
//

#if !defined(AFX_CHANGEWND_H__88C04470_BC00_4DBE_BD48_507F5D9FE603__INCLUDED_)
#define AFX_CHANGEWND_H__88C04470_BC00_4DBE_BD48_507F5D9FE603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CChangeWndApp:
// See ChangeWnd.cpp for the implementation of this class
//
typedef BOOL (__stdcall *funRunHook)(HMODULE hModule,DWORD dwThreadID);
typedef BOOL (__stdcall *funStopHook)();

class CChangeWndApp : public CWinApp
{
public:
	funRunHook RunHook;	//定义函数指针
	funStopHook StopHook;
	HMODULE hMod;		//定义动态链接库实例句柄
public:
	CChangeWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeWndApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CChangeWndApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEWND_H__88C04470_BC00_4DBE_BD48_507F5D9FE603__INCLUDED_)
