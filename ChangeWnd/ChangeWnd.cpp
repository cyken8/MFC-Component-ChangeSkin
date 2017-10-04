// ChangeWnd.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ChangeWnd.h"
#include "ChangeWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangeWndApp

BEGIN_MESSAGE_MAP(CChangeWndApp, CWinApp)
	//{{AFX_MSG_MAP(CChangeWndApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeWndApp construction

CChangeWndApp::CChangeWndApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CChangeWndApp object

CChangeWndApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CChangeWndApp initialization

BOOL CChangeWndApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	hMod = LoadLibrary(_T("../WndDll/Debug/WndDll.dll"));
	if(hMod)
	{
		//获取动态链接库中的RunHook函数地址
		RunHook=(funRunHook)GetProcAddress(hMod,_T("RunHook"));
		BOOL bRect=RunHook(0,GetCurrentThreadId());	//安装钩子

	}
	CChangeWndDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CChangeWndApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(hMod)
	{
		//获取动态链接库中的StopHook函数地址
		StopHook=(funStopHook)GetProcAddress(hMod,_T("StopHook"));
		StopHook();		//卸载钩子
	}
	FreeLibrary(hMod);
	return CWinApp::ExitInstance();
}
