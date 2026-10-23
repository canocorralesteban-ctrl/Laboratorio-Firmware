/****************************************************************************
 * @subject: Software Embebido
 * @file: hal_gpio.c
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano, Paulina Cabriales y Armando Garcia
 * @date: 22/Octubre/2026
 * @descripcion: Se conectan el hal y driver
 *****************************************************************************/

#include "hal_gpio.h"
#include "driver_gpio.h"

esp_err_t hal_gpio_init(uint8_t pin, hal_mode_t mode, hal_pull_t pull) {
    if (mode == HAL_INPUT) {
        driver_pull_t pull_driver = DRIVER_NONE_PULL;

        if (pull == HAL_PULL_UP)
            pull_driver = DRIVER_PULL_UP;
        else if (pull == HAL_PULL_DOWN)
            pull_driver = DRIVER_PULL_DOWN;

        return gpio_entrada(pin, pull_driver);
    }

    if (mode == HAL_OUTPUT)
        return gpio_salida(pin);

    return ESP_ERR_INVALID_ARG;
}

bool hal_gpio_read(uint8_t pin) {
    return gpio_read(pin);
}

esp_err_t hal_gpio_write(uint8_t pin, bool state)
{
    return gpio_write(pin, state);
}