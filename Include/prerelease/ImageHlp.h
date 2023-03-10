/*++ BUILD Version: 0001     Increment this if a change has global effects

Copyright (c) 1990-2000  Microsoft Corporation

Module Name:

    imagehlp.h

Abstract:

    This module defines the prototypes and constants required for the image
    help routines.

Revision History:

--*/

#ifndef _IMAGEHLP_
#define _IMAGEHLP_

#if _MSC_VER > 1020
#pragma once
#endif


#ifdef _WIN64
#ifndef _IMAGEHLP64
#define _IMAGEHLP64
#endif
#endif


#ifndef WINTRUST_H
#include <wintrust.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

#ifdef _IMAGEHLP_SOURCE_
#define IMAGEAPI __stdcall
#else
#define IMAGEAPI DECLSPEC_IMPORT __stdcall
#endif

#define IMAGE_SEPARATION (64*1024)

typedef struct _LOADED_IMAGE {
    PSTR                  ModuleName;
    HANDLE                hFile;
    PUCHAR                MappedAddress;
#ifdef _IMAGEHLP64
    PIMAGE_NT_HEADERS64   FileHeader;
#else
    PIMAGE_NT_HEADERS32   FileHeader;
#endif
    PIMAGE_SECTION_HEADER LastRvaSection;
    ULONG                 NumberOfSections;
    PIMAGE_SECTION_HEADER Sections;
    ULONG                 Characteristics;
    BOOLEAN               fSystemImage;
    BOOLEAN               fDOSImage;
    LIST_ENTRY            Links;
    ULONG                 SizeOfImage;
} LOADED_IMAGE, *PLOADED_IMAGE;



BOOL
IMAGEAPI
BindImage(
    IN PSTR ImageName,
    IN PSTR DllPath,
    IN PSTR SymbolPath
    );

typedef enum _IMAGEHLP_STATUS_REASON {
    BindOutOfMemory,
    BindRvaToVaFailed,
    BindNoRoomInImage,
    BindImportModuleFailed,
    BindImportProcedureFailed,
    BindImportModule,
    BindImportProcedure,
    BindForwarder,
    BindForwarderNOT,
    BindImageModified,
    BindExpandFileHeaders,
    BindImageComplete,
    BindMismatchedSymbols,
    BindSymbolsNotUpdated
} IMAGEHLP_STATUS_REASON;

typedef
BOOL
(__stdcall *PIMAGEHLP_STATUS_ROUTINE)(
    IMAGEHLP_STATUS_REASON Reason,
    PSTR ImageName,
    PSTR DllName,
    ULONG_PTR Va,
    ULONG_PTR Parameter
    );


BOOL
IMAGEAPI
BindImageEx(
    IN DWORD Flags,
    IN PSTR ImageName,
    IN PSTR DllPath,
    IN PSTR SymbolPath,
    IN PIMAGEHLP_STATUS_ROUTINE StatusRoutine
    );

#define BIND_NO_BOUND_IMPORTS  0x00000001
#define BIND_NO_UPDATE         0x00000002
#define BIND_ALL_IMAGES        0x00000004
#define BIND_CACHE_IMPORT_DLLS 0x00000008       // Cache dll's across
                                                //  calls to BindImageEx
                                                //  (same as NT 3.1->NT 4.0)

BOOL
IMAGEAPI
ReBaseImage(
    IN     PSTR CurrentImageName,
    IN     PSTR SymbolPath,
    IN     BOOL  fReBase,           // TRUE if actually rebasing, false if only summing
    IN     BOOL  fRebaseSysfileOk,  // TRUE is system images s/b rebased
    IN     BOOL  fGoingDown,        // TRUE if the image s/b rebased below the given base
    IN     ULONG CheckImageSize,    // Max size allowed  (0 if don't care)
    OUT    ULONG *OldImageSize,     // Returned from the header
    OUT    ULONG_PTR *OldImageBase, // Returned from the header
    OUT    ULONG *NewImageSize,     // Image size rounded to next separation boundary
    IN OUT ULONG_PTR *NewImageBase, // (in) Desired new address.
                                    // (out) Next address (actual if going down)
    IN     ULONG TimeStamp          // new timestamp for image, if non-zero
    );

BOOL
IMAGEAPI
ReBaseImage64(
    IN     PSTR CurrentImageName,
    IN     PSTR SymbolPath,
    IN     BOOL  fReBase,          // TRUE if actually rebasing, false if only summing
    IN     BOOL  fRebaseSysfileOk, // TRUE is system images s/b rebased
    IN     BOOL  fGoingDown,       // TRUE if the image s/b rebased below the given base
    IN     ULONG CheckImageSize,   // Max size allowed  (0 if don't care)
    OUT    ULONG *OldImageSize,    // Returned from the header
    OUT    ULONG64 *OldImageBase,  // Returned from the header
    OUT    ULONG *NewImageSize,    // Image size rounded to next separation boundary
    IN OUT ULONG64 *NewImageBase,  // (in) Desired new address.
                                   // (out) Next address (actual if going down)
    IN     ULONG TimeStamp         // new timestamp for image, if non-zero
    );

#define MAX_SYM_NAME            2000

//
// Define checksum return codes.
//

#define CHECKSUM_SUCCESS            0
#define CHECKSUM_OPEN_FAILURE       1
#define CHECKSUM_MAP_FAILURE        2
#define CHECKSUM_MAPVIEW_FAILURE    3
#define CHECKSUM_UNICODE_FAILURE    4

// Define Splitsym flags.

#define SPLITSYM_REMOVE_PRIVATE     0x00000001      // Remove CV types/symbols and Fixup debug
                                                    //  Used for creating .dbg files that ship
                                                    //  as part of the product.

#define SPLITSYM_EXTRACT_ALL        0x00000002      // Extract all debug info from image.
                                                    //  Normally, FPO is left in the image
                                                    //  to allow stack traces through the code.
                                                    //  Using this switch is similar to linking
                                                    //  with -debug:none except the .dbg file
                                                    //  exists...

#define SPLITSYM_SYMBOLPATH_IS_SRC  0x00000004      // The SymbolFilePath contains an alternate
                                                    //  path to locate the pdb.


//
// Define checksum function prototypes.
//

PIMAGE_NT_HEADERS
IMAGEAPI
CheckSumMappedFile (
    PVOID BaseAddress,
    DWORD FileLength,
    PDWORD HeaderSum,
    PDWORD CheckSum
    );

DWORD
IMAGEAPI
MapFileAndCheckSumA (
    PSTR Filename,
    PDWORD HeaderSum,
    PDWORD CheckSum
    );

DWORD
IMAGEAPI
MapFileAndCheckSumW (
    PWSTR Filename,
    PDWORD HeaderSum,
    PDWORD CheckSum
    );

#ifdef UNICODE
#define MapFileAndCheckSum  MapFileAndCheckSumW
#else
#define MapFileAndCheckSum  MapFileAndCheckSumA
#endif // !UNICODE

BOOL
IMAGEAPI
GetImageConfigInformation(
    PLOADED_IMAGE LoadedImage,
    PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
    );

DWORD
IMAGEAPI
GetImageUnusedHeaderBytes(
    PLOADED_IMAGE LoadedImage,
    PDWORD SizeUnusedHeaderBytes
    );

BOOL
IMAGEAPI
SetImageConfigInformation(
    PLOADED_IMAGE LoadedImage,
    PIMAGE_LOAD_CONFIG_DIRECTORY ImageConfigInformation
    );

// Image Integrity API's

#define CERT_PE_IMAGE_DIGEST_DEBUG_INFO         0x01
#define CERT_PE_IMAGE_DIGEST_RESOURCES          0x02
#define CERT_PE_IMAGE_DIGEST_ALL_IMPORT_INFO    0x04
#define CERT_PE_IMAGE_DIGEST_NON_PE_INFO        0x08      // include data outside the PE image

#define CERT_SECTION_TYPE_ANY                   0xFF      // Any Certificate type

typedef PVOID DIGEST_HANDLE;

typedef BOOL (WINAPI *DIGEST_FUNCTION) (DIGEST_HANDLE refdata, PBYTE pData, DWORD dwLength);

BOOL
IMAGEAPI
ImageGetDigestStream(
    IN      HANDLE  FileHandle,
    IN      DWORD   DigestLevel,
    IN      DIGEST_FUNCTION DigestFunction,
    IN      DIGEST_HANDLE   DigestHandle
    );

BOOL
IMAGEAPI
ImageAddCertificate(
    IN      HANDLE  FileHandle,
    IN      LPWIN_CERTIFICATE   Certificate,
    OUT     PDWORD  Index
    );

BOOL
IMAGEAPI
ImageRemoveCertificate(
    IN      HANDLE   FileHandle,
    IN      DWORD    Index
    );

BOOL
IMAGEAPI
ImageEnumerateCertificates(
    IN      HANDLE  FileHandle,
    IN      WORD    TypeFilter,
    OUT     PDWORD  CertificateCount,
    IN OUT  PDWORD  Indices OPTIONAL,
    IN OUT  DWORD   IndexCount  OPTIONAL
    );

BOOL
IMAGEAPI
ImageGetCertificateData(
    IN      HANDLE  FileHandle,
    IN      DWORD   CertificateIndex,
    OUT     LPWIN_CERTIFICATE Certificate,
    IN OUT  PDWORD  RequiredLength
    );

BOOL
IMAGEAPI
ImageGetCertificateHeader(
    IN      HANDLE  FileHandle,
    IN      DWORD   CertificateIndex,
    IN OUT  LPWIN_CERTIFICATE Certificateheader
    );

PLOADED_IMAGE
IMAGEAPI
ImageLoad(
    PSTR DllName,
    PSTR DllPath
    );

BOOL
IMAGEAPI
ImageUnload(
    PLOADED_IMAGE LoadedImage
    );

BOOL
IMAGEAPI
MapAndLoad(
    PSTR ImageName,
    PSTR DllPath,
    PLOADED_IMAGE LoadedImage,
    BOOL DotDll,
    BOOL ReadOnly
    );

BOOL
IMAGEAPI
UnMapAndLoad(
    PLOADED_IMAGE LoadedImage
    );

BOOL
IMAGEAPI
TouchFileTimes (
    HANDLE FileHandle,
    PSYSTEMTIME pSystemTime
    );

