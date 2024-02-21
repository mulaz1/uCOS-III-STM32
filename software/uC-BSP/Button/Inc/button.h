#include  <stdarg.h>
#include  <stdio.h>
#include "main.h"

#define BUTTON_MODE_EXTI 1

void BSP_PB_Init(_Bool ExtiEnable, GPIO_TypeDef* Port, uint16_t Pin);
int BSP_PB_GetState (GPIO_TypeDef* Port, uint16_t Pin);
int BSP_BTN_Callback(uint16_t GPIO_Pin);
