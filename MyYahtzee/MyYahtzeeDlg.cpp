// MyYahtzeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "MyYahtzeeDlg.h"
#include "HighScoreDlg.h"
#include "HighScoreSheetDlg.h"
#include "CreditStatic.h"
#include "RegKey.h"
#include <mmsystem.h>
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CCreditStatic m_static;
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeDlg dialog

CMyYahtzeeDlg::CMyYahtzeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyYahtzeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyYahtzeeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_UnlimitedRolls = FALSE;
	m_RollNumber = 0;
	m_SelectingDice = FALSE;
	m_Scoring = FALSE;
	m_Column1Scores = 0;
	m_Column2Scores = 0;
	m_Column3Scores = 0;
	m_Column4Scores = 0;
	m_Column5Scores = 0;
	m_Column6Scores = 0;
	m_NumYahtzees = 0;
}

void CMyYahtzeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyYahtzeeDlg)
	DDX_Control(pDX, IDC_BUTTON2, m_Button2);
	DDX_Control(pDX, IDC_SETTINGS, m_Settings);
	DDX_Control(pDX, IDC_RESETGAME, m_ResetGame);
	DDX_Control(pDX, IDC_BUTTON3, m_Button3);
	DDX_Control(pDX, IDC_BUTTON1, m_Button1);
	DDX_Control(pDX, IDC_UNDO, m_Undo);
	DDX_Control(pDX, IDC_DICEFRAME, m_DiceFrame);
	DDX_Control(pDX, IDC_CLICKONDICE, m_ClickOnDice);
	DDX_Control(pDX, IDC_HOLD5, m_Hold5);
	DDX_Control(pDX, IDC_HOLD4, m_Hold4);
	DDX_Control(pDX, IDC_HOLD3, m_Hold3);
	DDX_Control(pDX, IDC_HOLD2, m_Hold2);
	DDX_Control(pDX, IDC_HOLD1, m_Hold1);
	DDX_Control(pDX, IDC_DIE_TWO, m_DieTwo);
	DDX_Control(pDX, IDC_DIE_THREE, m_DieThree);
	DDX_Control(pDX, IDC_DIE_ONE, m_DieOne);
	DDX_Control(pDX, IDC_DIE_FOUR, m_DieFour);
	DDX_Control(pDX, IDC_DIE_FIVE, m_DieFive);
	DDX_Control(pDX, IDC_YAHTZEE_3, m_Yahtzee3);
	DDX_Control(pDX, IDC_YAHTZEE_2, m_Yahtzee2);
	DDX_Control(pDX, IDC_YAHTZEE_1, m_Yahtzee1);
	DDX_Control(pDX, IDC_TWO_3, m_Two3);
	DDX_Control(pDX, IDC_TWO_2, m_Two2);
	DDX_Control(pDX, IDC_TWO_1, m_Two1);
	DDX_Control(pDX, IDC_TOTAL_3, m_Total3);
	DDX_Control(pDX, IDC_TOTAL_2, m_Total2);
	DDX_Control(pDX, IDC_TOTAL_1, m_Total1);
	DDX_Control(pDX, IDC_THREE_3, m_Three3);
	DDX_Control(pDX, IDC_THREE_2, m_Three2);
	DDX_Control(pDX, IDC_THREE_1, m_Three1);
	DDX_Control(pDX, IDC_SMALLSTR_3, m_SmallStr3);
	DDX_Control(pDX, IDC_SMALLSTR_2, m_SmallStr2);
	DDX_Control(pDX, IDC_SMALLSTR_1, m_SmallStr1);
	DDX_Control(pDX, IDC_SIX_3, m_Six3);
	DDX_Control(pDX, IDC_SIX_2, m_Six2);
	DDX_Control(pDX, IDC_SIX_1, m_Six1);
	DDX_Control(pDX, IDC_SECTIONTWO_3, m_SectionTwo3);
	DDX_Control(pDX, IDC_SECTIONTWO_2, m_SectionTwo2);
	DDX_Control(pDX, IDC_SECTIONTWO_1, m_SectionTwo1);
	DDX_Control(pDX, IDC_SECTIONONE_2, m_SectionOne2);
	DDX_Control(pDX, IDC_SECTIONONE_1, m_SectionOne1);
	DDX_Control(pDX, IDC_SECTIONONE_3, m_SectionOne3);
	DDX_Control(pDX, IDC_ROLL_DICE, m_RollDice);
	DDX_Control(pDX, IDC_ONE_3, m_One3);
	DDX_Control(pDX, IDC_ONE_2, m_One2);
	DDX_Control(pDX, IDC_ONE_1, m_One1);
	DDX_Control(pDX, IDC_LARGESTR_3, m_LargeStr3);
	DDX_Control(pDX, IDC_LARGESTR_2, m_LargeStr2);
	DDX_Control(pDX, IDC_LARGESTR_1, m_LargeStr1);
	DDX_Control(pDX, IDC_GAMETOTAL, m_GameTotal);
	DDX_Control(pDX, IDC_FULLHOUSE_3, m_FullHouse3);
	DDX_Control(pDX, IDC_FULLHOUSE_2, m_FullHouse2);
	DDX_Control(pDX, IDC_FULLHOUSE_1, m_FullHouse1);
	DDX_Control(pDX, IDC_FOUR_3, m_Four3);
	DDX_Control(pDX, IDC_FOUR_2, m_Four2);
	DDX_Control(pDX, IDC_FOUR_1, m_Four1);
	DDX_Control(pDX, IDC_FIVE_3, m_Five3);
	DDX_Control(pDX, IDC_FIVE_2, m_Five2);
	DDX_Control(pDX, IDC_FIVE_1, m_Five1);
	DDX_Control(pDX, IDC_CHANCE_3, m_Chance3);
	DDX_Control(pDX, IDC_CHANCE_2, m_Chance2);
	DDX_Control(pDX, IDC_CHANCE_1, m_Chance1);
	DDX_Control(pDX, IDC_BONUS_3, m_Bonus3);
	DDX_Control(pDX, IDC_BONUS_2, m_Bonus2);
	DDX_Control(pDX, IDC_BONUS_1, m_Bonus1);
	DDX_Control(pDX, IDC_4OFKIND_3, m_4OfAKind3);
	DDX_Control(pDX, IDC_4OFKIND_2, m_4OfAKind2);
	DDX_Control(pDX, IDC_4OFKIND_1, m_4OfAKind1);
	DDX_Control(pDX, IDC_3OFKIND_3, m_3OfAKind3);
	DDX_Control(pDX, IDC_3OFKIND_2, m_3OfAKind2);
	DDX_Control(pDX, IDC_3OFKIND_1, m_3OfAKind1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyYahtzeeDlg, CDialog)
	//{{AFX_MSG_MAP(CMyYahtzeeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ROLL_DICE, OnRollDice)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_DIE_FIVE, OnDieFive)
	ON_BN_CLICKED(IDC_DIE_FOUR, OnDieFour)
	ON_BN_CLICKED(IDC_DIE_ONE, OnDieOne)
	ON_BN_CLICKED(IDC_DIE_THREE, OnDieThree)
	ON_BN_CLICKED(IDC_DIE_TWO, OnDieTwo)
	ON_EN_SETFOCUS(IDC_3OFKIND_1, OnSetfocus3ofkind1)
	ON_EN_SETFOCUS(IDC_3OFKIND_2, OnSetfocus3ofkind2)
	ON_EN_SETFOCUS(IDC_3OFKIND_3, OnSetfocus3ofkind3)
	ON_EN_SETFOCUS(IDC_4OFKIND_1, OnSetfocus4ofkind1)
	ON_EN_SETFOCUS(IDC_4OFKIND_2, OnSetfocus4ofkind2)
	ON_EN_SETFOCUS(IDC_4OFKIND_3, OnSetfocus4ofkind3)
	ON_EN_SETFOCUS(IDC_CHANCE_1, OnSetfocusChance1)
	ON_EN_SETFOCUS(IDC_CHANCE_2, OnSetfocusChance2)
	ON_EN_SETFOCUS(IDC_CHANCE_3, OnSetfocusChance3)
	ON_EN_SETFOCUS(IDC_FIVE_1, OnSetfocusFive1)
	ON_EN_SETFOCUS(IDC_FIVE_2, OnSetfocusFive2)
	ON_EN_SETFOCUS(IDC_FIVE_3, OnSetfocusFive3)
	ON_EN_SETFOCUS(IDC_FOUR_1, OnSetfocusFour1)
	ON_EN_SETFOCUS(IDC_FOUR_2, OnSetfocusFour2)
	ON_EN_SETFOCUS(IDC_FOUR_3, OnSetfocusFour3)
	ON_EN_SETFOCUS(IDC_FULLHOUSE_1, OnSetfocusFullhouse1)
	ON_EN_SETFOCUS(IDC_FULLHOUSE_2, OnSetfocusFullhouse2)
	ON_EN_SETFOCUS(IDC_FULLHOUSE_3, OnSetfocusFullhouse3)
	ON_EN_SETFOCUS(IDC_LARGESTR_1, OnSetfocusLargestr1)
	ON_EN_SETFOCUS(IDC_LARGESTR_2, OnSetfocusLargestr2)
	ON_EN_SETFOCUS(IDC_LARGESTR_3, OnSetfocusLargestr3)
	ON_EN_SETFOCUS(IDC_ONE_1, OnSetfocusOne1)
	ON_EN_SETFOCUS(IDC_ONE_2, OnSetfocusOne2)
	ON_EN_SETFOCUS(IDC_ONE_3, OnSetfocusOne3)
	ON_EN_SETFOCUS(IDC_SIX_1, OnSetfocusSix1)
	ON_EN_SETFOCUS(IDC_SIX_2, OnSetfocusSix2)
	ON_EN_SETFOCUS(IDC_SIX_3, OnSetfocusSix3)
	ON_EN_SETFOCUS(IDC_SMALLSTR_1, OnSetfocusSmallstr1)
	ON_EN_SETFOCUS(IDC_SMALLSTR_2, OnSetfocusSmallstr2)
	ON_EN_SETFOCUS(IDC_SMALLSTR_3, OnSetfocusSmallstr3)
	ON_EN_SETFOCUS(IDC_THREE_1, OnSetfocusThree1)
	ON_EN_SETFOCUS(IDC_THREE_2, OnSetfocusThree2)
	ON_EN_SETFOCUS(IDC_THREE_3, OnSetfocusThree3)
	ON_EN_SETFOCUS(IDC_TWO_1, OnSetfocusTwo1)
	ON_EN_SETFOCUS(IDC_TWO_2, OnSetfocusTwo2)
	ON_EN_SETFOCUS(IDC_TWO_3, OnSetfocusTwo3)
	ON_EN_SETFOCUS(IDC_YAHTZEE_1, OnSetfocusYahtzee1)
	ON_EN_SETFOCUS(IDC_YAHTZEE_2, OnSetfocusYahtzee2)
	ON_EN_SETFOCUS(IDC_YAHTZEE_3, OnSetfocusYahtzee3)
	ON_BN_CLICKED(IDOK, OnOk)
	ON_BN_CLICKED(IDC_UNDO, OnUndo)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_VIEWHIGHSCORES, OnViewhighscores)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_RESETGAME, OnResetgame)
	ON_BN_CLICKED(IDC_ABOUT, OnAbout)
	ON_BN_CLICKED(IDC_SETTINGS, OnSettings)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeDlg message handlers

