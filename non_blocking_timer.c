#include <stdio.h>
#include "pico/stdlib.h"
#include "non_blocking_timer.h"
#include "hardware/structs/systick.h"

sys_timer systick;

void init_systick()
{ 
	systick_hw->csr = 0; 	    //Disable 
	systick_hw->rvr = 124999UL; //Standard System clock (125Mhz)/ (rvr value + 1) = 1ms 
        systick_hw->csr = 0x7;      //Enable Systic, Enable Exceptions	
}

extern void isr_systick() //Rewrite of weak systick IRQ in crt0.s file
{
	systick.u32_tick_count++;     
}

uint32_t get_systick()
{
	return systick.u32_tick_count;
}

void init_non_blocking_timer(non_blocking_timer_handler *timer , uint32_t u32_time_period_ms,uint8_t u8_user_mode)
{
	timer->u32_t0_ms = 0U;
	timer->u32_timer_period = u32_time_period_ms;
	timer->timer_enabled = false;
	timer->u8_mode = u8_user_mode;
}

void start_non_blocking_timer(non_blocking_timer_handler *timer)
{
	timer->u32_t0_ms = get_systick();
	timer->timer_enabled = true;	
}

void stop_non_blocking_timer(non_blocking_timer_handler *timer)
{
	timer->timer_enabled = false;
}

uint8_t non_blocking_timer_expired(non_blocking_timer_handler *timer)
{
	if(timer->timer_enabled == true)
	{
		if ((get_systick() - timer->u32_t0_ms) >= timer->u32_timer_period) //accounts for buffer overflow
		{
			if (timer->u8_mode == CONTINOUS_MODE)
			{
				start_non_blocking_timer(timer); //Restart Timer for user in Continuous mode
			}
			return TIMER_EXPIRED;
		}
		else
		{
			return TIMER_NOT_EXPIRED;
		}
	}
	return TIMER_NOT_ENABLED;
}
