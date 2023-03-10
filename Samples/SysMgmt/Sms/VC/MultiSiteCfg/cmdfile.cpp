#include "stdpch.h"
#include "cmdfile.h"

#define NL _T("\n\r")
#define NS _T("")


// Function name	: CINIHandler::Clear
// Description 	: Empty the INI table, freeing up memory
// Return type 	: void 
// Argument 		: void
void CINIHandler::Clear(void)
{
	POSITION posCurPos = m_mapINIValues.GetStartPosition();
	CObject* pCurObject;
	CString	csKey;
	
	while (posCurPos!=NULL)
	{
		m_mapINIValues.GetNextAssoc(posCurPos, csKey, pCurObject);
		m_mapINIValues.RemoveKey(csKey);
		((CMapStringToString*)pCurObject)->RemoveAll();
		delete ((CMapStringToString*)pCurObject);
	}
}


// Function name	: CINIHandler::ProcessCurrentInputLine
// Description	   : parses line for key or section and enters it into the table
// Return type		: int - # of key found (1 or 0)
// Argument       : CString& csCurLine - input line
// Argument       : CString& csCurSection - in/out - current section, used as section if a
//                     key is found, otherwise set the new section if a section is found
int CINIHandler::ProcessCurrentInputLine(CString& csCurLine,CString& csCurSection)
{
	int cKeys=0; 

	// remove leading and trailing whitespace
	csCurLine.TrimLeft();
	csCurLine.TrimRight();

	if (!csCurLine.IsEmpty() && csCurLine.Left(1)!=_T(';')) // skip comments ';'
	{
		int iPosEqual; // position of '=' in line
		
		if (csCurLine.Left(1)==_T('[') && csCurLine.Right(1)==_T(']'))
		{
			csCurLine.MakeUpper(); // ini headers are case insensitive
			csCurLine = csCurLine.Mid(1,csCurLine.GetLength()-2); // trash brackets
			csCurSection = csCurLine;
		}
		else if (((iPosEqual = csCurLine.Find(_T('=')))>0) && !csCurSection.IsEmpty()) //skip lines with no section
		{
			CString csKey = csCurLine.Left(iPosEqual);
			csKey.MakeUpper(); // ini keys are case insensitive
			csKey.TrimRight();
			
			CString csValue = csCurLine.Mid(iPosEqual+1);
			csValue.TrimLeft();
			
			// add key/value 
			if (!csKey.IsEmpty() && !csValue.IsEmpty())
			{
			  SetValue(csCurSection,csKey,csValue);
			  cKeys++;
			}
		}
	}

	return cKeys;
}

// Function name	: CINIHandler::LoadFromString
// Description 	: Initialize the INI table from an INI text file
// 						 loaded into a string - uses CR and/or LF as line term
// Return type 	: int - number of key processed
// Argument 		: const CString& csINIasString - the text file
int CINIHandler::LoadFromString(const CString& csINIasString)
{
	CString csWork = csINIasString;
	CString csCurLine;
	CString csCurSection;
	int nKeyCount=0;
	
	// clear out old map
	Clear();
	
	while (!csWork.IsEmpty())
	{
		// get next line
		csCurLine = csWork.SpanExcluding(NL);
		// remove this line from work string
		csWork = csWork.Mid(csCurLine.GetLength());
		csWork = csWork.Mid(csWork.SpanIncluding(NL).GetLength());
		
		nKeyCount += ProcessCurrentInputLine(csCurLine,csCurSection);
		
	}
	
	return nKeyCount; 	
}


// Function name	: CINIHandler::LoadFromFile
// Description 	: Initialize the INI table from a text file
// Return type 	: int - number of keys processed, -1 major file error
// Argument 		: const CString& csFilePathName - filename to read from
int CINIHandler::LoadFromFile(const CString& csFilePathName)
{
	int nKeyCount=0;
	
	try
	{
		CStdioFile csfINIFile(csFilePathName,CFile::modeRead|
															CFile::shareDenyWrite|
															CFile::typeText);
		CString csCurLine;
		CString csCurSection;
		
		// clear out old map
		Clear();
		
		// get next line
		while (csfINIFile.ReadString(csCurLine))
		{
			
			nKeyCount += ProcessCurrentInputLine(csCurLine,csCurSection);
		}
	}
	catch(CException *pEx)
	{
		pEx->Delete();
		return -1;
	}
	
	return nKeyCount;
}

