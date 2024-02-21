#include "../Inc/button.h"

void BSP_PB_Init(_Bool ExtiEnable, GPIO_TypeDef* Port, uint16_t Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	HAL_GPIO_DeInit(Port,Pin);
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn|EXTI15_10_IRQn);

	if(ExtiEnable == BUTTON_MODE_EXTI){     //configure button in External interrupt mode

		GPIO_InitStruct.Pin = Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
		GPIO_InitStruct.Pull = GPIO_PULLUP;

		HAL_GPIO_Init(Port, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);   //activate all extern interrupt from 5 to 15
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn|EXTI15_10_IRQn);
	}
	else{
		GPIO_InitStruct.Pin = Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;

		HAL_GPIO_Init(Port, &GPIO_InitStruct);
	}
}

int BSP_PB_GetState (GPIO_TypeDef* Port, uint16_t Pin)
{
 return HAL_GPIO_ReadPin(Port, Pin);
}


int BSP_BTN_Callback(uint16_t GPIO_Pin){
	//do_something()
	return 0;
}
