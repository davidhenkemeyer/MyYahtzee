// ReadOnlyEditCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "ReadOnlyEditCtrl.h"
#include "MyYahtzeeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReadOnlyEditCtrl

CReadOnlyEditCtrl::CReadOnlyEditCtrl()
{
}

CReadOnlyEditCtrl::~CReadOnlyEditCtrl()
{
}


BEGIN_MESSAGE_MAP(CReadOnlyEditCtrl, CEdit)
	//{{AFX_MSG_MAP(CReadOnlyEditCtrl)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadOnlyEditCtrl message handlers

BOOL CReadOnlyEditCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	//::SetCursor(m_hCursor);
	return TRUE;
}

void CReadOnlyEditCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (((CMyYahtzeeDlg *)GetParent())->m_Scoring)
		CEdit::OnLButtonDown(nFlags, point);
}

void CReadOnlyEditCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
}
