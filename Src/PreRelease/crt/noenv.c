/***
*noenv.c - stub out CRT's environment string processing
*
*       Copyright (c) 1997-2000, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Stub out the environment string processing normally carried out at
*       during startup. Note, getenv, _putenv and _environ are not supported
*       if this object is used. Nor is the third argument to main.
*
*******************************************************************************/

#include <stdlib.h>

void __cdecl _setenvp(void) { }

void * __cdecl __crtGetEnvironmentStringsA(void) { return NULL; }

void __cdecl _wsetenvp(void) { }

void * __cdecl __crtGetEnvironmentStringsW(void) { return NULL; }
