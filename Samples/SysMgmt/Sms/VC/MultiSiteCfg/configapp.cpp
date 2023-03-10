
#include "stdpch.h"

#define _USE_AUTOSYMBOLS  // must be defined before the include
#include <smsprov.h>		  // include wbem names.
#include <wbemsec.h>
#include "configapp.h"
#include "modules.h"
#include "resource.h"

using namespace SMSSDK; // save ourselves some typing by using this namespace	

CConfigApp::CConfigApp(const _bstr_t& sApplicationName)
{
	m_sApplicationName = sApplicationName;
	m_pCallbackObj = NULL;
	m_lpCallbackLPARAM = 0;

	m_vInstalledCfgs.push_back(new CHinvSettings(m_wsServices));
	m_vInstalledCfgs.push_back(new CSinvSettings(m_wsServices));
	m_vInstalledCfgs.push_back(new CAPSettings(m_wsServices));
	m_vInstalledCfgs.push_back(new CNetLogonCI(m_wsServices));
	m_vInstalledCfgs.push_back(new CRToolSettings(m_wsServices));

	// these actually look valuable for large hierarchies.
	m_vInstalledCfgs.push_back(new CAddress(m_wsServices));
	m_vInstalledCfgs.push_back(new CSender(m_wsServices));
	
	m_vInstalledCfgs.push_back(new CSWMSettings(m_wsServices));
	m_vInstalledCfgs.push_back(new CTrapSettings(m_wsServices));
	m_vInstalledCfgs.push_back(new CRemoteCI(m_wsServices));
	m_vInstalledCfgs.push_back(new CNDSNetLogonCI(m_wsServices));
	m_vInstalledCfgs.push_back(new CNWNetLogonCI(m_wsServices));
	m_vInstalledCfgs.push_back(new CNetLogonDisc(m_wsServices));
	m_vInstalledCfgs.push_back(new CNDSNetLogonDisc(m_wsServices));
	m_vInstalledCfgs.push_back(new CNWNetLogonDisc(m_wsServices));
	m_vInstalledCfgs.push_back(new CHeartbeatDisc(m_wsServices));
	m_vInstalledCfgs.push_back(new CNTUserDisc(m_wsServices));
	m_vInstalledCfgs.push_back(new CNTGroupDisc(m_wsServices));
}

CConfigApp::~CConfigApp()
{
	try
	{
		for (int i=0; i < m_vInstalledCfgs.size(); i++)
			delete m_vInstalledCfgs[i];

		ReleaseContext();
	}
	catch(...)
	{
	}
}

void CConfigApp::Connect(const _bstr_t& sNamespace)
{
	// ConnectServer throws CWbemException objects
	m_pServices=NULL;

	// Connect to the site server
	m_wsServices.ConnectServer(sNamespace,&m_pServices);
	m_sNamespace = sNamespace;

	SetUpContext();
}

_bstr_t CConfigApp::GetProvNamespaceForServer(const _bstr_t& sServer)
{
	IEnumWbemClassObjectPtr pEnum;
	IWbemServicesPtr pServices;
	CWbemClassObject wcoProvLoc;
	_bstr_t sQuery;
	ULONG cReturned;
	_bstr_t sNamespace;
	HRESULT hr;

	// Connect to the "\\Server\root\sms" namespace on the site server
	m_wsServices.ConnectServer(L"\\\\" + sServer + L"\\root\\sms", &pServices);

	// Forumate a query to find the 'real' location of the provider for this site server
    sQuery = _bstr_t(L"SELECT ") + SMS_ProviderLocation::PROP_NamespacePath + L" FROM " + CLASS_SMS_ProviderLocation + 
		L" WHERE " +  SMS_ProviderLocation::PROP_ProviderForLocalSite + L"=True";

	// Execute the query
	hr = m_wsServices.ExecQuery(sQuery,&pEnum);
	if (FAILED(hr))
	   THROWWBEMERRHR(hr);

	// Procede to the first object in the query results
	hr = pEnum->Next(WBEM_INFINITE ,1,&wcoProvLoc,&cReturned);
	
	if (!FAILED(hr) && cReturned>0)
	{
		// Extract the provider location namespace
		sNamespace = wcoProvLoc.GetString(SMS_ProviderLocation::PROP_NamespacePath);
	}
	else
	   THROWWBEMERRHR(hr);

	return sNamespace;
}

