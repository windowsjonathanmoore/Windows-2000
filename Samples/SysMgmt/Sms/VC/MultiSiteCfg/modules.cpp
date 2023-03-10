#include "stdpch.h"

#define _USE_AUTOSYMBOLS  // must be defined before the include
#include <smsprov.h>		  // include wbem names.
#include <wbemsec.h>
#include "configapp.h"

#include "modules.h"

using namespace SMSSDK; // save ourselves some typing by using this namespace


/********** Client Agents **************************************************/

// -- Hardware Inventory --

CHinvSettings::CHinvSettings(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{ 
	m_sClassName = CLASS_SMS_SCI_ClientComp;
	m_sItemType=L"Client Component";
	m_sItemName=L"Hardware Inventory Agent";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Hardware Inventory Client Agent");

	m_ssEmbedPropsToCopy.insert(L"Inventory Schedule");
	m_ssEmbedPropsToCopy.insert(L"Maximum 3rd Party MIF Size");

	m_vsPropsToCopy.push_back(SMS_SCI_ClientComp::PROP_Flags);
}

// -- Software Inventory --

CSinvSettings::CSinvSettings(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{ 
	m_sClassName = CLASS_SMS_SCI_ClientComp;
	m_sItemType=L"Client Component";
	m_sItemName=L"Software Inventory Agent";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Software Inventory Client Agent");

	m_ssEmbedPropsToCopy.insert(L"Inventory Schedule");
	m_ssEmbedPropsToCopy.insert(L"Inventoriable Types");
	m_ssEmbedPropsToCopy.insert(L"Report Options");
	m_ssEmbedPropsToCopy.insert(L"Max Collected File Size");
	m_ssEmbedPropsToCopy.insert(L"Collectable Files");

	m_vsPropsToCopy.push_back(SMS_SCI_ClientComp::PROP_Flags);
}

CAPSettings::CAPSettings(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{ 
	m_sClassName = CLASS_SMS_SCI_ClientComp;
	m_sItemType=L"Client Component";
	m_sItemName=L"Software Distribution";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Advertised Programs Client Agent");

	m_ssEmbedPropsToCopy.insert(L"Refresh Minutes");
	m_ssEmbedPropsToCopy.insert(L"Use Settings");
	m_ssEmbedPropsToCopy.insert(L"Visible Signal on Available");
	m_ssEmbedPropsToCopy.insert(L"Audible Signal on Available");
	m_ssEmbedPropsToCopy.insert(L"Countdown Signal");
	m_ssEmbedPropsToCopy.insert(L"Countdown Minutes");
	m_ssEmbedPropsToCopy.insert(L"Audible Countdown Signal");
	m_ssEmbedPropsToCopy.insert(L"Show Icon");

	m_vsPropsToCopy.push_back(SMS_SCI_ClientComp::PROP_Flags);
}

// -- Remote Tools --

CRToolSettings::CRToolSettings(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_ClientComp;
	m_sItemType=L"Client Component";
	m_sItemName=L"Remote Control";
	m_sUnit=L"REMOTE CONTROL";

	m_vsConfigs.push_back("Remote Tools Client Agent");

	m_ssEmbedPropsToCopy.insert(L"Allow Client Change");
	m_ssEmbedPropsToCopy.insert(L"Allow Takeover");
	m_ssEmbedPropsToCopy.insert(L"Allow Remote Execute");
	m_ssEmbedPropsToCopy.insert(L"Allow File Transfer");
	m_ssEmbedPropsToCopy.insert(L"Allow Reboot");
	m_ssEmbedPropsToCopy.insert(L"Allow Chat");
	m_ssEmbedPropsToCopy.insert(L"Allow View Configuration");
	m_ssEmbedPropsToCopy.insert(L"Permission Required");
	m_ssEmbedPropsToCopy.insert(L"IndicatorType");
	m_ssEmbedPropsToCopy.insert(L"Visible Signal");
	m_ssEmbedPropsToCopy.insert(L"Audible Signal");
	m_ssEmbedPropsToCopy.insert(L"Always Visible");
	m_ssEmbedPropsToCopy.insert(L"CompressionType");
	m_ssEmbedPropsToCopy.insert(L"Default Protocol");
	m_ssEmbedPropsToCopy.insert(L"LanaNum");
	m_ssEmbedPropsToCopy.insert(L"Use IDIS");
	m_ssEmbedPropsToCopy.insert(L"Control Level");

	m_ssRegMultiListsToCopy.insert(L"PermittedViewers");
	m_ssRegMultiListsToCopy.insert(L"Video Drivers");

	m_vsPropsToCopy.push_back(SMS_SCI_ClientComp::PROP_Flags);
}


// --  Software Metering -- 

CSWMSettings::CSWMSettings(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"LICENSE METERING";
	m_vsConfigs.push_back("Software Metering Client Agent");

	CSubComps *pPart = new CSubComps(wsServ);

	// SMS_SCI_ClientComp - LICENSE METERING
	pPart->m_sClassName = CLASS_SMS_SCI_ClientComp;
	pPart->m_sItemType=L"Client Component";
	pPart->m_sItemName=L"LICENSE METERING";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_ClientComp::PROP_Flags);
	pPart->m_ssEmbedPropsToCopy.insert(L"GoOnlineInt");
	pPart->m_ssEmbedPropsToCopy.insert(L"TriesBeforeOffline");
	pPart->m_ssEmbedPropsToCopy.insert(L"ContinuousOffline");

	m_vpParts.push_back(pPart);

	CSubCompsSQ *pPartSQ = new CSubCompsSQ(wsServ);
	pPartSQ->m_sClassName = CLASS_SMS_SCI_Component;
	pPartSQ->m_sItemType=L"Component";
	pPartSQ->m_sItemName=L"LICENSE_METERING";
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LTMSYNCINT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_SZOPERMSG");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPTSZ_SZCHKOUTMSG");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPTSZ_SZINACTMSG");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LINFCKINT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LDNYMSGTM");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LCLGNTTIOT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LCLRCBINT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LCLREQTIOT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LCLTACTINT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LCLTCHKINT");
	pPartSQ->m_ssEmbedPropsToCopy.insert(L"SYSOPT_LCLTTIOT");

	m_vpParts.push_back(pPartSQ);
}


