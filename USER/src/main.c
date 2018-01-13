#include "stm32f407xx.h"
#include "main.h"
#include "led_init.h"
#include "rcc_init.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void vTaskBlinkGreen (void *argument);
void vTaskBlinkOrange (void *argument);
void vTaskBlinkRed (void *argument);
void vTaskBlinkBlue (void *argument);

int main(void)
{

	RCC_Init();
	LED_Init();

	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);
	
	xTaskCreate(vTaskBlinkGreen, "Blink Green", 32, NULL, 2, NULL);
	xTaskCreate(vTaskBlinkOrange, "Blink Orange", 32, NULL, 2, NULL);
	xTaskCreate(vTaskBlinkRed, "Blink Red", 32, NULL, 2, NULL);
	xTaskCreate(vTaskBlinkBlue, "Blink Blue", 32, NULL, 2, NULL);
	
	vTaskStartScheduler();
	
	
	while (1)
	{

	}
	
}

/* ==================================================================== */

void vTaskBlinkGreen (void *argument){
	while (1)
	{
		GREEN_LED_On();
			vTaskDelay(TIMER_ON);
		GREEN_LED_Off();
			vTaskDelay(TIMER_ON);
	}
}
		
void vTaskBlinkOrange (void *argument){
	while (1)
	{
		ORANGE_LED_Off();
			vTaskDelay(TIMER_ON);
		ORANGE_LED_On();
			vTaskDelay(TIMER_ON);
	}
}

void vTaskBlinkRed (void *argument){
	while (1)
	{
		RED_LED_On();
			vTaskDelay(TIMER_ON);
		RED_LED_Off();
			vTaskDelay(TIMER_ON);
	}
}

void vTaskBlinkBlue (void *argument){
	while (1)
	{
		BLUE_LED_Off();
			vTaskDelay(TIMER_ON);
		BLUE_LED_On();
			vTaskDelay(TIMER_ON);
	}
}