BOOL
IMAGEAPI
SplitSymbols (
    PSTR ImageName,
    PSTR SymbolsPath,
    PSTR SymbolFilePath,
    DWORD Flags                 // Combination of flags above
    );

BOOL
IMAGEAPI
UpdateDebugInfoFile(
    PSTR ImageFileName,
    PSTR SymbolPath,
    PSTR DebugFilePath,
    PIMAGE_NT_HEADERS32 NtHeaders
    );

BOOL
IMAGEAPI
UpdateDebugInfoFileEx(
    PSTR ImageFileName,
    PSTR SymbolPath,
    PSTR DebugFilePath,
    PIMAGE_NT_HEADERS32 NtHeaders,
    DWORD OldChecksum
    );


HANDLE
IMAGEAPI
FindDebugInfoFile (
    PSTR FileName,
    PSTR SymbolPath,
    PSTR DebugFilePath
    );

typedef BOOL
(CALLBACK *PFIND_DEBUG_FILE_CALLBACK)(
    HANDLE FileHandle,
    PSTR FileName,
    PVOID CallerData
    );

HANDLE
IMAGEAPI
FindDebugInfoFileEx (
    PSTR FileName,
    PSTR SymbolPath,
    PSTR DebugFilePath,
    PFIND_DEBUG_FILE_CALLBACK Callback,
    PVOID CallerData
    );

typedef BOOL
(CALLBACK *PFINDFILEINPATHCALLBACK)(
    PSTR  filename,
    PVOID context
    );

BOOL
IMAGEAPI
SymFindFileInPath(
    HANDLE hprocess,
    LPSTR  SearchPath,
    LPSTR  FileName,
    PVOID  id,
    DWORD  two,
    DWORD  three,
    DWORD  flags,
    LPSTR  FilePath,
    PFINDFILEINPATHCALLBACK callback,
    PVOID  context
    );

// FindFileInPath exists only for backwards compatibility
// with a pre-release version documented in an MSDN release.
// You should use SymFindFileInPath if you want to maintain
// future compatibility.

BOOL
IMAGEAPI
FindFileInPath(
    HANDLE hprocess,
    LPSTR  SearchPath,
    LPSTR  FileName,
    PVOID  id,
    DWORD  two,
    DWORD  three,
    DWORD  flags,
    LPSTR  FilePath
    );

BOOL
IMAGEAPI
FindFileInSearchPath(
    HANDLE hprocess,
    LPSTR  SearchPath,
    LPSTR  FileName,
    DWORD  one,
    DWORD  two,
    DWORD  three,
    LPSTR  FilePath
    );

HANDLE
IMAGEAPI
FindExecutableImage(
    PSTR FileName,
    PSTR SymbolPath,
    PSTR ImageFilePath
    );

typedef BOOL
(CALLBACK *PFIND_EXE_FILE_CALLBACK)(
    HANDLE FileHandle,
    PSTR FileName,
    PVOID CallerData
    );

HANDLE
IMAGEAPI
FindExecutableImageEx(
    PSTR FileName,
    PSTR SymbolPath,
    PSTR ImageFilePath,
    PFIND_EXE_FILE_CALLBACK Callback,
    PVOID CallerData
    );

PIMAGE_NT_HEADERS
IMAGEAPI
ImageNtHeader (
    IN PVOID Base
    );

PVOID
IMAGEAPI
ImageDirectoryEntryToDataEx (
    IN PVOID Base,
    IN BOOLEAN MappedAsImage,
    IN USHORT DirectoryEntry,
    OUT PULONG Size,
    OUT PIMAGE_SECTION_HEADER *FoundHeader OPTIONAL
    );

PVOID
IMAGEAPI
ImageDirectoryEntryToData (
    IN PVOID Base,
    IN BOOLEAN MappedAsImage,
    IN USHORT DirectoryEntry,
    OUT PULONG Size
    );

PIMAGE_SECTION_HEADER
IMAGEAPI
ImageRvaToSection(
    IN PIMAGE_NT_HEADERS NtHeaders,
    IN PVOID Base,
    IN ULONG Rva
    );

PVOID
IMAGEAPI
ImageRvaToVa(
    IN PIMAGE_NT_HEADERS NtHeaders,
    IN PVOID Base,
    IN ULONG Rva,
    IN OUT PIMAGE_SECTION_HEADER *LastRvaSection
    );

// Symbol server exports

typedef BOOL (*PSYMBOLSERVERPROC)(LPCSTR, LPCSTR, PVOID, DWORD, DWORD, LPSTR);
typedef BOOL (*PSYMBOLSERVEROPENPROC)(VOID);
typedef BOOL (*PSYMBOLSERVERCLOSEPROC)(VOID);
typedef BOOL (*PSYMBOLSERVERSETOPTIONSPROC)(UINT_PTR, ULONG64);
typedef BOOL (CALLBACK *PSYMBOLSERVERCALLBACKPROC)(UINT_PTR action, ULONG64 data, ULONG64 context);
typedef UINT_PTR (*PSYMBOLSERVERGETOPTIONSPROC)();

#define SSRVOPT_CALLBACK  0x1
#define SSRVOPT_DWORD     0x2
#define SSRVOPT_DWORDPTR  0x4
#define SSRVOPT_GUIDPTR   0x8
#define SSRVOPT_RESET    ((ULONG_PTR)-1)

#define SSRVACTION_TRACE 1


#ifndef _WIN64
// This api won't be ported to Win64 - Fix your code.

typedef struct _IMAGE_DEBUG_INFORMATION {
    LIST_ENTRY List;
    DWORD ReservedSize;
    PVOID ReservedMappedBase;
    USHORT ReservedMachine;
    USHORT ReservedCharacteristics;
    DWORD ReservedCheckSum;
    DWORD ImageBase;
    DWORD SizeOfImage;

    DWORD ReservedNumberOfSections;
    PIMAGE_SECTION_HEADER ReservedSections;

    DWORD ReservedExportedNamesSize;
    PSTR ReservedExportedNames;

    DWORD ReservedNumberOfFunctionTableEntries;
    PIMAGE_FUNCTION_ENTRY ReservedFunctionTableEntries;
    DWORD ReservedLowestFunctionStartingAddress;
    DWORD ReservedHighestFunctionEndingAddress;

    DWORD ReservedNumberOfFpoTableEntries;
    PFPO_DATA ReservedFpoTableEntries;

    DWORD SizeOfCoffSymbols;
    PIMAGE_COFF_SYMBOLS_HEADER CoffSymbols;

    DWORD ReservedSizeOfCodeViewSymbols;
    PVOID ReservedCodeViewSymbols;

    PSTR ImageFilePath;
    PSTR ImageFileName;
    PSTR ReservedDebugFilePath;

    DWORD ReservedTimeDateStamp;

    BOOL  ReservedRomImage;
    PIMAGE_DEBUG_DIRECTORY ReservedDebugDirectory;
    DWORD ReservedNumberOfDebugDirectories;

    DWORD ReservedOriginalFunctionTableBaseAddress;

    DWORD Reserved[ 2 ];

} IMAGE_DEBUG_INFORMATION, *PIMAGE_DEBUG_INFORMATION;


PIMAGE_DEBUG_INFORMATION
IMAGEAPI
MapDebugInformation(
    HANDLE FileHandle,
    PSTR FileName,
    PSTR SymbolPath,
    DWORD ImageBase
    );

BOOL
IMAGEAPI
UnmapDebugInformation(
    PIMAGE_DEBUG_INFORMATION DebugInfo
    );

#endif

BOOL
IMAGEAPI
SearchTreeForFile(
    PSTR RootPath,
    PSTR InputPathName,
    PSTR OutputPathBuffer
    );

BOOL
IMAGEAPI
MakeSureDirectoryPathExists(
    PCSTR DirPath
    );

//
// UnDecorateSymbolName Flags
//

#define UNDNAME_COMPLETE                 (0x0000)  // Enable full undecoration
#define UNDNAME_NO_LEADING_UNDERSCORES   (0x0001)  // Remove leading underscores from MS extended keywords
#define UNDNAME_NO_MS_KEYWORDS           (0x0002)  // Disable expansion of MS extended keywords
#define UNDNAME_NO_FUNCTION_RETURNS      (0x0004)  // Disable expansion of return type for primary declaration
#define UNDNAME_NO_ALLOCATION_MODEL      (0x0008)  // Disable expansion of the declaration model
#define UNDNAME_NO_ALLOCATION_LANGUAGE   (0x0010)  // Disable expansion of the declaration language specifier
#define UNDNAME_NO_MS_THISTYPE           (0x0020)  // NYI Disable expansion of MS keywords on the 'this' type for primary declaration
#define UNDNAME_NO_CV_THISTYPE           (0x0040)  // NYI Disable expansion of CV modifiers on the 'this' type for primary declaration
#define UNDNAME_NO_THISTYPE              (0x0060)  // Disable all modifiers on the 'this' type
#define UNDNAME_NO_ACCESS_SPECIFIERS     (0x0080)  // Disable expansion of access specifiers for members
#define UNDNAME_NO_THROW_SIGNATURES      (0x0100)  // Disable expansion of 'throw-signatures' for functions and pointers to functions
#define UNDNAME_NO_MEMBER_TYPE           (0x0200)  // Disable expansion of 'static' or 'virtual'ness of members
#define UNDNAME_NO_RETURN_UDT_MODEL      (0x0400)  // Disable expansion of MS model for UDT returns
#define UNDNAME_32_BIT_DECODE            (0x0800)  // Undecorate 32-bit decorated names
#define UNDNAME_NAME_ONLY                (0x1000)  // Crack only the name for primary declaration;
                                                                                                   //  return just [scope::]name.  Does expand template params
#define UNDNAME_NO_ARGUMENTS             (0x2000)  // Don't undecorate arguments to function
#define UNDNAME_NO_SPECIAL_SYMS          (0x4000)  // Don't undecorate special names (v-table, vcall, vector xxx, metatype, etc)

DWORD
IMAGEAPI
WINAPI
UnDecorateSymbolName(
    PCSTR   DecoratedName,         // Name to undecorate
    PSTR    UnDecoratedName,       // If NULL, it will be allocated
    DWORD    UndecoratedLength,     // The maximym length
    DWORD    Flags                  // See above.
    );

//
// StackWalking API
//

typedef enum {
    AddrMode1616,
    AddrMode1632,
    AddrModeReal,
    AddrModeFlat
} ADDRESS_MODE;