// -- Event To Trap Translator Client Agent Properties --

CTrapSettings::CTrapSettings(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_ClientComp;
	m_sItemType=L"Client Component";
	m_sItemName=L"NT Event to SNMP Trap Translator";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Event To Trap Translator Client Agent");

	m_vsPropsToCopy.push_back(SMS_SCI_ClientComp::PROP_Flags);

}

/*********Client Installation Methods **********************************************************************/

// -- Windows Networking Logon Client Installation --

CNetLogonCI::CNetLogonCI(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"SMS";
	m_vsConfigs.push_back("Windows NT Logon Client Installation");

	CSubCompsSQ *pPart = new CSubCompsSQ(wsServ);

	// SMS_NT_LOGON_INSTALLATION_MANAGER
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
//	pPart->m_ssEmbedPropListsToCopy.insert(L"Domain List");
//	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_ssEmbedPropsToCopy.insert(L"SETTINGS");
	pPart->m_sItemName = L"SMS_NT_LOGON_INSTALLATION_MANAGER";

	m_vpParts.push_back(pPart);

/*
	// copy SMS_NT_LOGON_DISCOVERY_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NT_LOGON_DISCOVERY_MANAGER";

	m_vpParts.push_back(pPart);
*/

	// SMS_NT_LOGON_SERVER_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"POLLING INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT PROPERTIES");
	pPart->m_sItemName = L"SMS_NT_LOGON_SERVER_MANAGER";

	m_vpParts.push_back(pPart);
}

