// SettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "SettingsDlg.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingsDlg dialog


CSettingsDlg::CSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingsDlg)
	m_DiceRoll = TRUE;
	m_Exit = TRUE;
	m_HiScore = TRUE;
	m_Score = TRUE;
	m_Yahtzee = TRUE;
	//}}AFX_DATA_INIT
}


void CSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingsDlg)
	DDX_Check(pDX, IDC_DICEROLLSOUND, m_DiceRoll);
	DDX_Check(pDX, IDC_EXITSOUND, m_Exit);
	DDX_Check(pDX, IDC_HIGHSCORESOUND, m_HiScore);
	DDX_Check(pDX, IDC_SCORESOUND, m_Score);
	DDX_Check(pDX, IDC_YAHTZEESOUND, m_Yahtzee);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSettingsDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingsDlg message handlers

void CSettingsDlg::OnOK() 
{
	UpdateData(TRUE);

	CRegKey regKey;
	regKey.Open(HKEY_LOCAL_MACHINE, "Software\\Henkemeyer Software\\Triple Yahztee", TRUE);

	regKey.SetValue("HiScoreSound", m_HiScore);
	regKey.SetValue("DiceRollSound", m_DiceRoll);
	regKey.SetValue("ExitSound", m_Exit);
	regKey.SetValue("ScoreSound", m_Score);
	regKey.SetValue("YahtzeeSound", m_Yahtzee);

	CDialog::OnOK();
}
