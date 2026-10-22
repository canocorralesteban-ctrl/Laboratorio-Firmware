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

#include "gpio_2026.h"

// PINES DE LOS LEDS
typedef enum {
    LED_2  = 2,
    LED_4  = 4,
    LED_5  = 5,    
    LED_16 = 16,
    LED_17 = 17
} bsp_led_t;

// PINES DE LOS LEDS RGB
typedef enum {
    RGB_R = 14,
    RGB_G = 13,
    RGB_B = 12
} bsp_rgb_t;

// PINES DE LOS BOTONES
typedef enum {
    BTN_1 = 18,
    BTN_2 = 19
} bsp_boton_t;

// PROTOTIPO DE LAS FUNCIONES DEL BSP


#endif