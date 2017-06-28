#include "fsm_table.h"

//****************************************************************************//
// State table typedef
//****************************************************************************//

struct StateMachine
{
    Evento_t evento;
    State_t state;
} sm;

const FSM_STATE_TABLE StateTable [NR_STATES][NR_EVENTS] =
{
    NULL, S0,             NULL, S1,
    aguartaInit, S1,      NULL, S2,
    blinkSequency, S2,    NULL, S3,
    checkSequency, S3,    NULL, S1,
};


void initFSM(void)
{
    sm.evento = E0;
    sm.state = S0;
    
    rgb_index = 0;
}

// callback, quando BLE conectado, seta evento para E1

void aguartaInit(void){
    uint8_t b;
    
    // if (BLEavailable()){
    //  b = readBLE();
    
    if (b == 'i'){
        sm.evento = E1;
    }
    
    // }
}

void blinkSequency(void){
    
    if (rgb_index < RGB_LENGTH){        
        set_rgb_color(rgb_sequency[rgb_index]);
        delay(500);
        set_rgb_color(OFF);
        delay(500);
        
    } else if (rgb_index == RGB_LENGTH){
        // sendBLE('o')
        rgb_index = 0;
    } else{
        sm.evento = E1;
    }
    
    rgb_index++;
    
}

void checkSequency(void){
    
    if (rgb_index < RGB_LENGTH){ // still receiving bluetooth data
        
        uint8_t color;
        // color = readBLE();
        
        switch(color){
            case 'r':
                rgb_recv[rgb_index] = RED;
                break;
            case 'g':
                rgb_recv[rgb_index] = GREEN;
                break;
            case 'b':
                rgb_recv[rgb_index] = BLUE;
                break;
            default:
                rgb_recv[rgb_index] = NULL;
        }
        
    } else if (rgb_index == RGB_LENGTH){ // done receiving
        
        uint8_t score = calculate_score();
        // sendBLE(score);
        
    } else{
        sm.evento = E1;
    }
    
    rgb_index++;
}


void handleFSM(void){
    if (StateTable[sm.state][sm.evento].ptrFunc != NULL)
        StateTable[sm.state][sm.evento].ptrFunc();

    sm.state = StateTable[sm.state][sm.evento].NextState;
    
    if (sm.state != S0)
        sm.evento = E0;
}



uint8_t calculate_score(void){
    uint8_t i;
    uint8_t score = 0;
    
    for (i=0; i<RGB_LENGTH; i++){
        if (rgb_sequency[i] == rgb_recv[i])
            score++;
    }
    
    return score;
}


void fsm_tabela_teste(void)
{
	
    initFSM();
    while(1)
        handleFSM();
}