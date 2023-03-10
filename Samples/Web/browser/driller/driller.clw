; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDrillerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "driller.h"

ClassCount=3
Class1=CDrillerApp
Class2=CDrillerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DRILLER_DIALOG

[CLS:CDrillerApp]
Type=0
HeaderFile=driller.h
ImplementationFile=driller.cpp
Filter=N

[CLS:CDrillerDlg]
Type=0
HeaderFile=drilldlg.h
ImplementationFile=drilldlg.cpp
BaseClass=CDialog
LastObject=CDrillerDlg
Filter=N
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=drillerDlg.h
ImplementationFile=drillerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DRILLER_DIALOG]
Type=1
Class=CDrillerDlg
ControlCount=5
Control1=IDC_EXPLORER1,{8856F961-340A-11D0-A96B-00C04FD705A2},1342242816
Control2=IDC_BTN_GO,button,1342242817
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_BTN_DRILL,button,1342242816
Control5=IDC_LIST1,listbox,1353777408

