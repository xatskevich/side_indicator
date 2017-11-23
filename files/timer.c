
#include "main.h"

void TIM14_IRQHandler(void){	//620мс

	TIM14->SR &= ~TIM_SR_UIF;	//сброс флага

	can_error = 0;
	if(can_ctrl == 1){	//если в течение 620мс не было CAN сообщений
		can_error = 1;		//выставляем ошибку
		can_error_mask ^= 1;	//маска моргания индикаторами
		if(can_error_mask) GPIOA -> BSRR = 0xf8;
		else GPIOA -> BRR = 0xf8;
	}

	can_ctrl = 1;

	morg ^= 1;		//моргалка

	//	GPIOA -> ODR ^= 0xf8;
	//	GPIOB -> ODR ^= 1;
	IWDG_ReloadCounter();
}


void Init_Timer(){

	//таймер контроля CAN
	TIM14->PSC = 2399;
	TIM14->ARR = 6200;		//период 620мс
	TIM14->DIER |= TIM_DIER_UIE;
	TIM14->CR1 |= TIM_CR1_CEN;

	//вектор
	NVIC_InitStructure.NVIC_IRQChannel = TIM14_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPriority = 0x01;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}
