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

  $History: RegKey.cpp $
 * 
 * *****************  Version 17  *****************
 * User: Sfeldma      Date: 7/02/98    Time: 7:30p
 * Updated in $/Seaside/Development/Prosetp.cpl
 * * EGuadalu - Modified various container classes to derive from
 * CPointerArray.
 *   lots of code was removed since it is now provided for by the base
 * class.
 * * CEventLogRecords, CErrorConditions, CProperties, CTeams, CSettings,
 * CAdapters, CDevices
 * 
 * *****************  Version 16  *****************
 * User: Sfeldma      Date: 7/05/98    Time: 6:53p
 * Updated in $/Seaside/Development/Prosetp.cpl
 * Passing the correct number of bytes in ::SetValue for REG_SZ.
 * 
 * *****************  Version 15  *****************
 * User: Sfeldma      Date: 6/24/98    Time: 9:34a
 * Updated in $/Seaside/Development/Prosetp.cpl
 * 
 * *****************  Version 14  *****************
 * User: Dhenkeme     Date: 5/27/98    Time: 10:46a
 * Updated in $/Seaside/Development/Prosetp.cpl
 * Added "Intel Proprietary" header and VSS History keyword

*******************************************************************************/
// RegKey.cpp: implementation of the CRegKey class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RegKey.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRegKey::CRegKey()
{
	Init();
}

CRegKey::CRegKey(const CRegKey& rhs)
{
    UNREFERENCED_PARAMETER(rhs);
	// Don't allow copies of this object.
	TRACE("CRegKey doesn't allow object copies!\n");
	ASSERT(FALSE);
}

CRegKey::~CRegKey()
{
	Close();
}

void CRegKey::Init()
{
	m_hKey = NULL;
	m_Opened = FALSE;
	m_Result = ERROR_SUCCESS;
	m_EnumIndex = 0;
}

BOOL CRegKey::Open(HKEY hKey, const CString& SubKey, BOOL ReadWrite)
{
	REGSAM	Sam;

	if (m_Opened)
		RegCloseKey(m_hKey);

	Sam = ReadWrite ? KEY_READ | KEY_WRITE : KEY_READ;

	m_Result = RegOpenKeyEx(hKey, SubKey, 0,
		Sam, &m_hKey);
	m_Opened = (m_Result == ERROR_SUCCESS);
	
	return m_Opened;
}

BOOL CRegKey::Open(HKEY hKey, UINT SubKeyID, BOOL ReadWrite)
{
	return Open(hKey, GetStringFromID(SubKeyID), ReadWrite);
}

BOOL CRegKey::Create(HKEY hKey, const CString& SubKey, 
	BOOL ReadWrite, BOOL Volatile)
{
	DWORD	dwReason;
	REGSAM	Sam;
	DWORD	Options;

	if (m_Opened)
		RegCloseKey(m_hKey);

	Sam = ReadWrite ? KEY_READ | KEY_WRITE : KEY_READ;
	Options = Volatile ? REG_OPTION_VOLATILE : REG_OPTION_NON_VOLATILE;

	m_Result = RegCreateKeyEx(hKey, SubKey, 0, 0, Options, Sam, 
		0, &m_hKey, &dwReason);
	m_Opened = (m_Result == ERROR_SUCCESS);

	return m_Opened;
}

BOOL CRegKey::Create(HKEY hKey, UINT SubKeyID, BOOL ReadWrite, BOOL Volatile)
{
	return Create(hKey, GetStringFromID(SubKeyID), ReadWrite, Volatile);
}

BOOL CRegKey::SubKeyExists(const CString& SubKey)
{
	CRegKey	TempKey;
	return TempKey.Open(m_hKey, SubKey, FALSE);
}

BOOL CRegKey::SubKeyExists(UINT SubKeyID)
{
	return SubKeyExists(GetStringFromID(SubKeyID));
}

HKEY CRegKey::GetHKey()
{
	return m_hKey;
}

LONG CRegKey::LastResult()
{
	return m_Result;
}

