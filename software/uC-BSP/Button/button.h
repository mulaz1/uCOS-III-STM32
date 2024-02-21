#include  <stdarg.h>
#include  <stdio.h>
#include "stm32f4xx.h"
#include "main.h"



typedef enum
{
 BUTTON_MODE_GPIO = 0,
 BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

void BSP_PB_Init(unsigned int button, ButtonMode_TypeDef ButtonMode);
int BSP_PB_GetState (unsigned int button);