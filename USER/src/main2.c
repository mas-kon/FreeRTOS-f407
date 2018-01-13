#include "stm32f407xx.h"
#include "rcc_init.h"
#include "led_init.h"



#define LED1_ON    GPIOD->BSRR=GPIO_BSRR_BS_12
#define LED1_OFF   GPIOD->BSRR=GPIO_BSRR_BR_12

static volatile uint32_t TimingDelay;

/* Delay & timers */
void SysTick_Handler(void) {
 if (TimingDelay) {
        TimingDelay--;
    }    
  }
    
void Delay_mS(uint32_t nTime) {
    TimingDelay = nTime;
    while (TimingDelay);
  }

int main (void) 
{

	RCC_Init();
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock /1000);

	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;
  GPIOD->MODER &= ~GPIO_MODER_MODER12 ;
  GPIOD->MODER |= GPIO_MODER_MODER12_0 ;
	
	while(1)
	{
     LED1_ON ;
     Delay_mS(500);
     LED1_OFF ;
     Delay_mS(500);
	}
}
