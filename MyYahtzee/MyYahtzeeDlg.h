// MyYahtzeeDlg.h : header file
//

#if !defined(AFX_MYYAHTZEEDLG_H__93371CC6_E1F7_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_MYYAHTZEEDLG_H__93371CC6_E1F7_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyEditCtrl.h"
#include "ReadOnlyEditCtrl.h"
#include "YahtzeeDlg.h"	// Added by ClassView
#include "HighScoreSheet.h"
#include "SettingsDlg.h"
#include <afxtempl.h>

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeDlg dialog

class CMyYahtzeeDlg : public CDialog
{
// Construction
public:
	DWORD m_NumYahtzees;
	CSettingsDlg m_SettingsDlg;
	BOOL m_UnlimitedRolls;
	void LoadHighScores();
	CHighScoreSheet m_HighScores;
	void SaveHighScores();
	CYahtzeeDlg m_YahtzeeDlg;
	DWORD * m_pColumnPtr;
	DWORD * m_pValuePtr;
	CMyEditCtrl * pUndoCtrl;
	void ResetGame();
	CString m_OldDiceFrame;
	DWORD m_OldRollNumber;
	CString m_OldText;
	void UpdateGameTotal();
	void UpdateColumn6();
	void UpdateColumn5();
	void UpdateColumn4();
	void UpdateColumn3();
	void UpdateColumn2();
	DWORD m_Column1Scores;
	DWORD m_Column2Scores;
	DWORD m_Column3Scores;
	DWORD m_Column4Scores;
	DWORD m_Column5Scores;
	DWORD m_Column6Scores;
	void UpdateColumn1();
	BOOL Rolled1();
	BOOL Rolled2();
	BOOL Rolled3();
	BOOL Rolled4();
	BOOL Rolled5();
	BOOL Rolled6();
	BOOL IsSmallStraight();
	BOOL IsLargeStraight();
	BOOL IsFullHouse();
	BOOL IsYahtzee();
	DWORD GetNumberValue(DWORD Number);
	DWORD GetChanceValue();
	void ResetDice();
	BOOL m_Scoring;
	DWORD m_GameTotalValue;
	DWORD m_Column1Value;
	DWORD m_Column2Value;
	DWORD m_Column3Value;
	DWORD m_Column4Value;
	DWORD m_Column5Value;
	DWORD m_Column6Value;
	DWORD m_One1Value;
	DWORD m_One2Value;
	DWORD m_One3Value;
	DWORD m_Two1Value;
	DWORD m_Two2Value;
	DWORD m_Two3Value;
	DWORD m_Three1Value;
	DWORD m_Three2Value;
	DWORD m_Three3Value;
	DWORD m_Four1Value;
	DWORD m_Four2Value;
	DWORD m_Four3Value;
	DWORD m_Five1Value;
	DWORD m_Five2Value;
	DWORD m_Five3Value;
	DWORD m_Six1Value;
	DWORD m_Six2Value;
	DWORD m_Six3Value;
	DWORD m_Yahtzee1Value;
	DWORD m_Yahtzee2Value;
	DWORD m_Yahtzee3Value;
	DWORD m_Chance1Value;
	DWORD m_Chance2Value;
	DWORD m_Chance3Value;
	DWORD m_FullHouse1Value;
	DWORD m_FullHouse2Value;
	DWORD m_FullHouse3Value;
	DWORD m_3OfAKind1Value;
	DWORD m_3OfAKind2Value;
	DWORD m_3OfAKind3Value;
	DWORD m_4OfAKind1Value;
	DWORD m_4OfAKind2Value;
	DWORD m_4OfAKind3Value;
	DWORD m_SmallStr1Value;
	DWORD m_SmallStr2Value;
	DWORD m_SmallStr3Value;
	DWORD m_LargeStr1Value;
	DWORD m_LargeStr2Value;
	DWORD m_LargeStr3Value;
	DWORD Get3OfAKindValue();
	DWORD Get4OfAKindValue();
	BOOL m_SelectingDice;
	BOOL m_DieOneHeld;
	BOOL m_DieTwoHeld;
	BOOL m_DieThreeHeld;
	BOOL m_DieFourHeld;
	BOOL m_DieFiveHeld;

	HICON m_Icon1;
	HICON m_Icon2;
	HICON m_Icon3;
	HICON m_Icon4;
	HICON m_Icon5;
	HICON m_Icon6;
	
