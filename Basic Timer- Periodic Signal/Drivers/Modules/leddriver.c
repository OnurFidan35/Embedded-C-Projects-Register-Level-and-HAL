/*
 * leddriver.c
 *
 *  Created on: Dec 20, 2025
 *      Author: Onur Fidan
 */
#include "stm32f4xx_hal.h"

void leddriver_init(void){
	RCC->AHB1ENR |= (1<<3);
	GPIOD->MODER &= ~(1<<27);
	GPIOD->MODER |=  (1<<26);
	GPIOD->MODER &= ~(1<<25);
	GPIOD->MODER |=  (1<<24);
	GPIOD->MODER &= ~(1<<29);
	GPIOD->MODER |=  (1<<28);
	GPIOD->MODER &= ~(1<<31);
	GPIOD->MODER |=  (1<<30);
	GPIOD->OSPEEDR &= ~(1<<27);
	GPIOD->OSPEEDR &= ~(1<<26);
	GPIOD->OSPEEDR &= ~(1<<25);
	GPIOD->OSPEEDR &= ~(1<<24);
	GPIOD->OSPEEDR &= ~(1<<29);
	GPIOD->OSPEEDR &= ~(1<<28);
	GPIOD->OSPEEDR &= ~(1<<31);
	GPIOD->OSPEEDR &= ~(1<<30);
	GPIOD->OTYPER &=~(1<<13);
	GPIOD->OTYPER &=~(1<<12);
	GPIOD->OTYPER &=~(1<<14);
	GPIOD->OTYPER &=~(1<<15);


}
void leddriver_on(void){

	GPIOD->ODR |=(1<<13);
	GPIOD->ODR |=(1<<12);
	GPIOD->ODR |=(1<<14);
	GPIOD->ODR |=(1<<15);

}
void leddriver_off(void){

	GPIOD->ODR &=~(1<<13);
	GPIOD->ODR &=~(1<<12);
	GPIOD->ODR &=~(1<<14);
	GPIOD->ODR &=~(1<<15);

}
