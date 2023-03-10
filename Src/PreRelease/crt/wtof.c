/***
*wtof.c - convert wchar_t string to floating point number
*
*       Copyright (c) 1985-2000, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Converts a wide character string into a floating point number.
*
*******************************************************************************/

#ifndef _UNICODE
#define _UNICODE
#endif  /* _UNICODE */

#include <cruntime.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dbgint.h>
/***
*double wtof(ptr) - convert wide char string to floating point number
*
*Purpose:
*       atof recognizes an optional string of whitespace, then
*       an optional sign, then a string of digits optionally
*       containing a decimal point, then an optional e or E followed
*       by an optionally signed integer, and converts all this to
*       to a floating point number.  The first unrecognized
*       character ends the string.
*
*Entry:
*       ptr - pointer to wide char string to convert
*
*Exit:
*       returns floating point value of wide character representation
*
*Exceptions:
*
*******************************************************************************/
double __cdecl _wtof(
        const wchar_t *ptr
        )
{
    char *cptr;
    size_t len;
    double retval;
    while (iswspace(*ptr))
        ptr++;

    len = wcstombs(NULL, ptr, 0);
    cptr = (char *)_malloc_crt((len +1)*sizeof(char));
    // UNDONE: check for errors
    wcstombs(cptr, ptr, len);
    retval = atof(cptr);
    _free_crt(cptr);
    return retval;
}
