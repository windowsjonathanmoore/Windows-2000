// Genset.cpp
#include <windows.h>
#include <tchar.h>
#include <MsiQuery.h>


// Global defines
#define TARGET_PATH                           TEXT("INSTALLDIR1")
#define YES_STRING                            TEXT("YES")
#define NO_STRING                             TEXT("NO")
#define NULL_STRING                           TEXT("")
#define BACK_SLASH_STRING                     TEXT("\\")
#define SERVER_INSTALLED_PROPERTY             TEXT("SERVER_INSTALLED")


// Global instance handle
HINSTANCE  g_hInstance  = NULL;

// Global error strings
TCHAR  szError[MAX_PATH];
TCHAR  szTitle[MAX_PATH];


//====================================================================
// Initialize the DLL
//--------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hInstance, DWORD fdwReason, void*)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		g_hInstance = hInstance;
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
		g_hInstance = 0;

	return TRUE;
};   


extern "C" {

//=========================================================================
// Set Upgrade Path
//-------------------------------------------------------------------------
UINT __stdcall SetHISPath(MSIHANDLE hInstall)
{
	UINT    uMSIError                = ERROR_SUCCESS;
	TCHAR	szInstallDir[MAX_PATH]   = TEXT("");
	DWORD   dReturnCode              = ERROR_SUCCESS;
	HKEY    hKey                     = NULL;
	DWORD   dDataSize                = sizeof(szInstallDir);

	// Open the Parameters Key
	if (ERROR_SUCCESS == RegOpenKeyEx( HKEY_LOCAL_MACHINE,
	                                   TEXT("SOFTWARE\\Microsoft\\Sna Server\\CurrentVersion\\Setup"),
	                                   0,
	                                   KEY_READ,
	                                   &hKey ))
	{
		if (ERROR_SUCCESS == RegQueryValueEx( hKey,
		                                      TEXT("RootDir"),
		                                      NULL,
		                                      NULL,
		                                      (unsigned char *)szInstallDir,
		                                      &dDataSize ))
		{
			lstrcat( szInstallDir,
			         TEXT("\\") );
		}

		// Close the registry handle
		RegCloseKey( hKey );
	}

	// Set the target path
	uMSIError = MsiSetTargetPath( hInstall,
			                      TARGET_PATH,
							      szInstallDir );

	// All finished...
	return ERROR_SUCCESS; //uMSIError;
}



//=========================================================================
// Set Upgrade Path
//-------------------------------------------------------------------------
UINT __stdcall GetHISData(MSIHANDLE hInstall)
{
	UINT    uMSIError                = ERROR_SUCCESS;
	TCHAR   szBuff[32]               = TEXT("");
	BOOL    bServerInstalled         = FALSE;
	DWORD   dReturnCode              = ERROR_SUCCESS;
	HKEY    hKey                     = NULL;
	DWORD   dDataSize                = sizeof(szBuff);

	dDataSize = sizeof(szBuff);


	// Open the Parameters Key
	if (ERROR_SUCCESS == RegOpenKeyEx( HKEY_LOCAL_MACHINE,
	                                   TEXT("SOFTWARE\\Microsoft\\Sna Server\\CurrentVersion\\Setup"),
	                                   0,
	                                   KEY_READ,
	                                   &hKey ))
	{
		if (ERROR_SUCCESS == RegQueryValueEx( hKey,
		                                      TEXT("SetupMode"),
		                                      NULL,
		                                      NULL,
		                                      (unsigned char *)szBuff,
		                                      &dDataSize ))
		{
			if (!lstrcmpi( szBuff,
			               TEXT("HIServer") ))
			{
				bServerInstalled = TRUE;
			}
			else if (!lstrcmpi( szBuff,
			                    TEXT("Server") ))
			{
				bServerInstalled = TRUE;
			}
		}

		// Close the registry handle
		RegCloseKey( hKey );
	}

	// Set the Server Installed Property
	uMSIError = MsiSetProperty( hInstall,
	                            SERVER_INSTALLED_PROPERTY,
                                bServerInstalled ? YES_STRING :
	                                               NO_STRING );

	// All finished...
	return ERROR_SUCCESS; // uMSIError;
}


} // extern "C"
