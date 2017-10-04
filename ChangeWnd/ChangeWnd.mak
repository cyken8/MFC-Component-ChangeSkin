# Microsoft Developer Studio Generated NMAKE File, Based on ChangeWnd.dsp
!IF "$(CFG)" == ""
CFG=ChangeWnd - Win32 Debug
!MESSAGE No configuration specified. Defaulting to ChangeWnd - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "ChangeWnd - Win32 Release" && "$(CFG)" != "ChangeWnd - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ChangeWnd.mak" CFG="ChangeWnd - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ChangeWnd - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ChangeWnd - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ChangeWnd - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ChangeWnd.exe"


CLEAN :
	-@erase "$(INTDIR)\AddBookInfo.obj"
	-@erase "$(INTDIR)\BookManage.obj"
	-@erase "$(INTDIR)\ChangeWnd.obj"
	-@erase "$(INTDIR)\ChangeWnd.pch"
	-@erase "$(INTDIR)\ChangeWnd.res"
	-@erase "$(INTDIR)\ChangeWndDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ChangeWnd.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\ChangeWnd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\ChangeWnd.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ChangeWnd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ChangeWnd.pdb" /machine:I386 /out:"$(OUTDIR)\ChangeWnd.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ChangeWnd.obj" \
	"$(INTDIR)\ChangeWndDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ChangeWnd.res" \
	"$(INTDIR)\BookManage.obj" \
	"$(INTDIR)\AddBookInfo.obj"

"$(OUTDIR)\ChangeWnd.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ChangeWnd - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ChangeWnd.exe"


CLEAN :
	-@erase "$(INTDIR)\AddBookInfo.obj"
	-@erase "$(INTDIR)\BookManage.obj"
	-@erase "$(INTDIR)\ChangeWnd.obj"
	-@erase "$(INTDIR)\ChangeWnd.pch"
	-@erase "$(INTDIR)\ChangeWnd.res"
	-@erase "$(INTDIR)\ChangeWndDlg.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\ChangeWnd.exe"
	-@erase "$(OUTDIR)\ChangeWnd.ilk"
	-@erase "$(OUTDIR)\ChangeWnd.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\ChangeWnd.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\ChangeWnd.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ChangeWnd.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ChangeWnd.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ChangeWnd.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ChangeWnd.obj" \
	"$(INTDIR)\ChangeWndDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\ChangeWnd.res" \
	"$(INTDIR)\BookManage.obj" \
	"$(INTDIR)\AddBookInfo.obj"

"$(OUTDIR)\ChangeWnd.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ChangeWnd.dep")
!INCLUDE "ChangeWnd.dep"
!ELSE 
!MESSAGE Warning: cannot find "ChangeWnd.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ChangeWnd - Win32 Release" || "$(CFG)" == "ChangeWnd - Win32 Debug"
SOURCE=.\AddBookInfo.cpp

"$(INTDIR)\AddBookInfo.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ChangeWnd.pch"


SOURCE=.\BookManage.cpp

"$(INTDIR)\BookManage.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ChangeWnd.pch"


SOURCE=.\ChangeWnd.cpp

"$(INTDIR)\ChangeWnd.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ChangeWnd.pch"


SOURCE=.\ChangeWnd.rc

"$(INTDIR)\ChangeWnd.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\ChangeWndDlg.cpp

"$(INTDIR)\ChangeWndDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ChangeWnd.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "ChangeWnd - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\ChangeWnd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ChangeWnd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "ChangeWnd - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\ChangeWnd.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ   /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ChangeWnd.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

