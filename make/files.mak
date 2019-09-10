#===================================================================================================
#
#    @file        files.mak
#    @version     1.0.0
#
#    @brief       AUTOSAR - files to be build for the current application.
#    @details     List of files to be built for the Leds Sample Application.
#
#    Project      : AUTOSAR 4.2 MCAL
#    Platform     : PA
#    Peripheral   : 
#    Dependencies : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM
#
#    Autosar Version       : 4.2.2
#    Autosar Revision      : ASR_REL_4_2_REV_0002
#    Autosar Conf. Variant :
#    Software Version      : 1.0.0
#    Build Version         : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20171702
#
#    (c) Copyright 2006-2017 NXP Inc
#    All Rights Reserved.
#
#    This file contains sample code only. It is not part of the production code deliverables.
#
#
#===================================================================================================
##===================================================================================================

################################################################################
# Sample application name
################################################################################
SAMPLE_APP_NAME := Integration

#

################################################################################
# List of all source directories (test, dependency, and generated .c files)
################################################################################
#
# specify modules which will be compiled and linked
include Modules
# paths for building installed plugins
SRC_DIRS    +=  $(GENERATE_DIR)/src \
                $(foreach mod,$(MODULE_LIST),$(PLUGINS_DIR)/$(mod)_$(AR_PKG_NAME)/src) \
                $(foreach swc_comp,$(APP_SWC_LIST),$(DEV_DIR)/src/swc/$(swc_comp)) \
                $(foreach bsw_comp,$(APP_BSW_LIST),$(DEV_DIR)/src/bsw/$(bsw_comp))
#
################################################################################
# List of source files
################################################################################
SRC_FILES   +=  $(DEV_DIR)/src/main.c \
                $(DEV_DIR)/src/sample_app_mcal_initialization_task.c 


ifeq ($(modulelist),os)
  ifeq ($(TOOLCHAIN),cw)
    ASM_FILES_TO_BUILD      += $(DEV_DIR)/toolchains/CW_Startup_vle_os.s
  else
    SRC_FILES       += $(DEV_DIR)/toolchains/Startup_vle_os.c
  endif
else
ifeq ($(TOOLCHAIN),cw)
    SRC_FILES       += $(DEV_DIR)/toolchains/CW_Startup_vle.s
else
    SRC_FILES       += $(DEV_DIR)/toolchains/Startup_vle.c
endif
endif


################################################################################
# List of all include directories (test, dependency, and generated .h files)
################################################################################
#
INCLUDE_DIRS+=      $(GENERATE_DIR)/include \
                    $(DEV_DIR)/include \
                    $(foreach mod,$(MODULE_LIST),$(PLUGINS_DIR)/$(mod)_$(AR_PKG_NAME)/include) \
                    $(foreach swc_comp,$(APP_SWC_LIST),$(DEV_DIR)/include/swc/$(swc_comp)) \
                    $(foreach bsw_comp,$(APP_BSW_LIST),$(DEV_DIR)/include/bsw/$(bsw_comp))
#
################################################################################
# Path to the linker definition file
################################################################################
ifeq ($(DERIVATIVE), 5746C)
#take linker command files
LINKER_DEFS_GHS_FLASH   :=    $(DEV_DIR)/toolchains/autosar_flash.ld
LINKER_DEFS_CW_FLASH    :=    $(DEV_DIR)/toolchains/autosar_flash.lcf
LINKER_DEFS_DIAB_FLASH  :=    $(DEV_DIR)/toolchains/autosar_flash.dld
else
#take linker command files
LINKER_DEFS_GHS_FLASH   :=
LINKER_DEFS_GHS_RAM     :=
LINKER_DEFS_CW_FLASH    :=
LINKER_DEFS_CW_RAM      :=
LINKER_DEFS_DIAB_FLASH  :=
LINKER_DEFS_DIAB_RAM    :=
endif

ifeq ($(TOOLCHAIN),ghs)
    ifeq ($(findstring @LoadTo=ram, $(TEST_PARAMS)),)
        # if linking into flash
        LINKER_DEFS      :=    $(LINKER_DEFS_GHS_FLASH)
    else
        #if linking into ram
        LINKER_DEFS      :=    $(LINKER_DEFS_GHS_RAM)
    endif
    printout := $(shell echo  .set COMPILER_USED, COMPILER_GHS > compiler_used.s );
else
ifeq ($(TOOLCHAIN),cw)
    ifeq ($(findstring @LoadTo=ram, $(TEST_PARAMS)),)
        # if linking into flash
        LINKER_DEFS      :=    $(LINKER_DEFS_CW_FLASH)
    else
        #if linking into ram
        LINKER_DEFS      :=    $(LINKER_DEFS_CW_RAM)
    endif
    printout := $(shell echo  .set COMPILER_USED, COMPILER_CW > compiler_used.s );
else
    ifeq ($(findstring @LoadTo=ram, $(TEST_PARAMS)),)
        # if linking into flash
        LINKER_DEFS      :=    $(LINKER_DEFS_DIAB_FLASH)
    else
        #if linking into ram
        LINKER_DEFS      :=    $(LINKER_DEFS_DIAB_RAM)
    endif
    printout := $(shell echo .set COMPILER_USED, COMPILER_DIAB > compiler_used.s );
endif
endif

################################################################################
# Additional test specific C compiler options
################################################################################
CCOPT   +=

#
################################################################################
# Additional test specific linker options
################################################################################
LDOPT           +=

################################################################################
# Custom libraries
################################################################################
LIBS            +=


#