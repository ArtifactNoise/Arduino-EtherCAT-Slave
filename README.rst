=========================================
Arduino-EtherCAT-Slave
=========================================

Be sure to look at the license.

:LAN925X_SPI(.cpp&.h): Low Level(SPI peripheral)  Source
:LAN9252(.cpp&.h):  Source for LAN9252



example


   LAN925X_SPI_Init();      <- It is absolutely necessary.
 
    // RESET
    //LAN9252_RESET();      <- option.

    // Chip ID_REV register read.
    addr = ID_REV;      
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"ID_REV[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    // Chip BYTE_TEST register read.
    addr = BYTE_TEST;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"BYTE_TEST[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    // Chip FREE_RUN register read.
    addr = FREE_RUN;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"FREE_RUN[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    // CSR Type_Register register read.        
    addr = Type_Register;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Type_Register[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    // CSR Product_ID register read.  
    addr = Product_ID;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Product_ID[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    // CSR Vendor_ID register read.  
    addr = Vendor_ID;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Vendor_ID[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    // CSR Process_Data_RAM register read.  
    addr = Process_Data_RAM;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Process_Data_RAM[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);