typedef struct _tagADDRESS64 {
    DWORD64       Offset;
    WORD          Segment;
    ADDRESS_MODE  Mode;
} ADDRESS64, *LPADDRESS64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define ADDRESS ADDRESS64
#define LPADDRESS LPADDRESS64
#else
typedef struct _tagADDRESS {
    DWORD         Offset;
    WORD          Segment;
    ADDRESS_MODE  Mode;
} ADDRESS, *LPADDRESS;

__inline
void
Address32To64(
    LPADDRESS a32,
    LPADDRESS64 a64
    )
{
    a64->Offset = (ULONG64)(LONG64)(LONG)a32->Offset;
    a64->Segment = a32->Segment;
    a64->Mode = a32->Mode;
}

__inline
void
Address64To32(
    LPADDRESS64 a64,
    LPADDRESS a32
    )
{
    a32->Offset = (ULONG)a64->Offset;
    a32->Segment = a64->Segment;
    a32->Mode = a64->Mode;
}
#endif

//
// This structure is included in the STACKFRAME structure,
// and is used to trace through usermode callbacks in a thread's
// kernel stack.  The values must be copied by the kernel debugger
// from the DBGKD_GET_VERSION and WAIT_STATE_CHANGE packets.
//

//
// New KDHELP structure for 64 bit system support.
// This structure is preferred in new code.
//
typedef struct _KDHELP64 {

    //
    // address of kernel thread object, as provided in the
    // WAIT_STATE_CHANGE packet.
    //
    DWORD64   Thread;

    //
    // offset in thread object to pointer to the current callback frame
    // in kernel stack.
    //
    DWORD   ThCallbackStack;

    //
    // offset in thread object to pointer to the current callback backing
    // store frame in kernel stack.
    //
    DWORD   ThCallbackBStore;

    //
    // offsets to values in frame:
    //
    // address of next callback frame
    DWORD   NextCallback;

    // address of saved frame pointer (if applicable)
    DWORD   FramePointer;


    //
    // Address of the kernel function that calls out to user mode
    //
    DWORD64   KiCallUserMode;

    //
    // Address of the user mode dispatcher function
    //
    DWORD64   KeUserCallbackDispatcher;

    //
    // Lowest kernel mode address
    //
    DWORD64   SystemRangeStart;

    DWORD64  Reserved[8];

} KDHELP64, *PKDHELP64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define KDHELP KDHELP64
#define PKDHELP PKDHELP64
#else
typedef struct _KDHELP {

    //
    // address of kernel thread object, as provided in the
    // WAIT_STATE_CHANGE packet.
    //
    DWORD   Thread;

    //
    // offset in thread object to pointer to the current callback frame
    // in kernel stack.
    //
    DWORD   ThCallbackStack;

    //
    // offsets to values in frame:
    //
    // address of next callback frame
    DWORD   NextCallback;

    // address of saved frame pointer (if applicable)
    DWORD   FramePointer;

    //
    // Address of the kernel function that calls out to user mode
    //
    DWORD   KiCallUserMode;

    //
    // Address of the user mode dispatcher function
    //
    DWORD   KeUserCallbackDispatcher;

    //
    // Lowest kernel mode address
    //
    DWORD   SystemRangeStart;

    //
    // offset in thread object to pointer to the current callback backing
    // store frame in kernel stack.
    //
    DWORD   ThCallbackBStore;

    DWORD  Reserved[8];

} KDHELP, *PKDHELP;

__inline
void
KdHelp32To64(
    PKDHELP p32,
    PKDHELP64 p64
    )
{
    p64->Thread = p32->Thread;
    p64->ThCallbackStack = p32->ThCallbackStack;
    p64->NextCallback = p32->NextCallback;
    p64->FramePointer = p32->FramePointer;
    p64->KiCallUserMode = p32->KiCallUserMode;
    p64->KeUserCallbackDispatcher = p32->KeUserCallbackDispatcher;
    p64->SystemRangeStart = p32->SystemRangeStart;
}
#endif

typedef struct _tagSTACKFRAME64 {
    ADDRESS64   AddrPC;               // program counter
    ADDRESS64   AddrReturn;           // return address
    ADDRESS64   AddrFrame;            // frame pointer
    ADDRESS64   AddrStack;            // stack pointer
    ADDRESS64   AddrBStore;           // backing store pointer
    PVOID       FuncTableEntry;       // pointer to pdata/fpo or NULL
    DWORD64     Params[4];            // possible arguments to the function
    BOOL        Far;                  // WOW far call
    BOOL        Virtual;              // is this a virtual frame?
    DWORD64     Reserved[3];
    KDHELP64    KdHelp;
} STACKFRAME64, *LPSTACKFRAME64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define STACKFRAME STACKFRAME64
#define LPSTACKFRAME LPSTACKFRAME64
#else
typedef struct _tagSTACKFRAME {
    ADDRESS     AddrPC;               // program counter
    ADDRESS     AddrReturn;           // return address
    ADDRESS     AddrFrame;            // frame pointer
    ADDRESS     AddrStack;            // stack pointer
    PVOID       FuncTableEntry;       // pointer to pdata/fpo or NULL
    DWORD       Params[4];            // possible arguments to the function
    BOOL        Far;                  // WOW far call
    BOOL        Virtual;              // is this a virtual frame?
    DWORD       Reserved[3];
    KDHELP      KdHelp;
    ADDRESS     AddrBStore;           // backing store pointer
} STACKFRAME, *LPSTACKFRAME;
#endif


typedef
BOOL
(__stdcall *PREAD_PROCESS_MEMORY_ROUTINE64)(
    HANDLE      hProcess,
    DWORD64     qwBaseAddress,
    PVOID       lpBuffer,
    DWORD       nSize,
    LPDWORD     lpNumberOfBytesRead
    );

typedef
PVOID
(__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE64)(
    HANDLE  hProcess,
    DWORD64 AddrBase
    );

typedef
DWORD64
(__stdcall *PGET_MODULE_BASE_ROUTINE64)(
    HANDLE  hProcess,
    DWORD64 Address
    );

typedef
DWORD64
(__stdcall *PTRANSLATE_ADDRESS_ROUTINE64)(
    HANDLE    hProcess,
    HANDLE    hThread,
    LPADDRESS64 lpaddr
    );

BOOL
IMAGEAPI
StackWalk64(
    DWORD                             MachineType,
    HANDLE                            hProcess,
    HANDLE                            hThread,
    LPSTACKFRAME64                    StackFrame,
    PVOID                             ContextRecord,
    PREAD_PROCESS_MEMORY_ROUTINE64    ReadMemoryRoutine,
    PFUNCTION_TABLE_ACCESS_ROUTINE64  FunctionTableAccessRoutine,
    PGET_MODULE_BASE_ROUTINE64        GetModuleBaseRoutine,
    PTRANSLATE_ADDRESS_ROUTINE64      TranslateAddress
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)

#define PREAD_PROCESS_MEMORY_ROUTINE PREAD_PROCESS_MEMORY_ROUTINE64
#define PFUNCTION_TABLE_ACCESS_ROUTINE PFUNCTION_TABLE_ACCESS_ROUTINE64
#define PGET_MODULE_BASE_ROUTINE PGET_MODULE_BASE_ROUTINE64
#define PTRANSLATE_ADDRESS_ROUTINE PTRANSLATE_ADDRESS_ROUTINE64

#define StackWalk StackWalk64

#else

typedef
BOOL
(__stdcall *PREAD_PROCESS_MEMORY_ROUTINE)(
    HANDLE  hProcess,
    DWORD   lpBaseAddress,
    PVOID   lpBuffer,
    DWORD   nSize,
    PDWORD  lpNumberOfBytesRead
    );

typedef
PVOID
(__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE)(
    HANDLE  hProcess,
    DWORD   AddrBase
    );

typedef
DWORD
(__stdcall *PGET_MODULE_BASE_ROUTINE)(
    HANDLE  hProcess,
    DWORD   Address
    );

typedef
DWORD
(__stdcall *PTRANSLATE_ADDRESS_ROUTINE)(
    HANDLE    hProcess,
    HANDLE    hThread,
    LPADDRESS lpaddr
    );

BOOL
IMAGEAPI
StackWalk(
    DWORD                             MachineType,
    HANDLE                            hProcess,
    HANDLE                            hThread,
    LPSTACKFRAME                      StackFrame,
    PVOID                             ContextRecord,
    PREAD_PROCESS_MEMORY_ROUTINE      ReadMemoryRoutine,
    PFUNCTION_TABLE_ACCESS_ROUTINE    FunctionTableAccessRoutine,
    PGET_MODULE_BASE_ROUTINE          GetModuleBaseRoutine,
    PTRANSLATE_ADDRESS_ROUTINE        TranslateAddress
    );

#endif


#define API_VERSION_NUMBER 9

typedef struct API_VERSION {
    USHORT  MajorVersion;
    USHORT  MinorVersion;
    USHORT  Revision;
    USHORT  Reserved;
} API_VERSION, *LPAPI_VERSION;

LPAPI_VERSION
IMAGEAPI
ImagehlpApiVersion(
    VOID
    );

LPAPI_VERSION
IMAGEAPI
ImagehlpApiVersionEx(
    LPAPI_VERSION AppVersion
    );

DWORD
IMAGEAPI
GetTimestampForLoadedLibrary(
    HMODULE Module
    );

//
// typedefs for function pointers
//
typedef BOOL
(CALLBACK *PSYM_ENUMMODULES_CALLBACK64)(
    PSTR ModuleName,
    DWORD64 BaseOfDll,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK64)(
    PSTR SymbolName,
    DWORD64 SymbolAddress,
    ULONG SymbolSize,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK64W)(
    PWSTR SymbolName,
    DWORD64 SymbolAddress,
    ULONG SymbolSize,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PENUMLOADED_MODULES_CALLBACK64)(
    PSTR ModuleName,
    DWORD64 ModuleBase,
    ULONG ModuleSize,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYMBOL_REGISTERED_CALLBACK64)(
    HANDLE  hProcess,
    ULONG   ActionCode,
    ULONG64 CallbackData,
    ULONG64 UserContext
    );

typedef
PVOID
(CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK)(
    HANDLE  hProcess,
    DWORD   AddrBase,
    PVOID   UserContext
    );

typedef
PVOID
(CALLBACK *PSYMBOL_FUNCENTRY_CALLBACK64)(
    HANDLE  hProcess,
    ULONG64 AddrBase,
    ULONG64 UserContext
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)

