<HTML><HEAD>
<Center><IMG SRC="setup/images/header.bmp" ALT="Platform SDK"></Center>
   <META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=iso-8859-1">
   <TITLE>Microsoft Platform SDK</TITLE></HEAD>
<BODY LINK="#0000FF" VLINK="#800080" BGCOLOR="#FFFFFF"><UL>

<!----------------------  TITLE  ------------------------ -->
<CENTER><B><FONT FACE="Arial Narrow" SIZE=+3>
Microsoft Platform Software Development Kit (SDK)
</FONT></B></CENTER>

<BR>

<!--------  Purpose ---------------->
<FONT FACE="Arial, Times New Roman" SIZE=2></FONT>


<HR WITDH=75% SIZE=4>

<!------------- ToC ------------ -->
<TABLE BORDER=0 CELLSPACING=0 CELLPADDING=0 WIDTH="100%" >
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#INTRO"><FONT FACE="Arial, Times New Roman" SIZE=2>Introduction</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#SYSREQ"><FONT FACE="Arial, Times New Roman" SIZE=2>System Requirements</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#INSTALLING"><FONT FACE="Arial, Times New Roman" SIZE=2>Installation Instructions</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#WHATSNEW"><FONT FACE="Arial, Times New Roman" SIZE=2>What's New</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#PRERELEASE"><FONT FACE="Arial, Times New Roman" SIZE=2>Pre-Release Content</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#NEWS"><FONT FACE="Arial, Times New Roman" SIZE=2>Release Notes</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#ISSUES"><FONT FACE="Arial, Times New Roman" SIZE=2>Known Issues</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#ARCHIVE"><FONT FACE="Arial, Times New Roman" SIZE=2>Online Download</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#DEVSUPPORT"><FONT FACE="Arial, Times New Roman" SIZE=2>Developer Support</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#LICENSE"><FONT FACE="Arial, Times New Roman" SIZE=2>License Agreements</FONT></A></B></TD></TR>
<TR><TD WIDTH="100%"><B><A HREF="readme.htm#FEEDBACK"><FONT FACE="Arial, Times New Roman" SIZE=2>Feedback</FONT></A></B></TD></TR>
</TABLE>




<!------ Introduction - -->
<HR WITDH=75% SIZE=4>
<A NAME="INTRO"></A><B><FONT FACE="Arial Narrow" SIZE=+3>Introduction</FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

Welcome to the Microsoft Platform SDK, February 2001 Edition. This edition targets development for Whistler Beta 2 (32-bit and 64-bit), Microsoft� Windows� Millennium Edition (Windows Me), Microsoft Windows� 2000, Microsoft Windows NT� version 4.0, and Windows 98 operating systems; the Microsoft BackOffice� family of products, Microsoft Internet Explorer version 3.<i>x</i> and later; and members of the .Net Enterprise Server family of products.  The Platform SDK is the successor to the Win32� and BackOffice SDKs as well as the many other technology-specific SDKs that were once separate.
<p>
The key objectives of the Platform SDK are to simplify installation of your development environment by integrating formerly discrete SDKs, introduce you to the latest technologies, and provide information about existing technologies. Visit the Microsoft Developer Network (MSDN�) Web site at <a href="http://msdn.microsoft.com/" target="_top">http://msdn.microsoft.com/</a> for the latest information on the Platform SDK and MSDN.
</p>
<p>
The Platform SDK comprises the following main components:
<UL>
<LI>Headers, libraries, and type libraries needed to build your application.
<LI>Documentation providing technology overviews, detailed interface references, and tools usage.
<LI>Samples to demonstrate the various technologies available.
<LI>Tools to aid in the development and debugging of applications.
<LI>Redistributables to support application deployment.
</UL>


<p>
To obtain the Platform SDK to install on your computer:
<UL>
<LI>Subscribe to MSDN at the Professional or Universal level.  An MSDN subscription at either of these levels provides access to operating systems and beta releases as well as the Platform SDK on CD-ROM.  For details about subscribing to MSDN, see <a href="http://msdn.microsoft.com/subscriptions/default.asp" target="_top">http://msdn.microsoft.com/subscriptions/default.asp</a>.
<LI>Visit our Web site at <a href="http://www.microsoft.com/msdownload/platformsdk/setuplauncher.htm" target="_top">http://www.microsoft.com/msdownload/platformsdk/setuplauncher.htm</a> to download the Platform SDK.
<LI>Order a CD-ROM of the Platform SDK from the Developer Store; the charge is minimal: you pay for shipping and handling only.
<UL>
<LI><b>U.S.</b> and <b>Canadian</b> customers, click <a href="http://developerstore.com/devstore/product.asp?productID=7594&store=TOOLBOX_NA&DisplayCode=HIDE">here</a>.
<LI><B>International</b> customers, click <a href="http://developerstore.com/devstore/product.asp?productID=7596&store=TOOLBOX_INTL&DisplayCode=HIDE">here</a>.
</UL>
<LI>To view the Platform SDK documentation <i>only,</i> visit the MSDN Library online at <a href="http://www.msdn.microsoft.com/library/default.asp" target="_top">http://www.msdn.microsoft.com/library/default.asp</a>.
</UL>
</FONT>




<!--- System Requiements --->
<HR WITDH=75% SIZE=4>
<A NAME="SYSREQ"></A><B><FONT FACE="Arial Narrow" SIZE=+3>System Requirements</FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

