// YahtzeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "YahtzeeDlg.h"
#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYahtzeeDlg dialog


CYahtzeeDlg::CYahtzeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CYahtzeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYahtzeeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	NewFont.CreateFont(130, 0, 0, 0, 900, 0, 0, 0, 0, 
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, "Courier");
}


void CYahtzeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYahtzeeDlg)
	DDX_Control(pDX, IDC_YAHTZEE, m_Yahtzee);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CYahtzeeDlg, CDialog)
	//{{AFX_MSG_MAP(CYahtzeeDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYahtzeeDlg message handlers

BOOL CYahtzeeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_Yahtzee.SetFont(&NewFont, TRUE);
	m_Yahtzee.SetWindowText("");
	SetTimer(3, 300, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CYahtzeeDlg::OnTimer(UINT nIDEvent) 
{
	if (m_Display)	
	{
		m_Yahtzee.SetWindowText("Yahtzee!");
	}
	else
	{
		m_Yahtzee.SetWindowText("");
	}
	m_Display = !m_Display;

	CDialog::OnTimer(nIDEvent);
}

