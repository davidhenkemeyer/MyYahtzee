// HighScoreSheetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "HighScoreSheetDlg.h"
#include "HighScoreSheetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHighScoreSheetDlg dialog


CHighScoreSheetDlg::CHighScoreSheetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHighScoreSheetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHighScoreSheetDlg)
	m_Date1 = _T("");
	m_Date10 = _T("");
	m_Date2 = _T("");
	m_Date3 = _T("");
	m_Date4 = _T("");
	m_Date5 = _T("");
	m_Date6 = _T("");
	m_Date7 = _T("");
	m_Date8 = _T("");
	m_Date9 = _T("");
	m_Player1 = _T("");
	m_Player10 = _T("");
	m_Player2 = _T("");
	m_Player3 = _T("");
	m_Player4 = _T("");
	m_Player5 = _T("");
	m_Player6 = _T("");
	m_Player7 = _T("");
	m_Player8 = _T("");
	m_Player9 = _T("");
	m_Score1 = _T("");
	m_Score10 = _T("");
	m_Score2 = _T("");
	m_Score3 = _T("");
	m_Score4 = _T("");
	m_Score5 = _T("");
	m_Score6 = _T("");
	m_Score7 = _T("");
	m_Score8 = _T("");
	m_Score9 = _T("");
	//}}AFX_DATA_INIT
}


void CHighScoreSheetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHighScoreSheetDlg)
	DDX_Control(pDX, IDC_SCORE, m_Score);
	DDX_Control(pDX, IDC_PLAYERNAME, m_PlayerName);
	DDX_Control(pDX, IDC_DATE, m_Date);
	DDX_Text(pDX, IDC_DATE1, m_Date1);
	DDX_Text(pDX, IDC_DATE10, m_Date10);
	DDX_Text(pDX, IDC_DATE2, m_Date2);
	DDX_Text(pDX, IDC_DATE3, m_Date3);
	DDX_Text(pDX, IDC_DATE4, m_Date4);
	DDX_Text(pDX, IDC_DATE5, m_Date5);
	DDX_Text(pDX, IDC_DATE6, m_Date6);
	DDX_Text(pDX, IDC_DATE7, m_Date7);
	DDX_Text(pDX, IDC_DATE8, m_Date8);
	DDX_Text(pDX, IDC_DATE9, m_Date9);
	DDX_Text(pDX, IDC_PLAYER1, m_Player1);
	DDX_Text(pDX, IDC_PLAYER10, m_Player10);
	DDX_Text(pDX, IDC_PLAYER2, m_Player2);
	DDX_Text(pDX, IDC_PLAYER3, m_Player3);
	DDX_Text(pDX, IDC_PLAYER4, m_Player4);
	DDX_Text(pDX, IDC_PLAYER5, m_Player5);
	DDX_Text(pDX, IDC_PLAYER6, m_Player6);
	DDX_Text(pDX, IDC_PLAYER7, m_Player7);
	DDX_Text(pDX, IDC_PLAYER8, m_Player8);
	DDX_Text(pDX, IDC_PLAYER9, m_Player9);
	DDX_Text(pDX, IDC_SCORE1, m_Score1);
	DDX_Text(pDX, IDC_SCORE10, m_Score10);
	DDX_Text(pDX, IDC_SCORE2, m_Score2);
	DDX_Text(pDX, IDC_SCORE3, m_Score3);
	DDX_Text(pDX, IDC_SCORE4, m_Score4);
	DDX_Text(pDX, IDC_SCORE5, m_Score5);
	DDX_Text(pDX, IDC_SCORE6, m_Score6);
	DDX_Text(pDX, IDC_SCORE7, m_Score7);
	DDX_Text(pDX, IDC_SCORE8, m_Score8);
	DDX_Text(pDX, IDC_SCORE9, m_Score9);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHighScoreSheetDlg, CDialog)
	//{{AFX_MSG_MAP(CHighScoreSheetDlg)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHighScoreSheetDlg message handlers

BOOL CHighScoreSheetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	NewFont.CreateFont(16, 0, 0, 0, 600, 0, 1, 0, 0, 
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, 
		DEFAULT_PITCH | FF_DONTCARE, "Arial");
	m_PlayerName.SetFont(&NewFont);
	m_Score.SetFont(&NewFont);
	m_Date.SetFont(&NewFont);
	
	UpdateScores();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CHighScoreSheetDlg::OnClear() 
{
	if (MessageBox("Are you sure you wish to clear the high scores?", "Clear?", MB_YESNO) == IDYES)
		m_pHighScoreSheet->Clear();	

	UpdateScores();
}

void CHighScoreSheetDlg::UpdateScores()
{
	m_Player1 = m_pHighScoreSheet->m_Scores[0].m_Name;
	m_Player2 = m_pHighScoreSheet->m_Scores[1].m_Name;
	m_Player3 = m_pHighScoreSheet->m_Scores[2].m_Name;
	m_Player4 = m_pHighScoreSheet->m_Scores[3].m_Name;
	m_Player5 = m_pHighScoreSheet->m_Scores[4].m_Name;
	m_Player6 = m_pHighScoreSheet->m_Scores[5].m_Name;
	m_Player7 = m_pHighScoreSheet->m_Scores[6].m_Name;
	m_Player8 = m_pHighScoreSheet->m_Scores[7].m_Name;
	m_Player9 = m_pHighScoreSheet->m_Scores[8].m_Name;
	m_Player10 = m_pHighScoreSheet->m_Scores[9].m_Name;

	m_Score1.Format("%d", m_pHighScoreSheet->m_Scores[0].m_Score);
	m_Score2.Format("%d", m_pHighScoreSheet->m_Scores[1].m_Score);
	m_Score3.Format("%d", m_pHighScoreSheet->m_Scores[2].m_Score);
	m_Score4.Format("%d", m_pHighScoreSheet->m_Scores[3].m_Score);
	m_Score5.Format("%d", m_pHighScoreSheet->m_Scores[4].m_Score);
	m_Score6.Format("%d", m_pHighScoreSheet->m_Scores[5].m_Score);
	m_Score7.Format("%d", m_pHighScoreSheet->m_Scores[6].m_Score);
	m_Score8.Format("%d", m_pHighScoreSheet->m_Scores[7].m_Score);
	m_Score9.Format("%d", m_pHighScoreSheet->m_Scores[8].m_Score);
	m_Score10.Format("%d", m_pHighScoreSheet->m_Scores[9].m_Score);

	m_Date1 = m_pHighScoreSheet->m_Scores[0].m_Date;
	m_Date2 = m_pHighScoreSheet->m_Scores[1].m_Date;
	m_Date3 = m_pHighScoreSheet->m_Scores[2].m_Date;
	m_Date4 = m_pHighScoreSheet->m_Scores[3].m_Date;
	m_Date5 = m_pHighScoreSheet->m_Scores[4].m_Date;
	m_Date6 = m_pHighScoreSheet->m_Scores[5].m_Date;
	m_Date7 = m_pHighScoreSheet->m_Scores[6].m_Date;
	m_Date8 = m_pHighScoreSheet->m_Scores[7].m_Date;
	m_Date9 = m_pHighScoreSheet->m_Scores[8].m_Date;
	m_Date10 = m_pHighScoreSheet->m_Scores[9].m_Date;

	UpdateData(FALSE);
}
