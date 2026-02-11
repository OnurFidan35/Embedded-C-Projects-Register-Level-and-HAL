/*
 * buttondriver.c
 *
 *  Created on: Dec 20, 2025
 *      Author: Onur Fidan
 */
#include "stm32f4xx_hal.h"

void buttondriver_init(){

	RCC->AHB1ENR |= (1<<0);
	GPIOA->MODER &= ~(1<<1);
	GPIOA->MODER &= ~(1<<0);
	GPIOA->OSPEEDR &= ~(1<<0);
	GPIOA->OSPEEDR &= ~(1<<1);
	GPIOA->OTYPER &=~(1<<0);

}

void ButtonDriverIRQ_init(){
	//CLOCK SETTINGS
	RCC->AHB1ENR |= (1<<0); // A port clok enable
    __HAL_RCC_SYSCFG_CLK_ENABLE();

    //GPIO SETTINGS
    GPIOA->MODER &= ~(1<<1);
    GPIOA->MODER &= ~(1<<0);
    GPIOA->PUPDR &= ~(3<<0);

    //EXTI SETTINGS
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA; // |= 0x0000U ile aynı şey st burada bize kolaylık sağlıyor
    EXTI->IMR |= EXTI_IMR_MR0; // |= (1<<0) ile aynı şey
    EXTI->RTSR |= EXTI_RTSR_TR0;

    //NVIC SETTINGS
    NVIC_SetPriority(EXTI0_IRQn,1);
    NVIC_EnableIRQ(EXTI0_IRQn);
}
int buttondriver_get_state(){

	return (GPIOA->IDR & (1<<0));

}


void EXTI0_IRQHandler(void){

	if((EXTI->PR & EXTI_PR_PR0)==EXTI_PR_PR0){  //bu fonksiyon zaten sadece EXTI0 hatti için yani birden fazla hatta bağlı değil

		                                           // gerek yok ama birden fazla hatta bağlı fonksiyonlar için kontrol bu şekilde
											  // pending registerın ilgili bitine(flag) bakılır
		EXTI->PR |= EXTI_PR_PR0; //Flaga tekrardan 1 yazarak 0 yaptık(dokumanda reset için tekrar 1 yazın diyor 0 değil)

		for(volatile uint32_t i = 0; i < 50000; i++); // ark gürültüsü mü 5 10 ms bekle
		if((GPIOA->IDR & (1 << 0))){ //hala basılıysa gürültü değil
		GPIOD->ODR ^=(1<<12);
		GPIOD->ODR ^=(1<<14);
		GPIOD->ODR ^=(1<<15);
		GPIOD->ODR ^=(1<<13);
		}
	}


}

