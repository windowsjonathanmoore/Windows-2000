/*++

Copyright (c) 1995  Microsoft Corporation

Module Name:

    pshpack4.h

Abstract:

    This file turns 4 byte packing of structures on.  (That is, it disables
    automatic alignment of structure fields.)  An include file is needed
    because various compilers do this in different ways.  For Microsoft
    compatible compilers, this files uses the push option to the pack pragma
    so that the poppack.h include file can restore the previous packing
    reliably.

    The file poppack.h is the complement to this file.

--*/

#if ! (defined(lint) || defined(_lint) || defined(RC_INVOKED) || defined(IS_16))
#if ( _MSC_VER >= 800 )
#pragma warning(disable:4103)
#if !(defined( MIDL_PASS )) || defined( __midl )
#pragma pack(push)
#endif
#pragma pack(4)
#else
#pragma pack(4)
#endif
#endif // ! (defined(lint) || defined(_lint) || defined(RC_INVOKED) || defined(IS_16))
