//---------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation 1991-2000
//
// File   : uxtheme.h
// Version: 1.0
//---------------------------------------------------------------------------
#ifndef _UXTHEME_H_
#define _UXTHEME_H_
//---------------------------------------------------------------------------
#include <commctrl.h>
//---------------------------------------------------------------------------
// #if (_WIN32_WINNT >= 0x0500)     // turn this off until browseui is fixed...
//---------------------------------------------------------------------------

// Define API decoration for direct importing of DLL references.
#ifndef THEMEAPI
#if !defined(_UXTHEME_)
#define THEMEAPI          EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE
#define THEMEAPI_(type)   EXTERN_C DECLSPEC_IMPORT type STDAPICALLTYPE
#else
#define THEMEAPI          STDAPI
#define THEMEAPI_(type)   STDAPI_(type)
#endif
#endif // THEMEAPI

//---------------------------------------------------------------------------
//----- DrawThemeText() flags ----

#define DTT_GRAYED      0x1         // draw a grayed-out string  
//---------------------------------------------------------------------------
//----- HitTestThemeBackground, HitTestThemeBackgroundRegion flags ----

//  Theme background segment hit test flag (default). possible return values are:
//  HTCLIENT: hit test succeeded in the middle background segment
//  HTTOP, HTLEFT, HTTOPLEFT, etc:  // hit test succeeded in the the respective theme background segment.
#define HTTB_BACKGROUNDSEG          0x0000  

//  Fixed border hit test option.  possible return values are:
//  HTCLIENT: hit test succeeded in the middle background segment
//  HTBORDER: hit test succeeded in any other background segment
#define HTTB_FIXEDBORDER            0x0002  // Return code may be either HTCLIENT or HTBORDER. 

//  Caption hit test option.  Possible return values are:
//  HTCAPTION: hit test succeeded in the top, top left, or top right background segments
//  HTNOWHERE or another return code, depending on absence or presence of accompanying flags, resp.
#define HTTB_CAPTION                0x0004  

//  Resizing border hit test flags.  Possible return values are:
//  HTCLIENT: hit test succeeded in middle background segment
//  HTTOP, HTTOPLEFT, HTLEFT, HTRIGHT, etc:    hit test succeeded in the respective system resizing zone
//  HTBORDER: hit test failed in middle segment and resizing zones, but succeeded in a background border segment
#define HTTB_RESIZINGBORDER_LEFT    0x0010  // Hit test left resizing border, 
#define HTTB_RESIZINGBORDER_TOP     0x0020  // Hit test top resizing border
#define HTTB_RESIZINGBORDER_RIGHT   0x0040  // Hit test right resizing border
#define HTTB_RESIZINGBORDER_BOTTOM  0x0080  // Hit test bottom resizing border
#define HTTB_RESIZINGBORDER         (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP|\
                                     HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)

// Resizing border is specified as a template, not just window edges.
#define HTTB_USESIZINGTEMPLATE      0x0100

//---------------------------------------------------------------------------
//---- DrawThemeLine() flags ----

#define DTL_LEFT        0x1
#define DTL_TOP         0x2
#define DTL_RIGHT       0x4
#define DTL_BOTTOM      0x8
//---------------------------------------------------------------------------
typedef HANDLE HTHEME;          // handle to a section of theme data for class

//---------------------------------------------------------------------------
//  IsThemeActive()     - can be used to test if a theme for the current app
//                        is active.  If so, theme-aware windows should call
//                        "OpenThemeData()" to start using theme drawing 
//                        services.  If not, the window doesn't have to 
//                        ask again until it receives a WM_THEMECHANGED msg.
//---------------------------------------------------------------------------
THEMEAPI_(BOOL) IsThemeActive();

//---------------------------------------------------------------------------
//  OpenThemeData()     - Open the theme data for the specified HWND and 
//                        semi-colon separated list of class names. 
// 
//                        OpenThemeData() will try each class name, one at 
//                        a time, and use the first matching theme info
//                        found.  If a match is found, a theme handle
//                        to the data is returned.  If no match is found,
//                        a "NULL" handle is returned. 
//
//                        When the window is destroyed or a WM_THEMECHANGED
//                        msg is received, "CloseThemeData()" should be 
//                        called to close the theme handle.
//
//  hwnd                - window handle of the control/window to be themed
//
//  pszClassList        - class name (or list of names) to match to theme data
//                        section.  if the list contains more than one name, 
//                        the names are tested one at a time for a match.  
//                        If a match is found, OpenThemeData() returns a 
//                        theme handle associated with the matching class. 
//                        This param is a list (instead of just a single 
//                        class name) to provide the class an opportunity 
//                        to get the "best" match between the class and 
//                        the current theme.  For example, a button might
//                        pass L"OkButton, Button" if its ID=ID_OK.  If 
//                        the current theme has an entry for OkButton, 
//                        that will be used.  Otherwise, we fall back on 
//                        the normal Button entry.
//---------------------------------------------------------------------------
THEMEAPI_(HTHEME) OpenThemeData(HWND hwnd, LPCWSTR pszClassList);

