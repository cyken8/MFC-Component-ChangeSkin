#if !defined(AFX_ADDBOOKINFO_H__80DA67CC_AE4E_40ED_80E4_4425270CC151__INCLUDED_)
#define AFX_ADDBOOKINFO_H__80DA67CC_AE4E_40ED_80E4_4425270CC151__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddBookInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddBookInfo dialog

class CAddBookInfo : public CDialog
{
// Construction
public:
	CAddBookInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddBookInfo)
	enum { IDD = IDD_INPUTINFODLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddBookInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddBookInfo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDBOOKINFO_H__80DA67CC_AE4E_40ED_80E4_4425270CC151__INCLUDED_)
