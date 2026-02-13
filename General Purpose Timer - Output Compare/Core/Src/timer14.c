/*
 * timer14.c
 *
 *  Created on: Feb 13, 2026
 *      Author: Onur Fidan
 */


#include <timer14.h>
#include "stm32f4xx_hal.h"




void timer14_init(void){

	 oc_led_init();

	//Enable TIM6 Clock
	__HAL_RCC_TIM14_CLK_ENABLE();

	// Timer clock=168mhz/168000=1000hz(1ms period)
	TIM14->PSC=167999;


	//OUTPUT COMPARE MODE
	TIM14->CCMR1&= ~TIM_CCMR1_CC1S_0;
	TIM14->CCMR1&= ~TIM_CCMR1_CC1S_1;

	//OUTPUT COMPARE MODE - TOGGLE ON MATCH
	TIM14->CCMR1 |= TIM_CCMR1_OC1M_0;
	TIM14->CCMR1 |= TIM_CCMR1_OC1M_1;
	TIM14->CCMR1 &=~TIM_CCMR1_OC1M_2;

	//ENABLE OC1REF OUTPUT
	TIM14->CCER |=TIM_CCER_CC1E;

	//OUTPUT POLARITY : ACTIVE HIGH
	TIM14->CCER |=TIM_CCER_CC1P;


	// Reload in every 100 ms
	TIM14->ARR=99;
	TIM14->CCR1=99;





}



uint16_t timer14_capture_set_period(uint16_t ms){

	TIM14->ARR=ms-1;
	TIM14->CCR1=ms-1;

}

void timer14_enable(void){

	TIM14->CR1 |= TIM_CR1_CEN;

}



void timer14_disable(void){

	TIM14->CR1 &= ~(TIM_CR1_CEN);

}


void oc_led_init(void){

	//Enable clock
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//Select mode : Alternate function
	//BIT 14: 0
	//BIT 15: 1
	GPIOA->MODER &= ~(1<<14);
	GPIOA->MODER |=(1<<15);


	//Select output type
	GPIOA->OTYPER  &= ~(1<<7); //Output push pull

	//Medium speed
	GPIOA->OSPEEDR  |= (1<<14);
	GPIOA->OSPEEDR  &= ~(1<<15);

	//No pull up pull down
	GPIOA->PUPDR  &= ~(1<<14);
	GPIOA->PUPDR  &= ~(1<<15);


	//Alternate function: GPIOA - 7 =AF9
	GPIO_AFRL_AFRL0 |= (1<<31);
	GPIO_AFRL_AFRL0  &= ~(1<<30);
	GPIO_AFRL_AFRL0  &= ~(1<<29);
	GPIO_AFRL_AFRL0 |= (1<<28);

}


