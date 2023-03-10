REM This batch file generates Java/COM Integration Classes for TAPI 3.0 which are
REM used by the Tapi3 Java samples in the Platform SDK.  To run this batch file, 
REM you must have the SDK for Java installed, version 2.0 or greater.
REM Once you have installed the SDK, go to the \bin directory under the main SDK
REM install directory  and run CreateComClassesForTapi3 at the command line.


jactiveX /javatlb /xh /X:m- %windir%\system32\tapi3.dll
jactiveX /javatlb /xh /X:m- %windir%\system32\quartz.dll
jactiveX /javatlb /xh /X:m- %windir%\system32\sdpblb.dll
jactiveX /javatlb /xh /X:m- %windir%\system32\rend.dll
jactiveX /javatlb /xh /X:m- %windir%\system32\h323msp.dll
jactiveX /javatlb /xh /X:m- %windir%\system32\confmsp.dll
jvc /nomessage /x- /cp %windir%\java\classes\classes.zip;%windir%\java\trustlib %windir%\java\trustlib\tapi3\*.java
jvc /nomessage /x- /cp %windir%\java\classes\classes.zip;%windir%\java\trustlib %windir%\java\trustlib\quartz\*.java
jvc /nomessage /x- /cp %windir%\java\classes\classes.zip;%windir%\java\trustlib %windir%\java\trustlib\rend\*.java
jvc /nomessage /x- /cp %windir%\java\classes\classes.zip;%windir%\java\trustlib %windir%\java\trustlib\sdpblb\*.java
jvc /nomessage /x- /cp %windir%\java\classes\classes.zip;%windir%\java\trustlib %windir%\java\trustlib\h323msp\*.java
jvc /nomessage /x- /cp %windir%\java\classes\classes.zip;%windir%\java\trustlib %windir%\java\trustlib\confmsp\*.java
