#ifndef LED_INIT_H_
#define LED_INIT_H_

#include "stm32f4xx.h"

#define GREEN_LED_On()			GPIOD->BSRR |= GPIO_BSRR_BS12
#define GREEN_LED_Off()			GPIOD->BSRR |= GPIO_BSRR_BR12
#define GREEN_LED_Toggle()	GPIOD->ODR ^= GPIO_ODR_ODR_12

#define ORANGE_LED_On()			GPIOD->BSRR |= GPIO_BSRR_BS13
#define ORANGE_LED_Off()		GPIOD->BSRR |= GPIO_BSRR_BR13
#define ORANGE_LED_Toggle()	GPIOD->ODR ^= GPIO_ODR_ODR_13

#define RED_LED_On()				GPIOD->BSRR |= GPIO_BSRR_BS14
#define RED_LED_Off()				GPIOD->BSRR |= GPIO_BSRR_BR14
#define RED_LED_Toggle()		GPIOD->ODR ^= GPIO_ODR_ODR_14

#define BLUE_LED_On()				GPIOD->BSRR |= GPIO_BSRR_BS15
#define BLUE_LED_Off()			GPIOD->BSRR |= GPIO_BSRR_BR15
#define BLUE_LED_Toggle()		GPIOD->ODR ^= GPIO_ODR_ODR_15

void LED_Init(void);

#endif /* LED_INIT_H_ */
