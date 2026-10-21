/******************************** Timer MACROS Configuration **************************************
 * @subject: Software Embebido
 * @file: gpio_config_2026.h
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano Cano
 * @date: 02/Octubre/2026
 * @descripcion: Definicion de Macros a Registros
 *********************************************************************************************/
#ifndef GPIO_CONFIG_2026_H
#define GPIO_CONFIG_2026_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

/*********************************************************************
* Esta Version es para inciar con el manejo de registros con MACROS
*/
// DECLARACION DE CONSTANTES Y MACROFUNCIONES
#define GPIO_OUT            (*((volatile uint32_t*)(0x3FF44004)))
#define GPIO_W1TS           (*((volatile uint32_t*)(0x3FF44008)))
#define GPIO_W1TC           (*((volatile uint32_t*)(0x3FF4400C)))
#define GPIO_ENABLE_W1TS    (*((volatile uint32_t*)(0x3FF44024)))
#define GPIO_ENABLE_W1TC    (*((volatile uint32_t*)(0x3FF44028)))
#define IOMUX_GPIO18        (*((volatile uint32_t*)(0x3FF49070)))
#define IOMUX_GPIO19        (*((volatile uint32_t*)(0x3FF49074)))
#define GPIO_IN             (*((volatile uint32_t*)(0x3FF4403C)))
#define HWREG32(ADDR) (*((volatile uint32_t *)(ADDR)))
#define IOMUX_REG(NUM)      HWREG32(IOMUX_ADDR[NUM])

// MASCARAS DE BITS
#define FUN_WPD  (1UL<<7)
#define FUN_WPU  (1UL<<8)
#define FUN_IE   (1UL<<9)
#define MCU_SEL  (1UL<<13)
#define _BIT(X)  (1UL<<(X))


#define IS_IN_RANGE(VAL,MIN,MAX)  ((MIN <= VAL) && (VAL <= MAX))
#define IS_GPIO(NUM)    (((NUM) <= 19) || IS_IN_RANGE(NUM, 21, 23)\
                        || IS_IN_RANGE(NUM, 25, 27) || IS_IN_RANGE(NUM, 32, 39))

#define IS_ONLY_IN(NUM) (IS_IN_RANGE(NUM, 34, 39))

#endif