// REG_DWORD
void CRegKey::GetValue(const CString& ValueName, DWORD* Value, DWORD Default)
{
	DWORD	dwRegType = REG_DWORD;
	DWORD	dwSize = sizeof(DWORD);

	m_Result = ERROR_SUCCESS;
	
	if (!m_Opened)
	{
		*Value = 0;
		return;
	}
	
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, &dwRegType, 
		(BYTE *)Value, &dwSize);

	if (m_Result != ERROR_SUCCESS)
		*Value = Default;
}

void CRegKey::GetValue(UINT ValueNameID, DWORD* Value, DWORD Default)
{
	GetValue(GetStringFromID(ValueNameID), Value, Default);
}

// REG_SZ
void CRegKey::GetValue(const CString& ValueName, CString* Value,
	CString Default, BOOL ExpandSZ)
{
	DWORD	dwRegType = REG_SZ;
	DWORD	dwSize = 0;

	if (ExpandSZ)
		dwRegType = REG_EXPAND_SZ;

	m_Result = ERROR_SUCCESS;
	
	// If we haven't opened the key, return empty string
	if (!m_Opened)
	{
		*Value = __TEXT("");
		return;
	}
	
	// Get the size of the string
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, &dwRegType, 
		NULL, &dwSize);

	// If error (i.e value not found), set to default value
	if (m_Result != ERROR_SUCCESS)
	{
		*Value = Default;
		return;
	}

	// Get the string from the registry and place it directly
	// into the CString buffer.
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, &dwRegType, 
		(BYTE *)Value->GetBufferSetLength(dwSize), &dwSize);
	Value->ReleaseBuffer();

	// If error (i.e value not found), set to default value
	if (m_Result != ERROR_SUCCESS)
	{
		*Value = Default;
		return;
	}

	if (ExpandSZ)
	{
		CString ExpandedString;
		DWORD size = ExpandEnvironmentStrings(*Value , NULL, 0);
		ExpandEnvironmentStrings(*Value, 
			ExpandedString.GetBufferSetLength(size), size);
		ExpandedString.ReleaseBuffer();
		*Value = ExpandedString;
	}
}

void CRegKey::GetValue(UINT ValueNameID, CString* Value,
	CString Default, BOOL ExpandSZ)
{
	GetValue(GetStringFromID(ValueNameID), Value, Default, ExpandSZ);
}

void CRegKey::GetValue(UINT ValueNameID, CString* Value,
	UINT DefaultID, BOOL ExpandSZ)
{
	GetValue(GetStringFromID(ValueNameID), Value, 
		GetStringFromID(DefaultID), ExpandSZ);
}

// REG_BINARY
void CRegKey::GetValue(const CString& ValueName, BYTE* Value,
	DWORD* cbData)
{
	DWORD	dwRegType = REG_BINARY;
	
	*cbData = 0;
	m_Result = ERROR_SUCCESS;
	
	// If we haven't opened the key, return
	if (!m_Opened)
		return;
	
	// Get the size of the data
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, &dwRegType, 
		NULL, cbData);

	// Get the binary data from the registry
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, &dwRegType, 
		Value, cbData);
}


void CRegKey::GetValue(UINT ValueNameID, BYTE* Value,
	DWORD* cbData)
{
	GetValue(GetStringFromID(ValueNameID), Value, cbData);
}

// REG_MULTI_SZ
void CRegKey::GetValue(const CString& ValueName, 
	CArray<CString, CString&>* Value, DWORD* cbData)
{
	DWORD	dwRegType = REG_MULTI_SZ;

	if (cbData != NULL)
		*cbData = 0;
	
	m_Result = ERROR_SUCCESS;
	
	// Empty the array
	Value->RemoveAll();
	
	// If we haven't opened the key, return
	if (!m_Opened)
		return;

	DWORD tmpSize;
	
	// Get the size of the data
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, NULL, 
		NULL, &tmpSize);

	LPBYTE Buffer;
	Buffer = (LPBYTE)malloc((size_t)tmpSize);
	// Get the binary data from the registry
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, NULL, 
		Buffer, &tmpSize);

	if (m_Result != ERROR_SUCCESS)
	{
		free(Buffer);
		return;
	}
	
	if (cbData != NULL)
		*cbData = 0;
	
	CString tmpString;
	for (LPBYTE p = Buffer; p[0] != '\0'; p += tmpString.GetLength() + 1)
	{
		if (cbData != NULL)
			(*cbData)++;
		tmpString = p;
		Value->Add( tmpString );
	}

	free(Buffer);
}

