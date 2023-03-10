/**********************************************************************/
/*                                                                    */
/*      MULTIWND.C                                                    */
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
/*    InitStringBuffer(HWND)                                          */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL InitStringBuffer(HWND hWnd)
{
    LPSTR lpStr = NULL;

    if (lpStr = GlobalAlloc(GPTR,MAXSIZE_STR))
    {
        SetWindowLongPtr(hWnd,MYGWL_LPSTR,(LONG_PTR)lpStr);
    }
    else
    {
        SetWindowLongPtr(hWnd,MYGWL_LPSTR,(LONG_PTR)0L);
    }
}

/**********************************************************************/
/*                                                                    */
/*    DestroyStringBuffer(HWND)                                       */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL DestroyStringBuffer(HWND hWnd)
{
    LPSTR lpStr = NULL;

    lpStr = (LPSTR)GetWindowLongPtr(hWnd,MYGWL_LPSTR);
    if (lpStr)
    {
        GlobalFree((HANDLE)lpStr);
    }
}

/**********************************************************************/
/*                                                                    */
/*    MyDrawString(HWND,WPARAM,LPARAM)                                */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL MyDrawString(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
    LPSTR lpStr = NULL;
    HDC   hDC;
    PAINTSTRUCT ps;
    HFONT hOldFont;
    HFONT hFont;
    DWORD dwHeight;
    TEXTMETRIC      tm;
    RECT rc;

    lpStr = (LPSTR)GetWindowLongPtr(hWnd,MYGWL_LPSTR);
    if (!lpStr)
        return;

    hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
    if (!hFont)
        return;


    hDC = BeginPaint(hWnd, &ps);
    hOldFont = SelectObject(hDC, hFont);

    lpStr = (LPSTR)GetWindowLongPtr(hWnd,MYGWL_LPSTR);
    // Get dwHeight.
    GetTextMetrics(hDC,&tm);
    dwHeight = tm.tmHeight + tm.tmExternalLeading;


    GetClientRect(hWnd,&rc);
    rc.bottom -= dwHeight;

    DrawText(hDC,lpStr,-1,&rc,DT_LEFT | DT_WORDBREAK);

    SelectObject(hDC, hOldFont);
    EndPaint(hWnd, &ps);
}

/**********************************************************************/
/*                                                                    */
/*    MySetCompositionFont(HWND)                                      */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL MySetCompositionFont(HWND hWnd)
{
    HIMC hIMC;

    if (hIMC = ImmGetContext(hWnd))
    {
        LOGFONT lf;
        HFONT   hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
        GetObject(hFont,sizeof(lf),&lf);

        ImmSetCompositionFont(hIMC,&lf);
        ImmReleaseContext(hWnd, hIMC);
    }
}

/**********************************************************************/
/*                                                                    */
/*    MySetCompositionForm(HWND)                                      */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL MySetCompositionForm(HWND hWnd)
{
    RECT            rc;
    HIMC            hIMC;
    HDC             hDC;
    TEXTMETRIC      tm;
    DWORD           dwHeight;
    HFONT           hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
    HFONT           hOldFont;
    COMPOSITIONFORM CompForm;

    if (!hFont)
        return;

    if (hIMC = ImmGetContext(hWnd))
    {
        // Get dwHeight.
        hDC = GetDC(hWnd);
        hOldFont = SelectObject(hDC, hFont);
        GetTextMetrics(hDC,&tm);
        dwHeight = tm.tmHeight + tm.tmExternalLeading;
        SelectObject(hDC, hOldFont);
        ReleaseDC(hWnd,hDC);


        GetClientRect(hWnd,&rc);
        CompForm.dwStyle = CFS_POINT;
        CompForm.ptCurrentPos.x = rc.left;
        CompForm.ptCurrentPos.y = rc.bottom - dwHeight;
        ImmSetCompositionWindow(hIMC,&CompForm);

        ImmReleaseContext(hWnd, hIMC);
    }
}

/**********************************************************************/
/*                                                                    */
/*    MyChangeFont(HWND)                                              */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL MyChangeFont(HWND hWnd)
{
    LOGFONT lf;
    CHOOSEFONT cf;
    HFONT hFont;

    /* Set all structure fields to zero. */
    memset(&cf, 0, sizeof(CHOOSEFONT));

    cf.lStructSize = sizeof(CHOOSEFONT);
    cf.hwndOwner = hWnd;
    cf.lpLogFont = &lf;
    cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
    cf.rgbColors = RGB(0, 255, 255); /* light blue */
    cf.nFontType = SCREEN_FONTTYPE;

    if (ChooseFont(&cf))
    {
        hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
        DeleteObject(hFont);

        hFont = CreateFontIndirect(&lf);
        SetWindowLongPtr(hWnd,MYGWL_FONT,(LONG_PTR)hFont);
        MySetCompositionForm(hWnd);
        MySetCompositionFont(hWnd);
    }
    SetFocus(hWnd);
}

