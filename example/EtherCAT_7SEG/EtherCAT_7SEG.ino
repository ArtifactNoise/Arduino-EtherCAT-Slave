 #include <SPI.h>

#include "LAN9252.h"
#include "LAN925X_SPI.h"

#define seg7_A  2
#define seg7_B  3
#define seg7_C  4
#define seg7_D  5
#define seg7_E  6
#define seg7_F  7
#define seg7_HM 8
#define seg7_KP  9
#define seg7_DP  14

#define seg7_TR1  15
#define seg7_TR2  16
#define seg7_TR3  17
#define seg7_TR4  18
#define seg7_TR5  19

void setup() {
  Serial.begin( 115200 ); 
  Serial.println( "===============================================" ); 
  Serial.println( "EtherCAT Testing." ); 
  Serial.println( "===============================================" ); 
  pinMode(seg7_A, OUTPUT);
  pinMode(seg7_B, OUTPUT);
  pinMode(seg7_C, OUTPUT);
  pinMode(seg7_D, OUTPUT);
  pinMode(seg7_E, OUTPUT);
  pinMode(seg7_F, OUTPUT);
  pinMode(seg7_HM, OUTPUT);
  pinMode(seg7_KP, OUTPUT);
  pinMode(seg7_DP, OUTPUT);
  pinMode(seg7_TR1, OUTPUT);
  pinMode(seg7_TR2, OUTPUT);
  pinMode(seg7_TR3, OUTPUT);
  pinMode(seg7_TR4, OUTPUT);
  pinMode(seg7_TR5, OUTPUT);


  
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

    delay(2000);
    
    //addr = RUN_LED_Override;
    //LAN9252_EtherCAT_CSR_WRITE(CSR_SIZE_32bit,addr,1<<4 | 0x0D);
    //addr = 0x1000;
    //rdata = LAN9252_EtherCAT_PRAM_READ(2,addr);
    //sprintf(S1,"READ[0x%04X]: 0x%08lX \n\r",addr,rdata);
    //UART_TX_Stringth(S1);
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
    sprintf(S1,"%05lu",rdata);
    SEG7_DATA(S1);
    //sprintf(S1,"%05lu",12345);
}


void UART_TX_Stringth(char S1[])
{
    Serial.print(S1); 
  
}
void SEG7_DATA(char num[])
{
 int TIME=0;
//-----------------------------------------//
    digitalWrite(seg7_TR1, LOW );
    digitalWrite(seg7_TR2, HIGH);
    digitalWrite(seg7_TR3, HIGH);
    digitalWrite(seg7_TR4, HIGH);
    digitalWrite(seg7_TR5, HIGH);
    
    SEG7_NUM(num[0]);
     delay(TIME);
     SEG7_CLEAR();
     delay(TIME);
 //-----------------------------------------//
    digitalWrite(seg7_TR1, HIGH);
    digitalWrite(seg7_TR2, LOW);
    digitalWrite(seg7_TR3, HIGH);
    digitalWrite(seg7_TR4, HIGH);
    digitalWrite(seg7_TR5, HIGH);
    
    SEG7_NUM(num[1]);
     delay(TIME);
     SEG7_CLEAR();
     delay(TIME);
 //-----------------------------------------//
    digitalWrite(seg7_TR1, HIGH);
    digitalWrite(seg7_TR2, HIGH);
    digitalWrite(seg7_TR3, LOW);
    digitalWrite(seg7_TR4, HIGH);
    digitalWrite(seg7_TR5, HIGH);
    
    SEG7_NUM(num[2]);
     delay(TIME);
     SEG7_CLEAR();
     delay(TIME);
 //-----------------------------------------//
    digitalWrite(seg7_TR1, HIGH);
    digitalWrite(seg7_TR2, HIGH);
    digitalWrite(seg7_TR3, HIGH);
    digitalWrite(seg7_TR4, LOW);
    digitalWrite(seg7_TR5, HIGH);
    
    SEG7_NUM(num[3]);
     delay(TIME);
     SEG7_CLEAR();
     delay(TIME);
 //-----------------------------------------//
    digitalWrite(seg7_TR1, HIGH);
    digitalWrite(seg7_TR2, HIGH);
    digitalWrite(seg7_TR3, HIGH);
    digitalWrite(seg7_TR4, HIGH);
    digitalWrite(seg7_TR5, LOW);
    
    SEG7_NUM(num[4]);
    delay(TIME);
     SEG7_CLEAR();
     delay(TIME);
 //-----------------------------------------//
}
void SEG7_CLEAR()
{
    digitalWrite(seg7_A, HIGH);
    digitalWrite(seg7_B, HIGH );
    digitalWrite(seg7_C, HIGH );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, HIGH);
    digitalWrite(seg7_DP, HIGH);
}
void SEG7_NUM(char num)
{
  if(num == '0')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, LOW);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, HIGH);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '1')
  {
    digitalWrite(seg7_A, HIGH);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, HIGH);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '2')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, HIGH );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, LOW);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '3')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '4')
  {
    digitalWrite(seg7_A, HIGH);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '5')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, HIGH );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '6')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, HIGH );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, LOW);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '7')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, HIGH);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '8')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, LOW);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '9')
  {
    digitalWrite(seg7_A, LOW);
    digitalWrite(seg7_B, LOW );
    digitalWrite(seg7_C, LOW );
    digitalWrite(seg7_D, LOW);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, LOW);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
    if(num == '-')
  {
    digitalWrite(seg7_A, HIGH);
    digitalWrite(seg7_B, HIGH );
    digitalWrite(seg7_C, HIGH );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
    if(num == '+')
  {
    digitalWrite(seg7_A, HIGH);
    digitalWrite(seg7_B, HIGH );
    digitalWrite(seg7_C, HIGH );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, LOW);
    digitalWrite(seg7_KP, LOW);
    digitalWrite(seg7_DP, HIGH);
  }
  if(num == '.')
  {
    digitalWrite(seg7_A, HIGH);
    digitalWrite(seg7_B, HIGH );
    digitalWrite(seg7_C, HIGH );
    digitalWrite(seg7_D, HIGH);
    digitalWrite(seg7_E, HIGH);
    digitalWrite(seg7_F, HIGH);
    digitalWrite(seg7_HM, HIGH);
    digitalWrite(seg7_KP, HIGH);
    digitalWrite(seg7_DP, LOW);
  }
}