	void SetDie(DWORD DieNumber, DWORD DieValue);
	DWORD GetRandValue(DWORD PreviousValue);
	DWORD m_DieOneValue;
	DWORD m_DieTwoValue;
	DWORD m_DieThreeValue;
	DWORD m_DieFourValue;
	DWORD m_DieFiveValue;
	DWORD m_RollNumber;
	CMyYahtzeeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyYahtzeeDlg)
	enum { IDD = IDD_MYYAHTZEE_DIALOG };
	CButton	m_Button2;
	CButton	m_Settings;
	CButton	m_ResetGame;
	CButton	m_Button3;
	CButton	m_Button1;
	CButton	m_Undo;
	CButton	m_DiceFrame;
	CStatic	m_ClickOnDice;
	CStatic	m_Hold5;
	CStatic	m_Hold4;
	CStatic	m_Hold3;
	CStatic	m_Hold2;
	CStatic	m_Hold1;
	CStatic	m_DieTwo;
	CStatic	m_DieThree;
	CStatic	m_DieOne;
	CStatic	m_DieFour;
	CStatic	m_DieFive;
	CMyEditCtrl	m_Yahtzee3;
	CMyEditCtrl	m_Yahtzee2;
	CMyEditCtrl	m_Yahtzee1;
	CMyEditCtrl	m_Two3;
	CMyEditCtrl	m_Two2;
	CMyEditCtrl	m_Two1;
	CReadOnlyEditCtrl	m_Total3;
	CReadOnlyEditCtrl	m_Total2;
	CReadOnlyEditCtrl	m_Total1;
	CMyEditCtrl	m_Three3;
	CMyEditCtrl	m_Three2;
	CMyEditCtrl	m_Three1;
	CMyEditCtrl	m_SmallStr3;
	CMyEditCtrl	m_SmallStr2;
	CMyEditCtrl	m_SmallStr1;
	CMyEditCtrl	m_Six3;
	CMyEditCtrl	m_Six2;
	CMyEditCtrl	m_Six1;
	CReadOnlyEditCtrl	m_SectionTwo3;
	CReadOnlyEditCtrl	m_SectionTwo2;
	CReadOnlyEditCtrl	m_SectionTwo1;
	CReadOnlyEditCtrl	m_SectionOne2;
	CReadOnlyEditCtrl	m_SectionOne1;
	CReadOnlyEditCtrl	m_SectionOne3;
	CButton	m_RollDice;
	CMyEditCtrl	m_One3;
	CMyEditCtrl	m_One2;
	CMyEditCtrl	m_One1;
	CMyEditCtrl	m_LargeStr3;
	CMyEditCtrl	m_LargeStr2;
	CMyEditCtrl	m_LargeStr1;
	CReadOnlyEditCtrl	m_GameTotal;
	CMyEditCtrl	m_FullHouse3;
	CMyEditCtrl	m_FullHouse2;
	CMyEditCtrl	m_FullHouse1;
	CMyEditCtrl	m_Four3;
	CMyEditCtrl	m_Four2;
	CMyEditCtrl	m_Four1;
	CMyEditCtrl	m_Five3;
	CMyEditCtrl	m_Five2;
	CMyEditCtrl	m_Five1;
	CMyEditCtrl	m_Chance3;
	CMyEditCtrl	m_Chance2;
	CMyEditCtrl	m_Chance1;
	CReadOnlyEditCtrl	m_Bonus3;
	CReadOnlyEditCtrl	m_Bonus2;
	CReadOnlyEditCtrl	m_Bonus1;
	CMyEditCtrl	m_4OfAKind3;
	CMyEditCtrl	m_4OfAKind2;
	CMyEditCtrl	m_4OfAKind1;
	CMyEditCtrl	m_3OfAKind3;
	CMyEditCtrl	m_3OfAKind2;
	CMyEditCtrl	m_3OfAKind1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyYahtzeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyYahtzeeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRollDice();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDieFive();
	afx_msg void OnDieFour();
	afx_msg void OnDieOne();
	afx_msg void OnDieThree();
	afx_msg void OnDieTwo();
	afx_msg void OnSetfocus3ofkind1();
	afx_msg void OnSetfocus3ofkind2();
	afx_msg void OnSetfocus3ofkind3();
	afx_msg void OnSetfocus4ofkind1();
	afx_msg void OnSetfocus4ofkind2();
	afx_msg void OnSetfocus4ofkind3();
	afx_msg void OnSetfocusChance1();
	afx_msg void OnSetfocusChance2();
	afx_msg void OnSetfocusChance3();
	afx_msg void OnSetfocusFive1();
	afx_msg void OnSetfocusFive2();
	afx_msg void OnSetfocusFive3();
	afx_msg void OnSetfocusFour1();
	afx_msg void OnSetfocusFour2();
	afx_msg void OnSetfocusFour3();
	afx_msg void OnSetfocusFullhouse1();
	afx_msg void OnSetfocusFullhouse2();
	afx_msg void OnSetfocusFullhouse3();
	afx_msg void OnSetfocusLargestr1();
	afx_msg void OnSetfocusLargestr2();
	afx_msg void OnSetfocusLargestr3();
	afx_msg void OnSetfocusOne1();
	afx_msg void OnSetfocusOne2();
	afx_msg void OnSetfocusOne3();
	afx_msg void OnSetfocusSix1();
	afx_msg void OnSetfocusSix2();
	afx_msg void OnSetfocusSix3();
	afx_msg void OnSetfocusSmallstr1();
	afx_msg void OnSetfocusSmallstr2();
	afx_msg void OnSetfocusSmallstr3();
	afx_msg void OnSetfocusThree1();
	afx_msg void OnSetfocusThree2();
	afx_msg void OnSetfocusThree3();
	afx_msg void OnSetfocusTwo1();
	afx_msg void OnSetfocusTwo2();
	afx_msg void OnSetfocusTwo3();
	afx_msg void OnSetfocusYahtzee1();
	afx_msg void OnSetfocusYahtzee2();
	afx_msg void OnSetfocusYahtzee3();
	afx_msg void OnOk();
	afx_msg void OnUndo();
	afx_msg void OnButton1();
	afx_msg void OnViewhighscores();
	afx_msg void OnButton3();
	afx_msg void OnResetgame();
	afx_msg void OnAbout();
	afx_msg void OnSettings();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYYAHTZEEDLG_H__93371CC6_E1F7_11D2_8916_00A0C9F74786__INCLUDED_)