//---------------------------------------------------------------------------
//  CloseTHemeData()    - closes the theme data handle.  This should be done 
//                        when the window being themed is destroyed or
//                        whenever a WM_THEMECHANGED msg is received 
//                        (followed by an attempt to create a new Theme data 
//                        handle).
//
//  hTheme              - open theme data handle (returned from prior call
//                        to OpenThemeData() API).
//---------------------------------------------------------------------------
THEMEAPI CloseThemeData(HTHEME hTheme);

//---------------------------------------------------------------------------
//    functions for basic drawing support 
//---------------------------------------------------------------------------
// The following methods are the theme-aware drawing services.
// Controls/Windows are defined in drawable "parts" by their author: a 
// parent part and 0 or more child parts.  Each of the parts can be 
// described in "states" (ex: disabled, hot, pressed).  
//---------------------------------------------------------------------------
// For the list of all themed classes and the definition of all
// parts and states, see the file "tmschmea.h".
//---------------------------------------------------------------------------
// Each of the below methods takes a "iPartId" param to specify the 
// part and a "iStateId" to specify the state of the part.  
// "iStateId=0" refers to the root part.  "iPartId" = "0" refers to 
// the root class.  
//-----------------------------------------------------------------------
// Note: draw operations are always scaled to fit (and not to exceed)  
// the specified "Rect".
//-----------------------------------------------------------------------

//------------------------------------------------------------------------
//  DrawThemeBackground()   
//                      - draws the theme-specified border and fill for 
//                        the "iPartId" and "iStateId".  This could be 
//                        based on a bitmap file, a border and fill, or 
//                        other image description.  
//
//  hTheme              - theme data handle
//  hdc                 - HDC to draw into
//  iPartId             - part number to draw
//  iStateId            - state number (of the part) to draw
//  pRect               - defines the size/location of the part
//  pClipRect           - optional clipping rect (don't draw outside it)
//------------------------------------------------------------------------
THEMEAPI DrawThemeBackground(HTHEME hTheme, HDC hdc, 
    int iPartId, int iStateId, const RECT *pRect, OPTIONAL const RECT *pClipRect);

//-------------------------------------------------------------------------
//  DrawThemeText()     - draws the text using the theme-specified 
//                        color and font for the "iPartId" and 
//                        "iStateId".  
//
//  hTheme              - theme data handle
//  hdc                 - HDC to draw into
//  iPartId             - part number to draw
//  iStateId            - state number (of the part) to draw
//  pszText             - actual text to draw
//  dwCharCount         - number of chars to draw (-1 for all)
//  dwTextFlags         - same as DrawText() "uFormat" param
//  dwTextFlags2        - additional drawing options 
//  pRect               - defines the size/location of the part
//-------------------------------------------------------------------------
THEMEAPI DrawThemeText(HTHEME hTheme, HDC hdc, int iPartId, 
    int iStateId, LPCWSTR pszText, int iCharCount, DWORD dwTextFlags, 
    DWORD dwTextFlags2, const RECT *pRect);

//-------------------------------------------------------------------------
//  GetThemeBackgroundContentRect()
//                      - gets the size of the content for the theme-defined 
//                        background.  This is usually the area inside
//                        the borders or Margins.  
//
//      hTheme          - theme data handle
//      hdc             - (optional) device content to be used for drawing
//      iPartId         - part number to draw
//      iStateId        - state number (of the part) to draw
//      pBoundingRect   - the outer RECT of the part being drawn
//      pContentRect    - RECT to receive the content area
//-------------------------------------------------------------------------
THEMEAPI GetThemeBackgroundContentRect(HTHEME hTheme, OPTIONAL HDC hdc, 
    int iPartId, int iStateId,  const RECT *pBoundingRect, 
    OUT RECT *pContentRect);