void CConfigApp::SetUpContext()
{
	WCHAR wcComputerName[MAX_COMPUTERNAME_LENGTH + 1];

	// Get the name of this computer
	wcComputerName[0] = L'\0';
	DWORD dwLen = MAX_COMPUTERNAME_LENGTH + 1;
	GetComputerNameW(wcComputerName,&dwLen);

	// Add the ApplicationName and MachineName values to the context object
	m_wsServices.SetContextValue(CONTEXTVALUE_ApplicationName,m_sApplicationName);
	m_wsServices.SetContextValue(CONTEXTVALUE_MachineName,_bstr_t(wcComputerName));
	
	// Get a session handle for editting the site control file & add it to the context object
	m_sSCFHandle = GetSCFHandle();
	m_wsServices.SetContextValue(CONTEXTVALUE_SessionHandle,m_sSCFHandle);

	// Cache the current context object and get handle for it
	m_sCTXHandle = GetCTXHandle(); 

	// Use the handle of the cached context instead of all the context values
	m_wsServices.DeleteAllContextValues(); 
	m_wsServices.SetContextValue(CONTEXTVALUE_ContextHandle,m_sCTXHandle);
}

void CConfigApp::ReleaseContext()
{
	// Release all the values in the context object
	m_wsServices.DeleteAllContextValues();

	// Release the site control file session handle
	if (m_sSCFHandle.length())
		ReleaseSCFHandle(m_sSCFHandle);

	// Release the cached context handle
	if (m_sCTXHandle.length())
		ReleaseCTXHandle(m_sCTXHandle);
}

_bstr_t CConfigApp::GetSCFHandle()
{
	HRESULT hr;
	_bstr_t sSCFSessionHandle;
	CWbemClassObject wcoInparam; // no in params, leave null
	CWbemClassObject wcoOutparam;

	// Execute the GetSessionHandle method to get a session handle for editting the SCF
	hr = m_wsServices.ExecMethod(CLASS_SMS_SiteControlFile, SMS_SiteControlFile::METHOD_GetSessionHandle, wcoInparam, wcoOutparam);
	if (FAILED(hr))
		THROWWBEMERRHR(hr);

	// Extract and return the session handle
	return wcoOutparam.GetString(SMS_SiteControlFile::GetSessionHandle::Out::PARAM_SessionHandle);
}

void CConfigApp::ReleaseSCFHandle(const _bstr_t& sHandle)
{
	HRESULT hr;
	CWbemClassObject wcoInparamClass;
	CWbemClassObject wcoOutparamClass;
	CWbemClassObject wcoInparam;
	CWbemClassObject wcoOutparam;

	// Get the In & Out-parameter objects for the ReleaseSessionHandle method
	hr = m_wsServices.GetMethodSignatures(CLASS_SMS_SiteControlFile,SMS_SiteControlFile::METHOD_ReleaseSessionHandle,wcoInparamClass,wcoOutparamClass);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Spawn an instance of the In-Params object
	wcoInparam = wcoInparamClass.SpawnInstance();
	if( !wcoInparam ) 
		THROWWBEMERR;

	// Set the SessionHandle value of the In-params
	hr = wcoInparam.Put(SMS_SiteControlFile::ReleaseSessionHandle::In::PARAM_SessionHandle, sHandle);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Execute the ReleaseSessionHandle method
	hr = m_wsServices.ExecMethod(CLASS_SMS_SiteControlFile, SMS_SiteControlFile::METHOD_ReleaseSessionHandle, wcoInparam, wcoOutparam);

	if (FAILED(hr))
		THROWWBEMERRHR(hr);
}

_bstr_t CConfigApp::GetCTXHandle()
{
	HRESULT hr;
	_bstr_t sSCFSessionHandle;
	CWbemClassObject wcoInparam; // no in, leave null
	CWbemClassObject wcoOutparam;

	// Execute the GetContextHandle method to cache the current context object
	hr = m_wsServices.ExecMethod(CLASS_SMS_ContextMethods, SMS_ContextMethods::METHOD_GetContextHandle, wcoInparam, wcoOutparam);
	if (FAILED(hr))
		THROWWBEMERRHR(hr);

	// Extract and return the handle to the cached context object
	return wcoOutparam.GetString(SMS_ContextMethods::GetContextHandle::Out::PARAM_ContextHandle);
}