/**********************************************************************/
/*                                                                    */
/*    GetDefaultGUIFont(void)                                         */
/*                                                                    */
/**********************************************************************/
HFONT GetDefaultGUIFont(void)
{
    static HFONT hFont;
    OSVERSIONINFO VerInfo;

    if (hFont)
        return hFont;

    VerInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&VerInfo);

    if (VerInfo.dwMajorVersion < 4) {
        NONCLIENTMETRICS ncm;

        ncm.cbSize = sizeof(NONCLIENTMETRICS);
        SystemParametersInfo(SPI_GETNONCLIENTMETRICS, sizeof(ncm), &ncm, 0);
        hFont = CreateFontIndirect(&ncm.lfStatusFont);

        if (!hFont)
            hFont = GetStockObject(SYSTEM_FONT);
    } else {
        hFont = GetStockObject(DEFAULT_GUI_FONT);
    }

    return hFont;
}

/**********************************************************************/
/*                                                                    */
/*    OverFlowText(HWND,LPSTR,LPSTR)                                  */
/*                                                                    */
/**********************************************************************/
BOOL FAR PASCAL OverFlowText(HWND hWnd,LPSTR lpStr,LPSTR lpResultStr)
{
    BOOL            bRet = FALSE;
    RECT            rc;
    HDC             hDC;
    TEXTMETRIC      tm;
    int             nHeight;
    HFONT           hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
    HFONT           hOldFont;
    LPSTR           lpTemp;

    if (!hFont)
        return FALSE;

    if (lstrlen(lpStr) + lstrlen(lpResultStr) > MAXSIZE_STR)
    {
        bRet = TRUE;

    }
    else
    {
        lpTemp = GlobalAlloc(GPTR,MAXSIZE_STR);

        if (lpTemp)
        {
            lstrcpy(lpTemp,lpStr);
            lstrcat(lpTemp,lpResultStr);

            GetClientRect(hWnd,&rc);

            hDC = GetDC(hWnd);
            hOldFont = SelectObject(hDC, hFont);
            GetTextMetrics(hDC,&tm);

            rc.bottom -= tm.tmHeight + tm.tmExternalLeading;
            nHeight = rc.bottom;

            if (nHeight < DrawText(hDC,lpTemp,-1,&rc,DT_LEFT | DT_WORDBREAK | DT_CALCRECT))
            {
                bRet = TRUE;
            }

            SelectObject(hDC, hOldFont);
            ReleaseDC(hWnd,hDC);

            GlobalFree((HANDLE)lpTemp);
        }
    }


    return bRet;
}

/**********************************************************************/
/*                                                                    */
/*    AddResultString(HWND)                                           */
/*                                                                    */
/**********************************************************************/
void FAR PASCAL AddResultString(HWND hWnd)
{
    HIMC  hIMC;
    DWORD dwLen;
    LPSTR lpStr;
    LPSTR lpResultStr;

    lpStr = (LPSTR)GetWindowLongPtr(hWnd,MYGWL_LPSTR);

    hIMC = ImmGetContext(hWnd);

    if (!hIMC)
        return;

    dwLen = ImmGetCompositionString(hIMC,GCS_RESULTSTR,NULL,0L);

    if (dwLen)
    {
        lpResultStr = GlobalAlloc(GPTR,dwLen+1);

        if (lpResultStr)
        {
            ImmGetCompositionString(hIMC,GCS_RESULTSTR,
                                                  lpResultStr,dwLen+1);

            if (OverFlowText(hWnd,lpStr,lpResultStr))
                lstrcpy(lpStr,lpResultStr);
            else
                lstrcat(lpStr,lpResultStr);

            InvalidateRect(hWnd,NULL,TRUE);

            GlobalFree((HANDLE)lpResultStr);
        }
    }

    ImmReleaseContext(hWnd,hIMC);

}

/**********************************************************************/
/*                                                                    */
/*    NoUINoIMCWndProc(HWND, UINT, WPARAM, LPARAM)                    */
/*                                                                    */
/**********************************************************************/
long FAR PASCAL NoUINoIMCWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HFONT hFont;

    switch (message) 
    {
	case WM_CREATE:
            hFont = GetDefaultGUIFont();
            SetWindowLongPtr(hWnd,MYGWL_FONT,(LONG_PTR)hFont);

            InitStringBuffer(hWnd);

	    break;

        case WM_LBUTTONDBLCLK:
            MyChangeFont(hWnd);
	    break;

        case WM_LBUTTONDOWN:
            SetFocus(hWnd);
	    break;

        case WM_SETFOCUS:
            MySetCompositionFont(hWnd);
            MySetCompositionForm(hWnd);
	    break;

        case WM_IME_COMPOSITION:
            if (lParam & GCS_RESULTSTR)
            {
                AddResultString(hWnd);
            }
	    return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
	    break;

        case WM_SIZE:
            switch (wParam)
            {
                case SIZENORMAL:
                case SIZEFULLSCREEN:
                    if (hWnd == GetFocus())
                    {
                        MySetCompositionForm(hWnd);
                    }
                    InvalidateRect(hWnd,NULL,TRUE);
                    break;


                case SIZEICONIC:
	            return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
                    break;
            }
	    break;


	case WM_PAINT:
            MyDrawString(hWnd,wParam,lParam);
	    break;

	case WM_DESTROY:
            hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
            DeleteObject(hFont);

            DestroyStringBuffer(hWnd);

	    break;

	default:
	    return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0L;

}

