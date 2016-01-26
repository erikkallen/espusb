
#ifndef __F25L32Q_CMDS_H__
#define __F25L32Q_CMDS_H__

/* SPIflash Status Values */

#define MEM_STATUS_BUSY                     (1 << 0)
#define MEM_STATUS_WRITE_ENABLE             (1 << 1)
#define MEM_STATUS_BP0                      (1 << 2)
#define MEM_STATUS_BP1                      (1 << 3)
#define MEM_STATUS_BP2                      (1 << 4)
#define MEM_STATUS_BPL                      (1 << 7)


/* SPIflash Commands */
#define MEM_READ                        0x03
#define MEM_WRITE                       0x02
#define MEM_SECTOR_ERASE_4K             0x20
#define MEM_SECTOR_ERASE_64K            0xD8
#define MEM_CHIP_ERASE                  0xC7
#define MEM_POWER_DOWN                  0xB9
#define MEM_READ_STATUS1                0x05
#define MEM_READ_STATUS2                0x35
#define MEM_ENABLE_WRITE_STATUS         0x50
#define MEM_WRITE_STATUS                0x01
#define MEM_WRITE_ENABLE                0x06
#define MEM_WRITE_ENABLE                0x04
#define MEM_READ_ID                     0x90

#define SELECT_CHIP                     PORTB &= ~(1<<PB4); \
                                        _delay_ms(10); \
                                        PORTB &= ~(1<<PB0);
#define DESELECT_CHIP                   PORTB |= (1<<PB0); \
                                        PORTB |= (1<<PB4);

void mem_read(uint32_t addr, uint8_t * buf, uint8_t sz);
void mem_write(uint32_t addr, uint8_t * buf, uint8_t sz);
uint16_t mem_read_id();
void mem_erase_sector_4k(uint32_t address);
void mem_erase_sector_64k(uint32_t address);
void mem_erase_chip();
void mem_write_enable();
#endif
