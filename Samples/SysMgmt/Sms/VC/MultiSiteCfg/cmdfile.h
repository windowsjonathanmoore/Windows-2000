

// better interface to windows INI files
class CINIHandler 
{
private:
	CMapStringToOb m_mapINIValues;
   int ProcessCurrentInputLine(CString& csCurLine,CString& csCurSection);

public:
	CINIHandler() { Clear(); }
	~CINIHandler() { Clear(); }
	int     LoadFromString(const CString& csINIasString);
	int     LoadFromFile(const CString& csFilePathName);
	void    ExportToString(CString&  csINIasString, const CString& csLineTerm) const;
	bool    ExportToFile(const CString& csFilePathName) const;
	CString GetValue(const CString& csSection, const CString& csKey) const;
	int     GetCDLValue(const CString& csSection, const CString& csKey, CStringArray* pstrarrValues) const;
	void    SetCDLValue(const CString& csSection, const CString& csKey, const CStringArray* pstrarrValues);

	void    SetValue(const CString& csSection, const CString& csKey, const CString& csValue);
	void    Clear(void);

	static bool ValueIsTrue(const CString& csValue)
		{ return (_tcsncicmp(csValue,_T("T"),1)==0 || _tcsncicmp(csValue,_T("Y"),1)==0 || _ttoi(csValue)!=0); }
};





class CCfgCmdFile
{
private:
	CINIHandler m_iniFile;

public:
	CCfgCmdFile() {}
	~CCfgCmdFile() {}


	bool LoadSettings(const CString& csFile)
	{
		return m_iniFile.LoadFromFile(csFile)>0; 
	}

	bool SaveSetting(const CString& csFile) const
	{
		return m_iniFile.ExportToFile(csFile);
	}

	void Clear() { m_iniFile.Clear(); }


	CString GetSiteServer() const;
	void SetSiteServer(const CString& csSiteServer);

    CString GetSourceSite() const;
	void SetSourceSite(const CString& csSourceSite);

	void GetDestSites(CStringArray& csaDestSites) const;
	void SetDestSites(const CStringArray& csaSrcSites);

	void GetSettings(CStringArray& csaSettings) const;
	void SetSettings(CStringArray& csaSettings);

};