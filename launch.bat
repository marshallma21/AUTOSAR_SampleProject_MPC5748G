::===================================================================================================
::
::    @file        launch.bat
::    @version     1.0.0
::
::    @brief       AUTOSAR - Sample_app - launches build.
::    @details     Launches the build of the sample application
::
::    Project      : AUTOSAR 4.2 MCAL
::    Patform      : PA
::    Peripheral   : 
::    Dependencies : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM
::
::    Autosar Version       : 4.2.2
::    Autosar Revision      : ASR_REL_4_2_REV_0002
::    Autosar Conf. Variant :
::    Software Version      : 1.0.0
::    Build Version         : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20171702
::
::    (c) Copyright 2006-2017 NXP Inc
::    All Rights Reserved.
::
::    This file contains sample code only. It is not part of the production code deliverables.
::
::===================================================================================================
::::===================================================================================================

@echo off

::You have to uncomment and set the following variables if they are not already set
:: uncomment line below if you do not set TRESOS_DIR over environment
::TRESOS
SET TRESOS_DIR=D:/EB/tresos
::MAKE
SET MAKE_DIR=D:/NXP/S32DS_Power_v2.1/S32DS/build_tools/msys32/usr
::GHS
SET GHS_DIR=C:/Tools/ghs/comp_201516_ppc
::DIAB
SET DIAB_DIR=D:/WindRiver/compilers/diab-5.9.6.2
::IAR
::SET IAR_DIR=C:/Tools/IAR Systems/Embedded Workbench 7.3/arm/
::Path to the plugins folder
SET PLUGINS_DIR=./plugins
::SSC
SET SSC_ROOT=C:/Freescale/AUTOSAR/MPC574xG_AUTOSAR_OS_4_0_86_RTM_1_0_1

if not defined TRESOS_DIR GOTO missing_path_names_TRESOS_DIR
if not exist %TRESOS_DIR% GOTO missing_path_names_TRESOS_DIR
if not defined MAKE_DIR GOTO missing_path_names_MAKE_DIR
if not exist %MAKE_DIR% GOTO missing_path_names_MAKE_DIR

cmd /c "make.bat %1 %2 %3 %4 %5 %6"

GOTO end

:: The variable TRESOS_DIR was not specified
:missing_path_names_TRESOS_DIR
ECHO.
ECHO    The variable TRESOS_DIR was not set correctly.
ECHO    Please specify this variable manually, by editing
ECHO    the batch file 'launch.bat'.
ECHO.
pause
GOTO end

:: The variable MAKE_DIR was not specified
:missing_path_names_MAKE_DIR
ECHO.
ECHO    The variable MAKE_DIR was not set correctly.
ECHO    Please specify this variable manually, by editing
ECHO    the batch file 'launch.bat'.
ECHO.
pause
GOTO end

:end
