
#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f0xx.h"                  // Device header
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_can.h"
#include "stm32f0xx_misc.h"
#include "stm32f0xx_iwdg.h"

#include "CAN.h"
#include "GPIO.h"
#include "rcc.h"
#include "timer.h"


extern uint16_t level, min, max, koeff, koef_perc;
extern uint8_t lvl_out, percent, can_ctrl, can_error, can_error_mask, morg, press, w_morg;

extern CanTxMsg TxMessage;
extern GPIO_InitTypeDef GPIO_InitStructure;
extern NVIC_InitTypeDef NVIC_InitStructure;
extern CAN_InitTypeDef CAN_InitStructure;
extern CAN_FilterInitTypeDef CAN_FilterInitStructure;

#endif