The following are the system requirements to install the current edition of the Platform SDK: 
<UL>
<LI>Whistler Beta 2 32-bit (Personal or Professional), Whistler Beta 2 64-bit (Professional), Microsoft� Windows� Millennium Edition (Windows Me), Microsoft Windows� 2000 (Professional or Server), Microsoft Windows NT� version 4.0 (Professional or Server), or Windows 98.
<LI>Microsoft Internet Explorer 4.02 or later.
<LI>Microsoft Windows&nbsp;Installer version 1.2 runtime executables on Windows 98, Microsoft� Windows� Millennium Edition (Windows Me), and Microsoft Windows NT� version 4.0, and native version of Microsoft Windows&nbsp;Installer on other platforms. 
<LI>A C/C++ compiler (Microsoft Visual C++<sup>&reg;</sup> 6.0 or later) to build C/C++ samples.  A pre-release C/C++ compilation system is provided to target Windows 2000 64-Bit Edition (pre-release). To gain access to the compilation system, during setup you must select <B>Win64 Development Components (pre-release)</B>.
<LI>Microsoft Visual Basic� to build Visual Basic samples. 
<LI>Approximately 1150 MB of disk space is required for a full installation, but a good deal more space is needed to compile all the samples.  Significantly more space is needed when installing to a FAT partition. However, you may reduce disk space usage by choosing the <B>Custom</B> install option and selecting only the components you need. 
</UL>





<!------ Installing - -->
<HR WITDH=75% SIZE=4>
<A NAME="INSTALLING"></A><B><FONT FACE="Arial Narrow" SIZE=+3>Installation Instructions</FONT></B>
<BR>


<!-------------- SDK Install ----------- -->
<P><B><FONT FACE="Arial Narrow" SIZE=+1>SDK Installation</FONT></B>
<BR>The Microsoft Platform SDK setup program installs the SDK headers, libraries, sample files, documentation, and tools necessary for developing applications for the Windows environment.  As mentioned in <A HREF="readme.htm#SYSREQ"><FONT FACE="Arial, Times New Roman" SIZE=2>System Requirements</FONT></A>, the Platform SDK employs the Microsoft Windows&nbsp;Installer version 1.1 and may therefore request that you first update your system before installation of the Platform SDK can proceed.
<BR>
<OL>
<LI>Uninstall any previous installations of the Platform SDK by using the Control Panel.
<LI>Run Setup.exe, found on the Platform SDK CD.
<LI>Click <B>Next</B> to start installing the Platform SDK.
<LI>Read and accept the End&nbsp;User License Agreement.
<LI>Enter your name and organization.
<LI>Choose <B>Typical</B> to install the most commonly used options, or <B>Custom</B> to be given a choice of components available for installation.
<LI>Choose the installation directory.
<LI>If you selected <B>Custom</B> install, select the components you want to install.  For more information, see "Visual C++ 6.0 IDE Directory Settings" in the <TR><TD WIDTH="100%"><B><A HREF="readme.htm#NEWS"><FONT FACE="Arial, Times New Roman" SIZE=2>Release Notes</FONT></A></B></TD></TR>.
<LI>Click <B>Next</B> to begin installation of the Platform SDK files.  
</OL>


<BR>
<!-------------- Troubleshooting the Platform SDK Install ----------- -->
<P><B><FONT FACE="Arial Narrow" SIZE=+1>Troubleshooting the PSDK Installation</FONT></B>
<BR>If you receive a 1603 error from the Windows Installer (InstMSI.exe) and are installing on Microsoft Windows� 2000 or Microsoft Windows NT� version 4.0, try restarting your system and logging on with an account that is a member of the local Administrators group.
<BR>
<P>To ensure that existing system environment variables are preserved when installing the Platform SDK on Windows 98, you may need to expand the environment space (depending on your specific configuration, by as much as 4k), if you also select "Register Environment Variables" during installation.  

<!------ What's New - -->
<HR WITDH=75% SIZE=4>
<A NAME="WHATSNEW"></A><B><FONT FACE="Arial Narrow" SIZE=+3>What's New</FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

This edition of the Platform SDK also supports development on and for Whistler Beta 2 (32-bit and 64-bit).  Whistler Beta 2 (64-bit) development is <em><b>ONLY</b></em> available on Microsoft Windows� 2000 and Whistler Beta 2 (64-bit).  For a complete list of new content in this release, please refer to the <B>What's New</B> section in the Platform SDK documentation. For a list of the pre-release content contained in this edition of the Platform SDK, see <A HREF="readme.htm#PRERELEASE"><FONT FACE="Arial, Times New Roman" SIZE=2>Pre-release Content</FONT></A>.  For more information on developing for Whistler Beta 2 (64-bit), please refer to the <B>Development Guides</B> section of the Platform SDK documentation.
<BR><BR>

<P>
This edition of the Platform SDK supports development for Whistler Beta 2 (32-bit and 64-bit) by providing an additional set of headers and libraries for those platforms that represent any new content or any changes from the released versions of these same files.  

<P>This means you can develop an application for Microsoft� Windows� Millennium Edition (Windows Me), Microsoft Windows� 2000, Microsoft Windows NT� version 4.0, Windows 98, or Windows 95 without the risk of inadvertently developing an application that requires some feature available only on Whistler Beta 2 (32-bit or 64-bit) because separate headers and libraries are used.

<P>
For important <em><b>NEW</b></em> information about building applications with this edition of the Platform SDK, please refer to the <A HREF="readme.htm#NEWS"><FONT FACE="Arial, Times New Roman" SIZE=2>Release Notes</FONT></A>, paying particular attention to the first four subsections.


<!------ Pre-Release Content - -->
<HR WITDH=75% SIZE=4>
<A NAME="PRERELEASE"></A><B><FONT FACE="Arial Narrow" SIZE=+3>Pre-Release Content</FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

