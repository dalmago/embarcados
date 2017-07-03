#include "hc_blth.h"

void blth_init(void){
	struct usart_config config_usart;
	usart_get_config_defaults(&config_usart);

	config_usart.baudrate    = 38400;

	config_usart.mux_setting = EXT1_UART_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EXT1_UART_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EXT1_UART_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EXT1_UART_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EXT1_UART_SERCOM_PINMUX_PAD3;
	
	while (usart_init(&usart_instance, EXT1_UART_MODULE, &config_usart) != STATUS_OK);
	
	usart_enable(&usart_instance);
}

void blth_write_char(uint8_t c){
	usart_write_wait(&usart_instance, c);
}

uint8_t blth_recv_char(void){
	volatile uint16_t c;
	
	if (usart_read_wait(&usart_instance, &c) == STATUS_OK){
		return c;
	}
	
	return 0;
}