BOOL CMyYahtzeeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	DWORD HiScoreSound, DiceRollSound, ExitSound, ScoreSound, YahtzeeSound;
	CRegKey regKey;
	regKey.Open(HKEY_LOCAL_MACHINE, "Software\\Henkemeyer Software\\Triple Yahztee");

	regKey.GetValue("HiScoreSound", &HiScoreSound, 1);
	regKey.GetValue("DiceRollSound", &DiceRollSound, 1);
	regKey.GetValue("ExitSound", &ExitSound, 1);
	regKey.GetValue("ScoreSound", &ScoreSound, 1);
	regKey.GetValue("YahtzeeSound", &YahtzeeSound, 1);

	m_SettingsDlg.m_DiceRoll = DiceRollSound;
	m_SettingsDlg.m_HiScore = HiScoreSound;
	m_SettingsDlg.m_Exit = ExitSound;
	m_SettingsDlg.m_Score = ScoreSound;
	m_SettingsDlg.m_Yahtzee = YahtzeeSound;



	srand( (unsigned)time( NULL ) );	

	LoadHighScores();

	ResetGame();
	
#ifdef _DEBUG
	m_Settings.ShowWindow(SW_SHOW);
	m_Button1.ShowWindow(SW_SHOW);
	m_Button2.ShowWindow(SW_SHOW);
	m_Button3.ShowWindow(SW_SHOW);
	m_Button3.SetWindowText("Unlimited Rolls OFF");
#endif

	m_Undo.EnableWindow(FALSE);

	m_ClickOnDice.SetWindowText("Press \"Roll\" to roll the dice.");
	m_RollNumber = 0;

	m_DieOneHeld = FALSE;
	m_DieTwoHeld = FALSE;
	m_DieThreeHeld = FALSE;
	m_DieFourHeld = FALSE;
	m_DieFiveHeld = FALSE;

	m_Hold1.SetWindowText("");
	m_Hold2.SetWindowText("");
	m_Hold3.SetWindowText("");
	m_Hold4.SetWindowText("");
	m_Hold5.SetWindowText("");

	m_Icon1 = AfxGetApp()->LoadIcon(IDI_ONE);
	m_Icon2 = AfxGetApp()->LoadIcon(IDI_TWO);
	m_Icon3 = AfxGetApp()->LoadIcon(IDI_THREE);
	m_Icon4 = AfxGetApp()->LoadIcon(IDI_FOUR);
	m_Icon5 = AfxGetApp()->LoadIcon(IDI_FIVE);
	m_Icon6 = AfxGetApp()->LoadIcon(IDI_SIX);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	UpdateColumn1();
	UpdateColumn2();
	UpdateColumn3();
	UpdateColumn4();
	UpdateColumn5();
	UpdateColumn6();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyYahtzeeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyYahtzeeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyYahtzeeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyYahtzeeDlg::OnRollDice() 
{
	if (m_Column1Scores == 6 && m_Column2Scores == 6 && m_Column3Scores == 6 &&
		m_Column4Scores == 7 && m_Column5Scores == 7 && m_Column6Scores == 7)
	{
		ResetGame();
	}
	
	if (m_SettingsDlg.m_DiceRoll)
		PlaySound("dice.wav", NULL, SND_ASYNC);
	if (m_RollNumber == 0)
	{
		m_Hold1.SetWindowText("");
		m_Hold2.SetWindowText("");
		m_Hold3.SetWindowText("");
		m_Hold4.SetWindowText("");
		m_Hold5.SetWindowText("");
		m_DieOneHeld = FALSE;
		m_DieTwoHeld = FALSE;
		m_DieThreeHeld = FALSE;
		m_DieFourHeld = FALSE;
		m_DieFiveHeld = FALSE;
	}
	m_Undo.EnableWindow(FALSE);
	m_ClickOnDice.SetWindowText("");
	m_SelectingDice = FALSE;
	m_RollNumber++;
	SetTimer(1, 30, NULL);
	int RollTime = 900 + (rand() % 100);
#ifdef _DEBUG
	RollTime = 31;
#endif
	SetTimer(2, RollTime, NULL);
	m_RollDice.EnableWindow(FALSE);
}

void CMyYahtzeeDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 3)
	{
		m_YahtzeeDlg.DestroyWindow();   
		KillTimer(3);
		return;
	}
	if (nIDEvent == 2)
	{
		KillTimer(1);
		KillTimer(2);
		m_Scoring = TRUE;
		m_SelectingDice = TRUE;
		m_ClickOnDice.SetWindowText("Click on the dice you wish to hold.");
		CString RollNumber;
		RollNumber.Format("Roll %d", m_RollNumber);
		m_DiceFrame.SetWindowText(RollNumber);
		if (m_RollNumber == 3 && !m_UnlimitedRolls)
		{
			m_RollDice.EnableWindow(FALSE);
			m_SelectingDice = FALSE;
			m_RollNumber = 0;
		}
		else
		{
			m_RollDice.EnableWindow(TRUE);
		}
		if (IsYahtzee())
		{
			m_NumYahtzees++;
			if(m_YahtzeeDlg.Create(IDD_YAHTZEE,NULL))
			{
				m_YahtzeeDlg.m_NumYahtzees = m_NumYahtzees;
				m_YahtzeeDlg.CenterWindow();
				m_YahtzeeDlg.ShowWindow(SW_SHOW);
				m_YahtzeeDlg.UpdateWindow();
			}
			theApp.PlayRandomSound("Yahtzee");
			SetTimer(3, 4000, NULL);
		}
		return;
	}
	if (nIDEvent == 4)
	{
		KillTimer(4);
		m_DieOneValue = 1;
		m_DieTwoValue = 1;
		m_DieThreeValue = 1;
		m_DieFourValue = 1;
		m_DieFiveValue = 1;
		SetDie(1, 1);
		SetDie(2, 1);
		SetDie(3, 1);
		SetDie(4, 1);
		SetDie(5, 1);
		m_Scoring = TRUE;
		m_SelectingDice = TRUE;
		m_ClickOnDice.SetWindowText("Click on the dice you wish to hold.");
		CString RollNumber;
		RollNumber.Format("Roll %d", m_RollNumber);
		m_DiceFrame.SetWindowText(RollNumber);
		if (m_RollNumber == 3 && !m_UnlimitedRolls)
		{
			m_RollDice.EnableWindow(FALSE);
			m_SelectingDice = FALSE;
			m_RollNumber = 0;
		}
		else
		{
			m_RollDice.EnableWindow(TRUE);
		}
		if (IsYahtzee())
		{
			m_NumYahtzees++;
			if(m_YahtzeeDlg.Create(IDD_YAHTZEE,NULL))
			{
				m_YahtzeeDlg.m_NumYahtzees = m_NumYahtzees;
				m_YahtzeeDlg.CenterWindow();
				m_YahtzeeDlg.ShowWindow(SW_SHOW);
				m_YahtzeeDlg.UpdateWindow();
			}
			if (m_SettingsDlg.m_Yahtzee)
			{
				theApp.PlayRandomSound("Yahtzee");
			}

			SetTimer(3, 4000, NULL);
		}
		return;
	}

	// Get random numbers
	m_DieOneValue = m_DieOneHeld ? m_DieOneValue : GetRandValue(m_DieOneValue);
	m_DieTwoValue = m_DieTwoHeld? m_DieTwoValue : GetRandValue(m_DieTwoValue);
	m_DieThreeValue = m_DieThreeHeld ? m_DieThreeValue : GetRandValue(m_DieThreeValue);
	m_DieFourValue = m_DieFourHeld ? m_DieFourValue : GetRandValue(m_DieFourValue);
	m_DieFiveValue = m_DieFiveHeld ? m_DieFiveValue : GetRandValue(m_DieFiveValue);

	// Change the cursors
	SetDie(1, m_DieOneValue);
	SetDie(2, m_DieTwoValue);
	SetDie(3, m_DieThreeValue);
	SetDie(4, m_DieFourValue);
	SetDie(5, m_DieFiveValue);

	//TRACE("Roll # %d : %d \n", m_RollNumber++, m_DieOneValue);
	CDialog::OnTimer(nIDEvent);
}


DWORD CMyYahtzeeDlg::GetRandValue(DWORD PreviousValue)
{
	DWORD Value = (rand() % 6) + 1;
	while (Value == PreviousValue)
	{
		Value = (rand() % 6) + 1;	
	}
	return Value;
}

void CMyYahtzeeDlg::SetDie(DWORD DieNumber, DWORD DieValue)
{
	switch (DieNumber)
	{
	case 1:
		switch (DieValue)
		{
		case 1:
			m_DieOne.SetIcon(m_Icon1);
			break;
		case 2:
			m_DieOne.SetIcon(m_Icon2);
			break;
		case 3:
			m_DieOne.SetIcon(m_Icon3);
			break;
		case 4:
			m_DieOne.SetIcon(m_Icon4);
			break;
		case 5:
			m_DieOne.SetIcon(m_Icon5);
			break;
		case 6:
			m_DieOne.SetIcon(m_Icon6);
			break;
		}
		break;
	case 2:
		switch (DieValue)
		{
		case 1:
			m_DieTwo.SetIcon(m_Icon1);
			break;
		case 2:
			m_DieTwo.SetIcon(m_Icon2);
			break;
		case 3:
			m_DieTwo.SetIcon(m_Icon3);
			break;
		case 4:
			m_DieTwo.SetIcon(m_Icon4);
			break;
		case 5:
			m_DieTwo.SetIcon(m_Icon5);
			break;
		case 6:
			m_DieTwo.SetIcon(m_Icon6);
			break;
		}
		break;
	case 3:
		switch (DieValue)
		{
		case 1:
			m_DieThree.SetIcon(m_Icon1);
			break;
		case 2:
			m_DieThree.SetIcon(m_Icon2);
			break;
		case 3:
			m_DieThree.SetIcon(m_Icon3);
			break;
		case 4:
			m_DieThree.SetIcon(m_Icon4);
			break;
		case 5:
			m_DieThree.SetIcon(m_Icon5);
			break;
		case 6:
			m_DieThree.SetIcon(m_Icon6);
			break;
		}
		break;
	case 4:
		switch (DieValue)
		{
		case 1:
			m_DieFour.SetIcon(m_Icon1);
			break;
		case 2:
			m_DieFour.SetIcon(m_Icon2);
			break;
		case 3:
			m_DieFour.SetIcon(m_Icon3);
			break;
		case 4:
			m_DieFour.SetIcon(m_Icon4);
			break;
		case 5:
			m_DieFour.SetIcon(m_Icon5);
			break;
		case 6:
			m_DieFour.SetIcon(m_Icon6);
			break;
		}
		break;
	case 5:
		switch (DieValue)
		{
		case 1:
			m_DieFive.SetIcon(m_Icon1);
			break;
		case 2:
			m_DieFive.SetIcon(m_Icon2);
			break;
		case 3:
			m_DieFive.SetIcon(m_Icon3);
			break;
		case 4:
			m_DieFive.SetIcon(m_Icon4);
			break;
		case 5:
			m_DieFive.SetIcon(m_Icon5);
			break;
		case 6:
			m_DieFive.SetIcon(m_Icon6);
			break;
		}
		break;
	}
}

void CMyYahtzeeDlg::OnDieFive() 
{
	if (m_SelectingDice)
	{
		if (m_DieFiveHeld)
		{
			m_Hold5.SetWindowText("");
		}
		else
		{
			m_Hold5.SetWindowText("Hold");
		}
		m_DieFiveHeld = !m_DieFiveHeld;
	}
}

void CMyYahtzeeDlg::OnDieFour() 
{
	if (m_SelectingDice)
	{
		if (m_DieFourHeld)
		{
			m_Hold4.SetWindowText("");
		}
		else
		{
			m_Hold4.SetWindowText("Hold");
		}
		m_DieFourHeld = !m_DieFourHeld;
	}
}

void CMyYahtzeeDlg::OnDieOne() 
{
	if (m_SelectingDice)
	{
		if (m_DieOneHeld)
		{
			m_Hold1.SetWindowText("");
		}
		else
		{
			m_Hold1.SetWindowText("Hold");
		}
		m_DieOneHeld = !m_DieOneHeld;
	}
}

void CMyYahtzeeDlg::OnDieThree() 
{
	if (m_SelectingDice)
	{
		if (m_DieThreeHeld)
		{
			m_Hold3.SetWindowText("");
		}
		else
		{
			m_Hold3.SetWindowText("Hold");
		}
		m_DieThreeHeld = !m_DieThreeHeld;
	}
}

void CMyYahtzeeDlg::OnDieTwo() 
{
	if (m_SelectingDice)
	{
		if (m_DieTwoHeld)
		{
			m_Hold2.SetWindowText("");
		}
		else
		{
			m_Hold2.SetWindowText("Hold");
		}
		m_DieTwoHeld = !m_DieTwoHeld;
	}
}

DWORD CMyYahtzeeDlg::Get3OfAKindValue()
{
	if (((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieThreeValue)) ||
		((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieFourValue)) ||
		((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue)) ||
		((m_DieOneValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue)) ||
		((m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue)) ||
		((m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFiveValue)) ||
		((m_DieTwoValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue)) ||
		((m_DieThreeValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue)) )
	{
		if (IsYahtzee() && m_NumYahtzees > 3)
			return (m_DieOneValue + m_DieTwoValue + m_DieThreeValue + m_DieFourValue + m_DieFiveValue + 100);
		else
			return (m_DieOneValue + m_DieTwoValue + m_DieThreeValue + m_DieFourValue + m_DieFiveValue);
	}
	else
	{
		return 0;
	}
}

DWORD CMyYahtzeeDlg::Get4OfAKindValue()
{
	if (((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue)) ||
		((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue)) ||
		((m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue)) )
	{
		if (IsYahtzee() && m_NumYahtzees > 3)
			return (m_DieOneValue + m_DieTwoValue + m_DieThreeValue + m_DieFourValue + m_DieFiveValue + 100);
		else
			return (m_DieOneValue + m_DieTwoValue + m_DieThreeValue + m_DieFourValue + m_DieFiveValue);
	}
	else
	{
		return 0;
	}
}

