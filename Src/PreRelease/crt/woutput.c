/***
*woutput.c - wprintf style output to a FILE (wchar_t version)
*
*       Copyright (c) 1993-2000, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file defines the symbol UNICODE and then #includes the file
*       "output.c" in order to implement _woutput(), the helper for the
*       wide character versions of *wprintf() family of functions.
*
*******************************************************************************/


#ifndef _UNICODE
#define _UNICODE 1
#endif  /* _UNICODE */

#ifndef UNICODE
#define UNICODE 1
#endif  /* UNICODE */

#include "output.c"