This edition of the Platform SDK includes a significant amount of pre-release content, allowing developers to start their application development without waiting until a technology is released. Of course, as with any pre-release content, changes can and do occur prior to the final release.  As a result, developers must be aware of this and fully test their applications using the final released content.  Please refer to the <TR><TD WIDTH="100%"><B><A HREF="readme.htm#LICENSE"><FONT FACE="Arial, Times New Roman" SIZE=2>License Agreements</FONT></A></B></TD></TR> for more details about released and pre-release content in the Platform SDK. 
<P>
This edition of the Platform SDK contains the following pre-release content:
<UL>
<LI>64-bit development environment, including 64-bit headers, libraries, and tools.  
<UL>
<LI>A compilation system based on a pre-release version of a 64-bit compiler and linker.  These tools <em><b>ONLY</b></em> run on Microsoft Windows� 2000 and Whistler Beta 2 (64-bit) and no other Windows operating system.
<LI>Headers and libraries to develop applications targeted towards Whistler Beta 2 (64-bit). 
<LI>Headers, libraries, source, and runtimes for ATL, CRT, and MFC designed for Whistler Beta 2 (64-bit).
<LI>Two debuggers that can be used for debugging your Whistler Beta 2 (64-bit) application.
</UL>  
<LI>Headers and libraries to develop applications targeted towards Whistler Beta 2 (32-bit).  For the exact set of headers and libraries, please refer to the include\prerelease and lib\prerelease directories on a Platform SDK installation.
</UL>

<P>
The Platform SDK documentation distinguishes pre-release content from released content.  For more information, please refer to the <B>Preliminary Information</B> subsection under the <B>Getting Started</B> node in the Platform SDK documentation.  Additionally, some pre-release material is a documentation-only preview to provide you with advance notice of new functionality to come.

<P>
Pre-release headers and libraries are separated from released headers and libraries by placing pre-release content in special pre-release subdirectories under <EM>%MSSDK%\include</EM> and <EM>%MSSDK%\lib</EM>.  

<P>During installation, both released and pre-release headers and libraries are installed. (Note: 64-bit headers, libraries, and tools are installed only if you select "Win64 Development Components (pre-release)" during setup.)  This allows you to target your application development to use the latest pre-release content (such as Whistler) or to use only headers and libraries for products that have been released (for example, Microsoft� Windows� Millennium Edition, Microsoft Windows� 2000, Microsoft Windows NT� version 4.0, Windows 98, or Windows 95).

<BR><BR>




<!-------------------- Release Notes  ------------ -->
<HR WITDH=75% SIZE=4>
<A NAME="NEWS"></A><B><FONT FACE="Arial Narrow"><FONT SIZE=+3>Release Notes</FONT></FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Building Applications with the Platform SDK</FONT></B>
<BR>This edition of the Platform SDK targets development for Whistler Beta 2 (32-bit or 64-bit), Microsoft� Windows� Millennium Edition (Windows Me), Microsoft Windows 2000, Microsoft Windows NT� version 4.0, and Windows 98 operating systems; the Microsoft BackOffice� family of products, and Microsoft Internet Explorer version 4.<i>x</i> and later.  

<UL>
<P>
<LI>
The details of configuring compile and link time options can be found in the <B>Getting Started</B> section of the Platform SDK documentation as well as in Win32.mak, which is located in <EM>%MSSDK%\include</EM>.  

<P>
<LI>
Starting with the Whistler Beta 1 edition of the Platform SDK, several new shortcuts were added to the Platform SDK menu (Start | Programs | Microsoft Platform SDK) to open up specially configured command windows for building applications on the command line.  These command windows allow you to specifically target development on Microsoft Windows� 2000, Microsoft� Windows� Millennium Edition (Windows Me), Whistler Beta 2 (32- or 64-bit).  Please note that these shortcuts allow you to specify whether you want to build an application with debugging enabled (Debug) or without debugging enabled (Release).  Please note that not all command windows are available on all Windows platforms, please refer to <em>Building 64-bit Applications with the Platform</em> SDK later in this document for more details.

<P>
<LI>
Starting with the Whistler Beta 1 edition of the Platform SDK, the <B>Setenv.bat</B> batch script was enhanced (along with Win32.mak) to allow you to specifically target Microsoft Windows 2000, Microsoft� Windows� Millennium Edition, and Whistler Beta 2 (32-bit or 64-bit) platforms.  Not only are the locations of the <EM>include</EM>, <EM>lib</EM>, and <EM>path</EM> environment variables set, but so too are a few other environment variables (when using win32.mak in your makefile) to ensure that at compile-time, <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and <EM>WIN32_WINDOWS</EM> are set appropriately.  For an explanation of how to set <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and/or <EM>WIN32_WINDOWS</EM>, please refer to the <B>Getting Started</B> section of the Platform SDK documentation for more details.

<P>
<LI>
To target a platform not built in to Setenv.bat, just set the <EM>include</EM> and <EM>lib</EM> to point to the set of headers and libraries you want to use, and update either your makefile or your source files to set the defines, <EM>WINVER, WIN32_IE, WIN32_WINNT</EM>, and/or <EM>WIN32_WINDOWS</EM> as appropriate for your target platform(s).  For example to target an older platform, such as Microsoft Windows NT� version 4.0, Windows 98, or Windows 95, you will need to set the include and lib environment variables to point to <EM>%MSSDK%\include</EM> and <EM>%MSSDK%\lib</EM> respectively, and then set <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and/or <EM>WIN32_WINDOWS</EM> in your makefile (or Visual C++ project) as appropriate, based on what platform(s) you want to target.  For an explanation of how to set <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and/or <EM>WIN32_WINDOWS</EM>, please refer to the <B>Getting Started</B> section of the Platform SDK documentation for more details.  

<P>
<LI>
To target multiple platforms, you will need to choose the least common denominator with regard to environment settings.  For example, to target Whistler Beta 2 (32-bit) and a released platform such as Microsoft Windows NT� version 4.0 you would not use any pre-release headers or libraries.  Furthermore, you would need to set <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and/or <EM>WIN32_WINDOWS</EM> as appropriate for Microsoft Windows NT� version 4.0 and the version of Internet Explorer you want to support.  This would mean that you would not take advantage of any new features of Whistler Beta 2 (32-bit).

<P>
<LI>
Please remember that when you target an application to run on a specific platform(s), it may not run on your development machine.  For example, if you decide to target an application to run on Whistler Beta 2 (32-bit) it would not run on Windows 98.

