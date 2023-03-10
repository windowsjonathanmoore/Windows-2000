/* Copyright (c) 2001 Microsoft Corp. All rights reserved. */

#if _MSC_VER > 1000
#pragma once
#endif

#if defined(__cplusplus)
extern "C" {
#endif


#if !defined(RC_INVOKED) /* RC complains about long symbols in #ifs */
#if ISOLATION_AWARE_ENABLED


#if !defined(ISOLATION_AWARE_INLINE)
#if defined(__cplusplus)
#define ISOLATION_AWARE_INLINE inline
#else
#define ISOLATION_AWARE_INLINE __inline
#endif
#endif



BOOL WINAPI IsolationAwarePrivateActivateMyActCtx(ULONG_PTR* pulpCookie);

/*
These are private.
*/
__declspec(selectany) HANDLE g_hWinbasePrivateIsolationAwareMyActCtx = INVALID_HANDLE_VALUE;
__declspec(selectany) BOOL   g_fIsolationAwarePrivateDownlevel = FALSE;
FARPROC WINAPI WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll(LPCSTR pszProcName);

HMODULE WINAPI IsolationAwareLoadLibraryA(LPCSTR lpLibFileName);
HMODULE WINAPI IsolationAwareLoadLibraryW(LPCWSTR lpLibFileName);
HMODULE WINAPI IsolationAwareLoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
HMODULE WINAPI IsolationAwareLoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
HANDLE WINAPI IsolationAwareCreateActCtxA(PCACTCTXA pActCtx);
HANDLE WINAPI IsolationAwareCreateActCtxW(PCACTCTXW pActCtx);
void WINAPI IsolationAwareAddRefActCtx(HANDLE hActCtx);
void WINAPI IsolationAwareReleaseActCtx(HANDLE hActCtx);
BOOL WINAPI IsolationAwareZombifyActCtx(HANDLE hActCtx);
BOOL WINAPI IsolationAwareActivateActCtx(HANDLE hActCtx,ULONG_PTR*lpCookie);
BOOL WINAPI IsolationAwareDeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
BOOL WINAPI IsolationAwareGetCurrentActCtx(HANDLE*lphActCtx);
BOOL WINAPI IsolationAwareFindActCtxSectionStringA(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
BOOL WINAPI IsolationAwareFindActCtxSectionStringW(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
BOOL WINAPI IsolationAwareFindActCtxSectionGuid(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,const GUID*lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
BOOL WINAPI IsolationAwareQueryActCtxW(DWORD dwFlags,HANDLE hActCtx,ULONG ulSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T*pcbWrittenOrRequired);

#if defined(UNICODE)

#define IsolationAwareCreateActCtx IsolationAwareCreateActCtxW
#define IsolationAwareFindActCtxSectionString IsolationAwareFindActCtxSectionStringW
#define IsolationAwareLoadLibrary IsolationAwareLoadLibraryW
#define IsolationAwareLoadLibraryEx IsolationAwareLoadLibraryExW

#else /* UNICODE */

#define IsolationAwareCreateActCtx IsolationAwareCreateActCtxA
#define IsolationAwareFindActCtxSectionString IsolationAwareFindActCtxSectionStringA
#define IsolationAwareLoadLibrary IsolationAwareLoadLibraryA
#define IsolationAwareLoadLibraryEx IsolationAwareLoadLibraryExA

#endif /* UNICODE */

ISOLATION_AWARE_INLINE HMODULE WINAPI IsolationAwareLoadLibraryA(LPCSTR lpLibFileName)
{
    HMODULE moduleResult = NULL;
    ULONG_PTR  ulpCookie = 0;
    const BOOL fActivateActCtxSuccess = g_fIsolationAwarePrivateDownlevel || IsolationAwarePrivateActivateMyActCtx(&ulpCookie);
    if (!fActivateActCtxSuccess)
        return moduleResult;
    __try
    {
        moduleResult = LoadLibraryA(lpLibFileName);
    }
    __finally
    {
        if (!g_fIsolationAwarePrivateDownlevel)
        {
            const BOOL fPreserveLastError = (moduleResult == NULL);
            const DWORD dwLastError = fPreserveLastError ? GetLastError() : NO_ERROR;
            if (!IsolationAwareDeactivateActCtx(0, ulpCookie))
            {
                const DWORD dwLastError2 = GetLastError();
                if (dwLastError2 != ERROR_PROC_NOT_FOUND
                     && dwLastError2 != ERROR_CALL_NOT_IMPLEMENTED
                   )
                    OutputDebugStringA("DeactivateActCtx failed in IsolationAwareLoadLibraryA\n");
            }
            if (fPreserveLastError)
                SetLastError(dwLastError);
        }
    }
    return moduleResult;
}

ISOLATION_AWARE_INLINE HMODULE WINAPI IsolationAwareLoadLibraryW(LPCWSTR lpLibFileName)
{
    HMODULE moduleResult = NULL;
    ULONG_PTR  ulpCookie = 0;
    const BOOL fActivateActCtxSuccess = g_fIsolationAwarePrivateDownlevel || IsolationAwarePrivateActivateMyActCtx(&ulpCookie);
    if (!fActivateActCtxSuccess)
        return moduleResult;
    __try
    {
        moduleResult = LoadLibraryW(lpLibFileName);
    }
    __finally
    {
        if (!g_fIsolationAwarePrivateDownlevel)
        {
            const BOOL fPreserveLastError = (moduleResult == NULL);
            const DWORD dwLastError = fPreserveLastError ? GetLastError() : NO_ERROR;
            if (!IsolationAwareDeactivateActCtx(0, ulpCookie))
            {
                const DWORD dwLastError2 = GetLastError();
                if (dwLastError2 != ERROR_PROC_NOT_FOUND
                     && dwLastError2 != ERROR_CALL_NOT_IMPLEMENTED
                   )
                    OutputDebugStringA("DeactivateActCtx failed in IsolationAwareLoadLibraryW\n");
            }
            if (fPreserveLastError)
                SetLastError(dwLastError);
        }
    }
    return moduleResult;
}

ISOLATION_AWARE_INLINE HMODULE WINAPI IsolationAwareLoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags)
{
    HMODULE moduleResult = NULL;
    ULONG_PTR  ulpCookie = 0;
    const BOOL fActivateActCtxSuccess = g_fIsolationAwarePrivateDownlevel || IsolationAwarePrivateActivateMyActCtx(&ulpCookie);
    if (!fActivateActCtxSuccess)
        return moduleResult;
    __try
    {
        moduleResult = LoadLibraryExA(lpLibFileName,hFile,dwFlags);
    }
    __finally
    {
        if (!g_fIsolationAwarePrivateDownlevel)
        {
            const BOOL fPreserveLastError = (moduleResult == NULL);
            const DWORD dwLastError = fPreserveLastError ? GetLastError() : NO_ERROR;
            if (!IsolationAwareDeactivateActCtx(0, ulpCookie))
            {
                const DWORD dwLastError2 = GetLastError();
                if (dwLastError2 != ERROR_PROC_NOT_FOUND
                     && dwLastError2 != ERROR_CALL_NOT_IMPLEMENTED
                   )
                    OutputDebugStringA("DeactivateActCtx failed in IsolationAwareLoadLibraryExA\n");
            }
            if (fPreserveLastError)
                SetLastError(dwLastError);
        }
    }
    return moduleResult;
}

ISOLATION_AWARE_INLINE HMODULE WINAPI IsolationAwareLoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags)
{
    HMODULE moduleResult = NULL;
    ULONG_PTR  ulpCookie = 0;
    const BOOL fActivateActCtxSuccess = g_fIsolationAwarePrivateDownlevel || IsolationAwarePrivateActivateMyActCtx(&ulpCookie);
    if (!fActivateActCtxSuccess)
        return moduleResult;
    __try
    {
        moduleResult = LoadLibraryExW(lpLibFileName,hFile,dwFlags);
    }
    __finally
    {
        if (!g_fIsolationAwarePrivateDownlevel)
        {
            const BOOL fPreserveLastError = (moduleResult == NULL);
            const DWORD dwLastError = fPreserveLastError ? GetLastError() : NO_ERROR;
            if (!IsolationAwareDeactivateActCtx(0, ulpCookie))
            {
                const DWORD dwLastError2 = GetLastError();
                if (dwLastError2 != ERROR_PROC_NOT_FOUND
                     && dwLastError2 != ERROR_CALL_NOT_IMPLEMENTED
                   )
                    OutputDebugStringA("DeactivateActCtx failed in IsolationAwareLoadLibraryExW\n");
            }
            if (fPreserveLastError)
                SetLastError(dwLastError);
        }
    }
    return moduleResult;
}

ISOLATION_AWARE_INLINE HANDLE WINAPI IsolationAwareCreateActCtxA(PCACTCTXA pActCtx)
{
    HANDLE result = INVALID_HANDLE_VALUE;
    typedef HANDLE (WINAPI* PFN)(PCACTCTXA pActCtx);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("CreateActCtxA");
        if (s_pfn == NULL)
            return result;
    }
    result = s_pfn(pActCtx);
    return result;
}

ISOLATION_AWARE_INLINE HANDLE WINAPI IsolationAwareCreateActCtxW(PCACTCTXW pActCtx)
{
    HANDLE result = INVALID_HANDLE_VALUE;
    typedef HANDLE (WINAPI* PFN)(PCACTCTXW pActCtx);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("CreateActCtxW");
        if (s_pfn == NULL)
            return result;
    }
    result = s_pfn(pActCtx);
    return result;
}

