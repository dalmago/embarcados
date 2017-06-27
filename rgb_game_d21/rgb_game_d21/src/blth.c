#include "blth.h"

at_ble_status_t init_peripheral_role(void)
{
    at_ble_status_t status;
    at_ble_init_config_t pf_cfg;
    platform_config busConfig;
    at_ble_addr_t addr = {AT_BLE_ADDRESS_PUBLIC,
        {0x25, 0x75, 0x11, 0x6a, 0x7f, 0x7f}
    };
    //Set device name
    status = at_ble_device_name_set((uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
    CHECK_ERROR(status, __EXIT);
    /*Memory allocation required by GATT Server DB*/
    pf_cfg.memPool.memSize = 0;
    pf_cfg.memPool.memStartAdd = NULL;
    /*Bus configuration*/
    busConfig.bus_type = UART;
    pf_cfg.plf_config = &busConfig;
    //Initializations of device
    status = at_ble_init(&pf_cfg);
    CHECK_ERROR(status, __EXIT);
    //Set device address
    status = at_ble_addr_set(&addr);
    CHECK_ERROR(status, __EXIT);
    //Set advertising data, instead of NULL set scan response data if needed
    status = at_ble_adv_data_set(adv_data, sizeof(adv_data), NULL, 0))
    CHECK_ERROR(status, __EXIT);
    //Start advertising
    status = at_ble_adv_start(AT_BLE_ADV_TYPE_UNDIRECTED, AT_BLE_ADV_GEN_DISCOVERABLE, NULL, AT_BLE_ADV_FP_ANY, 100, 0, false))
__EXIT:
    return status;
}
