#include "../Inc/button.h"

void Btn_Init(GPIO_TypeDef* Port, uint16_t Pin, Btn_ModeState ExtIEnable)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	HAL_GPIO_DeInit(Port,Pin);
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn|EXTI15_10_IRQn);

	if(ExtIEnable == BUTTON_MODE_EXTI){     //configure button in External interrupt mode

		GPIO_InitStruct.Pin = Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
		GPIO_InitStruct.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(Port, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0);   //activate all extern interrupt from 5 to 15
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn|EXTI15_10_IRQn);
	}
	else{
		GPIO_InitStruct.Pin = Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(Port, &GPIO_InitStruct);
	}
}

GPIO_PinState Btn_getState (GPIO_TypeDef* Port, uint16_t Pin)
{

//add anti balancing algorithm
 return HAL_GPIO_ReadPin(Port, Pin);
}


int Btn_Callback(uint16_t GPIO_Pin){
	//do_something()
	return 0;
}