void CConfigApp::ReleaseCTXHandle(const _bstr_t& sHandle)
{
	HRESULT hr;
	CWbemClassObject wcoInparamClass;
	CWbemClassObject wcoOutparamClass;
	CWbemClassObject wcoInparam;
	CWbemClassObject wcoOutparam;

	// Get the In & Out parameters object for the ReleaseContextHandle method
	hr = m_wsServices.GetMethodSignatures(CLASS_SMS_ContextMethods,SMS_ContextMethods::METHOD_ClearContextHandle,wcoInparamClass,wcoOutparamClass);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Spawn an instance of the In-params object
	wcoInparam = wcoInparamClass.SpawnInstance();
	if( !wcoInparam ) 
		THROWWBEMERR;

	// Add the Context Handle to the in-params object
	hr = wcoInparam.Put(SMS_ContextMethods::ClearContextHandle::In::PARAM_ContextHandle, sHandle);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Execute the ReleaseContextHandle method
	hr = m_wsServices.ExecMethod(CLASS_SMS_ContextMethods, SMS_ContextMethods::METHOD_ClearContextHandle, wcoInparam, wcoOutparam);
	if (FAILED(hr))
		THROWWBEMERRHR(hr);
}


void CConfigApp::GetSiteCodes(bstrVector& vsSites, bool bCheckWriteAccess/*=false*/)
{
	HRESULT hr;
	ULONG ulReturned;
	long lPermFlags=0;
	IEnumWbemClassObjectPtr pEnum;
	CWbemClassObject wcoResult;
	WCHAR wcPad[] = L"    - ";

	vsSites.clear();

	// Create an enumeration of the SMS_Site class
	hr = m_wsServices.CreateInstanceEnum(CLASS_SMS_Site,WBEM_FLAG_SHALLOW|WBEM_FLAG_FORWARD_ONLY,&pEnum);
	if (FAILED(hr))
		return;

	// Set the interface security on the enumeration object
	if( FAILED( hr = SetInterfaceSecurity(pEnum, NULL, NULL, NULL, true) ) )
		return;

	// Loop through all the objects in the enumeration
	while (!FAILED(hr=pEnum->Next(WBEM_INFINITE, 1, &wcoResult, &ulReturned)) && ulReturned>0) 
	{

		// Get the build number of this particular SMS_Site object
		long nBuildNumber = wcoResult.GetLong(SMS_Site::PROP_BuildNumber);

		// Is this an old site? (Pre SMS 2.0)
		if (nBuildNumber < 1239)
		{
			continue; // 1.2 or older site
		}

		// Should we check for security rights to Write?
		if (bCheckWriteAccess)
		{
			IWbemQualifierSetPtr pQualSet;
			lPermFlags=0;

			// Get the qualifiers for this SMS_Site object
			wcoResult->GetQualifierSet(&pQualSet);
			if (pQualSet)
			{
				_variant_t vVal;
				// Is the SecurityVerbs qualifier present, and if so, get its value
				if (!FAILED(pQualSet->Get(_bstr_t("SecurityVerbs"),0,&vVal,NULL)))
					lPermFlags = vVal;
			}
		}

		// If we're not checking for Write access, or the object has modify permissions
		if (!bCheckWriteAccess || (lPermFlags & SMS_SecuredObject::AvailableInstancePermissions::BIT_MODIFY))
		{
			_bstr_t sSiteCode;
			_bstr_t sSiteName;
			_bstr_t sTitle;
			_bstr_t sServerName;

			// Get the SiteCode, SiteName, & ServerName values of the site
			sSiteCode = wcoResult.GetString(SMS_Site::PROP_SiteCode);
			sSiteName = wcoResult.GetString(SMS_Site::PROP_SiteName);
			sServerName = wcoResult.GetString(SMS_Site::PROP_ServerName);
			sTitle = sSiteCode + &wcPad[sSiteCode.length()] + sSiteName;

			vsSites.push_back(sTitle);

			// Cache the site properties
			m_mSiteServerNameCache[sSiteCode] = sServerName;
		}
	}
}

void CConfigApp::RefreshSCF(const _bstr_t& sSite)
{
	HRESULT hr;
	CWbemClassObject wcoInparamClass;
	CWbemClassObject wcoOutparamClass;
	CWbemClassObject wcoInparam;
	CWbemClassObject wcoOutparam;

	// Get the In & Out parameters objects for the RefreshSCF method
	hr = m_wsServices.GetMethodSignatures(CLASS_SMS_SiteControlFile,SMS_SiteControlFile::METHOD_RefreshSCF,wcoInparamClass,wcoOutparamClass);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Spawn an instance of the In-params object
	wcoInparam = wcoInparamClass.SpawnInstance();
	if( !wcoInparam ) 
		THROWWBEMERR;

	// Add the SiteCode to the In-params object
	hr = wcoInparam.Put(SMS_SiteControlFile::RefreshSCF::In::PARAM_SiteCode, sSite);
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// And finally...  Execute the refresh
	hr = m_wsServices.ExecMethod(CLASS_SMS_SiteControlFile, SMS_SiteControlFile::METHOD_RefreshSCF, wcoInparam, wcoOutparam);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);
}


