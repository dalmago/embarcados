/**
 * \file
 *
 * \brief Empty user application template
 *
 */


/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include "led.h"
#include "utils.h"
// #include "blth.h"
// #include "fsm_table.h"

int main (void)
{
	system_init();
    setup_rgb(PORTB.16, PORTB.17, PORTB.11);
    // init_peripheral_role();
    

    while(1){
        set_rgb_color(RED);
        delay(500);
        set_rgb_color(OFF);
        delay(500);
        
    }
}
