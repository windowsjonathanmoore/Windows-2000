****************************************************************
  Copyright (c)1999 Microsoft Corporation, All Rights Reserved
****************************************************************

1. What MultiSiteCfg Does & How

    The MultiSiteCfg tool is the most complex of all the SMS sample apps.  It
    uses the site control manipulation methods and objects to copy the settings
    and configuration from one site to multiple other sites. It can connect to 
    a central site, and force the propigation of various site settings from one
    site to any other site in the heirarchy.  This sample makes extensive use of
    the WMI Helper classes in the \include\SshWbemHelpers.h file.

2. Running the Sample

    This sample application uses a GUI instead of command line arguments to interact
    with the user.  

    To start the application, simply run the .exe file and the GUI will load and display.

    From here, a user can select the source site from which the settings and configuration
    are taken, and a set of destination sites where the configuration and settings are
    copied to.

3. Requirements

    Runs on: NT4.0 or greater.
    WMI must be installed on the machine.

4. Building the Sample

    Using NMAKE:
	Running NMake at the command line will build the default "makefile" in
	the sample's directory.

    Using the VC++ IDE:
	Open the .DSP Project file and select Build -> Build
	

    