void CConfigApp::CommitSCF(const _bstr_t& sSite)
{
	HRESULT hr;
	CWbemClassObject wcoInparamClass;
	CWbemClassObject wcoOutparamClass;
	CWbemClassObject wcoInparam;
	CWbemClassObject wcoOutparam;

	// Get the In & Out parameters objects for the CommitSCF method
	hr = m_wsServices.GetMethodSignatures(CLASS_SMS_SiteControlFile,SMS_SiteControlFile::METHOD_CommitSCF,wcoInparamClass,wcoOutparamClass);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Spawn an instance of the In-params object
	wcoInparam = wcoInparamClass.SpawnInstance();
	if( !wcoInparam ) 
		THROWWBEMERR;

	// Add the SiteCode to the In-params object
	hr = wcoInparam.Put(SMS_SiteControlFile::RefreshSCF::In::PARAM_SiteCode, sSite);
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// And finally...  Execute the commit
	hr = m_wsServices.ExecMethod(CLASS_SMS_SiteControlFile, SMS_SiteControlFile::METHOD_CommitSCF, wcoInparam, wcoOutparam);
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);
}

void CConfigApp::GetInstalledUnits(const _bstr_t& sSiteCode, bstrSet& ssInstalledUnits)
{
	
	HRESULT hr=0;
	_bstr_t sPath;
	CWbemClassObject wcoSiteDef;

	ssInstalledUnits.clear();

	// Formulate the path to the SiteDefinition site control item for the given sitecode
	sPath = _bstr_t(CLASS_SMS_SCI_SiteDefinition) + L".";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_FileType) + L"=2,";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_ItemType) + L"=\"Site Definition\",";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_ItemName) + L"=\"Site Definition\",";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_SiteCode) + L"=\"" + sSiteCode + L"\"";

	// Get the SiteDefinition site control item
	wcoSiteDef = m_wsServices.GetObject(sPath,false);

	if (wcoSiteDef)
	{
		_variant_t vTemp;

		// Get the "PropLists" array out of the SiteDefinition object
		if (!FAILED(hr=wcoSiteDef.Get(SMS_SCI_SiteDefinition::PROP_PropLists,vTemp)))
		{

			CWbemClassObjectSafeVector vPropList = vTemp;

			// Walk through the objects in the "PropLists" array
			for (int i=0; i < vPropList.size(); i++)
			{
				// Is this the "Installed Units" property list?
				if (vPropList[i].GetString(SMS_EmbeddedPropertyList::PROP_PropertyListName)==_bstr_t(L"Installed Units"))
				{
					// Get the values for this property
					if (!FAILED(hr=vPropList[i].Get(SMS_EmbeddedPropertyList::PROP_Values,vTemp)))
					{
						_bstr_tSafeVector svsUnits = vTemp;
						ssInstalledUnits.insert(svsUnits.begin(),svsUnits.end());
					}
					break;
				}
			}
		}
	}
	ASSERT(hr==0);
	ASSERT(ssInstalledUnits.size()>0);
}

void CConfigApp::SetSiteAndGetAvailConfigs(const _bstr_t& sSite, bstrVector& vsConfigs)
{
	bstrVector vsIndivConfigs;
	bstrSet    ssInstalledUnits;
	m_sCurSite = _bstr_t(SysAllocStringLen(sSite,3),false); // if only there were a _bstr_t::left()

	// Get a list of installed units for the site
	GetInstalledUnits(m_sCurSite, ssInstalledUnits);


	m_mAvailCfgs.clear();
	vsConfigs.clear();

	for (int i=0; i < m_vInstalledCfgs.size(); i++)
	{
		vsIndivConfigs.clear();
		// find out the settings that this handler can handle
		m_vInstalledCfgs[i]->SetSiteAndGetAvailConfigs(m_sCurSite,ssInstalledUnits,vsIndivConfigs);

		for (int j=0; j < vsIndivConfigs.size(); j++)
		{
			// set up the mapping between the name and the object that handles it
			m_mAvailCfgs[vsIndivConfigs[j]] = m_vInstalledCfgs[i];
			vsConfigs.push_back(vsIndivConfigs[j]);
		}

	}

}

