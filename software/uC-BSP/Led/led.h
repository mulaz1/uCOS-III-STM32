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


#include  <stdarg.h>
#include  <stdio.h>
#include "stm32f4xx.h"
#include "main.h"


#define HIGH 1
#define LOW 0

void         BSP_LED_Init 				 (void);

void  		 BSP_LED_On 				 (unsigned int led);

void  		 BSP_LED_Off 				 (unsigned int led);

void  		 BSP_LED_Toggle 			 (unsigned int led);
