/*
 * flash_mem.h
 *
 * Created: 7/3/2017 12:32:54 AM
 *  Author: Matheus Dal Mago
 */ 


#ifndef __flash_mem_rgb_game__
#define __flash_mem_rgb_game__

#include <asf.h>
#include <stdint.h>
#include <at25dfx.h>
#include "conf_at25dfx.h"

uint8_t ultima_pontuacao;

void flash_init(void);
void store_score(uint8_t);

#endif /* FLASH_MEM_H_ */