void CConfigApp::TransferSettings(const bstrVector& vsConfigs, const _bstr_t& sDstSite)
{
	CString csMsg;
	CConfigItem* pCurItem;

	// Get the destination site code to transfer the setting to.
	_bstr_t sDstSiteCode = _bstr_t(SysAllocStringLen(sDstSite,3),false); // if only there were a _bstr_t::left()

	for (int i=0; i < vsConfigs.size(); i++)
	{
		try
		{
			pCurItem = m_mAvailCfgs[vsConfigs[i]]; // map setting name to handler

			if (pCurItem)
				pCurItem->TransferSettings(vsConfigs[i], sDstSiteCode);

			if (m_pCallbackObj && !m_pCallbackObj->TransferItemCompleted(sDstSiteCode,vsConfigs[i],m_lpCallbackLPARAM))
				break;
		}
		catch(...)
		{
			// Raise an error status message if the transfer failed
			csMsg.LoadString(IDS_STAT_COPY_ERROR);
			csMsg += "[" + vsConfigs[i] + "]" + " to site: " + sDstSiteCode;
			CConfigApp::RaiseStatusMessage(_bstr_t(csMsg),
				SMS_StatusMessage::MessageType::ENUM_Milestone,SMS_StatusMessage::Severity::ENUM_Error);

			if (!m_pCallbackObj || !m_pCallbackObj->TransferItemError(sDstSiteCode,vsConfigs[i],m_lpCallbackLPARAM))
				throw;
		}
	}
}

void CConfigApp::TransferSettings(const bstrVector& vsConfigs, const bstrVector& vsDstSites)
{

	RefreshSCF(m_sCurSite);

	for (int i=0; i < vsDstSites.size(); i++)
	{
		// Refresh all the cached SCFs & Transfer the latest settings
		RefreshSCF(vsDstSites[i]);
		TransferSettings(vsConfigs,vsDstSites[i]);
	}

	for (int j=0; j < vsDstSites.size(); j++)
	{	_bstr_t sDstSiteCode = _bstr_t(SysAllocStringLen(vsDstSites[j],3),false); // if only there were a _bstr_t::left()

		// Commit all the changes
		CommitSCF(sDstSiteCode);
	}

}

void CConfigApp::RaiseStatusMessage(const _bstr_t& sMessage, LONG nMessageType, LONG nSeverity)
{
	HRESULT hr;
	CWbemClassObject wcoInparamClass;
	CWbemClassObject wcoOutparamClass;
	CWbemClassObject wcoInparam;
	CWbemClassObject wcoOutparam;

	_bstr_t sMethodName;

	// Determine the method to execute based on the severity or the status message
	if (nSeverity==SMS_StatusMessage::Severity::ENUM_Informational)
		sMethodName = SMS_StatusMessage::METHOD_RaiseInformationalStatusMsg;
	else if (nSeverity==SMS_StatusMessage::Severity::ENUM_Warning)
		sMethodName = SMS_StatusMessage::METHOD_RaiseWarningStatusMsg;
	else 
		sMethodName = SMS_StatusMessage::METHOD_RaiseErrorStatusMsg;


	// Get the In & Our parameter objects for the Raise***StatusMsg method
	hr = m_wsServices.GetMethodSignatures(CLASS_SMS_StatusMessage,sMethodName,wcoInparamClass,wcoOutparamClass);

	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Spawn an instance of the methods In-params object
	wcoInparam = wcoInparamClass.SpawnInstance();
	if( !wcoInparam ) 
		THROWWBEMERR;

	// Set the MessageType In-param
	hr = wcoInparam.Put(SMS_StatusMessage::RaiseErrorStatusMsg::In::PARAM_MessageType, nMessageType);
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Set the MessageText In-param
	hr = wcoInparam.Put(SMS_StatusMessage::RaiseErrorStatusMsg::In::PARAM_MessageText, sMessage);
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Set the ProcessID In-param
	hr = wcoInparam.Put(SMS_StatusMessage::RaiseErrorStatusMsg::In::PARAM_ProcessID, (long)GetCurrentProcessId());
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Set the ThreadID In-param
	hr = wcoInparam.Put(SMS_StatusMessage::RaiseErrorStatusMsg::In::PARAM_ThreadID, (long)GetCurrentThreadId());
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);

	// Execute the method to raise the status message
	hr = m_wsServices.ExecMethod(CLASS_SMS_StatusMessage, sMethodName, wcoInparam, wcoOutparam);
	if( FAILED(hr) )
		THROWWBEMERRHR(hr);
}

/****************************************************************************************/

bstr2bstrMap CConfigItem::s_mSiteServerNameCache;

CWbemClassObject CConfigItem::GetSiteControlItem(const _bstr_t& sClass, const _bstr_t& sItemType, const _bstr_t& sItemName, const _bstr_t& sSiteCode)
{
	_bstr_t sPath;

	// Formulate a path to the given site control item
	sPath = sClass + L".";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_FileType) + L"=2,";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_ItemType) + L"=\"" + sItemType + L"\",";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_ItemName) + L"=\"" + sItemName + L"\",";
	sPath += _bstr_t(SMS_SiteControlItem::PROP_SiteCode) + L"=\"" + sSiteCode + L"\"";

	// Get the site control item and return it.
	return m_wsServices.GetObject(sPath,false);
}

