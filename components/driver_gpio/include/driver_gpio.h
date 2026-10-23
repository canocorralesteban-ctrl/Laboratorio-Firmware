/****************************************************************************
 * @subject: Software Embebido
 * @file: driver_gpio.h
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano, Paulina Cabriales y Armando Garcia
 * @date: 22/Octubre/2026
 * @descripcion: Prototiopos de las funciones del driver
 *****************************************************************************/

#ifndef  DRIVER_GPIO_H
#define  DRIVER_GPIO_H

// Incluir librerias
#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"

// Enumeraciones
typedef enum {DRIVER_INPUT, DRIVER_OUTPUT}driver_mode_t;
typedef enum {DRIVER_NONE_PULL, DRIVER_PULL_UP, DRIVER_PULL_DOWN}driver_pull_t;

// Definiciones 
esp_err_t gpio_salida(uint8_t num);
esp_err_t gpio_entrada(uint8_t num, driver_pull_t pull);
esp_err_t gpio_write(uint8_t num, bool state);
bool gpio_read(uint8_t num);

#endif