// Function name	: CINIHandler::ExportToString
// Description 	: Export the INI table to text file representation in a string
// Return type 	: void 
// Argument 		: CString&  csINIasString - out param, the INI text file in a string
// Argument 		: const CString& csLineTerm - line terminator to use
void CINIHandler::ExportToString(CString&  csINIasString, const CString& csLineTerm) const
{
	POSITION posCurSecPos = m_mapINIValues.GetStartPosition();
	
	csINIasString.Empty();
	
	while (posCurSecPos!=NULL)
	{
		CObject* pCurSectionMap;
		CString	csSecName;
		
		m_mapINIValues.GetNextAssoc(posCurSecPos, csSecName, pCurSectionMap);
		if (!csSecName.IsEmpty() && pCurSectionMap!=NULL)
		{
			CMapStringToString *pCurSectionStrMap = (CMapStringToString*)pCurSectionMap;
			POSITION posCurKeyPos = pCurSectionStrMap->GetStartPosition();
			CString csKeyName,csValue;
			
			csINIasString+= _T('[') + csSecName + _T(']') + csLineTerm;
			
			while (posCurKeyPos!=NULL)
			{
				pCurSectionStrMap->GetNextAssoc(posCurKeyPos,csKeyName,csValue);
				if (!csKeyName.IsEmpty() && !csValue.IsEmpty())
					csINIasString += csKeyName + _T('=') + csValue + csLineTerm;
			}
		}
		
	}
}

// Function name	: CPDFManager::ExportToFile
// Description 	: Exports the stored INI file to a text file
// Return type 	: bool - true on success
// Argument 		: const CString& csFilePathName - name of file to export to
bool CINIHandler::ExportToFile(const CString& csFilePathName) const
{
	
	try
	{
		POSITION posCurSecPos = m_mapINIValues.GetStartPosition();
		CStdioFile csfINIFile(csFilePathName,CFile::modeCreate|
			CFile::modeWrite|
			CFile::shareExclusive|
			CFile::typeText);
		
		while (posCurSecPos!=NULL)
		{
			CObject* pCurSectionMap;
			CString	csSecName;
			
			m_mapINIValues.GetNextAssoc(posCurSecPos, csSecName, pCurSectionMap);
			if (!csSecName.IsEmpty() && pCurSectionMap!=NULL)
			{
				CMapStringToString *pCurSectionStrMap = (CMapStringToString*)pCurSectionMap;
				POSITION posCurKeyPos = pCurSectionStrMap->GetStartPosition();
				CString csKeyName,csValue;
				
				csfINIFile.WriteString(_T('[') + csSecName + _T("]\n"));
				
				while (posCurKeyPos!=NULL)
				{
					pCurSectionStrMap->GetNextAssoc(posCurKeyPos,csKeyName,csValue);
					if (!csKeyName.IsEmpty() && !csValue.IsEmpty())
						csfINIFile.WriteString(csKeyName + _T('=') + csValue + _T('\n'));
				}
			}
			
		}
		
	}
	catch(CException *pEx)
	{
		pEx->Delete();
		return false;
	}
	
	return true;
}

// Function name	: CINIHandler::GetValue
// Description 	 : Get the value for given section/key value
// Return type 	: CString - key value, empty for section/key not found
// Argument 		  : const CString& csSection - section name
// Argument 		  : const CString& csKey - key name
CString CINIHandler::GetValue(const CString& csSection,const CString& csKey) const
{
	CString csValue;
	CString csCISection = csSection;
	CString csCIKey = csKey;
	CObject* pSectionStrMap;
	
	csCISection.MakeUpper();
	csCIKey.MakeUpper();
	
	if (m_mapINIValues.Lookup(csCISection,pSectionStrMap) && pSectionStrMap!=NULL)
		((CMapStringToString*)pSectionStrMap)->Lookup(csCIKey,csValue);
	
	return csValue;
}


