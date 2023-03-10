THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Copyright (C) 2000 Microsoft Corporation.  All Rights Reserved.


READPOL.VBS V2.0 - Read ACS Policies from Windows 2000 Directory Service

Abstract:

READPOL.VBS is an ADSI based visual basic script to display ACS polices 
from Windows 2000 Active Directory. It is an alternative way of displaying 
ACS polices. You can run this script on a Windows 2000 machine that is part
of a Windows 2000 domain. Any authenticated user on the domain can run
this script.  


Usage:

Please either run the batch file provided or call the script using with 
windows scripting host command line interpreter i.e. cscript readpol.vbs ...

readpol [subnet|global] [user|all|config]

        global: search under the global container
        subnet: search under this subnet container

        user:   look for only this user name
        all:    to see all users
        config: to see subnet configuration


Scenario:

If your rsvp request is getting a rejection from ACS. You may want to 
investigate if there's a particular rejection applies for you. Assuming
you are running an application on SUBNET 172.31.240.0\21:

1. Check if there's a subnet policy restriction applies for you. Does your 
   name have a separate policy or an authenticated policy restricts your request.

   readpol 172.31.240.0\/21 all

2. If not then check if there's a global policy restriction.

   readpol global all

3. If not then finally check the resource restrictions for your subnet.

   readpol 172.31.240.0\/21 config 

In general it's very unlikely that you may have a separate policy for yourself
but if you think this is the case you may display the policy applies for you.

   under a subnet:
   readpol 172.31.240.0\/21 YourUserName
   or under global:
   readpol global YourUserName

For interpretation of the policy elements listed under policies please refer
to the ACS documentation.  


