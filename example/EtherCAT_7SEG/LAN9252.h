/* 
 * File:   LAN9252.h
 * Author: kitagami
 *
 * Created on January 29, 2020, 9:11 PM
 */

#ifndef LAN9252_H
#define	LAN9252_H

#include <SPI.h>
#include <stdint.h>

#define ECAT_PRAM_RD_DATA       0x000
#define ECAT_PRAM_WR_DATA       0x020
#define ID_REV                  0x050
#define IRQ_CFG                 0x054
#define INT_STS                 0x058
#define INT_EN                  0x05C
#define BYTE_TEST               0x064
#define HW_CFG                  0x074
#define PMT_CTRL                0x084
#define GPT_CFG                 0x08C
#define GPT_CNT                 0x090
#define FREE_RUN                0x09C
#define RESET_CTL               0x1F8

#define ETHERCAT_RST            0x40
#define PHY_B_RST               0x04
#define PHY_A_RST               0x02
#define DIGITAL_RST             0x01

#define ECAT_CSR_DATA           0x300
#define ECAT_CSR_CMD            0x304
#define CSR_BUSY                1<<31
#define CSR_SIZE_8bit           1
#define CSR_SIZE_16bit          2
#define CSR_SIZE_32bit          4
#define ECAT_PRAM_RD_ADDR_LEN   0x308
#define ECAT_PRAM_RD_CMD        0x30C
#define ECAT_PRAM_WR_ADDR_LEN   0x310
#define ECAT_PRAM_WR_CMD        0x314

#define PRAM_READ_BUSY  1<<31
#define PRAM_READ_ABORT 1<<30
#define PRAM_WRITE_BUSY  1<<31
#define PRAM_WRITE_ABORT 1<<30
    