//-------------------------------------------------------------------------
//  GetThemeBackgroundExtent() - calculates the size/location of the theme-
//                               specified background based on the 
//                               "pContentRect".
//
//      hTheme          - theme data handle
//      hdc             - (optional) device content to be used for drawing
//      iPartId         - part number to draw
//      iStateId        - state number (of the part) to draw
//      pContentRect    - RECT that defines the content area
//      pBoundingRect   - RECT to receive the overall size/location of part
//-------------------------------------------------------------------------
THEMEAPI GetThemeBackgroundExtent(HTHEME hTheme, OPTIONAL HDC hdc,
    int iPartId, int iStateId, const RECT *pContentRect, 
    OUT RECT *pExtentRect);

//-------------------------------------------------------------------------
typedef enum THEMESIZE
{
    TS_MIN,             // minimum size
    TS_TRUE,            // true or best size
};

//-------------------------------------------------------------------------
//  GetThemePartSize() - returns the specified size of the theme part
//
//  hTheme              - theme data handle
//  hdc                 - HDC to select font into & measure against
//  iPartId             - part number to retrieve size for
//  iStateId            - state number (of the part) 
//  eSize               - the type of size to be retreived
//  psz                 - receives the specified size of the part 
//-------------------------------------------------------------------------
THEMEAPI GetThemePartSize(HTHEME hTheme, HDC hdc, 
    int iPartId, int iStateId, enum THEMESIZE eSize, OUT SIZE *psz);

//-------------------------------------------------------------------------
//  GetThemeTextExtent() - calculates the size/location of the specified 
//                         text when rendered in the Theme Font. 
//
//  hTheme              - theme data handle
//  hdc                 - HDC to select font & measure into
//  iPartId             - part number to draw
//  iStateId            - state number (of the part) 
//  pszText             - the text to be measured
//  dwCharCount         - number of chars to draw (-1 for all)
//  dwTextFlags         - same as DrawText() "uFormat" param
//  pszBoundingRect     - optional: to control layout of text
//  pszExtentRect       - receives the RECT for text size/location
//-------------------------------------------------------------------------
THEMEAPI GetThemeTextExtent(HTHEME hTheme, HDC hdc, 
    int iPartId, int iStateId, LPCWSTR pszText, int iCharCount, 
    DWORD dwTextFlags, OPTIONAL const RECT *pBoundingRect, 
    OUT RECT *pExtentRect);

//-------------------------------------------------------------------------
//  GetThemeTextMetrics()
//                      - returns info about the theme-specified font
//                        for the part/state passed in.
//
//  hTheme              - theme data handle
//  hdc                 - optional: HDC for screen context
//  iPartId             - part number to draw
//  iStateId            - state number (of the part) 
//  ptm                 - receives the font info
//-------------------------------------------------------------------------
THEMEAPI GetThemeTextMetrics(HTHEME hTheme, OPTIONAL HDC hdc, 
    int iPartId, int iStateId, OUT TEXTMETRIC* ptm);

//-------------------------------------------------------------------------
//  GetThemeBackgroundRegion()
//                      - computes the region for a regular or partially 
//                        transparent theme-specified background that is 
//                        bound by the specified "pRect".
//                        If the rectangle is empty, sets the HRGN to NULL 
//                        and return S_FALSE.
//
//  hTheme              - theme data handle
//  iPartId             - part number to draw
//  iStateId            - state number (of the part) 
//  pRect               - the RECT used to draw the part
//  pRegion             - receives handle to calculated region
//-------------------------------------------------------------------------
THEMEAPI GetThemeBackgroundRegion(HTHEME hTheme,  
    int iPartId, int iStateId, const RECT *pRect, OUT HRGN *pRegion);

//-------------------------------------------------------------------------
//  HitTestThemeBackground()
//                      - returns a HitTestCode (a subset of the values 
//                        returned by WM_NCHITTEST) for the point "ptTest" 
//                        within the theme-specified background
//                        (bound by pRect).  "pRect" and "ptTest" should 
//                        both be in the same coordinate system 
//                        (client, screen, etc).
//
//      hTheme          - theme data handle
//      hdc             - HDC to draw into
//      iPartId         - part number to test against
//      iStateId        - state number (of the part) 
//      pRect           - the RECT used to draw the part
//      hrgn            - optional region to use; must be in same coordinates as
//                      -    pRect and pTest.
//      ptTest          - the hit point to be tested
//      dwOptions       - HTTB_xxx constants
//      pwHitTestCode   - receives the returned hit test code - one of:
//  
//                        HTNOWHERE, HTLEFT, HTTOPLEFT, HTBOTTOMLEFT,
//                        HTRIGHT, HTTOPRIGHT, HTBOTTOMRIGHT,
//                        HTTOP, HTBOTTOM, HTCLIENT
//-------------------------------------------------------------------------
THEMEAPI HitTestThemeBackground(HTHEME hTheme, OPTIONAL HDC hdc, int iPartId, 
    int iStateId, DWORD dwOptions, const RECT *pRect, OPTIONAL HRGN hrgn, 
    POINT ptTest, OUT WORD *pwHitTestCode);

