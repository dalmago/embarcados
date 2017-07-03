#include "flash_mem.h"

#define FIRST_BYTE (68)

struct spi_module at25dfx_spi;
struct at25dfx_chip_module at25dfx_chip;

void flash_init(void){
	
	struct at25dfx_chip_config at25dfx_chip_config;
	struct spi_config at25dfx_spi_config;
	at25dfx_spi_get_config_defaults(&at25dfx_spi_config);
	at25dfx_spi_config.mode_specific.master.baudrate = AT25DFX_CLOCK_SPEED;
	at25dfx_spi_config.mux_setting = AT25DFX_SPI_PINMUX_SETTING;
	at25dfx_spi_config.pinmux_pad0 = AT25DFX_SPI_PINMUX_PAD0;
	at25dfx_spi_config.pinmux_pad1 = AT25DFX_SPI_PINMUX_PAD1;
	at25dfx_spi_config.pinmux_pad2 = AT25DFX_SPI_PINMUX_PAD2;
	at25dfx_spi_config.pinmux_pad3 = AT25DFX_SPI_PINMUX_PAD3;
	spi_init(&at25dfx_spi, AT25DFX_SPI, &at25dfx_spi_config);
	spi_enable(&at25dfx_spi);
	 
	at25dfx_chip_config.type = AT25DFX_MEM_TYPE;
	at25dfx_chip_config.cs_pin = AT25DFX_CS;
	at25dfx_chip_init(&at25dfx_chip, &at25dfx_spi, &at25dfx_chip_config);
	 
	 
	uint8_t read_buffer[2];
	uint8_t write_buffer[] = {FIRST_BYTE};
	ultima_pontuacao = 0;
	
	 at25dfx_chip_wake(&at25dfx_chip);
	 
	 if (at25dfx_chip_check_presence(&at25dfx_chip) == STATUS_OK) {
		 at25dfx_chip_read_buffer(&at25dfx_chip, 0x0000, read_buffer, 2);
		 
		 if (read_buffer[0] != FIRST_BYTE){ // first memory write
			 
			 at25dfx_chip_set_global_sector_protect(&at25dfx_chip, false);
			 at25dfx_chip_write_buffer(&at25dfx_chip, 0x0000, write_buffer, 1);
			 			 
		 } else{
			 ultima_pontuacao = read_buffer[1];
		 }
	 }
	 
	 // at25dfx_chip_sleep(&at25dfx_chip);
}

void store_score(uint8_t s){
	
	uint8_t write_buffers[2];
	write_buffers[0] = FIRST_BYTE;
	write_buffers[1] = s;
	
	ultima_pontuacao = s;
	
	//at25dfx_chip_wake(&at25dfx_chip);
	at25dfx_chip_write_buffer(&at25dfx_chip, 0x0000, write_buffers, 2);
	
	//at25dfx_chip_sleep(&at25dfx_chip);
}
