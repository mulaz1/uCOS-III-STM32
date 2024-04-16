/*
 *********************************************************************************************************
 *
 *                                        BOARD SUPPORT PACKAGE
 *
 *                                     ST Microelectronics STM32
 *                                              on the
 *
 *                                     Micrium uC-Eval-STM32F107
 *                                        Evaluation Board
 */

#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif
#include  <stdarg.h>
#include  <stdio.h>

#include "stm32f4xx_hal.h"

#define LED_NUM 8

void Led_Init(void);

//void  		 BSP_LED_On 				 (unsigned int led);
//
//void  		 BSP_LED_Off 				 (unsigned int led);

void BSP_LED_Toggle(unsigned int led);
void ledOut(uint8_t value);

#ifdef __cplusplus
}
#endif

#endif /* __LED_H */
