// HighScoreSheet.cpp: implementation of the CHighScoreSheet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyYahtzee.h"
#include "HighScoreSheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHighScoreSheet::CHighScoreSheet()
{

}

CHighScoreSheet::~CHighScoreSheet()
{

}

BOOL CHighScoreSheet::IsHighScore(int Score)
{
	return (Score > m_Scores[9].m_Score);
}

void CHighScoreSheet::AddHighScore(CHighScore HighScore)
{
	for (int i = 0; i < 10; i++)
	{
		if (m_Scores[i].m_Score < HighScore.m_Score)
		{
			for (int j = 9; j > i; j--)
			{
				m_Scores[j] = m_Scores[j-1];
			}
			m_Scores[j] = HighScore; 
			break;
		}
	}
}

void CHighScoreSheet::Clear()
{
	for (int i = 0; i < 10; i++)
	{
		m_Scores[i].m_Score = 0;
		strcpy(m_Scores[i].m_Name, "Empty");
		strcpy(m_Scores[i].m_Date, "");
	}
}
