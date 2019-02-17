// HighScore.h: interface for the CHighScore class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HIGHSCORE_H__EB7F4E65_E30B_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_HIGHSCORE_H__EB7F4E65_E30B_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHighScore  
{
public:
	char m_Date[20];
	char m_Name[20];
	int m_Score;
	CHighScore();
	virtual ~CHighScore();

};

#endif // !defined(AFX_HIGHSCORE_H__EB7F4E65_E30B_11D2_8916_00A0C9F74786__INCLUDED_)
