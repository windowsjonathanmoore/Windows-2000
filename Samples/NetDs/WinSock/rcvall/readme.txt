readme.txt

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1999  Microsoft Corporation.  All Rights Reserved.


Description:

This sample illustrates how to use the new Windows 2000 Winsock ioctls:
SIO_RCVALL, SIO_RCVALL_MCAST, and SIO_RCVALL_IGMPMCAST. These new ioctls
allow a Winsock application to capture all IP traffic, all IP multicast
traffic, or all IGMP traffic on a given network interface. This is done
by creating a raw socket which is bound to a specific local IP interface.
Once the socket is bound, the specified ioctl option is set and subseqent
receive operations will return incoming IP packets of the requested type.

The sample is composed of 3 files: rcvall.c, parser.c, and parser.h.
The first file, rcvall.c, is the main file. It creates the socket, binds
it locally, and starts receiving data (i.e. the incoming IP traffic). 
Once a packet is read it calls the parse routine contained in parser.c
(along with prototypes contained in parser.h).  The parse routine will
print out the IP header as well as headers for UDP, TCP, and IGMP. The
IP protocol can encapsulate many other protocols as well; however, this
sample will not decode other protocol headers.


Build:

    Via NMAKE
        Run nmake.exe in the sample directory.

    Via manual build:
        cl rcvall.c parser.c ws2_32.lib

Usage:

    This sample works on Windows 2000 only.

    To run the sample with the defaults (bind to first IP address and
        capture all IP traffic):

        rcvall.exe

    For multiple homed machines you can obtain a list of local IP addresses
        by running:

        rcvall.exe -?

        This will print out usage information as well as a list of local IP
        addresses (indexed from 0 ... n-1 where n is the number of local IP 
        addresses.  Then to listen on a different IP address simply supply the
        proper index value with the -i:INDEX options as in:

        rcvall.exe -i:2

    To capture IGMP traffic (SIO_RCVALL_IGMPMCAST) or all multicast traffic
        (SIO_RCVALL_MCAST) use the -t:OPTION argument where OPTION is the
        string "igmp" or "multicast" respectively.

        For example to capture IGMP traffic only:

        rcvall.exe -t:igmp

        To capture all multicast traffic only:

        rcvall.exe -t:multicast

    You may also filter the received IP traffic based upon source IP address,
        source port, destination IP address, and/or destination port.

        -sa:aaa.bbb.ccc.ddd     filters on source IP address
        -da:aaa.bbb.ccc.ddd     filters on destination IP address
        -sp:x                   filters on source port
        -dp:x                   filters on destination port

        For example the following command will listen on the first IP
        interface for all IP traffic whose destination is 10.0.0.1 on port 21:

        rcvall.exe -t:ip -da:10.0.0.1 -dp:21

        Only those IP packets received that match the given criteria will
        be printed.