//------------------------------------------------------------------------
//  DrawThemeLine()     - draws the theme-defined line within the 
//                        specified "pRect".  "iStateId" selects the line 
//                        type (flat, raised, lowered).  "dwDtlFlags" 
//                        selects which line(s) to draw around the rect 
//                        (left, top, right, bottom).
//
//  hTheme              - theme data handle
//  hdc                 - HDC to draw into
//  iStateId            - style of line to draw (LVS_XXX or LHS_XXX)
//  pRect               - the RECT used to draw the line(s)
//  dwDtlFlags          - which parts of rect to draw (DTL_XXX flags)
//------------------------------------------------------------------------
THEMEAPI DrawThemeLine(HTHEME hTheme, HDC hdc, int iStateId, 
    const RECT *pRect, DWORD dwDtlFlags);

//------------------------------------------------------------------------
//  DrawThemeEdge()     - Similar to the DrawEdge() API, but uses part colors
//                        and is high-DPI aware
//  hTheme              - theme data handle
//  hdc                 - HDC to draw into
//  iPartId             - part number to draw
//  iStateId            - state number of part
//  pDestRect           - the RECT used to draw the line(s)
//  uEdge               - Same as DrawEdge() API
//  uFlags              - Same as DrawEdge() API
//  pContentRect        - Receives the interior rect if (uFlags & BF_ADJUST)
//------------------------------------------------------------------------
THEMEAPI DrawThemeEdge(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, 
                       const RECT *pDestRect, UINT uEdge, UINT uFlags, OPTIONAL OUT RECT *pContentRect);

//------------------------------------------------------------------------
//  DrawThemeBorder()   - draws the theme-defined border within the 
//                        specified "pRect".  "iStateId" selects the 
//                        border type (flat, raised, lowered). 
//
//  hTheme              - theme data handle
//  hdc                 - HDC to draw into
//  iStateId            - style of border to draw (BSS_XXX enums)
//  pRect               - the RECT used to draw the border
//------------------------------------------------------------------------
THEMEAPI DrawThemeBorder(HTHEME hTheme, HDC hdc, int iStateId, 
    const RECT *pRect);

//------------------------------------------------------------------------
//  DrawThemeIcon()     - draws an image within an imagelist based on 
//                        a (possible) theme-defined effect. 
//
//  hTheme              - theme data handle
//  hdc                 - HDC to draw into
//  iPartId             - part number to draw
//  iStateId            - state number of part
//  pRect               - the RECT to draw the image within
//  himl                - handle to IMAGELIST 
//  iImageIndex         - index into IMAGELIST (which icon to draw)
//------------------------------------------------------------------------
THEMEAPI DrawThemeIcon(HTHEME hTheme, HDC hdc, int iPartId, 
    int iStateId, const RECT *pRect, HIMAGELIST himl, int iImageIndex);

//---------------------------------------------------------------------------
//  IsThemePartDefined() - returns TRUE if the theme has defined parameters
//                         for the specified "iPartId" and "iStateId".
//
//  hTheme              - theme data handle
//  iPartId             - part number to find definition for
//  iStateId            - state number of part
//---------------------------------------------------------------------------
THEMEAPI_(BOOL) IsThemePartDefined(HTHEME hTheme, int iPartId, 
    int iStateId);

//---------------------------------------------------------------------------
//  IsThemeBackgroundPartiallyTransparent()
//                      - returns TRUE if the theme specified background for 
//                        the part/state has transparent pieces or 
//                        alpha-blended pieces.
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//---------------------------------------------------------------------------
THEMEAPI_(BOOL) IsThemeBackgroundPartiallyTransparent(HTHEME hTheme, 
    int iPartId, int iStateId);

//---------------------------------------------------------------------------
//    lower-level theme information services
//---------------------------------------------------------------------------
// The following methods are getter routines for each of the Theme Data types.
// Controls/Windows are defined in drawable "parts" by their author: a 
// parent part and 0 or more child parts.  Each of the parts can be 
// described in "states" (ex: disabled, hot, pressed).  
//---------------------------------------------------------------------------
// Each of the below methods takes a "iPartId" param to specify the 
// part and a "iStateId" to specify the state of the part.  
// "iStateId=0" refers to the root part.  "iPartId" = "0" refers to 
// the root class.  
//-----------------------------------------------------------------------
// Each method also take a "iPropId" param because multiple instances of 
// the same primitive type can be defined in the theme schema.
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
//  GetThemeColor()     - Get the value for the specified COLOR property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  pColor              - receives the value of the property
//-----------------------------------------------------------------------
THEMEAPI GetThemeColor(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT COLORREF *pColor);

