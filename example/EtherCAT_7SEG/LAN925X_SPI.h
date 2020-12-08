/* 
 * File:   LAN9250_SPI.h
 * Author: kitagami
 *
 * Created on May 8, 2019, 1:38 AM
 */
#include <stdint.h>

#ifndef LAN9250_SPI_H
#define	LAN9250_SPI_H
void LAN925X_SPI_Init(void);
uint8_t SPI_8bit_Read(void);
void SPI_8bit_Write(uint8_t wdata);
void SQI_RESET(void);
uint32_t LAN925X_SPI_READ(uint16_t addr);
uint32_t LAN925X_SPI_WRITE(uint16_t addr,uint32_t data);
#endif	/* LAN9250_SPI_H */

