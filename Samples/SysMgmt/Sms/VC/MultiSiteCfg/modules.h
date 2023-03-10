
//////////////////////////////////////////////////////////////////////////
// Modules.h
// 
// Contains the definitions for the transfer objects (derived from CConfigItem).
//
// The following modules are defined:
//
// Client Agents
//    CHinvSettings  - Hardware Inventory Client Agent
//    CSinvSettings  - Software Inventory Client Agent
//    CAPSettings    - Advertised Programs Client Agent
//    CRToolSettings - Remote Tools Client Agent
//    CSWMSettings   - Software Metering Client Agent
//    CTrapSettings  - Event To Trap Translator Client Agent
//
// Logon Discovery Methods
//    CNetLogonDisc    - Windows NT Network Logon Discovery
//    CNDSNetLogonDisc - Netware NDS Logon Discovery
//    CNWNetLogonDisc  - Netware Bidary Logon Discovery
//    CHeartbeatDisc   - Heartbeat Discovery
//    CNTUserDisc      - Windows NT User Discovery
//    CNTGroupDisc     - Windows NT User Group Discovery

//
// Client Installation Methods
//    CNetLogonCI    - Windows Networking Logon Client Installation
//	  CRemoteCI      - Windows NT Remote Client Installation
//    CNDSNetLogonCI - Netware NDS Logon Client Installation
//    CNWNetLogonCI  - Netware Bindary Logon Client Installation
//
//
// Addresses
//    CAddress       - Addresses
//
// Senders
//    CSender        - Senders
//
//////////////////////////////////////////////////////////////////////////


class CSimpleSCI;
class CMultiPartSCI;

/********** Client Agents **************/
class CHinvSettings : public CSimpleSCI
{
public:

	CHinvSettings(CWbemServices& wsServ);

};

class CSinvSettings : public CSimpleSCI
{
public:

	CSinvSettings(CWbemServices& wsServ);

};

class CAPSettings : public CSimpleSCI
{
public:

	CAPSettings(CWbemServices& wsServ);

};

class CRToolSettings : public CSimpleSCI
{
public:

	CRToolSettings(CWbemServices& wsServ);

};

class CSWMSettings : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CSWMSettings;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

	class CSubComps : public CSimpleSCI
	{
		friend class CSWMSettings;
	public:
		CSubComps(CWbemServices& wsServ) : CSimpleSCI(wsServ) {}
	};

public:
	CSWMSettings(CWbemServices& wsServ);

};

class CTrapSettings : public CSimpleSCI
{
public:
	CTrapSettings(CWbemServices& wsServ);

};

/*********** Client Installation Methods *******/

class CNetLogonCI : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CNetLogonCI;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

public:

	CNetLogonCI(CWbemServices& wsServ);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;

};

class CRemoteCI : public CSimpleSCISQ
{
	public:

	CRemoteCI(CWbemServices& wsServ);

};

class CNDSNetLogonCI : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CNDSNetLogonCI;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

public:

	CNDSNetLogonCI(CWbemServices& wsServ);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
};

class CNWNetLogonCI : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CNWNetLogonCI;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

public:

	CNWNetLogonCI(CWbemServices& wsServ);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
};


/***************** Discovery Methods ********************/


class CNetLogonDisc : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CNetLogonDisc;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

public:

	CNetLogonDisc(CWbemServices& wsServ);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;

};

class CNDSNetLogonDisc : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CNDSNetLogonDisc;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

public:

	CNDSNetLogonDisc(CWbemServices& wsServ);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
};

class CNWNetLogonDisc : public CMultiPartSCI
{
protected:
	class CSubCompsSQ : public CSimpleSCISQ
	{
		friend class CNWNetLogonDisc;
	public:
		CSubCompsSQ(CWbemServices& wsServ) : CSimpleSCISQ(wsServ) {}
	};

public:

	CNWNetLogonDisc(CWbemServices& wsServ);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
};

class CHeartbeatDisc : public CSimpleSCI
{
public:
	CHeartbeatDisc(CWbemServices& wsServ);
};

class CNTUserDisc : public CSimpleSCISQ
{
public:
	CNTUserDisc(CWbemServices& wsServ);
};

class CNTGroupDisc : public CSimpleSCISQ
{
public:
	CNTGroupDisc(CWbemServices& wsServ);
};


/******************** Addresses **************************/

class CAddress : public CSimpleSCI
{
private:
	bstr2bstrMap m_mssTypeToDispName;
	bstr2bstrMap m_mssNameToItemName;
	void TransferUsageSchedule(CWbemClassObject wcoSrc, CWbemClassObject wcoDst) ;

public:
	CAddress(CWbemServices& wsServ);
	void SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;

};

/*********** Sender *********************/

class CSender : public CSimpleSCI
{
private:
	bstr2bstrMap m_mssTypeToDispName;
	bstr2bstrMap m_mssNameToItemName;

public:
	CSender(CWbemServices& wsServ);
	void SetSiteAndGetAvailConfigs(const _bstr_t& sSite, const bstrSet& ssInstalledUnits, bstrVector& vsConfigs);
	void TransferSettings(const _bstr_t& sSettingName, const _bstr_t& sDstSite) ;
};

