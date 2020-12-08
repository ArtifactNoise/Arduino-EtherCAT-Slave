
#include "LAN9252.h"
#include "LAN925X_SPI.h"
#include <stdint.h>

//=============================================================================//
// LAN9252 RESET
//=============================================================================//
void LAN9252_RESET(void)
{
    uint32_t rdata;
    uint32_t wdata;
    uint32_t addr;
    
    addr = RESET_CTL;
    LAN925X_SPI_WRITE(addr,ETHERCAT_RST);       
    addr = BYTE_TEST;
    rdata = LAN925X_SPI_READ(addr);
    while(rdata!=0x87654321)
    {
        addr = BYTE_TEST;
        rdata = LAN925X_SPI_READ(addr);
    }
}

//=============================================================================//
// LAN9252 EtherCAT CSR WRITE
//=============================================================================//
void LAN9252_EtherCAT_CSR_WRITE(uint8_t CSR_SIZE,uint16_t CSR_ADDR,uint32_t CSR_DATA)
{

    uint32_t rdata;
    uint32_t wdata;
    uint16_t addr;
    addr = ECAT_CSR_DATA;
    wdata = CSR_DATA;
    LAN925X_SPI_WRITE(addr,wdata);

    addr = ECAT_CSR_CMD;
    wdata = (uint32_t)CSR_BUSY | (uint32_t)0<<30 | (uint32_t)CSR_SIZE<<16 | (uint32_t)CSR_ADDR; //Write
    LAN925X_SPI_WRITE(addr,wdata);
    
    addr = ECAT_CSR_CMD;
    rdata = LAN925X_SPI_READ(addr);
    while(CSR_BUSY&rdata)
    {
        addr = ECAT_CSR_CMD;
        rdata = LAN925X_SPI_READ(addr);
    }

}
//=============================================================================//
// LAN9252 EtherCAT CSR READ
//=============================================================================//
uint32_t LAN9252_EtherCAT_CSR_READ(uint8_t CSR_SIZE,uint16_t CSR_ADDR)
{

    uint32_t rdata;
    uint32_t wdata;
    uint16_t addr;
    addr = ECAT_CSR_CMD;
    wdata = (uint32_t)CSR_BUSY | (uint32_t)1<<30 | (uint32_t)CSR_SIZE<<16 | (uint32_t)CSR_ADDR; //Read
    LAN925X_SPI_WRITE(addr,wdata);
    
    addr = ECAT_CSR_CMD;
    rdata = LAN925X_SPI_READ(addr);
    while(CSR_BUSY&rdata)
    {
        addr = ECAT_CSR_CMD;
        rdata = LAN925X_SPI_READ(addr);
    }
    addr = ECAT_CSR_DATA;
    rdata = LAN925X_SPI_READ(addr);
    return rdata;
}
//=============================================================================//
// LAN9252 EtherCAT Prossec RAM Read
//=============================================================================//
uint32_t LAN9252_EtherCAT_PRAM_READ(uint16_t PRAM_READ_LEN,uint16_t PRAM_READ_ADDR)
{
    uint32_t rdata;
    uint32_t wdata;
    uint32_t tmp;
    uint16_t addr;
    
    addr = ECAT_PRAM_RD_ADDR_LEN;
    wdata = (uint32_t)PRAM_READ_LEN<<16 | (uint32_t)PRAM_READ_ADDR; 
    LAN925X_SPI_WRITE(addr,wdata);

    addr = ECAT_PRAM_RD_CMD;
    wdata = PRAM_READ_BUSY ; 
    LAN925X_SPI_WRITE(addr,wdata);

    addr = ECAT_PRAM_RD_DATA;
    rdata = LAN925X_SPI_READ(addr);

    addr = ECAT_PRAM_RD_CMD;
    tmp = LAN925X_SPI_READ(addr);
    while(PRAM_READ_BUSY&tmp)
    {
        addr = ECAT_PRAM_RD_CMD;
        tmp = LAN925X_SPI_READ(addr);
    }
    return rdata;
}
//=============================================================================//
// LAN9252 EtherCAT Prossec RAM Read
//=============================================================================//
void LAN9252_EtherCAT_PRAM_WRITE(uint16_t PRAM_WRITE_LEN,uint16_t PRAM_WRITE_ADDR, uint32_t PRAM_WR_DATA)
{
    uint32_t rdata;
    uint32_t wdata;
    uint32_t tmp;
    uint16_t addr;

    
    addr = ECAT_PRAM_WR_DATA;
    wdata = PRAM_WR_DATA; 
    LAN925X_SPI_WRITE(addr,wdata);
    
    addr = ECAT_PRAM_WR_ADDR_LEN;
    wdata = (uint32_t)PRAM_WRITE_LEN<<16 | (uint32_t)PRAM_WRITE_ADDR; 
    LAN925X_SPI_WRITE(addr,wdata);

    addr = ECAT_PRAM_WR_CMD;
    wdata = PRAM_WRITE_BUSY ; 
    LAN925X_SPI_WRITE(addr,wdata);

    addr = ECAT_PRAM_WR_CMD;
    tmp = LAN925X_SPI_READ(addr);
    while(PRAM_WRITE_BUSY&tmp)
    {
        addr = ECAT_PRAM_WR_CMD;
        tmp = LAN925X_SPI_READ(addr);
    }
}
