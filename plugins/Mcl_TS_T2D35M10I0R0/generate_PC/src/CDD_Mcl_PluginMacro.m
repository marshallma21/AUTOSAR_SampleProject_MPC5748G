[!NOCODE!][!//
/**
  @file    Mcl_PluginMacros.m
  @version 1.0.0

  @brief   AUTOSAR Mcl - plugin check.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform PA
  Peripheral eDMA
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.0
  BuildVersion MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/
[!/* *************************** Dem config macro ******************************
******************************************************************************/!]
[!MACRO "DemConfig","MclConfigType"!]

/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
* @violates @ref Mcl_Cfg_c_REF_10 MISRA 2004 Required Rule 8.10, all declarations must be static */
[!IF "$MclConfigType = ''"!]
CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config =
[!ELSE!][!//
CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config_[!"$MclConfigType"!] =
[!ENDIF!]
{

    /** MCL_DMA_E_BUS error code */ 
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_BUS)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_BUS)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_BUS)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},

    /** MCL_DMA_E_DESCRIPTOR  error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_DESCRIPTOR)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_DESCRIPTOR)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_DESCRIPTOR)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    /** MCL_DMA_E_ECC error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_ECC)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_ECC)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_ECC)/@name"!]
    [!ELSE!]
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    /** MCL_DMA_E_PRIORITY error code */ 
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_PRIORITY)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_PRIORITY)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_PRIORITY)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    
    /** MCL_DMA_E_UNRECOGNIZED error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_UNRECOGNIZED)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_UNRECOGNIZED)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_UNRECOGNIZED)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]},
    
    /** MCL_DMA_E_INCONSISTENCY error code */
    {
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_INCONSISTENCY)"!][!//
        (uint32)STD_ON,
    [!ELSE!][!//
        (uint32)STD_OFF,
    [!ENDIF!][!//
    [!IF "node:exists(MclDemEventParameterRefs/MCL_E_DMA_INCONSISTENCY)"!][!//
        (uint16)DemConf_DemEventParameter_[!"node:ref(MclDemEventParameterRefs/MCL_E_DMA_INCONSISTENCY)/@name"!]
    [!ELSE!][!//
        (uint16)0U
    [!ENDIF!]
    [!/* */!]}
};

[!ENDMACRO!][!// Dem config end

[!/* *************************** Notification config macro ******************************
******************************************************************************/!]
[!MACRO "NotificationHandler","Suffix"!]

#if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
/* DMA Channel Transfer Completion Notifications */
    [!NOCODE!]
        [!VAR "OuterLoopCounter" = "0"!]
        [!VAR "InnerLoopCounter" = "0"!]
        [!LOOP "MclConfigSet/*/DMAChannel/*"!]
            [!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
            [!VAR "InnerLoopCounter" = "0"!]
            [!VAR "MatchCounter" = "0"!]  
            [!VAR "Notification" = "MclDmaTransferCompletionNotif"!]
            
            [!LOOP "../../../*/DMAChannel/*"!]
              [!IF "(MclDmaTransferCompletionNotif != 'NULL_PTR') and (MclDmaTransferCompletionNotif != '"NULL"') and (MclDmaTransferCompletionNotif != 'NULL')"!]
                  [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
                  [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
                      [!IF "($Notification = MclDmaTransferCompletionNotif)"!]
                          [!VAR "MatchCounter" = "$MatchCounter + 1"!]
                      [!ENDIF!]
                  [!ENDIF!]
              [!ENDIF!]
            [!ENDLOOP!]

            [!IF "$MatchCounter = 1"!]
                /* issue error if the ISR is disabled */
                [!VAR "hwCh" = "DmaHwChannel"!]
                [!LOOP "../../../../MclGeneral/MclIsrAvailable/*"!]
                    [!IF "(MclIsrName = $hwCh) and (MclIsrEnabled =  'false')"!]
                        [!ERROR!] [!//
                             "Interrupt configuration error ! Mcl hardware channel [!"$hwCh"!] has a transfer completion notification configured in one of the variants, but the ISR for the channel is disabled in the Mcl Interrupts Available TAB. "[!//
                        [!ENDERROR!][!//
                    [!ENDIF!]
                [!ENDLOOP!]
                /* generate declaration */
                [!CODE!][!//
                [!IF "$Suffix = ''"!][!//
                /** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_11 MISRA 2004 Rule 8.8 */
                [!ELSEIF "$Suffix = 'PC'"!][!//
                /* */
                [!ELSEIF "$Suffix = 'PB'"!][!//
                /* */
                [!ENDIF!][!//
    extern FUNC(void, MCL_CODE)[!"MclDmaTransferCompletionNotif"!](void);[!//      
                [!ENDCODE!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDNOCODE!]
#endif

/* DMA error notifications */
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
[!IF "(MclGeneral/MclErrorNotificationDma0 != 'NULL_PTR') and (MclGeneral/MclErrorNotificationDma0 != '"NULL"') and (MclGeneral/MclErrorNotificationDma0 != 'NULL')"!]
    /** Notification for DMA0 */  
    [!IF "$Suffix = ''"!][!//
    /** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 Violates MISRA 2004 Required Rule 8.10 All declarations and definitions should have internal linkage */ 
    /** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_11 MISRA 2004 Rule 8.8 */
    [!ELSEIF "$Suffix = 'PC'"!][!//
    /** @violates @ref Mcl_Cfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10 All declarations and definitions should have internal linkage */  
    [!ELSEIF "$Suffix = 'PB'"!][!//
     /** @violates @ref Mcl_PBcfg_c_REF_10 Violates MISRA 2004 Required Rule 8.10 All declarations and definitions should have internal linkage */  
    [!ENDIF!]
    extern FUNC(void, MCL_CODE) [!"normalize-space(MclGeneral/MclErrorNotificationDma0)"!](VAR(Mcl_DmaChannelErrorStatusType, AUTOMATIC) u8ErrorCode);
[!ENDIF!]
#endif

[!ENDMACRO!][!// Notification config end



[!/* *************************** DMA channel config ******************************
******************************************************************************/!]
[!MACRO "DmaChannelConfig","DmaConfigType"!]

[!IF "$DmaConfigType ='PC'"!]
static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig_[!"$DmaConfigType"!][MCL_DMA_CONF_CHANNELS_[!"$DmaConfigType"!]] =
[!ELSEIF "$DmaConfigType ='PB'"!]
static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMA_CONF_CHANNELS_[!"$DmaConfigType"!]_[!"@index"!]] =
[!ELSE!]
static CONST(Mcl_DmaChannelConfigType, MCL_CONST) Mcl_Dma_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
[!ENDIF!]
{
[!FOR "varCounter" = "0" TO "num:i(count(DMAChannel/*))"!][!//
[!LOOP "DMAChannel/*"!][!//
[!IF "MclDMAChannelId = $varCounter"!][!//
    /** @brief [!"node:name(.)"!] - [!"DmaHwChannel"!] */
    { 
[!/* */!][!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
        /** @brief Enable Channel Preemption */
        ([!IF "ECP='true'"!]DMA_ECP_EN_U8[!ELSE!]DMA_ECP_DIS_U8[!ENDIF!]) |
        /** @brief Disable Preempt Ability */
        ([!IF "DPA='true'"!]DMA_DPA_EN_U8[!ELSE!]DMA_DPA_DIS_U8[!ENDIF!]) |
        /** @brief Channel Priority */
        (DMA_PRIORITY_[!"DMAChannelPriority"!]_U8),
        /** @brief eDMA HW Channel used by the Mcl channel */
        DMA_HW_CHANNEL_[!"$DmaCh"!],
        /** @brief Master ID Replication */
        [!WS "8"!][!IF "EMI='true'"!]DMA_EMI_EN_U8[!ELSE!]DMA_EMI_DIS_U8[!ENDIF!][!CR!]
    }[!IF "(num:i($comma))<(num:i($dmaChannelCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!// DMA channel config

[!/* *************************** DMA instance config ******************************
******************************************************************************/!]
[!MACRO "DmaInstanceConfig","DmaConfigType"!]
/** @brief Configuration for Dma instances */
[!IF "$DmaConfigType = 'PC'"!]
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig_[!"$DmaConfigType"!][MCL_DMA_NB_CONTROLLERS] =
[!ELSEIF "$DmaConfigType = 'PB'"!]
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMA_NB_CONTROLLERS] =
[!ELSE!]
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_10 external ... could be made static */
static CONST(Mcl_DmaConfigInstanceType, MCL_CONST) Mcl_Dma_InstanceConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_NB_CONTROLLERS] =
[!ENDIF!] 
{
[!//
[!NOCODE!]
    [!VAR "comma" = "0"!][!//
    [!FOR "currentInstance" = "0" TO "$LastDmaInstanceId"!]
    [!CODE!]{[!ENDCODE!][!//
        [!VAR "dmaCurrentInstanceExists" = "num:i(0)"!][!//
        [!LOOP "DmaInstance/*"!][!//
            [!VAR "dmaCurrentInstanceNumber" = "substring-after(node:value(DmaHwInstance),'eDMA_Instance')"!][!//
            [!IF "$dmaCurrentInstanceNumber = $currentInstance"!][!//
                [!VAR "dmaCurrentInstanceExists" = "num:i(1)"!][!//
                [!VAR "ChannelExistsForCrtDmaInstance" = "num:i(0)"!][!//
                [!LOOP "../../DMAChannel/*"!][!//
                    [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
                    [!VAR "Group" = "num:i($DmaCh div $ChannelsPerDmaGroup)"!][!//
                    [!VAR "CurrentDma" = "num:i($Group div (num:i($ChannelsPerDmaInstance div $ChannelsPerDmaGroup)))"!][!//
                    [!IF "num:i($dmaCurrentInstanceNumber) = $CurrentDma"!][!//
                        [!VAR "ChannelExistsForCrtDmaInstance"="num:i(1)"!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
                [!IF "$ChannelExistsForCrtDmaInstance=0"!][!//
                    [!ERROR!][!//
                    "Inconsistent Configuration! For Dma Instance [!"$currentInstance"!] there is no channel configured.Delete instance eDMA_Instance[!"$currentInstance"!]."[!//
                    [!ENDERROR!][!//
                [!ENDIF!][!CR!]
[!CODE!]    /** @brief Dma Hardware Instance [!"$currentInstance"!]*/
    /** @brief Dma CR Register */
    (uint32)(([!IF "MclEDMA_CX='true'"!]DMA_CANCEL_TRANSFER_EN_U32[!ELSE!]DMA_CANCEL_TRANSFER_DIS_U32[!ENDIF!]) |
    ([!IF "MclEDMA_ECX='true'"!]DMA_ERROR_CANCEL_TRANSFER_EN_U32[!ELSE!]DMA_ERROR_CANCEL_TRANSFER_DIS_U32[!ENDIF!]) | 
    [!IF "MclEDMA_ERGA='false'"!][!//
    [!IF "$DmaPriorityGroup0Exists = 'true'"!][!WS "4"!]((uint32)[!"num:i(MclEDMAChGroup0Priority)"!] << DMA_CHANNEL_GROUP_0_PRIORITY_SHIFT_U8) |[!CR!][!ENDIF!]
    [!IF "$DmaPriorityGroup1Exists = 'true'"!][!WS "4"!]((uint32)[!"num:i(MclEDMAChGroup1Priority)"!] << DMA_CHANNEL_GROUP_1_PRIORITY_SHIFT_U8) |[!CR!][!ENDIF!]
    [!IF "$DmaPriorityGroup2Exists = 'true'"!][!WS "4"!]((uint32)[!"num:i(MclEDMAChGroup2Priority)"!] << DMA_CHANNEL_GROUP_2_PRIORITY_SHIFT_U8) |[!CR!][!ENDIF!]
    [!IF "$DmaPriorityGroup3Exists = 'true'"!][!WS "4"!]((uint32)[!"num:i(MclEDMAChGroup3Priority)"!] << DMA_CHANNEL_GROUP_3_PRIORITY_SHIFT_U8) |[!CR!][!ENDIF!]
    [!ENDIF!][!//
    ([!IF "MclEDMA_CLM='true'"!]DMA_CONT_LINK_MODE_EN_U32[!ELSE!]DMA_CONT_LINK_MODE_DIS_U32[!ENDIF!]) |
    ([!IF "MclEDMA_HALT='true'"!]DMA_HALT_OPERATIONS_EN_U32[!ELSE!]DMA_HALT_OPERATIONS_DIS_U32[!ENDIF!]) |
    ([!IF "MclEDMA_HOE='true'"!]DMA_HALT_ON_ERROR_EN_U32[!ELSE!]DMA_HALT_ON_ERROR_DIS_U32[!ENDIF!]) |[!ENDCODE!]
[!CODE!]    [!IF "MclEDMA_ERGA='true'"!](DMA_ROUND_ROBIN_GROUP_ARB_EN_U32)[!ELSE!]/** @violates @ref Mcl_PB_PC_Cfg_c_REF_11 Boolean operation whose results are invariant shall not be permitted */
    (DMA_ROUND_ROBIN_GROUP_ARB_DIS_U32)[!ENDIF!] |[!ENDCODE!]
[!CODE!]    ([!IF "MclEDMA_ERCA='true'"!]DMA_ROUND_ROBIN_ARB_EN_U32[!ELSE!]DMA_ROUND_ROBIN_ARB_DIS_U32[!ENDIF!]) |
    [!IF "MclEDMA_EDBG='true'"!](DMA_DEBUG_EN_U32)[!ELSE!]/** @violates @ref Mcl_PB_PC_Cfg_c_REF_11 Boolean operation whose results are invariant shall not be permitted */
    (DMA_DEBUG_DIS_U32)[!ENDIF!]),
    /** @brief Dma Usage in Configuration */[!CR!]
    [!IF "$ChannelExistsForCrtDmaInstance=1"!]    DMA_INSTANCE_USED[!ELSE!]    DMA_INSTANCE_NOT_USED[!ENDIF!]
    
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ,
    /** @brief DMA error notification function */[!ENDCODE!]
[!IF "$currentInstance = 0"!][!//
    [!/* */!][!IF "(../../../../MclGeneral/MclErrorNotificationDma0 = '') or (../../../../MclGeneral/MclErrorNotificationDma0 = 'NULL_PTR') or (../../../../MclGeneral/MclErrorNotificationDma0 = 'NULL')"!][!//
[!CODE!]    NULL_PTR[!ENDCODE!]
    [!/* */!][!ELSE!][!//
[!CODE!]    &[!"../../../../MclGeneral/MclErrorNotificationDma0"!][!ENDCODE!]
    [!/* */!][!ENDIF!][!//
[!ENDIF!]
[!CODE!]
#endif
[!ENDCODE!]

[!CODE!]    }[!IF "(num:i($comma))<(num:i($LastDmaInstanceId))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$dmaCurrentInstanceExists=0"!][!//
        [!LOOP "DMAChannel/*"!][!//
                [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
                [!VAR "Group" = "num:i($DmaCh div $ChannelsPerDmaGroup)"!][!//
                [!VAR "CurrentDma" = "num:i($Group div (num:i($ChannelsPerDmaInstance div $ChannelsPerDmaGroup)))"!][!//
                [!IF "num:i($currentInstance) = $CurrentDma"!][!//
                    [!ERROR!][!//
                           "Inconsistent Configuration! Dma hardware channel eDMA_[!"$DmaCh"!] uses Dma instance eDMA_Instance[!"$currentInstance"!] which is not configured."[!//
                    [!ENDERROR!][!//
                [!ENDIF!][!//
        [!ENDLOOP!]
[!CODE!]    /** @brief Dma Hardware Instance [!"$currentInstance"!] */
    /** @brief Dma CR Register */
    (Mcl_DmaControlType)0x00000400UL,
    /** @brief Dma Usage in Configuration */
    DMA_INSTANCE_NOT_USED
#if (MCL_DMA_ERROR_INTERRUPTS_USED == STD_ON)
    ,
    NULL_PTR
#endif
[!ENDCODE!]
[!CODE!]    }[!IF "(num:i($comma))<(num:i($LastDmaInstanceId))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!ENDCODE!][!//
    [!ENDIF!][!// 
[!ENDFOR!]
[!ENDNOCODE!]
};
[!ENDMACRO!][!// DMA instances config

[!/* *************************** DMA MUX Channel config ******************************
******************************************************************************/!]
[!MACRO "DmaMuxChannelConfig","DmaConfigType"!]
[!IF "$DmaMuxInstancesNumber != 0"!][!//
[!IF "$DmaMuxChannelsNo > 0"!][!//
[!NOCODE!]/***************************** Configuration for DMAMUX ********************/[!ENDNOCODE!][!//
/** @brief Configuration for DmaMux channels */
[!IF "$DmaConfigType = 'PC'"!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]] =
[!ELSEIF "$DmaConfigType = 'PB'"!][!//
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]_[!"@index"!]] =
[!ELSE!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
[!ENDIF!]
{
[!NOCODE!]
[!VAR "comma" = "1"!][!//
[!FOR "varCounter" = "0" TO "num:i(count(DMAChannel/*))"!][!//
    [!LOOP "DMAChannel/*"!][!//
        [!IF "MclDMAChannelId = $varCounter"!][!//
            [!VAR "DmaCh" = "substring-after(node:value(DmaHwChannel),'eDMA_')"!][!//
            [!IF "$ChannelsPerDmaMuxSmall = $ChannelsPerDmaMuxLarge"!][!//
                [!VAR "DmaMuxInstance"="$DmaCh div $ChannelsPerDmaMuxLarge"!][!//
                [!VAR "DmaMuxChannel"="$DmaCh mod $ChannelsPerDmaMuxLarge"!][!//
            [!ELSE!] [!//
                [!IF "$DmaCh < ($NumberOfDmaMuxSmallInstances * $ChannelsPerDmaMuxSmall)"!][!//
                    [!VAR "DmaMuxInstance"="$DmaCh div $ChannelsPerDmaMuxSmall"!][!//
                    [!VAR "DmaMuxChannel"="$DmaCh mod $ChannelsPerDmaMuxSmall"!][!//
                [!ELSE!][!//
                    [!VAR "DmaMuxInstance"="$NumberOfDmaMuxSmallInstances + (($DmaCh - ($NumberOfDmaMuxSmallInstances * $ChannelsPerDmaMuxSmall)) div $ChannelsPerDmaMuxLarge)"!][!//
                    [!VAR "DmaMuxChannel"="($DmaCh - ($NumberOfDmaMuxSmallInstances * $ChannelsPerDmaMuxSmall)) mod $ChannelsPerDmaMuxLarge"!][!//
                [!ENDIF!][!//
            [!ENDIF!] [!//
            [!VAR "DmaMuxInstance"="num:i($DmaMuxInstance)"!][!//
            [!VAR "DmaMuxChannel"="num:i($DmaMuxChannel)"!][!//
            [!IF "$DmaMuxInstance < $DmaMuxInstancesNumber"!][!//            
                [!CODE!][!CR!][!WS,"4"!]{[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]/** @brief Hardware DMAMUX channel used */[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]DMA_MUX_CH_[!"$DmaMuxChannel"!],[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]/** @brief DMAMUX instance used */[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]DMA_MUX_[!"$DmaMuxInstance"!],[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]/** @brief DMAMUX_CHCFGn register configuration */[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!](uint8)(([!IF "MclDMAChannelEnable='true'"!]DMAMUX_CHANNEL_EN_U32[!ELSE!]DMAMUX_CHANNEL_DIS_U32[!ENDIF!]) |[!ENDCODE!]
                [!CODE!][!CR!][!WS,"8"!]([!IF "MclDMAChannelTriggerEnable='true'"!]DMAMUX_CHANNEL_TRIG_EN_U32[!ELSE!]DMAMUX_CHANNEL_TRIG_DIS_U32[!ENDIF!]) |[!ENDCODE!]
                [!FOR "varLoop" = "0" TO "$DmaMuxInstancesNumber - 1"!]
                    [!IF "$DmaMuxInstance=$varLoop"!]
                        [!IF "node:value(concat("DmaSource",string(num:i($varLoop))))!='NOT_USED'"!]
                            [!CODE!][!CR!][!WS,"8"!](MCL_DMA_MUX_[!"$DmaMuxInstance"!]_[!"node:value(concat("DmaSource",num:i($varLoop)))"!]))[!ENDCODE!]
                        [!ELSE!]
                            [!CODE!][!CR!][!WS,"8"!](0U))[!ENDCODE!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDFOR!]
[!/* */!][!CODE!][!CR!][!WS,"4"!]}[!IF "(num:i($comma))<(num:i($dmaChannelCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};
[!ELSE!][!//
/** @brief Configuration for DmaMux channels */
[!IF "$DmaConfigType = 'PC'"!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]+1] =
[!ELSEIF "$DmaConfigType = 'PB'"!][!//
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig_[!"$DmaConfigType"!]_[!"@index"!][MCL_DMAMUX_CONF_CHANNELS_[!"$DmaConfigType"!]+1] =
[!ELSE!]
static CONST( Mcl_DmaMuxChannelConfigType, MCL_CONST) Mcl_DmaMux_ChannelConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_DMA_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]+1] =
[!ENDIF!]
{
      /** @brief Dummy config used for the case when no DMAMUX channel is configured */  
      {
         /** @brief Hardware DMAMUX channel used */
         DMA_MUX_CH_0,
         /** @brief DMAMUX instance used */
         DMA_MUX_0,
         /** @brief DMAMUX_CHCFGn register configuration */
        (0U)
      }
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDMACRO!][!// DMA Mux Channel Config

[!/* *************************** AXBS Config Master ******************************
******************************************************************************/!]
[!MACRO "AxbsConfigMaster","AxbsConfigType"!]

/**
* @brief Number of configured Master port
*/
[!VAR "MastercrossbarPortCount" = "num:i(count(MclCrossbarLogicalMasterPorts/*))"!]

[!IF "$EnableInitAXBS_MGPCR = 1"!]
[!IF "$AxbsConfigType = 'PC'"!]
#define MCL_CROSSBAR_MASTER_PORTS_[!"$AxbsConfigType"!]  [!"$MastercrossbarPortCount"!]
static CONST( Mcl_CrossbarMasterHwIpsConfigType, MCL_CONST)Mcl_Crossbar_MasterPortConfig_[!"$AxbsConfigType"!][MCL_CROSSBAR_MASTER_PORTS_[!"$AxbsConfigType"!]] =
[!ELSEIF "$AxbsConfigType = 'PB'"!]
#define MCL_CROSSBAR_MASTER_PORTS_[!"@index"!]  [!"$MastercrossbarPortCount"!]
static CONST( Mcl_CrossbarMasterHwIpsConfigType, MCL_CONST)Mcl_Crossbar_MasterPortConfig_[!"@index"!][MCL_CROSSBAR_MASTER_PORTS_[!"@index"!]] =
[!ELSE!]
#define MCL_CROSSBAR_MASTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]  [!"$MastercrossbarPortCount"!]
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_12 MISRA 2004 Rule 1.4 */
static CONST( Mcl_CrossbarMasterHwIpsConfigType, MCL_CONST)Mcl_Crossbar_MasterPortConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_CROSSBAR_MASTER_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
[!ENDIF!]
{
    [!VAR "comma" = "1"!][!//
    [!LOOP "MclCrossbarLogicalMasterPorts/*"!][!//
        [!VAR "MclMasterCrossbarHwPortNumber"="node:value(node:ref(MclCrossbarHwMasterPortRef)/MclMasterPortNumber)"!][!//
        [!VAR "MclCrossbarInstanceNumber" = "substring-after(node:value((node:ref(MclCrossbarHwMasterPortRef))/../../MclCrossbarHwInstance),"AXBS_")"!][!//
        [!VAR "MclCrossbarArbitrates" = "node:value((node:ref(MclCrossbarHwMasterPortRef))/MclCrossbarArbitrates)"!][!//
        {
            [!"$MclMasterCrossbarHwPortNumber"!]U,
            [!"$MclCrossbarInstanceNumber"!]U,
            ((uint32)([!"num:i($MclCrossbarArbitrates)"!]UL) >> AXBS_AULB_SHIFT_U32)
        }[!IF "(num:i($comma))<(num:i($MastercrossbarPortCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!//
    [!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDMACRO!][!// AXBS Config Master

[!/* *************************** AXBS Config Slave ******************************
******************************************************************************/!]
[!MACRO "AxbsConfigSlave","AxbsConfigType"!]
[!NOCODE!]/*********************** Configuration for the crossbar switch ******************/[!ENDNOCODE!][!//
/**
* @brief Number of configured crossbar channels
*/
[!VAR "crossbarPortCount" = "num:i(count(MclCrossbarLogicalSlavePorts/*))"!]

[!IF "$AxbsConfigType = 'PC'"!]
#define MCL_CROSSBAR_CONF_PORTS_PC  [!"$crossbarPortCount"!]
/** @brief Configuration for the crossbar ports */
static CONST( Mcl_CrossbarSlaveHwIpsConfigType, MCL_CONST)Mcl_Crossbar_SlavePortConfig_PC[MCL_CROSSBAR_CONF_PORTS_PC] =
[!ELSEIF "$AxbsConfigType = 'PB'"!]
#define MCL_CROSSBAR_CONF_PORTS_[!"@index"!]  [!"$crossbarPortCount"!]
/** @brief Configuration for the crossbar ports */
static CONST( Mcl_CrossbarSlaveHwIpsConfigType, MCL_CONST)Mcl_Crossbar_SlavePortConfig_[!"@index"!][MCL_CROSSBAR_CONF_PORTS_[!"@index"!]] =
[!ELSE!]
/** @violates @ref Mcl_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_REF_12 MISRA 2004 Rule 1.4 */
static CONST( Mcl_CrossbarSlaveHwIpsConfigType, MCL_CONST)Mcl_Crossbar_SlavePortConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCL_CROSSBAR_CONF_PORTS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
[!ENDIF!]
{
[!VAR "comma" = "1"!][!//
[!FOR "varCounter" = "0" TO "$crossbarPortCount"!][!//
[!LOOP "MclCrossbarLogicalSlavePorts/*"!][!//
    [!IF "MclCrossbarLogicalSlavePortId = $varCounter"!][!//
        [!VAR "MclCrossbarHwPortNumber" = "node:value(node:ref(MclCrossbarHwSlavePortRef)/MclSlavePortNumber)"!][!//
        [!VAR "MclCrossbarInstanceNumber" = "substring-after(node:value((node:ref(MclCrossbarHwSlavePortRef))/../../MclCrossbarHwInstance),"AXBS_")"!][!//
        [!VAR "MclParkingCtrl" = "'AXBS_PCTL_PARK_FIELD'"!][!//
        [!IF "$MclCrossbarInstanceNumber = 0"!][!VAR "NumberOfMaster" = "count(ecu:list('Mcl.Crossbar.AXBS0.Masters'))"!][!//
        [!ELSE!][!VAR "NumberOfMaster" = "count(ecu:list('Mcl.Crossbar.AXBS1.Masters'))"!][!ENDIF!][!//
        [!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarParkingControl = 'LastMaster'"!][!VAR "MclParkingCtrl" = "'AXBS_PCTL_LAST_MASTER'"!][!ENDIF!][!//
        [!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarParkingControl = 'LowPowerPark'"!][!VAR "MclParkingCtrl" = "'AXBS_PCTL_LOW_POWER_PARK'"!][!ENDIF!][!//
        
        /** Logical port [!"$varCounter"!] */
        {
                 /**  Hardware port slave number */
                [!"$MclCrossbarHwPortNumber"!]U,
                 /**  Hardware crossbar instance */
                [!"$MclCrossbarInstanceNumber"!]U,
[!IF "$PRSIsReadOnly = 0"!] 
                 /**  Priority register configuration */  
                (
[!IF "$MclCrossbarInstanceNumber = 0"!][!// /**For AXBS0**/
                        (AXBS_MASTER0_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster0"!]_U32 ))
    [!IF "$NumberOfMaster >= 2"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master1')"!]
                        |(AXBS_MASTER1_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster1"!]_U32 << AXBS_MASTER1_SHIFT_U32))
        [!ENDIF!]    
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 3"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master2')"!]
                        |(AXBS_MASTER2_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster2"!]_U32 << AXBS_MASTER2_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 4"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master3')"!]
                        |(AXBS_MASTER3_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster3"!]_U32 << AXBS_MASTER3_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 5"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master4')"!]
                        |(AXBS_MASTER4_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster4"!]_U32 << AXBS_MASTER4_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 6"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master5')"!]
                        |(AXBS_MASTER5_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster5"!]_U32 << AXBS_MASTER5_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 7"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master6')"!]
                        |(AXBS_MASTER6_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster6"!]_U32 << AXBS_MASTER6_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster = 8"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master7')"!]
                        |(AXBS_MASTER7_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster7"!]_U32 << AXBS_MASTER7_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
[!ELSE!][!//   /**For AXBS1**/
                        (AXBS_MASTER0_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster0"!]_U32 ))
    [!IF "$NumberOfMaster >= 2"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master1')"!]
                        |(AXBS_MASTER1_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster1"!]_U32 << AXBS_MASTER1_SHIFT_U32))
        [!ENDIF!]    
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 3"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master2')"!]
                        |(AXBS_MASTER2_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster2"!]_U32 << AXBS_MASTER2_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 4"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master3')"!]
                        |(AXBS_MASTER3_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster3"!]_U32 << AXBS_MASTER3_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 5"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master4')"!]
                        |(AXBS_MASTER4_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster4"!]_U32 << AXBS_MASTER4_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 6"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master5')"!]
                        |(AXBS_MASTER5_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster5"!]_U32 << AXBS_MASTER5_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 7"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master6')"!]
                        |(AXBS_MASTER6_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster6"!]_U32 << AXBS_MASTER6_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster = 8"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master7')"!]
                        |(AXBS_MASTER7_MASK32 & ((uint32)AXBS_PRIORITY_[!"node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarPrioMaster7"!]_U32 << AXBS_MASTER7_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!][!//
                ),
[!ENDIF!][!//
                /** Control register configuration */
                (
                (AXBS_LK_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnableLock"!]AXBS_LOCK_EN_U32[!ELSE!]AXBS_LOCK_DIS_U32[!ENDIF!]) << AXBS_LOCK_SHIFT_U32))
                |(AXBS_HLP_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarHaltLowPrio"!]AXBS_HLP_LOWEST_U32[!ELSE!]AXBS_HLP_HIGHEST_U32[!ENDIF!]) << AXBS_HLP_SHIFT_U32)) 
[!IF "$MclCrossbarInstanceNumber = 0"!][!// /**For AXBS0**/
                |(AXBS_HPE0_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM0"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE0_SHIFT_U32))
    [!IF "$NumberOfMaster >= 2"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master1')"!]
                |(AXBS_HPE1_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM1"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE1_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 3"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master2')"!]
                |(AXBS_HPE2_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM2"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE2_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 4"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master3')"!]
                |(AXBS_HPE3_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM3"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE3_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 5"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master4')"!]
                |(AXBS_HPE4_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM4"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE4_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 6"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master5')"!]
                |(AXBS_HPE5_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM5"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE5_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 7"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master6')"!]
                |(AXBS_HPE6_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM6"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE6_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster = 8"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS0.Masters'),'Master7')"!]
                |(AXBS_HPE7_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM7"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE7_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
[!ELSE!][!/* /**For AXBS1**/
            */!]|(AXBS_HPE0_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM0"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE0_SHIFT_U32))
    [!IF "$NumberOfMaster >= 2"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master1')"!]
                |(AXBS_HPE1_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM1"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE1_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 3"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master2')"!]
                |(AXBS_HPE2_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM2"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE2_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 4"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master3')"!]
                |(AXBS_HPE3_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM3"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE3_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 5"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master4')"!]
                |(AXBS_HPE4_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM4"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE4_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 6"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master5')"!]
                |(AXBS_HPE5_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM5"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE5_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster >= 7"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master6')"!]
                |(AXBS_HPE6_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM6"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE6_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
    [!IF "$NumberOfMaster = 8"!]
        [!IF "node:containsValue(ecu:list('Mcl.Crossbar.AXBS1.Masters'),'Master7')"!]
                |(AXBS_HPE7_BIT_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnablePrioElevM7"!]AXBS_HPE_EN_U32[!ELSE!]AXBS_HPE_DIS_U32[!ENDIF!]) << AXBS_HPE7_SHIFT_U32))
        [!ENDIF!]
    [!ENDIF!]
[!ENDIF!][!//
                |(AXBS_ARB_BITS_MASK32 & ((uint32)([!IF "node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarEnableFixedPrio"!]AXBS_ARB_FIXED_U32[!ELSE!]AXBS_ARB_ROUND_ROBIN_U32[!ENDIF!]) << AXBS_ARB_SHIFT_U32))   
                |(AXBS_PCTL_BITS_MASK32 & ((uint32)([!"$MclParkingCtrl"!]_U32) << AXBS_PCTL_SHIFT_U32))
                /** @violates @ref Mcl_PB_PC_Cfg_c_REF_11 Boolean operation whose results are invariant shall not be permitted */
                |(AXBS_PARK_BITS_MASK32 & ((uint32)(AXBS_MASTER_[!"substring-after(node:ref(MclCrossbarHwSlavePortRef)/MclCrossbarParkField ,'Master')"!]_U32)))        
                /** @violates @ref Mcl_PB_PC_Cfg_c_REF_11 Boolean operation whose results are invariant shall not be permitted */
                ),                

        [!/* */!]}[!IF "(num:i($comma))<(num:i($crossbarPortCount))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]
[!/* */!]};
[!ENDMACRO!][!// AXBS Config Slave

[!/* *************************** TRGMUX Config ******************************
******************************************************************************/!]
[!/* *************************** Mcl export driver configuration ***************************
******************************************************************************/!]
[!MACRO "MclExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(./MclConfigSet/*)"!][!//
[!CODE!][!//
/** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */  
#define MCL_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Mcl_ConfigType, MCL_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Mcl_ConfigType, MCL_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]
[!ENDNOCODE!]
