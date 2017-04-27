// SysTick.c
// Implements two busy-wait based delay routines
#include <stdint.h>
// Initialize SysTick with busy wait running at bus clock.
#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))
void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0;                   // disable SysTick during setup
  NVIC_ST_RELOAD_R = 0x00FFFFFFF;       // maximum reload value
  NVIC_ST_CURRENT_R = 0;                // write to current to clear it
                                        // enable SysTick with core clock
  NVIC_ST_CTRL_R = 0x0005;
}
// The delay parameter is in units of the 80 MHz core clock. (12.5 ns)
void SysTick_Wait(uint32_t delay){
	volatile uint32_t eTime; //elasped time
	uint32_t sTime = NVIC_ST_CURRENT_R;
	do{
		eTime= (sTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
	}
	while(eTime<=delay);
	

}

// Time delay using busy wait.
// waits for count*10ms
// 10000us equals 10ms
void SysTick_Wait10ms(uint32_t delay){
	uint32_t i;
	for(i=0;i<delay;i++)
	{
		SysTick_Wait(80000); //10ms is 800000 cycles with a 80MH core clock
	}
	

}