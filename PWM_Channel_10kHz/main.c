#include "Clock_Driver.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"
#include "Debug_Driver.h"

//Example of using GPIO_Driver

/* This driver uses the GPIO_Driver and PWM_Driver libraries which provide definitions for
   different functions that help to intialize Tiva c  peripherals.
   To use this driver you will also need to use tm4c123gh6pm to map 
   registers correctly.
   This example provides you with a PWM signal with variable frequency and duty cycle.
   The initial frequency and duty cycle are 10Khz and 20% respectively.
   Used pins
   ===========
   Pin GND as Ground
   Pin B7 as PWM output

   History
   =======
   2021/August/08  - First release (Mosad)
   mo.eldibani@gmail.com
*/

void main()
{
  Debug_Intialization();													//To intialize Pins for Debugging Leds
  
  Set_Clock_MHz(16,80);														//To set System clk
  CLK_PWM_Enable(0);														//To Enable PWM module 0
  CLK_Enable('B');															//To Enable clk for port B
  PIN_FUNCTION_SELECT('B',7,"Alternative");									//Set pin B7 as Alternative
  PIN_CONFIGURE('B',7,"PWM");												//Configure Pin B7 as PWM
  PIN_ANALOG_DIGITAL('B',7,"Digital");										//Set pin B7 as digital										
  Use_PWM_Divisor(80,40);													//Set PWM clk
  PWM_Generator_Enable(0,0,"Disable");										//Disable Generator 0
  PWM_Action_For_Load(0,0,'B',"LOW");										//Drive PWM low when reach load value
  PWM_Action_Comparator_Down(0,0,'B',"HIGH");								//Drive PWm high when reach comparator
  PWM_Set_Frequency(0,0,10000,40);											//Set frequency for 10Khz
  PWM_Set_Duty_Cycle(0,0,'B',0);  											//Set duty cycle for 0%
  PWM_Generator_Enable(0,0,"Enable");										//Enable  Generator 0
  PWM_Module_Start(0);														//Start PWM Module 0
  
  for(int i=0;i<3600;i++)													//dummy delay
  {
    for(int j=0;j<3600;j++)
    {
    
    }
  
  }
  
    PWM_Set_Duty_Cycle(0,0,'B',20);  										//Set Duty cycle for 20%

}