//-----------------------------------------------------------------------
//  GetThemeMetric()    - Get the value for the specified metric/size
//                        property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  piVal               - receives the value of the property
//-----------------------------------------------------------------------
THEMEAPI GetThemeMetric(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT int *piVal);

//-----------------------------------------------------------------------
//  GetThemeString()    - Get the value for the specified string property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  pszBuff             - receives the string property value
//  cchMaxBuffChars     - max. number of chars allowed in pszBuff
//-----------------------------------------------------------------------
THEMEAPI GetThemeString(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT LPWSTR pszBuff, int cchMaxBuffChars);

//-----------------------------------------------------------------------
//  GetThemeBool()      - Get the value for the specified BOOL property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  pfVal               - receives the value of the property
//-----------------------------------------------------------------------
THEMEAPI GetThemeBool(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT BOOL *pfVal);

//-----------------------------------------------------------------------
//  GetThemeInt()       - Get the value for the specified int property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  piVal               - receives the value of the property
//-----------------------------------------------------------------------
THEMEAPI GetThemeInt(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT int *piVal);

//-----------------------------------------------------------------------
//  GetThemeEnumValue() - Get the value for the specified ENUM property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  piVal               - receives the value of the enum (cast to int*)
//-----------------------------------------------------------------------
THEMEAPI GetThemeEnumValue(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT int *piVal);

//-----------------------------------------------------------------------
//  GetThemePosition()  - Get the value for the specified position
//                        property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  pPoint              - receives the value of the position property
//-----------------------------------------------------------------------
THEMEAPI GetThemePosition(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT POINT *pPoint);

//-----------------------------------------------------------------------
//  GetThemeFont()      - Get the value for the specified font property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  pFont               - receives the value of the LOGFONT property
//-----------------------------------------------------------------------
THEMEAPI GetThemeFont(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT LOGFONT *pFont);

//-----------------------------------------------------------------------
//  GetThemeRect()      - Get the value for the specified RECT property
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to get the value for
//  pRect               - receives the value of the RECT property
//-----------------------------------------------------------------------
THEMEAPI GetThemeRect(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT RECT *pRect);

//-----------------------------------------------------------------------
typedef struct _MARGINS
{
    int cxLeftWidth;      // width of left border that retains its size
    int cxRightWidth;     // width of right border that retains its size
    int cyTopHeight;      // height of top border that retains its size
    int cyBottomHeight;   // height of bottom border that retains its size
} MARGINS, *PMARGINS;

//-----------------------------------------------------------------------
//  GetThemeMargins()   - Get the value for the specified MARGINS property
//
//      hTheme          - theme data handle
//      iPartId         - part number 
//      iStateId        - state number of part
//      iPropId         - the property number to get the value for
//      pMargins        - receives the value of the MARGINS property
//-----------------------------------------------------------------------
THEMEAPI GetThemeMargins(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT MARGINS *pMargins);

//-----------------------------------------------------------------------
#define MAX_INTLIST_COUNT 10

typedef struct _INTLIST
{
    int iValueCount;      // number of values in iValues
    int iValues[MAX_INTLIST_COUNT];
} INTLIST, *PINTLIST;

//-----------------------------------------------------------------------
//  GetThemeIntList()   - Get the value for the specified INTLIST struct
//
//      hTheme          - theme data handle
//      iPartId         - part number 
//      iStateId        - state number of part
//      iPropId         - the property number to get the value for
//      pIntList        - receives the value of the INTLIST property
//-----------------------------------------------------------------------
THEMEAPI GetThemeIntList(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT INTLIST *pIntList);

//-----------------------------------------------------------------------
typedef enum PROPERTYORIGIN
{
    PO_STATE,           // property was found in the state section
    PO_PART,            // property was found in the part section
    PO_CLASS,           // property was found in the class section
    PO_GLOBAL,          // property was found in [globals] section
    PO_NOTFOUND         // property was not found
};

//-----------------------------------------------------------------------
//  GetThemePropertyOrigin()
//                      - searches for the specified theme property
//                        and sets "pOrigin" to indicate where it was 
//                        found (or not found)
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to search for
//  pOrigin             - receives the value of the property origin
//-----------------------------------------------------------------------
THEMEAPI GetThemePropertyOrigin(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT enum PROPERTYORIGIN *pOrigin);

