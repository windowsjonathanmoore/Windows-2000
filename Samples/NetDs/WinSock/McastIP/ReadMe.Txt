SUMMARY
======= 
 
The MCASTIP samples demonstrate the basic multicast sequence of operations in WinSock 1 (setsocketopt) and WinSock 2 (WSAJoinLeaf).


DISCLAIMER
==========
Sample code adapted after "Network Programming for Microsoft Windows" by Anthony Jones and Jim Ohlund (© 1999, Anthony Jones and Jim Ohlund, published by Microsoft Press, ISBN 0-7356-0560-2). Used with permission from MS Press and the authors.


FILES
=====

README.TXT	Readme file
MAKEFILE	Makefile file
MCASTWS1.C	Source for multicast clinet/server using WinSock 1
MCASTWS2.C	Source for multicast clinet/server using WinSock 2


PLATFORM SUPORTED
=================

Windows NT 4, Windows 2000, and Windows 95/98.  Note that for Windows 95, "Winsock 2 Update for WinSock 2" is required in order to run MCASTWS2 (please see http://support.microsoft.com/support/platformsdk/networking/Downloads.asp).


RUNNING THE SERVER AND CLIENT APPLICATIONS
==========================================

To build, type "nmake" at the command line.

To run the samples, please follow the usage specified below

    mcastws1.exe [-s] [-m:str] [-p:int] [-i:str] [-l] [-n:int]
       -s        Act as sender; otherwise receive data
       -m:str    Dotted decimal IP multicast address to join
       -p:int    Port number to use
       -i:str    Local interface to use
       -l        Disable the loopback 
       -n:int    Number of messages to send or receive

    Mcastws2.exe [-s] [-m:str] [-p:int] [-i:str] [-l] [-n:int]
       -s        Act as sender; otherwise receive data
       -m:str    Dotted decimal IP multicast address to join
       -p:int    Port number to use
       -i:str    Local interface to use
       -l        Disable the loopback 
       -n:int    Number of messages to send or receive
