#include "LAN925X_SPI.h"
#include <SPI.h>
#include <stdint.h>
//********************************************************************//
// HardWare Interface
//********************************************************************//
#define     SPI_CS_LOW()    digitalWrite(10, LOW);
#define     SPI_CS_HIGH()   digitalWrite(10, HIGH);
void LAN925X_SPI_Init(void)
{
   SPI_CS_HIGH();
   SPI.begin();  
   SPI.setClockDivider(SPI_CLOCK_DIV2);
   SPI.setBitOrder(MSBFIRST); 
   SPI.setDataMode(SPI_MODE0);
}
uint8_t SPI_8bit_Read(void)
{
        return SPI.transfer(0);
}
void SPI_8bit_Write(uint8_t wdata)
{
        SPI.transfer(wdata);
}

void SQI_RESET(void)
{
    //SS2_SetDigitalInput();
    //while(SS2_GetValue()!=1);
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_HIGH();
    SPI_CS_LOW();
    SPI_8bit_Write(0xFF);
    SPI_CS_HIGH();
}




uint32_t LAN925X_SPI_READ(uint16_t addr)
{
    uint32_t rdata;
    SPI_CS_LOW();
    SPI_8bit_Write(0x03); //Instruction
    SPI_8bit_Write( 0xFF&(addr>>8) ); //Address
    SPI_8bit_Write( 0xFF&(addr>>0) ); //Address
    rdata =  (uint32_t)SPI_8bit_Read();
    rdata |= (uint32_t)SPI_8bit_Read()<<8;
    rdata |= (uint32_t)SPI_8bit_Read()<<16;
    rdata |= (uint32_t)SPI_8bit_Read()<<24;
    SPI_CS_HIGH();
    return rdata;
}

uint32_t LAN925X_SPI_WRITE(uint16_t addr,uint32_t data)
{
    uint32_t rdata;
    SPI_CS_LOW();
    SPI_8bit_Write(0x02); //Instruction
    SPI_8bit_Write( 0xFF&(addr>>8) ); //Address
    SPI_8bit_Write( 0xFF&(addr>>0) ); //Address
    SPI_8bit_Write( 0xFF&(data>>0) );
    SPI_8bit_Write( 0xFF&(data>>8) );
    SPI_8bit_Write( 0xFF&(data>>16) );
    SPI_8bit_Write( 0xFF&(data>>24) );
    SPI_CS_HIGH();
    return rdata;
}
