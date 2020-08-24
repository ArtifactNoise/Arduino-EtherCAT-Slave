#include <SPI.h>


#include "LAN9252.h"
#include "LAN925X_SPI.h"


#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define LED_5 6
#define LED_6 7
#define LED_7 8
#define LED_8 9
#define LED_9 10
#define LED_10 11
#define LED_11 12
#define LED_12 13
#define LED_13 14
#define LED_14 15
#define LED_15 16
#define LED_16 16


void setup() {

  pinMode(10, OUTPUT);

 
 Serial.begin( 115200 ); 
 Serial.println( "===============================================" ); 
 Serial.println( "EtherCAT Testing." ); 
 Serial.println( "===============================================" ); 
 
 digitalWrite(10, HIGH);

    uint32_t rdata;
    uint32_t wdata;
    char  S1[100];
    uint16_t addr=0;
   
   LAN925X_SPI_Init();
 
  // RESET
  //LAN9252_RESET();

    addr = ID_REV;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"ID_REV[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = BYTE_TEST;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"BYTE_TEST[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = FREE_RUN;
    rdata = LAN925X_SPI_READ(addr);
    sprintf(S1,"FREE_RUN[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

        
    addr = Type_Register;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Type_Register[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    addr = Product_ID;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Product_ID[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    addr = Vendor_ID;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Vendor_ID[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);

    addr = Process_Data_RAM;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    sprintf(S1,"Process_Data_RAM[0x%04X]: 0x%08lX \n\r",addr,rdata);
    UART_TX_Stringth(S1);
    
    //addr = RUN_LED_Override;
    //LAN9252_EtherCAT_CSR_WRITE(CSR_SIZE_32bit,addr,1<<4 | 0x0D);
    //addr = 0x1000;
    //rdata = LAN9252_EtherCAT_PRAM_READ(2,addr);
    //sprintf(S1,"READ[0x%04X]: 0x%08lX \n\r",addr,rdata);
    //UART_TX_Stringth(S1);

    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);
    pinMode(LED_4, OUTPUT);
    pinMode(LED_5, OUTPUT);
    pinMode(LED_6, OUTPUT);
    pinMode(LED_7, OUTPUT);
    pinMode(LED_8, OUTPUT);
    pinMode(LED_9, OUTPUT);
    pinMode(LED_10, OUTPUT);
    pinMode(LED_11, OUTPUT);
    pinMode(LED_12, OUTPUT);
    pinMode(LED_13, OUTPUT);
    pinMode(LED_14, OUTPUT);
    pinMode(LED_15, OUTPUT);
    pinMode(LED_16, OUTPUT);
}



    uint32_t rdata;
    uint32_t wdata;
    uint32_t rdata_buff[20];    
    int cnt = 0;
    
void loop() {
    char  S1[100];
    uint16_t addr=0;
    
    addr = Process_Data_RAM;
    rdata = LAN9252_EtherCAT_CSR_READ(CSR_SIZE_32bit,addr);
    rdata_buff[cnt]=rdata;

    digitalWrite(LED_1, (0x0001&(rdata>>0)));
    digitalWrite(LED_2, (0x0001&(rdata>>1)));
    digitalWrite(LED_3, (0x0001&(rdata>>2)));
    digitalWrite(LED_4, (0x0001&(rdata>>3)));
    digitalWrite(LED_5, (0x0001&(rdata>>4)));
    digitalWrite(LED_6, (0x0001&(rdata>>5)));
    digitalWrite(LED_7, (0x0001&(rdata>>6)));
    digitalWrite(LED_8, (0x0001&(rdata>>7)));
    digitalWrite(LED_9, (0x0001&(rdata>>8)));
    digitalWrite(LED_10, (0x0001&(rdata>>9)));
    digitalWrite(LED_11, (0x0001&(rdata>>10)));
    digitalWrite(LED_12, (0x0001&(rdata>>11)));
    digitalWrite(LED_13, (0x0001&(rdata>>12)));
    digitalWrite(LED_14, (0x0001&(rdata>>13)));
    digitalWrite(LED_15, (0x0001&(rdata>>14)));
    digitalWrite(LED_16, (0x0001&(rdata>>15)));
}


void UART_TX_Stringth(char S1[])
{
    Serial.print(S1); 
  
}
