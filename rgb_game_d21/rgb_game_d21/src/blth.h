#ifndef __blth_rgb_game__
#define __blth_rgb_game__

#include <stdint.h>
#include <asf.h>
#include "at_ble_api.h"

#define CHECK_ERROR(VAR,LABEL) if(AT_BLE_SUCCESS != VAR) { goto LABEL; }

#define DEVICE_NAME "RGB Game"

uint8_t adv_data[] = { 0x11, 0x07, 0x1b, 0xc5, 0xd5, 0xa5, 0x02, 0x00, 0x37,
                    0xaa, 0xe3, 0x11, 0x2a, 0xdc, 0x00, 0xcd, 0x30, 0x57};

at_ble_status_t init_peripheral_role(void);

#endif
