/***
*charmax.c - definition of _charmax variable
*
*       Copyright (c) 1993-2000, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       defines _charmax
*
*       According to ANSI, certain elements of the lconv structure must be
*       initialized to CHAR_MAX and the value of CHAR_MAX changes when
*       the user compiles -J, the value of CHAR_MAX changes. To reflect this
*       change in the lconv structure, we initialize the structure to SCHAR_MAX,
*       and when any of the users modules are compiled -J, the structure is
*       updated.
*
*       Files involved:
*
*       locale.h - if -J, generates an unresolved external to _charmax
*       charmax.c - defines _charmax and sets to UCHAR_MAX (255), places
*               _lconv_init in startup initializer table if pulled in by -J
*       lconv.c - initializes lconv structure to SCHAR_MAX (127),
*               since libraries built without -J
*       lcnvinit.c - sets lconv members to 25.
**
*******************************************************************************/

#ifdef _MSC_VER

#include <sect_attribs.h>
#include <internal.h>

void __lconv_init(void);

int _charmax = 255;

#pragma data_seg(".CRT$XIC")
_CRTALLOC(".CRT$XIC") static _PVFV pinit = __lconv_init;

#pragma data_seg()

#endif  /* _MSC_VER */
