   Windows Template Library - WTL Version 3.1         (build 0269)  09/25/00
-------------------------------------------------------------------------------
	Copyright (C) 1997-2000 Microsoft Corporation
	All rights reserved.

This file is a part of Windows Template Library. The code and information is 
provided "as-is" without warranty of any kind, either expressed or implied.
-------------------------------------------------------------------------------



Welcome to the Windows Template Library, version 3.1. This document contains
the following topics:

	1. Introduction
	2. Features And Installation
	3. Packing List
	4. Class Overview
	5. ATL/WTL AppWizard
	6. Changes Between WTL 3.0 And 3.1


1. Introduction
---------------

Windows Template Library, or WTL, is a set of classes that extend ATL to
support more complex user interfaces for either applications or various UI
components, while maintaining the big advantage of ATL - small and fast code.
WTL classes were designed to be the best and the easiest way to implement rich
Win32 based UI for ATL based applications, servers, components, and controls.

WTL provides support for implementing various user interface elements, from
frame and popup windows, to MDI, standard and common controls, common dialogs,
property sheets and pages, GDI objects, UI updating, scrollable windows,
splitter windows, command bars, etc. The WTL classes are mostly templated and
use minimal instance data and inline functions. They were not designed as a
framework, so they do not impose a particular application model, and can
accommodate any. The classes do not use hooks or thread local storage, so they
have no restrictions that those techniques impose. They also have no
inter-dependencies and can be freely mixed with straight SDK code. In summary,
WTL delivers very small and efficient code, very close in size and speed to SDK
programs, while presenting a more logical, object oriented model to a
programmer.


2. Features And Installation
----------------------------

This release brings greatly expanded set of classes, adding support for command
bars, scrollable windows, splitter windows, and bitmap buttons. The wrapper
classes for common controls and common dialogs fully support all versions,
including new Windows 2000 and Internet Explorer 5 controls. Also new is
support for printing and print preview, as well as various utility classes.

One important change is that atlapp.h now has to be included. That doesn't mean
that you have to create an application, just that atlapp.h contains base
definitions required for WTL projects.

To install WTL, just copy the whole directory structure to the location of your
choice. Please be sure to add the WTL\include directory to the list of include
directories in VC++.

To install ATL/WTL AppWizard, just copy the file appwiz\atlapp60.awx to the
custom app wizard directory in the VC++ installation,
%VCDIR%\Common\MSDev98\Template, where %VCDIR% is the directory where VC++ 6.0
is installed. It will then appear in the list of App Wizards when you select
File.New and choose the Project tab.


3. Packing List
---------------

readme.txt		this file

include\
	atlapp.h	message loop, interfaces, general app stuff
	atlcrack.h	message cracker macros
	atlctrls.h	standard and common control classes
	atlctrlw.h	command bar class
	atlctrlx.h	bitmap button, check list view, and other controls
	atlddx.h	data exchange for dialogs and windows
	atldlgs.h	common dialog classes, property sheet and page classes
	atlframe.h	frame window classes, MDI, update UI classes
	atlgdi.h	DC classes, GDI object classes
	atlmisc.h	ATL ports of CPoint, CRect, CSize, CString, etc.
	atlprint.h	printing and print preview
	atlres.h	standard resource IDs
	atlscrl.h	scrollable windows
	atlsplit.h	splitter windows
	atluser.h	menu class

samples\
	BmpView\	bitmap file view sample
	MTPad\		multithreaded notepad sample
	MDIDocVw\	ATL version of the MDI sample
	GuidGen\	ATL version of the GuidGen sample

appwiz\
	atlapp60.awx	ATL/WTL AppWizard


4. Class Overview
-----------------

usage:	mi base	- a base class (multiple inheritance)
	client	- wrapper class for a handle
	impl	- implements a window (has WindowProc)
	as-is	- to be used directly
	helper	- a helper class
	base	- implementation base class

-------------------------------------------------------------------------------
class name			usage		description
-------------------------------------------------------------------------------

---app/module support----------------------------------------------------------

CAppModule					app support, CComModule derived
CServerAppModule				module for COM servers

CMessageLoop			as-is		message loop

CMessageFilter			mi base		message filter interface
CIdleHandler			mi base		idle time handler interface