void CNetLogonCI::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) 
{
/*
	// only copy the Domain List property for Logon Discovery if we are set to keep the lists synchronized
	CSubCompsSQ* pPart = (CSubCompsSQ*)m_vpParts[1];
	CWbemClassObject wcoSrc = pPart->GetEmbeddedProperty(L"Synchronize Lists");
	long lVal=0;

	if (wcoSrc)
		lVal = wcoSrc.GetLong(SMS_EmbeddedProperty::PROP_Value);


	if (lVal)
		pPart->m_ssEmbedPropListsToCopy.insert(L"Domain List");
	else
		pPart->m_ssEmbedPropListsToCopy.erase(L"Domain List");
*/

	CMultiPartSCI::TransferSettings(sSettingName,sDstSite);
}


// -- Windows NT Remote Client Installation -- 

CRemoteCI::CRemoteCI(CWbemServices& wsServ) : CSimpleSCISQ(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_Component;
	m_sItemType=L"Component";
	m_sItemName=L"SMS_DISCOVERY_DATA_MANAGER";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Windows NT Remote Client Installation");

	m_ssEmbedPropsToCopy.insert(L"SETTINGS");
	m_ssEmbedPropsToCopy.insert(L"FILTERS");

}

// -- NetWare NDS Logon Client Installation --

CNDSNetLogonCI::CNDSNetLogonCI(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"NWNDS";
	m_vsConfigs.push_back("NetWare NDS Logon Client Installation");

	CSubCompsSQ *pPart = new CSubCompsSQ(wsServ);

	// SMS_NDS_LOGON_INSTALLATION_MANAGER
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
//	pPart->m_ssEmbedPropListsToCopy.insert(L"Context List");
	pPart->m_ssEmbedPropsToCopy.insert(L"SETTINGS");
//	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NDS_LOGON_INSTALLATION_MANAGER";

	m_vpParts.push_back(pPart);

/*
	// copy SMS_NDS_LOGON_DISCOVERY_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NDS_LOGON_DISCOVERY_MANAGER";

	m_vpParts.push_back(pPart);
*/

	// SMS_NDS_LOGON_SERVER_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT PROPERTIES");
	pPart->m_sItemName = L"SMS_NDS_LOGON_SERVER_MANAGER";

	m_vpParts.push_back(pPart);
}

void CNDSNetLogonCI::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) 
{
/*
	// only copy the Domain List property for Logon Installation if we are set to keep the lists synchronized
	CSubCompsSQ* pPart = (CSubCompsSQ*)m_vpParts[1];
	CWbemClassObject wcoSrc = pPart->GetEmbeddedProperty(L"Synchronize Lists");
	long lVal=0;

	if (wcoSrc)
		lVal = wcoSrc.GetLong(SMS_EmbeddedProperty::PROP_Value);

	if (lVal)
		pPart->m_ssEmbedPropListsToCopy.insert(L"Context List");
	else
		pPart->m_ssEmbedPropListsToCopy.erase(L"Context List");
*/
	CMultiPartSCI::TransferSettings(sSettingName,sDstSite);
}

// -- NetWare Bindery Logon Client Installation --

CNWNetLogonCI::CNWNetLogonCI(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"NWBIND";
	m_vsConfigs.push_back("NetWare Bindery Logon Client Installation");

	CSubCompsSQ *pPart = new CSubCompsSQ(wsServ);

	// SMS_NW_LOGON_INSTALLATION_MANAGER
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
//	pPart->m_ssEmbedPropListsToCopy.insert(L"Server List");
	pPart->m_ssEmbedPropsToCopy.insert(L"SETTINGS");
//	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NW_LOGON_INSTALLATION_MANAGER";

	m_vpParts.push_back(pPart);

/*
	// SMS_NW_LOGON_DISCOVERY_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NW_LOGON_DISCOVERY_MANAGER";

	m_vpParts.push_back(pPart);
*/

	// SMS_NW_LOGON_SERVER_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT PROPERTIES");
	pPart->m_sItemName = L"SMS_NW_LOGON_SERVER_MANAGER";

	m_vpParts.push_back(pPart);
}