// Function name	: CINIHandler::GetCDLValue
// Description 	: Get Comma Delimeted List Value: gets a value that is a series
// 						 of comma delimeted items, parses them, and puts them into a string array
// Return type 	: int - number of items in list parsed, -1 for error
// Argument 		: const CString& csSection - section to search
// Argument 		: const CString& csKey - key to search for
// Argument 		: CStringArray* pstrarrValues - out param, string array to put items into
int CINIHandler::GetCDLValue(const CString& csSection,const CString& csKey, CStringArray* pstrarrValues) const
{
	CString csWork;
	TCHAR *ptchItemList, *ptchCurItem;
	
	if (!pstrarrValues) return -1;
	
	pstrarrValues->RemoveAll();
	
	csWork = GetValue(csSection,csKey);
	
	ptchItemList = csWork.GetBuffer(1);
	
	ptchCurItem = _tcstok(ptchItemList,_T(","));
	while (ptchCurItem!=NULL)
	{
		CString csCurItem(ptchCurItem);
		csCurItem.TrimLeft();
		csCurItem.TrimRight();
		pstrarrValues->Add(csCurItem);
		ptchCurItem = _tcstok(NULL,_T(","));

	}
	
	csWork.ReleaseBuffer();
	
	return pstrarrValues->GetSize();
}

void  CINIHandler::SetCDLValue(const CString& csSection, const CString& csKey, const CStringArray* pstrarrValues)
{
	CString csValue;

	csValue = pstrarrValues->GetAt(0);

	for (int i=1; i<pstrarrValues->GetSize(); i++)
	{
		csValue += _T(",") + pstrarrValues->GetAt(i);
	}

	SetValue(csSection,csKey,csValue);
}


// Function name	: CINIHandler::SetValue
// Description 	: Set the value for a given section/key pair
// Return type 	: void 
// Argument 		: const CString& csSection - INI section name
// Argument 		: const CString& csKey - INI key name
// Argument 		: const CString& csValue - new key value
void CINIHandler::SetValue(const CString& csSection,const CString& csKey,const CString& csValue)
{
	CString csCISection = csSection;
	CString csCIKey = csKey;
	CObject* pSectionStrMap;
	
	csCISection.MakeUpper();
	csCIKey.MakeUpper();
	
	if (m_mapINIValues.Lookup(csCISection,pSectionStrMap) && pSectionStrMap!=NULL)
		((CMapStringToString*)pSectionStrMap)->SetAt(csCIKey,csValue);
	else
	{
		// if section doesn't exist, create it
		pSectionStrMap = (CObject*)new CMapStringToString;
		((CMapStringToString*)pSectionStrMap)->SetAt(csCIKey,csValue);
		m_mapINIValues.SetAt(csCISection,pSectionStrMap);
	}
	
	
}


/******************************************************************************************************/

CString CCfgCmdFile::GetSiteServer() const
{
	return m_iniFile.GetValue(_T("Sites"),_T("SiteServer"));
}

void CCfgCmdFile::SetSiteServer(const CString& csSiteServer)
{
	m_iniFile.SetValue(_T("Sites"),_T("SiteServer"),csSiteServer);
}


CString CCfgCmdFile::GetSourceSite() const
{
	return m_iniFile.GetValue(_T("Sites"),_T("Source"));
}

void CCfgCmdFile::SetSourceSite(const CString& csSourceSite)
{
	m_iniFile.SetValue(_T("Sites"),_T("Source"), csSourceSite);
}


void CCfgCmdFile::GetDestSites(CStringArray& csaDestSites) const
{
    m_iniFile.GetCDLValue(_T("Sites"),_T("DestSites"), &csaDestSites);
}

void CCfgCmdFile::SetDestSites(const CStringArray& csaDestSites)
{
    m_iniFile.SetCDLValue(_T("Sites"),_T("DestSites"), &csaDestSites);
}

void CCfgCmdFile::GetSettings(CStringArray& csaSettings) const
{
	CString csValue,csKey;
	csaSettings.RemoveAll();

	int i=0;
	while (true)
	{
		csKey.Format("Setting%d",i++);
		csValue = m_iniFile.GetValue("SettingsToCopy",csKey);
		if (csValue.IsEmpty())
			break;
		else
			csaSettings.Add(csValue);
	}
}

void CCfgCmdFile::SetSettings(CStringArray& csaSettings)
{
	CString csKey;

	for (int i=0; i < csaSettings.GetSize(); i++)	
	{
		csKey.Format("Setting%d",i);
		m_iniFile.SetValue("SettingsToCopy",csKey,csaSettings[i]);

	}

}