void CRegKey::GetValue(UINT ValueNameID, CArray<CString, CString&>* Value,
	DWORD* cbData)
{
	GetValue(GetStringFromID(ValueNameID), Value, cbData);
}

// REG_DWORD
void CRegKey::SetValue(const CString& ValueName, DWORD Value)
{
	m_Result = ERROR_SUCCESS;
	
	if (!m_Opened)
		return;
	
	m_Result = RegSetValueEx(m_hKey, ValueName, 0, REG_DWORD, 
		(BYTE *)&Value, sizeof(DWORD));
}

void CRegKey::SetValue(UINT ValueNameID, DWORD Value)
{
	SetValue(GetStringFromID(ValueNameID), Value);
}

// REG_SZ
void CRegKey::SetValue(const CString& ValueName, CString Value, BOOL ExpandSZ)
{
	m_Result = ERROR_SUCCESS;
	DWORD dwType = REG_SZ;
	
	if (!m_Opened)
		return;

	if (ExpandSZ)
		dwType = REG_EXPAND_SZ;
	
	m_Result = RegSetValueEx(m_hKey, ValueName, 0, dwType, 
		(BYTE *)(LPCTSTR)Value, Value.GetLength() + 1);
}

void CRegKey::SetValue(UINT ValueNameID, CString Value, BOOL ExpandSZ)
{
	SetValue(GetStringFromID(ValueNameID), Value, ExpandSZ);
}

// REG_BINARY
void CRegKey::SetValue(const CString& ValueName, BYTE* Value, DWORD cbData)
{
	m_Result = ERROR_SUCCESS;
	
	if (!m_Opened)
		return;
	
	m_Result = RegSetValueEx(m_hKey, ValueName, 0, REG_BINARY, 
		Value, cbData);
}

void CRegKey::SetValue(UINT ValueNameID, BYTE* Value, DWORD cbData)
{
	SetValue(GetStringFromID(ValueNameID), Value, cbData);
}

// REG_MULTI_SZ
void CRegKey::SetValue(const CString& ValueName, 
	const CArray<CString, CString&>& Value)
{
	m_Result = ERROR_SUCCESS;
	
	if (!m_Opened)
		return;
	
	DWORD BufferSize = 0;

	for (int i = 0; i < Value.GetSize(); i++)
	{
		// Add 1 for the delimiting '\0' characters
		BufferSize += Value.GetAt(i).GetLength() + 1;	
	}

	BufferSize++;	// For the last '\0'

	LPBYTE Buffer;
	Buffer = (LPBYTE)malloc((size_t)BufferSize);
	LPBYTE p = Buffer;

	for (i = 0; i < Value.GetSize(); i++)
	{
		_tcscpy((char *)p, Value.GetAt(i));
		p += Value.GetAt(i).GetLength() + 1;
	}

	Buffer[BufferSize-1] = '\0';

	m_Result = RegSetValueEx(m_hKey, ValueName, 0, REG_MULTI_SZ, 
		Buffer, BufferSize);

	free(Buffer);
}

void CRegKey::SetValue(UINT ValueNameID, 
	const CArray<CString, CString&>& Value)
{
	SetValue(GetStringFromID(ValueNameID), Value);
}

