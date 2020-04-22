#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

#include "gpio.h"

#define PWM_MAX (10)
#define PWM_MIN (0)
//#define FREQ_MAX (1000000)

int FREQ_MAX = 1000000;  //SOMENTE FAZENDO TESTES COM A FREQUENCIA

int LED_D1 = 0;

int PWM = 5;

int chave1 = 0;
int chave2 = 0;

int apertado() {
  int valor = PortJ_Input();

  if (valor == 2 || valor == 1 ) {
    for ( int i = 0; i < FREQ_MAX; i++ ) {}
  }
  
  return valor;
  
}

void muda_PWM(uint8_t botao) {
  if ( botao == 3 ) { // nenhum botao sendo apertado
  PortN_Output(0);
    return;
  } else if ( botao == 2 ) {  //sw1 sendo apertado
  PortN_Output(2);
    if (PWM < PWM_MAX){  //verifica se não passou 100%
      PWM++;
      return;
    } else {
//      PWM = 10;
      return;
    }
  } else if ( botao == 1 ) {  //sw2 sendo apertado
  PortN_Output(1);
    if (PWM > PWM_MIN){  //verifica se não passou 0%
      PWM--;
      return;
    } else {
//      PWM = 0;
      return;
    }
  } else {
  PortN_Output(3);
    return;  //outros casos
  }
}

void PWM_execute() {
  
  for ( int i = 0; i < (FREQ_MAX*PWM/10); i++ ) {
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_PIN_0);
    muda_PWM(apertado());
  }
  for ( int i = 0; i < (FREQ_MAX*(10 - PWM)/10); i++ ) {
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0);
    muda_PWM(apertado());
  }
  
}

void main(void){
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  
  GPIO_Init();
  
  while(1){
        
    
    PWM_execute();
    
    
  } // while
} // main
