#include "lib/include.h"
extern void Configurar_GPIO(void)
{
volatile uint32_t delay= SYSCTL->RCGCGPIO;      // no need to unlock;
SYSCTL->RCGCGPIO |= 0x12;      // Puertos b y E (00010010)
//GPIO se hace para cada puerto
//Entradas 0, salidas 1. DIR--DATA DIRECTION
GPIOB->DIR |= 0x3F;    // salidas en el puerto b, desde PB0-PB5 (00111111=0x3F)
GPIOE->DIR &= ~0x03;   // Entradas en el puerto E, desde PE0-PE1 (00000011=0x03) Y va negado 

//DEN--digital enable 0-funcion digital deshabilitada 1-func dig habilitada
GPIOB->DEN |= 0x3F;    // enable digital on PB5-0 (00111111=0x3F)
GPIOE->DEN |= 0x03;    // enable digital on PE1-0 (00000011=0x03)

}