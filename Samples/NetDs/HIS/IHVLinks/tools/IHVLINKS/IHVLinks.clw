; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIHVFinish
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "IHVLinks.h"

ClassCount=3
Class1=CIHVLinksApp
Class2=CIHVLinksDlg

ResourceCount=4
Resource2=IDD_WELCOME
Resource1=IDR_MAINFRAME
Resource3=IDD_IHVLINKS_DIALOG
Class3=CIHVFinish
Resource4=IDD_FINISH

[CLS:CIHVLinksApp]
Type=0
HeaderFile=IHVLinks.h
ImplementationFile=IHVLinks.cpp
Filter=N

[CLS:CIHVLinksDlg]
Type=0
HeaderFile=IHVLinksDlg.h
ImplementationFile=IHVLinksDlg.cpp
Filter=D
LastObject=CIHVLinksDlg
BaseClass=CPropertyPageEx
VirtualFilter=dWC



[DLG:IDD_IHVLINKS_DIALOG]
Type=1
Class=CIHVLinksDlg
ControlCount=3
Control1=IDC_IHV_TREE,SysTreeView32,1350642439
Control2=IDC_STATIC,button,1342177287
Control3=IDC_DESCRIPTION,static,1342308352

[DLG:IDD_WELCOME]
Type=1
Class=?
ControlCount=4
Control1=IDC_WELCOMETITLE,static,1342177289
Control2=IDC_WELCOMETITLE2,static,1342177289
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TXT_DB_NAME2,static,1342308352

[DLG:IDD_FINISH]
Type=1
Class=CIHVFinish
ControlCount=4
Control1=IDC_FINISHTITLE,static,1342177289
Control2=IDC_FINISHTITLE2,static,1342177289
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TXT_DB_NAME2,static,1342308352

[CLS:CIHVFinish]
Type=0
HeaderFile=IHVFinish1.h
ImplementationFile=IHVFinish1.cpp
BaseClass=CDialog
Filter=D
LastObject=CIHVFinish
VirtualFilter=dWC

