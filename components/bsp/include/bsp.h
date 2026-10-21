/******************************** Timer MACROS Configuration **************************************
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

// Declaracion de HW de la placa "Panther 48"
#define LED_2 2
#define LED_4 4
#define LED_5 5
#define LED_16 16
#define LED_17 17

typedef enum{LEDR = 12, LEDG, LEDB}led_rgb_e_t;
typedef enum{B_IZQ = 18, B_DER}boton_e_t;
typedef enum{NTC = 36, LDR = 39}sensor_e_t;
typedef enum{SDA = 21, SCL}oled_e_t;

typedef void(*isr_gpio_t)(void *arg);
typedef struct {
    uint8_t timer;
    uint8_t frec;
    uint8_t resolution;
    uint8_t channel;
    union {
        uint8_t duty;
        uint8_t duty_percent;
    };
}pwm_t;

typedef struct{
    uint8_t     pin;
    gpio_mode_t mode;
    pull_type_e pull_mode;
    uint8_t     int_type;
    bool        inv_logic;
    uint8_t     state;
    uint8_t     state_old;
    isr_gpio_t  callback;
    pwm_t       pwm;
}bsp_gpio_in_config_t;

// PROTOTIPOS (INTERFAZ DEL DRIVER)
extern esp_err_t bsp_gpio_salida(uint8_t num_gpio);
extern esp_err_t bsp_init_salidas(void);
extern esp_err_t bsp_gpio_entrada(uint8_t num, pull_type_e pull_type);
extern esp_err_t bsp_init_entradas(void);
extern esp_err_t bsp_init_board(void);

extern esp_err_t bsp_gpio_write(uint8_t num, bool state);
bool bsp_gpio_read(uint8_t num);

#endif