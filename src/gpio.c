// -------------------------------------------------------------------------------

// Autores:

// Caio Alessandro Resnauer
// Erik Ryuichi Yamamoto
// Victor Jordão

// -------------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>

//#include "TM4C1294NCPDT.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "gpio.h"

// -------------------------------------------------------------------------------

void GPIO_Init(void) {
  
// GIPO N -> LEDS 1 E 2  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION); // Habilita GPIO N (LED D1 = PN1, LED D2 = PN0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)); // Aguarda final da habilitação
  
  GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1); // LEDs D1 e D2 como saída
  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, 0); // LEDs D1 e D2 apagados
  GPIOPadConfigSet(GPIO_PORTN_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  
// GIPO F -> LEDS 3 E 4
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D3 = PF4, LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4); // LEDs D3 e D4 como saída
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, 0); // LEDs D3 e D4 apagados
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);
  
// GIPO J -> PUSH-BUTTONS SW1 E SW2
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ); // Habilita GPIO J (push-button SW1 = PJ0, push-button SW2 = PJ1)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)); // Aguarda final da habilitação
    
  GPIOPinTypeGPIOInput(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1); // push-buttons SW1 e SW2 como entrada
  GPIOPadConfigSet(GPIO_PORTJ_BASE, GPIO_PIN_0 | GPIO_PIN_1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
  
  
}
// -------------------------------------------------------------------------------

uint32_t PortC_Input(void) {
  return GPIOPinRead(GPIO_PORTC_BASE, BIT7);
}

// -------------------------------------------------------------------------------

uint32_t PortJ_Input(void) {
  return GPIOPinRead(GPIO_PORTJ_BASE, BIT1 | BIT0);
}

// -------------------------------------------------------------------------------

void PortA_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTA_BASE, BIT7 | BIT6 | BIT5 | BIT4, valor);
}

// -------------------------------------------------------------------------------

void PortB_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTB_BASE, BIT5 | BIT4, valor);
}

// -------------------------------------------------------------------------------

void PortE_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTE_BASE, BIT3 | BIT2 | BIT1 | BIT0, valor);
}

// -------------------------------------------------------------------------------

void PortF_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTF_BASE, BIT3 | BIT2, valor);
}

// -------------------------------------------------------------------------------

void PortH_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTH_BASE, BIT3 | BIT2 | BIT1 | BIT0, valor);
}

// -------------------------------------------------------------------------------

void PortK_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTK_BASE, BIT7 | BIT6 | BIT5 | BIT4 | BIT3 | BIT2 | BIT1 | BIT0, valor);
}

// -------------------------------------------------------------------------------

void PortL_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTL_BASE, BIT3 | BIT2 | BIT1 | BIT0, valor);
}

// -------------------------------------------------------------------------------

void PortM_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTM_BASE, BIT6 | BIT2 | BIT1 | BIT0, valor);
}

// -------------------------------------------------------------------------------

void PortN_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTN_BASE, BIT1 | BIT0, valor);
}

// -------------------------------------------------------------------------------

void PortQ_Output(uint32_t valor) {
  GPIOPinWrite(GPIO_PORTQ_BASE, BIT3 | BIT2 | BIT1 | BIT0, valor);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////