void CNWNetLogonCI::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) 
{
/*
	// only copy the Server List property for Logon Installation if we are set to keep the lists synchronized
	CSubCompsSQ* pPart = (CSubCompsSQ*)m_vpParts[1];
	CWbemClassObject wcoSrc = pPart->GetEmbeddedProperty(L"Synchronize Lists");
	long lVal=0;

	if (wcoSrc)
		lVal = wcoSrc.GetLong(SMS_EmbeddedProperty::PROP_Value);

	if (lVal)
		pPart->m_ssEmbedPropListsToCopy.insert(L"Server List");
	else
		pPart->m_ssEmbedPropListsToCopy.erase(L"Server List");
*/
	CMultiPartSCI::TransferSettings(sSettingName,sDstSite);
}


/********* Discovery Methods **********************************************************************/

CNetLogonDisc::CNetLogonDisc(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"SMS";
	m_vsConfigs.push_back("Windows NT Logon Discovery");

	CSubCompsSQ *pPart = new CSubCompsSQ(wsServ);

	// copy SMS_NT_LOGON_DISCOVERY_MANAGER
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
//	pPart->m_ssEmbedPropListsToCopy.insert(L"Domain List");
	pPart->m_ssEmbedPropsToCopy.insert(L"SETTINGS");
//	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NT_LOGON_DISCOVERY_MANAGER";

	m_vpParts.push_back(pPart);

/*
	// SMS_NT_LOGON_INSTALLATION_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NT_LOGON_INSTALLATION_MANAGER";

	m_vpParts.push_back(pPart);
*/

	// SMS_NT_LOGON_SERVER_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"POLLING INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT PROPERTIES");
	pPart->m_sItemName = L"SMS_NT_LOGON_SERVER_MANAGER";

	m_vpParts.push_back(pPart);
}


void CNetLogonDisc::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) 
{
/*
	// only copy the Domain List property for Logon Discovery if we are set to keep the lists synchronized
	CSubCompsSQ* pPart = (CSubCompsSQ*)m_vpParts[1];
	CWbemClassObject wcoSrc = pPart->GetEmbeddedProperty(L"Synchronize Lists");
	long lVal=0;

	if (wcoSrc)
		lVal = wcoSrc.GetLong(SMS_EmbeddedProperty::PROP_Value);

	if (lVal)
		pPart->m_ssEmbedPropListsToCopy.insert(L"Domain List");
	else
		pPart->m_ssEmbedPropListsToCopy.erase(L"Domain List");
*/
	CMultiPartSCI::TransferSettings(sSettingName,sDstSite);
}

// -- NetWare NDS Logon Discovery --

CNDSNetLogonDisc::CNDSNetLogonDisc(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"NWNDS";
	m_vsConfigs.push_back("NetWare NDS Logon Discovery");

	CSubCompsSQ *pPart = new CSubCompsSQ(wsServ);

	// copy SMS_NDS_LOGON_DISCOVERY_MANAGER
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
//	pPart->m_ssEmbedPropListsToCopy.insert(L"Context List");
	pPart->m_ssEmbedPropsToCopy.insert(L"SETTINGS");
//	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NDS_LOGON_DISCOVERY_MANAGER";

	m_vpParts.push_back(pPart);

/*
	// SMS_NDS_LOGON_INSTALLATION_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NDS_LOGON_INSTALLATION_MANAGER";

	m_vpParts.push_back(pPart);
*/

	// SMS_NDS_LOGON_SERVER_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT PROPERTIES");
	pPart->m_sItemName = L"SMS_NDS_LOGON_SERVER_MANAGER";

	m_vpParts.push_back(pPart);
}

