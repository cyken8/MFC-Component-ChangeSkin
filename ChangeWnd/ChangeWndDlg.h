// ChangeWndDlg.h : header file
//

#if !defined(AFX_CHANGEWNDDLG_H__646048A8_0D81_4927_AEBD_297AA901E8B6__INCLUDED_)
#define AFX_CHANGEWNDDLG_H__646048A8_0D81_4927_AEBD_297AA901E8B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeWndDlg dialog

class CChangeWndDlg : public CDialog
{
// Construction
public:
	CChangeWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChangeWndDlg)
	enum { IDD = IDD_CHANGEWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGEWNDDLG_H__646048A8_0D81_4927_AEBD_297AA901E8B6__INCLUDED_)