BOOL CRegKey::EnumSubKey(CString* pSubKeyName)
{
	DWORD		cbName = 256;
	TCHAR		TempBuffer[256];
	FILETIME	FileTime;
	
	if (!m_Opened)
		return FALSE;

	if (pSubKeyName->IsEmpty())
		m_EnumIndex = 0;

	m_Result = RegEnumKeyEx(m_hKey, m_EnumIndex++, TempBuffer,
		&cbName, 0, NULL, NULL, &FileTime);

	if (m_Result == ERROR_SUCCESS)
		*pSubKeyName = TempBuffer;
	else
		pSubKeyName->Empty();
	
	if (m_Result == ERROR_NO_MORE_ITEMS)
		m_EnumIndex = 0;
	
	return (m_Result == ERROR_SUCCESS);
}


BOOL CRegKey::EnumValue(CString* pValueName)
{
	DWORD		cbName = 256;
	TCHAR		TempBuffer[256];
	
	if (!m_Opened)
		return FALSE;

	if (pValueName->IsEmpty())
		m_EnumIndex = 0;

	// Get the size of the data
	m_Result = RegEnumValue(m_hKey, m_EnumIndex++, TempBuffer,
		&cbName, 0, NULL, NULL, NULL);

	if (m_Result == ERROR_SUCCESS)
		*pValueName = TempBuffer;
	else
		pValueName->Empty();
	
	if (m_Result == ERROR_NO_MORE_ITEMS)
		m_EnumIndex = 0;
	
	return (m_Result == ERROR_SUCCESS);
}

BOOL CRegKey::DeleteSubKey(const CString& SubKeyName)
{
	CRegKey SubKey;
	CString SubSubKeyName;
	CArray <CString, CString&> SubSubKeyList;
	
	// Check if the parent key has been opened
	if (!m_Opened)
		return FALSE;

	// Check if the subkey name is not empty
	if (SubKeyName.IsEmpty())
		return FALSE;

	// Open the subkey
	if (!SubKey.Open(m_hKey, SubKeyName))
		return FALSE;

	// Build a array of key names under the subkey
	while (SubKey.EnumSubKey(&SubSubKeyName))
		SubSubKeyList.Add(SubSubKeyName);
	
	// For each key name in the array, recusively call
	// this routine to delete the key.
	for (int i = 0; i < SubSubKeyList.GetSize(); i++)
	{
		if (!SubKey.DeleteSubKey(SubSubKeyList[i]))
			return FALSE;
	}
	
	// Close the subkey
	SubKey.Close();

	// Finally, delete the subkey now that all keys under
	// the subkey have been deleted.
	m_Result = RegDeleteKey(m_hKey, SubKeyName);
	
	return (m_Result == ERROR_SUCCESS);
}

BOOL CRegKey::DeleteSubKey(UINT SubKeyNameID)
{
	return DeleteSubKey(GetStringFromID(SubKeyNameID));
}

BOOL CRegKey::DeleteValue(UINT SubKeyNameID)
{
	return DeleteValue(GetStringFromID(SubKeyNameID));
}

BOOL CRegKey::DeleteValue(const CString& ValueName)
{
	if (!m_Opened)
		return FALSE;

	m_Result = RegDeleteValue(m_hKey, ValueName);
	
	return (m_Result == ERROR_SUCCESS);
}

void CRegKey::Close()
{
	if (m_Opened)
	{
		RegCloseKey(m_hKey);
		Init();
	}
}

CString CRegKey::GetStringFromID(UINT ID)
{
	CString String;

	VERIFY(String.LoadString(ID));

	return String;
}


DWORD CRegKey::GetRegType(CString& ValueName)
{
	DWORD	dwRegType = NULL;
	DWORD	dwSize = 0;

	m_Result = ERROR_SUCCESS;
	
	// If we haven't opened the key, return NULL
	if (!m_Opened)
	{
		return NULL;
	}
	
	// Get the reg type
	m_Result = RegQueryValueEx(m_hKey, ValueName, 0, &dwRegType, 
		NULL, NULL);

	// If error (i.e value not found), return NULL
	if (m_Result != ERROR_SUCCESS)
	{
		return NULL;
	}

	return dwRegType;
}