---frame windows---------------------------------------------------------------

CFrameWindowImplBase<>		base
	CFrameWindowImpl<>	impl		frame window support

COwnerDraw<>			impl mi base	owner-draw msg map and handlers
CDialogResize<>			impl mi base	support for resizing dialogs


---MDI windows-----------------------------------------------------------------

CMDIWindow			client		MDI methods
CMDIFrameWindowImpl<>		impl		MDI frame window
CMDIChildWindowImpl<>		impl		MDI child window


---update UI-------------------------------------------------------------------

CUpdateUIBase			base
	CUpdateUI<>		mi base class	provides support for UI update


---standard controls-----------------------------------------------------------

CStatic				client		static ctrl
CButton				client		button ctrl
CListBox			client		list box ctrl
CComboBox			client		combo box ctrl
CEdit				client		edit ctrl
CEditCommands			mi		standard edit command support
CScrollBar			client		scroll bar ctrl


---common controls-------------------------------------------------------------

CImageList			client/impl	image list
CListViewCtrl			client		list view ctrl
CTreeViewCtrl			client		tree view ctrl
  CTreeItem			helper
CTreeViewCtrlEx			client		uses CTreeItem
CHeaderCtrl			client		header bar ctrl
CToolBarCtrl			client		toolbar ctrl
CStatusBarCtrl			client		status bar ctrl
CTabCtrl			client		tab ctrl
CToolTipCtrl			client		tool tip ctrl
  CToolInfo			helper
CTrackBarCtrl			client		trackbar ctrl
CUpDownCtrl			client		up-down ctrl
CProgressBarCtrl		client		progress bar ctrl
CHotKeyCtrl			client		hot key ctrl
CAnimateCtrl			client		animation ctrl
CRichEditCtrl			client		rich edit ctrl
CRichEditCommands		mi		std rich edit commands support
CDragListBox			client		drag list box
  CDragListNotifyImpl<>		impl mi class	support for notifications

CReBarCtrl			client		rebar ctrl
CComboBoxEx			client		extended combo box
CDateTimePickerCtrl		client		date-time ctrl
CFlatScrollBarImpl		mi impl		flat scroll bars support
CFlatScrollBar			as-is		flat scroll bars support
CIPAddressCtrl			client		IP address ctrl
CMonthCalendarCtrl		client		month calendar ctrl

CCustomDraw<>			impl mi class	custom draw handling support


---property sheet & page-------------------------------------------------------

CPropertySheetWindow		client
	CPropertySheetImpl<>	impl		property sheet		
		CPropertySheet	as-is
CPropertyPageWindow		client
	CPropertyPageImpl<>	impl		property page
		CPropertyPage	as-is
	CAxPropertyPageImpl<>	impl		property page with ActiveX
		CAxPropertyPage	as-is


---common dialogs--------------------------------------------------------------

CFileDialogImpl<>		impl		GetOpenFileName/GetSaveFileName
	CFileDialog		as-is
CFolderDialogImpl		impl		directory picker
	CFolderDialog		as-is
CFontDialogImpl<>		impl		ChooseFont common dialog
	CFontDialog		as-is
  CRichEditFontDialogImpl<>	impl		ChooseFont for rich edit
	CRichEditFontDialog	as-is
CColorDialogImpl<>		impl		ChooseColor common dialog
	CColorDialog		as-is
CPrintDialogImpl<>		impl		PrintDlg common dialog
	CPrintDialog		as-is
CPrintDialogExImpl		impl		new Win2000 print dialog
	CPrintDialogEx		as-is
CPageSetupDialogImpl<>		impl		PageSetupDlg common dialog
	CPageSetupDialog	as-is
CFindReplaceDialogImpl<>	impl		FindText/ReplaceText
	CFindReplaceDialog	as-is


---USER support-----------------------------------------------------------------

CMenu				client		menu support


---GDI support-----------------------------------------------------------------

CDC				client		DC support
	CPaintDC		client		for handling WM_PAINT
	CClientDC		client		for GetDC
	CWindowDC		client		for GetWindowDC

CPen				client		GDI pen object
CBrush				client		GDI brush object
CFont				client		GDI font object
CBitmap				client		GDI bitmap object
CPalette			client		GDI palette object
CRgn				client		GDI rgn object


