/************************************************************************************
*
* CConfigApp.h
*
* CConfigApp - the class which is the interface into our application.
* CConfigItem - the which is used by CConfigApp as the interface into the 
*    objects that control the transfer of individual settings in the site control file.
* 
* Actual tranfer objects are derived from CConfigItem or one of the following:
*
* CSimpleSCI - A simple implementation of CConfigItem used when the site control file
*              settings are contained in one item and the properties to copy can be named
*              at complile time.
*
* CSimpleSCISQ - Similar to CSimpleSCI except that the site control item name ends in
*                "|<server name>"
*
* CMultiPartSCI - An implementation of CConfigItem for transfering settings that are
*                 contained in more than one class. It contains multiple instances of
*                 CConfigItem and delegates the work to them.
* 
************************************************************************************/

#pragma once


class CConfigItem;

typedef std::vector<_bstr_t> bstrVector;
typedef std::set<_bstr_t>	  bstrSet;
typedef std::map<_bstr_t,_bstr_t> bstr2bstrMap;
typedef std::vector<CConfigItem*> CIVector;


#define THROWWBEMERR throw CWbemException(_bstr_t(__FILE__)+":"+_bstr_t(_variant_t((long)__LINE__)))
#define THROWWBEMERRHR(HR) throw CWbemException(HR,_bstr_t(__FILE__)+":"+_bstr_t(_variant_t((long)__LINE__)))

// This class provides the interface to the actual aplication.
class CConfigApp
{
public:
	/* The client application should define an object that supports this interface in order to
	   receive status information */
	struct IProgressCallback
	{
		virtual bool TransferItemCompleted(const _bstr_t& sSite, const _bstr_t& sItemName, LPARAM lParam)=0;
		virtual bool TransferItemError(const _bstr_t& sSite, const _bstr_t& sItemName, LPARAM lParam)=0;
	};

private:
	typedef std::map<_bstr_t,CConfigItem*> cfgMap;
	typedef std::vector<CConfigItem*> cfgVector;

	_bstr_t m_sApplicationName;
	_bstr_t m_sNamespace;
	_bstr_t m_sSCFHandle;
	_bstr_t m_sCTXHandle;
	CWbemServices m_wsServices;
	IWbemServicesPtr m_pServices;
	IProgressCallback* m_pCallbackObj;
	LPARAM m_lpCallbackLPARAM;
	_bstr_t   m_sCurSite;
	cfgVector m_vInstalledCfgs;
	cfgMap    m_mAvailCfgs;
	bstr2bstrMap m_mSiteServerNameCache;

	void SetUpContext() ;
	void ReleaseContext() ;
	_bstr_t GetSCFHandle() ;
	void ReleaseSCFHandle(const _bstr_t& sHandle) ;
	_bstr_t GetCTXHandle() ;
	void ReleaseCTXHandle(const _bstr_t& sHandle) ;
	void GetInstalledUnits(const _bstr_t& sSiteCode, bstrSet& ssInstalledUnits);
	void RefreshSCF(const _bstr_t& sSite) ;
	void CommitSCF(const _bstr_t& sSite) ;
	void TransferSettings(const bstrVector& vsConfigs, const _bstr_t& sDstSite) ;

public:

	CConfigApp(const _bstr_t& sApplicationName);
	~CConfigApp();

    // connect to a namespace
	void Connect(const _bstr_t& sNamespace);

	// retrive the provider namespace from a SMS Site Server
	_bstr_t GetProvNamespaceForServer(const _bstr_t& sServer);

	// the following require an active connection:

	// retrive the site codes for the site and it's subsites
	// if bCheckWriteAccess is set, only return sites that the user has
	// write access to
	void GetSiteCodes(bstrVector& vsSites, bool bCheckWriteAccess=false);

	// Set the source site and retrieve the configurations supported by this site
	void SetSiteAndGetAvailConfigs(const _bstr_t& sSite, bstrVector& vsConfigs) ;

