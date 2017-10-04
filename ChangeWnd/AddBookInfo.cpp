// AddBookInfo.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeWnd.h"
#include "AddBookInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddBookInfo dialog


CAddBookInfo::CAddBookInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CAddBookInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddBookInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAddBookInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddBookInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddBookInfo, CDialog)
	//{{AFX_MSG_MAP(CAddBookInfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddBookInfo message handlers
