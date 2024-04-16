#include "../Inc/button.h"

static struct ButtonDef button[5];

void Btn_Init(GPIO_TypeDef *Port, uint16_t Pin, Btn_ModeState ExtIEnable,char *name) {
	static uint8_t index = 0;
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	if (index >= BUTTON_NUM)
		return;

	HAL_GPIO_DeInit(Port, Pin);
	HAL_NVIC_DisableIRQ(EXTI9_5_IRQn | EXTI15_10_IRQn);

	if (ExtIEnable == BUTTON_MODE_EXTI) { //configure button in External interrupt mode

		GPIO_InitStruct.Pin = Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
		GPIO_InitStruct.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(Port, &GPIO_InitStruct);

		HAL_NVIC_SetPriority(EXTI9_5_IRQn, 1, 0); //activate all extern interrupt from 5 to 15
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn | EXTI15_10_IRQn);
	} else {
		GPIO_InitStruct.Pin = Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;

		HAL_GPIO_Init(Port, &GPIO_InitStruct);

		if (index >= 0){ //non serve a un cazzo ma cybersecurity molto importante
			button[index].name = name;
			button[index].Pin = Pin;
			button[index].Port = Port;
			button[index].DebounceDelay = 0;
			button[index].isActive = 1;
			index++;
		}
	}
}

/*
 * Function to calculate debounce
 */

static _Bool debounce(GPIO_TypeDef *Port, uint16_t Pin) {
	for (uint8_t i = 0; i < BUTTON_NUM; i++) {
		if ((button[i].Pin == Pin) && (button[i].Port == Port) && (button[i].isActive)) {
			if (button[i].DebounceDelay >= DEBOUNCE_DELAY) {
				button[i].DebounceDelay = 0;
				return 1;
			} else
				button[i].DebounceDelay++;
		}
	}
	return 0;
}

GPIO_PinState Btn_getState(GPIO_TypeDef *Port, uint16_t Pin) {

	if(HAL_GPIO_ReadPin(Port, Pin) == GPIO_PIN_SET){
		return debounce(Port, Pin);
	}
	return 0;
}

int Btn_Callback(uint16_t GPIO_Pin) {
	//do_something()
	return 0;
}