<P>
<LI>
If you neither run setenv.bat nor select one of the Platform SDK menu shortcuts to open a build command window, then the default settings in win32.mak will be to target Microsoft Windows� 2000 and Internet Explorer 5.0.

</UL>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Visual C++� 6.0 IDE Directory Settings and Registering Environment Variables during Custom Setup</FONT></B>
<BR>
During a Custom setup, you will have the option to update your Visual C++� 6.0. Choosing this option makes a global change to Visual C++� 6.0 settings that places the Platform SDK library, executable directories, and include directories at the beginning of the list of 
directories searched by Visual C++� 6.0 when building programs in the IDE.

<P>
With the new layout of the <em>include</em>, <em>lib</em>, and <em>bin</em> directories to accommodate pre-release content, choosing to update your Visual C++� 6.0 
or registering environment variables during a custom setup results in setting the Visual C++� 6.0 build environment or command line build environment respectively, only for  released operating systems, namely Microsoft� Windows� Millennium Edition (Windows Me), Microsoft Windows� 2000, Microsoft Windows NT� version 4.0, Windows 98, or Windows 95.  Remember that only the location of <EM>include</EM>, <EM>lib</EM>, and <EM>path</EM> are set, and to target a specific platform, you still must set (as in previous editions of the Platform SDK) <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and/or <EM>WIN32_WINDOWS</EM>.  For an explanation of how to set <EM>WINVER, WIN32_IE, WIN32_WINNT,</EM> and/or <EM>WIN32_WINDOWS</EM>, please refer to the <B>Getting Started</B> section of the Platform SDK documentation for more details. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Building 64-bit Applications with the Platform SDK</FONT></B>
<BR>This edition of the Platform SDK will allow you to target Whistler Beta 2 (64-bit).  It supports the new 64-bit data types and a pre-release version of a Visual Studio 64-bit compiler, linker, libraries and remote debugger.  The Platform SDK <em><b>MUST</b></em> be installed on Microsoft Windows� 2000 or Whistler Beta 2 (64-bit) to target Whistler Beta 2 (64-bit).  
The 64-bit .dlls (such as ATL, CRT, and MFC) located in the Platform SDK redist directory may be loaded onto a 64-bit target machine for development purposes only, and are not otherwise redistributable.  None of the tools to support 64-bit development are redistributable.  Products built with these tools may not be commercially distributed.  

<UL>
<P><LI>
To set up your development environment to target Whistler Beta 2 (64-bit), you must either open up a "Win64 Pre-release Build Environment" command window or run the Setenv.bat batch script with the /pre64 switch.  This command window will <em><b>ONLY</b></em> be available on Microsoft Windows� 2000 or Whistler Beta 2 and no other Windows operating system.  Additionally the /pre64 switch to setenv.bat will return an error if run on any Windows operating system other than Microsoft Windows� 2000 or Whistler Beta 2. Whistler Beta 2 (32-bit) is <em><b>NOT</b></em> a supported configuration for developing applications for Whistler Beta 2 (64-bit).  

<P><LI>The <B>Setwin64.bat</B> batch file has been replaced by <B>Setenv.bat</B> with the /pre64 switch.  

<P><LI>
Applications built to target Whistler Beta 2 (64-bit) will not run on any other version of Windows.

<P><LI>
For details about the 64-bit compilation tools (compiler and debugger), please <B>first</B> install the Platform SDK, selecting the "Win64 Development Components (pre-release)." Then refer to the document <A HRef="bin\prerelease\Win64\Readme.doc">Microsoft C/C++ IA-64 Compiler and Debugger Release Notes (pre-release)</A>. &nbsp;&nbsp;

<P><LI>
In order to get the correct compile-time flags to test your code, you should include Win32.mak in your makefiles. Win32.mak is in the <EM>%mssdk%\Include</EM> directory of the CD-ROM and will be in <EM>%mssdk%\Include</EM> after you install the SDK.   If you do not use Win32.mak, you will need to modify your compiler command line appropriately.  


<P><LI>
Typical compiler warnings that indicate improper handling of 64-bit data are the following:
<PRE>
warning C4305: 'return' : truncation from 'unsigned __int64 ' to 'long ' 
warning C4311: 'type cast' : pointer truncation from 'int *__ptr64 ' to 'int ' 
warning C4312: 'type cast' : conversion from 'int ' to 'int *__ptr64 ' of greater size 
warning C4313: 'printf' : '%p' in format string conflicts with argument 2 of type '__int64 ' 
warning C4318: passing constant zero as the length to memset 
warning C4319: '~' : zero extending 'unsigned long ' to 'unsigned __int64 ' of greater size 
warning C4242: '=' : conversion from 'unsigned int' to 'unsigned short', possible loss of data 
warning C4244: 'return' : conversion from '__int64' to 'unsigned int', possible loss of data 
</PRE>

<P><LI>
If you reference WIN32.MAK in your makefile and use the $(cflags) environment variable, a handful of compiler warnings will be suppressed.  Please refer to %MSSDK%\Include\Prerelease\Pre64Pra.h for the list of suppressed warnings.  To re-enable these warnings, just comment out the pragma.

