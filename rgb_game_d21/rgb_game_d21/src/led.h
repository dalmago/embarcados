#ifndef __led_rgb_game__
#define __led_rgb_game__

#include <stdint.h>
#include <asf.h>

uint8_t r_led;
uint8_t g_led;
uint8_t b_led;

typedef enum{
    RED=0,
    GREEN,
    BLUE,
    OFF
}led_color_t;

void setup_rgb(const uint8_t r, const uint8_t g, const uint8_t b);
void set_rgb_color(led_color_t c);

#endif
