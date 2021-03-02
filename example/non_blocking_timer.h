#ifndef NON_BLOCKING_TIMER_H
#define NON_BLOCKING_TIMER

#define TIMER_NOT_EXPIRED 0U
#define TIMER_EXPIRED     1U
#define TIMER_NOT_ENABLED 2U

typedef struct
{
	uint32_t u32_tick_count;
}sys_timer;

typedef struct
{
	uint32_t u32_t0_ms;       //Stores start time 
	uint32_t u32_timer_period; 
	bool timer_enabled;
}non_blocking_timer_handler;

void init_systick();
uint32_t get_systick();
void init_non_blocking_timer(non_blocking_timer_handler *timer, uint32_t time_period);
void start_non_blocking_timer(non_blocking_timer_handler *timer);
void stop_non_blocking_timer(non_blocking_timer_handler *timer);
uint8_t non_blocking_timer_expired(non_blocking_timer_handler *timer);  
#endif 