CWbemClassObject CConfigItem::GetSiteControlItem(const _bstr_t& sItemType, const _bstr_t& sItemName, const _bstr_t& sSiteCode)
{ 
	// Get the specified site control item and return it
	return GetSiteControlItem(CLASS_SMS_SiteControlItem,sItemType,sItemName,sSiteCode);
}

void CConfigItem::TransferEmbeddedProps(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrSet& ssProps)
{
	HRESULT hr;
	_variant_t vTemp;
	CWbemClassObjectSafeVector vSrcProps, vDstProps;
	int cFoundProps=0;

	// Get the embedded objects in the "Props" array property of the source object
	if (FAILED(hr=wcoSrc.Get(L"Props",vTemp)))
		THROWWBEMERRHR(hr);

	vSrcProps = vTemp;

	// Get the embedded objects in the "Props" array property of the destination object
	if (FAILED(hr=wcoDst.Get(L"Props",vTemp)))
		THROWWBEMERRHR(hr);

	vDstProps = vTemp;

	// Loop through all the embedded properties in the source object's "Props" array
	for (int i=0; i < vSrcProps.size(); i++)
	{
		// Get this property's name
		_bstr_t sCurSrcPropName = vSrcProps[i].GetString(SMS_EmbeddedProperty::PROP_PropertyName);

		// Is this one of the properties we want to transfer?
		if (ssProps.find(sCurSrcPropName)!=ssProps.end())
		{
			// Loop through all the embedded properties in the destination object's "Props" array
			for (int j=0; j < vDstProps.size(); j++)
			{
				// Get this property's name
				_bstr_t sCurDstPropname = vDstProps[j].GetString(SMS_EmbeddedProperty::PROP_PropertyName);

				// If the property exists in the destination object, then we copy the value
				if (sCurDstPropname==sCurSrcPropName)
				{
					vDstProps[j] = vSrcProps[i];
					cFoundProps++;
					break;
				}
			}
		}
	}

	// Make sure we copied all the properties that we expected to
	ASSERT(cFoundProps==ssProps.size());

	// Copy the modified "Props" array back to the destination object
	if (FAILED(hr=wcoDst.Put(L"Props",vDstProps.GetVariant())))
		THROWWBEMERRHR(hr);
}

void CConfigItem::TransferMultiStringLists(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrSet& ssProps)
{
	HRESULT hr;
	_variant_t vTemp;
	CWbemClassObjectSafeVector vSrcProps, vDstProps;
	int cFoundProps=0;

	// Get the embedded multi-strings in the "RegMultiStringLists" array of the source object
	if (FAILED(hr=wcoSrc.Get(L"RegMultiStringLists",vTemp)))
		THROWWBEMERRHR(hr);

	vSrcProps = vTemp;

	// Get the embedded multi-strings in the "RegMultiStringLists" array of the destination object
	if (FAILED(hr=wcoDst.Get(L"RegMultiStringLists",vTemp)))
		THROWWBEMERRHR(hr);

	vDstProps = vTemp;

	// Loop through all the embedded multi-strings in the source object's "RegMultiStringLists" array
	for (int i=0; i < vSrcProps.size(); i++)
	{
		// Get the name of this embedded multi-string property
		_bstr_t sCurSrcPropName = vSrcProps[i].GetString(SMS_Client_Reg_MultiString_List::PROP_ValueName);

		// Is this one of the embedded multi-string properties we want to transfer?
		if (ssProps.find(sCurSrcPropName)!=ssProps.end())
		{
			// Loop through all the embedded multi-strings in the destination object's "RegMultiStringLists" array
			for (int j=0; j < vDstProps.size(); j++)
			{
				// Get the name of this embedded multi-string property
				_bstr_t sCurDstPropname = vDstProps[j].GetString(SMS_Client_Reg_MultiString_List::PROP_ValueName);

				// If this is the same property as the one in the source object, then we copy it
				if (sCurDstPropname==sCurSrcPropName)
				{
					vDstProps[j] = vSrcProps[i];
					cFoundProps++;
					break;
				}
			}
		}
	}

	ASSERT(cFoundProps==ssProps.size());

	if (FAILED(hr=wcoDst.Put(L"RegMultiStringLists",vDstProps.GetVariant())))
		THROWWBEMERRHR(hr);
}

