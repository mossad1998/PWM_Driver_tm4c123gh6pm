#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "tm4c123gh6pm.h"
#include <string.h>
#include "Debug_Driver.h"



#ifndef __PWM_Driver_H__
#define __PWM_Driver_H__


extern void CLK_PWM_Enable(int PWM_module);                                                              //Clock for the module
extern void Use_PWM_Divisor(int System_Clock,int PWM_Clock);                                             //To set PWM Clock
extern void PWM_Generator_Enable(int PWM_module,int Generator,char type[10]);                            //Enable or Disable specific Generator
extern void PWM_Action_For_Load(int PWM_module,int Generator,char Comparator,char type[10]);             //Action to be taken when the counter matches the value in the load register
extern void PWM_Action_Comparator_Down(int PWM_module,int Generator,char Comparator,char type[10]);      //Action to be taken when the counter matches the value in the Comparator
extern void PWM_Set_Frequency(int PWM_module,int Generator,int Frequency,int PWM_Clock_MHz);             //Set the Frequency for the pwm
extern void PWM_Set_Duty_Cycle(int PWM_module,int Generator,char Comparator,int Duty);                   //To determine the duty cycle
extern void PWM_Module_Start(int PWM_module);                                                            //To start the pwm Module

#endif
