# Microsoft Developer Studio Generated NMAKE File, Based on WndDll.dsp
!IF "$(CFG)" == ""
CFG=WndDll - Win32 Debug
!MESSAGE No configuration specified. Defaulting to WndDll - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "WndDll - Win32 Release" && "$(CFG)" != "WndDll - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "WndDll.mak" CFG="WndDll - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "WndDll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "WndDll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
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

!IF  "$(CFG)" == "WndDll - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\WndDll.dll"


CLEAN :
	-@erase "$(INTDIR)\DrawButton.obj"
	-@erase "$(INTDIR)\DrawDialog.obj"
	-@erase "$(INTDIR)\DrawEdit.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\WndDll.obj"
	-@erase "$(INTDIR)\WndDll.pch"
	-@erase "$(INTDIR)\WndDll.res"
	-@erase "$(OUTDIR)\WndDll.dll"
	-@erase "$(OUTDIR)\WndDll.exp"
	-@erase "$(OUTDIR)\WndDll.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\WndDll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\WndDll.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WndDll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\WndDll.pdb" /machine:I386 /def:".\WndDll.def" /out:"$(OUTDIR)\WndDll.dll" /implib:"$(OUTDIR)\WndDll.lib" 
DEF_FILE= \
	".\WndDll.def"
LINK32_OBJS= \
	"$(INTDIR)\WndDll.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WndDll.res" \
	"$(INTDIR)\DrawEdit.obj" \
	"$(INTDIR)\DrawDialog.obj" \
	"$(INTDIR)\DrawButton.obj"

"$(OUTDIR)\WndDll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "WndDll - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\WndDll.dll" "$(OUTDIR)\WndDll.bsc"


CLEAN :
	-@erase "$(INTDIR)\DrawButton.obj"
	-@erase "$(INTDIR)\DrawButton.sbr"
	-@erase "$(INTDIR)\DrawDialog.obj"
	-@erase "$(INTDIR)\DrawDialog.sbr"
	-@erase "$(INTDIR)\DrawEdit.obj"
	-@erase "$(INTDIR)\DrawEdit.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\WndDll.obj"
	-@erase "$(INTDIR)\WndDll.pch"
	-@erase "$(INTDIR)\WndDll.res"
	-@erase "$(INTDIR)\WndDll.sbr"
	-@erase "$(OUTDIR)\WndDll.bsc"
	-@erase "$(OUTDIR)\WndDll.dll"
	-@erase "$(OUTDIR)\WndDll.exp"
	-@erase "$(OUTDIR)\WndDll.ilk"
	-@erase "$(OUTDIR)\WndDll.lib"
	-@erase "$(OUTDIR)\WndDll.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\WndDll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ    /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\WndDll.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\WndDll.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\WndDll.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\DrawEdit.sbr" \
	"$(INTDIR)\DrawDialog.sbr" \
	"$(INTDIR)\DrawButton.sbr"

"$(OUTDIR)\WndDll.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\WndDll.pdb" /debug /machine:I386 /def:".\WndDll.def" /out:"$(OUTDIR)\WndDll.dll" /implib:"$(OUTDIR)\WndDll.lib" /pdbtype:sept 
DEF_FILE= \
	".\WndDll.def"
LINK32_OBJS= \
	"$(INTDIR)\WndDll.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\WndDll.res" \
	"$(INTDIR)\DrawEdit.obj" \
	"$(INTDIR)\DrawDialog.obj" \
	"$(INTDIR)\DrawButton.obj"

"$(OUTDIR)\WndDll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
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
!IF EXISTS("WndDll.dep")
!INCLUDE "WndDll.dep"
!ELSE 
!MESSAGE Warning: cannot find "WndDll.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "WndDll - Win32 Release" || "$(CFG)" == "WndDll - Win32 Debug"
SOURCE=.\DrawButton.cpp

!IF  "$(CFG)" == "WndDll - Win32 Release"


"$(INTDIR)\DrawButton.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ELSEIF  "$(CFG)" == "WndDll - Win32 Debug"


"$(INTDIR)\DrawButton.obj"	"$(INTDIR)\DrawButton.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ENDIF 

SOURCE=.\DrawDialog.cpp

!IF  "$(CFG)" == "WndDll - Win32 Release"


"$(INTDIR)\DrawDialog.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ELSEIF  "$(CFG)" == "WndDll - Win32 Debug"


"$(INTDIR)\DrawDialog.obj"	"$(INTDIR)\DrawDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ENDIF 

SOURCE=.\DrawEdit.cpp

!IF  "$(CFG)" == "WndDll - Win32 Release"


"$(INTDIR)\DrawEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ELSEIF  "$(CFG)" == "WndDll - Win32 Debug"


"$(INTDIR)\DrawEdit.obj"	"$(INTDIR)\DrawEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "WndDll - Win32 Release"

CPP_SWITCHES=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\WndDll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\WndDll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "WndDll - Win32 Debug"

CPP_SWITCHES=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\WndDll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ    /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\WndDll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\WndDll.cpp

!IF  "$(CFG)" == "WndDll - Win32 Release"


"$(INTDIR)\WndDll.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ELSEIF  "$(CFG)" == "WndDll - Win32 Debug"


"$(INTDIR)\WndDll.obj"	"$(INTDIR)\WndDll.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\WndDll.pch"


!ENDIF 

SOURCE=.\WndDll.rc

"$(INTDIR)\WndDll.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

