#include "Clock_Driver.h"
#include "GPIO_Driver.h"
#include "PWM_Driver.h"
#include "Debug_Driver.h"

void main()
{
  Debug_Intialization();
  
  Set_Clock_MHz(16,80);
  CLK_PWM_Enable(0);
  CLK_Enable('B');
  PIN_FUNCTION_SELECT('B',7,"Alternative");
  PIN_CONFIGURE('B',7,"PWM");
  PIN_ANALOG_DIGITAL('B',7,"Digital");
  Use_PWM_Divisor(80,40);
  PWM_Generator_Enable(0,0,"Disable");
  PWM_Action_For_Load(0,0,'B',"LOW");
  PWM_Action_Comparator_Down(0,0,'B',"HIGH");
  PWM_Set_Frequency(0,0,10000,40);
  PWM_Set_Duty_Cycle(0,0,'B',0);  
  PWM_Generator_Enable(0,0,"Enable");
  PWM_Module_Start(0);
  
  for(int i=0;i<3600;i++)
  {
    for(int j=0;j<3600;j++)
    {
    
    }
  
  }
  
    PWM_Set_Duty_Cycle(0,0,'B',20);  

}
