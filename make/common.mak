#===================================================================================================
#
#    @file        common.mak
#    @version     1.0.2
#
#    @brief       AUTOSAR - Release Check Sample Application Makefile.
#    @details     File used to build the Release Check Sample Application.
#
#    Project      : AUTOSAR 4.0 MCAL
#    Platform     : PA
#    Peripheral   : 
#    Dependencies : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM
#
#    Autosar Version       : 4.0.3
#    Autosar Revision      : ASR_REL_4_0_REV_0003
#    Autosar Conf. Variant :
#    Software Version      : 1.0.2
#    Build Version         : MPC5746C_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20160812
#	 This file contains sample code only. It is not part of the production code deliverables.
#
#    (c) Copyright 2006-2016 Freescale Semiconductor Inc
#    All Rights Reserved.
#
#===================================================================================================
##===================================================================================================


# TOOLS
RM    :=del /f /q
ECHO  :=echo

# Tresos path
TRESOS_BASE = $(TRESOS_DIR)
TRESOSBASE  = $(TRESOS_BASE)

# Compiler by default
ifeq ($(TOOLCHAIN),)
compiler=ghsppc
endif

ifeq ($(TOOLCHAIN),ghs)
compiler=ghsppc
endif

ifeq ($(TOOLCHAIN),diab)
compiler=diabppc
endif

ifeq ($(TOOLCHAIN),cw)
compiler=cwppc
endif


# Path to compiler directory
ifeq ($(compiler),diabppc)
DIABDIR     = $(DIAB_DIR)
endif
ifeq ($(compiler),ghsppc)
GHSDIR       = $(GHS_DIR)
endif

# Check of compiler type
ifneq ($(compiler),diabppc)
ifneq ($(compiler),ghsppc)
ifneq ($(compiler),cwppc)
$(error Undefined compiler type: '$(compiler)', use ghsppc or diabppc.)
endif
endif
endif

# MCU type
ifeq ($(mcu),)
ifeq ($(sc),1)
# mcu type by default
mcu=5746C
endif
ifeq ($(sc),2)
mcu=5607B
endif
ifeq ($(sc),3)
mcu=5606S
endif
ifeq ($(sc),4)
mcu=5606S
endif
endif

# Check of mcu type
ifneq ($(mcu),5746C)
ifneq ($(mcu),5604P)
ifneq ($(mcu),5606S)
$(error Undefined mcu type: '$(mcu)', expected one of following: 5607B, 5604P or 5606S)
endif
endif
endif

# Check type of derivative
ifeq ($(mcu),5604P)
ifeq ($(sc),3)
$(error MPC5604P do not have MPU)
endif
endif

ifeq ($(mcu),5604P)
ifeq ($(sc),4)
$(error MPC5604P do not have MPU)
endif
endif

register_define = $(eval $(1)_KEY =$(1));$(eval $(1)_VALUE=$($(1))));$(eval PREPROCESSOR_DEFINES += $(1)))
remove_slashes = $(subst /,\,$(1))
to_dslashes = $(subst \\,\,$(1))

empty       =
space       = $(empty) $(empty)

remove_spaces = $(subst $(space),\$(space),$(1))


$(foreach bsw,$(modulelist),\
$(eval bsw_name=$(call remove_slashes,$($(bsw)_dir)))\
$(eval $(bsw)_cfg_dir?=cfgno)\
$(eval PREPROCESSOR_DEFINES += $(bsw) $(bsw_name) $(bsw)_name_string $(bsw)_cfg_id)\
$(eval $(bsw)_KEY=$(bsw)_integrated)\
$(eval $(bsw)_VALUE=1)\
$(eval $(bsw)_name_string_KEY=$(bsw)_name_string)\
$(eval $(bsw)_name_string_VALUE=$(bsw_name)_string)\
$(eval $(bsw)_cfg_id_KEY=$(bsw)_cfg_id)\
$(eval $(bsw)_cfg_id_VALUE=$(call remove_slashes,$($(bsw)_cfg_dir)_id))\
$(eval $(bsw_name)_KEY=$(bsw_name))\
$(eval $(bsw_name)_VALUE=1))

