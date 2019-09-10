#===================================================================================================
#   @file    build_cfg.mak
#   @version 1.0.0
#
#   @brief       configuration file for GHS toolchain
#   @details     This file contains the compiler, assembler, linker options for GHS toolchain
#
#===================================================================================================
#   Project              : AUTOSAR 4.2 MCAL
#   Platform             : PA
#   Peripheral           : 
#   Dependencies         : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM
#
#   Autosar Version      : 4.2.2
#   Autosar Revision     : ASR_REL_4_2_REV_0002
#   Autosar Conf.Variant :
#   SW Version           : 1.0.0
#   Build Version        : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20171702
#
#   (c) Copyright 2006-2017 NXP Inc
#   All Rights Reserved.
#
#    This file contains sample code only. It is not part of the production code deliverables.
#
#===================================================================================================
#===================================================================================================
###===================================================================================================
# Setup buid tools
# MISRA-C 2004 Rule checking.
VLETYPE = vle
PRJFLAG :=-DMPC$(DERIVATIVE)

MISRA_ALL = --misra_2004=all
# Allowed exceptions are to be documented in the source code. Exceptions are documented in Global_MSG_C-Coding_Guidelines.doc Appendix A
MISRA_ALLOWED = --misra_2004=all,-5.7,-11.3,-11.4,-14.7,-17.1,-17.2,-17.4,-20.3,-20.4
#MISRA = $(MISRA_ALLOWED)

# Actual core:
MULTICORE_TST_CORE=$(if $(findstring CORE,$(CFG_SET)),$(subst CORE,,$(lastword $(subst $(_UNDERLINE_CHAR_), $(_SPACE_CHAR_), $(CFG_SET)))),)

# CORE-specific CC/AS/LD options
CCOPT_CORE_ := -cpu=ppc5748gz4204
ASOPT_CORE_ := $(CCOPT_CORE_)
LDOPT_CORE_ := $(CCOPT_CORE_)

CCOPT_CORE_0:= -cpu=ppc5748gz4204
ASOPT_CORE_0:= $(CCOPT_CORE_0)
LDOPT_CORE_0:= $(CCOPT_CORE_0)

CCOPT_CORE_1:= -cpu=ppc5748gz4204
ASOPT_CORE_1:= $(CCOPT_CORE_1)
LDOPT_CORE_1:= $(CCOPT_CORE_1)

CCOPT_CORE_2:= -cpu=ppc5748gz210
 
ASOPT_CORE_2:= $(CCOPT_CORE_2)
LDOPT_CORE_2:= $(CCOPT_CORE_2)

CCOPT_CORE=$(CCOPT_CORE_$(MULTICORE_TST_CORE)) 
ASOPT_CORE=$(ASOPT_CORE_$(MULTICORE_TST_CORE))
LDOPT_CORE=$(LDOPT_CORE_$(MULTICORE_TST_CORE))

SUBDERIVATIVE_NAME=-DDERIVATIVE_$(DERIVATIVE)

CC             := $(call winpath, $(TOOLCHAIN_DIR)/ccppc.exe)
LD             := $(call winpath, $(TOOLCHAIN_DIR)/ccppc.exe)
AS             := $(call winpath, $(TOOLCHAIN_DIR)/asppc.exe)
CCOPT             :=  $(CCOPT) \
                    $(MISRA) \
                    $(PRJFLAG) \
					$(DEFINE_FLAG_SPECIFIC) \
                    -DGHS \
                    --incorrect_pragma_warnings \
                   -$(VLETYPE) \
                   -DAUTOSAR_OS_NOT_USED \
                   $(SUBDERIVATIVE_NAME) \
                   -DEU_DISABLE_ANSILIB_CALLS \
                   -preprocess_assembly_files \
                   --no_exceptions \
                   -dual_debug \
                   --prototype_errors \
                   -Wundef \
                   -ansi \
                   -Ospace \
                   -G \
                   -noslashcomment \
                   -Wimplicit-int \
                   -Wshadow \
                   -Wtrigraphs \
                   -noSPE \
                   -nostartfile \
                   -sda=0 \
                   --short_enum \
                   --diag_error 223                   
                   
LDOPT             :=  $(LDOPT) \
                    --nocpp \
                    -Mn \
                    -delete \
                    -ignore_debug_references \
                    -keepmap \
                    -$(VLETYPE) \
                    -nostartfiles    
	
	
ASOPT             := $(ASOPT) \
                    -G \
                    -list
      