void CMyYahtzeeDlg::ResetDice()
{
	m_Undo.EnableWindow(TRUE);
	m_ClickOnDice.GetWindowText(m_OldText);
	m_ClickOnDice.SetWindowText("Press \"Roll\" to roll the dice.");
	m_DiceFrame.GetWindowText(m_OldDiceFrame);
	m_DiceFrame.SetWindowText("Dice");
	m_OldRollNumber = m_RollNumber;
	m_RollNumber = 0;
	m_SelectingDice = FALSE;
	m_RollDice.EnableWindow(TRUE);
}

void CMyYahtzeeDlg::OnUndo() 
{
	pUndoCtrl->EnableWindow(TRUE);
	pUndoCtrl->SetWindowText("");
	m_Undo.EnableWindow(FALSE);
	m_RollNumber = m_OldRollNumber;
	if (m_RollNumber != 0)
		m_RollDice.EnableWindow(TRUE);
	else
		m_RollDice.EnableWindow(FALSE);
	m_SelectingDice = TRUE;
	m_Scoring = TRUE;
	m_DiceFrame.SetWindowText(m_OldDiceFrame);
	m_ClickOnDice.SetWindowText(m_OldText);
	(*m_pValuePtr) = 0;
	(*m_pColumnPtr)--;
	UpdateColumn1();
	UpdateColumn2();
	UpdateColumn3();
	UpdateColumn4();
	UpdateColumn5();
	UpdateColumn6();
}

