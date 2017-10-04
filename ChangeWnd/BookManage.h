#if !defined(AFX_BOOKMANAGE_H__54E67BA5_A30B_4FDE_86B2_9E4CE4D83746__INCLUDED_)
#define AFX_BOOKMANAGE_H__54E67BA5_A30B_4FDE_86B2_9E4CE4D83746__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookManage dialog

class CBookManage : public CDialog
{
// Construction
public:
	CBookManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBookManage)
	enum { IDD = IDD_BOOKINFOADDDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookManage)
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKMANAGE_H__54E67BA5_A30B_4FDE_86B2_9E4CE4D83746__INCLUDED_)
