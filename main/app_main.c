/*
 * app_main.c
 *
 *  Created on: 2020-02-01 23:25
 *      Author: Jack Chen <redchenjs@live.com>
 */

#include "esp_bt.h"
#include "esp_log.h"

#include "nvs_flash.h"

#include "driver/uart.h"
#include "soc/uhci_periph.h"
#include "driver/periph_ctrl.h"

#define TAG "uart_hci"

int app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    periph_module_enable(PERIPH_UART1_MODULE);
    periph_module_enable(PERIPH_UHCI0_MODULE);

    ESP_ERROR_CHECK(uart_set_pin(UART_NUM_1, 5, 18, 19, 23));

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_bt_controller_init(&bt_cfg));
    ESP_ERROR_CHECK(esp_bt_controller_enable(ESP_BT_MODE_BTDM));

    ESP_LOGI(TAG, "initialized, tx: 5, rx: 18, rts: 19, cts: 23");

    return 0;
}
