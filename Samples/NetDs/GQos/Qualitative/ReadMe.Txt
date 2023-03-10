THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 2000 Microsoft Corporation.  All Rights Reserved.


Qualitative - Qualitative QoS example

Abstract:

Qualitative sample is a simple Winsock client/server program that utilizes 
qualitative QoS. It demonstrates the techniques to create a Policy Element based 
on Application ID and Policy Locator. The sender is a console based winsock server 
that listens on port 8888. The receiver is a dialog based winsock client that can 
connect and receive using either QoS socket or Non-QoS socket.

Scenario:

1. Two QoS aware routers connect three subnets. 
2. The client runs on subnet 1.
3. The server runs on subnet 3.
4. Subnet 2 is saturated with local broadcast.
5. A Policy Server capable of AppID and DSCP marking is configured to
   priority mark "TestSoft"(AppID) and "TestERP"(PolicyLocator). Note: the ACS from
   Windows 2000 release does not yet support AppID. Future version of the ACS will 
   add AppID support.  
5. Run the Non-QoS query on the receiver - slow
6. Run the QoS query on the receiver - fast

Reference:

http://www.microsoft.com/windows2000/library/howitworks/communications/trafficmgmt/