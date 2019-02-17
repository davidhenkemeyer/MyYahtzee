#if !defined(AFX_HIGHSCOREDLG_H__C03CD001_E352_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_HIGHSCOREDLG_H__C03CD001_E352_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HighScoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHighScoreDlg dialog

class CHighScoreDlg : public CDialog
{
// Construction
public:
	BOOL m_PlaySound;
	int m_Score;
	CHighScoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHighScoreDlg)
	enum { IDD = IDD_HIGHSCORE };
	CStatic	m_ScoreCtrl;
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHighScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHighScoreDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIGHSCOREDLG_H__C03CD001_E352_11D2_8916_00A0C9F74786__INCLUDED_)
