/**********************************************************************/
/*                                                                    */
/*      DLGS.C                                                        */
/*                                                                    */
/*      Copyright (c) 1995 - 2000  Microsoft Corporation                     */
/*                                                                    */
/**********************************************************************/

#include "windows.h"
#include "imm.h"
#include "resource.h"
#include "multiui.h"

/**********************************************************************/
/*                                                                    */
/*    About(HWND, UINT, WPARAM, LPARAM)                               */
/*                                                                    */
/**********************************************************************/
BOOL AboutDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
        case WM_INITDIALOG:
            return (TRUE);

        case WM_COMMAND:
            if (wParam == IDOK
                || wParam == IDCANCEL) {
                EndDialog(hDlg, TRUE);
                return (TRUE);
            }
            break;
    }
    return (FALSE);
}

