###########################################################################
## Makefile generated for component 'Experiment1'. 
## 
## Makefile     : Experiment1.mk
## Generated on : Mon Oct 16 17:25:39 2023
## Final product: $(RELATIVE_PATH_TO_ANCHOR)\Experiment1.rt-win64
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file

PRODUCT_NAME              = Experiment1
MAKEFILE                  = Experiment1.mk
MATLAB_ROOT               = C:\R2023a
MATLAB_BIN                = C:\R2023a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\user\Documents\MATLAB
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 1
TGT_FCN_LIB               = ISO_C
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
COMPILER_COMMAND_FILE     = Experiment1_comp.rsp
CMD_FILE                  = Experiment1.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          QUARC win64 | nmake (64-bit Windows)
# Supported Version(s):    14
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# cvarsdll
# cvarsmt
# conlibs
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

CPU                   = AMD64
APPVER                = 5.02
CRT_DECL              = -DCRTAPI1=_cdecl -DCRTAPI2=_cdecl
MISC                  = -D_AMD64_=1 -DWIN64 -D_WIN64  -DWIN32 -D_WIN32 -D_WINNT -D_WIN32_WINNT=0x0502 -DNTDDI_VERSION=0x05020000 -D_WIN32_IE=0x0600 -DWINVER=0x0502
REQ_OPTS              = $(cvarsdll) $(CRT_DECL) $(MISC)
QUARC_REQ_OPTS        = -DVXWORKS -DQUARC -DTARGET_TYPE=win64
SUPRESS_WARNINGS      = /wd4100 /wd4996
CFLAGS_ADDITIONAL     = $(SUPRESS_WARNINGS) -D_CRT_SECURE_NO_DEPRECATE
CPPFLAGS_ADDITIONAL   = /EHsc- $(CFLAGS_ADDITIONAL)
QUARC_LDFLAGS         = /LIBPATH:$(QUARC)\lib\win64
QUARC_LIBS            = extmode_quarc_r2013b.lib quanser_communications.lib quanser_runtime.lib quanser_common.lib ippccmt.lib ippcvmt.lib ippimt.lib ippsmt.lib ippvmmt.lib ippcoremt.lib shell32.lib comdlg32.lib
QUARC_SYS_LIBS        = libusb-1.0.lib
NODEFAULTFLAGS_DEBUG  = /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrt.lib  /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcprt.lib
NODEFAULTFLAGS_NDEBUG = /NODEFAULTLIB:libc.lib /NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:msvcrtd.lib /NODEFAULTLIB:libcd.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcprtd.lib
STDIO_LIBS            = legacy_stdio_definitions.lib

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(REQ_OPTS) $(QUARC_REQ_OPTS) $(CFLAGS_ADDITIONAL) \
                       -Ox -DNDEBUG
CPPFLAGS             = $(cflags) $(REQ_OPTS) $(QUARC_REQ_OPTS) $(CPPFLAGS_ADDITIONAL) \
                       -Ox -DNDEBUG
CPP_LDFLAGS          = $(ldebug) $(QUARC_LDFLAGS) $(conflags) $(conlibs) $(STDIO_LIBS) \
                       $(NODEFAULTFLAGS_NDEBUG) \
                       $(QUARC_LIBS) \
                       $(QUARC_SYS_LIBS)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(QUARC_LDFLAGS) $(conflags) $(conlibs) $(STDIO_LIBS) \
                         $(NODEFAULTFLAGS_NDEBUG) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(QUARC_LDFLAGS) $(conflags) $(conlibs) $(STDIO_LIBS) \
                       $(NODEFAULTFLAGS_NDEBUG) \
                       $(QUARC_LIBS) \
                       $(QUARC_SYS_LIBS)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
