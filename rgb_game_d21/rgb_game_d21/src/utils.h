#ifndef __utils_rgb_game__
#define __utils_rgb_game__

#include <stdint.h>
#include <asf.h>
#include <tcc.h>

// uint16_t timer_count = 0;
struct tcc_module tcc_instance;

void timer_config(void);
void delay(uint16_t ms);

#endif