//-----------------------------------------------------------------------//
// ESC Information
//-----------------------------------------------------------------------//
#define Type_Register                            0x0000
#define Revision_Register                        0x0001
#define Build_Register                           0x0002
#define FMMUs_Supported                          0x0004
#define SyncManagers_Supported                   0x0005
#define RAM_Size                                 0x0006
#define Port_Descriptor                          0x0007
#define ESC_Features_Supported                   0x0008
//-----------------------------------------------------------------------//
// Station Address
//-----------------------------------------------------------------------//
#define Configured_Station                       0x0010
#define Configured_Station_Alias                 0x0012
//-----------------------------------------------------------------------//
// Write Protection
//-----------------------------------------------------------------------//
#define Write_Enable                             0x0020
#define Write_Protection                         0x0021
#define ESC_Write_Enable                         0x0030
#define ESC_Write_Protection                     0x0031
//-----------------------------------------------------------------------//
// Data Link Layer
//-----------------------------------------------------------------------//
#define ESC_Reset_ECAT                           0x0040
#define ESC_Reset_PDI                            0x0041
#define ESC_DL_Control                           0x0100
#define Physical_Read_Write_Offset               0x0108
#define ESC_DL_Status                            0x0110
//-----------------------------------------------------------------------//
// Application Layer
//-----------------------------------------------------------------------//
#define AL_Control                               0x0120
#define AL_Status                                0x0130
#define AL_Status_Code                           0x0134
#define RUN_LED_Override                         0x0138
//-----------------------------------------------------------------------//
// PDI (Process Data Interface)
//-----------------------------------------------------------------------//
#define PDI_Control                              0x0140
#define ESC_Configuration                        0x0141
#define ASIC_Configuration                       0x0142
#define PDI_Configuration                        0x0150
#define Sync_Latch_PDI_Configuration             0x0151
#define Extended_PDI_Configuration               0x0152
//-----------------------------------------------------------------------//
//Interrupts
//-----------------------------------------------------------------------//
#define ECAT_Event_Mask                          0x0200
#define AL_Event_Mask                            0x0204
#define ECAT_Event_Request                       0x0210
#define AL_Event_Request                         0x0220
//-----------------------------------------------------------------------//
// Error Counters
//-----------------------------------------------------------------------//
#define RX_Error_Counters                        0x0300
#define Forwarded_RX_Error_Counters              0x0308
#define ECAT_Processing_Unit_Error_Counter       0x030C
#define PDI_Error_Counter                        0x030D
#define PDI_Error_Code                           0x030E
#define Lost_Link_Counters                       0x0310
//-----------------------------------------------------------------------//
// Watchdogs
//-----------------------------------------------------------------------//
#define Watchdog_Time_PDI                        0x0410
#define Watchdog_Time_Process_Data               0x0420
#define Watchdog_Status_Process_Data             0x0440
#define Watchdog_Counter_Process_Data            0x0442
#define Watchdog_Counter_PDI                     0x0443
//-----------------------------------------------------------------------//
// EEPROM Interface
//-----------------------------------------------------------------------//
#define EEPROM_Configuration                     0x0500
#define EEPROM_PDI_Access_State                  0x0501
#define EEPROM_Control_Status                    0x0502
#define EEPROM_Address                           0x0504
#define EEPROM_Data                              0x0508
//-----------------------------------------------------------------------//
// MII Management Interface
//-----------------------------------------------------------------------//
#define MII_Management_Control_Status            0x0510
#define PHY_Address                              0x0512
#define PHY_Register_Address                     0x0513
#define PHY_DATA                                 0x0514
#define MII_Management_ECAT_Access_State         0x0516
#define MII_Management_PDI_Access_State          0x0517
#define PHY_Port_Statuss                         0x0518
/*=========================================================
0600h FMMU[2:0]s (3x16 bytes)
+0h-3h FMMUx Logical Start Address
+4h-5h FMMUx Length
+6h FMMUx Logical Start Bit
+7h FMMUx Logical Stop Bit
+8h-9h FMMUx Physical Start Address
+Ah FMMUx Physical Start Bit
+Bh FMMUx Type
+Ch FMMUx Activate
+Dh-Fh FMMUx Reserved
0800h-081Fh SyncManager[3:0]s (4x8 bytes)
+0h-1h SyncManager x Physical Start Address
+2h-3h SyncManager x Length
+4h SyncManager x Control
+5h SyncManager x Status
+6h SyncManager x Activate
+7h SyncManager x PDI Control
===========================================================*/
//-----------------------------------------------------------------------//
// Distributed Clocks - Receive Times
//-----------------------------------------------------------------------//
#define Receive_Time_Port_0                       0x0900
#define Receive_Time_Port_1                       0x0904
#define Receive_Time_Port_2                       0x0908
//-----------------------------------------------------------------------//
//Distributed Clocks - Time Loop Control Unit
//-----------------------------------------------------------------------//
#define System_Time                               0x0910
#define Receive_Time_ECAT_Processing_Unit         0x0918
#define System_Time_Offset                        0x0920
#define System_Time_Delay                         0x0928
#define System_Time_Difference                    0x092C
#define Speed_Counter_Start                       0x0930
#define Speed_Counter_Diff                        0x0932
#define System_Time_Difference_Filter_Depth       0x0934
#define Speed_Counter_Filter_Depth                0x0935
//-----------------------------------------------------------------------//
// Distributed Clocks - Cyclic Unit Control
//-----------------------------------------------------------------------//
#define Cyclic Unit Control                       0x0980
//-----------------------------------------------------------------------//
// Distributed Clocks - SYNC Out Unit
//-----------------------------------------------------------------------//
#define Activation                                0x0981
#define Pulse_Length_of_SyncSignals               0x0982
#define Activation_Status                         0x0984
#define SYNC0_Status                              0x098E
#define SYNC1_Status                              0x098F
#define Start_Time_Cyclic_Operation               0x0990
#define Next_SYNC1_Pulse                          0x0998
#define SYNC0_Cycle_Time                          0x09A0
#define SYNC1_Cycle_Time                          0x09A4
//-----------------------------------------------------------------------//
// Distributed Clocks - Latch In Unit
//-----------------------------------------------------------------------//
#define LATCH0_Control                            0x09A8
#define LATCH1_Control                            0x09A9
#define LATCH0_Status                             0x09AE
#define LATCH1_Status                             0x09AF
#define LATCH0_Time_Positive_Edge                 0x09B0
#define LATCH0_Time_Negative_Edge                 0x09B8
#define LATCH1_Time_Positive_Edge                 0x09C0
#define LATCH1_Time_Negative_Edge                 0x09C8
//-----------------------------------------------------------------------//
// Distributed Clocks - SyncManager Event Times
//-----------------------------------------------------------------------//
#define EtherCAT_Buffer_Change_Event_Time         0x09F0
#define PDI_Buffer_Start_Time_Event               0x09F8
#define PDI_Buffer_Change_Event_Time              0x09FC
//-----------------------------------------------------------------------//
// ESC Specific
//-----------------------------------------------------------------------//
#define Product_ID                                0x0E00
#define Vendor_ID                                 0x0E08
//-----------------------------------------------------------------------//
// Digital Input/Output
//-----------------------------------------------------------------------//
#define Digital_IO_Output_Data                    0x0F00
#define General_Purpose_Output                    0x0F10
#define General_Purpose_Input                     0x0F18
//-----------------------------------------------------------------------//
// User RAM
//-----------------------------------------------------------------------//
#define User_RAM                                  0x0F80
//-----------------------------------------------------------------------//
// Process Data RAM
//-----------------------------------------------------------------------//
#define Process_Data_RAM                          0x1000    

void LAN9252_RESET(void);
void LAN9252_EtherCAT_CSR_WRITE(uint8_t CSR_SIZE,uint16_t CSR_ADDR,uint32_t CSR_DATA);
uint32_t LAN9252_EtherCAT_CSR_READ(uint8_t CSR_SIZE,uint16_t CSR_ADDR);
uint32_t LAN9252_EtherCAT_PRAM_READ(uint16_t PRAM_READ_LEN,uint16_t PRAM_READ_ADDR);
void LAN9252_EtherCAT_PRAM_WRITE(uint16_t PRAM_WRITE_LEN,uint16_t PRAM_WRITE_ADDR, uint32_t PRAM_WR_DATA);



#endif	/* LAN9252_H */

