; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBookManage
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ChangeWnd.h"

ClassCount=4
Class1=CChangeWndApp
Class2=CChangeWndDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_BOOKINFOADDDLG
Resource2=IDR_MAINFRAME
Resource3=IDD_CHANGEWND_DIALOG
Resource4=IDD_ABOUTBOX
Class4=CBookManage
Resource5=IDD_INPUTINFODLG

[CLS:CChangeWndApp]
Type=0
HeaderFile=ChangeWnd.h
ImplementationFile=ChangeWnd.cpp
Filter=W
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CChangeWndDlg]
Type=0
HeaderFile=ChangeWndDlg.h
ImplementationFile=ChangeWndDlg.cpp
Filter=D
LastObject=CChangeWndDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ChangeWndDlg.h
ImplementationFile=ChangeWndDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHANGEWND_DIALOG]
Type=1
Class=CChangeWndDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_BOOKINFOADDDLG]
Type=1
Class=CBookManage
ControlCount=2
Control1=ID_ADD,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_INPUTINFODLG]
Type=1
Class=?
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BOOKNAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_NUMB,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_AUTHOR,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PRICE,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_PUBLIC,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CONTENT,edit,1350631552

[CLS:CBookManage]
Type=0
HeaderFile=BookManage.h
ImplementationFile=BookManage.cpp
BaseClass=CDialog
Filter=D
LastObject=CBookManage
VirtualFilter=dWC

