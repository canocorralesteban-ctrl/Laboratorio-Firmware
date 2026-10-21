/******************************** Timer MACROS Configuration **************************************
 * @subject: Software Embebido
 * @file: gpio_config_2026.h
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano Cano
 * @date: 02/Octubre/2026
 * @descripcion: Prototiopos de las funciones del driver
 * @descripcion: Definicion de Macros a Registros
 *********************************************************************************************/
#ifndef  GPIO_2026_H
#define  GPIO_2026_H

// Incluir librerias
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "gpio_config_2026.h"

// ENUMERACIONES
typedef enum {NONE_PULL, PULL_UP, PULL_DOWN}pull_type_e;
typedef enum {INPUT, OUTPUT, OUTPWM}gpio_mode_t;

esp_err_t gpio_salida(uint8_t num);
esp_err_t gpio_entrada(uint8_t num, pull_type_e pull_type);
bool gpio_read(uint8_t num);
esp_err_t gpio_write(uint8_t num, bool state);

#endif