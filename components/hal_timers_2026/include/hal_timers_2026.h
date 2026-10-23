#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "esp_attr.h"
#include "esp_intr_alloc.h"
#include "esp_log.h"
#include "soc/interrupts.h"

typedef struct{
    uint32_t T0_CONFIG_REG;
    uint32_t T0_LO_REG;
    uint32_t T0_HI_REG;
    uint32_t T0_UPDATE_REG;
    uint32_t T0_ALARM_LO_REG;
    uint32_t T0_ALARM_HI_REG;
    uint32_t T0_LOAD_LO_REG;
    uint32_t T0_LOAD_HI_REG;
    uint32_t T0_LOAD_REG;

    uint32_t T1_CONFIG_REG;
    uint32_t T1_LO_REG;
    uint32_t T1_HI_REG;
    uint32_t T1_UPDATE_REG;
    uint32_t T1_ALARM_LO_REG;
    uint32_t T1_ALARM_HI_REG;
    uint32_t T1_LOAD_LO_REG;
    uint32_t T1_LOAD_HI_REG;
    uint32_t T1_LOAD_REG;
}volatile* const timer_addr_map_ptr_t;

#define TIMER_GROUP0_BASE_ADDR (0x3FF5F000)
#define TIMER_GROUP1_BASE_ADDR (0x3FF60000)

#define TIMG0 ((timer_addr_map_ptr_t)0x3FF5F000)
#define TIMG1 ((timer_addr_map_ptr_t)0x3FF60000)

#define T_EN 				(1UL << 31) //Habilitar timer. Tipo "Play/pause", dependiendo de si esta en HI_LO
#define T_INCREASE			(1UL << 30) //Direccion de conteo del timer. En este caso es en aumento.
#define T_AUTORELOAD		(1UL << 29) //Si el timer se debe "recargar" o reiniciar automaticamente.
#define T_DIVIDER_PRESCALE	(80UL << 13) // 80 MHz/80 = 1 MHz, que da 1us por tick
#define T_LEVEL_INT_EN		(1UL << 11)  // Habilitarr interrupcion de timer.
#define T_ALARM_EN			(1UL << 10)	//Habilitar alarma del timer

//CTEs de tiempo
#define DEBOUNCE_US			20000UL		//20 ms de tiempo para antirrebote.
#define BLINK_STANDBY_US	1000000UL	//1s (Para parpadeo de system standby)
#define BLINK_RUNNING_US	250000UL	//Unidad de tiempo de 250ms (Para parpadeo de system running)
#define HOLD_US				3000000UL	//Unidad de tiempo de 3s (Para el contador de 3 segundos de RST)
/*
typedef enum {TIMER0, TIMER1, TIMER2, TIMER3, TIMER4} avail_timers_e_t;
typedef struct{
    uint64_t timer_time;
    void arg* timer_isr; //Puntero a función para configurar ISR.
} timer_config_t;

void hal_timer_start(avail_timers_e_t);
void hal_timer_stop(avail_timers_e_t);
void hal_timer_configure(avail_timers_e_t, timer_config_t);
*/