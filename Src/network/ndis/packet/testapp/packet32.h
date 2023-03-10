
#ifndef __PACKET32
#define __PACKET32


#define        DOSNAMEPREFIX   TEXT("Packet_")

typedef struct _ADAPTER {

    HANDLE     hFile;

    TCHAR      SymbolicLink[MAX_LINK_NAME_LENGTH];

    } ADAPTER, *LPADAPTER;


typedef struct _PACKET {
    HANDLE       hEvent;
    OVERLAPPED   OverLapped;
    PVOID        Buffer;
    UINT         Length;
    } PACKET, *LPPACKET;


BOOL
PacketStartDriver(
    LPTSTR     ServiceName
    );
BOOL
PacketStopDriver(
    IN LPCTSTR      ServiceName
    );

PVOID
PacketOpenAdapter(
    LPTSTR   AdapterName
    );


BOOL
PacketSendPacket(
    LPADAPTER   AdapterObject,
    LPPACKET    lpPacket,
    BOOLEAN     Sync
    );


PVOID
PacketAllocatePacket(
    LPADAPTER   AdapterObject
    );


VOID
PacketInitPacket(
    LPPACKET    lpPacket,
    PVOID       Buffer,
    UINT        Length
    );

VOID
PacketFreePacket(
    LPPACKET    lpPacket
    );



BOOL
PacketResetAdapter(
    LPADAPTER  AdapterObject
    );


BOOLEAN
PacketGetAddress(
    LPADAPTER  AdapterObject,
    PUCHAR     AddressBuffer,
    PUINT       Length
    );




BOOL
PacketWaitPacket(
    LPADAPTER  AdapterObject,
    LPPACKET   lpPacket,
    PULONG     BytesReceived
    );
/*++

Routine Description:

    This routine waits for an overlapped IO on a packet to complete
    Called if the send or receive call specified FALSE for the Sync parmeter

Arguments:

    AdapterObject  - AdapterObject return by PacketOpenAdapter

    lpPacket       - Packet object returned by PacketAllocatePacket and initialized
                     by PacketInitPacket

Return Value:

    SUCCESS - TRUE if overlapped call succeeded
    FAILURE -

--*/

BOOL
PacketReceivePacket(
    LPADAPTER   AdapterObject,
    LPPACKET    lpPacket,
    BOOLEAN     Sync,
    PULONG      BytesReceived
    );
/*++

Routine Description:

    This rotine issues a receive request from the adapter

Arguments:

    AdapterObject  - AdapterObject return by PacketOpenAdapter

    lpPacket       - Packet object returned by PacketAllocatePacket and initialized
                     by PacketInitPacket

    Sync           - TRUE if service should wait for packet to transmit


Return Value:

    SUCCESS - TRUE if succeeded and SYNC==TRUE
    FAILURE -

--*/



VOID
PacketCloseAdapter(
    LPADAPTER   lpAdapter
    );

BOOL
PacketSetFilter(
    LPADAPTER  AdapterObject,
    ULONG      Filter
    );
/*++

Routine Description:

    This rotine sets the adapters packet filter

Arguments:

    AdapterObject  - AdapterObject return by PacketOpenAdapter

    Filter         - filter to be set

Return Value:

    SUCCESS -
    FAILURE -

--*/


ULONG
PacketGetAdapterNames(
    PTSTR   pStr,
    PULONG  BufferSize
    );




#endif


