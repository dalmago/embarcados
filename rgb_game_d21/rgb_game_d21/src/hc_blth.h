/*
 * hc_blth.h
 *
 * Created: 7/2/2017 8:04:30 PM
 *  Author: Matheus Dal Mago
 */ 


#ifndef __hc_blth_rgb_game__
#define __hc_blth_rgb_game__

#include <asf.h>

struct usart_module usart_instance;

void blth_init(void);
void blth_write_char(uint8_t);
uint8_t blth_recv_char(void);

#endif /* HC_BLTH_H_ */