ifeq ($(debug),yes)
cmm_file = $(call remove_slashes,$(BIN_OUTPUT_PATH)\$(projname).cmm)
endif
obj_output_path = $(call remove_slashes,$(OBJ_OUTPUT_PATH))
bin_output_path = $(call remove_slashes,$(BIN_OUTPUT_PATH))

# set final target
.PHONY: all
all: $(BIN_OUTPUT_PATH)\$(projname).elf

ifeq ($(platform),mpc5600)
PLATFORM_DEFINE=_MPC5600_
else
$(error What platform?)
endif

$(call register_define,$(PLATFORM_DEFINE))

#include defs.mak and rules.mak for os
mak_path=ssc\mak
ext_includes=sample\standard\external_includes
include $(SSC_ROOT)\$(mak_path)\os_defs.mak
include $(SSC_ROOT)\$(mak_path)\os_rules.mak

#OS_PROPHEADER = cfg\include\osprop.h
OS_PROPHEADER = cfg\include\Os_prop.h

OBJ_FILE_SUFFIX = o
LIB_FILE_SUFFIX = lib

.SUFFIXES:            # Delete the default suffixes
.SUFFIXES: .c .h .$(OBJ_FILE_SUFFIX) .$(LIB_FILE_SUFFIX)

ifeq ($(compiler),cwppc)
#\/---------- CODE WARRIOR ------------------\/
# CodeWarrior compiler root directory
#CW_DIR      = $(call remove_spaces,$(call remove_slashes,$(CWDIR)))

# Compiler paths
cbin        = $(call cmdpath,$(CW_DIR)/PowerPC_EABI_Tools/Command_Line_Tools)
cinc        = $(call cmdpath,$(CW_DIR)/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include)
clib        = $(call cmdpath,$(CW_DIR)/PowerPC_EABI_Support/Runtime/Lib)
clibinc     = $(call cmdpath,$(CW_DIR)/PowerPC_EABI_Support/Runtime/Include)
ceabinc     = $(call cmdpath,$(CW_DIR)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include)
ceablib     = $(call cmdpath,$(CW_DIR)/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib)

# Executables
CC          = $(cbin)/mwcceppc
CP          = $(cbin)/mwcceppc
AS          = $(cbin)/mwasmeppc
LI          = $(cbin)/mwldeppc

# Compilers' options
ccopt       = -proc Zen -c -vle -fp none -sdata2 0 -sdata 0 -ppc_asm_to_vle -func_align 4 -r -pragma "read_only_switch_tables on" -ansi off \
            -msgstyle gcc -Cpp_exceptions off -opt all,nopeep -MMD -gccdep -g -char unsigned -sym dwarf-2,full

#ccopt_mcal  = -proc Zen -c -vle -fp none -sdata2 0 -sdata 0 -ppc_asm_to_vle -func_align 4 -r -pragma "read_only_switch_tables on" \
#              -ansi off -msgstyle gcc -Cpp_exceptions off -opt all,nopeep -MMD -gccdep -g -sym dwarf-2,full

ccopt_mcal  =  -proc Zen $(PRJFLAG) -DMWERKS -MMD -ansi off -pragma "read_only_switch_tables on" -vle -nosyspath -common off -w on \
                -char unsigned -sdatathreshold 0 -sdata2threshold 0 -Cpp_exceptions off -use_lmw_stmw on \
                -r $(SUBDERIVATIVE_NAME) -sym dwarf-2,full $(VLETYPE) -gdwarf-2 \
                -DEU_DISABLE_ANSILIB_CALLS -lang c -fp none -opt all  -func_align 4 -w undefmacro \
                -ir $(call winpath, $(TOOLCHAIN_DIR))/PowerPC_EABI_Support/MSL/MSL_C \
                -ppc_asm_to_vle -DMCAL_CER_VALIDATION 


cpopt       = -nostdinc -nosyspath -DOSCWPPC -I$(cinc) -I$(clib) -I$(clibinc) -I$(ceabinc)