---enhanced controls----------------------------------------------------------

CCommandBarCtrlImpl		impl		command bar
	CCommandBarCtrl		as-is
CBitmapButtonImpl		impl		bitmap button
	CBitmapButton		as-is
CCheckListViewCtrlImpl		impl		check list box
	CCheckListViewCtrl	as-is
CHyperLinkImpl			impl		hyper link control
	CHyperLink		as-is
CWaitCursor			as-is		wait cursor
CMultiPaneStatusBarCtrlImpl	impl		status bar with multiple panes
	CMultiPaneStatusBarCtrl	as-is
CPaneContainerImpl<>		impl		pane window container
	CPaneContainer		as-is


---additional UI components---------------------------------------------------

CScrollImpl			impl		scrolling support
CScrollWindowImpl		impl		scrollable window
CMapScrollImpl			impl		scrolling support with map modes
CMapScrollWindowImpl		impl		scrollable window with map modes

CSplitterImpl			impl		splitter support
CSplitterWindowImpl		impl		splitter window
CSplitterWindow			as-is


---printing support------------------------------------------------------------

CPrinterInfo<>			as-is		print info support
CPrinter			client		printer handle wrapper
CDevMode			client		DEVMODE wrapper
CPrinterDC			client		printing DC support
CPrintJobInfo			client		print job info
CPrintJob			client		print job support
CPrintPreview			mi		print preview support
CPrintPreviewWindow		as-is		print preview window


---miscellaneous---------------------------------------------------------------

CSize				as-is		ATL port of MFC's CSize
CPoint				as-is		ATL port of MFC's CPoint
CRect				as-is		ATL port of MFC's CRect
CString				as-is		ATL port of MFC's CString

CWinDataExchange		mi		data exchange for controls
CRecentDocumentList		mi or as-is	support for MRU list


5. ATL/WTL AppWizard
--------------------

ATL/WTL AppWizard generates starting code for a WTL app. It has options to
create code for different app types and features.

You can choose the following options:

	- Application type (SDI, multi thread SDI, MDI, dialog based)
	- Support for hosting ActiveX controls
	- COM server support
	- toolbar, rebar, command bar, status bar
	- view window, and it's type (generic, dialog based form, or a list 
	  box, edit, list view, tree view, rich edit based, HTML page)
	- for a dialog based app, or a form based view window, support for 
	  hosting ActiveX controls in the dialog

This wizard can be used only with VC++ 6.0.


6. Changes Between WTL 3.0 And 3.1
----------------------------------

New classes:
	CPaneContainer - implements a window that provides a title bar and a
		close button (like Explorer)

	CDialogResize - an MI class that allows resizing of dialogs (or any 
		windows with child windows/controls)

	CAxPropertyPageImpl - implements a property page that can host ActiveX
		controls

