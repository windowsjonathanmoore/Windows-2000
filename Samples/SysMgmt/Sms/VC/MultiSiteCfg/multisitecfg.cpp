// MultiSiteCfg.cpp : Defines the class behaviors for the application.
//

#include "stdpch.h"

#define _USE_AUTOSYMBOLS  // must be defined before the include
#define _INIT_AUTOSYMBOLS // must be defined before the include in one and only one file
#include <smsprov.h>		  // include wbem names.
#include <algorithm>

#include "MultiSiteCfg.h"
#include "MultiSiteCfgDlg.h"
#include "GetServerDlg.h"
#include "wbemsec.h"
#include "cmdfile.h"
#include "configapp.h"

using namespace SMSSDK;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgApp

BEGIN_MESSAGE_MAP(CMultiSiteCfgApp, CWinApp)
	//{{AFX_MSG_MAP(CMultiSiteCfgApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgApp construction

CMultiSiteCfgApp::CMultiSiteCfgApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMultiSiteCfgApp object

CMultiSiteCfgApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMultiSiteCfgApp initialization

BOOL CMultiSiteCfgApp::InitInstance()
{

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CoInitializeEx(0, COINIT_APARTMENTTHREADED ); 
	InitializeSecurity(TRUE);

	{

		m_pCfg = new CConfigApp(AfxGetAppName());

		CThisAppCommandLineInfo cliCmdLine;
		ParseCommandLine(cliCmdLine);

		if (cliCmdLine.m_csNamespace.IsEmpty() && cliCmdLine.m_csServer.IsEmpty() && cliCmdLine.m_csCmdFile.IsEmpty())
		{
			CGetServerDlg gsdlg;

			if (gsdlg.DoModal()==IDOK)
				cliCmdLine.m_csServer = gsdlg.m_csServer;
		}

		if (!cliCmdLine.m_csCmdFile.IsEmpty())
		{
			RunCommandFile(cliCmdLine.m_csCmdFile);
		}
		else if (!cliCmdLine.m_csNamespace.IsEmpty() || !cliCmdLine.m_csServer.IsEmpty())
		{

			CMultiSiteCfgDlg dlg;

			dlg.SetCfgAppOb(m_pCfg);
			dlg.SetNamespace(cliCmdLine.m_csNamespace);
			dlg.SetServer(cliCmdLine.m_csServer);
			m_pMainWnd = &dlg;

			try
			{
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
			}
			catch(...)
			{
			}
		}

	}
	

	CoUninitialize();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

////////////////////////////////////////////////////////////////////////////////////
// this function implements running the application silently from a command file
// it takes commands from the csCmdFile, validates the settings, and performs the transfer
void CMultiSiteCfgApp::RunCommandFile(const CString& csCmdFile)
{
	CCfgCmdFile cmdFile;

	if (cmdFile.LoadSettings(csCmdFile))
	{
	  try
	  {
		 bstrVector vsSites, vsSitesToCopy;
		 bstrVector vsConfigs, vsConfigsToCopy;

		 // connect to server
	    _bstr_t sNamespace = (LPCTSTR)m_pCfg->GetProvNamespaceForServer(_bstr_t(cmdFile.GetSiteServer()));
		m_pCfg->Connect(sNamespace);

		_bstr_t sSrcSite = _bstr_t(cmdFile.GetSourceSite());

		// get available sites
	    m_pCfg->GetSiteCodes(vsSites);

		// make sure our source site is one of them
		if (std::find(vsSites.begin(),vsSites.end(),sSrcSite)!=vsSites.end())
		{
			CStringArray csaDstSites;

			// get sites we have write access to
			vsSites.clear();
			m_pCfg->GetSiteCodes(vsSites,true);


			// get saved dst sites
			cmdFile.GetDestSites(csaDstSites);

			// find which ones exist
			for (int i=0; i < csaDstSites.GetSize(); i++)
			{
				_bstr_t sDstSite = _bstr_t(csaDstSites[i]);

				if (std::find(vsSites.begin(),vsSites.end(),sDstSite)!=vsSites.end())
					vsSitesToCopy.push_back(sDstSite);
			}

			// get available configs
			m_pCfg->SetSiteAndGetAvailConfigs(sSrcSite,vsConfigs);

			CStringArray csaSettings;
			// get saved configs
			cmdFile.GetSettings(csaSettings);

			// find which ones exist
			for (i=0; i < csaSettings.GetSize(); i++)
			{
				_bstr_t sSetting = _bstr_t(csaSettings[i]);

				if (std::find(vsConfigs.begin(),vsConfigs.end(),sSetting)!=vsConfigs.end())
					vsConfigsToCopy.push_back(sSetting);
			}

			CString csMsg;

			csMsg.LoadString(IDS_STAT_CYCLE_BEGIN);
			m_pCfg->RaiseStatusMessage(_bstr_t(csMsg + csCmdFile),
			SMS_StatusMessage::MessageType::ENUM_Milestone,SMS_StatusMessage::Severity::ENUM_Informational);

			m_pCfg->TransferSettings(vsConfigsToCopy,vsSitesToCopy);

			csMsg.LoadString(IDS_STAT_CYCLE_OK);
			m_pCfg->RaiseStatusMessage(_bstr_t(csMsg + csCmdFile),
			SMS_StatusMessage::MessageType::ENUM_Milestone,SMS_StatusMessage::Severity::ENUM_Informational);

		}
		/* else source site doesn't exist */
	}
	catch (CWbemException e)
	{
		CString csMsg,csMsg2;
		m_pCfg->SetProgressCallback(NULL);

		try
		{
		}
		catch(...)
		{			
		}

		csMsg.LoadString(IDS_STAT_CYCLE_ERROR);		
		csMsg2.Format(csMsg, (LPCTSTR)e.GetDescription());
		m_pCfg->RaiseStatusMessage(_bstr_t(csMsg),
			SMS_StatusMessage::MessageType::ENUM_Milestone,SMS_StatusMessage::Severity::ENUM_Error);

		}
	}
	/* else can't find file */
}

void CThisAppCommandLineInfo::ParseParam( LPCTSTR lpszParam, BOOL bFlag, BOOL bLast )
{
	CString csParam(lpszParam);
   int iEq = csParam.Find('=');

	if (iEq > 0 && csParam.Left(iEq).CompareNoCase("Namespace")==0)
	{
		m_csNamespace = csParam.Mid(iEq+1);
	}
	else if (iEq > 0 && csParam.Left(iEq).CompareNoCase("Server")==0)
	{
		m_csServer = csParam.Mid(iEq+1);
	}
	else if (iEq > 0 && csParam.Left(iEq).CompareNoCase("CmdFile")==0)
	{
		m_csCmdFile = csParam.Mid(iEq+1);
	}
	else
		CCommandLineInfo::ParseParam(lpszParam,bFlag,bLast);
}

