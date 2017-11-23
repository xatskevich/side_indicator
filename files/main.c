
#include "main.h"

uint16_t level, min, max, koeff, koef_perc;
uint8_t lvl_out, percent, can_ctrl, can_error, can_error_mask, morg, press, w_morg;

CanTxMsg TxMessage;
GPIO_InitTypeDef GPIO_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
CAN_InitTypeDef CAN_InitStructure;
CAN_FilterInitTypeDef CAN_FilterInitStructure;


int main(void)
{

	Init_IWDG();			//сторожевой

	Init_RCC();			//тактирование блоков
//	delay_ms(1);
	Init_GPIO();		//инициализация портов

	Init_CAN();
	Init_Timer();

	//GPIO_SetBits(GPIOB, GPIO_Pin_0);
	GPIO_SetBits(GPIOA, GPIO_Pin_2);

    while(1)
    {

    }
}
