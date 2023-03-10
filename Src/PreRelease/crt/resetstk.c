/***
*resetstk.c - Recover from Stack overflow.
*
*       Copyright (c) 1989-2000, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines the _resetstkoflw() function.
*
*******************************************************************************/

#include <malloc.h>
#include <windows.h>


/***
* void _resetstkoflw(void) - Recovers from Stack Overflow
*
* Purpose:
*       Sets the guard page to its position before the stack overflow.
*
*******************************************************************************/

void _resetstkoflw(void)
{
    LPBYTE pStack, pGuard, pStackBase, pCommitBase;
    MEMORY_BASIC_INFORMATION mbi;
    SYSTEM_INFO si;
    DWORD PageSize;

    // Use alloca() to get the current stack pointer
    pStack = _alloca(1);

    // Find the base of the stack.
    VirtualQuery(pStack, &mbi, sizeof mbi);
    pStackBase = mbi.AllocationBase;

    VirtualQuery(pStackBase, &mbi, sizeof mbi);

    if (mbi.State &MEM_RESERVE )
    {
       pCommitBase = (LPBYTE)mbi.AllocationBase + mbi.RegionSize;
       VirtualQuery(pCommitBase, &mbi, sizeof mbi);
    }
    else
    {
        pCommitBase = pStackBase;
    }


    // Find the page just below where stack pointer currently points.
    GetSystemInfo(&si);
    PageSize = si.dwPageSize;

    pGuard = (LPBYTE) (((DWORD_PTR)pStack & ~(DWORD_PTR)(PageSize -1)) - PageSize);

    if ( pGuard < pStackBase)
    // We can't save this
        return;

    if (pGuard > pStackBase) {
        VirtualFree(pStackBase, pGuard -pStackBase, MEM_DECOMMIT);
    }

    VirtualAlloc(pGuard, PageSize, MEM_COMMIT, PAGE_READWRITE);
    VirtualProtect(pGuard, PageSize, PAGE_READWRITE | PAGE_GUARD, &PageSize);
}