#$(shell echo Using current linker options$(LDOPT) 1>&2)				
#$(shell echo Using asambler linker $(ASOPT) 1>&2)
$(shell echo Using current compiler options $(CCOPT) 1>&2)
                    
	  
ifeq ($(findstring @LoadTo=ram, $(TEST_PARAMS)),)
    # if compiling/linking into flash
else
    #if compiling/linking into ram
    ASOPT       := $(ASOPT)
    CCOPT       := $(CCOPT) -DSINTRAM
endif

ifeq ($(CCOV_ENABLE),ON)
    #if code coverage is needed
    CCOPT:= $(CCOPT) -DCCOV_ENABLE
else
    #if code coverage is NOT needed then enable the CER validation
    CCOPT:= $(CCOPT) -DMCAL_CER_VALIDATION
endif

ifeq ($(ENABLE_RCHECK),ON)
    #if code runtime checks are needed
    CCOPT:= $(CCOPT) -check=all -DENABLE_RCHECK -DAUX_BUFFER_ADDR=$(AUX_BUFFER_ADDR)
else
ifeq ($(AUX_BUFFER_APP),ON)
    CCOPT       := $(CCOPT) -DENABLE_TIMERS
endif
endif

ifeq ($(T32_TRACE_APP),ON)
    CCOPT       := $(CCOPT) -DT32_TRACE_APP
endif

ifeq ($(D_CACHE_ENABLE),ON)
    #if D_CACHE is needed
    CCOPT:= $(CCOPT) -DD_CACHE_ENABLE
endif
ifeq ($(I_CACHE_ENABLE),ON)
    #if I_CACHE is needed
    CCOPT:= $(CCOPT) -DI_CACHE_ENABLE
endif
ifeq ($(BTB_ENABLE),ON)
   #if BTB is needed
    CCOPT:= $(CCOPT) -DBTB_ENABLE
endif

ifeq ($(MULTICORE_TST_ENABLE),ON)
   #if MULTICORE is enabled
    CCOPT:= $(CCOPT) -DMULTICORE_TST_ENABLE
endif

# Setup system libs, inlude dirs, and sourceinclude files
LIBS            :=
#INCLUDE_DIRS    =
#SRC_FILES        =
# Extention of the linked executable file
EXE_EXT := elf

# Compiling and Linking macros
COMPILE_C_FILE = $(CC) $(CCOPT_CORE) $(CCOPT) -DFILE_BASENAME=$(basename $(notdir $<)) -c $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) -o $(call winpath, $(OUT_DIR)/$@)
PREPROCESS_C_FILE = $(CC) $(CCOPT_CORE)  $(CCOPT)  -DENABLE_DUMMY_SUITES -DPREPROCESS_ONLY_TEST -E $(call winpath, $<) $(addprefix -I, $(INCLUDE_DIRS)) -o $(call winpath, $(OUT_DIR)/$(notdir $@))
COMPILE_S_FILE = $(AS) $(ASOPT_CORE) $(ASOPT) $(call winpath, $<) -o $(call winpath, $(OUT_DIR)/$@)
LINK_O_FILES = $(LD) $(LDOPT_CORE) $(LDOPT) $(foreach LINKER_DEF, $(LINKER_DEFS), $(call winpath, $(LINKER_DEF))) $(addprefix $(call winpath, $(OUT_DIR)/), $(OUT_FILES)) $(call winpath, $(LIBS)) -o $(call winpath, $@)

COMPILER_VERSION_CMD = $(CC) -V a.c 2>&1 | grep $(COMPILER_REFERENCE_VERSION)
COMPILER_REFERENCE_VERSION := "C-POWERPC 2013.5.4 DEVELOPMENT VERSION: Copyright (C) 1983-2013 Green Hills Software.  All Rights Reversed."

#check toolchain version
ifeq ($(TOOLCHAIN_VERSION),)
    #export to environment - so that is checked only once during current make run
    export TOOLCHAIN_VERSION:= $(strip $(shell $(COMPILER_VERSION_CMD)))
endif
ifeq ($(strip $(TOOLCHAIN_VERSION)),)
    $(shell echo "**************************************************************************************" 1>&2)
    $(shell echo Bad Compiler version 1>&2)
    $(shell echo For $(PLATFORM)-$(DERIVATIVE) you must use: $(COMPILER_REFERENCE_VERSION) 1>&2)
    $(shell echo "**************************************************************************************" 1>&2)
    $(error Bad Compiler version)
endif