//---------------------------------------------------------------------------
//  SetWindowTheme()
//                      - redirects an existing Window to use a different 
//                        section of the current theme information than its 
//                        class normally asks for.
//
//  hwnd                - the handle of the window (cannot be NULL)
//
//  pszSubAppName       - app (group) name to use in place of the calling
//                        app's name.  If NULL, the actual calling app 
//                        name will be used.
//
//  pszSubIdList        - semicolon separated list of class Id names to 
//                        use in place of actual list passed by the 
//                        window's class.  if NULL, the id list from the 
//                        calling class is used.
//---------------------------------------------------------------------------
// The Theme Manager will remember the "pszSubAppName" and the
// "pszSubIdList" associations thru the lifetime of the window (even 
// if themes are subsequently changed).  The window is sent a 
// "WM_THEMECHANGED" msg at the end of this call, so that the new
// theme can be found and applied.
//---------------------------------------------------------------------------
// When "pszSubAppName" or "pszSubIdList" are NULL, the Theme Manager 
// removes the previously remember association.  To turn off theme-ing for 
// the specified window, you can pass an empty string (L"") so it 
// won't match any section entries.
//---------------------------------------------------------------------------
THEMEAPI SetWindowTheme(HWND hwnd, LPCWSTR pszSubAppName, 
    LPCWSTR pszSubIdList);

//---------------------------------------------------------------------------
//  GetThemeFilename()  - Get the value for the specified FILENAME property.
//
//  hTheme              - theme data handle
//  iPartId             - part number 
//  iStateId            - state number of part
//  iPropId             - the property number to search for
//  pszThemeFileName    - output buffer to receive the filename
//  cchMaxBuffChars     - the size of the return buffer, in chars
//---------------------------------------------------------------------------
THEMEAPI GetThemeFilename(HTHEME hTheme, int iPartId, 
    int iStateId, int iPropId, OUT LPWSTR pszThemeFileName, int cchMaxBuffChars);

//---------------------------------------------------------------------------
//  GetThemeSysColor()  - Get the value of the specified System color. 
//
//  hTheme              - the theme data handle.  if non-NULL, will return
//                        color from [SysMetrics] section of theme.
//                        if NULL, will return the global system color.
//
//  iColorId            - the system color index defined in winuser.h
//---------------------------------------------------------------------------
THEMEAPI_(COLORREF) GetThemeSysColor(HTHEME hTheme, int iColorId);

//---------------------------------------------------------------------------
//  GetThemeSysColorBrush() 
//                      - Get the brush for the specified System color. 
//
//  hTheme              - the theme data handle.  if non-NULL, will return
//                        brush matching color from [SysMetrics] section of 
//                        theme.  if NULL, will return the brush matching
//                        global system color.
//
//  iColorId            - the system color index defined in winuser.h
//---------------------------------------------------------------------------
THEMEAPI_(HBRUSH) GetThemeSysColorBrush(HTHEME hTheme, int iColorId);

//---------------------------------------------------------------------------
//  GetThemeSysSize()   - Get the value of the specified System size metric. 
//
//  hTheme              - the theme data handle.  if non-NULL, will return
//                        size from [SysMetrics] section of theme.
//                        if NULL, will return the global system metric.
//
//  iSizeId             - the following values are searched for in the
//                        theme [SysMetrics] section:
//
//                          SM_CXBORDER   (border width)
//                          SM_CXVSCROLL  (scrollbar width)
//                          SM_CYHSCROLL  (scrollbar height)
//                          SM_CXSIZE     (caption width)
//                          SM_CYSIZE     (caption height)
//                          SM_CXSMSIZE   (small caption width)
//                          SM_CYSMSIZE   (small caption height)
//                          SM_CXMENUSIZE (menubar width)
//                          SM_CYMENUSIZE (menubar height)
//
//                        any other iSizeId values will be passed directly
//                        to the system GetSystemMetrics() function
//---------------------------------------------------------------------------
THEMEAPI_(int) GetThemeSysSize(HTHEME hTheme, int iSizeId);

//---------------------------------------------------------------------------
//  GetThemeSysBool()   - Get the boolean value of specified System metric. 
//
//  hTheme              - the theme data handle.  if non-NULL, will return
//                        BOOL from [SysMetrics] section of theme.
//                        if NULL, will return the specified system boolean.
//
//  iBoolId             - the TMT_XXX BOOL number (first BOOL
//                        is TMT_FLATMENUS)
//---------------------------------------------------------------------------
THEMEAPI_(BOOL) GetThemeSysBool(HTHEME hTheme, int iBoolId);

