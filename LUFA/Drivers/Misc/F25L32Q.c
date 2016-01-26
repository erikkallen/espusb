#include "F25L32Q.h"

void mem_read(uint32_t addr, uint8_t * buf, uint8_t sz) {
    SELECT_CHIP

    SPI_SendByte(MEM_READ);
    SPI_SendByte((addr >> 16) & 0xff);
    SPI_SendByte((addr >> 8) & 0xff);
    SPI_SendByte(addr & 0xff);

    for (size_t i = 0; i < sz; i++) {
        *(buf + i) = SPI_ReceiveByte();
    }

    DESELECT_CHIP
}

void mem_write(uint32_t addr, uint8_t * buf, uint8_t sz) {
    mem_write_enable();
    SELECT_CHIP

    SPI_SendByte(MEM_WRITE);
    SPI_SendByte((addr >> 16) & 0xff);
    SPI_SendByte((addr >> 8) & 0xff);
    SPI_SendByte(addr & 0xff);

    for (size_t i = 0; i < sz; i++) {
        SPI_SendByte(*(buf+i));
    }

    DESELECT_CHIP
}

uint16_t mem_read_id() {
    SELECT_CHIP

    SPI_SendByte(MEM_READ_ID);
    SPI_SendByte(0x0);
    SPI_SendByte(0x0);
    SPI_SendByte(0x0);
    uint8_t Byte1 = SPI_ReceiveByte();
    uint8_t Byte2 = SPI_ReceiveByte();

    // Assert CS
    DESELECT_CHIP

    return Byte1 | (Byte2 >> 8);
}

void mem_erase_sector_4k(uint32_t address) {

}

void mem_erase_sector_64k(uint32_t address){

}

void mem_erase_chip(){

}

void mem_write_enable() {
    SELECT_CHIP
    SPI_SendByte(MEM_WRITE_ENABLE);
    // Assert CS
    DESELECT_CHIP
}
