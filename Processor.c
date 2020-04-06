
#include "Processor.h"
typedef void (*switchprev_CBK)(void);
void set_cbk(switchprev_CBK pf);
void TOPREVILLIGE(void);
switchprev_CBK cbk_func;
void switch_prev(uint8_t u8_level)
{
	uint8_t RE=0;

			switch (u8_level)
			{
				case PREVILLIGE:
            set_cbk(TOPREVILLIGE);					
						asm("SVC #0");
				     break;
				
				case UNPREVILLIGE:       				
						asm("MOV    RE,#0X00000001");
						asm("MSR	   CONTROL, RE");
				break;
			}
}


int SVC_Handler(void)
{
		cbk_func();
	
	return 0;
}
void set_cbk(switchprev_CBK pf)
{

	cbk_func=pf;

}
void TOPREVILLIGE(void)
{
		
				uint8_t RE=0;
				asm("MOV    RE,#0X00000000");
				asm("MSR	   CONTROL, RE");
		    return ;
}