cpopt += -DFLASH_START

asopt       = -msgstyle gcc -proc Zen -DOSPROPH="\"$(OS_PROPHEADER)\""  -MMD -gccdep -vle -sym dwarf-2,full


LIBRARIES_LINK_ONLY += $(clib)/Runtime.PPCEABI.V.a $(ceablib)/MSL_C.PPCEABI.bare.V.a

ldopt       = -proc Zen -code_merging all -far_near_addressing -vle_enhance_merging -romaddr 0x00000000 -rambuffer 0x00000000 \
              -msgstyle gcc -nostdlib -char unsigned -g -sym dwarf-2,full  -listdwarf -map -lcf $(LINKER_CMD_OUTFILE) $(FILES_TO_LINK)

#/\---------- CODE WARRIOR ------------------/\

endif  # $(compiler) == cwppc

ifeq ($(compiler),diabppc)

#\/---------- DIAB ------------------\/


# Compilers' options
ctrg = PPCE200Z4204N3VEG:simple

# Compiler paths
cbin        = $(call cmdpath, $(DIAB_DIR)/win32/bin)
cinc        = $(call cmdpath, $(DIAB_DIR)/include)
clib        = $(call cmdpath, $(DIAB_DIR)/PPCVLEE)

# Executables
CC          = $(cbin)/dcc
CP          = $(cbin)/dcc
AS          = $(cbin)/das
LI          = $(cbin)/dld

# Compilers' options

ccopt       =  -t$(ctrg) -c -DOSDIABPPC -Xdialect-ansi -Xmake-dependency=4 -g -XO \
               -Wa,-Xisa-vle -Xdebug-dwarf2 -Xdebug-inline-on -Xdebug-local-all -Xdebug-struct-all \
               -Xdebug-local-cie -Xsmall-data=0 -Xnested-interrupts \
               -Xforce-declarations -ee1481 -Xsemi-is-newline


#ccopt_mcal  =  -tPPCE200Z4VEN:simple $(PRJFLAG) $(DEBUG_FLAGS) $(SUBDERIVATIVE_NAME) -DDIAB -DEU_DISABLE_ANSILIB_CALLS \
#                -g -c -Xdialect-ansi -XO -Xsize-opt -Xsmall-data=0 -Xno-common -Wa,-Xisa-vle -Xdebug-dwarf2 \
#               -Xdebug-local-all -Xdebug-local-cie -Xdebug-struct-all -Xforce-declarations -Xmacro-undefined-warn \
#                -ee1481 -Xnested-interrupts -Xaddr-sconst=0x11 -Xaddr-sdata=0x11 \
#               -DMCAL_CER_VALIDATION

ccopt_mcal       := -t$(ctrg) \
				-c \
                -DMPC$(DERIVATIVE) \
                -DDERIVATIVE_$(DERIVATIVE) \
                -DDIAB \
                -DEU_DISABLE_ANSILIB_CALLS \
                -Xdialect-ansi \
                -XO \
                -Xsize-opt \
                -Xsmall-data=0 \
                -Xno-common \
				-g3 \
                -Wa,-Xisa-vle \
                -Xdebug-dwarf2 \
                -Xdebug-local-all \
                -Xdebug-local-cie \
                -Xdebug-struct-all \
                -Xforce-declarations \
                -Xmacro-undefined-warn \
                -ee1481 \
                -Xnested-interrupts \
                -Xc-new \
                -Xaddr-sconst=0x11 \
                -Xaddr-sdata=0x11 \
                -Xlink-time-lint \
                -DMCAL_CER_VALIDATION

ccopt       += -Xmacro-undefined-warn # generate a warning when an undefined macro name occurs in an #if preprocessor directive
ccopt_mcal  += -Xmacro-undefined-warn # generate a warning when an undefined macro name occurs in an #if preprocessor directive

