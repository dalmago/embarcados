
/*
 * fsm_tabela.h
 *
 */


#ifndef __fsm_table_rgb_game__
#define __fsm_table_rgb_game__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "led.h"
#include "utils.h"
#include "hc_blth.h"
#include "flash_mem.h"

typedef struct
{
    void (*ptrFunc) (void);
    uint8_t NextState;
} FSM_STATE_TABLE;


#define MAX_BUFFER 10

#define NR_STATES 4
#define NR_EVENTS 2

#define RGB_LENGTH 5

typedef enum
{
    S0 = 0,
    S1,
    S2,
    S3
} State_t;

typedef enum
{
    E0 = 0,
    E1,
    E2,
    E3,
    E4
} Evento_t;


void initFSM(void);
void aguartaInit(void);
void blinkSequency(void);
void checkSequency(void);
void handleFSM(void);
uint8_t calculate_score(void);

#endif /* FSM_TABELA_H_ */
