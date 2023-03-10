/***
*initcrit.c - CRT wrapper for InitializeCriticalSectionAndSpinCount
*
*       Copyright (c) 1999-2000, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Contains __crtInitCritSecAndSpinCount, a wrapper for
*       the Win32 API InitializeCriticalSectionAndSpinCount which is only
*       available on NT4SP3 or better.
*
*       *** For internal use only ***
*
*******************************************************************************/

#ifdef _MT

#include <cruntime.h>
#include <windows.h>
#include <internal.h>
#include <rterr.h>

typedef
DWORD
(WINAPI * PFN_SET_CRITICAL_SECTION_SPIN_COUNT) (
    PCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount
);

/***
*void __crtDummySetSpinCount() - dummy SetCriticalSectionSpinCount
*
*Purpose:
*       For systems where the Win32 API SetCriticalSectionSpinCount is
*       unavailable, this is called instead.
*
*Entry:
*       PCRITICAL_SECTION lpCriticalSection - ptr to critical section
*       DWORD dwSpinCount - initial spin count setting
*
*Exit:
*       Always returns 0 (previous SpinCount in real API)
*
*Exceptions:
*
*******************************************************************************/

static DWORD WINAPI __crtDummySetSpinCount (
    PCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount
    )
{
    return 0;
}

/***
*void __crtInitCritSecAndSpinCount() - initialize critical section
*
*Purpose:
*       Calls InitializeCriticalSection, and if available,
*       SetCriticalSectionSpinCount.  On multiprocessor systems, a spin count
*       should be used with critical sections, but the appropriate APIs are
*       only available on NT4SP3 or later.
*
*       Also handles the out of memory condition which is possible with
*       InitializeCriticalSection.
*
*Entry:
*       PCRITICAL_SECTION lpCriticalSection - ptr to critical section
*       DWORD dwSpinCount - initial spin count setting
*
*Exit:
*       None
*       calls _amsg_exit on failure
*
*Exceptions:
*
*******************************************************************************/

void __cdecl __crtInitCritSecAndSpinCount (
    PCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount
    )
{
    static PFN_SET_CRITICAL_SECTION_SPIN_COUNT __crtSetCritSecSpinCount = NULL;

    __try {
        InitializeCriticalSection(lpCriticalSection);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        /*
         * InitializeCriticalSection failed by raising an exception.
         * Bail with a runtime error.
         */
        _amsg_exit(_RT_LOCK);
    }

    if (__crtSetCritSecSpinCount == NULL) {
        HINSTANCE hKernel32;

        hKernel32 = LoadLibrary("kernel32.dll");
        if (hKernel32 != NULL) {
            __crtSetCritSecSpinCount = (PFN_SET_CRITICAL_SECTION_SPIN_COUNT)
                GetProcAddress(hKernel32, "SetCriticalSectionSpinCount");

            if (__crtSetCritSecSpinCount == NULL) {
                /* SetCriticalSectionSpinCount not available, use dummy API */
                __crtSetCritSecSpinCount = __crtDummySetSpinCount;
            }

            /* We can free this handle because we statically link to it */
            FreeLibrary(hKernel32);
        }
        else {
            /* LoadLibrary failed (should never happen), use dummy API */
            __crtSetCritSecSpinCount = __crtDummySetSpinCount;
        }
    }

    /*
     * Either call the real SetCriticalSectionSpinCount API or the
     * dummy replacement if the real API wasn't found the first time through.
     */
    __crtSetCritSecSpinCount(lpCriticalSection, dwSpinCount);
}

#endif  /* _MT */