#define PSYM_ENUMMODULES_CALLBACK PSYM_ENUMMODULES_CALLBACK64
#define PSYM_ENUMSYMBOLS_CALLBACK PSYM_ENUMSYMBOLS_CALLBACK64
#define PSYM_ENUMSYMBOLS_CALLBACKW PSYM_ENUMSYMBOLS_CALLBACK64W
#define PENUMLOADED_MODULES_CALLBACK PENUMLOADED_MODULES_CALLBACK64
#define PSYMBOL_REGISTERED_CALLBACK PSYMBOL_REGISTERED_CALLBACK64
#define PSYMBOL_FUNCENTRY_CALLBACK PSYMBOL_FUNCENTRY_CALLBACK64

#else

typedef BOOL
(CALLBACK *PSYM_ENUMMODULES_CALLBACK)(
    PSTR  ModuleName,
    ULONG BaseOfDll,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACK)(
    PSTR  SymbolName,
    ULONG SymbolAddress,
    ULONG SymbolSize,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYM_ENUMSYMBOLS_CALLBACKW)(
    PWSTR  SymbolName,
    ULONG SymbolAddress,
    ULONG SymbolSize,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PENUMLOADED_MODULES_CALLBACK)(
    PSTR  ModuleName,
    ULONG ModuleBase,
    ULONG ModuleSize,
    PVOID UserContext
    );

typedef BOOL
(CALLBACK *PSYMBOL_REGISTERED_CALLBACK)(
    HANDLE  hProcess,
    ULONG   ActionCode,
    PVOID   CallbackData,
    PVOID   UserContext
    );

#endif


//
// symbol flags
//

#define SYMF_OMAP_GENERATED   0x00000001
#define SYMF_OMAP_MODIFIED    0x00000002
#ifndef _DBGHELP_USER_GENERATED_SYMBOLS_NOTSUPPORTED
#define SYMF_USER_GENERATED   0x00000004
#endif // !_DBGHELP_USER_GENERATED_SYMBOLS_NOTSUPPORTED
#define SYMF_REGISTER         0x00000008
#define SYMF_REGREL           0x00000010
#define SYMF_FRAMEREL         0x00000020
#define SYMF_PARAMETER        0x00000040
#define SYMF_LOCAL            0x00000080
//
// symbol type enumeration
//
typedef enum {
    SymNone = 0,
    SymCoff,
    SymCv,
    SymPdb,
    SymExport,
    SymDeferred,
    SymSym,       // .sym file
    SymDia,
    NumSymTypes
} SYM_TYPE;

//
// symbol data structure
//

typedef struct _IMAGEHLP_SYMBOL64 {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_SYMBOL64)
    DWORD64                     Address;                // virtual address including dll base address
    DWORD                       Size;                   // estimated size of symbol, can be zero
    DWORD                       Flags;                  // info about the symbols, see the SYMF defines
    DWORD                       MaxNameLength;          // maximum size of symbol name in 'Name'
    CHAR                        Name[1];                // symbol name (null terminated string)
} IMAGEHLP_SYMBOL64, *PIMAGEHLP_SYMBOL64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_SYMBOL IMAGEHLP_SYMBOL64
#define PIMAGEHLP_SYMBOL PIMAGEHLP_SYMBOL64
#else
typedef struct _IMAGEHLP_SYMBOL {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_SYMBOL)
    DWORD                       Address;                // virtual address including dll base address
    DWORD                       Size;                   // estimated size of symbol, can be zero
    DWORD                       Flags;                  // info about the symbols, see the SYMF defines
    DWORD                       MaxNameLength;          // maximum size of symbol name in 'Name'
    CHAR                        Name[1];                // symbol name (null terminated string)
} IMAGEHLP_SYMBOL, *PIMAGEHLP_SYMBOL;
#endif

//
// module data structure
//

typedef struct _IMAGEHLP_MODULE64 {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_MODULE64)
    DWORD64                     BaseOfImage;            // base load address of module
    DWORD                       ImageSize;              // virtual size of the loaded module
    DWORD                       TimeDateStamp;          // date/time stamp from pe header
    DWORD                       CheckSum;               // checksum from the pe header
    DWORD                       NumSyms;                // number of symbols in the symbol table
    SYM_TYPE                    SymType;                // type of symbols loaded
    CHAR                        ModuleName[32];         // module name
    CHAR                        ImageName[256];         // image name
    CHAR                        LoadedImageName[256];   // symbol file name
} IMAGEHLP_MODULE64, *PIMAGEHLP_MODULE64;

typedef struct _IMAGEHLP_MODULE64W {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_MODULE64)
    DWORD64                     BaseOfImage;            // base load address of module
    DWORD                       ImageSize;              // virtual size of the loaded module
    DWORD                       TimeDateStamp;          // date/time stamp from pe header
    DWORD                       CheckSum;               // checksum from the pe header
    DWORD                       NumSyms;                // number of symbols in the symbol table
    SYM_TYPE                    SymType;                // type of symbols loaded
    WCHAR                       ModuleName[32];         // module name
    WCHAR                       ImageName[256];         // image name
    WCHAR                       LoadedImageName[256];   // symbol file name
} IMAGEHLP_MODULEW64, *PIMAGEHLP_MODULEW64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_MODULE IMAGEHLP_MODULE64
#define PIMAGEHLP_MODULE PIMAGEHLP_MODULE64
#define IMAGEHLP_MODULEW IMAGEHLP_MODULEW64
#define PIMAGEHLP_MODULEW PIMAGEHLP_MODULEW64
#else
typedef struct _IMAGEHLP_MODULE {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_MODULE)
    DWORD                       BaseOfImage;            // base load address of module
    DWORD                       ImageSize;              // virtual size of the loaded module
    DWORD                       TimeDateStamp;          // date/time stamp from pe header
    DWORD                       CheckSum;               // checksum from the pe header
    DWORD                       NumSyms;                // number of symbols in the symbol table
    SYM_TYPE                    SymType;                // type of symbols loaded
    CHAR                        ModuleName[32];         // module name
    CHAR                        ImageName[256];         // image name
    CHAR                        LoadedImageName[256];   // symbol file name
} IMAGEHLP_MODULE, *PIMAGEHLP_MODULE;

typedef struct _IMAGEHLP_MODULEW {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_MODULE)
    DWORD                       BaseOfImage;            // base load address of module
    DWORD                       ImageSize;              // virtual size of the loaded module
    DWORD                       TimeDateStamp;          // date/time stamp from pe header
    DWORD                       CheckSum;               // checksum from the pe header
    DWORD                       NumSyms;                // number of symbols in the symbol table
    SYM_TYPE                    SymType;                // type of symbols loaded
    WCHAR                       ModuleName[32];         // module name
    WCHAR                       ImageName[256];         // image name
    WCHAR                       LoadedImageName[256];   // symbol file name
} IMAGEHLP_MODULEW, *PIMAGEHLP_MODULEW;
#endif

//
// source file line data structure
//

typedef struct _IMAGEHLP_LINE64 {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_LINE64)
    PVOID                       Key;                    // internal
    DWORD                       LineNumber;             // line number in file
    PCHAR                       FileName;               // full filename
    DWORD64                     Address;                // first instruction of line
} IMAGEHLP_LINE64, *PIMAGEHLP_LINE64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_LINE IMAGEHLP_LINE64
#define PIMAGEHLP_LINE PIMAGEHLP_LINE64
#else
typedef struct _IMAGEHLP_LINE {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_LINE)
    PVOID                       Key;                    // internal
    DWORD                       LineNumber;             // line number in file
    PCHAR                       FileName;               // full filename
    DWORD                       Address;                // first instruction of line
} IMAGEHLP_LINE, *PIMAGEHLP_LINE;
#endif

//
// data structures used for registered symbol callbacks
//

#define CBA_DEFERRED_SYMBOL_LOAD_START          0x00000001
#define CBA_DEFERRED_SYMBOL_LOAD_COMPLETE       0x00000002
#define CBA_DEFERRED_SYMBOL_LOAD_FAILURE        0x00000003
#define CBA_SYMBOLS_UNLOADED                    0x00000004
#define CBA_DUPLICATE_SYMBOL                    0x00000005
#define CBA_READ_MEMORY                         0x00000006
#define CBA_DEFERRED_SYMBOL_LOAD_CANCEL         0x00000007
#define CBA_SET_OPTIONS                         0x00000008
#define CBA_DEBUG_INFO                          0x10000000

typedef struct _IMAGEHLP_CBA_READ_MEMORY {
    DWORD64   addr;                                     // address to read from
    PVOID     buf;                                      // buffer to read to
    DWORD     bytes;                                    // amount of bytes to read
    DWORD    *bytesread;                                // pointer to store amount of bytes read
} IMAGEHLP_CBA_READ_MEMORY, *PIMAGEHLP_CBA_READ_MEMORY;

typedef struct _IMAGEHLP_DEFERRED_SYMBOL_LOAD64 {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD64)
    DWORD64                     BaseOfImage;            // base load address of module
    DWORD                       CheckSum;               // checksum from the pe header
    DWORD                       TimeDateStamp;          // date/time stamp from pe header
    CHAR                        FileName[MAX_PATH];     // symbols file or image name
    BOOLEAN                     Reparse;                // load failure reparse
} IMAGEHLP_DEFERRED_SYMBOL_LOAD64, *PIMAGEHLP_DEFERRED_SYMBOL_LOAD64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_DEFERRED_SYMBOL_LOAD IMAGEHLP_DEFERRED_SYMBOL_LOAD64
#define PIMAGEHLP_DEFERRED_SYMBOL_LOAD PIMAGEHLP_DEFERRED_SYMBOL_LOAD64
#else
typedef struct _IMAGEHLP_DEFERRED_SYMBOL_LOAD {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_DEFERRED_SYMBOL_LOAD)
    DWORD                       BaseOfImage;            // base load address of module
    DWORD                       CheckSum;               // checksum from the pe header
    DWORD                       TimeDateStamp;          // date/time stamp from pe header
    CHAR                        FileName[MAX_PATH];     // symbols file or image name
    BOOLEAN                     Reparse;                // load failure reparse
} IMAGEHLP_DEFERRED_SYMBOL_LOAD, *PIMAGEHLP_DEFERRED_SYMBOL_LOAD;
#endif