<P><LI>
For more information about developing applications for Whistler Beta 2 (64-bit), refer to the <B>Development Guides</B> section of the Platform SDK documentation.
</UL>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Debugging 64-bit Applications with the Platform SDK</FONT></B>
<BR>
As mentioned earlier in <TR><TD WIDTH="100%"><B><A HREF="readme.htm#PRERELEASE"><FONT FACE="Arial, Times New Roman" SIZE=2>Pre-release Content</FONT></A></B></TD></TR> section, there are 2 debuggers provided in the Platform SDK that can be used to debug Whistler Beta 2 (64-bit) applications:
<UL>
<LI>A remote debugger based on a pre-release version of Visual Studio� is available for Microsoft Windows� 2000 <em><b>ONLY</b></em>. This tool is installed when the component "Win64 Development Components (pre-release)." is selected during setup.  For information about how to setup and use this debugger, please <B>first</B> install the Platform SDK, selecting the "Win64 Development Components (pre-release)." Then refer to the document <A HRef="bin\prerelease\Win64\Readme.doc">Microsoft C/C++ IA-64 Compiler and Debugger Release Notes (pre-release)</A>. &nbsp;&nbsp;
<LI>Debugging Tools for Windows contains WinDbg, Kd, and Cdb for debugging Windows NT 4.0, Windows 2000, and Windows Whistler.  This package is available in both the 32-bit and the 64-bit SDK by selecting Debugging Tools for Windows Beta during setup.  In addition the 64-bit SDK has a 64-bit native package that is required for debugging 32-bit and 64-bit user-mode applications running on an ia64 processor.  This package is available by selecting Debugging Tools for Windows 64-bit Beta during setup.  Please see <a href="http://www.microsoft.com/ddk/debugging"> http://www.microsoft.com/ddk/debugging</a> for more information about the tools.
</UL>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Whistler Beta 2 (64-bit) Fault Alignment</FONT></B>
<BR>
The system unhandled alignment fault handler is turned off by default. This means that any unaligned data accesses that occur in an application will generate an exception and will not automatically be fixed up by the system if you do not install an unhandled exception filter in your application with the SetUnhandledExceptionFilter or catch the exception in a __try/__except block. You can turn on the system alignment fault hander on a per-process basis by calling SetErrorMode(SEM_NOALIGNMENTFAULTEXCEPT). Please note that your process may experience severe performance degradation if you turn on the system alignment fault handler and your process generates alignment faults.
<P>
If you have installed the new Windbg debugger as your system debugger, Windbg will automatically be launched if any process on the system generates an unhandled exception of any kind. If you do not have a debugger installed as your system debugger, you will receive a dialog stating that your executable has encountered an error and ask if you want to report the problem to Microsoft.  

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Tested Compilers</FONT></B>
<BR>The Platform SDK has been tested with Visual C++� 6.0 Service 
Pack 4. Some samples may not build without applying Visual Studio Service Pack 4. 
See <a href="http://msdn.microsoft.com/vstudio/" target="_top">http://msdn.microsoft.com/vstudio/</a> for more information about Visual Studio service packs.
Samples can be built with other compilers, but other compilers 
were not completely tested. 
<P>
If you are using Visual C++ 5.0, it is recommended that you upgrade to Visual C++ 6.0.  The import libraries included with this release of the Platform SDK have a different format than that used by Visual C++ 5.0, which improves performance and decreases storage requirements.  


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Common Compile-time Warnings</FONT></B>
<BR>
<UL>
<LI>Do not use <I>MakeProcInstance</I>. Instead, pass DLGPROC directly (the first parameter to <I>MakeProcInstance</I>).  Also, be sure to delete the <I>FreeProcInstance</I> function that is paired with <I>MakeProcInstance</I>.
<LI>Explicit casts are now necessary in many situations in which intrinsic casts worked before, such as casting DLGPROC.
</UL>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>MFC Unicode Libraries</FONT></B>
<BR>Some samples require that you install the Unicode MFC libraries. You can
select them during a custom Visual C++ installation. If you do not install these 
libraries, building samples that need them generates an error similar to the 
following:
<BR><P>LINK : fatal error LNK1104: cannot open file "MFC42ud.lib"


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Exception Handling</FONT></B>
<BR>
Previous releases of the Platform SDK included
the following definitions in Win32.mak to map structured exception
handling keywords to their proper underscored names:
<PRE>
    try -> __try 
    except -> __except 
    finally -> __finally 
    leave -> __leave
</PRE>
This caused problems for developers who chose to use C++ 
structured exception handling in which "try" is supposed to
be "try" rather than "__try". For this reason, by default, 
the mapping has been removed from Win32.mak. This may
cause compile-time errors for your applications. If this causes problems with your application, you can obtain the old behavior by adding the following to your makefile before including Win32.mak: 
<PRE>
    SEHMAP = TRUE 
</PRE>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM Use of SChannel Protocols</FONT></B>
<BR>
For a client to use any of the SChannel protocols, it must specify SChannel as the authentication service in its call to CoInitializeSecurity. The client must also call CoSetProxyBlanket, again specifying SChannel as the authentication service. The call to CoSetProxyBlanket must be made even if you are not changing the parameters from when CoInitializeSecurity was called.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Application Partitions on Whistler Professional and Personal Computers</FONT></B>
<BR>
You can create COM+ application partitions on Whistler Server computers, but not on Whistler Professional or Personal computers. However, you can administer COM+ application partitions on a Whistler Server computer remotely from a Whistler Professional or Personal computer.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Application Partitions Installation of Long Application Names</FONT></B>
<BR>
Due to a bug in Whistler Beta 2, it is not possible to install a COM+ application with a name longer than 12 characters into any COM+ application partition other than a base application partition. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Application Partitions Visual Basic Debugging</FONT></B>
<BR>
COM+ does not currently support the debugging of Visual Basic applications that are in a partition other than the base application partition. For Visual Basic application development, debug and test the application in the base application partition. When development is completed, move the application to another partition. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Application Export</FONT></B>
<BR>
A COM+ application export can fail with the following message: 
<pre>
	Error occurred writing to the application file. 
</pre>
This can occur if the same type library is registered with two different paths under the HKEY_CLASSES_ROOT\TypeLib key and the HKEY_CLASSES_ROOT\CLSID\{}\TypeLib key. An example of this is short file name versus long file name or different capitalization in the paths. This should not affect components generated by Visual Basic. The workaround is to either write the same path to both the type library and the class registration key by changing the component's self-registration code, or to manually modify one of the registry keys using Regedit.exe before exporting the application.

