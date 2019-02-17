#if !defined(AFX_MYEDITCTRL_H__93371CCE_E1F7_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_MYEDITCTRL_H__93371CCE_E1F7_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyEditCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyEditCtrl window

class CMyEditCtrl : public CEdit
{
// Construction
public:
	CMyEditCtrl();
	HCURSOR m_hCursor;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyEditCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyEditCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyEditCtrl)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYEDITCTRL_H__93371CCE_E1F7_11D2_8916_00A0C9F74786__INCLUDED_)
