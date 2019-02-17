// MyEditCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "MyYahtzeeDlg.h"
#include "MyEditCtrl.h"
#include <mmsystem.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEditCtrl

CMyEditCtrl::CMyEditCtrl()
{
	m_hCursor = AfxGetApp()->LoadCursor(IDC_PENCIL);
}

CMyEditCtrl::~CMyEditCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyEditCtrl, CEdit)
	//{{AFX_MSG_MAP(CMyEditCtrl)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEditCtrl message handlers

BOOL CMyEditCtrl::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (((CMyYahtzeeDlg *)GetParent())->m_Scoring)
		::SetCursor(m_hCursor);
	return TRUE;
}

void CMyEditCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (((CMyYahtzeeDlg *)GetParent())->m_Scoring)
	{
		((CMyYahtzeeDlg *)GetParent())->pUndoCtrl = this;
		if (((CMyYahtzeeDlg *)GetParent())->m_SettingsDlg.m_Score)
			PlaySound("Click.wav", NULL, SND_ASYNC);
		CEdit::OnLButtonDown(nFlags, point);
	}
}

void CMyEditCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
}
