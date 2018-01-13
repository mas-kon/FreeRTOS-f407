#include "stm32f4xx.h"
#include "delay.h"

static volatile uint32_t TimingDelay;

/* Delay & timers */
void SysTick_Handler(void) {
 if (TimingDelay) {
        TimingDelay--;
    }    
  }
    
void Delay(uint32_t nTime) {
    TimingDelay = nTime;
    while (TimingDelay);
  }
