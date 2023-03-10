	Shellwalk is a namespace verification tool used to find bugs in namespace implementations.  
It recursively descends through the namespace performing Folder, Item, PIDL, and COM related tests 
on every folder item it encounters.  It can be run in an exhaustive test pass mode, or in a walk 
mode that is directed at a specific location.  It logs through the LOR logging utility, creating
a list of all failures that can be viewed later.

Executable: ShellWalk.exe
Command Line Flags:
	\Stress - Stress Mode.  Repeats a single threaded test pass ad. infinitum.
	\tp - Starts a single threaded test pass, and exits upon completion.

Modes:
	Leak - Leak test pass.  Requires Snapper.dll and a checked build of Windows 2000
	Stress - Stress Mode
	Test Pass - Full test pass of the entire systems namespace.
	Walk - Test run rooted at a location chosen by the user.

Tests:
Shellwalk currently tests methods on the following namespace interfaces:
	IShellFolder
	IContextMenu
	IPersist
	IPersistFile
	IPersistFolder
	IPersistFolder2
	IPersistFolder3
	IShellLink
	IEnumIDList
	IShellIcon
	IUnknown

Tests for additional interfaces will be added in future versions.

Files:
	Shellwalk.exe
	IShellwalk.dll
	LogManager.dll
	Lordll.dll
	LorLog32.dll
	LorLoggign.dll
	Snapper.dll
	LorLogging.ini
	MTShellWalk.ini

To Specify logging locations and filenames modify the fields in LorLogging.ini.