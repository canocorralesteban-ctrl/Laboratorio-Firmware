#include "bsp.h"

bsp_gpio_in_config_t salida{

};

esp_err_t bsp_gpio_salida(uint8_t num){
    return gpio_salida(num);
}

esp_err_t bsp_gpio_entrada(uint8_t num, pull_type_e pull_type){
    return gpio_entrada(num, pull_type);
}

esp_err_t bsp_init_salidas(void){
    return ESP_OK;
}
