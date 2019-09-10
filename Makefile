#===================================================================================================
#
#    @file        Makefile
#    @version     1.0.0
#
#    @brief       AUTOSAR - Release Check Sample Application Makefile.
#    @details     File used to build the Release Check Sample Application.
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
#===================================================================================================
##===================================================================================================

################################################################################
# Command separator
################################################################################
#
	# running on windows command prompt
	COMMAND_SEPARATOR = &&
	COMMAND_INTERPRETER = cmd
#
################################################################################
# Load and check the configuration
################################################################################

SAMPLE_APP_NAME:= sample_app_mcal


CFG_MAK_FILE := make/config.mak

#
#
# Including local configuration file
#
-include $(CFG_MAK_FILE)

#
# Including cygwin environment tools (absolute paths)
#
TOOLS_DEFS := make/tools.mak


#

include $(TOOLS_DEFS)

# Check the dev dir
ifeq ($(strip $(DEV_DIR)),)
$(error Development directory path (DEV_DIR) is empty)
endif

# Check the Toolchain dir
ifeq ($(strip $(TOOLCHAIN_DIR)),)
$(error TOOLCHAIN directory path (TOOLCHAIN_DIR) is empty)
endif

#
# Check the Build dir
ifeq ($(strip $(BUILD_DIR)),)
$(error Build directory path (BUILD_DIR) is empty)
endif

# Check the AUTOSAR package name
ifeq ($(strip $(AR_PKG_NAME)),)
$(error AUTOSAR package name (AR_PKG_NAME) is empty)
endif

# Check the device name
ifeq ($(strip $(DERIVATIVE)),)
$(error Device name (DERIVATIVE) is empty)
endif

# Check the platform name
ifeq ($(strip $(PLATFORM)),)
$(error Device name (PLATFORM) is empty)
endif

# Check the toolchain name
ifeq ($(strip $(TOOLCHAIN)),)
$(error Toolchain name (TOOLCHAIN) is empty)
endif

#
# Check the dev dir
ifeq ($(strip $(GENERATE_CMD)),)
GENERATE_CMD = generate
endif


# Check log file
ifeq ($(strip $(BUILD_LOG)),)
BUILD_LOG = build.log
$(shell echo Using default BUILD_LOG: $(BUILD_LOG). Other options - file_name or None 1>&2)
endif

ifneq ($(strip $(BUILD_LOG)),None)
CAPTURE_OUTPUT = 2>&1 | $(TEE) -a $(OUT_DIR)/$(BUILD_LOG); \
if test ! "$${PIPESTATUS[0]}" -eq 0 ; then  \
 $(ECHO) ERROR: Build of $(SAMPLE_APP_NAME) has failed >>$(OUT_DIR)/$(BUILD_LOG); \
 $(DO_BEFORE_BUILD_FAIL) \
 exit 1; fi;
else
CAPTURE_OUTPUT :=
endif

# Flags used for M4 and compiler to define macros from CMD line
DEFINE_FLAG_DEFAULT:= -DMCAL_ENABLE_SUPERVISOR_MODE
DEFINE_FLAG_SPECIFIC:= $(DEFINE_FLAG_DEFAULT)

################################################################################
# Path conversion utilities
################################################################################
winpath = $(patsubst /cygdrive/$(word 2,$(subst /, , $(1)))%,$(word 2,$(subst /, ,$(1))):%,$(1))
cygpath = $(if $(findstring :,$(1)),/cygdrive/$(subst :,,$(1)),$(1))
cmdpath = $(subst /,\,$(1))

#

	GENERATE_DIR    = $(DEV_DIR)/mcal_cfg/generated
#
$(shell echo generate dir $(GENERATE_DIR) 1>&2)

AR_PKG_REG_EXP		:= "TS_T[0-9]\{1,2\}D[0-9]\{1,2\}M[0-9]\{1,2\}I[0-9]\{1,2\}R[0-9]\{1,2\}"
OUT_DIR			= $(BUILD_DIR)

#
ifeq ($(strip $(PLUGINS_DIR)),)
	PLUGINS_DIR		:= $(TRESOS_DIR)/plugins
endif
$(shell echo plugins dir $(PLUGINS_DIR) 1>&2)
################################################################################
# Builder specific options defined in the included make
#
#	CC; LD; AS ... 			generators
#	CCOPT; LDOPT; ASOPT		their options
#	LIBS; INCLUDE_DIRS; SRC_FILES	system libs, inlude dirs, and sourceinclude files
#
#	EXE_EXT				test file extentions
#	COMPILE_C_FILE			macro called for "C -> OBJ" rule
#	COMPILE_S_FILE			macro called for "S -> OBJ" rule (could be blank)
#	LINK_O_FILES			macro called for "OBJ -> $(EXE_EXT)" rule
#
################################################################################

#include toolchain options
BUILD_CFG_FILE := make/$(TOOLCHAIN)/build_cfg.mak


