#include "hal_timers_2026.h"

void hal_timer_start(avail_timer_groups_e_t timer_group, avail_timer_inGroups_e_t timer_sel){
    timer_addr_map_ptr_t group_ptr = ((timer_group == TIMER_GROUP0)? TIMG0 : TIMG1);

    if(timer_sel == TIMER_0) 
        group_ptr -> T0_CONFIG_REG |= T_EN; //Habilitar Timer0 del grupo
    if(timer_sel == TIMER_1) 
        group_ptr -> T1_CONFIG_REG |= T_EN; //Habilitar Timer1 del grupo
}
void hal_timer_stop(avail_timer_groups_e_t timer_group, avail_timer_inGroups_e_t timer_sel){
    timer_addr_map_ptr_t group_ptr = ((timer_group == TIMER_GROUP0)? TIMG0 : TIMG1);

    if(timer_sel == TIMER_0)
        group_ptr -> T0_CONFIG_REG &= ~T_EN; //Detener Timer0 del grupo
    if(timer_sel == TIMER_1)
        group_ptr -> T1_CONFIG_REG &= ~T_EN; //Detener Timer1 del grupo

}
void hal_timer_reset(avail_timer_groups_e_t timer_group, avail_timer_inGroups_e_t timer_sel, uint64_t time_toLoad){
    timer_addr_map_ptr_t group_ptr = ((timer_group == TIMER_GROUP0)? TIMG0 : TIMG1);

    if(timer_sel == TIMER_0){
        group_ptr -> T0_CONFIG_REG &= ~T_EN; //Detener timer 0 del grupo antes de cargar valor.
        group_ptr -> T0_LOAD_LO_REG = (uint32_t)(time_toLoad & 0x0000FFFF); //Máscara para extraer los 32 LSB de uint64_t.
        group_ptr -> T0_LOAD_HI_REG = (uint32_t)(time_toLoad >> 32); //Corrimiento para extraer los 32 MSB de uint64_t.
        group_ptr -> T0_LOAD_REG = 1; //Cargar HI-LO REG
        group_ptr -> INT_CLR_REG = (SET_BIT_HIGH(0)); //Limpiar interrupción del timer.
        group_ptr -> T0_CONFIG_REG |= (T_ALARM_EN | T_EN); //Habilitar alarma y timer 0 del grupo.
    }
    if(timer_sel == TIMER_1){
        group_ptr -> T1_CONFIG_REG &= ~T_EN; //Detener timer 1 del grupo antes de cargar valor.
        group_ptr -> T1_LOAD_LO_REG = (uint32_t)(time_toLoad & 0x0000FFFF); //Máscara para extraer los 32 LSB de uint64_t. 
        group_ptr -> T1_LOAD_HI_REG = (uint32_t)(time_toLoad >> 32); //Corrimiento para extraer los 32 MSB de uint64_t.
        group_ptr -> T1_LOAD_REG = 1; //Cargar HI-LO REG
        group_ptr -> INT_CLR_REG = (SET_BIT_HIGH(1)); //Limpiar interrupción del timer.
        group_ptr -> T1_CONFIG_REG |= (T_ALARM_EN | T_EN); //Habilitar alarma y timer 1 del grupo.
    }
}
void hal_timer_configure(avail_timer_groups_e_t timer_group, avail_timer_inGroups_e_t timer_sel, timer_config_t config_struct){
    
}