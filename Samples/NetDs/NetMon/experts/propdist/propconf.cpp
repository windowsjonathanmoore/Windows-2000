//=============================================================================
//  Microsoft (R) Network Monitor (tm). 
//  Copyright (C) 1997 - 2000. All rights reserved.
//
//  MODULE: PropConf.cpp
//
//  Handles the dialog for configuring the Property Distribution Expert
//=============================================================================

#include <windows.h>
#include <windowsx.h>   // requred for message crackers and macro api's
#include <stdio.h>      // for sprintf
#include <netmon.h>
#include "Dialogs.h"
#include "PropDist.h"


//////////////////////////////////////////////////////////////////////////////
// Global Variables

typedef struct _SubClass
{
    WNDPROC     lpfnOrigWndProc;
    HWND        hwnd;
} SUBCLASS;
typedef SUBCLASS *PSUBCLASS;

HEXPERTKEY        g_hExpertKey;
PPROPDISTCONFIG * g_ppPropDistConfig;
HCAPTURE          g_hCapture;

//////////////////////////////////////////////////////////////////////////////
// Forward Declarations
BOOL CALLBACK ConfigPropDistDlg_DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// input handlers
BOOL ConfigPropDistDlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void ConfigPropDistDlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void ConfigPropDistDlg_OnOKButton( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void ConfigPropDistDlg_OnCancelButton( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void ConfigPropDistDlg_OnProtocolBox( HWND hwnd, int id, HWND hwndProtocol, UINT codeNotify);
void ConfigPropDistDlg_OnPropertyBox( HWND hwnd, int id, HWND hwndProperty, UINT codeNotify);
void ConfigPropDistDlg_OnHelpButton( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

// box interaction helpers
void PropertyBoxRefill( HWND hwnd, HPROTOCOL hProtocol);
void ActivateBitNumber( HWND hwnd, HPROPERTY hProperty);

// Bit number subclass helpers
void SubclassBitNumber(HWND hwndBitNumber);
LRESULT CALLBACK BitNumberWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_Do
BOOL ConfigPropDistDlg_Do(HWND hwnd, 
                          PPROPDISTCONFIG *ppPropDistConfig, 
                          HCAPTURE hCapture, 
                          HEXPERTKEY hExpertKey)
{
    // save the current struture
    g_hExpertKey = hExpertKey;
    g_ppPropDistConfig = ppPropDistConfig;
    g_hCapture = hCapture;

    // create the dialog box...
    return DialogBox( g_hInstance, 
                      MAKEINTRESOURCE(IDD_PropDistConfig), 
                      hwnd, 
                      (DLGPROC)ConfigPropDistDlg_DlgProc);
}

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_DlgProc
BOOL CALLBACK ConfigPropDistDlg_DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        HANDLE_MSG(hwnd,    WM_INITDIALOG,      ConfigPropDistDlg_OnInitDialog);
        HANDLE_MSG(hwnd,    WM_COMMAND,         ConfigPropDistDlg_OnCommand);

        // this makes the F1 key act like the Help key
        case WM_HELP:
            ConfigPropDistDlg_OnHelpButton(hwnd, ID_HELP, NULL, 0);
            break;
    }
    return(FALSE);
}

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnInitDialog
BOOL ConfigPropDistDlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    LPPROTOCOLTABLE pProtocolTable;
    DWORD i;
    DWORD nCurSel;
    BOOL fProtocolSet = FALSE;
    LPPROTOCOLINFO pProtocolInfo;
    char BitNumberTemp[MAX_PATH];

    HWND hwndProtocol = GetDlgItem(hwnd, IDE_Protocol);
    HWND hwndProperty = GetDlgItem(hwnd, IDE_Property);
    HWND hwndPropertyLabel = GetDlgItem(hwnd, IDL_Property);
    HWND hwndBitNumber= GetDlgItem(hwnd, IDE_BitNumber);

    // get the protocols
    pProtocolTable = GetEnabledProtocols( g_hCapture );
    if( pProtocolTable == NULL )
    {
        return FALSE;
    }

    // prefill the protocol box with protocols...
    for( i = 0; i < pProtocolTable->nProtocols; i++)
    {
        // get this protocol's info
        pProtocolInfo = GetProtocolInfo(pProtocolTable->hProtocol[i]);
        if( pProtocolInfo == NULL )
        {
            return FALSE;
        }

        // add this protocol
        nCurSel = ComboBox_AddString(hwndProtocol, pProtocolInfo->ProtocolName);
        ComboBox_SetItemData(hwndProtocol, nCurSel, pProtocolTable->hProtocol[i] );
    }

    // make sure that only numbers can be entered in the bit number box
    SubclassBitNumber( hwndBitNumber );

    // now select the passed in configuration variables
    if( (*g_ppPropDistConfig) != NULL )
    {
        // we did get a configuration...
        // set the protocol
        nCurSel = ComboBox_FindString( hwndProtocol, 0,
                                       (*g_ppPropDistConfig)->szProtocolName);
        if( nCurSel == CB_ERR )
        {
            // could not find the protocol
            // TODO: should this be a failure case?
            return TRUE;
        }
        ComboBox_SetCurSel( hwndProtocol, nCurSel );

        // fill in the properties
        PropertyBoxRefill( hwnd, 
                      (HPROTOCOL)ComboBox_GetItemData( hwndProtocol, nCurSel));

        // set the property
        nCurSel = ComboBox_FindString( hwndProperty, 0,
                                       (*g_ppPropDistConfig)->szPropertyName);
        if( nCurSel == CB_ERR )
        {
            // could not find the property
            // TODO: should this be a failure case?
            return TRUE;
        }
        ComboBox_SetCurSel( hwndProperty, nCurSel);

        // do we need to enable the bit number edit control
        ActivateBitNumber( hwnd, (HPROPERTY)ComboBox_GetItemData(hwndProperty, 
                                                                 nCurSel));

        // fill in the bit number
        if( (*g_ppPropDistConfig)->fBitNumberSet &&
            IsWindowEnabled( hwndBitNumber) != FALSE )
        {
            sprintf( BitNumberTemp, "%d", 
                     (*g_ppPropDistConfig)->nBitNumber );
            Edit_SetText( hwndBitNumber, BitNumberTemp );
        }
    }
    else
    {
        // no configuration was passed, gray out the property box
        EnableWindow( hwndProperty, FALSE );
        EnableWindow( hwndPropertyLabel, FALSE );
    }

    return TRUE;
}

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnCommand
void ConfigPropDistDlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        // OK Button has been hit...
        case IDOK:
            ConfigPropDistDlg_OnOKButton(hwnd, id, hwndCtl, codeNotify);
            break;

        // Cancel button has been hit
        case IDCANCEL:
            ConfigPropDistDlg_OnCancelButton(hwnd, id, hwndCtl, codeNotify);
            break;

        // something happened in the Protocol Box
        case IDE_Protocol:
            ConfigPropDistDlg_OnProtocolBox(hwnd, id, hwndCtl, codeNotify);
            break;

        // something happened in the Property Box
        case IDE_Property:
            ConfigPropDistDlg_OnPropertyBox(hwnd, id, hwndCtl, codeNotify);
            break;

        case ID_HELP:
            ConfigPropDistDlg_OnHelpButton(hwnd, id, hwndCtl, codeNotify);
            break;
    }
}

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnOKButton
void ConfigPropDistDlg_OnOKButton( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    DWORD nCurSelProtocol;
    DWORD nCurSelProperty;
    BYTE  BitNumber = 0;
    BOOL  fBitNumberSet = FALSE;
    DWORD PropertyNameLength = 0;
    DWORD BufferSize;
    HPROPERTY hProperty;
    LPPROPERTYINFO pPropertyInfo;
    char szBitNumberTemp[MAX_PATH];
    char Msg[MAX_PATH];
    char String[MAX_PATH];

    HWND hwndProtocol = GetDlgItem(hwnd, IDE_Protocol);
    HWND hwndProperty = GetDlgItem(hwnd, IDE_Property);
    HWND hwndBitNumber= GetDlgItem(hwnd, IDE_BitNumber);

    LoadString(g_hInstance, IDS_PROPDISTTITLE, Msg, MAX_PATH);

    // validate the protocol -------------------------------------------------
    nCurSelProtocol = ComboBox_GetCurSel( hwndProtocol );
    if( nCurSelProtocol == CB_ERR )
    {
        // tell them that we need a protocol
        LoadString(g_hInstance, IDS_MUSTSELECTPROTOCOL, String, MAX_PATH);
        MessageBox(hwnd, String, Msg, MB_OK);
        return;
    }

    // validate the property -------------------------------------------------
    try
    {
        nCurSelProperty = ComboBox_GetCurSel( hwndProperty );
        if( nCurSelProperty == CB_ERR )
        {
            // there is no current selection
            throw 1;
        }

        // do we need a bit number
        hProperty = ComboBox_GetItemData( hwndProperty, nCurSelProperty);
        if( hProperty == NULL )
        {
            // there is no HPROTOCOL
            throw 1;
        }
        pPropertyInfo = GetPropertyInfo( hProperty );
        if( pPropertyInfo == NULL )
        {
            // there was not property info
            throw 1;
        }
    }
    catch(...)
    {
        // tell them that we need a protocol
        LoadString(g_hInstance, IDS_MUSTSELECTPROTOCOL, String, MAX_PATH);
        MessageBox(hwnd, String, Msg, MB_OK);
        return;
    }

    // do we need a bit number -----------------------------------------------
    if( pPropertyInfo->DataQualifier == PROP_QUAL_FLAGS )
    {
        // yes we need one
        if( Edit_GetText( hwndBitNumber, szBitNumberTemp, MAX_PATH) == NULL )
        {
            // tell them that we need a protocol
            LoadString(g_hInstance, IDS_MUSTENTERBITNUM, String, MAX_PATH);
            MessageBox(hwnd, String, Msg, MB_OK);
            return;
        }

        // convert this into a number
        // NOTE: this should not fault as we have validated each digit
        sscanf( szBitNumberTemp, "%d", &BitNumber );
        fBitNumberSet = TRUE;
    }

    // We have enough valid data to return, Size the buffer ------------------
    // what size buffer do we need?
    PropertyNameLength = ComboBox_GetTextLength(hwndProperty) + 1;
    BufferSize = sizeof( PROPDISTCONFIG ) + PropertyNameLength;
    if( SizeConfigBuffer( g_hExpertKey, g_ppPropDistConfig, BufferSize ) == FALSE )
    {
        // we could not grow the config...
        EndDialog( hwnd, FALSE );
    }


    // fill in the Config ----------------------------------------------------
    (*g_ppPropDistConfig)->nTotalLength =  BufferSize;
    (*g_ppPropDistConfig)->fBitNumberSet = fBitNumberSet;
    (*g_ppPropDistConfig)->nBitNumber =    BitNumber; 
    ComboBox_GetText( hwndProtocol, 
                      (*g_ppPropDistConfig)->szProtocolName,
                      16);
    ComboBox_GetText( hwndProperty, 
                      (*g_ppPropDistConfig)->szPropertyName,
                      PropertyNameLength);

    // we are done
    EndDialog(hwnd, TRUE);
}

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnCancelButton
void ConfigPropDistDlg_OnCancelButton( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{   
    EndDialog(hwnd, FALSE);
}

//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnProtocolBox
void ConfigPropDistDlg_OnProtocolBox( HWND hwnd, int id, HWND hwndProtocol, UINT codeNotify)
{   
    DWORD nCurSel;

    // unless this is a selection change, we don't care
    if( codeNotify != CBN_SELCHANGE )
        return;

    // the selection has changed, we need to refill the property box
    nCurSel = ComboBox_GetCurSel( hwndProtocol);
    if( nCurSel != CB_ERR )
    {
        // refill it
        PropertyBoxRefill( hwnd, 
                           (HPROTOCOL)ComboBox_GetItemData( hwndProtocol, nCurSel ));
    }
}
                                
//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnHelpButton()
void ConfigPropDistDlg_OnHelpButton( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    // TODO - Respond to the help message
}

//////////////////////////////////////////////////////////////////////////////
// PropertyBoxRefill
void PropertyBoxRefill( HWND hwnd, HPROTOCOL hProtocol)
{
    LPPROTOCOLINFO pProtocolInfo;
    HPROPERTY hProperty;
    LPPROPERTYINFO pPropertyInfo;
    DWORD i;
    DWORD nCurSel;

    HWND hwndProperty = GetDlgItem(hwnd, IDE_Property);
    HWND hwndPropertyLabel = GetDlgItem(hwnd, IDL_Property);

    // activate the box
    EnableWindow( hwndProperty, TRUE );
    EnableWindow( hwndPropertyLabel, TRUE );

    // get our list of properties
    pProtocolInfo = GetProtocolInfo( hProtocol );
    if( pProtocolInfo == NULL )
    {
        return;
    }

    // clear out the ComboBox
    ComboBox_ResetContent( hwndProperty );
    
    // fill in the box
    for( i = 0; 
         i < (int)pProtocolInfo->PropertyDatabase->nProperties; 
         i++ )
    {
        // get a handle to this property
        hProperty = 
            pProtocolInfo->PropertyDatabase->PropertyInfo[i]->hProperty;
        if( hProperty == NULL )
        {
            return;
        }

        // get the name of this property
        pPropertyInfo = GetPropertyInfo(hProperty);
        if( pPropertyInfo == NULL )
        {
            return;
        }

        // insert the data structure into the list
        nCurSel = ComboBox_AddString(hwndProperty, pPropertyInfo->Label);
        ComboBox_SetItemData(hwndProperty, nCurSel, hProperty);
    }

    // ungray the protocol box
    EnableWindow( hwndProperty, TRUE );
    EnableWindow( hwndPropertyLabel, TRUE );

    // clear out the Bit Number
    ActivateBitNumber( hwnd, NULL);
}

//////////////////////////////////////////////////////////////////////////////
// PropertyBoxRefill
void ActivateBitNumber( HWND hwnd, HPROPERTY hProperty)
{
    LPPROPERTYINFO pPropertyInfo;
    HWND hwndBitNumber = GetDlgItem(hwnd, IDE_BitNumber);
    HWND hwndBitNumberLabel = GetDlgItem( hwnd, IDL_BitNumber);

    // get the info for this property
    pPropertyInfo = GetPropertyInfo( hProperty);
    if( pPropertyInfo == NULL )
    {
        Edit_SetText( hwndBitNumber, "");
        EnableWindow( hwndBitNumber, FALSE );
        return;
    }

    // should the Bit Number box be open
    if( pPropertyInfo->DataQualifier == PROP_QUAL_FLAGS )
    {
        // yes it should
        EnableWindow( hwndBitNumber, TRUE );
        EnableWindow( hwndBitNumberLabel, TRUE );
    }
    else
    {
        // no it should not
        Edit_SetText( hwndBitNumber, "");
        EnableWindow( hwndBitNumber, FALSE );
        EnableWindow( hwndBitNumberLabel, FALSE );
    }
}




//////////////////////////////////////////////////////////////////////////////
// ConfigPropDistDlg_OnPropertyBox
void ConfigPropDistDlg_OnPropertyBox( HWND hwnd, int id, HWND hwndProperty, UINT codeNotify)
{   
    DWORD nCurSel;

    // unless this is a selection change, we don't care
    if( codeNotify != CBN_SELCHANGE )
        return;

    // the selection has changed, we need to Selectively reactiveate the Bit Number
    nCurSel = ComboBox_GetCurSel( hwndProperty);
    if( nCurSel != CB_ERR )
    {
        // Activate it
        ActivateBitNumber( hwnd, 
                           (HPROPERTY)ComboBox_GetItemData( hwndProperty, nCurSel ));
    }
}
                                

//////////////////////////////////////////////////////////////////////////////
// SubclassBitNumber
void SubclassBitNumber(HWND hwndBitNumber)
{
    PSUBCLASS pSubClass;
    DWORD rc;

    // allocate our subclass structure
    pSubClass = (PSUBCLASS)ExpertAllocMemory(g_hExpertKey,
                                             sizeof(SUBCLASS),
                                             &rc);

    //  init structure and subclass window class
    pSubClass->hwnd = hwndBitNumber;
    pSubClass->lpfnOrigWndProc = SubclassWindow(hwndBitNumber, BitNumberWndProc);

    // store the editmask struct in the GWL_USERDATA spot
    SetWindowLong(hwndBitNumber, GWL_USERDATA, (DWORD)pSubClass);
}

//////////////////////////////////////////////////////////////////////////////
// BitNumberWndProc
LRESULT CALLBACK BitNumberWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    PSUBCLASS pSubClass;
    LRESULT Result;

    // get our instance data
    pSubClass = (PSUBCLASS)GetWindowLong(hwnd, GWL_USERDATA);

    switch (msg)
    {
        case WM_CHAR:
             // backspaces are OK
            if( ((CHAR)wParam) == VK_BACK )
            {
                break;
            }

            // numbers are OK
            if( ((CHAR)wParam) >= '0' &&
                ((CHAR)wParam) <= '9' )
            {
                break;
            }

            // we got to here, that means that this is not a legal character
            FlashWindow(hwnd, TRUE);
            FlashWindow(hwnd, FALSE);
            return(0); // swallow it

        case WM_DESTROY:
            // restore original wndproc
            SubclassWindow(hwnd, pSubClass->lpfnOrigWndProc);
#ifdef _WIN32_IE        // VC6 hack
            Result = CallWindowProc(pSubClass->lpfnOrigWndProc, hwnd, msg, wParam, lParam);
#else
            Result = CallWindowProc((FARPROC)pSubClass->lpfnOrigWndProc, hwnd, msg, wParam, lParam);
#endif
            ExpertFreeMemory( g_hExpertKey, pSubClass);
            return Result;

    } /* end switch */

    // pass message on through to original window proc
#ifdef _WIN32_IE        // VC6 hack
    return CallWindowProc(pSubClass->lpfnOrigWndProc, hwnd, msg, wParam, lParam);
#else
    return CallWindowProc((FARPROC)pSubClass->lpfnOrigWndProc, hwnd, msg, wParam, lParam);
#endif
}

////////////////////////////////////////////////////////////////////////////////////////
// SizeConfigBuffer
BOOL SizeConfigBuffer( HEXPERTKEY hExpertKey, 
                       PPROPDISTCONFIG *ppPropDistConfig,
                       DWORD BufferSize )
{
    DWORD rc;
    PPROPDISTCONFIG TempConfig;

    // do we have a config buffer?
    if( *ppPropDistConfig == NULL )
    {
        // no, allocate one
        *ppPropDistConfig = (PPROPDISTCONFIG)ExpertAllocMemory( 
                                    hExpertKey,
                                    BufferSize,
                                    &rc);
        if( *ppPropDistConfig == NULL )
        {
            return FALSE;
        }
    }
    else
    {
        // is the given buffer big enough
        if( (*ppPropDistConfig)->nTotalLength < BufferSize )
        {

            // no, we must grow it
            TempConfig = (PPROPDISTCONFIG)ExpertReallocMemory( 
                                    hExpertKey,
                                    *ppPropDistConfig,
                                    BufferSize,
                                    &rc);
            if( TempConfig == NULL )
            {
                return FALSE;
            }

            // it worked
            *ppPropDistConfig = TempConfig;
        }
    }

    return TRUE;
}

