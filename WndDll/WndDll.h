// WndDll.h : main header file for the WNDDLL DLL
//

#if !defined(AFX_WNDDLL_H__E4D586F1_4634_4D52_A468_522296CBA403__INCLUDED_)
#define AFX_WNDDLL_H__E4D586F1_4634_4D52_A468_522296CBA403__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWndDllApp
// See WndDll.cpp for the implementation of this class
//

class CWndDllApp : public CWinApp
{
public:
	CWndDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWndDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CWndDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WNDDLL_H__E4D586F1_4634_4D52_A468_522296CBA403__INCLUDED_)
