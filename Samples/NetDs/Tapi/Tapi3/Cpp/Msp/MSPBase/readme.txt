______________________________________________________________________________

  Copyright (C) 2000 Microsoft Corporation. All rights reserved.

______________________________________________________________________________



Media Streaming Provider Base Classes



Overview:


These are the sources for Media Streaming Provider Base Classes.

See Platform SDK and SampleMSP sample for more information on using MSP Base
Classes for writing Media Streaming Providers.



Building MSP Base Classes


To build MSP Base Classes, set up Platform SDK build environment, then run nmake
from the MSPBase directory. This will build MSPBaseSample.lib. 

Note that MSPBase' headers can be found in Platform SDK's include directory.



Building Your MSP with MSP Base Classes


Your MSP should link with the lib file produced from building MSP Base Classes.

Platform SDK includes mspbase.lib file which was produced by building MSP Base
Classes with ATL 2.1. If you are using ATL2.1 for building your MSP, you can
link your MSP to this file without building your own version from MSPBase
sources.

If you want to use a different version of ATL or want to make changes to the 
base classes, you should build your MSP Base Classes in MSPBase directory and
link your Media Streaming Provider DLL to the resulting lib file.

SampleMSP is an example of an MSP that uses a custom-built msp.

Note that the the same version of ATL must used to build your MSP and MSPBase
library linked to it.