//---------------------------------------------------------------------------
//  GetThemeSysFont()   - Get the LOGFONT for the specified System font. 
//
//  hTheme              - the theme data handle.  if non-NULL, will return
//                        font from [SysMetrics] section of theme.
//                        if NULL, will return the specified system font.
//
//  iFontId             - the TMT_XXX font number (first font
//                        is TMT_CAPTIONFONT)
//
//  plf                 - ptr to LOGFONT to receive the font value.
//---------------------------------------------------------------------------
THEMEAPI GetThemeSysFont(HTHEME hTheme, int iFontId, OUT LOGFONT *plf);

//---------------------------------------------------------------------------
//  GetThemeSysString() - Get the value of specified System string metric. 
//
//  hTheme              - the theme data handle (required)
//
//  iStringId           - must be one of the following values:
//
//                          TMT_CSSNAME
//                          TMT_XMLNAME
//
//  pszStringBuff       - the buffer to receive the string value
//
//  cchMaxStringChars   - max. number of chars that pszStringBuff can hold
//---------------------------------------------------------------------------
THEMEAPI GetThemeSysString(HTHEME hTheme, int iStringId, 
    OUT LPWSTR pszStringBuff, int cchMaxStringChars);

//---------------------------------------------------------------------------
//  GetThemeSysInt() - Get the value of specified System int.
//
//  hTheme              - the theme data handle (required)
//
//  iIntId              - must be one of the following values:
//
//                          TMT_DPIX
//                          TMT_DPIY
//                          TMT_MINCOLORDEPTH
//
//  piValue             - ptr to int to receive value
//---------------------------------------------------------------------------
THEMEAPI GetThemeSysInt(HTHEME hTheme, int iIntId, int *piValue);

//---------------------------------------------------------------------------
//  IsAppThemed()       - returns TRUE if current app is themed
//---------------------------------------------------------------------------
THEMEAPI_(BOOL) IsAppThemed();


//---------------------------------------------------------------------------
//  GetWindowTheme()    - if window is themed, returns its most recent
//                        HTHEME from OpenThemeData() - otherwise, returns
//                        NULL.
//
//      hwnd            - the window to get the HTHEME of
//---------------------------------------------------------------------------
THEMEAPI_(HTHEME) GetWindowTheme(HWND hwnd);


//---------------------------------------------------------------------------
//  EnableThemeDialogTexture() 
//
//  - Enables/disables dialog background theme.  This method can be used to 
//    tailor dialog compatibility with child windows and controls that 
//    may or may not coordinate the rendering of their client area backgrounds 
//    with that of their parent dialog in a manner that supports seamless 
//    background texturing.
//
//      hdlg         - the window handle of the target dialog
//      fEnable      - TRUE to enable the theme-defined background texturing,
//                     FALSE to disable background texturing.
//---------------------------------------------------------------------------
THEMEAPI EnableThemeDialogTexture(HWND hwnd, BOOL fEnable);


//---------------------------------------------------------------------------
//  IsThemeDialogTextureEnabled() 
//
//  - Reports whether the dialog supports background texturing.
//
//      hdlg         - the window handle of the target dialog
//---------------------------------------------------------------------------
THEMEAPI_(BOOL) IsThemeDialogTextureEnabled(HWND hwnd);


//---------------------------------------------------------------------------
//---- flags to control theming within an app ----

#define STAP_ALLOW_NONCLIENT    (1 << 0)
#define STAP_ALLOW_CONTROLS     (1 << 1)
#define STAP_ALLOW_WEBCONTENT   (1 << 2)

//---------------------------------------------------------------------------
//  GetThemeAppProperties()
//                      - returns the app property flags that control theming
//---------------------------------------------------------------------------
THEMEAPI_(DWORD) GetThemeAppProperties();

//---------------------------------------------------------------------------
//  SetThemeAppProperties()
//                      - sets the flags that control theming within the app
//
//      dwFlags         - the flag values to be set
//---------------------------------------------------------------------------
THEMEAPI_(void) SetThemeAppProperties(DWORD dwFlags);