/**********************************************************************/
/*                                                                    */
/*    NoUIOwnIMCWndProc(HWND, UINT, WPARAM, LPARAM)                   */
/*                                                                    */
/**********************************************************************/
long FAR PASCAL NoUIOwnIMCWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HIMC hIMC;
    HFONT hFont;

    switch (message) 
    {
	case WM_CREATE:
            hFont = GetDefaultGUIFont();
            SetWindowLongPtr(hWnd,MYGWL_FONT,(LONG_PTR)hFont);

            hIMC = ImmCreateContext();
            ImmAssociateContext(hWnd,hIMC);

            // Save hIMC into WndExtra.
            SetWindowLongPtr(hWnd,MYGWL_IMC,(LONG_PTR)hIMC);

            MySetCompositionFont(hWnd);
            MySetCompositionForm(hWnd);

            InitStringBuffer(hWnd);

	    break;

        case WM_LBUTTONDBLCLK:
            MyChangeFont(hWnd);
	    break;

        case WM_LBUTTONDOWN:
            SetFocus(hWnd);
	    break;

        case WM_IME_COMPOSITION:
            if (lParam & GCS_RESULTSTR)
            {
                AddResultString(hWnd);
            }
	    return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
	    break;

        case WM_SIZE:
            switch (wParam)
            {
                case SIZENORMAL:
                case SIZEFULLSCREEN:
                    MySetCompositionForm(hWnd);
                    InvalidateRect(hWnd,NULL,TRUE);
                    break;

                case SIZEICONIC:
	            return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
                    break;
            }
	    break;

	case WM_PAINT:
            MyDrawString(hWnd,wParam,lParam);
	    break;

	case WM_DESTROY:
            hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
            DeleteObject(hFont);

            hIMC = (HIMC)GetWindowLongPtr(hWnd,MYGWL_IMC);
            ImmDestroyContext(hIMC);

            DestroyStringBuffer(hWnd);

	    break;

	default:
	    return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0L;

}

/**********************************************************************/
/*                                                                    */
/*    OwnUIOwnIMCWndProc(HWND, UINT, WPARAM, LPARAM)                  */
/*                                                                    */
/**********************************************************************/
long FAR PASCAL OwnUIOwnIMCWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HFONT hFont;
    HIMC  hIMC = 0L;
    HWND  hIMEWnd = (HWND)GetWindowLongPtr(hWnd,MYGWL_IMEWND);


    if (IsWindow(hIMEWnd) && ImmIsUIMessage(hIMEWnd,message,wParam,lParam))
    {
        switch (message) 
        {
            case WM_IME_COMPOSITION:
                if (lParam & GCS_RESULTSTR)
                {
                    AddResultString(hWnd);
                }
	        break;

            default:
	        break;
        }

	return 0L;
    }

    switch (message) 
    {
	case WM_CREATE:
            hFont = GetDefaultGUIFont();
            SetWindowLongPtr(hWnd,MYGWL_FONT,(LONG_PTR)hFont);

            hIMC = ImmCreateContext();
            ImmAssociateContext(hWnd,hIMC);

            // Save hIMC into WndExtra.
            SetWindowLongPtr(hWnd,MYGWL_IMC,(LONG_PTR)hIMC);

            if (!(hIMEWnd = CreateWindow("Ime", "",
                    WS_POPUP | WS_DISABLED,
	            0,0,0,0,
	            hWnd, NULL, hInst, NULL)))
	        return -1;

            // Save hIMEWnd into WndExtra.
            SetWindowLongPtr(hWnd,MYGWL_IMEWND,(LONG_PTR)hIMEWnd);

            MySetCompositionFont(hWnd);
            MySetCompositionForm(hWnd);

            InitStringBuffer(hWnd);

	    break;

        case WM_LBUTTONDBLCLK:
            MyChangeFont(hWnd);
	    break;

        case WM_LBUTTONDOWN:
            SetFocus(hWnd);
	    break;

        case WM_SIZE:
            switch (wParam)
            {
                case SIZENORMAL:
                case SIZEFULLSCREEN:
                    MySetCompositionForm(hWnd);
                    InvalidateRect(hWnd,NULL,TRUE);
                    break;

                case SIZEICONIC:
	            return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
                    break;
            }
	    break;

	case WM_PAINT:
            MyDrawString(hWnd,wParam,lParam);
	    break;

	case WM_DESTROY:
            hFont = (HFONT)GetWindowLongPtr(hWnd,MYGWL_FONT);
            DeleteObject(hFont);

            hIMC = (HIMC)GetWindowLongPtr(hWnd,MYGWL_IMC);
            ImmDestroyContext(hIMC);

            DestroyStringBuffer(hWnd);

	    break;

	default:
	    return (LONG)(DefWindowProc(hWnd, message, wParam, lParam));
    }
    return 0L;

}
