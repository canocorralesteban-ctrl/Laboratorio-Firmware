#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "esp_attr.h"
#include "esp_intr_alloc.h"
#include "esp_log.h"
#include "soc/interrupts.h"

typedef struct{
    //Group's Timer0
    uint32_t T0_CONFIG_REG;
    uint32_t T0_LO_REG;
    uint32_t T0_HI_REG;
    uint32_t T0_UPDATE_REG;
    uint32_t T0_ALARM_LO_REG;
    uint32_t T0_ALARM_HI_REG;
    uint32_t T0_LOAD_LO_REG;
    uint32_t T0_LOAD_HI_REG;
    uint32_t T0_LOAD_REG;

    //Group's Timer1
    uint32_t T1_CONFIG_REG;
    uint32_t T1_LO_REG;
    uint32_t T1_HI_REG;
    uint32_t T1_UPDATE_REG;
    uint32_t T1_ALARM_LO_REG;
    uint32_t T1_ALARM_HI_REG;
    uint32_t T1_LOAD_LO_REG;
    uint32_t T1_LOAD_HI_REG;
    uint32_t T1_LOAD_REG;

    //WDT Configuration
    uint32_t RESERVED_WDTCONFIG0_REG;
    uint32_t RESERVED_WDTCONFIG1_REG;
    uint32_t RESERVED_WDTCONFIG2_REG;
    uint32_t RESERVED_WDTCONFIG3_REG;
    uint32_t RESERVED_WDTCONFIG4_REG;
    uint32_t RESERVED_WDTCONFIG5_REG;
    uint32_t RESERVED_WDTFEED_REG;
    uint32_t RESERVED_WDTWPROTECT_REG;

    //RTC Calibration
    uint32_t RESERVED_RTCCALICFG_REG;
    uint32_t RESERVED_RTCCALICFG1_REG;

    //Interrupt Registers
    uint32_t INT_ENA_REG;
    uint32_t INT_RAW_REG;
    uint32_t INT_ST_REG;
    uint32_t INT_CLR_REG;
}volatile* const timer_addr_map_ptr_t;

//Direcciones base de los grupos de timers.
#define TIMER_GROUP0_BASE_ADDR (0x3FF5F000) 
#define TIMER_GROUP1_BASE_ADDR (0x3FF60000) 

#define TIMG0 ((timer_addr_map_ptr_t)TIMER_GROUP0_BASE_ADDR) //Primer estructura para el Grupo 0 de timers.
#define TIMG1 ((timer_addr_map_ptr_t)TIMER_GROUP1_BASE_ADDR) //Segunda estructura para el Grupo 1 de timers.


//OPERACIONES DE BIT CON MACROFUNCIONES PARA LOS TIMERS
#define T_EN 				(1UL << 31) //Habilitar timer. Tipo "Play/pause", dependiendo de si esta en HI_LO
#define T_INCREASE			(1UL << 30) //Direccion de conteo del timer. En este caso es en aumento.
#define T_AUTORELOAD		(1UL << 29) //Si el timer se debe "recargar" o reiniciar automaticamente.
#define T_DIVIDER_PRESCALE	(80UL << 13) // 80 MHz/80 = 1 MHz, que da 1us por tick
#define T_LEVEL_INT_EN		(1UL << 11)  // Habilitarr interrupcion de timer.
#define T_ALARM_EN			(1UL << 10)	//Habilitar alarma del timer

#define SET_BIT_HIGH(X)     (1UL << X)

//CTEs de tiempo
#define DEBOUNCE_US			20000UL		//20 ms de tiempo para antirrebote.
#define BLINK_STANDBY_US	1000000UL	//1s (Para parpadeo de system standby)
#define BLINK_RUNNING_US	250000UL	//Unidad de tiempo de 250ms (Para parpadeo de system running)
#define HOLD_US				3000000UL	//Unidad de tiempo de 3s (Para el contador de 3 segundos de RST)

typedef enum {TIMER_GROUP0, TIMER_GROUP1}avail_timer_groups_e_t;
typedef enum {TIMER_0, TIMER_1} avail_timer_inGroups_e_t;

typedef struct{
    uint64_t timer_time;
    void* timer_isr; //Puntero a función para configurar ISR.
    uint32_t autoreload;
} timer_config_t;
/*
void hal_timer_start(avail_timers_e_t);
void hal_timer_stop(avail_timers_e_t);
void hal_timer_reset(avail_timers_e_t);
void hal_timer_configure(avail_timers_e_t, timer_config_t);
*/