# Include the sample specification make file
BUILD_FILES_LIST := $(DEV_DIR)/make/files.mak


#
#
include $(BUILD_FILES_LIST)

include $(BUILD_CFG_FILE)

$(shell echo build  file $(BUILD_FILES_LIST) 1>&2)
$(shell echo build cfg file dir $(BUILD_CFG_FILE) 1>&2)

################################################################################
# Add link to Vector_vle_mcal.s
################################################################################
SRC_FILES    += $(DEV_DIR)/toolchains/Vector_vle_core.s
SRC_FILES    += $(DEV_DIR)/toolchains/Vector_vle_mcal.s

# List of all source file names (.c files in SRC_DIRS directories and SRC_FILES)
ALL_SRC_FILES := $(foreach DIR,$(SRC_DIRS), $(wildcard $(call winpath, $(DIR))/*.c)) $(foreach FILE, $(SRC_FILES), $(call winpath, $(FILE)))
OUT_FILES := $(foreach DIR,$(SRC_DIRS),$(notdir $(wildcard $(DIR)/*.c))) $(notdir $(SRC_FILES))
PARSE_FILES := $(OUT_FILES:.c=.par)
OUT_FILES := $(OUT_FILES:.c=.o)
OUT_FILES := $(OUT_FILES:.C=.o)
OUT_FILES := $(OUT_FILES:.s=.o)
OUT_FILES := $(sort $(OUT_FILES))

# Append directories of the SRC_FILES
SRC_DIRS += $(dir $(SRC_FILES))

# List of include files (must be in the cygwin path format since they are used in prerequisities)
INCLUDE_FILES := $(foreach DIR, $(INCLUDE_DIRS), $(wildcard $(DIR)/*.h))

# List of include directories (must be in the windows path format since it's passed to the compiler)
INCLUDE_DIRS := $(foreach DIR, $(INCLUDE_DIRS), $(call winpath, $(DIR)))

# Print a delimiter line after the make header log
$(shell echo ----------------------------------------------------------------------------- 1>&2)

################################################################################
# Build targets
################################################################################
.PHONY: build
build: $(OUT_DIR)/$(SAMPLE_APP_NAME).$(EXE_EXT)

vpath %.c $(addsuffix :, $(SRC_DIRS))
vpath %.C $(addsuffix :, $(SRC_DIRS))
vpath %.s $(addsuffix :, $(SRC_DIRS))
vpath %.o $(OUT_DIR)

$(OUT_DIR)/$(SAMPLE_APP_NAME).$(EXE_EXT): $(OUT_FILES) $(LIBS) $(LINKER_DEF)
	$(call LINK_O_FILES)  $(call CAPTURE_OUTPUT)

%.o : %.c $(INCLUDE_FILES)
	$(call COMPILE_C_FILE)  $(call CAPTURE_OUTPUT)

%.o : %.C $(INCLUDE_FILES)
	$(call COMPILE_C_FILE)  $(call CAPTURE_OUTPUT)

%.o : %.s
	$(call COMPILE_S_FILE)  $(call CAPTURE_OUTPUT)

################################################################################
# Type the list of available tests on specified directory
################################################################################
.PHONY: help
help:
		@$(ECHO);
		@$(ECHO) "Makefile for building the MCAL Sample Application"
		@$(ECHO) "        "
		@$(ECHO) "Available targets:"
		@$(ECHO) "    build - compiles and links the application"
		@$(ECHO) "    clean - cleans the folder structure of the files generated during build"
		@$(ECHO) "        "
		@$(ECHO) "Options:"
		@$(ECHO) "    TOOLCHAIN=toolchain_name  - selects the toolchain used for building the application"
		@$(ECHO) "           Possible values for toolchain_name:"
		@$(ECHO) "                 - ghs  - (default) - Builds with GreenHills Multi. Uses GHS_DIR environment variable."
		@$(ECHO) "                 - cw   - Builds with Freescale CodeWarrior for MPC. Uses CW_DIR environment variable."
		@$(ECHO) "                 - diab - Builds with Windriver DIAB. Uses DIAB_DIR environment variable."
		@$(ECHO) "        "
		@$(ECHO) "Example commands:"
		@$(ECHO) "        "
		@$(ECHO) "    make clean"
		@$(ECHO) "    make build"
		@$(ECHO) "    make TOOLCHAIN=diab clean build"
		@$(ECHO) "        "

#

################################################################################
# Clean targets
################################################################################
.PHONY: clean
# delete all files
clean:
	$(RM) $(call cmdpath, $(OUT_DIR)/*.elf)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.a)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.o)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.d)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dba)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dbo)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dla)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dnm)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.map)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.run)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.lst)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.si)
	$(RM) compiler_used.s

#
#
################################################################################
# Makefile debug targets
################################################################################
print-%: ; $(error DEBUG Info: $* is $($*) ($(value $*)) (from $(origin $*)))

