#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <winsock.h>
#include <winbase.h>
#include <ctype.h>
#include <ras.h>
#include <mprapi.h>
#include <raserror.h>
#include <tchar.h>

					 
#define SUCCESS 0
#define FAILURE -1

RASENTRY rasEntry;
void Usage();

VOID __cdecl main (argc, argv)
int argc;
TCHAR * argv[];
{
	
	DWORD dwErr = 0;
    TCHAR szEntryName[RAS_MaxEntryName + 1];
    TCHAR szPhoneNumber[RAS_MaxPhoneNumber + 1];

     if (argc != 3) {
        Usage();
        return;
     }

    // 1st argument is entryName and 2nd is phone number
     
    lstrcpy(szEntryName,argv[1]);
    lstrcpy(szPhoneNumber,argv[2]);


    // Set all the simple options and call the RasSetEntryProperties.

     rasEntry.dwSize = sizeof(RASENTRY);
     rasEntry.dwfOptions = 0;
     rasEntry.dwfOptions = RASEO_PreviewPhoneNumber | RASEO_ShowDialingProgress | RASEO_PreviewUserPw | RASEO_PreviewDomain;
     rasEntry.dwfOptions |= RASEO_CustomScript;
     lstrcpy(rasEntry.szLocalPhoneNumber,szPhoneNumber);
     
     rasEntry.dwfNetProtocols = RASNP_Ip | RASNP_Ipx | RASNP_NetBEUI; 

     lstrcpy(rasEntry.szDeviceType,RASDT_Modem);
     rasEntry.dwSubEntries = 1; 
  
     rasEntry.dwType =  RASET_Phone;
     rasEntry.dwEncryptionType = ET_None; 


     dwErr = RasSetEntryProperties( NULL,
                                    szEntryName,
                                    &rasEntry,
                                    sizeof(RASENTRY),
                                    NULL,
                                    0);


     if (dwErr == 0) {
       _tprintf(_T("Successfully created the custom entry %s \n"),szEntryName);
       _tprintf(_T("Dial Using this entry after registering the custom.dll \n"));
     }
     else 
       _tprintf(_T("Failed to Create the entry Error = %d  \n"),dwErr);

     return;

}

void Usage()
{
printf("Usage : customentry <EntryName> <PhoneNumber> \n");   
return;
}


