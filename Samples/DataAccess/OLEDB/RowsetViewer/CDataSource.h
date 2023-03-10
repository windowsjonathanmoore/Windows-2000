//-----------------------------------------------------------------------------
// Microsoft OLE DB RowsetViewer
// Copyright (C) 1994 - 2000 By Microsoft Corporation.
//
// @doc
//
// @module CDATASOURCE.H
//
//-----------------------------------------------------------------------------------

#ifndef _CDATASOURCE_H_
#define _CDATASOURCE_H_


///////////////////////////////////////////////////////////////
// Includes
//
///////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////
// CDataSource class
//
/////////////////////////////////////////////////////////////////
class CDataSource : public CPropertiesBase
{
public:
	//Constructors
	CDataSource(CMainWindow* pCMainWindow, CMDIChild* pCMDIChild = NULL);
	virtual ~CDataSource();

	//IUnknown Helpers
	virtual HRESULT			AutoQI(DWORD dwCreateOpts);
	virtual HRESULT			AutoRelease();
	virtual IUnknown**		GetInterfaceAddress(REFIID riid);

	//Pure Virtual
	virtual WCHAR*			GetObjectName()			{ return L"DataSource";				}
	virtual UINT			GetObjectMenu()			{ return IDM_DATASOURCEMENU;		}
	virtual REFIID			GetDefaultInterface()	{ return IID_IDBProperties;			}
	virtual WCHAR*			GetObjectDesc();
	virtual LONG			GetObjectImage()	{ return IMAGE_DATASOURCE;			}

	//Members

	//Helpers
	virtual HRESULT			CreateSession(CAggregate* pCAggregate, REFIID riid, IUnknown** ppIUnknown);
	virtual HRESULT			AdminCreateDataSource(CAggregate* pCAggregate, ULONG cPropSets, DBPROPSET* rgPropSets, REFIID riid, IUnknown** ppIUnknown);
	virtual HRESULT			GetClassID(CLSID* pclsid, WCHAR** ppwszProgID = NULL);

	//OLE DB Interfaces
	//[MANADATORY]
	IDBCreateSession*			m_pIDBCreateSession;			//DataSource interface
	IPersist*					m_pIPersist;					//DataSource interface

	//[OPTIONAL]
	IDBDataSourceAdmin*			m_pIDBDataSourceAdmin;			//DataSource interface
	IDBInfo*					m_pIDBInfo;						//DataSource interface
	IPersistFile*				m_pIPersistFile;				//DataSource interface

	//Services
	IServiceProvider*			m_pIServiceProvider;			//Service Interface

	//DataSource info
	BSTR						m_bstrDataSource;
	BSTR						m_bstrDBMS;
	BSTR						m_bstrDBMSVer;

	BSTR						m_bstrProviderName;
	BSTR						m_bstrProviderDesc;
	LONG						m_lDataSourceType;
};


#endif	//_CDATASOURCE_H_