void CConfigItem::TransferEmbeddedPropLists(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrSet& ssProps)
{
	HRESULT hr;
	_variant_t vTemp;
	CWbemClassObjectSafeVector vSrcProps, vDstProps;
	int cFoundProps=0;

	// Get the embedded property lists in the "PropLists" array of the source object
	if (FAILED(hr=wcoSrc.Get(L"PropLists",vTemp)))
		THROWWBEMERRHR(hr);

	vSrcProps = vTemp;

	// Get the embedded property lists in the "PropLists" array of the destination object
	if (FAILED(hr=wcoDst.Get(L"PropLists",vTemp)))
		THROWWBEMERRHR(hr);

	vDstProps = vTemp;

	// Loop through all the property lists in the source object
	for (int i=0; i < vSrcProps.size(); i++)
	{
		// Get the name of this property list
		_bstr_t sCurSrcPropName = vSrcProps[i].GetString(SMS_EmbeddedPropertyList::PROP_PropertyListName);

		// Is this one of the property lists we want to transfer?
		if (ssProps.find(sCurSrcPropName)!=ssProps.end())
		{
			// Loop through all the property lists in the source object
			for (int j=0; j < vDstProps.size(); j++)
			{
				// Get the name of this property list
				_bstr_t sCurDstPropname = vDstProps[j].GetString(SMS_EmbeddedPropertyList::PROP_PropertyListName);

				// Is the source property list the same as this destination property list
				if (sCurDstPropname==sCurSrcPropName)
				{
					// Copy the property list values
					vDstProps[j] = vSrcProps[i];
					cFoundProps++;
					break;
				}
			}
		}
	}

	ASSERT(cFoundProps==ssProps.size());

	// Put the modified PropLists array back into the destination object
	if (FAILED(hr=wcoDst.Put(L"PropLists",vDstProps.GetVariant())))
		THROWWBEMERRHR(hr);

}

void CConfigItem::TransferProps(CWbemClassObject wcoSrc, CWbemClassObject wcoDst, const bstrVector& vsProps)
{
	HRESULT hr;
	_variant_t vValue;

	// Loop through all the properties in the vsProps property name array
	for (int i=0; i < vsProps.size(); i++)
	{
		// Get the property value from the source object
		if (FAILED(hr=wcoSrc.Get(vsProps[i],vValue)))
			THROWWBEMERRHR(hr);

		// Put the property value into the destination object
		if (FAILED(hr = wcoDst.Put(vsProps[i],vValue)))
			THROWWBEMERRHR(hr);
	}

}

_bstr_t CConfigItem::GetSiteServerName(const _bstr_t& sSiteCode) 
{
	// try and find it in the cache first
	_bstr_t sServerName = s_mSiteServerNameCache[sSiteCode];

	if (!sServerName)
	{
		IEnumWbemClassObjectPtr pEnum;
		CWbemClassObject wcoResult;
		ULONG cReturned;
		HRESULT hr;

		// Formulate a query to find the servername for a given sitecode
		_bstr_t sQuery = _bstr_t(L"SELECT ") + SMS_Site::PROP_ServerName + L" FROM " + CLASS_SMS_Site + 
			             L" WHERE " + SMS_Site::PROP_SiteCode + L"=\"" + sSiteCode + L"\"";

		// Execute the query
		hr = m_wsServices.ExecQuery(sQuery,&pEnum);
		if (FAILED(hr))
		   THROWWBEMERRHR(hr);

		// Set the interface security on the query object
		if (FAILED(hr=SetInterfaceSecurity(pEnum, NULL, NULL, NULL, true)))
			THROWWBEMERRHR(hr);

		// Move to the next item in the query
		hr = pEnum->Next(WBEM_INFINITE ,1,&wcoResult,&cReturned);
	
		if (!FAILED(hr) && cReturned>0)
		{
			// Get the ServerName value
			sServerName = wcoResult.GetString(SMS_Site::PROP_ServerName);
		}
		else
		   THROWWBEMERRHR(hr);

		s_mSiteServerNameCache[sSiteCode] = sServerName;
	}

	return sServerName;
}

/****************************************************************************************/

void CSimpleSCI::SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs)
{
	m_sCurSite = sSite;
	vsConfigs.clear();

	// Is the specified unit installed?
	if (ssInstalledUnits.find(m_sUnit)!=ssInstalledUnits.end())
	{
		vsConfigs.assign(m_vsConfigs.begin(),m_vsConfigs.end());
	}
}