<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Bring Your Own Transaction</FONT></B>
<BR>
When using Bring Your Own Transaction (BYOT), do not begin the transaction inside a COM+ configured component. Beginning the transaction inside a COM+ configured component can lead to deadlock conditions. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Synchronization </FONT></B>
<BR>
In a component with synchronization, avoid calling out of IObjectControl::Deactivate. Consider the following example where deadlock may occur: 
<p>
Component A, B, and C are hosted in their own COM+ applications (implying they are hosted by their own processes) and reside in the same synchronization domain. Avoid application designs where component A can call into Component C directly and indirectly through Component B. This is because the following situation might occur:
<ul>
<li>A calls B, which calls C 
<li>B dies 
<li>A's call to B returns (with failure) 
<li>A proceeds to call into C directly 
</ul>
COM+ detects the second call into C as having the same logical thread ID as the first call and therefore allows the reentrancy, but nevertheless this creates a situation where there may actually be two physical threads of execution running inside C. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>COM+ Subscriptions and Event Firing</FONT></B>
<BR>
The following scenario causes an infinite loop: If you subscribe to IComMethodEvents and you have events enabled for your subscription, your method will continually loop. By default, Events and Statistics are enabled for any component, unless declaratively specified. The workaround is to disable Events and Statistics for the subscriber. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Web and Internet Samples</FONT></B>
<BR>
To compile and run some of the C/C++ Web and Internet samples, you will need to include the Platform SDK header and library files for Win32 and Internet Explorer in your development environment.  To obtain the full set of header and library files necessary to build the C/C++ projects, you will need, at minimum, to install the 'Build Environment' section of the Platform SDK.
<p>
For new and updated Web samples, visit the MSDN Online Web & Internet Samples site at <a href="http://msdn.microsoft.com/downloads/samples/internet/default.asp">http://msdn.microsoft.com/downloads/samples/internet/default.asp</a>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>DirectX</FONT></B>
<BR>
<UL>
<LI><B>DirectX Redistributable Runtimes</B>.  The DirectX redistributable runtime installation can be downloaded from <a href="http://msdn.microsoft.com/code/sample.asp?url=/msdn-files/027/001/551/msdncompositedoc.xml">http://msdn.microsoft.com/code/sample.asp?url=/msdn-files/027/001/551/msdncompositedoc.xml</a>.

<LI><B>Building Visual Basic DirectX Samples</B>. To build the Visual Basic DirectX samples, you may need to register one or more controls located in the \Bin\DirectX\VBSupport directory after installing the DirectX Visual Basic samples. You can use RegSvr32.exe to register controls. These controls will not be registered during setup.

<LI><B>DirectShow Base Classes</B>.  The DirectShow base classes (strmbase.lib and strmbasd.lib) ship in two forms with the Platform SDK.  Binary libraries are available in the LIB directory, but source code is also available in the Samples\Multimedia\DirectShow\BaseClasses subdirectory.  The two library files provided with the PSDK may be built with an updated version of the base classes source code, which may not perfectly match the source code provided in the sample directory.  Therefore, if you want to modify the base classes or single-step through them while debugging a DirectShow-based application or filter, you should rebuild the library using instructions provided in the Samples\Multimedia\DirectShow root directory.  If you rebuild the library from the supplied source, be sure to link with the updated version of strmbase.lib (or strmbasd.lib, for debug builds) and not the version supplied in the Platform SDK LIB directory.

<LI><B>DirectX 8 Registry Keys</B>. The Platform SDK sets the registry key HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\DirectX\DX8SDK Samples Path when installed.  This is to ensure that applications can be properly developed and run on your machine.

<LI>Additional DirectX information is available in the file %MSSDK%\dxreadme.txt after you install the Platform SDK.