	// transfer the configurations listed in vsConfigs from the previously set site
	// to the sites listed in vsDstSites
	void TransferSettings(const bstrVector& vsConfigs, const bstrVector& vsDstSites) ;

	// return the currently selected site
	_bstr_t GetSelectedSite(void) const { return m_sCurSite; }

	// rasie a status message
	void RaiseStatusMessage(const _bstr_t& sMessage, LONG nMessageType, LONG nSeverity);

	void SetProgressCallback(IProgressCallback *pCallbackObj, LPARAM lParam=0)
	{ m_pCallbackObj=pCallbackObj; m_lpCallbackLPARAM = lParam; }

	// look up the name of a site server for a particular sited code, GetSiteCodes must have been
	// previously called
	_bstr_t GetSiteServerName(const _bstr_t& sSiteCode)  { return m_mSiteServerNameCache[sSiteCode]; }
};

/***********************************************************************************************/

// This is the parent class for setting transfer objects.
class CConfigItem
{
	friend class CMultiPartSCI;
private:
	static bstr2bstrMap s_mSiteServerNameCache;


protected:
	CWbemServices& m_wsServices;
	_bstr_t        m_sCurSite;

    
	CWbemClassObject GetSiteControlItem(const _bstr_t& sClass,const _bstr_t& sItemType, const _bstr_t& sItemName, const _bstr_t& sSiteCode);
	CWbemClassObject GetSiteControlItem(const _bstr_t& sItemType, const _bstr_t& sItemName, const _bstr_t& sSiteCode);

	void TransferEmbeddedProps(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrSet& ssProps) ;
	void TransferEmbeddedPropLists(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrSet& ssProps) ;
	void TransferMultiStringLists(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrSet& ssProps) ;
	void TransferProps(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrVector& vsProps) ;

public:
	CConfigItem(CWbemServices& wsServ) : m_wsServices(wsServ) {}
	virtual ~CConfigItem() {}
	
	_bstr_t GetSiteServerName(const _bstr_t& sSiteCode);


	virtual void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) =0;
	virtual void SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs)=0;

};

/****************************************************************************************/


class CSimpleSCI : public CConfigItem
{
	friend class CMultiPartSCI;

protected:
		_bstr_t			m_sClassName;
		_bstr_t        m_sItemType;
		_bstr_t        m_sItemName;
		_bstr_t        m_sUnit;
		bstrVector     m_vsConfigs;
		bstrVector     m_vsPropsToCopy;
		bstrSet			m_ssEmbedPropsToCopy;
		bstrSet			m_ssEmbedPropListsToCopy;
		bstrSet			m_ssRegMultiListsToCopy;

public:
	CSimpleSCI(CWbemServices& wsServ) : CConfigItem(wsServ) {}
	virtual CWbemClassObject GetSiteControlItem(const _bstr_t& sSiteCode=_bstr_t());
	virtual void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
	virtual void SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs);
	virtual void TransferSettingsObj(CWbemClassObject wcoSource, CWbemClassObject wcoDest);
	virtual CWbemClassObject GetEmbeddedProperty(const _bstr_t& sPropName, const _bstr_t& sSiteCode=_bstr_t());

};

class CSimpleSCISQ : public CSimpleSCI
{
	friend class CMultiPartSCI;

public:
	CSimpleSCISQ(CWbemServices& wsServ) : CSimpleSCI(wsServ) {}
	CWbemClassObject GetSiteControlItem(const _bstr_t& sSiteCode=_bstr_t());

};

class CMultiPartSCI : public CConfigItem
{
protected:
	_bstr_t        m_sCurSite;
	bstrVector     m_vsConfigs;
	_bstr_t        m_sUnit;
	CIVector       m_vpParts;


public:
	CMultiPartSCI(CWbemServices& wsServ) : CConfigItem(wsServ) {}
	virtual ~CMultiPartSCI();
	virtual void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
	virtual void SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs);

};