ISOLATION_AWARE_INLINE void WINAPI IsolationAwareAddRefActCtx(HANDLE hActCtx)
{
    typedef void (WINAPI* PFN)(HANDLE hActCtx);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("AddRefActCtx");
        if (s_pfn == NULL)
            return;
    }
    s_pfn(hActCtx);
    return;
}

ISOLATION_AWARE_INLINE void WINAPI IsolationAwareReleaseActCtx(HANDLE hActCtx)
{
    typedef void (WINAPI* PFN)(HANDLE hActCtx);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("ReleaseActCtx");
        if (s_pfn == NULL)
            return;
    }
    s_pfn(hActCtx);
    return;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareZombifyActCtx(HANDLE hActCtx)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(HANDLE hActCtx);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("ZombifyActCtx");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(hActCtx);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareActivateActCtx(HANDLE hActCtx,ULONG_PTR*lpCookie)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(HANDLE hActCtx,ULONG_PTR*lpCookie);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("ActivateActCtx");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(hActCtx,lpCookie);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareDeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(DWORD dwFlags,ULONG_PTR ulCookie);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("DeactivateActCtx");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(dwFlags,ulCookie);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareGetCurrentActCtx(HANDLE*lphActCtx)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(HANDLE*lphActCtx);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("GetCurrentActCtx");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(lphActCtx);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareFindActCtxSectionStringA(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("FindActCtxSectionStringA");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(dwFlags,lpExtensionGuid,ulSectionId,lpStringToFind,ReturnedData);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareFindActCtxSectionStringW(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("FindActCtxSectionStringW");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(dwFlags,lpExtensionGuid,ulSectionId,lpStringToFind,ReturnedData);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareFindActCtxSectionGuid(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,const GUID*lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(DWORD dwFlags,const GUID*lpExtensionGuid,ULONG ulSectionId,const GUID*lpGuidToFind,PACTCTX_SECTION_KEYED_DATA ReturnedData);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("FindActCtxSectionGuid");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(dwFlags,lpExtensionGuid,ulSectionId,lpGuidToFind,ReturnedData);
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwareQueryActCtxW(DWORD dwFlags,HANDLE hActCtx,ULONG ulSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T*pcbWrittenOrRequired)
{
    BOOL fResult = FALSE;
    typedef BOOL (WINAPI* PFN)(DWORD dwFlags,HANDLE hActCtx,ULONG ulSubInstance,ULONG ulInfoClass,PVOID pvBuffer,SIZE_T cbBuffer,SIZE_T*pcbWrittenOrRequired);
    static PFN s_pfn;
    if (s_pfn == NULL)
    {
        s_pfn = (PFN)WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll("QueryActCtxW");
        if (s_pfn == NULL)
            return fResult;
    }
    fResult = s_pfn(dwFlags,hActCtx,ulSubInstance,ulInfoClass,pvBuffer,cbBuffer,pcbWrittenOrRequired);
    return fResult;
}



FORCEINLINE
HMODULE
WINAPI
WinbasePrivateGetModuleHandle_Kernel32_dll(
    )
{
    HMODULE hKernel32 = GetModuleHandleW(L"Kernel32.dll");
    if (hKernel32 == NULL
           && GetLastError() == ERROR_CALL_NOT_IMPLEMENTED
       )
        hKernel32 = GetModuleHandleA("Kernel32.dll");
    return hKernel32;
}

/*
 * InterlockedCompareExchange is not exported on Windows 95.
 * This function lets clients of SideBySide load on Windows 95,
 * though SideBySide functionality is not provided there.
 *
 * IA64 always has this function.
 */
#if defined(_X86_) || defined(_M_IX86)

typedef PVOID (WINAPI* WINBASE_PRIVATE_X86_PFN_INTERLOCKED_COMPARE_EXCHANGE_POINTER)(PVOID* Destination, PVOID Exchange, PVOID Comperand);

__declspec(selectany) WINBASE_PRIVATE_X86_PFN_INTERLOCKED_COMPARE_EXCHANGE_POINTER WinbasePrivatePfnInterlockedCompareExchangePointer = NULL;

FORCEINLINE
BOOL
WINAPI
WinbasePrivateDelayLoadInterlockedCompareExchangePointer(
    )
/*
This function is private to functions present in this header.
Do not use it.
*/
{
    BOOL Success = FALSE;
    HMODULE Kernel32;

    if (WinbasePrivatePfnInterlockedCompareExchangePointer != NULL)
    {
        Success = TRUE;
        goto Exit;
    }

    Kernel32 = WinbasePrivateGetModuleHandle_Kernel32_dll();
    if (Kernel32 == NULL)
        goto Exit;
    WinbasePrivatePfnInterlockedCompareExchangePointer =
        (WINBASE_PRIVATE_X86_PFN_INTERLOCKED_COMPARE_EXCHANGE_POINTER)GetProcAddress(Kernel32, "InterlockedCompareExchange");
    if (WinbasePrivatePfnInterlockedCompareExchangePointer == NULL)
        goto Exit;

    Success = TRUE;
Exit:
    return Success;
}

#else /* X86 */

#define WinbasePrivatePfnInterlockedCompareExchangePointer InterlockedCompareExchangePointer

#endif /* X86 */

ISOLATION_AWARE_INLINE BOOL
WINAPI
WinbasePrivateVirtualAddressToHModule(
    IN PVOID     pvVirtualAddress,
    OUT HMODULE* phModule
    )
/*
This function is private to functions present in this header.
Do not use it.
*/
{
    MEMORY_BASIC_INFORMATION mbi;
    SIZE_T size;
    BOOL fResult = FALSE;

    size = VirtualQuery(pvVirtualAddress, &mbi, sizeof(mbi));
    if (size < sizeof(mbi))
    {
        if (GetLastError() == NO_ERROR)
            SetLastError(ERROR_INTERNAL_ERROR);
        goto Exit;
    }
    *phModule = (HMODULE)mbi.AllocationBase;
    fResult = TRUE;
Exit:
    return fResult;
}

#define WINBASE_NUMBER_OF(x) (sizeof(x) / sizeof((x)[0]))

ISOLATION_AWARE_INLINE
BOOL
WINAPI
WinbasePrivateCreateActCtxForHModule(HMODULE hModule, HANDLE* phactctx)
/*
This function is private to functions present in this header.
Do not use it.

On downlevel platforms (Windows 95, Windows 98, Windows ME, Windows NT 4, Windows 2000), this
function returns TRUE and a NULL handle.
*/
{

    WCHAR rgchFullModulePath[MAX_PATH + 1];
    DWORD dw;
    ACTCTXW actCtx;
    HANDLE hActCtx = INVALID_HANDLE_VALUE;
    BOOL fResult = FALSE;

    if (*phactctx != INVALID_HANDLE_VALUE)
    {
        fResult = TRUE;
        goto Exit;
    }

    if (g_fIsolationAwarePrivateDownlevel)
    {
        hActCtx = NULL;
        goto Success;
    }

    rgchFullModulePath[WINBASE_NUMBER_OF(rgchFullModulePath) - 1] = 0;
    rgchFullModulePath[WINBASE_NUMBER_OF(rgchFullModulePath) - 2] = 0;
    dw = GetModuleFileNameW(hModule, rgchFullModulePath, WINBASE_NUMBER_OF(rgchFullModulePath));
    if (dw == 0)
        goto Exit;
    if (rgchFullModulePath[WINBASE_NUMBER_OF(rgchFullModulePath) - 2] != 0)
    {
        SetLastError(ERROR_BUFFER_OVERFLOW);
        goto Exit;
    }
    LoadLibraryW(rgchFullModulePath);

    actCtx.cbSize = sizeof(actCtx);
    actCtx.dwFlags = ACTCTX_FLAG_RESOURCE_NAME_VALID;
    actCtx.lpSource = rgchFullModulePath;
    actCtx.lpResourceName = (LPCWSTR)(ULONG_PTR)2;
    hActCtx = IsolationAwareCreateActCtxW(&actCtx);
    if (hActCtx == INVALID_HANDLE_VALUE)
        goto Exit;

Success:
    *phactctx = hActCtx;
    fResult = TRUE;
Exit:
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI WinbasePrivateIsolationAwareCreateMyActCtx (void)
/*
The correctness of this function depends on it being statically linked into
what "my" refers to.

This function is private to functions present in this header.
Do not use it.
*/
{
    BOOL fResult = FALSE;
    HANDLE hMyActCtx = INVALID_HANDLE_VALUE;
    HMODULE hModule;
    ULONG_PTR ulpCookie;

    if (g_fIsolationAwarePrivateDownlevel)
    {
        fResult = TRUE;
        goto Exit;
    }

    if (g_hWinbasePrivateIsolationAwareMyActCtx != INVALID_HANDLE_VALUE)
    {
        fResult = TRUE;
        goto Exit;
    }

#if defined(_X86_) || defined(_M_IX86)
    if (!WinbasePrivateDelayLoadInterlockedCompareExchangePointer())
        goto Exit;
#endif

    if (!WinbasePrivateVirtualAddressToHModule(&g_hWinbasePrivateIsolationAwareMyActCtx, &hModule))
        goto Exit;

    if (!WinbasePrivateCreateActCtxForHModule(hModule, &hMyActCtx))
        goto Exit;

#define ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION              (2)

    if (IsolationAwareActivateActCtx(hMyActCtx, &ulpCookie))
    {
        __try
        {
            ACTCTX_SECTION_KEYED_DATA actCtxSectionKeyedData;

            actCtxSectionKeyedData.cbSize = sizeof(actCtxSectionKeyedData);
            if (IsolationAwareFindActCtxSectionStringW(0, NULL, ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION, L"Comctl32.dll", &actCtxSectionKeyedData))
            {
                /* get button, edit, etc. registered */
                LoadLibraryW(L"Comctl32.dll");
            }
        }
        __finally
        {
            IsolationAwareDeactivateActCtx(0, ulpCookie);
        }
    }

    if (WinbasePrivatePfnInterlockedCompareExchangePointer(
        (PVOID*)&g_hWinbasePrivateIsolationAwareMyActCtx,
        hMyActCtx,
        INVALID_HANDLE_VALUE)
        != INVALID_HANDLE_VALUE)
    {
        /* We lost the race. */
        IsolationAwareReleaseActCtx(hMyActCtx);
        fResult = TRUE;
        goto Exit;
    }


    fResult = TRUE;
Exit:
    return fResult;
}

ISOLATION_AWARE_INLINE BOOL WINAPI IsolationAwarePrivateActivateMyActCtx(ULONG_PTR* pulpCookie)
/*
This function is private to functions present in this header and other headers.
*/
{
    BOOL fResult = FALSE;

    if (g_fIsolationAwarePrivateDownlevel)
    {
        fResult = TRUE;
        goto Exit;
    }
    if (!WinbasePrivateIsolationAwareCreateMyActCtx())
        goto Exit;
    if (!IsolationAwareActivateActCtx(g_hWinbasePrivateIsolationAwareMyActCtx, pulpCookie))
        goto Exit;

    fResult = TRUE;
Exit:
	if (!fResult)
	{
		const DWORD dwLastError = GetLastError();
		if (dwLastError == ERROR_PROC_NOT_FOUND
			|| dwLastError == ERROR_CALL_NOT_IMPLEMENTED
			)
		{
			g_fIsolationAwarePrivateDownlevel = TRUE;
			fResult = TRUE;
		}
	}
    return fResult;
}

#undef WINBASE_NUMBER_OF

ISOLATION_AWARE_INLINE FARPROC WINAPI WinbasePrivateIsolationAwareGetProcAddress_Kernel32_dll(LPCSTR pszProcName)
/* This function is shared by the other stubs in this header. */
{
    FARPROC proc = NULL;
    static HMODULE s_module;
    if (s_module == NULL)
    {
        s_module = WinbasePrivateGetModuleHandle_Kernel32_dll();
        if (s_module == NULL)
            return proc;
    }
    proc = GetProcAddress(s_module, pszProcName);
    return proc;
}

#define ActivateActCtx IsolationAwareActivateActCtx
#define AddRefActCtx IsolationAwareAddRefActCtx
#define CreateActCtxA IsolationAwareCreateActCtxA
#define CreateActCtxW IsolationAwareCreateActCtxW
#define DeactivateActCtx IsolationAwareDeactivateActCtx
#define FindActCtxSectionGuid IsolationAwareFindActCtxSectionGuid
#define FindActCtxSectionStringA IsolationAwareFindActCtxSectionStringA
#define FindActCtxSectionStringW IsolationAwareFindActCtxSectionStringW
#define GetCurrentActCtx IsolationAwareGetCurrentActCtx
#define LoadLibraryA IsolationAwareLoadLibraryA
#define LoadLibraryExA IsolationAwareLoadLibraryExA
#define LoadLibraryExW IsolationAwareLoadLibraryExW
#define LoadLibraryW IsolationAwareLoadLibraryW
#define QueryActCtxW IsolationAwareQueryActCtxW
#define ReleaseActCtx IsolationAwareReleaseActCtx
#define ZombifyActCtx IsolationAwareZombifyActCtx

#endif /* ISOLATION_AWARE_ENABLED */
#endif /* RC */


#if defined(__cplusplus
} /* __cplusplus */
#endif
