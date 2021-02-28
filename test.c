#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"
#include "non_blocking_timer.h"

const uint LED_PIN = 25;

non_blocking_timer_handler led_timer; // create user timer struct 

void toggle_led()
{
	gpio_put(LED_PIN, !gpio_get(LED_PIN));
}

int main()
{
	stdio_init_all(); 
	init_non_blocking_timer(&led_timer, 1000); //initalise ledtimer for a 1second period 
	init_systick();                            //init and enable systick 

	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN,GPIO_OUT);
	start_non_blocking_timer(&led_timer);	
	while(1)
	{
		if(non_blocking_timer_expired(&led_timer) == TIMER_EXPIRED) 
		{
			printf("systick %ld\r\n",get_systick()); //Print out systick value 
			toggle_led();                            //Toggle LED 1s On 1s OFF
			start_non_blocking_timer(&led_timer);    //restart 1s timer 
		}
	}
}

