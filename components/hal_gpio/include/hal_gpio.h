/****************************************************************************
 * @subject: Software Embebido
 * @file: hal_gpio.h
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano, Paulina Cabriales y Armando Garcia
 * @date: 22/Octubre/2026
 * @descripcion: Prototipos del HAL de gpio
 *****************************************************************************/

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"

typedef enum {HAL_INPUT, HAL_OUTPUT} hal_mode_t;
typedef enum {HAL_NONE_PULL, HAL_PULL_UP, HAL_PULL_DOWN} hal_pull_t;

esp_err_t hal_gpio_init(uint8_t pin, hal_mode_t mode, hal_pull_t pull);
bool hal_gpio_read(uint8_t pin);
esp_err_t hal_gpio_write(uint8_t pin, bool state);

#endif