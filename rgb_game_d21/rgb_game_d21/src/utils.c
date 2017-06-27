#include "utils.h"

void timer_config(void){
    
}

void delay(uint16_t ms){
    struct tcc_config tcc_cfg;
    
    tcc_get_config_defaults(&tcc_cfg, TCC1);
    tcc_cfg.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV8; // 8MHz
    tcc_init(&tcc_instance, TCC1, &tcc_cfg);
    tcc_enable(&tcc_instance);
    
    uint32_t t;
    
    do{
        t = tcc_get_count_value(&tcc_instance)/1000;
    } while (t < period_ms);
    
    tcc_reset(&tcc_instance);
}