void CMyYahtzeeDlg::OnSetfocus3ofkind1() 
{
	if (!m_Scoring)
		return;
	m_3OfAKind1Value = Get3OfAKindValue();
	CString Value;
	Value.Format("%d", m_3OfAKind1Value);
	m_3OfAKind1.SetWindowText(Value);
	m_3OfAKind1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_3OfAKind1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocus3ofkind2() 
{
	if (!m_Scoring)
		return;
	m_3OfAKind2Value = Get3OfAKindValue();
	CString Value;
	Value.Format("%d", m_3OfAKind2Value);
	m_3OfAKind2.SetWindowText(Value);
	m_3OfAKind2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_3OfAKind2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocus3ofkind3() 
{
	if (!m_Scoring)
		return;
	m_3OfAKind3Value = Get3OfAKindValue();
	CString Value;
	Value.Format("%d", m_3OfAKind3Value);
	m_3OfAKind3.SetWindowText(Value);
	m_3OfAKind3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_3OfAKind3Value;
	m_pColumnPtr = &m_Column6Scores;
}

void CMyYahtzeeDlg::OnSetfocus4ofkind1() 
{
	if (!m_Scoring)
		return;
	m_4OfAKind1Value = Get4OfAKindValue();
	CString Value;
	Value.Format("%d", m_4OfAKind1Value);
	m_4OfAKind1.SetWindowText(Value);
	m_4OfAKind1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_4OfAKind1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocus4ofkind2() 
{
	if (!m_Scoring)
		return;
	m_4OfAKind2Value = Get4OfAKindValue();
	CString Value;
	Value.Format("%d", m_4OfAKind2Value);
	m_4OfAKind2.SetWindowText(Value);
	m_4OfAKind2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_4OfAKind2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocus4ofkind3() 
{
	if (!m_Scoring)
		return;
	m_4OfAKind3Value = Get4OfAKindValue();
	CString Value;
	Value.Format("%d", m_4OfAKind3Value);
	m_4OfAKind3.SetWindowText(Value);
	m_4OfAKind3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_4OfAKind3Value;
	m_pColumnPtr = &m_Column6Scores;
}

void CMyYahtzeeDlg::OnSetfocusChance1() 
{
	if (!m_Scoring)
		return;
	m_Chance1Value = GetChanceValue();
	CString Value;
	Value.Format("%d", m_Chance1Value);
	m_Chance1.SetWindowText(Value);
	m_Chance1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_Chance1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocusChance2() 
{
	if (!m_Scoring)
		return;
	m_Chance2Value = GetChanceValue();
	CString Value;
	Value.Format("%d", m_Chance2Value);
	m_Chance2.SetWindowText(Value);
	m_Chance2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_Chance2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocusChance3() 
{
	if (!m_Scoring)
		return;
	m_Chance3Value = GetChanceValue();
	CString Value;
	Value.Format("%d", m_Chance3Value);
	m_Chance3.SetWindowText(Value);
	m_Chance3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_Chance3Value;
	m_pColumnPtr = &m_Column6Scores;
}

void CMyYahtzeeDlg::OnSetfocusFive1() 
{
	if (!m_Scoring)
		return;
	m_Five1Value = GetNumberValue(5);
	CString Value;
	Value.Format("%d", m_Five1Value);
	m_Five1.SetWindowText(Value);
	m_Five1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column1Scores++;
	UpdateColumn1();
	m_pValuePtr = &m_Five1Value;
	m_pColumnPtr = &m_Column1Scores;
}

void CMyYahtzeeDlg::OnSetfocusFive2() 
{
	if (!m_Scoring)
		return;
	m_Five2Value = GetNumberValue(5);
	CString Value;
	Value.Format("%d", m_Five2Value);
	m_Five2.SetWindowText(Value);
	m_Five2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column2Scores++;
	UpdateColumn2();
	m_pValuePtr = &m_Five2Value;
	m_pColumnPtr = &m_Column2Scores;
}

void CMyYahtzeeDlg::OnSetfocusFive3() 
{
	if (!m_Scoring)
		return;
	m_Five3Value = GetNumberValue(5);
	CString Value;
	Value.Format("%d", m_Five3Value);
	m_Five3.SetWindowText(Value);
	m_Five3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column3Scores++;
	UpdateColumn3();
	m_pValuePtr = &m_Five3Value;
	m_pColumnPtr = &m_Column3Scores;
}

void CMyYahtzeeDlg::OnSetfocusFour1() 
{
	if (!m_Scoring)
		return;
	m_Four1Value = GetNumberValue(4);
	CString Value;
	Value.Format("%d", m_Four1Value);
	m_Four1.SetWindowText(Value);
	m_Four1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column1Scores++;
	UpdateColumn1();
	m_pValuePtr = &m_Four1Value;
	m_pColumnPtr = &m_Column1Scores;
}

void CMyYahtzeeDlg::OnSetfocusFour2() 
{
	if (!m_Scoring)
		return;
	m_Four2Value = GetNumberValue(4);
	CString Value;
	Value.Format("%d", m_Four2Value);
	m_Four2.SetWindowText(Value);
	m_Four2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column2Scores++;
	UpdateColumn2();
	m_pValuePtr = &m_Four2Value;
	m_pColumnPtr = &m_Column2Scores;
}

void CMyYahtzeeDlg::OnSetfocusFour3() 
{
	if (!m_Scoring)
		return;
	m_Four3Value = GetNumberValue(4);
	CString Value;
	Value.Format("%d", m_Four3Value);
	m_Four3.SetWindowText(Value);
	m_Four3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column3Scores++;
	UpdateColumn3();
	m_pValuePtr = &m_Four3Value;
	m_pColumnPtr = &m_Column3Scores;
}

void CMyYahtzeeDlg::OnSetfocusFullhouse1() 
{
	if (!m_Scoring)
		return;
	m_FullHouse1Value = IsFullHouse() ? 25 : 0;
	if (IsYahtzee() && m_NumYahtzees > 3)
		m_FullHouse1Value += 100;
	CString Value;
	Value.Format("%d", m_FullHouse1Value);
	m_FullHouse1.SetWindowText(Value);
	m_FullHouse1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_FullHouse1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocusFullhouse2() 
{
	if (!m_Scoring)
		return;
	m_FullHouse2Value = IsFullHouse() ? 25 : 0;
	if (IsYahtzee() && m_NumYahtzees > 3)
		m_FullHouse2Value += 100;
	CString Value;
	Value.Format("%d", m_FullHouse2Value);
	m_FullHouse2.SetWindowText(Value);
	m_FullHouse2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_FullHouse2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocusFullhouse3() 
{
	if (!m_Scoring)
		return;
	m_FullHouse3Value = IsFullHouse() ? 25 : 0;
	if (IsYahtzee() && m_NumYahtzees > 3)
		m_FullHouse3Value += 100;
	CString Value;
	Value.Format("%d", m_FullHouse3Value);
	m_FullHouse3.SetWindowText(Value);
	m_FullHouse3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_FullHouse3Value;
	m_pColumnPtr = &m_Column6Scores;
}

void CMyYahtzeeDlg::OnSetfocusLargestr1() 
{
	if (!m_Scoring)
		return;
	m_LargeStr1Value = IsLargeStraight() ? 40 : 0;
	CString Value;
	Value.Format("%d", m_LargeStr1Value);
	m_LargeStr1.SetWindowText(Value);
	m_LargeStr1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_LargeStr1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocusLargestr2() 
{
	if (!m_Scoring)
		return;
	m_LargeStr2Value = IsLargeStraight() ? 40 : 0;
	CString Value;
	Value.Format("%d", m_LargeStr2Value);
	m_LargeStr2.SetWindowText(Value);
	m_LargeStr2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_LargeStr2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocusLargestr3() 
{
	if (!m_Scoring)
		return;
	m_LargeStr3Value = IsLargeStraight() ? 40 : 0;
	CString Value;
	Value.Format("%d", m_LargeStr3Value);
	m_LargeStr3.SetWindowText(Value);
	m_LargeStr3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_LargeStr3Value;
	m_pColumnPtr = &m_Column6Scores;
}

void CMyYahtzeeDlg::OnSetfocusOne1() 
{
	if (!m_Scoring)
		return;
	m_One1Value = GetNumberValue(1);
	CString Value;
	Value.Format("%d", m_One1Value);
	m_One1.SetWindowText(Value);
	m_One1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column1Scores++;
	UpdateColumn1();
	m_pValuePtr = &m_One1Value;
	m_pColumnPtr = &m_Column1Scores;
}

void CMyYahtzeeDlg::OnSetfocusOne2() 
{
	if (!m_Scoring)
		return;
	m_One2Value = GetNumberValue(1);
	CString Value;
	Value.Format("%d", m_One2Value);
	m_One2.SetWindowText(Value);
	m_One2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column2Scores++;
	UpdateColumn2();
	m_pValuePtr = &m_One2Value;
	m_pColumnPtr = &m_Column2Scores;
}

void CMyYahtzeeDlg::OnSetfocusOne3() 
{
	if (!m_Scoring)
		return;
	m_One3Value = GetNumberValue(1);
	CString Value;
	Value.Format("%d", m_One3Value);
	m_One3.SetWindowText(Value);
	m_One3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column3Scores++;
	UpdateColumn3();
	m_pValuePtr = &m_One3Value;
	m_pColumnPtr = &m_Column3Scores;
}

void CMyYahtzeeDlg::OnSetfocusSix1() 
{
	if (!m_Scoring)
		return;
	m_Six1Value = GetNumberValue(6);
	CString Value;
	Value.Format("%d", m_Six1Value);
	m_Six1.SetWindowText(Value);
	m_Six1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column1Scores++;
	UpdateColumn1();
	m_pValuePtr = &m_Six1Value;
	m_pColumnPtr = &m_Column1Scores;
}

void CMyYahtzeeDlg::OnSetfocusSix2() 
{
	if (!m_Scoring)
		return;
	m_Six2Value = GetNumberValue(6);
	CString Value;
	Value.Format("%d", m_Six2Value);
	m_Six2.SetWindowText(Value);
	m_Six2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column2Scores++;
	UpdateColumn2();
	m_pValuePtr = &m_Six2Value;
	m_pColumnPtr = &m_Column2Scores;
}

void CMyYahtzeeDlg::OnSetfocusSix3() 
{
	if (!m_Scoring)
		return;
	m_Six3Value = GetNumberValue(6);
	CString Value;
	Value.Format("%d", m_Six3Value);
	m_Six3.SetWindowText(Value);
	m_Six3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column3Scores++;
	UpdateColumn3();
	m_pValuePtr = &m_Six3Value;
	m_pColumnPtr = &m_Column3Scores;
}

void CMyYahtzeeDlg::OnSetfocusSmallstr1() 
{
	if (!m_Scoring)
		return;
	m_SmallStr1Value = IsSmallStraight() ? 30 : 0;
	CString Value;
	Value.Format("%d", m_SmallStr1Value);
	m_SmallStr1.SetWindowText(Value);
	m_SmallStr1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_SmallStr1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocusSmallstr2() 
{
	if (!m_Scoring)
		return;
	m_SmallStr2Value = IsSmallStraight() ? 30 : 0;
	CString Value;
	Value.Format("%d", m_SmallStr2Value);
	m_SmallStr2.SetWindowText(Value);
	m_SmallStr2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_SmallStr2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocusSmallstr3() 
{
	if (!m_Scoring)
		return;
	m_SmallStr3Value = IsSmallStraight() ? 30 : 0;
	CString Value;
	Value.Format("%d", m_SmallStr3Value);
	m_SmallStr3.SetWindowText(Value);
	m_SmallStr3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_SmallStr3Value;
	m_pColumnPtr = &m_Column6Scores;
}

void CMyYahtzeeDlg::OnSetfocusThree1() 
{
	if (!m_Scoring)
		return;
	m_Three1Value = GetNumberValue(3);
	CString Value;
	Value.Format("%d", m_Three1Value);
	m_Three1.SetWindowText(Value);
	m_Three1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column1Scores++;
	UpdateColumn1();
	m_pValuePtr = &m_Three1Value;
	m_pColumnPtr = &m_Column1Scores;
}

void CMyYahtzeeDlg::OnSetfocusThree2() 
{
	if (!m_Scoring)
		return;
	m_Three2Value = GetNumberValue(3);
	CString Value;
	Value.Format("%d", m_Three2Value);
	m_Three2.SetWindowText(Value);
	m_Three2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column2Scores++;
	UpdateColumn2();
	m_pValuePtr = &m_Three2Value;
	m_pColumnPtr = &m_Column2Scores;
}

void CMyYahtzeeDlg::OnSetfocusThree3() 
{
	if (!m_Scoring)
		return;
	m_Three3Value = GetNumberValue(3);
	CString Value;
	Value.Format("%d", m_Three3Value);
	m_Three3.SetWindowText(Value);
	m_Three3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column3Scores++;
	UpdateColumn3();
	m_pValuePtr = &m_Three3Value;
	m_pColumnPtr = &m_Column3Scores;
}

void CMyYahtzeeDlg::OnSetfocusTwo1() 
{
	if (!m_Scoring)
		return;
	m_Two1Value = GetNumberValue(2);
	CString Value;
	Value.Format("%d", m_Two1Value);
	m_Two1.SetWindowText(Value);
	m_Two1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column1Scores++;
	UpdateColumn1();
	m_pValuePtr = &m_Two1Value;
	m_pColumnPtr = &m_Column1Scores;
}

void CMyYahtzeeDlg::OnSetfocusTwo2() 
{
	if (!m_Scoring)
		return;
	m_Two2Value = GetNumberValue(2);
	CString Value;
	Value.Format("%d", m_Two2Value);
	m_Two2.SetWindowText(Value);
	m_Two2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column2Scores++;
	UpdateColumn2();
	m_pValuePtr = &m_Two2Value;
	m_pColumnPtr = &m_Column2Scores;
}

void CMyYahtzeeDlg::OnSetfocusTwo3() 
{
	if (!m_Scoring)
		return;
	m_Two3Value = GetNumberValue(2);
	CString Value;
	Value.Format("%d", m_Two3Value);
	m_Two3.SetWindowText(Value);
	m_Two3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column3Scores++;
	UpdateColumn3();
	m_pValuePtr = &m_Two3Value;
	m_pColumnPtr = &m_Column3Scores;
}

void CMyYahtzeeDlg::OnSetfocusYahtzee1() 
{
	if (!m_Scoring)
		return;
	m_Yahtzee1Value = IsYahtzee() ? 50 : 0;
	if (IsYahtzee() && m_NumYahtzees > 3)
		m_Yahtzee1Value += 100;
	CString Value;
	Value.Format("%d", m_Yahtzee1Value);
	m_Yahtzee1.SetWindowText(Value);
	m_Yahtzee1.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column4Scores++;
	UpdateColumn4();
	m_pValuePtr = &m_Yahtzee1Value;
	m_pColumnPtr = &m_Column4Scores;
}

void CMyYahtzeeDlg::OnSetfocusYahtzee2() 
{
	if (!m_Scoring)
		return;
	m_Yahtzee2Value = IsYahtzee() ? 50 : 0;
	if (IsYahtzee() && m_NumYahtzees > 3)
		m_Yahtzee2Value += 100;
	CString Value;
	Value.Format("%d", m_Yahtzee2Value);
	m_Yahtzee2.SetWindowText(Value);
	m_Yahtzee2.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column5Scores++;
	UpdateColumn5();
	m_pValuePtr = &m_Yahtzee2Value;
	m_pColumnPtr = &m_Column5Scores;
}

void CMyYahtzeeDlg::OnSetfocusYahtzee3() 
{
	if (!m_Scoring)
		return;
	m_Yahtzee3Value = IsYahtzee() ? 50 : 0;
	if (IsYahtzee() && m_NumYahtzees > 3)
		m_Yahtzee3Value += 100;
	CString Value;
	Value.Format("%d", m_Yahtzee3Value);
	m_Yahtzee3.SetWindowText(Value);
	m_Yahtzee3.EnableWindow(FALSE);
	m_Scoring = FALSE;
	ResetDice();
	m_Column6Scores++;
	UpdateColumn6();
	m_pValuePtr = &m_Yahtzee3Value;
	m_pColumnPtr = &m_Column6Scores;
}

DWORD CMyYahtzeeDlg::GetChanceValue()
{
	if (IsYahtzee() && m_NumYahtzees > 3)
		return (m_DieOneValue + m_DieTwoValue + m_DieThreeValue + m_DieFourValue + m_DieFiveValue + 100);
	else
		return (m_DieOneValue + m_DieTwoValue + m_DieThreeValue + m_DieFourValue + m_DieFiveValue);
}

DWORD CMyYahtzeeDlg::GetNumberValue(DWORD Number)
{
	int Total = 0;
	if (m_DieOneValue == Number)
		Total += m_DieOneValue;
	if (m_DieTwoValue == Number)
		Total += m_DieTwoValue;
	if (m_DieThreeValue == Number)
		Total += m_DieThreeValue;
	if (m_DieFourValue == Number)
		Total += m_DieFourValue;
	if (m_DieFiveValue == Number)
		Total += m_DieFiveValue;
	if ((m_DieFiveValue == Number) && (IsYahtzee()) && m_NumYahtzees > 3)
		Total += 100;

	return Total;
}

BOOL CMyYahtzeeDlg::IsYahtzee()
{
	return ((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieThreeValue) &&
		(m_DieThreeValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue));
}

BOOL CMyYahtzeeDlg::IsFullHouse()
{
	if (((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieThreeValue) && (m_DieFourValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieFourValue) && (m_DieThreeValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieTwoValue) && (m_DieTwoValue == m_DieFiveValue) && (m_DieThreeValue == m_DieFourValue)) ||
		((m_DieOneValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue) && (m_DieTwoValue == m_DieFiveValue)) ||
		((m_DieOneValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFiveValue) && (m_DieTwoValue == m_DieFourValue)) ||
		((m_DieOneValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue) && (m_DieTwoValue == m_DieThreeValue)) ||
		((m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFourValue) && (m_DieOneValue == m_DieFiveValue)) ||
		((m_DieTwoValue == m_DieThreeValue) && (m_DieThreeValue == m_DieFiveValue) && (m_DieOneValue == m_DieFourValue)) ||
		((m_DieTwoValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue) && (m_DieOneValue == m_DieThreeValue)) ||
		((m_DieThreeValue == m_DieFourValue) && (m_DieFourValue == m_DieFiveValue) && (m_DieOneValue == m_DieTwoValue)) )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL CMyYahtzeeDlg::IsSmallStraight()
{
	return ( (Rolled1() && Rolled2() && Rolled3() && Rolled4()) || 
			 (Rolled2() && Rolled3() && Rolled4() && Rolled5()) || 
			 (Rolled3() && Rolled4() && Rolled5() && Rolled6()) );
}

BOOL CMyYahtzeeDlg::IsLargeStraight()
{
	return ( (Rolled1() && Rolled2() && Rolled3() && Rolled4() && Rolled5()) || 
		 (Rolled2() && Rolled3() && Rolled4() && Rolled5() && Rolled6()) );
}

BOOL CMyYahtzeeDlg::Rolled1()
{
	return (m_DieOneValue == 1 || m_DieTwoValue == 1 || m_DieThreeValue == 1 ||
		m_DieFourValue == 1 || m_DieFiveValue == 1);
}

BOOL CMyYahtzeeDlg::Rolled2()
{
	return (m_DieOneValue == 2 || m_DieTwoValue == 2 || m_DieThreeValue == 2 ||
		m_DieFourValue == 2 || m_DieFiveValue == 2);
}

BOOL CMyYahtzeeDlg::Rolled3()
{
	return (m_DieOneValue == 3 || m_DieTwoValue == 3 || m_DieThreeValue == 3 ||
		m_DieFourValue == 3 || m_DieFiveValue == 3);
}

BOOL CMyYahtzeeDlg::Rolled4()
{
	return (m_DieOneValue == 4 || m_DieTwoValue == 4 || m_DieThreeValue == 4 ||
		m_DieFourValue == 4 || m_DieFiveValue == 4);
}

BOOL CMyYahtzeeDlg::Rolled5()
{
	return (m_DieOneValue == 5 || m_DieTwoValue == 5 || m_DieThreeValue == 5 ||
		m_DieFourValue == 5 || m_DieFiveValue == 5);
}

BOOL CMyYahtzeeDlg::Rolled6()
{
	return (m_DieOneValue == 6 || m_DieTwoValue == 6 || m_DieThreeValue == 6 ||
		m_DieFourValue == 6 || m_DieFiveValue == 6);
}

void CMyYahtzeeDlg::UpdateColumn1()
{
	// Add up the scores
	m_Column1Value = m_One1Value + m_Two1Value + m_Three1Value + 
		m_Four1Value + m_Five1Value + m_Six1Value;
	CString Value;
	Value.Format("%d", m_Column1Value);
	m_Total1.SetWindowText(Value);
	m_Total1.EnableWindow(FALSE);
	if (m_Column1Value >= 63)
	{
		Value.Format("%d", 35);
		m_Column1Value += 35;
	}
	else
	{
		Value.Format("%d", 0);
	}
	m_Bonus1.SetWindowText(Value);
	Value.Format("%d", m_Column1Value);
	m_SectionOne1.SetWindowText(Value);
	m_Bonus1.EnableWindow(FALSE);
	m_SectionOne1.EnableWindow(FALSE);
	UpdateGameTotal();
}

void CMyYahtzeeDlg::UpdateColumn2()
{
	// Add up the scores
	m_Column2Value = m_One2Value + m_Two2Value + m_Three2Value + 
		m_Four2Value + m_Five2Value + m_Six2Value;
	CString Value;
	Value.Format("%d", m_Column2Value);
	m_Total2.SetWindowText(Value);
	m_Total2.EnableWindow(FALSE);
	if (m_Column2Value >= 63)
	{
		Value.Format("%d", 35);
		m_Column2Value += 35;
	}
	else
	{
		Value.Format("%d", 0);
	}
	m_Bonus2.SetWindowText(Value);
	m_Column2Value = m_Column2Value * 2;
	Value.Format("%d", m_Column2Value);
	m_SectionOne2.SetWindowText(Value);
	m_Bonus2.EnableWindow(FALSE);
	m_SectionOne2.EnableWindow(FALSE);
	UpdateGameTotal();
}

void CMyYahtzeeDlg::UpdateColumn3()
{
	// Add up the scores
	m_Column3Value = m_One3Value + m_Two3Value + m_Three3Value + 
		m_Four3Value + m_Five3Value + m_Six3Value;
	CString Value;
	Value.Format("%d", m_Column3Value);
	m_Total3.SetWindowText(Value);
	m_Total3.EnableWindow(FALSE);
	if (m_Column3Value >= 63)
	{
		Value.Format("%d", 35);
		m_Column3Value += 35;
	}
	else
	{
		Value.Format("%d", 0);
	}
	m_Bonus3.SetWindowText(Value);
	m_Column3Value = m_Column3Value * 3;
	Value.Format("%d", m_Column3Value);
	m_SectionOne3.SetWindowText(Value);
	m_Bonus3.EnableWindow(FALSE);
	m_SectionOne3.EnableWindow(FALSE);
	UpdateGameTotal();
}

void CMyYahtzeeDlg::UpdateColumn4()
{
	// Add up the scores
	m_Column4Value = m_3OfAKind1Value + m_4OfAKind1Value + m_FullHouse1Value + 
		m_SmallStr1Value + m_LargeStr1Value + m_Yahtzee1Value + m_Chance1Value;
	CString Value;
	Value.Format("%d", m_Column4Value);
	m_SectionTwo1.SetWindowText(Value);
	m_SectionTwo1.EnableWindow(FALSE);
	UpdateGameTotal();
}

void CMyYahtzeeDlg::UpdateColumn5()
{
	// Add up the scores
	m_Column5Value = m_3OfAKind2Value + m_4OfAKind2Value + m_FullHouse2Value + 
		m_SmallStr2Value + m_LargeStr2Value + m_Yahtzee2Value + m_Chance2Value;
	CString Value;
	m_Column5Value = m_Column5Value * 2;
	Value.Format("%d", m_Column5Value);
	m_SectionTwo2.SetWindowText(Value);
	m_SectionTwo2.EnableWindow(FALSE);
	UpdateGameTotal();
}

void CMyYahtzeeDlg::UpdateColumn6()
{
	// Add up the scores
	m_Column6Value = m_3OfAKind3Value + m_4OfAKind3Value + m_FullHouse3Value + 
		m_SmallStr3Value + m_LargeStr3Value + m_Yahtzee3Value + m_Chance3Value;
	CString Value;
	m_Column6Value = m_Column6Value * 3;
	Value.Format("%d", m_Column6Value);
	m_SectionTwo3.SetWindowText(Value);
	m_SectionTwo3.EnableWindow(FALSE);
	UpdateGameTotal();
}

void CMyYahtzeeDlg::UpdateGameTotal()
{
	if (m_Column1Scores == 6 && m_Column2Scores == 6 && m_Column3Scores == 6 &&
		m_Column4Scores == 7 && m_Column5Scores == 7 && m_Column6Scores == 7)
	{
		m_Undo.EnableWindow(FALSE);
		m_GameTotalValue = m_Column1Value + m_Column2Value + m_Column3Value + 
			m_Column4Value + m_Column5Value + m_Column6Value;
		CString Value;
		Value.Format("%d", m_GameTotalValue);
		m_GameTotal.SetWindowText(Value);
		m_GameTotal.EnableWindow(FALSE);
		if (m_HighScores.IsHighScore(m_GameTotalValue))
		{
			// New high score
			CHighScoreDlg dlg;
			if (m_SettingsDlg.m_HiScore)
				dlg.m_PlaySound = TRUE;
			else
				dlg.m_PlaySound = FALSE;
			dlg.m_Score = m_GameTotalValue;
			dlg.DoModal();
			CHighScore hs;
			COleDateTime date;
			date = COleDateTime::GetCurrentTime();
			CString datestr = date.Format(VAR_DATEVALUEONLY);
			strcpy(hs.m_Name, (LPCTSTR)dlg.m_Name);
			strcpy(hs.m_Date, (LPCTSTR)datestr);
			hs.m_Score = m_GameTotalValue;
			m_HighScores.AddHighScore(hs);
			CHighScoreSheetDlg hsdlg;
			hsdlg.m_pHighScoreSheet = &m_HighScores;
			hsdlg.DoModal();
			SaveHighScores();
		}
		m_RollDice.SetWindowText("&New Game");
	}
	else
	{
		m_GameTotalValue = m_Column1Value + m_Column2Value + m_Column3Value + 
			m_Column4Value + m_Column5Value + m_Column6Value;
		CString Value;
		Value.Format("%d", m_GameTotalValue);
		m_GameTotal.SetWindowText(Value);
		m_GameTotal.EnableWindow(FALSE);
	}
}

void CMyYahtzeeDlg::OnOk() 
{
	if (MessageBox("Are you sure you want to stop playing?", "Triple Yahtzee", MB_YESNO) == IDNO)
	{
		return;
	}
	SaveHighScores();
	theApp.PlayRandomSound("Exit", TRUE);
	CDialog::OnOK();
}


void CMyYahtzeeDlg::SaveHighScores()
{
	// Save high scores	
	CFile myFile;
	if (myFile.Open("Scores.bin", CFile::modeWrite | CFile::shareDenyNone))
	{
		myFile.Write(&m_HighScores, sizeof(m_HighScores));
		myFile.Close();
	}
	else
	{
		AfxMessageBox("Save file not found!");
	}
}

void CMyYahtzeeDlg::OnButton1() 
{
	CHighScoreDlg dlg;
	if (m_SettingsDlg.m_HiScore)
		dlg.m_PlaySound = TRUE;
	else
		dlg.m_PlaySound = FALSE;

	dlg.m_Score = (rand() % 100) + 1;
	dlg.DoModal();
	CHighScore hs;
	COleDateTime date;
	date = COleDateTime::GetCurrentTime();
	CString datestr = date.Format(VAR_DATEVALUEONLY);
	strcpy(hs.m_Name, (LPCTSTR)dlg.m_Name);
	strcpy(hs.m_Date, (LPCTSTR)datestr);
	hs.m_Score = dlg.m_Score;
	m_HighScores.AddHighScore(hs);
	CHighScoreSheetDlg hsdlg;
	hsdlg.m_pHighScoreSheet = &m_HighScores;
	hsdlg.DoModal();
}

void CMyYahtzeeDlg::LoadHighScores()
{
	// Load high scores
	CFile myFile;
	if (myFile.Open("Scores.bin", CFile::modeRead | CFile::shareDenyNone))
	{
		// Read in the high scores
		myFile.Read((void *)&m_HighScores, sizeof(m_HighScores));
		myFile.Close();
	}
	else
	{
		// File doesn't exist.  Let's populate the High Score Sheet
		m_HighScores.m_NumberOfScores = 0;
		for (int i = 0; i < 10; i++)
		{
			m_HighScores.m_Scores[i].m_Score = 0;
			strcpy(m_HighScores.m_Scores[i].m_Name, "Empty");
			strcpy(m_HighScores.m_Scores[i].m_Date, "");
		}
		// Lets save this file now, just for the heck of it
		HANDLE hFile = CreateFile("Scores.bin", GENERIC_WRITE, FILE_SHARE_WRITE, 
			NULL, CREATE_NEW, FILE_ATTRIBUTE_HIDDEN, NULL);
		ASSERT(myFile.Open("Scores.bin", CFile::modeWrite | CFile::shareDenyNone));
		myFile.Write(&m_HighScores, sizeof(m_HighScores));
		CloseHandle(hFile);
		myFile.Close();
	}
}

void CMyYahtzeeDlg::OnViewhighscores() 
{
	CHighScoreSheetDlg dlg;
	dlg.m_pHighScoreSheet = &m_HighScores;
	dlg.DoModal();
}

void CMyYahtzeeDlg::OnButton3() 
{
	if (m_UnlimitedRolls)
	{
		m_UnlimitedRolls = FALSE;
		m_Button3.SetWindowText("Unlimited Rolls OFF");
	}
	else
	{
		m_UnlimitedRolls = TRUE;
		m_Button3.SetWindowText("Unlimited Rolls ON");
	}
}

void CMyYahtzeeDlg::ResetGame() 
{
	m_RollDice.SetWindowText("&Roll Dice");

	ResetDice();

	m_NumYahtzees = 0;

	// Clear all values
	m_Column1Scores = 0;
	m_Column2Scores = 0;
	m_Column3Scores = 0;
	m_Column4Scores = 0; 
	m_Column5Scores = 0;
	m_Column6Scores = 0;
	m_One1Value = 0;
	m_One2Value = 0;
	m_One3Value = 0;
	m_Two1Value = 0;
	m_Two2Value = 0;
	m_Two3Value = 0;
	m_Three1Value = 0;
	m_Three2Value = 0;
	m_Three3Value = 0;
	m_Four1Value = 0;
	m_Four2Value = 0;
	m_Four3Value = 0;
	m_Five1Value = 0;
	m_Five2Value = 0;
	m_Five3Value = 0;
	m_Six1Value = 0;
	m_Six2Value = 0;
	m_Six3Value = 0;
	m_3OfAKind1Value = 0;
	m_3OfAKind2Value = 0;
	m_3OfAKind3Value = 0;
	m_4OfAKind1Value = 0;
	m_4OfAKind2Value = 0;
	m_4OfAKind3Value = 0;
	m_FullHouse1Value = 0;
	m_FullHouse2Value = 0;
	m_FullHouse3Value = 0;
	m_SmallStr1Value = 0;
	m_SmallStr2Value = 0;
	m_SmallStr3Value = 0;
	m_LargeStr1Value = 0;
	m_LargeStr2Value = 0;
	m_LargeStr3Value = 0;
	m_Yahtzee1Value = 0;
	m_Yahtzee2Value = 0;
	m_Yahtzee3Value = 0;
	m_Chance1Value = 0;
	m_Chance2Value = 0;
	m_Chance3Value = 0;
	m_Column1Scores = 0;
	m_Column2Scores = 0;
	m_Column3Scores = 0;
	m_Column4Scores = 0;
	m_Column5Scores = 0;
	m_Column6Scores = 0;
	m_GameTotalValue = 0;
	m_Column1Value = 0;
	m_Column2Value = 0;
	m_Column3Value = 0;
	m_Column4Value = 0;
	m_Column5Value = 0;
	m_Column6Value = 0;

	UpdateColumn1();
	UpdateColumn2();
	UpdateColumn3();
	UpdateColumn4();
	UpdateColumn5();
	UpdateColumn6();

	// Reenable all edit boxes
	m_One1.EnableWindow(TRUE);
	m_One2.EnableWindow(TRUE);
	m_One3.EnableWindow(TRUE);
	m_Two1.EnableWindow(TRUE);
	m_Two2.EnableWindow(TRUE);
	m_Two3.EnableWindow(TRUE);
	m_Three1.EnableWindow(TRUE);
	m_Three2.EnableWindow(TRUE);
	m_Three3.EnableWindow(TRUE);
	m_Four1.EnableWindow(TRUE);
	m_Four2.EnableWindow(TRUE);
	m_Four3.EnableWindow(TRUE);
	m_Five1.EnableWindow(TRUE);
	m_Five2.EnableWindow(TRUE);
	m_Five3.EnableWindow(TRUE);
	m_Six1.EnableWindow(TRUE);
	m_Six2.EnableWindow(TRUE);
	m_Six3.EnableWindow(TRUE);
	m_3OfAKind1.EnableWindow(TRUE);
	m_3OfAKind2.EnableWindow(TRUE);
	m_3OfAKind3.EnableWindow(TRUE);
	m_4OfAKind1.EnableWindow(TRUE);
	m_4OfAKind2.EnableWindow(TRUE);
	m_4OfAKind3.EnableWindow(TRUE);
	m_FullHouse1.EnableWindow(TRUE);
	m_FullHouse2.EnableWindow(TRUE);
	m_FullHouse3.EnableWindow(TRUE);
	m_LargeStr1.EnableWindow(TRUE);
	m_LargeStr2.EnableWindow(TRUE);
	m_LargeStr3.EnableWindow(TRUE);
	m_SmallStr1.EnableWindow(TRUE);
	m_SmallStr2.EnableWindow(TRUE);
	m_SmallStr3.EnableWindow(TRUE);
	m_Yahtzee1.EnableWindow(TRUE);
	m_Yahtzee2.EnableWindow(TRUE);
	m_Yahtzee3.EnableWindow(TRUE);
	m_Chance1.EnableWindow(TRUE);
	m_Chance2.EnableWindow(TRUE);
	m_Chance3.EnableWindow(TRUE);

	// Clear all window text
	m_One1.SetWindowText("");
	m_One2.SetWindowText("");
	m_One3.SetWindowText("");
	m_Two1.SetWindowText("");
	m_Two2.SetWindowText("");
	m_Two3.SetWindowText("");
	m_Three1.SetWindowText("");
	m_Three2.SetWindowText("");
	m_Three3.SetWindowText("");
	m_Four1.SetWindowText("");
	m_Four2.SetWindowText("");
	m_Four3.SetWindowText("");
	m_Five1.SetWindowText("");
	m_Five2.SetWindowText("");
	m_Five3.SetWindowText("");
	m_Six1.SetWindowText("");
	m_Six2.SetWindowText("");
	m_Six3.SetWindowText("");
	m_3OfAKind1.SetWindowText("");
	m_3OfAKind2.SetWindowText("");
	m_3OfAKind3.SetWindowText("");
	m_4OfAKind1.SetWindowText("");
	m_4OfAKind2.SetWindowText("");
	m_4OfAKind3.SetWindowText("");
	m_FullHouse1.SetWindowText("");
	m_FullHouse2.SetWindowText("");
	m_FullHouse3.SetWindowText("");
	m_LargeStr1.SetWindowText("");
	m_LargeStr2.SetWindowText("");
	m_LargeStr3.SetWindowText("");
	m_SmallStr1.SetWindowText("");
	m_SmallStr2.SetWindowText("");
	m_SmallStr3.SetWindowText("");
	m_Yahtzee1.SetWindowText("");
	m_Yahtzee2.SetWindowText("");
	m_Yahtzee3.SetWindowText("");
	m_Chance1.SetWindowText("");
	m_Chance2.SetWindowText("");
	m_Chance3.SetWindowText("");
	m_Total1.SetWindowText("");
	m_Total2.SetWindowText("");
	m_Total3.SetWindowText("");
	m_SectionOne1.SetWindowText("");
	m_SectionOne2.SetWindowText("");
	m_SectionOne3.SetWindowText("");
	m_SectionTwo1.SetWindowText("");
	m_SectionTwo2.SetWindowText("");
	m_SectionTwo3.SetWindowText("");
	m_Bonus1.SetWindowText("");
	m_Bonus2.SetWindowText("");
	m_Bonus3.SetWindowText("");
	m_GameTotal.SetWindowText("");
	m_Hold1.SetWindowText("");
	m_Hold2.SetWindowText("");
	m_Hold3.SetWindowText("");
	m_Hold4.SetWindowText("");
	m_Hold5.SetWindowText("");
}

void CMyYahtzeeDlg::OnResetgame() 
{
	if (MessageBox("Are you sure you want to reset the game?", "Triple Yahtzee", MB_YESNO) == IDYES) {
		SetDie(1, 6);
		SetDie(2, 6);
		SetDie(3, 6);
		SetDie(4, 6);
		SetDie(5, 6);
		ResetGame();	
	}
}

void CMyYahtzeeDlg::OnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}
  
char *pArrCredit = { "BITMAP1^||"
		"|Version 2.00|"
		"Copyright (c) 2004|"
        "All Rights Reserved|"
        "david.c.henkemeyer@intel.com||||"
        "* * * * * * * * *\t|||"
        "New 2.00 Features:\r||100 bonus points for hitting additional yahtzees|Updated Pencil Cursor|Fixed \"Undo\" bug|Added running totals||||"
        "* * * * * * * * *\t|||"
        "Credits:\r|||"
        "Project Lead\r|David Henkemeyer|||"
        "Technical Lead\r|David Henkemeyer|||"
        "Engineering Lead\r|David Henkemeyer|||"
        "Quality Assurance Lead\r|David Henkemeyer|||"
        "Engineering\r|David Henkemeyer|||"
        "Conceptual Design\r|David Henkemeyer|||"
        "Artwork\r|David Henkemeyer|||"
        "Sound Editor\r|Karen Henkemeyer|||"
		"Version 2.00 Assistant\r|Gabriel Henkemeyer|||"
        "Tail Wagging Support\r|Bella|||||||||||||||||||||"
//        "BITMAP2^|||"  // this is a quoted bitmap resource 

//        "BITMAP4^|||||"
        };

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_static.SubclassDlgItem(IDC_DISPLAY_STATIC,this);
	m_static.SetCredits(pArrCredit,'|');
	m_static.SetSpeed(DISPLAY_MEDIUM);
	m_static.SetColor(BACKGROUND_COLOR, RGB(0,0,0));
	m_static.SetTransparent();
//	m_static.SetBkImage(IDB_BACKGROUND);
	m_static.StartScrolling();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyYahtzeeDlg::OnSettings() 
{
	m_SettingsDlg.DoModal();
}


void CMyYahtzeeDlg::OnButton2() 
{
	if (m_SettingsDlg.m_DiceRoll)
		PlaySound("dice.wav", NULL, SND_ASYNC);
	if (m_RollNumber == 0)
	{
		m_Hold1.SetWindowText("");
		m_Hold2.SetWindowText("");
		m_Hold3.SetWindowText("");
		m_Hold4.SetWindowText("");
		m_Hold5.SetWindowText("");
		m_DieOneHeld = FALSE;
		m_DieTwoHeld = FALSE;
		m_DieThreeHeld = FALSE;
		m_DieFourHeld = FALSE;
		m_DieFiveHeld = FALSE;
	}
	m_Undo.EnableWindow(FALSE);
	m_ClickOnDice.SetWindowText("");
	m_SelectingDice = FALSE;
	m_RollNumber++;
	int RollTime = 900 + (rand() % 100);
#ifdef _DEBUG
	RollTime = 31;
#endif
	SetTimer(4, RollTime, NULL);
	m_RollDice.EnableWindow(FALSE);
	
}
