#if !defined(AFX_READONLYEDITCTRL_H__B48AA0A0_E20A_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_READONLYEDITCTRL_H__B48AA0A0_E20A_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReadOnlyEditCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReadOnlyEditCtrl window

class CReadOnlyEditCtrl : public CEdit
{
// Construction
public:
	CReadOnlyEditCtrl();
	HCURSOR m_hCursor;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReadOnlyEditCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CReadOnlyEditCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CReadOnlyEditCtrl)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_READONLYEDITCTRL_H__B48AA0A0_E20A_11D2_8916_00A0C9F74786__INCLUDED_)
