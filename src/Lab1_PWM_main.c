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

bool isPress1 = false;  //default value for unpress buttons sw1 and sw2
bool isPress2 = false;  //default value for unpress buttonssw1 and sw2

//anti-aliasing of the buttons 
int apertado() {
//first changes variable isPressX on press down button
//then verificate when the button go up to account a validate pressing
  
  int buttonValue = PortJ_Input();

// cheks if the button was pressed down
  if (buttonValue == 2){  // sw1 pressed
    isPress1 = true;
  } else if (buttonValue == 1 ) {  // sw2 pressed
    isPress2 = true;
  }
 
//check when the button returns up
  if (isPress1 == true && buttonValue == 3) {
    isPress1 = false;
    return 2;  // sw1 validated
  }
  else if (isPress2 == true && buttonValue == 3) {
    isPress2 = false;
    return 1;  // sw2 validated
  } else {
    return 3;  // any button pressed
  }
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