Fixes and enhancements:
	CServerAppModule now clears m_hEventShutdown to avoid calling
		CloseHandle twice

	CString:
	- operator += now leaves original string intact if it's out of memory
	- Fixed bad DWORD_PTR usage in TrimRight, TrimLeft, Replace, Remove
	- Removed dependencies on CRT for projects that don't use it
	- Insert - fixed string corruption in release builds
	- Added optional floating point formatting (for projects that use CRT)

	CEdit and CRichEditCtrl: SetSelAll and SetSelNone had reversed
		implementation

	atlres.h: Changed IDs so that they are compatible with MFC's afxres.h

	Command Bar:
	- Added LoadMappedImages()
	- Changed handling of left and right arrow keys so that they don't
		close context menus
	- Add code to handle left/right arrow keys correctly on mirrored (RTL)
		systems
	- Removed handler that eats parent window's WM_SETTINGCHANGE
	- Fixed bitmap resource leak in Draw3DCheckmark
	- Fixed incorrect usage of CharLower in OnMenuChar
	- Fixed wrong color for the disabled items in hi-contrast mode
	- Added code to gray menu items if main window is inactive
	- Fixed keyboard mnemonic handling for IE 4
	- Fixed hook problems with multiple cmdbars in the same thread
	- Added support for radio menu items
	- Added support for disabled top-level menu items (also added in
		CFrameWindowImpl::PrepareChevronMenu)
	- Added keyboard shortcut (Alt+/) to invoke chevron menu
	- Added support to override menu item length in a derived class

	CBitmapButton:
	- Bypassed BUTTON DefWindowProc for hover style so that the button
		doesn't take focus
	- Added BMPBTN_AUTOFIRE extended style

	CDC:
	- Added _WTL_FORWARD_DECLARE_CSTRING define to allow usage of methods
		that accept CString
	- Fixed errors in GetTextFace and GetMenuItemString
	- Added GetCharWidth32
	- Added DrawIconEx method

	CMenu:
	- Implement following missing methods:
		GetMenuDefaultItem
		GetMenuInfo
		GetMenuItemRect
		HiliteMenuItem
		IsMenu
		MenuItemFromPoint
		SetMenuDefaultItem
		SetMenuInfo
	- GetMenuString - fixed to include space for terminating NULL character
		in returning string

	GDI and USER classes should destroy the GDI/USER objects in Attach if
		GDI/USER resource is managed

	CFrameWindowImpl:
	- OnToolTipText shouldn't save tool tip text if it's not for a menu
	- AddSimpleReBarBandCtrl now adds chevron style only for toolbars with
		buttons
	- AddSimpleReBarBand(Ctrl) - calc band ID if not specified

	CRecentDocumentList:
	- Fix - UpdateMenu deletes wrong menu item when the list is empty
	- Added code to allow restricting the number of characters displayed by
		MRU menu items

	Update UI:
	- Added support for blocking accelerators for disabled items
	- Improved search code assuming there are no duplicate entries (and
		added checks for duplicates)

	CSplitterWindow:
	- CSplitterWindowImpl should derive from CSplitterImpl<T , t_bVertical>
		to allow overriding of methods
	- Added single pane mode and SetSinglePaneMode/GetSinglePaneMode
	- Added right/bottom aligned resize mode using extended styles
		SPLIT_RIGHTALIGNED/SPLIT_BOTTOMALIGNED

	atlcrack.h: Added handlers for following new messages:
		WM_APPCOMMAND
		WM_NCXBUTTONDOWN
		WM_NCXBUTTONUP
		WM_NCXBUTTONDBLCLK
		WM_XBUTTONDOWN
		WM_XBUTTONUP
		WM_XBUTTONDBLCLK

	Win64:
	- Dialog return value should use DWLP_MSGRESULT and SetWindowLongPtr
	- CMenu::InsertMenu, AppendMenu, ModifyMenu should have UINT_PTR for
		the menu ID
	- Added appropriate type casts
	- CFrameWindowImpl::m_szAutoName - changed the size to fit the pointer
		value size
	- CListViewCtrl::SortItems should use LPARAM for user data instead of
		DWORD

	Misc:
	- Added optional mask argument to all methods for setting extended
		styles
	- CMDIWindow::MDIRestore - fixed to send WM_MDIRESTORE instead of
		WM_MDIICONARRANGE
	- CListViewCtrl: Added SortItemsEx method
	- CToolBarCtrl::GetButtonInfo - fixed to return int instead of BOOL
	- Added CToolBarCtrl::SetButtonSize and SetBitmapSize that accept cx
		and cy instead of SIZE
	- Printing: Changed how GetNewDevModeForPage works (comments in code)
	- CFileDialogImpl::_OnTypeChange incorrectly calls pT->OnSelChange
		instead of pT->OnTypeChange
	- CMultiPaneStatusBarCtrl::GetPaneTipText - fixed to use index instead
		of and ID internally
	- CWinDataExchange: Added references to arguments of DoDataExchange, so
		there are no level 4 warning even if the map is empty
	- CPropertySheetWindow: Added new, IE 5.0 specific methods
	- CPropertyPageImpl: Added new, IE 5.0 specific methods

	App Wizard:
	- added calls to RemoveMessageFilter and RemoveIdleHandler in
		CMainFrame::OnDestroy for COM server projects
	- added scroll bars for HTML view
	- CAppServerModule now handles -embedding as well as -automation
	- corrected code in CMainFrame::OnShowToolBar to correctly identify the
		toolbar in a rebar
	- dialog based app code now derives from CUpdateUI as public

- end of readme.txt -
