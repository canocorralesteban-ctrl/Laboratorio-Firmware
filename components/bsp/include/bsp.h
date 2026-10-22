/******************************** Timer STRUCT Configuration **************************************
 * @subject: Software Embebido
 * @file: bsp.h
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano Cano
 * @date: 02/Octubre/2026
 * @descripcion: BSP de la placa Panther48
 * @brief: Interfaz del BSP
 *********************************************************************************************/

#ifndef BSP_H
#define BSP_H

#include "hal_gpio.h"

// Pines de los leds
typedef enum {
    LED_2  = 2,
    LED_4  = 4,
    LED_5  = 5,    
    LED_16 = 16,
    LED_17 = 17
} led_t;

// Pines de los leds rgb
typedef enum {
    RGB_R = 14,
    RGB_G = 13,
    RGB_B = 12
} rgb_t;

// Pines de los botones
typedef enum {
    BTN_1 = 18,
    BTN_2 = 19
} boton_t;

// Prototipo de las funciones del bsp


#endif