void CNDSNetLogonDisc::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) 
{
/*
	// only copy the Domain List property for Logon Discovery if we are set to keep the lists synchronized
	CSubCompsSQ* pPart = (CSubCompsSQ*)m_vpParts[1];
	CWbemClassObject wcoSrc = pPart->GetEmbeddedProperty(L"Synchronize Lists");
	long lVal=0;

	if (wcoSrc)
		lVal = wcoSrc.GetLong(SMS_EmbeddedProperty::PROP_Value);

	if (lVal)
		pPart->m_ssEmbedPropListsToCopy.insert(L"Context List");
	else
		pPart->m_ssEmbedPropListsToCopy.erase(L"Context List");
*/
	CMultiPartSCI::TransferSettings(sSettingName,sDstSite);
}

// -- NetWare Bindery Logon Discovery --

CNWNetLogonDisc::CNWNetLogonDisc(CWbemServices& wsServ) : CMultiPartSCI(wsServ)
{
	m_sUnit=L"NWBIND";
	m_vsConfigs.push_back("NetWare Bindery Logon Discovery");

	CSubCompsSQ *pPart = new CSubCompsSQ(wsServ);

	// SMS_NW_LOGON_DISCOVERY_MANAGER
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
//	pPart->m_ssEmbedPropListsToCopy.insert(L"Server List");
	pPart->m_ssEmbedPropsToCopy.insert(L"SETTINGS");
//	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NW_LOGON_DISCOVERY_MANAGER";

	m_vpParts.push_back(pPart);

/*
	// SMS_NW_LOGON_INSTALLATION_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"Synchronize Lists");
	pPart->m_sItemName = L"SMS_NW_LOGON_INSTALLATION_MANAGER";

	m_vpParts.push_back(pPart);
*/

	// SMS_NW_LOGON_SERVER_MANAGER
	pPart = new CSubCompsSQ(wsServ);
	pPart->m_sClassName = CLASS_SMS_SCI_Component;
	pPart->m_sItemType=L"Component";
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT INTERVAL");
	pPart->m_ssEmbedPropsToCopy.insert(L"SCRIPT PROPERTIES");
	pPart->m_sItemName = L"SMS_NW_LOGON_SERVER_MANAGER";

	m_vpParts.push_back(pPart);
}

void CNWNetLogonDisc::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) 
{
	// only copy the Server List property for Logon Discovery if we are set to keep the lists synchronized
	CSubCompsSQ* pPart = (CSubCompsSQ*)m_vpParts[1];
	CWbemClassObject wcoSrc = pPart->GetEmbeddedProperty(L"Synchronize Lists");
	long lVal=0;

	if (wcoSrc)
		lVal = wcoSrc.GetLong(SMS_EmbeddedProperty::PROP_Value);

	if (lVal)
		pPart->m_ssEmbedPropListsToCopy.insert(L"Server List");
	else
		pPart->m_ssEmbedPropListsToCopy.erase(L"Server List");

	CMultiPartSCI::TransferSettings(sSettingName,sDstSite);
}

// ------- Heartbeat Discovery ------------

CHeartbeatDisc::CHeartbeatDisc(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_ClientConfig;
	m_sItemType=L"Client Configuration";
	m_sItemName=L"Client Properties";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Heartbeat Discovery");

	m_ssEmbedPropsToCopy.insert(L"Enable Heartbeat DDR");
	m_ssEmbedPropsToCopy.insert(L"DDR Refresh Interval");
}

// ------------ Windows NT User Account Discovery Properties ------------

CNTUserDisc::CNTUserDisc(CWbemServices& wsServ) : CSimpleSCISQ(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_Component;
	m_sItemType=L"Component";
	m_sItemName=L"SMS_NT_USER_DISCOVERY_AGENT";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Windows NT User Account Discovery");

	m_ssEmbedPropListsToCopy.insert(L"NT Domains");

	m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
	m_ssEmbedPropsToCopy.insert(L"SETTINGS");
	m_ssEmbedPropsToCopy.insert(L"Startup Schedule");
}