//---------------------------------------------------------------------------
//  GetCurrentThemeName()
//                      - Get the name of the current theme in-use.  
//                        Optionally, return the ColorScheme name and the 
//                        Size name of the theme.
//
//  pszThemeFileName    - receives the theme path & filename
//  cchMaxNameChars     - max chars allowed in pszNameBuff
//
//  pszColorBuff        - (optional) receives the canonical color scheme name
//                        (not the display name)
//  cchMaxColorChars    - max chars allowed in pszColorBuff
//
//  pszSizeBuff         - (optional) receives the canonical size name 
//                        (not the display name)
//  cchMaxSizeChars     - max chars allowed in pszSizeBuff
//---------------------------------------------------------------------------
THEMEAPI GetCurrentThemeName(
    OUT LPWSTR pszThemeFileName, int cchMaxNameChars, 
    OUT OPTIONAL LPWSTR pszColorBuff, int cchMaxColorChars,
    OUT OPTIONAL LPWSTR pszSizeBuff, int cchMaxSizeChars);

//---------------------------------------------------------------------------
//  GetThemeDocumentationProperty()
//                      - Get the value for the specified property name from 
//                        the [documentation] section of the themes.ini file 
//                        for the specified theme.  If the property has been 
//                        localized in the theme files string table, the 
//                        localized version of the property value is returned. 
//
//  pszThemeFileName    - filename of the theme file to query
//  pszPropertyName     - name of the string property to retreive a value for
//  pszValueBuff        - receives the property string value
//  cchMaxValChars      - max chars allowed in pszValueBuff
//---------------------------------------------------------------------------
#define SZ_THDOCPROP_DISPLAYNAME                L"DisplayName"
#define SZ_THDOCPROP_CANONICALNAME              L"ThemeName"
#define SZ_THDOCPROP_TOOLTIP                    L"ToolTip"
#define SZ_THDOCPROP_AUTHOR                     L"author"

THEMEAPI GetThemeDocumentationProperty(LPCWSTR pszThemeName,
    LPCWSTR pszPropertyName, OUT LPWSTR pszValueBuff, int cchMaxValChars);

//---------------------------------------------------------------------------
//  Theme API Error Handling
//
//      All functions in the Theme API use the WIN32 function 
//      "SetLastError()" to record any call failures.  
//
//      To retreive the simple error code of the last failure on the
//      current thread, use the WIN32 function "GetLastError()".
//
//      To retreive the full error context information for the last
//      theme API failure on the current thread, use the 
//      function "GetThemeLastErrorContext()".
//
//      To format a theme error and context into a msg, use the 
//      function "FormatThemeMessage()".
//---------------------------------------------------------------------------

typedef struct _THEME_ERROR_CONTEXT
{
    DWORD dwSize;                   // of this structure

    //---- error context information ----
    HRESULT hr;                     // error code from last error
    WCHAR szMsgParam1[MAX_PATH];    // value of first param for msg
    WCHAR szMsgParam2[MAX_PATH];    // value of second param for msg
    WCHAR szFileName[MAX_PATH];     // associated source filename
    WCHAR szSourceLine[MAX_PATH];   // source line
    int iLineNum;                   // source line number
} THEME_ERROR_CONTEXT, *PTHEME_ERROR_CONTEXT;

//---------------------------------------------------------------------------
//  GetThemeLastErrorContext()
//                      - fill in the THEME_ERROR_CONTEXT structure
//                        with needed information about the last theme API 
//                        error.
//
//  pContext            - ptr to the THEME_ERROR_CONTEXT to be filled
//---------------------------------------------------------------------------
THEMEAPI GetThemeLastErrorContext(OUT THEME_ERROR_CONTEXT *pContext);

//---------------------------------------------------------------------------
//  FormatThemeMessage() 
//                      - use the supplied theme error context
//                        to format an error message in the specified
//                        language.
//
//  dwLanguageId        - the language to format the error msg into
//
//  pContext            - ptr to theme context structure (see above)
//                        that supplies the HRESULT and string params
//
//  pszMessageBuff      - where to write the formatted msg.  If the
//                        message is too long, it is truncated.
//
//  cchMaxMessageChars  - maximum number of chars to write to buff
//---------------------------------------------------------------------------
THEMEAPI FormatThemeMessage(DWORD dwLanguageId, 
    THEME_ERROR_CONTEXT *pContext, OUT LPWSTR pszMessageBuff, 
    int cchMaxMessageChars);

//---------------------------------------------------------------------------
// GetThemeImageFromWindow
//---------------------------------------------------------------------------

THEMEAPI GetThemeImageFromParent(HWND hwnd, HDC hdc, RECT* prc);

//---------------------------------------------------------------------------
//#endif  /* (_WIN32_WINNT >= 0x0500) *// 
//---------------------------------------------------------------------------
#endif // _UXTHEME_H_
//---------------------------------------------------------------------------
