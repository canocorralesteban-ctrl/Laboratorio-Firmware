
/**
 * @subject: Software Embebido
 * @file: driver_gpio_config.h
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano, Paulina Cabriales y Armando Garcia
 * @date: 23/Octubre/2026
 * @descripcion: Mapeo de registros de GPIO con estructura
 */

#ifndef DRIVER_GPIO_CONFIG_H
#define DRIVER_GPIO_CONFIG_H

#include <stdint.h>

// Estructura con los registros de GPIO

typedef struct {
    volatile uint32_t reservado0;      // 0x00 
    volatile uint32_t out;             // 0x04  salidas GPIO 0-31
    volatile uint32_t out_w1ts;        // 0x08  poner en 1
    volatile uint32_t out_w1tc;        // 0x0C  poner en 0
    volatile uint32_t out1;            // 0x10  salidas GPIO 32-39
    volatile uint32_t out1_w1ts;       // 0x14  poner en 1
    volatile uint32_t out1_w1tc;       // 0x18  poner en 0
    volatile uint32_t reservado1;      // 0x1C
    volatile uint32_t enable;          // 0x20  habilita salida 0-31
    volatile uint32_t enable_w1ts;     // 0x24
    volatile uint32_t enable_w1tc;     // 0x28
    volatile uint32_t enable1;         // 0x2C  habilita salida 32-39
    volatile uint32_t enable1_w1ts;    // 0x30
    volatile uint32_t enable1_w1tc;    // 0x34
    volatile uint32_t strap;           // 0x38
    volatile uint32_t in;              // 0x3C  entradas GPIO 0-31
    volatile uint32_t in1;             // 0x40  entradas GPIO 32-39
} gpio_regs_t;

#define GPIO_BASE  0x3FF44000
#define GPIO_REGS  ((gpio_regs_t *)GPIO_BASE)

// mascaras de bits
#define FUN_WPD  (1UL<<7)   //pull down interno
#define FUN_WPU  (1UL<<8)   //pull up interno
#define FUN_IE   (1UL<<9)   //habilitar entrada
#define MCU_SEL  (1UL<<13)  //selecciona que el pin sea controlado por el MCU

#define _BIT(X)  (1UL<<(X)) //mascara de bit para el pin X

#endif