RasDial

RasDial is a console application that allows you to make a synchronous (or silent) 
RAS connection.

FILES
=====

The RasDial application uses the following files

File            Description

README.TXT      Readme file for RasDial application
RASDIAL.C       C source code
MAKEFILE        Nmake file for Windows NT or Windows 9x


RAS API's USED
==============

RASDIAL
RASGETCONNECTSTATUS
RASGETPROJECTIONINFO
RASHANGUP


-------------------------------------------
BUILDING THE APPLICATION FOR
MICROSOFT WINDOWS NT OR WINDOWS 9x:
-------------------------------------------

To build the application on either Windows NT or Windows 9x you will
need to have the rasapi32.dll installed in the system folder. 

Build the application:

  nmake cleanall
  nmake

The above commands build the executable program RasDial.exe
for Microsoft Windows NT or Windows 9x.


--------------------------------------------------------
RUNNING THE APPLICATION ON WINDOWS NT AND WINDOWS 9x
--------------------------------------------------------

To run the application type:

    RasDial -e [entry name] -p [phone number] -u [username] -z [password] -d [domain]

You will need to have a phonebook entry with the entry name in the default phonebook
