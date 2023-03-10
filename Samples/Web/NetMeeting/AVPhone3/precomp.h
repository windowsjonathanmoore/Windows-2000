#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers


// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// link in AltAxWinInit() & containment code statically
// this require a instance (_Module) of CComModule
#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>
#include <atlhost.h>

#include <ocidl.h>
#include <assert.h>

#include "resource.h"
#include "imsconf2.h"
#include "NetMeeting.h"
#include "ClUtil.h"
#include "MgrNtfy.h"
#include "CallNtfy.h"
#include "CnfNtfy.h"
#include "Conf.h"
