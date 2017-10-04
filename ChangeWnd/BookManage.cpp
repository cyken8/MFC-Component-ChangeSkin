// BookManage.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeWnd.h"
#include "BookManage.h"

#include "AddBookInfo.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookManage dialog


CBookManage::CBookManage(CWnd* pParent /*=NULL*/)
	: CDialog(CBookManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBookManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookManage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookManage, CDialog)
	//{{AFX_MSG_MAP(CBookManage)
	ON_BN_CLICKED(ID_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookManage message handlers

void CBookManage::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CAddBookInfo bookInfo;
	bookInfo.DoModal();
}
