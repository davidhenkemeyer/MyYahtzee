// HighScoreSheet.h: interface for the CHighScoreSheet class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HIGHSCORESHEET_H__C03CD002_E352_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_HIGHSCORESHEET_H__C03CD002_E352_11D2_8916_00A0C9F74786__INCLUDED_

#include "HighScore.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHighScoreSheet  
{
public:
	void Clear();
	void AddHighScore(CHighScore HighScore);
	BOOL IsHighScore(int Score);
	CHighScore m_Scores[10];
	UINT m_NumberOfScores;
	CHighScoreSheet();
	virtual ~CHighScoreSheet();

};

#endif // !defined(AFX_HIGHSCORESHEET_H__C03CD002_E352_11D2_8916_00A0C9F74786__INCLUDED_)