NODEBUG              = 0
SHAREDLIB_LDFLAGS    = $(ldebug) $(QUARC_LDFLAGS) $(conflags) $(conlibs) $(STDIO_LIBS) \
                       $(NODEFAULTFLAGS_NDEBUG) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)\Experiment1.rt-win64
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=1 -DALLOCATIONFCN=0 -DEXT_MODE=1 -DMAT_FILE=0 -DONESTEPFCN=0 -DTERMFCN=1 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0
DEFINES_CUSTOM = 
DEFINES_OPTS = -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1
DEFINES_STANDARD = -DMODEL=Experiment1 -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DRT -DUSE_RTMODEL

DEFINES = $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\Experiment1_quarc_win64\Experiment1.c $(START_DIR)\Experiment1_quarc_win64\Experiment1_data.c $(START_DIR)\Experiment1_quarc_win64\Experiment1_main.c $(START_DIR)\Experiment1_quarc_win64\rtGetInf.c $(START_DIR)\Experiment1_quarc_win64\rtGetNaN.c $(START_DIR)\Experiment1_quarc_win64\rt_nonfinite.c $(MATLAB_ROOT)\rtw\c\src\rt_sim.c C:\Quanser\QUARC\quarc\src\ext_svr.c C:\Quanser\QUARC\quarc\src\updown.c C:\Quanser\QUARC\quarc\src\ext_work.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Experiment1.obj Experiment1_data.obj Experiment1_main.obj rtGetInf.obj rtGetNaN.obj rt_nonfinite.obj rt_sim.obj ext_svr.obj updown.obj ext_work.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = C:\Quanser\QUARC\lib\win64\hil.lib C:\Quanser\QUARC\lib\win64\quanser_runtime.lib C:\Quanser\QUARC\lib\win64\quanser_common.lib

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


buildobj : set_environment_variables prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@cmd /C "@echo ### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@cmd /C "@echo ### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@cmd /C "@echo ### Done invoking postbuild tool."


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	@cmd /C "@echo ### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -out:$(PRODUCT) @$(CMD_FILE) $(LIBS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\Experiment1_quarc_win64}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\Experiment1_quarc_win64}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\simulink\src}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\rtw\c\src\ext_mode\common}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(MATLAB_ROOT)\toolbox\coder\rtiostream\src\utils}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


Experiment1.obj : "$(START_DIR)\Experiment1_quarc_win64\Experiment1.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\Experiment1_quarc_win64\Experiment1.c"


Experiment1_data.obj : "$(START_DIR)\Experiment1_quarc_win64\Experiment1_data.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\Experiment1_quarc_win64\Experiment1_data.c"


Experiment1_main.obj : "$(START_DIR)\Experiment1_quarc_win64\Experiment1_main.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\Experiment1_quarc_win64\Experiment1_main.c"


rtGetInf.obj : "$(START_DIR)\Experiment1_quarc_win64\rtGetInf.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\Experiment1_quarc_win64\rtGetInf.c"


rtGetNaN.obj : "$(START_DIR)\Experiment1_quarc_win64\rtGetNaN.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\Experiment1_quarc_win64\rtGetNaN.c"


rt_nonfinite.obj : "$(START_DIR)\Experiment1_quarc_win64\rt_nonfinite.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(START_DIR)\Experiment1_quarc_win64\rt_nonfinite.c"


rt_sim.obj : "$(MATLAB_ROOT)\rtw\c\src\rt_sim.c"
	$(CC) $(CFLAGS) -Fo"$@" "$(MATLAB_ROOT)\rtw\c\src\rt_sim.c"


ext_svr.obj : C:\Quanser\QUARC\quarc\src\ext_svr.c
	$(CC) $(CFLAGS) -Fo"$@" C:\Quanser\QUARC\quarc\src\ext_svr.c


updown.obj : C:\Quanser\QUARC\quarc\src\updown.c
	$(CC) $(CFLAGS) -Fo"$@" C:\Quanser\QUARC\quarc\src\updown.c


ext_work.obj : C:\Quanser\QUARC\quarc\src\ext_work.c
	$(CC) $(CFLAGS) -Fo"$@" C:\Quanser\QUARC\quarc\src\ext_work.c


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"
	@cmd /C "@echo ### NODEBUG = $(NODEBUG)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


