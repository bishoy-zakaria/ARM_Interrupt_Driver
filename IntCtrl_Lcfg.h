#ifndef IntCtrl_Lcfg_H
#define IntCtrl_Lcfg_H
#include "IntCtrl_Types.h"
typedef struct 
{
	int Interrupt_name     =0;
	int Groub_Priority     =0;
	int Sub_Groub_Priority =0;

}IntCtrl;

/* ************************ Cofiguration ********************* */

#define Interrupts_Max_Number          3

#define Interrupt_Priority_Levels     0x07 // 0x00 "XXX"
                                          //  0x05 "XXY"      
                                         //   0X06 "XYY"
										//    0x07 "YYY"
/* **************************************************************** */

IntCtrl IntCtrl_Config [Interrupts_Max_Number] =
{
/*  {Interrupt name ,  Groub priorirt , Sub groub priority} */

	{GPIO_Port_A    ,     1           ,   0               },
	{GPIO_Port_B    ,     2           ,   1               },
	{GPIO_Port_C    ,     3           ,   1               }
	
}


#endif