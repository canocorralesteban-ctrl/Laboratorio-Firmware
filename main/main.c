/******************************** Timer MACROS Configuration **************************************
 * @subject: Software Embebido
 * @file: main.c
 * @hardware: ESP32 (PANTHER48)
 * @author: Esteban Cano Cano
 * @date: 02/Octubre/2026
 * @descripcion: Implementacion de las funciones del driver
 *********************************************************************************************/

#include "gpio_2026.h"

#define BOTON_IZQ   18
#define BOTON_DER   19
#define LED2   2
#define LED4  4

// FUNCION PRINCIPAL
void app_main(void)
{
    /*Falta modificar para usar las funciones que hicimos gn gpio_2026*/
    // CONFIGURACION DEL HARDWARE
    GPIO_ENABLE_W1TS = _BIT(LED2) | _BIT(LED4);     //gpio_enable_w1ts LED en GPIO2 "fisicamente el bit1 se pone en alto los demas permanecen igual"
    GPIO_OUT &= ~(_BIT(LED2) | _BIT(LED4));  //gpio_out "ponemos en bajo el bit1 "

    GPIO_ENABLE_W1TC    = _BIT(BOTON_IZQ); //gpio_enable_w1tc Para asegurar que no sea salida
    IOMUX_GPIO18        |= (MCU_SEL|FUN_IE|FUN_WPU); // iomux_gpio18 Para configurar como entrada con pullup
    GPIO_ENABLE_W1TC    = _BIT(BOTON_DER); //gpio_enable_w1tc Para asegurar que no sea salida
    IOMUX_GPIO19        |= (MCU_SEL|FUN_IE|FUN_WPU); //iomux_gpio19 Para configurar como entrada con pullup

    uint8_t state_old_boton_izq  = true;
    uint8_t state_boton_izq   = true;
    uint8_t state_old_boton_der  = true;
    uint8_t state_boton_der   = true;

    // CODIGO DE APLICACION
    while(true)
    {
        state_boton_izq = (GPIO_IN >> BOTON_IZQ) & 0x01;  //gpio_in
        state_boton_izq = gpio_read(BOTON_IZQ);

        if((!state_boton_izq)&&state_old_boton_izq)
        {
            GPIO_W1TS = _BIT(LED2) | _BIT(LED4); //w1ts  LED 2 y 4
            printf("Led Encendido\n");
        }

        state_boton_der = (GPIO_IN >> BOTON_DER) & 0x01; //gpio_in

        if(!(state_boton_der)&&state_old_boton_der)
        {
            GPIO_W1TC = _BIT(LED2) | _BIT(LED4); //w1tc LED 2 y 4
            printf("Led Apagado\n");
        }
        state_old_boton_izq = state_boton_izq;
        state_old_boton_der = state_boton_der;
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}