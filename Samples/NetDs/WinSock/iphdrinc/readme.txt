readme.txt

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 1999  Microsoft Corporation.  All Rights Reserved.


Description:

This sample illustrates how to use the socket option IP_HDRINCL. This
option allows a Winsock app to manually create and include the IP
header information for each packet sent. This socket option has been
in the Winsock headers for quite some time but is now actually
supported on the Windows 2000 platform. Note that is it NOT supported
on Windows 9x or earlier version of Windows NT.

This sample uses the IP_HDRINCL to send UDP traffic. From the command
line you can specify the source IP address, source port, destination
IP address and destination port which will be inserted as the IP/UDP
header. This means you can send a UDP packet whose source IP address
is bogus.

This sample is composed of a single file: iphdrinc.c.  This file
contains the routines for creating a raw socket, setting the IP_HDRINCL
option, building the IP and UDP headers, and sending this fabricated
packet.


Build:

    Via NMAKE
        Run nmake.exe in the sample directory.

    Via manual build:
        cl iphdrinc.c ws2_32.lib

Usage:

    This sample works on Windows 2000 only.

    To run this sample you will need to run 2 instances of this sample.
        One instance will receive UDP packets (so you can see what the 
        source IP address is) and the other instance to send our
        prefabricated UDP packets.

        On one machine (with IP address aaa.bbb.ccc.ddd) run:

        iphdrinc.exe -r:5150

        This instance will receive any UDP traffic sent to port 5150.

        On another machine (or the same machine) run:

        iphdrinc.exe -fi:10.0.0.1 -fp:6666 -ti:aaa.bbb.ccc.ddd -tp:5150

        This causes 5 UDP packets to be send to the IP address aaa.bbb.ccc.ddd
        on port 5150.  When this occurs our first instance will read these
        five packets and report that the source IP address is 10.0.0.1 from
        port 6666.

    Additionally you can specify the -n:count parameter to specify the number
        of UDP packet sent. 

    The -m:STRING parameter can be specified to supply the data portion of the
        UDP packet.

    To print the usage information:

        iphdrinc.exe -?
