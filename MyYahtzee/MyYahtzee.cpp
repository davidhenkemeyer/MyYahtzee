// MyYahtzee.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyYahtzee.h"
#include "MyYahtzeeDlg.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeApp

BEGIN_MESSAGE_MAP(CMyYahtzeeApp, CWinApp)
	//{{AFX_MSG_MAP(CMyYahtzeeApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeApp construction

CMyYahtzeeApp::CMyYahtzeeApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyYahtzeeApp object

CMyYahtzeeApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMyYahtzeeApp initialization

BOOL CMyYahtzeeApp::InitInstance()
{
	AfxEnableControlContainer();

	CRegKey regKey;
	regKey.Create(HKEY_LOCAL_MACHINE, "Software\\Henkemeyer Software\\Triple Yahztee");
	regKey.Close();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMyYahtzeeDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}


void CMyYahtzeeApp::PlayRandomSound(CString Directory, BOOL bSync)
{
	int x = 0;
	WIN32_FIND_DATA findData;
	HANDLE hFile = FindFirstFile(Directory + "\\*.wav", &findData);
	while (hFile != INVALID_HANDLE_VALUE)
	{
		x++;
		TRACE("File:  %s\n", findData.cFileName);
		if (FindNextFile(hFile, &findData) == FALSE)
			break;
	}

	if (x == 0)
		return;

	int res = rand() % x;

	x = 0;
	hFile = FindFirstFile(Directory + "\\*.wav", &findData);
	while (hFile != INVALID_HANDLE_VALUE)
	{
		if (x == res)
		{
			// Play this sound!
			CString soundFile = Directory + "\\";
			soundFile += findData.cFileName;
			TRACE("Playing File:  %s\n", findData.cFileName);
			if (bSync) {
				PlaySound(soundFile, NULL, SND_SYNC);
			} else {
				PlaySound(soundFile, NULL, SND_ASYNC);
			}

		}
		x++;
		if (FindNextFile(hFile, &findData) == FALSE)
			break;
	}
}
