/*******************************************************************************
**                                                                            **
**                     I N T E L   P R O P R I E T A R Y                      **
**                                                                            **
**   COPYRIGHT (c) 1993-1998 BY INTEL CORPORATION. ALL RIGHTS RESERVED.  NO   **
**   PART  OF  THIS  PROGRAM OR PUBLICATION MAY BE REPRODUCED, TRANSMITTED,   **
**   TRANSCRIBED, STORED IN A RETRIEVAL  SYSTEM,  OR  TRANSLATED  INTO  ANY   **
**   LANGUAGE OR COMPUTER LANGUAGE IN ANY FORM OR BY ANY MEANS, ELECTRONIC,   **
**   MECHANICAL, MAGNETIC, OPTICAL, CHEMICAL, MANUAL, OR OTHERWISE, WITHOUT   **
**   THE PRIOR WRITTEN PERMISSION OF :                                        **
**                                                                            **
**                             INTEL CORPORATION                              **
**                                                                            **
**                          2200 MISSON COLLEGE BLVD                          **
**                                                                            **
**                     SANTA CLARA, CALIFORNIA 95052-8119                     **
**                                                                            **
********************************************************************************

  $History: RegKey.h $
* 
* *****************  Version 1  *****************
* User: Dhenkeme     Date: 10/08/99   Time: 10:35a
* Created in $/DSL/Personal/Henky/Yahtzee
* 
* *****************  Version 6  *****************
* User: Dhenkeme     Date: 5/24/99    Time: 3:54p
* Updated in $/DSL/ConfigWizard/DslSetup
* 
* *****************  Version 5  *****************
* User: Dhenkeme     Date: 5/07/99    Time: 9:33a
* Updated in $/DSL/ConfigWizard/DslSetup
* 
* *****************  Version 3  *****************
* User: Dhenkeme     Date: 4/29/99    Time: 1:59p
* Updated in $/DSL/ConfigWizard
* 
* *****************  Version 2  *****************
* User: Dhenkeme     Date: 3/23/99    Time: 2:48p
* Updated in $/DSL/ConfigWizard
* Broke out all classes into their own seperate files
* 
* *****************  Version 1  *****************
* User: Dhenkeme     Date: 3/23/99    Time: 1:17p
* Created in $/DSL/ConfigWizard
* 
* *****************  Version 12  *****************
* User: Sfeldma      Date: 7/02/98    Time: 7:30p
* Updated in $/Seaside/Development/Prosetp.cpl
* * EGuadalu - Modified various container classes to derive from
* CPointerArray.
*   lots of code was removed since it is now provided for by the base
* class.
* * CEventLogRecords, CErrorConditions, CProperties, CTeams, CSettings,
* CAdapters, CDevices
* 
* *****************  Version 11  *****************
* User: Sfeldma      Date: 6/24/98    Time: 9:34a
* Updated in $/Seaside/Development/Prosetp.cpl
* 
* *****************  Version 10  *****************
* User: Dhenkeme     Date: 5/27/98    Time: 10:46a
* Updated in $/Seaside/Development/Prosetp.cpl
* Added "Intel Proprietary" header and VSS History keyword

*******************************************************************************/
// RegKey.h: interface for the CRegKey class.
//
//////////////////////////////////////////////////////////////////////

#include <afxtempl.h>

#if !defined(AFX_REGKEY_H__B1AB73A3_45AA_11D1_80A6_00A0C95A2C7A__INCLUDED_)
#define AFX_REGKEY_H__B1AB73A3_45AA_11D1_80A6_00A0C95A2C7A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CRegKey  
{
private:		// Private members
	HKEY	m_hKey;
	BOOL	m_Opened;
	LONG	m_Result;
	DWORD	m_EnumIndex;

private:		// Private methods
	void Init();
	CString GetStringFromID(UINT ID);
public:			// Constructors and destructor
	CRegKey();
	CRegKey(const CRegKey& rhs);
	virtual ~CRegKey();
public:			// Public methods
	DWORD GetRegType(CString& ValueName);

	BOOL Open(HKEY hKey, const CString& SubKey, BOOL ReadWrite = FALSE);
	BOOL Open(HKEY hKey, UINT SubKeyID, BOOL ReadWrite = FALSE);
	
	BOOL Create(HKEY hKey, const CString& SubKey, BOOL ReadWrite = FALSE,
		BOOL Volatile = FALSE);
	BOOL Create(HKEY hKey, UINT SubKeyID, BOOL ReadWrite = FALSE,
		BOOL Volatile = FALSE);

	void Close();

	BOOL SubKeyExists(const CString& SubKey);
	BOOL SubKeyExists(UINT SubKeyID);
	HKEY GetHKey();

	void GetValue(const CString& ValueName, DWORD* Value, DWORD Default = 0);
	void GetValue(UINT ValueNameID, DWORD* Value, DWORD Default = 0);

	void GetValue(const CString& ValueName, CString* Value,
		CString Default = CString(_T("")), BOOL ExpandSZ = FALSE);
	void GetValue(UINT ValueNameID, CString* Value,
		CString Default = CString(_T("")), BOOL ExpandSZ = FALSE);
	void GetValue(UINT ValueNameID, CString* Value,
		UINT DefaultID, BOOL ExpandSZ = FALSE);

	void GetValue(const CString& ValueName, BYTE* Value, DWORD* cbData);
	void GetValue(UINT ValueNameID, BYTE* Value, DWORD* cbData);

	void CRegKey::GetValue(const CString& ValueName, 
		CArray<CString, CString&>* Value, DWORD* cbData = NULL);
	void CRegKey::GetValue(UINT ValueNameID, 
		CArray<CString, CString&>* Value, DWORD* cbData = NULL);

	void SetValue(const CString& ValueName, DWORD Value);
	void SetValue(UINT ValueNameID, DWORD Value);

	void SetValue(const CString& ValueName, CString Value, BOOL ExpandSZ = FALSE);
	void SetValue(UINT ValueNameID, CString Value, BOOL ExpandSZ = FALSE);

	void SetValue(const CString& ValueName, BYTE* Value, DWORD cbData);
	void SetValue(UINT ValueNameID, BYTE* Value, DWORD cbData);

	void SetValue(const CString& ValueName, const CArray<CString, CString&>& Value);
	void SetValue(UINT ValueNameID, const CArray<CString, CString&>& Value);

	BOOL EnumSubKey(CString* pSubKeyName);
	BOOL EnumValue(CString* pValueName);

	BOOL DeleteSubKey(const CString& SubKeyName);
	BOOL DeleteSubKey(UINT SubKeyNameID);

	BOOL DeleteValue(const CString& ValueName);
	BOOL DeleteValue(UINT SubKeyNameID);
	
	LONG LastResult();
};

#endif // !defined(AFX_REGKEY_H__B1AB73A3_45AA_11D1_80A6_00A0C95A2C7A__INCLUDED_)
