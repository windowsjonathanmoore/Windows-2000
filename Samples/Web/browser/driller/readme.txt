======================================================
Notes for Driller
======================================================

Driller is an MFC based control host, that hosts the 
WebBrowser Control. Built Using VC++6.0.

The functionality of drilling into the document hosted 
and listing the tags found in the listbox is discussed 
in the readme2 file for Drill.

Additional functionality that is present in the Driller 
sample is providing extra control through the implementation 
of the IDocHostUIHandler interface. This interface is 
documented in the SDK, this sample shows how this 
interface can be used to control the context menu's 
and extend the Dynamic HTML Object Model.

The Context menu's that appear as standard for a 
right mouse click are disabled within the Driller 
sample. This is achieved by returning S_OK from the 
ShowContextMenu method of the IDocHostUIHandler 
interface, indicating that the host has handled the 
call and the IE4 components need not perform the 
standard processing.

The Dynamic HTML Object Model is also extended in the 
Driller sample by providing an IDispatch interface to 
the getExternal method of the IDocHostUIhandler 
interface. This IDispatch is used whenever the script 
within the HTML document refers to window.external, 
whatever follows this will be handed to the GetIDsof 
Names member function of the IDispatch interface to be 
resolved.
This can be seen by loading the extend.htm file supplied 
into Driller and pressing the Extend button.

To implement the IDocHostUIHandler, the client site needs
to implement the interface. In MFC, the class COleControlSite
encapsulates the client site. In this example we are subclassing
MFC, a class CCustomControlSite, is derived from COleControlSite 
and CCustomControlSite implements IDocHostUIHandler. To hook
in the CCustomControlSite, a class CCustomOccManager is derived 
from COccManager. Subclassing COccManager and
COleControlSite in such a manner is implementation specific
to MFC. So, if future versions of MFC change the implementation
of COleControlSite or COccManager, this sample (and your code
if you use this technique) might not work. We are looking at 
possible ways to have MFC expose the client site for
customization. If in future MFC does expose the client
site, then we will modify this sample to use that functionality.

If you are using this sample, to design your code please be 
advised that you may have to change your code in the future.

It is possible that this sample will not compile because 
an include directory has not been identified.  The program
looks for the file called occimpl.h.  Prepended to 
the header file is the directory where that file
was located on the test machine.  This maybe different 
than most users.  The solution is to delete the prepended
directory and under project==> settings, go to the C/C++ tab, 
look under Preprocessor and then add the 
include directory to the additional include directories.  An 
example of what that might look like is:
c:\program files\devstudio\vc\mfc.