cpopt       = -I$(cinc) -DOSDIABPPC
asopt       = -t$(ctrg) -g -Xisa-vle -Xasm-debug-on
ldopt       = -t$(ctrg) -lc -m6 -Xelf -Xlibc-old -Xstop-on-redeclaration=0 $(call remove_slashes,$(LINKER_CMD_OUTFILE)) \
               $(call remove_slashes,$(FILES_TO_LINK)) -@O=$(bin_output_path)/$(projname).map

asopt +=-D FLASH_START
cpopt +=-D FLASH_START

#/\---------- DIAB ------------------/\

endif  # $(compiler) == diabppc

ifeq ($(compiler),ghsppc)

#\/---------- GREEN HILLS ------------------\/

proc        = ppc5646

# Compiler paths
cbin        = $(GHS_DIR)
cinc        = $(call cmdpath, $(GHS_DIR)/include)
clib        = $(call cmdpath, $(GHS_DIR)/lib/ppc5514)
clibinc     = $(call cmdpath, $(GHS_DIR)/include)
ceabinc     = $(call cmdpath, $(GHS_DIR)/include)
ceablib     = $(call cmdpath, $(GHS_DIR)/lib/ppc5514)

# Executables
CC 			:= $(call cmdpath, $(GHS_DIR)/ccppc.exe)
LI 			:= $(call cmdpath, $(GHS_DIR)/ccppc.exe)
AS 			:= $(call cmdpath, $(GHS_DIR)/asppc.exe)

# Compilers' options
ccopt       = -cpu=$(proc) -c -noSPE --no_exceptions -vle -g -dual_debug -DOSGHSPPC -O2 -sda=0 --diag_error 223 -MD -Ospace
                   
#ccopt_mcal  = -cpu=ppc5646 -ansi -noSPE -Ospace -sda=0 -vle -dual_debug -G --no_exceptions -Wundef -Wimplicit-int -Wshadow \
#                -Wtrigraphs --prototype_errors --incorrect_pragma_warnings -noslashcomment -preprocess_assembly_files -c \
#                --short_enum -DEU_DISABLE_ANSILIB_CALLS -DMCAL_CER_VALIDATION -DGHS

ccopt_mcal 			:=  -cpu=$(proc) \
                    -c \
                    -DMPC$(DERIVATIVE) \
                    -DGHS \
                    --incorrect_pragma_warnings \
                   -vle \
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
                   --short_enum
                
cpopt       = -I$(cinc) -I$(clib) -I$(clibinc) -I$(ceabinc) -DOSGHSPPC


cpopt += -DFLASH_START


asopt       = -cpu=$(proc)
#-DOSPROPH="\"$(OS_PROPHEADER)\"" -g -list

ldopt       = -cpu=$(proc) -nostartfiles -linker_warnings -vle -keepmap $(LINKER_CMD_OUTFILE) $(FILES_TO_LINK)

#/\---------- GREEN HILLS ------------------/\

endif  # $(compiler) == ghsppc


ifeq ($(cfg),xdm)
ifeq ($(TRESOS_BASE),)
$(error Variable TRESOS_BASE must be set)
endif
endif

ifeq ($(compiler),diabppc)
ifeq ($(DIABDIR),)
$(error Variable DIABDIR must be set)
endif
endif

ifeq ($(compiler),ghsppc)
ifeq ($(GHSDIR),)
$(error Variable GHSDIR must be set)
endif
endif

# List of include directories (must be in the windows path format since it's passed to the compiler)
INCLUDE_DIRS := $(foreach DIR, $(INCLUDE_DIRS), $(call winpath, $(DIR)))
CC_INCLUDE_PATH += $(INCLUDE_DIRS)

cpopt      += $(addprefix -I,$(call remove_slashes,$(CC_INCLUDE_PATH)))
cpopt      += $(foreach define,$(PREPROCESSOR_DEFINES),-D$($(define)_KEY)=$($(define)_VALUE))
cpopt      += -DMPC$(mcu) -DSCHM_USE_MACROS


OBJ_OUTPUT_PATH1=$(BIN_OUTPUT_PATH)

