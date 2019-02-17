// HighScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "HighScoreDlg.h"
#include <mmsystem.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHighScoreDlg dialog


CHighScoreDlg::CHighScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHighScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHighScoreDlg)
	m_Name = _T("");
	//}}AFX_DATA_INIT
}


void CHighScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHighScoreDlg)
	DDX_Control(pDX, IDC_SCORE, m_ScoreCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHighScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CHighScoreDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHighScoreDlg message handlers

BOOL CHighScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString sc;
	sc.Format("%d", m_Score);
	m_ScoreCtrl.SetWindowText(sc);
	if (m_PlaySound)
	{
		theApp.PlayRandomSound("HiScore");
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
