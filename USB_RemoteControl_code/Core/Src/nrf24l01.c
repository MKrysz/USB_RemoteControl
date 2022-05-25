#include "nrf24l01.h"
#include "spi.h"

void _RF_ReadRegister(uint8_t registerDDR, uint8_t *data, uint16_t len);
void _RF_WriteRegister(uint8_t registerDDR, uint8_t *data, uint16_t len);

#define RF_INSTR_READ_REGISTER 0x00
#define RF_INSTR_WRITE_REGISTER 0x20
#define RF_INSTR_READ_RX_PAYLOAD 0x51
#define RF_INSTR_WRITE_TX_PAYLOAD 0xA0
#define RF_INSTR_FLUSH_TX 0xE1
#define RF_INSTR_FLUSH_RX 0xE2
#define RF_INSTR_REUSE_TX_PL 0xE3
#define RF_INSTR_NOP 0xFF

#define RF_REG_DDR_CONFIG 0x00
//Enchanced Schock Burst
#define RF_REG_DDR_EN_AA 0x01
#define RF_REG_DDR_EN_RXADDR 0x02
#define RF_REG_DDR_SETUP_AW 0x03
#define RF_REG_DDR_SETUP_RETR 0x04
#define RF_REG_DDR_RF_CH 0x05
#define RF_REG_DDR_RF_SETUP 0x06
#define RF_REG_DDR_STATUS 0x07
#define RF_REG_DDR_OBSERVE_TX 0x08
#define RF_REG_DDR_CD 0x09
#define RF_REG_DDR_RX_ADDR_P0 0x0A
#define RF_REG_DDR_RX_ADDR_P1 0x0B
#define RF_REG_DDR_RX_ADDR_P2 0x0C
#define RF_REG_DDR_RX_ADDR_P3 0x0D
#define RF_REG_DDR_RX_ADDR_P4 0x0E
#define RF_REG_DDR_RX_ADDR_P5 0x0F
#define RF_REG_DDR_TX_ADDR 0x10
#define RF_REG_DDR_RX_PW_P0 0x11
#define RF_REG_DDR_RX_PW_P1 0x12
#define RF_REG_DDR_RX_PW_P2 0x13
#define RF_REG_DDR_RX_PW_P3 0x14
#define RF_REG_DDR_RX_PW_P4 0x15
#define RF_REG_DDR_RX_PW_P5 0x16
#define RF_REG_DDR_FIFO_STATUS 0X17


void RF_InterruptHandler(uint16_t pin)
{
    
}

void RF_Init()
{
    //wait a little since power up
    while(HAL_GetTick() < 500);
    
}


void _RF_ReadRegister(uint8_t registerDDR, uint8_t *data, uint16_t len)
{
    uint8_t SPI_Cmd = registerDDR | RF_INSTR_READ_REGISTER;
    HAL_SPI_Transmit(&RF_HSPI, &SPI_Cmd, 1, HAL_MAX_DELAY);
    HAL_Delay(1);
    for (size_t i = 0; i < len; i++)
    {
        SPI_Cmd = RF_INSTR_NOP;
        HAL_SPI_TransmitReceive(&RF_HSPI, &SPI_Cmd, &data + i, 1, HAL_MAX_DELAY);
        HAL_Delay(1);
    }
    
}

void _RF_WriteRegister(uint8_t registerDDR, uint8_t *data, uint16_t len)
{
    uint8_t SPI_Cmd = registerDDR | RF_INSTR_WRITE_REGISTER;
    HAL_SPI_Transmit(&RF_HSPI, &SPI_Cmd, 1, HAL_MAX_DELAY);
    HAL_Delay(1);
    HAL_SPI_Transmit(&RF_HSPI, data, len, HAL_MAX_DELAY)

}
