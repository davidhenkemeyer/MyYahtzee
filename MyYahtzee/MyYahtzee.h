// MyYahtzee.h : main header file for the MYYAHTZEE application
//

#if !defined(AFX_MYYAHTZEE_H__93371CC4_E1F7_11D2_8916_00A0C9F74786__INCLUDED_)
#define AFX_MYYAHTZEE_H__93371CC4_E1F7_11D2_8916_00A0C9F74786__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include <mmsystem.h>

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeApp:
// See MyYahtzee.cpp for the implementation of this class
//

class CMyYahtzeeApp : public CWinApp
{
public:
	void PlayRandomSound(CString Directory, BOOL bSync = FALSE);
	CMyYahtzeeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyYahtzeeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyYahtzeeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMyYahtzeeApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYYAHTZEE_H__93371CC4_E1F7_11D2_8916_00A0C9F74786__INCLUDED_)