// ------------ Windows NT User Group Account Discovery Properties ------------

CNTGroupDisc::CNTGroupDisc(CWbemServices& wsServ) : CSimpleSCISQ(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_Component;
	m_sItemType=L"Component";
	m_sItemName=L"SMS_NT_USER_GROUP_DISCOVERY_AGENT";
	m_sUnit=L"SMS";

	m_vsConfigs.push_back("Windows NT User Group Discovery");

	m_ssEmbedPropListsToCopy.insert(L"NT Domains");

	m_vsPropsToCopy.push_back(SMS_SCI_Component::PROP_Flag);
	m_ssEmbedPropsToCopy.insert(L"SETTINGS");
	m_ssEmbedPropsToCopy.insert(L"Startup Schedule");
}



/************** Addreses **************************************************************************/


CAddress::CAddress(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_Address;
	m_sItemType=L"Address";
	m_sUnit=L"SMS";

	m_vsPropsToCopy.push_back(SMS_SCI_Address::PROP_RateLimitingSchedule);
	m_vsPropsToCopy.push_back(SMS_SCI_Address::PROP_UnlimitedRateForAll);

	m_mssTypeToDispName[_bstr_t(L"MS_LAN")] = _bstr_t(L"Standard");
	m_mssTypeToDispName[_bstr_t(L"MS_ASYNC_RAS")] = _bstr_t(L"Asynch RAS");
	m_mssTypeToDispName[_bstr_t(L"MS_ISDN_RAS")] = _bstr_t(L"ISDN RAS");
	m_mssTypeToDispName[_bstr_t(L"MS_X25_RAS")] = _bstr_t(L"X25 RAS");
	m_mssTypeToDispName[_bstr_t(L"MS_SNA_RAS")] = _bstr_t(L"SNA RAS");

}

void CAddress::SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs)
{
	HRESULT hr=0;
	ULONG ulReturned;
	IEnumWbemClassObjectPtr pEnum;
	CWbemClassObject wcoResult;
	_bstr_t sWQL;
		
	m_sCurSite = sSite;

	sWQL =  _bstr_t(L"SELECT ") + SMS_SCI_Address::PROP_AddressType  + L",";
	sWQL += _bstr_t(SMS_SCI_Address::PROP_DesSiteCode) + L",";
	sWQL += _bstr_t(SMS_SiteControlItem::PROP_ItemName);
	sWQL += _bstr_t(L" FROM ") + CLASS_SMS_SCI_Address;
	sWQL += _bstr_t(L" WHERE ") + SMS_SiteControlItem::PROP_SiteCode + L"=\"" + m_sCurSite + L"\"";


	if (!FAILED(hr=m_wsServices.ExecQuery(sWQL,  &pEnum)))
	{
		if(!FAILED(hr=SetInterfaceSecurity(pEnum, NULL, NULL, NULL, true) ) )
		{
			while (!FAILED(hr=pEnum->Next(-1, 1, &wcoResult, &ulReturned)) && ulReturned>0)
			{
				_bstr_t sTitle, sType, sDesSiteCode, sItemName;

				sType = wcoResult.GetString(SMS_SCI_Address::PROP_AddressType);

				if (sType != _bstr_t(L"MS_COURIER"))
				{
					sDesSiteCode = wcoResult.GetString(SMS_SCI_Address::PROP_DesSiteCode);
					sItemName = wcoResult.GetString(SMS_SiteControlItem::PROP_ItemName);
					sTitle = _bstr_t(L"Address to ") + sDesSiteCode + L" - ";
					
					if (m_mssTypeToDispName[sType].length() > 0)
					{
						sTitle += m_mssTypeToDispName[sType];
					}
					else
					{
						sTitle += sType;
					}

					sTitle += L" Sender";

					vsConfigs.push_back(sTitle);
					m_mssNameToItemName[sTitle] = sItemName;
				}
			}
		}
	}

	ASSERT(!FAILED(hr));
}