typedef struct _IMAGEHLP_DUPLICATE_SYMBOL64 {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_DUPLICATE_SYMBOL64)
    DWORD                       NumberOfDups;           // number of duplicates in the Symbol array
    PIMAGEHLP_SYMBOL64          Symbol;                 // array of duplicate symbols
    DWORD                       SelectedSymbol;         // symbol selected (-1 to start)
} IMAGEHLP_DUPLICATE_SYMBOL64, *PIMAGEHLP_DUPLICATE_SYMBOL64;

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define IMAGEHLP_DUPLICATE_SYMBOL IMAGEHLP_DUPLICATE_SYMBOL64
#define PIMAGEHLP_DUPLICATE_SYMBOL PIMAGEHLP_DUPLICATE_SYMBOL64
#else
typedef struct _IMAGEHLP_DUPLICATE_SYMBOL {
    DWORD                       SizeOfStruct;           // set to sizeof(IMAGEHLP_DUPLICATE_SYMBOL)
    DWORD                       NumberOfDups;           // number of duplicates in the Symbol array
    PIMAGEHLP_SYMBOL            Symbol;                 // array of duplicate symbols
    DWORD                       SelectedSymbol;         // symbol selected (-1 to start)
} IMAGEHLP_DUPLICATE_SYMBOL, *PIMAGEHLP_DUPLICATE_SYMBOL;
#endif


//
// options that are set/returned by SymSetOptions() & SymGetOptions()
// these are used as a mask
//
#define SYMOPT_CASE_INSENSITIVE     0x00000001
#define SYMOPT_UNDNAME              0x00000002
#define SYMOPT_DEFERRED_LOADS       0x00000004
#define SYMOPT_NO_CPP               0x00000008
#define SYMOPT_LOAD_LINES           0x00000010
#define SYMOPT_OMAP_FIND_NEAREST    0x00000020
#define SYMOPT_LOAD_ANYTHING        0x00000040
#define SYMOPT_IGNORE_CVREC         0x00000080
#define SYMOPT_NO_UNQUALIFIED_LOADS 0x00000100
#define SYMOPT_FAIL_CRITICAL_ERRORS 0x00000200
#define SYMOPT_EXACT_SYMBOLS        0x00000400
#define SYMOPT_DEBUG                0x80000000


DWORD
IMAGEAPI
SymSetOptions(
    IN DWORD   SymOptions
    );

DWORD
IMAGEAPI
SymGetOptions(
    VOID
    );

BOOL
IMAGEAPI
SymCleanup(
    IN HANDLE hProcess
    );

