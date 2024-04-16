/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BUTTON_H
#define __BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include  <stdarg.h>
#include  <stdio.h>
#include "stm32f4xx_hal.h"

typedef enum
{
	BUTTON_MODE_EXTI = 0,
	BUTTON_MODE_POL
}Btn_ModeState;



struct ButtonDef{
	char* name;
	GPIO_TypeDef* Port;
	uint16_t Pin;
	uint32_t DebounceDelay;
	 _Bool isActive;
};


#define BUTTON_NUM 5
#define DEBOUNCE_DELAY 25000

void Btn_Init(GPIO_TypeDef* Port, uint16_t Pin, Btn_ModeState ExtIEnable,char* name);
GPIO_PinState Btn_getState (GPIO_TypeDef* Port, uint16_t Pin);
int Btn_Callback(uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* __BUTTON_H */