void CAddress::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite)
{
	HRESULT hr=0;
	ULONG ulReturned;
	IEnumWbemClassObjectPtr pEnum;

	CWbemClassObject wcoSource, wcoDest;

	m_sItemName = m_mssNameToItemName[sSettingName];

	wcoSource = GetSiteControlItem();
	_bstr_t sAddressType = wcoSource.GetString(SMS_SCI_Address::PROP_AddressType);

	_bstr_t sWQL = _bstr_t("SELECT * FROM ") + CLASS_SMS_SCI_Address + L" WHERE ";
	sWQL += _bstr_t(SMS_SCI_Address::PROP_AddressType) + L"=\"" + sAddressType + "\"";
	sWQL += _bstr_t(L" AND ") + SMS_SiteControlItem::PROP_SiteCode + L"=\"" + sDstSite + L"\"";

	if (FAILED(hr=m_wsServices.ExecQuery(sWQL,  &pEnum)))
		THROWWBEMERRHR(hr);

	if (FAILED(hr=SetInterfaceSecurity(pEnum, NULL, NULL, NULL, true)))
		THROWWBEMERRHR(hr);

	while (!FAILED(hr=pEnum->Next(WBEM_INFINITE, 1, &wcoDest, &ulReturned)) && ulReturned>0)
	{
		TransferProps(wcoSource,wcoDest,m_vsPropsToCopy);
		TransferUsageSchedule(wcoSource,wcoDest);

		if (FAILED(hr=m_wsServices.PutInstance(wcoDest,WBEM_FLAG_UPDATE_ONLY)))
			THROWWBEMERRHR(hr);
	}

}

void CAddress::TransferUsageSchedule(CWbemClassObject wcoSrc, CWbemClassObject wcoDst)
{
	HRESULT hr;
	_variant_t vTemp;
	CWbemClassObjectSafeVector vSrcProps;

	if (FAILED(hr=wcoSrc.Get(SMS_SCI_Address::PROP_UsageSchedule,vTemp)))
		THROWWBEMERRHR(hr);

	vSrcProps = vTemp;

    // update needs to be set if for the SMS provider to pay attention to it
	// in theory you could scan through both Backup and HourUsage arrays and only 
	// set update if they differed....
	// even though we're changing the source property, it doesn't affect anything as we never
	// put the source SMS_SCI_Address back into wbem.
	for (int i=0; i < vSrcProps.size(); i++)
	{
		vSrcProps[i].Put(SMS_SiteControlDaySchedule::PROP_update,_variant_t(true));
	}


	if (FAILED(hr=wcoDst.Put(SMS_SCI_Address::PROP_UsageSchedule,vSrcProps.GetVariant())))
		THROWWBEMERRHR(hr);

}

/************** Sender *************************************/


CSender::CSender(CWbemServices& wsServ) : CSimpleSCI(wsServ)
{
	m_sClassName = CLASS_SMS_SCI_Component;
	m_sItemType=L"Component";
	m_sUnit=L"SMS";

	m_ssEmbedPropsToCopy.insert(L"Concurrent Sending Limit");
	m_ssEmbedPropsToCopy.insert(L"Number of Retries");
	m_ssEmbedPropsToCopy.insert(L"Retry Delay");

	m_mssTypeToDispName[_bstr_t(L"SMS_LAN_SENDER")] = _bstr_t(L"Standard");
	m_mssTypeToDispName[_bstr_t(L"SMS_ASYNC_RAS_SENDER")] = _bstr_t(L"Asynch RAS");
	m_mssTypeToDispName[_bstr_t(L"SMS_ISDN_RAS_SENDER")] = _bstr_t(L"ISDN RAS");
	m_mssTypeToDispName[_bstr_t(L"SMS_X25_RAS_SENDER")] = _bstr_t(L"X25 RAS");
	m_mssTypeToDispName[_bstr_t(L"SMS_SNA_RAS_SENDER")] = _bstr_t(L"SNA RAS");

}