void CSimpleSCI::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite)
{
	CWbemClassObject wcoSource,wcoDest;

	// Get the source site control item to transfer from
	wcoSource = GetSiteControlItem();

	if (!wcoSource)
	{
		ASSERT(0);
		return;
	}

	// Get the destination site control item to transfer to
	wcoDest = GetSiteControlItem(sDstSite);

	if (!wcoDest)
	{
		ASSERT(0);
		return;
	}

	// Transfer the settings from the source object to the destination object
    TransferSettingsObj(wcoSource,wcoDest);
}

CWbemClassObject CSimpleSCI::GetSiteControlItem(const _bstr_t& sSiteCode/*=_bstr_t()*/)throw(CWbemException)
{
	// Was a sitecode specified?
	if (!sSiteCode)
		// Get and return the site control item for the current site
		return CConfigItem::GetSiteControlItem(m_sClassName,m_sItemType,m_sItemName,m_sCurSite);
	else
		// Get and return the site control item for the specified site
		return CConfigItem::GetSiteControlItem(m_sClassName,m_sItemType,m_sItemName,sSiteCode);
}

void CSimpleSCI::TransferSettingsObj(CWbemClassObject wcoSource, CWbemClassObject wcoDest)
{
	// Transfer the base properties for the site control item
	if (m_vsPropsToCopy.size()>0)
		TransferProps(wcoSource,wcoDest,m_vsPropsToCopy);

	// Transfer the embedded "Props" for the site control item
	if (m_ssEmbedPropsToCopy.size()>0)
		TransferEmbeddedProps(wcoSource,wcoDest,m_ssEmbedPropsToCopy);

	// Transfer the embedded "PropLists" for the site control item
	if (m_ssEmbedPropListsToCopy.size()>0)
		TransferEmbeddedPropLists(wcoSource,wcoDest,m_ssEmbedPropListsToCopy);

	// Transfer the embedded "RegMultiStringLists" for the site control item
	if (m_ssRegMultiListsToCopy.size()>0)
		TransferMultiStringLists(wcoSource,wcoDest,m_ssRegMultiListsToCopy);

	// Save the changes to the destination object
	HRESULT hr = m_wsServices.PutInstance(wcoDest,WBEM_FLAG_UPDATE_ONLY);
	if (FAILED(hr))
		THROWWBEMERRHR(hr);
}

CWbemClassObject CSimpleSCI::GetEmbeddedProperty(const _bstr_t& sPropName, const _bstr_t& sSiteCode/*=_bstr_t()*/)
{
	// Get the current site control item for the given sitecode
	CWbemClassObject wco = GetSiteControlItem(sSiteCode);

	if (!wco)
	{
		ASSERT(0);
		return wco;
	}

    _variant_t vTemp;	
	HRESULT hr;

	// Get the embedded "Props" for the object
	if (!FAILED(hr=wco.Get(L"Props",vTemp)))
	{	
		CWbemClassObjectSafeVector vwcoProps = vTemp;

		// Loop through all the properties in the "Props" array
		for (int i=0; i < vwcoProps.size(); i++)
		{
			// Get the name of the property
			_bstr_t sCurPropName = vwcoProps[i].GetString(SMS_EmbeddedProperty::PROP_PropertyName);

			// Is this the property the caller wanted?
			if (sCurPropName==sPropName)
				return vwcoProps[i];
		}
	}

	return CWbemClassObject();
}

/****************************************************************************************/

CWbemClassObject CSimpleSCISQ::GetSiteControlItem(const _bstr_t& sSiteCode/*=_bstr_t()*/)throw(CWbemException)
{
	if (!sSiteCode)
		return CConfigItem::GetSiteControlItem(m_sClassName,m_sItemType,m_sItemName + "|" + GetSiteServerName(m_sCurSite),m_sCurSite);
	else
		return CConfigItem::GetSiteControlItem(m_sClassName,m_sItemType,m_sItemName + "|" + GetSiteServerName(sSiteCode), sSiteCode);
}

/****************************************************************************************/

CMultiPartSCI::~CMultiPartSCI()
{
	for (int i=0; i<m_vpParts.size(); i++)
	{
		delete m_vpParts[i];
	}

	m_vpParts.clear();
}

void CMultiPartSCI::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite)
{
	for (int i=0; i<m_vpParts.size(); i++)
	{
		m_vpParts[i]->TransferSettings(sSettingName,sDstSite);
	}
}

void CMultiPartSCI::SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs)
{
	m_sCurSite = sSite;
	vsConfigs.clear();

	if (ssInstalledUnits.find(m_sUnit)!=ssInstalledUnits.end())
	{
		vsConfigs.assign(m_vsConfigs.begin(),m_vsConfigs.end());
	}

	for (int i=0; i<m_vpParts.size(); i++)
	{
		m_vpParts[i]->m_sCurSite = sSite;
	}

}
