/*==================================================================================================

   @file        autosar_flash.ld
   @version     1.0.0

   @brief       GHS Linker Command File for Internal FLASH for Calypso 3M.
   @details     GHS Linker Command File for Internal FLASH for Calypso 3M.
                This file contains sample code only. It is not part of the production code deliverables
====================================================================================================    
   Project      : AUTOSAR 4.2 MCAL
   Platform     : PA
   Peripheral   : 
   Dependencies : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM
   
   Autosar Version       : 4.2.2
   Autosar Revision      : ASR_REL_4_2_REV_0002
   Autosar Conf. Variant : 
   Software Version      : 1.0.0
   Build Version         : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20171702

   (c) Copyright 2006-2017 NXP Inc
   All Rights Reserved.

    This file contains sample code only. It is not part of the production code deliverables.
	  
====================================================================================================

Note: This linker command file to be used with MPC574XC/G device only.
==================================================================================================*/


MEMORY {
    /* 5748G - Flash 6.0 MB - 0x00F90000 - 0x0157FFFF */
    /* 5746C - Flash 3.0 MB - 0x00F90000 - 0x0127FFFF */
    
    flash_rsvd1         : ORIGIN = 0x00F90000, LENGTH = 0x70000
    flash_memory        : ORIGIN = ., LENGTH = 0x01270000-.
    flash_vec           : ORIGIN = 0x01270000, LENGTH = 0x10000
    flash_rsvd2         : ORIGIN = .,          LENGTH = 0

    /* 5748G - SRAM 768KB  : 0x40000000 - 0x400BFFFF */
    /* 5746C - SRAM 512KB  : 0x40000000 - 0x4007FFFF */
    ram_rsvd1               : ORIGIN = 0x20000000, LENGTH = 0
    int_sram                : ORIGIN = 0x40000000, LENGTH = 0x60B60
    res_ram                 : ORIGIN = 0x40060B60, LENGTH = 0x60 /* a reserved ram section needed by FLS driver */
    iram_stack              : ORIGIN = 0x40060BC0, LENGTH = 0x1000
    int_timers              : ORIGIN = 0x40061BC0, LENGTH = 0x0340
    int_results             : ORIGIN = 0x40061F00, LENGTH = 0x0100
    int_sram_no_cacheable   : ORIGIN = 0x40062000, LENGTH = 0x1E000
    ram_rsvd2           : ORIGIN = .,          LENGTH = 0

}

//
// Program layout for starting in ROM, copying data to RAM,
// and continuing to execute out of ROM.
//

