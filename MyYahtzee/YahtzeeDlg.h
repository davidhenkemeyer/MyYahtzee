#if !defined(AFX_YAHTZEEDLG_H__E2EDB280_E2CC_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_YAHTZEEDLG_H__E2EDB280_E2CC_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YahtzeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CYahtzeeDlg dialog

class CYahtzeeDlg : public CDialog
{
// Construction
public:
	DWORD m_NumYahtzees;
	BOOL m_Display;
	CFont NewFont;
	CYahtzeeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CYahtzeeDlg)
	enum { IDD = IDD_YAHTZEE };
	CStatic	m_Yahtzee;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYahtzeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CYahtzeeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YAHTZEEDLG_H__E2EDB280_E2CC_11D2_8916_00A0C9F74786__INCLUDED_)
