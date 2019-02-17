#if !defined(AFX_HIGHSCORESHEETDLG_H__C03CD007_E352_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_HIGHSCORESHEETDLG_H__C03CD007_E352_11D2_8916_00A0C9F74786__INCLUDED_

#include "HighScoreSheet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HighScoreSheetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHighScoreSheetDlg dialog

class CHighScoreSheetDlg : public CDialog
{
// Construction
public:
	void UpdateScores();
	CHighScoreSheet *m_pHighScoreSheet;
	CHighScoreSheetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHighScoreSheetDlg)
	enum { IDD = IDD_HIGHSCORESHEET };
	CStatic	m_Score;
	CStatic	m_PlayerName;
	CStatic	m_Date;
	CString	m_Date1;
	CString	m_Date10;
	CString	m_Date2;
	CString	m_Date3;
	CString	m_Date4;
	CString	m_Date5;
	CString	m_Date6;
	CString	m_Date7;
	CString	m_Date8;
	CString	m_Date9;
	CString	m_Player1;
	CString	m_Player10;
	CString	m_Player2;
	CString	m_Player3;
	CString	m_Player4;
	CString	m_Player5;
	CString	m_Player6;
	CString	m_Player7;
	CString	m_Player8;
	CString	m_Player9;
	CString	m_Score1;
	CString	m_Score10;
	CString	m_Score2;
	CString	m_Score3;
	CString	m_Score4;
	CString	m_Score5;
	CString	m_Score6;
	CString	m_Score7;
	CString	m_Score8;
	CString	m_Score9;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHighScoreSheetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHighScoreSheetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont NewFont;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIGHSCORESHEETDLG_H__C03CD007_E352_11D2_8916_00A0C9F74786__INCLUDED_)