# C rule
define generate_c_rule
$(addprefix $(OBJ_OUTPUT_PATH1)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(1))))): $(1)
	@$(ECHO) Processing $$<
	$(CC) $(ccopt) $(cpopt) $$(call cmdpath, $$<) -o $$(call cmdpath, $$@)
	@$(ECHO) DONE
endef

# C rule for MCAL
define generate_c_rule_mcal
$(addprefix $(OBJ_OUTPUT_PATH1)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(1))))): $(1)
	@$(ECHO) Processing $$<
	$(CC) $(ccopt_mcal) $(cpopt) $$(call cmdpath, $$<) -o $$(call cmdpath, $$@)
	@$(ECHO) DONE
endef

# Asm rule
define generate_asm_rule
$(addprefix $(OBJ_OUTPUT_PATH1)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(1))))): $(1)
	@$(ECHO) Processing $(1)
	$(AS) $(asopt) -o $$(call cmdpath, $$@) $$(call cmdpath, $$<)
	@$(ECHO) DONE
endef

XX_FILES_TO_BUILD = $(CC_FILES_TO_BUILD) $(S_FILES_TO_BUILD) $(ASM_FILES_TO_BUILD) $(ALL_SRC_FILES)
XX_OBJ_FILES = $(addprefix $(OBJ_OUTPUT_PATH1)\,$(addsuffix .$(OBJ_FILE_SUFFIX),$(basename $(notdir $(XX_FILES_TO_BUILD)))))
FILES_TO_LINK = $(XX_OBJ_FILES) $(LIBRARIES_LINK_ONLY) $(OBJECTS_LINK_ONLY)

# Dependencies
#-include $(XX_OBJ_FILES:.o=.d)

# Generation of C and assempler rules
$(foreach file,$(CC_FILES_TO_BUILD),$(eval $(call generate_c_rule, $(call to_dslashes, $(file)))))
# Generate with MCAL compiler option
$(foreach file,$(ALL_SRC_FILES),$(eval $(call generate_c_rule_mcal, $(call to_dslashes, $(file)))))
$(foreach file,$(ASM_FILES_TO_BUILD),$(eval $(call generate_asm_rule,$(file))))


# Rule for linking
$(BIN_OUTPUT_PATH)\$(projname).elf: $(FILES_TO_LINK) $(cmm_file) $(LINKER_CMD_OUTFILE)
	@$(ECHO) Linking $@
	$(LI) $(ldopt)  -o $(call winpath, $@)


# Target for show internal options
showflags:
	@$(ECHO) COMPILEROPTIONS = $(ccopt) $(cpopt)
	@$(ECHO) LINKEROPTIONS = $(ldopt)
	@$(ECHO) PREPROCESSOR_DEFINES = $(PREPROCESSOR_DEFINES)
	@$(ECHO) CC_FILES_TO_BUILD = $(CC_FILES_TO_BUILD)
	@$(ECHO) ASM_FILES_TO_BUILD = $(ASM_FILES_TO_BUILD)
	@$(ECHO) CC_INCLUDE_PATH = $(CC_INCLUDE_PATH)
	@$(ECHO) ALL_SRC_FILES = $(ALL_SRC_FILES)
	@$(ECHO) SRC_FILES = $(SRC_FILES)

clean:
	@$(ECHO) Clean...
	$(RM) $(call cmdpath, $(OUT_DIR)/*.elf)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.a)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.o)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dba)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dbo)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dla)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dnm)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.map)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.run)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.lst)
	$(RM) *.si
	$(RM) *.s
	$(RM) compiler_used.s
	$(RM) $(call cmdpath, $(OUT_DIR)/*.d)

clean_keep_elf:
	@$(ECHO) Clean with keep elf ...
	$(RM) $(call cmdpath, $(OUT_DIR)/*.a)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.o)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dba)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dbo)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dla)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.dnm)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.map)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.run)
	$(RM) $(call cmdpath, $(OUT_DIR)/*.lst)
	$(RM) *.si
	$(RM) *.s
	$(RM) compiler_used.s
	$(RM) $(call cmdpath, $(OUT_DIR)/*.d)
