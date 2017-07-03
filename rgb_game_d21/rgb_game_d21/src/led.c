#include "led.h"

void setup_rgb(const uint8_t r, const uint8_t g, const uint8_t b){
    
    r_led = r;
    g_led = g;
    b_led = b;
    
    struct port_config config_r, config_g, config_b;
    port_get_config_defaults(&config_r);
    port_get_config_defaults(&config_g);
    port_get_config_defaults(&config_b);
    
    config_r.direction = PORT_PIN_DIR_OUTPUT;
    config_g.direction = PORT_PIN_DIR_OUTPUT;
    config_b.direction = PORT_PIN_DIR_OUTPUT;
    
    port_pin_set_config(r_led, &config_r);
    port_pin_set_config(g_led, &config_g);
    port_pin_set_config(b_led, &config_b);
}

void set_rgb_color(led_color_t c){
    switch(c){
        case RED:
            port_pin_set_output_level(r_led, 1);
            port_pin_set_output_level(g_led, 0);
            port_pin_set_output_level(b_led, 0);
            break;
        case GREEN:
            port_pin_set_output_level(r_led, 0);
            port_pin_set_output_level(g_led, 1);
            port_pin_set_output_level(b_led, 0);
            break;
        case BLUE:
            port_pin_set_output_level(r_led, 0);
            port_pin_set_output_level(g_led, 0);
            port_pin_set_output_level(b_led, 1);
            break;
        default:
            port_pin_set_output_level(r_led, 0);
            port_pin_set_output_level(g_led, 0);
            port_pin_set_output_level(b_led, 0);
    }
}