void CSender::SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs)
{
	HRESULT hr=0;
	ULONG ulReturned;
	IEnumWbemClassObjectPtr pEnum;
	CWbemClassObject wcoResult;
	_bstr_t sWQL;
		
	m_sCurSite = sSite;

	sWQL =  _bstr_t(L"SELECT ") + SMS_SCI_Component::PROP_ComponentName  + L",";
	sWQL += _bstr_t(SMS_SCI_Component::PROP_Name) + L",";
	sWQL += _bstr_t(SMS_SiteControlItem::PROP_ItemName);
	sWQL += _bstr_t(L" FROM ") + CLASS_SMS_SCI_Component;
	sWQL += _bstr_t(L" WHERE ") + SMS_SiteControlItem::PROP_SiteCode + L"=\"" + m_sCurSite + L"\"";


	if (!FAILED(hr=m_wsServices.ExecQuery(sWQL,  &pEnum)))
	{
		if(!FAILED(hr=SetInterfaceSecurity(pEnum, NULL, NULL, NULL, true) ) )
		{
			while (!FAILED(hr=pEnum->Next(WBEM_INFINITE, 1, &wcoResult, &ulReturned)) && ulReturned>0)
			{
				_bstr_t sTitle, sType, sServer, sItemName;

				sType = wcoResult.GetString(SMS_SCI_Component::PROP_ComponentName);

				sServer = wcoResult.GetString(SMS_SCI_Component::PROP_Name);
				sItemName = wcoResult.GetString(SMS_SiteControlItem::PROP_ItemName);
				
				if (m_mssTypeToDispName[sType].length() > 0)
				{
					sTitle = m_mssTypeToDispName[sType];
				}
				else
				{
					_bstr_t sRight6 = _bstr_t(((wchar_t*)sType)+sType.length()-6);
					if (sRight6!=_bstr_t(L"SENDER"))
						continue;

					sTitle = sType;
				}

				sTitle += L" Sender on " + sServer;

				vsConfigs.push_back(sTitle);
				m_mssNameToItemName[sTitle] = sItemName;
			}
		}
	}

	ASSERT(!FAILED(hr));
}

void CSender::TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite)
{
	HRESULT hr=0;
	ULONG ulReturned;
	IEnumWbemClassObjectPtr pEnum;

	CWbemClassObject wcoSource, wcoDest;

	m_sItemName = m_mssNameToItemName[sSettingName];

	wcoSource = GetSiteControlItem();
	_bstr_t sSenderType = wcoSource.GetString(SMS_SCI_Component::PROP_ComponentName);

	_bstr_t sWQL = _bstr_t("SELECT * FROM ") + CLASS_SMS_SCI_Component + L" WHERE ";
	sWQL += _bstr_t(SMS_SCI_Component::PROP_ComponentName) + L"=\"" + sSenderType + "\"";
	sWQL += _bstr_t(L" AND ") + SMS_SiteControlItem::PROP_SiteCode + L"=\"" + sDstSite + L"\"";

	if (FAILED(hr=m_wsServices.ExecQuery(sWQL,  &pEnum)))
		THROWWBEMERRHR(hr);

	if (FAILED(hr=SetInterfaceSecurity(pEnum, NULL, NULL, NULL, true)))
		THROWWBEMERRHR(hr);

	while (!FAILED(hr=pEnum->Next(WBEM_INFINITE, 1, &wcoDest, &ulReturned)) && ulReturned>0)
	{
		TransferEmbeddedProps(wcoSource,wcoDest,m_ssEmbedPropsToCopy);

		if (FAILED(hr=m_wsServices.PutInstance(wcoDest,WBEM_FLAG_UPDATE_ONLY)))
			THROWWBEMERRHR(hr);
	}

}

