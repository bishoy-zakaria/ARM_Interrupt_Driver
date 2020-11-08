#include "Int_Ctrl.h"

extern IntCtrl_InterruptCfgType IntCtrl_InterruptCfg[];


void IntCtrl_init (void)
{
	__asm "SVC,#imm"
	
	
    for(i=0; i<Interrupts_Max_Number;i++)
	{
		IntCtrl_InterruptType   Loc_InterruptNum = IntCtrl_Config[i].Interrupt_name;
		IntCtrl_GroupPriType    Loc_GroupPri     = IntCtrl_Config[i].Groub_Priority;
		IntCtrl_SubGroupPriType Loc_SubGroupPri	 = IntCtrl_Config[i].Sub_Groub_Priority;
		
		/*TODO ENABLE\disable configured Interrupts*/
		
		Register_offset = Loc_InterruptNum/32;
		Bit_offset = Loc_InterruptNum%32;
		RegisterVal = NVIC_EN(Register_offset);
		
		Set_Bit(RegisterVal,Bit_offset);
		/* ******************* priority **************************** */
		
		#if Interrupt_Priority_Levels   ==  0x00
		{
		  uint32 Key = 0x05FA;
		  uint16 Priority_mode=0;
		  uint16 Pri_Offset=0 ;
		  uint32 priority=0;
		  
		  Key << = 16;
		  Intrrupt_Ctrl |= Key; // key
		  
		  Priority_mode = Interrupt_Priority_Levels;
		  Priority_mode << = 8;
		  Intrrupt_Ctrl |= Priority_mode; // xxx
		  
		  Pri_Offset =(Loc_InterruptNum%32)*8 + 5;
		  Priority_regs_Offset = Loc_InterruptNum/4;
		  
		  priority = Loc_GroupPri;
		  priority << = Pri_Offset;
		  
	      NVIC_PRI( Priority_regs_Offset) |= priority ;
		  
		  #endif
		}
		
		#elif Interrupt_Priority_Levels   ==  0x5
		{
		  uint32 Key = 0x05FA;
		  uint16 Priority_mode=0;
		  uint16 Pri_Offset=0 ;
		  uint32 priority=0;
		  
		  Key << = 16;
		  Intrrupt_Ctrl |= Key; // key
		  
		  Priority_mode = Interrupt_Priority_Levels;
		  Priority_mode << =8;
		  Intrrupt_Ctrl |= Priority_mode; // YYY
		  
		  Pri_Offset =(Loc_InterruptNum%32)*8 + 5;
		  Priority_regs_Offset = Loc_InterruptNum/4;
		  
		  priority= Loc_GroupPri;
		  priority << = Pri_Offset;
		  
	      NVIC_PRI( Priority_regs_Offset) |= priority ;
		  
		  #endif
		}
		
		 
		
	}
}


void SVC_Call(void)
{
	__asm "AND   CONTROL, CONTROL, #0x04"

	
}