SECTIONS
{
//
// RAM SECTIONS
//
    .ramcode                            ABS ALIGN(4): > int_sram   /* nedded to placing func in RAM */
    .PPC.EMB.sdata0                     ABS ALIGN(4): > int_sram
    .PPC.EMB.sbss0                CLEAR ABS ALIGN(4): > .
   
    .sdabase                               ALIGN(8) : > .   
    .sdata                                 ALIGN(4) : > .
    .sbss                                  ALIGN(4) : > .
    .data                                  ALIGN(4) : > .
    .mcal_data                                      : > .
    .bss                                   ALIGN(4) : > .
    .mcal_bss                                       : > .    
    // reserve space for .acfls_code_ram
    .acfls_code_ram                        ALIGN(4) : {. += SIZEOF(.acfls_code_rom);} > .
    // make sure the size of the reserved space is 4-bytes aligned     
    .acfls_code_ram_end                    ALIGN(4) : > .
    
    .mcal_bss_no_cacheable                 ALIGN(4) : > int_sram_no_cacheable
    .mcal_data_no_cacheable                ALIGN(4) : > . 
    
                                                  
//
// ROM SECTIONS
//
    .rcw                                            : > flash_rsvd1
    .text                                           : > flash_memory
    .vletext                                        : > .
    .mcal_text                                      : > .
    .syscall                                        : > .
    .rodata                                         : > .
    .sdata2                                         : > .
    .secinfo                                        : > .
    .fixaddr                                        : > .
    .fixtype                                        : > .


    .ROM.ramcode               ROM(.ramcode) ALIGN(0x10) ALIGN(4): > .
    .ROM.PPC.EMB.sdata0        ROM(.PPC.EMB.sdata0) ALIGN(4): > .
    .ROM.sdata                          ROM(.sdata) ALIGN(4): > .
    .ROM.data                            ROM(.data) ALIGN(4): > .
    .ROM.mcal_data                  ROM(.mcal_data) ALIGN(4): > .
    .ROM.mcal_data_no_cacheable  ROM(.mcal_data_no_cacheable ) ALIGN(4): > .
    .mcal_const_cfg                                 : > flash_memory
    .mcal_const                                     : > flash_memory    
    .acfls_code_rom                        ALIGN(4) : > flash_memory
    .isrvectbl_core                   ALIGN(0x1000) : > flash_vec
    .isrvectbl                        ALIGN(0x1000) : > .

//
// These special symbols mark the bounds of RAM and ROM memory.
// They are used by the MULTI debugger.
//
    __ghs_ramstart      = MEMADDR(ram_rsvd1);
    __ghs_ramend        = MEMENDADDR(ram_rsvd2);
    __ghs_romstart      = MEMADDR(flash_rsvd1);
    __ghs_romend        = MEMENDADDR(flash_rsvd2);

    __IV_ADDR           = MEMADDR(flash_vec);
    
    INT_SRAM_START      = ADDR(int_sram);
    INT_SRAM_SIZE       = 0x80000/64;                     // Init 64 bytes at a time
    SBSS_SRAM_START     = ADDR(.sbss);
    SBSS_SRAM_SIZE      = (SIZEOF(.sbss)+3)/4;            // Init 4 bytes at a time
    BSS_SRAM_START      = ADDR(.bss);
    BSS_SRAM_SIZE       = (SIZEOF(.bss)+SIZEOF(.mcal_bss)+3)/4;   // Init 4 bytes at a time
    SDATA_RW_START      = _SDA_BASE_;
    SDATA_RO_START      = _SDA2_BASE_;
    
    BSS_NO_CACHEABLE_SRAM_START      = ADDR(.mcal_bss_no_cacheable);
    BSS_NO_CACHEABLE_SRAM_SIZE       = (SIZEOF(.mcal_bss_no_cacheable)+3)/4;

    RC_RAMCODE_SRC =  ADDR(.ROM.ramcode);
    RC_RAMCODE_DEST = ADDR(.ramcode);
    RC_RAMCODE_SIZE = (SIZEOF(.ROM.ramcode)+3) / 4;         // Copy 4 bytes at a time
    
    RC_PPC_SDATA2_SRC   = ADDR(.ROM.PPC.EMB.sdata0);
    RC_PPC_SDATA2_DEST  = ADDR(.PPC.EMB.sdata0);
    RC_PPC_SDATA2_SIZE  = (SIZEOF(.ROM.PPC.EMB.sdata0)+3)/4; // Copy 4 bytes at a time
    RC_SDATA_SRC        = ADDR(.ROM.sdata);
    RC_SDATA_DEST       = ADDR(.sdata);
    RC_SDATA_SIZE       = (SIZEOF(.ROM.sdata)+3)/4;          // Copy 4 bytes at a time
    RC_DATA_SRC         = ADDR(.ROM.data);
    RC_DATA_DEST        = ADDR(.data);
    RC_DATA_SIZE        = (SIZEOF(.ROM.data)+3)/4 + (SIZEOF(.ROM.mcal_data)+3)/4;  //Copy 4 bytes at a time

    /* generate symbols used in start-up code to init .mcal_data_no_cacheable section */
    RC_DATA_NO_CACHEABLE_SRC    = ADDR(.ROM.mcal_data_no_cacheable) ;
    RC_DATA_NO_CACHEABLE_DEST   = ADDR(.mcal_data_no_cacheable);
    RC_DATA_NO_CACHEABLE_SIZE   = (SIZEOF(.ROM.mcal_data_no_cacheable)+3) / 4;
    
    __SP_INIT           = ADDR(iram_stack) + SIZEOF(iram_stack);
    __SP_END            = ADDR(iram_stack);
    __STACK_SIZE        = SIZEOF(iram_stack);
    
    __RAM_NO_CACHEABLE_START      = ADDR(int_sram_no_cacheable);
    __RAM_NO_CACHEABLE_END        = ADDR(int_sram_no_cacheable)+0x1DFFF;
    __RAM_CACHEABLE_START         = ADDR(int_sram);
    __RAM_CACHEABLE_END           = ADDR(int_sram)+0x61FFF;

    /* Fls module access code support */    
    Fls_ACEraseRomStart         = ADDR(.acfls_code_rom);
    Fls_ACEraseRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACEraseSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/

    Fls_ACWriteRomStart         = ADDR(.acfls_code_rom);
    Fls_ACWriteRomEnd           = ADDR(.acfls_code_rom) + SIZEOF(.acfls_code_rom);
    Fls_ACWriteSize             = (SIZEOF(.acfls_code_rom)+3) / 4; /* Copy 4 bytes at a time*/
    
    _ERASE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);
    _WRITE_FUNC_ADDRESS_        = ADDR(.acfls_code_ram);

}

OPTION ("-keep=Fls_Flash_AccessCode")
OPTION ("-keep=ccov_main")
