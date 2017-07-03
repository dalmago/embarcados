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
#include "hc_blth.h"
#include "fsm_table.h"

int main (void)
{
	system_init();
	setup_rgb(PIN_PB01, PIN_PB06, PIN_PB00);
	blth_init();
	initFSM();

    while(1){
         handleFSM();
    }
}