BOOL
IMAGEAPI
SymEnumerateModules64(
    IN HANDLE                       hProcess,
    IN PSYM_ENUMMODULES_CALLBACK64  EnumModulesCallback,
    IN PVOID                        UserContext
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymEnumerateModules SymEnumerateModules64
#else
BOOL
IMAGEAPI
SymEnumerateModules(
    IN HANDLE                     hProcess,
    IN PSYM_ENUMMODULES_CALLBACK  EnumModulesCallback,
    IN PVOID                      UserContext
    );
#endif

BOOL
IMAGEAPI
SymEnumerateSymbols64(
    IN HANDLE                       hProcess,
    IN DWORD64                      BaseOfDll,
    IN PSYM_ENUMSYMBOLS_CALLBACK64  EnumSymbolsCallback,
    IN PVOID                        UserContext
    );

BOOL
IMAGEAPI
SymEnumerateSymbolsW64(
    IN HANDLE                       hProcess,
    IN DWORD64                      BaseOfDll,
    IN PSYM_ENUMSYMBOLS_CALLBACK64W EnumSymbolsCallback,
    IN PVOID                        UserContext
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymEnumerateSymbols SymEnumerateSymbols64
#define SymEnumerateSymbolsW SymEnumerateSymbolsW64
#else
BOOL
IMAGEAPI
SymEnumerateSymbols(
    IN HANDLE                     hProcess,
    IN DWORD                      BaseOfDll,
    IN PSYM_ENUMSYMBOLS_CALLBACK  EnumSymbolsCallback,
    IN PVOID                      UserContext
    );

BOOL
IMAGEAPI
SymEnumerateSymbolsW(
    IN HANDLE                       hProcess,
    IN DWORD                        BaseOfDll,
    IN PSYM_ENUMSYMBOLS_CALLBACKW   EnumSymbolsCallback,
    IN PVOID                        UserContext
    );
#endif

BOOL
IMAGEAPI
EnumerateLoadedModules64(
    IN HANDLE                           hProcess,
    IN PENUMLOADED_MODULES_CALLBACK64   EnumLoadedModulesCallback,
    IN PVOID                            UserContext
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define EnumerateLoadedModules EnumerateLoadedModules64
#else
BOOL
IMAGEAPI
EnumerateLoadedModules(
    IN HANDLE                         hProcess,
    IN PENUMLOADED_MODULES_CALLBACK   EnumLoadedModulesCallback,
    IN PVOID                          UserContext
    );
#endif

PVOID
IMAGEAPI
SymFunctionTableAccess64(
    HANDLE  hProcess,
    DWORD64 AddrBase
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymFunctionTableAccess SymFunctionTableAccess64
#else
PVOID
IMAGEAPI
SymFunctionTableAccess(
    HANDLE  hProcess,
    DWORD   AddrBase
    );
#endif

BOOL
IMAGEAPI
SymGetModuleInfo64(
    IN  HANDLE                  hProcess,
    IN  DWORD64                 qwAddr,
    OUT PIMAGEHLP_MODULE64      ModuleInfo
    );

BOOL
IMAGEAPI
SymGetModuleInfoW64(
    IN  HANDLE                  hProcess,
    IN  DWORD64                 qwAddr,
    OUT PIMAGEHLP_MODULEW64     ModuleInfo
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetModuleInfo   SymGetModuleInfo64
#define SymGetModuleInfoW  SymGetModuleInfoW64
#else
BOOL
IMAGEAPI
SymGetModuleInfo(
    IN  HANDLE              hProcess,
    IN  DWORD               dwAddr,
    OUT PIMAGEHLP_MODULE  ModuleInfo
    );

BOOL
IMAGEAPI
SymGetModuleInfoW(
    IN  HANDLE              hProcess,
    IN  DWORD               dwAddr,
    OUT PIMAGEHLP_MODULEW  ModuleInfo
    );
#endif

DWORD64
IMAGEAPI
SymGetModuleBase64(
    IN  HANDLE              hProcess,
    IN  DWORD64             qwAddr
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetModuleBase SymGetModuleBase64
#else
DWORD
IMAGEAPI
SymGetModuleBase(
    IN  HANDLE              hProcess,
    IN  DWORD               dwAddr
    );
#endif

BOOL
IMAGEAPI
SymGetSymFromAddr64(
    IN  HANDLE              hProcess,
    IN  DWORD64             qwAddr,
    OUT PDWORD64            pdwDisplacement,
    OUT PIMAGEHLP_SYMBOL64  Symbol
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymFromAddr SymGetSymFromAddr64
#else
BOOL
IMAGEAPI
SymGetSymFromAddr(
    IN  HANDLE            hProcess,
    IN  DWORD             dwAddr,
    OUT PDWORD            pdwDisplacement,
    OUT PIMAGEHLP_SYMBOL  Symbol
    );
#endif

BOOL
IMAGEAPI
SymGetSymFromName64(
    IN  HANDLE              hProcess,
    IN  PSTR                Name,
    OUT PIMAGEHLP_SYMBOL64  Symbol
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymFromName SymGetSymFromName64
#else
BOOL
IMAGEAPI
SymGetSymFromName(
    IN  HANDLE            hProcess,
    IN  PSTR              Name,
    OUT PIMAGEHLP_SYMBOL  Symbol
    );
#endif

BOOL
IMAGEAPI
SymGetSymNext64(
    IN     HANDLE              hProcess,
    IN OUT PIMAGEHLP_SYMBOL64  Symbol
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymNext SymGetSymNext64
#else
BOOL
IMAGEAPI
SymGetSymNext(
    IN     HANDLE            hProcess,
    IN OUT PIMAGEHLP_SYMBOL  Symbol
    );
#endif

BOOL
IMAGEAPI
SymGetSymPrev64(
    IN     HANDLE              hProcess,
    IN OUT PIMAGEHLP_SYMBOL64  Symbol
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetSymPrev SymGetSymPrev64
#else
BOOL
IMAGEAPI
SymGetSymPrev(
    IN     HANDLE            hProcess,
    IN OUT PIMAGEHLP_SYMBOL  Symbol
    );
#endif

BOOL
IMAGEAPI
SymGetLineFromAddr64(
    IN  HANDLE                  hProcess,
    IN  DWORD64                 qwAddr,
    OUT PDWORD                  pdwDisplacement,
    OUT PIMAGEHLP_LINE64        Line
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLineFromAddr SymGetLineFromAddr64
#else
BOOL
IMAGEAPI
SymGetLineFromAddr(
    IN  HANDLE                hProcess,
    IN  DWORD                 dwAddr,
    OUT PDWORD                pdwDisplacement,
    OUT PIMAGEHLP_LINE        Line
    );
#endif

BOOL
IMAGEAPI
SymGetLineFromName64(
    IN     HANDLE               hProcess,
    IN     PSTR                 ModuleName,
    IN     PSTR                 FileName,
    IN     DWORD                dwLineNumber,
       OUT PLONG                plDisplacement,
    IN OUT PIMAGEHLP_LINE64     Line
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLineFromName SymGetLineFromName64
#else
BOOL
IMAGEAPI
SymGetLineFromName(
    IN     HANDLE             hProcess,
    IN     PSTR               ModuleName,
    IN     PSTR               FileName,
    IN     DWORD              dwLineNumber,
       OUT PLONG              plDisplacement,
    IN OUT PIMAGEHLP_LINE     Line
    );
#endif

BOOL
IMAGEAPI
SymGetLineNext64(
    IN     HANDLE               hProcess,
    IN OUT PIMAGEHLP_LINE64     Line
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLineNext SymGetLineNext64
#else
BOOL
IMAGEAPI
SymGetLineNext(
    IN     HANDLE             hProcess,
    IN OUT PIMAGEHLP_LINE     Line
    );
#endif

BOOL
IMAGEAPI
SymGetLinePrev64(
    IN     HANDLE               hProcess,
    IN OUT PIMAGEHLP_LINE64     Line
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymGetLinePrev SymGetLinePrev64
#else
BOOL
IMAGEAPI
SymGetLinePrev(
    IN     HANDLE             hProcess,
    IN OUT PIMAGEHLP_LINE     Line
    );
#endif

BOOL
IMAGEAPI
SymMatchFileName(
    IN  PSTR  FileName,
    IN  PSTR  Match,
    OUT PSTR *FileNameStop,
    OUT PSTR *MatchStop
    );

BOOL
IMAGEAPI
SymInitialize(
    IN HANDLE   hProcess,
    IN PSTR     UserSearchPath,
    IN BOOL     fInvadeProcess
    );

BOOL
IMAGEAPI
SymGetSearchPath(
    IN  HANDLE          hProcess,
    OUT PSTR            SearchPath,
    IN  DWORD           SearchPathLength
    );

BOOL
IMAGEAPI
SymSetSearchPath(
    IN HANDLE           hProcess,
    IN PSTR             SearchPath
    );

DWORD64
IMAGEAPI
SymLoadModule64(
    IN  HANDLE          hProcess,
    IN  HANDLE          hFile,
    IN  PSTR            ImageName,
    IN  PSTR            ModuleName,
    IN  DWORD64         BaseOfDll,
    IN  DWORD           SizeOfDll
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymLoadModule SymLoadModule64
#else
DWORD
IMAGEAPI
SymLoadModule(
    IN  HANDLE          hProcess,
    IN  HANDLE          hFile,
    IN  PSTR            ImageName,
    IN  PSTR            ModuleName,
    IN  DWORD           BaseOfDll,
    IN  DWORD           SizeOfDll
    );
#endif

BOOL
IMAGEAPI
SymUnloadModule64(
    IN  HANDLE          hProcess,
    IN  DWORD64         BaseOfDll
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymUnloadModule SymUnloadModule64
#else
BOOL
IMAGEAPI
SymUnloadModule(
    IN  HANDLE          hProcess,
    IN  DWORD           BaseOfDll
    );
#endif

BOOL
IMAGEAPI
SymUnDName64(
    IN  PIMAGEHLP_SYMBOL64 sym,               // Symbol to undecorate
    OUT PSTR               UnDecName,         // Buffer to store undecorated name in
    IN  DWORD              UnDecNameLength    // Size of the buffer
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymUnDName SymUnDName64
#else
BOOL
IMAGEAPI
SymUnDName(
    IN  PIMAGEHLP_SYMBOL sym,               // Symbol to undecorate
    OUT PSTR             UnDecName,         // Buffer to store undecorated name in
    IN  DWORD            UnDecNameLength    // Size of the buffer
    );
#endif

BOOL
IMAGEAPI
SymRegisterCallback64(
    IN HANDLE                        hProcess,
    IN PSYMBOL_REGISTERED_CALLBACK64 CallbackFunction,
    IN ULONG64                       UserContext
    );

BOOL
IMAGEAPI
SymRegisterFunctionEntryCallback64(
    IN HANDLE                       hProcess,
    IN PSYMBOL_FUNCENTRY_CALLBACK64 CallbackFunction,
    IN ULONG64                      UserContext
    );

#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define SymRegisterCallback SymRegisterCallback64
#define SymRegisterFunctionEntryCallback SymRegisterFunctionEntryCallback64
#else
BOOL
IMAGEAPI
SymRegisterCallback(
    IN HANDLE                      hProcess,
    IN PSYMBOL_REGISTERED_CALLBACK CallbackFunction,
    IN PVOID                       UserContext
    );

BOOL
IMAGEAPI
SymRegisterFunctionEntryCallback(
    IN HANDLE                     hProcess,
    IN PSYMBOL_FUNCENTRY_CALLBACK CallbackFunction,
    IN PVOID                      UserContext
    );
#endif


// Structure types
typedef enum IMAGEHLP_TYPES {
   IMAGEHLP_TYPEID_INDEX = 1,
   IMAGEHLP_TYPEID_NAME,
   IMAGEHLP_TYPEID_IMAGEHLP_SYMBOL,
   IMAGEHLP_TYPEID_IMAGEHLP_SYMBOL64,
   IMAGEHLP_TYPEID_MODULE_TYPE_INFO,
   IMAGEHLP_TYPEID_TYPE_ENUM_INFO,
   IMAGEHLP_TYPEID_ADDR,
   IMAGEHLP_TYPEID_ADDR_ENUM,
   IMAGEHLP_TYPEID_SYMBOL_SRC
} IMAGEHLP_TYPES;

typedef struct _IMAGEHLP_SYMBOL_SRC {
    DWORD sizeofstruct;
    DWORD type;
    char  file[MAX_PATH];
} IMAGEHLP_SYMBOL_SRC, *PIMAGEHLP_SYMBOL_SRC;

typedef struct _MODULE_TYPE_INFO { // AKA TYPTYP
    USHORT      dataLength;
    USHORT      leaf;
    BYTE        data[1];
} MODULE_TYPE_INFO, *PMODULE_TYPE_INFO;

#define IMAGEHLP_SYMBOL_INFO_VALUEPRESENT          1
#define IMAGEHLP_SYMBOL_INFO_REGISTER              SYMF_REGISTER        // 0x08
#define IMAGEHLP_SYMBOL_INFO_REGRELATIVE           SYMF_REGREL          // 0x10
#define IMAGEHLP_SYMBOL_INFO_FRAMERELATIVE         SYMF_FRAMEREL        // 0x20
#define IMAGEHLP_SYMBOL_INFO_PARAMETER             SYMF_PARAMETER       // 0x40
#define IMAGEHLP_SYMBOL_INFO_LOCAL                 SYMF_LOCAL           // 0x80

typedef struct _SYMBOL_INFO {
    ULONG       SizeOfStruct;
    ULONG       TypeIndex;        // Type Index of symbol
    ULONG64     Reserved[2];
    ULONG       Reserved2;
    ULONG       Size;
    ULONG64     ModBase;          // Base Address of module comtaining this symbol
    ULONG       Flags;
    ULONG64     Value;            // Value of symbol, ValuePresent should be 1
    ULONG64     Address;          // Address of symbol including base address of module
    ULONG       Register;         // register holding value or pointer to value
    ULONG       Scope;            // scope of the symbol
    ULONG       Tag;              // pdb classification
    ULONG       NameLen;          // Actual length of name
    ULONG       MaxNameLen;
    CHAR        Name[1];          // Name of symbol
} SYMBOL_INFO, *PSYMBOL_INFO;

typedef BOOL
(CALLBACK *PSYMBOL_TYPE_NAME_CALLBACK)(
    PSTR  MatchedName,
    ULONG typeIndex,
    PVOID CallerData
    );

typedef BOOL
(CALLBACK *PSYMBOL_TYPE_NAME_ADDR_CALLBACK)(
    PSTR    MatchedName,
    ULONG   typeIndex,
    ULONG64 symAddress,
    PVOID   CallerData
    );

typedef struct _IMAGEHLP_STACK_FRAME
{
    ULONG64 InstructionOffset;
    ULONG64 ReturnOffset;
    ULONG64 FrameOffset;
    ULONG64 StackOffset;
    ULONG64 BackingStoreOffset;
    ULONG64 FuncTableEntry;
    ULONG64 Params[4];
    ULONG64 Reserved[5];
    BOOL    Virtual;
    ULONG   Reserved2;
} IMAGEHLP_STACK_FRAME, *PIMAGEHLP_STACK_FRAME;

typedef VOID IMAGEHLP_CONTEXT, *PIMAGEHLP_CONTEXT;


ULONG
SymSetContext(
    HANDLE hProcess,
    PIMAGEHLP_STACK_FRAME StackFrame,
    PIMAGEHLP_CONTEXT Context
    );

//
// Full user-mode dump creation.
//

typedef BOOL (WINAPI *PDBGHELP_CREATE_USER_DUMP_CALLBACK)(
    DWORD       DataType,
    PVOID*      Data,
    LPDWORD     DataLength,
    PVOID       UserData
    );

BOOL
WINAPI
DbgHelpCreateUserDump(
    IN LPSTR                              FileName,
    IN PDBGHELP_CREATE_USER_DUMP_CALLBACK Callback,
    IN PVOID                              UserData
    );

BOOL
WINAPI
DbgHelpCreateUserDumpW(
    IN LPWSTR                             FileName,
    IN PDBGHELP_CREATE_USER_DUMP_CALLBACK Callback,
    IN PVOID                              UserData
    );

typedef BOOL
(CALLBACK *PSYM_ENUMERATESYMBOLS_CALLBACK)(
    PSYMBOL_INFO  pSymInfo,
    ULONG         SymbolSize,
    PVOID         UserContext
    );
BOOL
IMAGEAPI
SymFromAddr(
    IN  HANDLE              hProcess,
    IN  DWORD64             Address,
    OUT PDWORD64            Displacement,
    IN OUT PSYMBOL_INFO     Symbol
    );

BOOL
IMAGEAPI
SymFromName(
    IN  HANDLE              hProcess,
    IN  LPSTR               Name,
    OUT PSYMBOL_INFO        Symbol
    );

BOOL
IMAGEAPI
SymEnumSym(
    IN HANDLE                       hProcess,
    IN ULONG64                      BaseOfDll,
    IN PSYM_ENUMERATESYMBOLS_CALLBACK    EnumSymbolsCallback,
    IN PVOID                        UserContext
    );

BOOL
IMAGEAPI
SymEnumSymbols(
    IN HANDLE                       hProcess,
    IN ULONG64                      BaseOfDll,
    IN PCSTR                        Mask,
    IN PSYM_ENUMERATESYMBOLS_CALLBACK    EnumSymbolsCallback,
    IN PVOID                        UserContext
    );

typedef enum _IMAGEHLP_SYMBOL_TYPE_INFO {
    TI_GET_SYMTAG,
    TI_GET_SYMNAME,
    TI_GET_LENGTH,
    TI_GET_TYPE,
    TI_GET_TYPEID,
    TI_GET_BASETYPE,
    TI_GET_ARRAYINDEXTYPEID,
    TI_FINDCHILDREN,
    TI_GET_DATAKIND,
    TI_GET_ADDRESSOFFSET,
    TI_GET_OFFSET,
    TI_GET_VALUE,
    TI_GET_COUNT,
    TI_GET_CHILDRENCOUNT,
    TI_GET_BITPOSITION,
    TI_GET_VIRTUALBASECLASS,
    TI_GET_VIRTUALTABLESHAPEID,
    TI_GET_VIRTUALBASEPOINTEROFFSET,
    TI_GET_CLASSPARENTID,
    TI_GET_NESTED,
    TI_GET_SYMINDEX,
    TI_GET_LEXICALPARENT,
    TI_GET_ADDRESS,
} IMAGEHLP_SYMBOL_TYPE_INFO;

typedef struct _TI_FINDCHILDREN_PARAMS {
    ULONG Count;
    ULONG Start;
    ULONG ChildId[1];
} TI_FINDCHILDREN_PARAMS;

BOOL
IMAGEAPI
SymGetTypeInfo(
    IN  HANDLE          hProcess,
    IN  DWORD64         ModBase,
    IN  ULONG           TypeId,
    IN  IMAGEHLP_SYMBOL_TYPE_INFO GetType,
    OUT PVOID           pInfo
    );

typedef enum IMAGEHLP_ENUM_LISTS {
    IMG_ENUM_SYMBOLS,
    IMG_ENUM_LINES,
    IMG_ENUM_TABLES,
    IMG_ENUM_SEGMENTS,
} IMAGEHLP_ENUM_LISTS;

HRESULT
IMAGEAPI
SymGetNextEnumListMember(
    IN HANDLE               hProcess,
    IN DWORD64              ModBase,
    IN PVOID                pEnumList,
    IN IMAGEHLP_ENUM_LISTS  ListTag,
    OUT PVOID               pNext
    );

BOOL
IMAGEAPI
SymEnumTypes(
    IN HANDLE                       hProcess,
    IN ULONG64                      BaseOfDll,
    IN PSYM_ENUMERATESYMBOLS_CALLBACK    EnumSymbolsCallback,
    IN PVOID                        UserContext
    );

BOOL
IMAGEAPI
SymGetTypeFromName(
    IN  HANDLE              hProcess,
    IN  ULONG64             BaseOfDll,
    IN  LPSTR               Name,
    OUT PSYMBOL_INFO        Symbol
    );


#include <pshpack4.h>

#pragma warning(disable:4200) // Zero length array


#define MINIDUMP_SIGNATURE ('PMDM')
#define MINIDUMP_VERSION   (42899)
typedef DWORD RVA;
typedef ULONG64 RVA64;

typedef struct _MINIDUMP_LOCATION_DESCRIPTOR {
    ULONG32 DataSize;
    RVA Rva;
} MINIDUMP_LOCATION_DESCRIPTOR;

typedef struct _MINIDUMP_LOCATION_DESCRIPTOR64 {
    ULONG64 DataSize;
    RVA64 Rva;
} MINIDUMP_LOCATION_DESCRIPTOR64;


typedef struct _MINIDUMP_MEMORY_DESCRIPTOR {
    ULONG64 StartOfMemoryRange;
    MINIDUMP_LOCATION_DESCRIPTOR Memory;
} MINIDUMP_MEMORY_DESCRIPTOR, *PMINIDUMP_MEMORY_DESCRIPTOR;

// DESCRIPTOR64 is used for full-memory minidumps where
// all of the raw memory is laid out sequentially at the
// end of the dump.  There is no need for individual RVAs
// as the RVA is the base RVA plus the sum of the preceeding
// data blocks.
typedef struct _MINIDUMP_MEMORY_DESCRIPTOR64 {
    ULONG64 StartOfMemoryRange;
    ULONG64 DataSize;
} MINIDUMP_MEMORY_DESCRIPTOR64, *PMINIDUMP_MEMORY_DESCRIPTOR64;


typedef struct _MINIDUMP_HEADER {
    ULONG32 Signature;
    ULONG32 Version;
    ULONG32 NumberOfStreams;
    RVA StreamDirectoryRva;
    ULONG32 CheckSum;
    union {
        ULONG32 Reserved;
        ULONG32 TimeDateStamp;
    };
    ULONG64 Flags;
} MINIDUMP_HEADER, *PMINIDUMP_HEADER;

//
// The MINIDUMP_HEADER field StreamDirectoryRva points to 
// an array of MINIDUMP_DIRECTORY structures.
//

typedef struct _MINIDUMP_DIRECTORY {
    ULONG32 StreamType;
    MINIDUMP_LOCATION_DESCRIPTOR Location;
} MINIDUMP_DIRECTORY, *PMINIDUMP_DIRECTORY;


typedef struct _MINIDUMP_STRING {
    ULONG32 Length;         // Length in bytes of the string
    WCHAR   Buffer [0];     // Variable size buffer
} MINIDUMP_STRING, *PMINIDUMP_STRING;



//
// The MINIDUMP_DIRECTORY field StreamType may be one of the following types.
// Types will be added in the future, so if a program reading the minidump
// header encounters a stream type it does not understand it should ignore
// the data altogether. Any tag above LastReservedStream will not be used by
// the system and is reserved for program-specific information.
//

typedef enum _MINIDUMP_STREAM_TYPE {

    UnusedStream                = 0,
    ReservedStream0             = 1,
    ReservedStream1             = 2,
    ThreadListStream            = 3,
    ModuleListStream            = 4,
    MemoryListStream            = 5,
    ExceptionStream             = 6,
    SystemInfoStream            = 7,
    ThreadExListStream          = 8,
    Memory64ListStream          = 9,
    CommentStreamA              = 10,
    CommentStreamW              = 11,
    HandleDataStream            = 12,

    LastReservedStream          = 0xffff

} MINIDUMP_STREAM_TYPE;


//
// The minidump system information contains processor and
// Operating System specific information.
// 
    
typedef struct _MINIDUMP_SYSTEM_INFO {

    //
    // ProcessorArchitecture, ProcessorLevel and ProcessorRevision are all
    // taken from the SYSTEM_INFO structure obtained by GetSystemInfo( ).
    //
    
    USHORT ProcessorArchitecture;
    USHORT ProcessorLevel;
    USHORT ProcessorRevision;

    USHORT Reserved0;              // Reserved for future use. Must be zero.

    //
    // MajorVersion, MinorVersion, BuildNumber, PlatformId and
    // CSDVersion are all taken from the OSVERSIONINFO structure
    // returned by GetVersionEx( ).
    //
    
    ULONG32 MajorVersion;
    ULONG32 MinorVersion;
    ULONG32 BuildNumber;
    ULONG32 PlatformId;

    //
    // RVA to a CSDVersion string in the string table.
    //
    
    RVA CSDVersionRva;

    ULONG32 Reserved1;             // Reserved for future use.

    //
    // CPU information is obtained from one of two places.
    //
    //  1) On x86 computers, CPU_INFORMATION is obtained from the CPUID
    //     instruction. You must use the X86 portion of the union for X86
    //     computers.
    //
    //  2) On non-x86 architectures, CPU_INFORMATION is obtained by calling
    //     IsProcessorFeatureSupported().
    //
    
    union _CPU_INFORMATION {

        //
        // X86 platforms use CPUID function to obtain processor information.
        //
        
        struct {

            //
            // CPUID Subfunction 0, register EAX (VendorId [0]),
            // EBX (VendorId [1]) and ECX (VendorId [2]).
            //
            
            ULONG32 VendorId [ 3 ];
            
            //
            // CPUID Subfunction 1, register EAX
            //
            
            ULONG32 VersionInformation;

            //
            // CPUID Subfunction 1, register EDX
            //
            
            ULONG32 FeatureInformation;
            

            //
            // CPUID, Subfunction 80000001, register EBX. This will only
            // be obtained if the vendor id is "AuthenticAMD".
            //
            
            ULONG32 AMDExtendedCpuFeatures;
    
        } X86CpuInfo;

        //
        // Non-x86 platforms use processor feature flags.
        //
        
        struct {

            ULONG64 ProcessorFeatures [ 2 ];
            
        } OtherCpuInfo;
        
    } Cpu;

} MINIDUMP_SYSTEM_INFO, *PMINIDUMP_SYSTEM_INFO;

typedef union _CPU_INFORMATION CPU_INFORMATION, *PCPU_INFORMATION;


//
// The minidump thread contains standard thread
// information plus an RVA to the memory for this 
// thread and an RVA to the CONTEXT structure for
// this thread.
//


//
// ThreadId must be 4 bytes on all architectures.
//

C_ASSERT (sizeof ( ((PPROCESS_INFORMATION)0)->dwThreadId ) == 4);

typedef struct _MINIDUMP_THREAD {
    ULONG32 ThreadId;
    ULONG32 SuspendCount;
    ULONG32 PriorityClass;
    ULONG32 Priority;
    ULONG64 Teb;
    MINIDUMP_MEMORY_DESCRIPTOR Stack;
    MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
} MINIDUMP_THREAD, *PMINIDUMP_THREAD;

//
// The thread list is a container of threads.
//

typedef struct _MINIDUMP_THREAD_LIST {
    ULONG32 NumberOfThreads;
    MINIDUMP_THREAD Threads [0];
} MINIDUMP_THREAD_LIST, *PMINIDUMP_THREAD_LIST;


typedef struct _MINIDUMP_THREAD_EX {
    ULONG32 ThreadId;
    ULONG32 SuspendCount;
    ULONG32 PriorityClass;
    ULONG32 Priority;
    ULONG64 Teb;
    MINIDUMP_MEMORY_DESCRIPTOR Stack;
    MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
    MINIDUMP_MEMORY_DESCRIPTOR BackingStore;
} MINIDUMP_THREAD_EX, *PMINIDUMP_THREAD_EX;

//
// The thread list is a container of threads.
//

typedef struct _MINIDUMP_THREAD_EX_LIST {
    ULONG32 NumberOfThreads;
    MINIDUMP_THREAD_EX Threads [0];
} MINIDUMP_THREAD_EX_LIST, *PMINIDUMP_THREAD_EX_LIST;


//
// The MINIDUMP_EXCEPTION is the same as EXCEPTION on Win64.
//

typedef struct _MINIDUMP_EXCEPTION  {
    ULONG32 ExceptionCode;
    ULONG32 ExceptionFlags;
    ULONG64 ExceptionRecord;
    ULONG64 ExceptionAddress;
    ULONG32 NumberParameters;
    ULONG32 __unusedAlignment;
    ULONG64 ExceptionInformation [ EXCEPTION_MAXIMUM_PARAMETERS ];
} MINIDUMP_EXCEPTION, *PMINIDUMP_EXCEPTION;


//
// The exception information stream contains the id of the thread that caused
// the exception (ThreadId), the exception record for the exception
// (ExceptionRecord) and an RVA to the thread context where the exception
// occured.
//

typedef struct MINIDUMP_EXCEPTION_STREAM {
    ULONG32 ThreadId;
    ULONG32  __alignment;
    MINIDUMP_EXCEPTION ExceptionRecord;
    MINIDUMP_LOCATION_DESCRIPTOR ThreadContext;
} MINIDUMP_EXCEPTION_STREAM, *PMINIDUMP_EXCEPTION_STREAM;


//
// The MINIDUMP_MODULE contains information about a
// a specific module. It includes the CheckSum and
// the TimeDateStamp for the module so the module
// can be reloaded during the analysis phase.
//

typedef struct _MINIDUMP_MODULE {
    ULONG64 BaseOfImage;
    ULONG32 SizeOfImage;
    ULONG32 CheckSum;
    ULONG32 TimeDateStamp;
    RVA ModuleNameRva;
    VS_FIXEDFILEINFO VersionInfo;
    MINIDUMP_LOCATION_DESCRIPTOR CvRecord;
    MINIDUMP_LOCATION_DESCRIPTOR MiscRecord;
    ULONG64 Reserved0;                          // Reserved for future use.
    ULONG64 Reserved1;                          // Reserved for future use.
} MINIDUMP_MODULE, *PMINIDUMP_MODULE;   


//
// The minidump module list is a container for modules.
//

typedef struct _MINIDUMP_MODULE_LIST {
    ULONG32 NumberOfModules;
    MINIDUMP_MODULE Modules [ 0 ];
} MINIDUMP_MODULE_LIST, *PMINIDUMP_MODULE_LIST;


//
// Memory Ranges
//

typedef struct _MINIDUMP_MEMORY_LIST {
    ULONG32 NumberOfMemoryRanges;
    MINIDUMP_MEMORY_DESCRIPTOR MemoryRanges [0];
} MINIDUMP_MEMORY_LIST, *PMINIDUMP_MEMORY_LIST;

typedef struct _MINIDUMP_MEMORY64_LIST {
    ULONG64 NumberOfMemoryRanges;
    RVA64 BaseRva;
    MINIDUMP_MEMORY_DESCRIPTOR64 MemoryRanges [0];
} MINIDUMP_MEMORY64_LIST, *PMINIDUMP_MEMORY64_LIST;


//
// Support for user supplied exception information.
//

typedef struct _MINIDUMP_EXCEPTION_INFORMATION {
    DWORD ThreadId;
    PEXCEPTION_POINTERS ExceptionPointers;
    BOOL ClientPointers;
} MINIDUMP_EXCEPTION_INFORMATION, *PMINIDUMP_EXCEPTION_INFORMATION;


//
// Support for capturing system handle state at the time of the dump.
//

typedef struct _MINIDUMP_HANDLE_DESCRIPTOR {
    ULONG64 Handle;
    RVA TypeNameRva;
    RVA ObjectNameRva;
    ULONG Attributes;
    ULONG GrantedAccess;
    ULONG HandleCount;
    ULONG PointerCount;
} MINIDUMP_HANDLE_DESCRIPTOR, *PMINIDUMP_HANDLE_DESCRIPTOR;

typedef struct _MINIDUMP_HANDLE_DATA_STREAM {
    ULONG SizeOfHeader;
    ULONG SizeOfDescriptor;
    ULONG NumberOfDescriptors;
    ULONG Reserved;
} MINIDUMP_HANDLE_DATA_STREAM, *PMINIDUMP_HANDLE_DATA_STREAM;


//
// Support for arbitrary user-defined information.
//

typedef struct _MINIDUMP_USER_RECORD {
    ULONG32 Type;
    MINIDUMP_LOCATION_DESCRIPTOR Memory;
} MINIDUMP_USER_RECORD, *PMINIDUMP_USER_RECORD;


typedef struct _MINIDUMP_USER_STREAM {
    ULONG32 Type;
    ULONG BufferSize;
    PVOID Buffer;

} MINIDUMP_USER_STREAM, *PMINIDUMP_USER_STREAM;


typedef struct _MINIDUMP_USER_STREAM_INFORMATION {
    ULONG UserStreamCount;
    PMINIDUMP_USER_STREAM UserStreamArray;
} MINIDUMP_USER_STREAM_INFORMATION, *PMINIDUMP_USER_STREAM_INFORMATION;

//
// Callback support.
//

typedef enum _MINIDUMP_CALLBACK_TYPE {
    ModuleCallback,
    ThreadCallback,
    ThreadExCallback
} MINIDUMP_CALLBACK_TYPE;


typedef struct _MINIDUMP_THREAD_CALLBACK {
    ULONG ThreadId;
    HANDLE ThreadHandle;
    CONTEXT Context;
    ULONG SizeOfContext;
    ULONG64 StackBase;
    ULONG64 StackEnd;
} MINIDUMP_THREAD_CALLBACK, *PMINIDUMP_THREAD_CALLBACK;


typedef struct _MINIDUMP_THREAD_EX_CALLBACK {
    ULONG ThreadId;
    HANDLE ThreadHandle;
    CONTEXT Context;
    ULONG SizeOfContext;
    ULONG64 StackBase;
    ULONG64 StackEnd;
    ULONG64 BackingStoreBase;
    ULONG64 BackingStoreEnd;
} MINIDUMP_THREAD_EX_CALLBACK, *PMINIDUMP_THREAD_EX_CALLBACK;


typedef enum _THREAD_WRITE_FLAGS {
    ThreadWriteThread            = 0x0001,
    ThreadWriteStack             = 0x0002,
    ThreadWriteContext           = 0x0004,
    ThreadWriteBackingStore      = 0x0008,
    ThreadWriteInstructionWindow = 0x0010
} THREAD_WRITE_FLAGS;

typedef struct _MINIDUMP_MODULE_CALLBACK {
    PWCHAR FullPath;
    ULONG64 BaseOfImage;
    ULONG SizeOfImage;
    ULONG CheckSum;
    ULONG TimeDateStamp;
    VS_FIXEDFILEINFO VersionInfo;
    PVOID CvRecord; 
    ULONG SizeOfCvRecord;
    PVOID MiscRecord;
    ULONG SizeOfMiscRecord;
} MINIDUMP_MODULE_CALLBACK, *PMINIDUMP_MODULE_CALLBACK;


typedef enum _MODULE_WRITE_FLAGS {
    ModuleWriteModule       = 0x0001,
    ModuleWriteDataSeg      = 0x0002,
    ModuleWriteMiscRecord   = 0x0004
} MODULE_WRITE_FLAGS;


typedef struct _MINIDUMP_CALLBACK_INPUT {
    ULONG ProcessId;
    HANDLE ProcessHandle;
    ULONG CallbackType;
    union {
        MINIDUMP_THREAD_CALLBACK Thread;
        MINIDUMP_THREAD_EX_CALLBACK ThreadEx;
        MINIDUMP_MODULE_CALLBACK Module;
    };
} MINIDUMP_CALLBACK_INPUT, *PMINIDUMP_CALLBACK_INPUT;

typedef struct _MINIDUMP_CALLBACK_OUTPUT {
    union {
        ULONG ModuleWriteFlags;
        ULONG ThreadWriteFlags;
    };
} MINIDUMP_CALLBACK_OUTPUT, *PMINIDUMP_CALLBACK_OUTPUT;

        
//
// A normal minidump contains just the information
// necessary to capture stack traces for all of the
// existing threads in a process.
//
// A minidump with data segments includes all of the data
// sections from loaded modules in order to capture
// global variable contents.  This can make the dump much
// larger if many modules have global data.
//
// A minidump with full memory includes all of the accessible
// memory in the process and can be very large.  A minidump
// with full memory always has the raw memory data at the end
// of the dump so that the initial structures in the dump can
// be mapped directly without having to include the raw
// memory information.
//

typedef enum _MINIDUMP_TYPE {
    MiniDumpNormal         = 0x0000,
    MiniDumpWithDataSegs   = 0x0001,
    MiniDumpWithFullMemory = 0x0002,
    MiniDumpWithHandleData = 0x0004,
} MINIDUMP_TYPE;


//
// The minidump callback should modify the FieldsToWrite parameter to reflect
// what portions of the specified thread or module should be written to the
// file.
//

typedef
BOOL
(WINAPI * MINIDUMP_CALLBACK_ROUTINE) (
    IN PVOID CallbackParam,
    IN CONST PMINIDUMP_CALLBACK_INPUT CallbackInput,
    IN OUT PMINIDUMP_CALLBACK_OUTPUT CallbackOutput
    );

typedef struct _MINIDUMP_CALLBACK_INFORMATION {
    MINIDUMP_CALLBACK_ROUTINE CallbackRoutine;
    PVOID CallbackParam;
} MINIDUMP_CALLBACK_INFORMATION, *PMINIDUMP_CALLBACK_INFORMATION;



//++
//
// PVOID
// RVA_TO_ADDR(
//     PVOID Mapping,
//     ULONG Rva
//     )
//
// Routine Description:
//
//     Map an RVA that is contained within a mapped file to it's associated
//     flat address.
//
// Arguments:
//
//     Mapping - Base address of mapped file containing the RVA.
//
//     Rva - An Rva to fixup.
//
// Return Values:
//
//     A pointer to the desired data.
//
//--

#define RVA_TO_ADDR(Mapping,Rva) ((PVOID)(((ULONG_PTR) (Mapping)) + (Rva)))

BOOL
WINAPI
MiniDumpWriteDump(
    IN HANDLE hProcess,
    IN DWORD ProcessId,
    IN HANDLE hFile,
    IN MINIDUMP_TYPE DumpType,
    IN CONST PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam, OPTIONAL
    IN CONST PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam, OPTIONAL
    IN CONST PMINIDUMP_CALLBACK_INFORMATION CallbackParam OPTIONAL
    );

BOOL
WINAPI
MiniDumpReadDumpStream(
    IN PVOID BaseOfDump,
    IN ULONG StreamNumber,
    OUT PMINIDUMP_DIRECTORY * Dir, OPTIONAL
    OUT PVOID * StreamPointer, OPTIONAL
    OUT ULONG * StreamSize OPTIONAL
    );

#include <poppack.h>

#ifdef __cplusplus
}
#endif


#endif // _IMAGEHLP_