</UL>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Active Directory/ADSI Release Notes</FONT></B>
<BR>In order to run the ADSI Viewer tool (\Bin\adsvw.exe) on platforms other than 
Windows 2000, you must first install the ADSI client software. The client 
software can be downloaded from the following location: 
<a href="http://www.microsoft.com/ntserver/nts/downloads/other/ADSI25/default.asp" target="_top">http://www.microsoft.com/ntserver/nts/downloads/other/ADSI25/default.asp</a>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Windows Media Services</FONT></B>
<BR>To download the complete suite of Windows Media Services, see the 
Windows Media� Technologies page at the Microsoft site 
<a href="http://www.microsoft.com/windows/windowsmedia/" target="_top">http://www.microsoft.com/windows/windowsmedia/</a>.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>BizTalk Samples and Tools</FONT></B>
<BR>The Microsoft� BizTalk� Server 2000 sample files, tools, and associated readmes must be used with a running installation of BizTalk Server 2000. To evaluate the samples and tools, you can download a copy of BizTalk Server 2000 Evaluation Edition from the Microsoft BizTalk Server Web site <a href="http://www.microsoft.com/biztalk"target="_top">(http://www.microsoft.com/biztalk)</a>. The Evaluation Edition contains all the BizTalk Server sample files and tools. BizTalk documentation can be found in the Platform SDK. 

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Commerce Server 2000 Samples and Tools</FONT></B>
<BR>The Microsoft� Commerce Server 2000 sample files, tools, and associated readmes must be used with a running installation of Commerce Server 2000. To evaluate the samples and tools, you can download a copy of Commerce Server 2000 Evaluation Edition from the Microsoft Commerce Server Web site <a href="http://www.microsoft.com/commerceserver"target="_top">(http://www.microsoft.com/commerceserver)</a>. The Evaluation Edition contains all the Commerce Server sample files and tools. Commerce Server documentation can be found in the Platform SDK.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Universal Plug and Play Release Notes</FONT></B>
<BR>For more information about Universal Plug and Play (UPnP), please visit 
<a href="http://www.upnp.org/" target="_top">http://www.upnp.org/</a>.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Visual Basic Command-line Makefiles</FONT></B>
<BR>
Some of the Visual Basic� samples have command-line makefiles. To 
build these samples from the command line, you must include Vb6.exe in your path.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Microsoft� SDK for Java 4.0 </FONT></B>
<BR>Some samples may require Microsoft SDK for Java. For more information, visit
<a href="http://www.microsoft.com/java/" target="_top">http://www.microsoft.com/java/</a>.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Broadcast Architecture</FONT></B>
<BR>The Broadcast Architecture documentation is now located within the DirectShow documentation under the name "Microsoft TV Technologies."

<P><B><FONT FACE="Arial Narrow" SIZE=+1>
Isolated Applications & Side by Side Assemblies</FONT></B><BR>
The formats for Win32 Application, Assembly and Configuration manifests have changed. If you previously created a manifest file for Whistler Beta 1, you will need to update your manifest to reflect the new format. For more information, see the topic "Manifest File Format" in the Whistler Beta 2 documentation of the Platform SDK.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>
Side by Side/Theming Applications</FONT></B><BR>
More documentation on Side by Side/Theming Applicaions is available at  <a href=http://www.devx.com/whistler/>http://www.devx.com/whistler/</a>.

<P>

<BR><BR>




<!-------------------- Known Issues  ------------ -->
<HR WITDH=75% SIZE=4>
<A NAME="ISSUES"></A><B><FONT FACE="Arial Narrow"><FONT SIZE=+3>Known Issues</FONT></FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">


<P><B><FONT FACE="Arial Narrow" SIZE=+1>64-bit Application Development</FONT></B>
<BR>
<UL>
<LI>The Visual Basic 6.0 samples are not supported on Whistler Beta 2 (64-bit).
</UL>


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Developing 32-bit Applications on Whistler Beta 2 (64-bit)</FONT></B>
<BR>
If you attempt to develop a 32-bit C/C++ application on Whistler Beta 2 (64-bit) do not select to register environment variables when you install Microsoft Visual C++<sup>&reg;</sup> 6.0.  Instead, to set your desired 32-bit build environment, open a command session and run vcvars32.bat found in the Visual C++ product \bin folder to set the environment variables, followed by setenv.bat in the Platform SDK product folder, specifying the appropriate switch (/pre32 /2000 /me).  


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Conflicts Between Edbbcli.h and Ntdsbcli.h</FONT></B>
<BR>
C/C++ modules or header files which include both Edbbcli.h (Exchange backup 
client definitions) and Ntdsbcli.h (NTDS backup client definitions) will 
encounter conflicts between the two files. The following symbols are multiply 
defined:
<UL>
<LI>BFT_PATCH_FILE
<LI>tagEDB_RSTMAPA
<LI>tagEDB_RSTMAPW
</UL>
<P>
A solution to work around this problem is to only include one or the other of 
these header files in the same compilation unit. Generally, each of these two 
header files relates to different backup functionality.  It should be possible 
to partition the application such that the functionality dealing with Exchange 
is in a separate module from the functionality dealing with NTDS.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Compilation Error with Adoint.h</FONT></B>
<BR>
Adoinit.h cannot be properly compiled when used in a project of only C files, but requires a project of C++ files instead.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Winsock2.h and Windows.h Issue</FONT></B>
<BR>
Applications built targeting Windows Sockets 2 should #include Windows.h after Winsock2.h or not at all.  Including Windows.h prior to Winsock2.h will result in compile-time errors. 


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Sample Compile Errors and Dependencies</FONT></B>
<UL>
<LI>The BYOT samples do not function with a local SQL server. To run and test the 
BYOT samples, install and configure a remote SQL Server according to the 
sample documentation.

<LI>The \Samples\Web\SiteServer\ContentDeployment\VB\EventSink\FileSink samples will not build until the following controls from the Site Server 3.0 product are installed:
<OL>
<LI>Microsoft Site Server\Bin\Crsapi.dll -- Site Server 3.0 Content Deployment Object Library
<LI>Microsoft Site Server\Bin\SSEVENT.dll -- Site Server 3.0 Server Event Type Library
</OL>

<LI>The \Samples\DbMsg\CDO\Transport Event Registration sample requires that the Server Extension Objects COM Library control (\System32\Inetsrv\Seo.dll) is installed.  This control is installed by Windows 2000 and the Windows NT 4.0 Server Option Pack.

</UL>

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Building Samples Applications with the Platform SDK</FONT></B>
<BR>
Samples that are not intended to run on specific Windows Platforms as well as samples that do not build cleanly for certain platforms (for example, some samples that build cleanly for the 32-bit platforms do not for Whistler Beta 2 (64-bit) have been disabled in win32.mak from building for those platforms. The actual list of samples is identified in the files I386Win955_0.txt, I386WinNT5_0.txt, I386WinNT5_01.txt, and I64WinNT5_01.txt located in %MSSDK%\Samples.

<P><B><FONT FACE="Arial Narrow" SIZE=+1>InlineIsEqualGUID:Ambiguous Call to Overloaded Function</FONT></B>
<BR>
If you encounter the following error when using the Platform SDK and ATL, please review  <a href="http://support.microsoft.com/support/kb/articles/Q243/2/98.ASP">FIX: Error Message: C2668: InlineIsEqualGUID: Ambiguous Call to Overloaded Function</a> for a complete description of the problem and the workaround available. 
<pre>
	C2668: 'InlineIsEqualGUID' : ambiguous call to overloaded function 
</pre>

<P><B><FONT FACE="Arial Narrow" SIZE=+1>GDI+ Graphics.DrawImage()</FONT></B>
<BR>
The documentation for Graphics.DrawImage() incorrectly states that you can pass coordinates for an arbitrary convex quad. This is not supported - rather you must pass three points which describe the upper left, upper right, and lower left corners.  
<BR><BR>



<P><B><FONT FACE="Arial Narrow" SIZE=+1>Web Storage System Conferencing Headers and Samples</FONT></B>
<BR>The Web Storage System (WSS) conferencing headers and samples are not included in this release of the Platform SDK. They can be found at <a href=http://www.microsoft.com/exchange/downloads>http://www.microsoft.com/exchange/downloads</a>. 

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Internet Connection Sharing Interfaces and Methods</FONT></B>
<BR>

Although the Platform SDK documents the following Internet Connection Sharing (ICS) interfaces and methods, these interfaces and methods are not supported not supported by the operating system: 
<P><ul>
<li>IEnumNetSharingApplicationDefinition 
<li>INetSharingApplicationDefinition 
<li>INetSharingApplicationDefinitionCollection 
<li>INetSharingApplicationDefinitionProps 
<li>INetSharingApplicationDefinitionResponseRangeProps 
<li>INetSharingManager::CreateBlankApplicationDefinition 
<li>INetSharingManager::EnumApplicationDefinitions 
</li></ul><P>

<P><B><FONT FACE="Arial Narrow" SIZE=+1>MMC Snap-in Designer for Visual Basic</FONT></B>
<BR>
If the <b>New Project</B> dialog doesn't present a <b>SnapIn</b> project, then copy the files located in your C:\Program Files\Microsoft Platform SDK\Samples\SysMgmt\MMC\Visual Basic\Template\ directory to your C:\Program Files\Microsoft Visual Studio\VB98\Template\Projects\ directory. Substitute equivalent paths if your installation of the Platform SDK or Visual Basic did not use the paths listed here.

<P><B><FONT FACE="Arial Narrow" SIZE=+1>dxguid.lib for Whistler Beta 2 (64-bit)</FONT></B>
<BR>
The DirectX file dxguid.lib for Whistler Beta 2 (64-bit) is not included and therefore applications or samples depending upon this for Whistler Beta 2 (64-bit) will not build.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>comdlg32.ocx Removed on Upgrade</FONT></B>
<BR>
The file comdlg32.ocx located in %MSSDK%\Bin\DirectX\VBSupport may be removed if upgrading from an earlier edition of the Platform SDK.  A clean install of the Platform SDK will resolve this.


<P><B><FONT FACE="Arial Narrow" SIZE=+1>Building COM Samples on Windows 98 on Windows ME</FONT></B>
<BR>
The COM samples located in %MSSDK%\Samples\COM should not be built on Windows 98 or Windows ME, though they can be built on Whistler Beta 2 32-bit (Personal or Professional), Microsoft Windows� 2000 (Professional or Server), or Microsoft Windows NT� version 4.0 (Professional or Server) to target Windows 98 or Windows ME (except for Com\Fundamentals\DCom\TimeOuts\PingResp).


<!--- Archive --->
<HR WITDH=75% SIZE=4>
<A NAME="ARCHIVE"></A><B><FONT FACE="Arial Narrow" SIZE=+3>Online Download</FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Redistributables</FONT></B>
<BR>
The Microsoft Platform SDK, February 2001 Edition will be the last to ship redistributable components as an integral part of its setup.  Instead these redistributable components will be available to you and your customers online with directions in the Platform SDK about where and how to obtain them.  The redistributable components in question currently are located under %MSSDK%\Redist.

<P><B><FONT FACE="Arial Narrow" SIZE=+1>Archive</FONT></B>
<BR>
Periodically content will be placed in an online archive for download and therefore removed from the current Platform SDK. The purpose of this is to ensure that the Platform SDK content remains current, while enabling older content to become available for customers who may need it.  To view a complete list of archived content available for download, such as MAPI and Exchange 5.5 samples, please go to the <a href="http://www.microsoft.com/downloads/search.asp?LangID=20&LangDIR=en-us&OpSysID=925&Search=Keywords&Value=Platform SDK Archive&Show=Alpha&Start=&AddLangID=20  
 ">Platform SDK Archive</a>.


<!-------------------- Developer Support  ------------ -->
<HR WITDH=75% SIZE=4>
<A NAME="DEVSUPPORT"></A><B><FONT FACE="Arial Narrow"><FONT SIZE=+3>Developer Support</FONT></FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

For information on Microsoft Developer Support, see 
<a href="setup/html/support.htm">Support.htm</a>.
<BR><BR>




<!-------------------- License Agreement  ------------ -->
<HR WITDH=75% SIZE=4>
<A NAME="LICENSE"></A><B><FONT FACE="Arial Narrow"><FONT SIZE=+3>License Agreements</FONT></FONT></B>
<BR><BR><FONT FACE="Arial, Times New Roman">

The software products included on the enclosed compact disc are licensed to
you, the end user. Your use of the software products are subject
to the terms of an End&nbsp;User License Agreement (&quot;EULA&quot;)
accompanying the software products and located in the \License
subdirectory on the CD. You must read and accept the terms of
the EULA before you access or use the software products. If you
do not agree to the terms of the EULA, you are not authorized to
use the software product. 
<p>View the <a href="license/license.txt" target="contents">license</a> agreement.
<BR><BR>




<!-------------------- Feedback  ------------ -->
<HR WITDH=75% SIZE=4>
<A NAME="FEEDBACK"></A>
<B><FONT FACE="Arial Narrow"><FONT SIZE=+3>Feedback</FONT></FONT></B>

<P>Mail bug reports or suggestions for the Platform SDK 
to <a href="mailto:SdkFdbk@microsoft.com">SdkFdbk@microsoft.com</a>, and let us know
if there is a particular Microsoft technology or SDK that you would like to see included in the Platform SDK.
<BR><BR>


<HR width="90%"></BODY></HTML>

<BR> 
<CENTER><FONT FACE="ARIAL,HELVETICA"><font size=1>&copy;2000 Microsoft Corporation. <a href="http://www.microsoft.com/info/cpyright.htm" target="_top">Legal Notices.</font></a></font></CENTER>
