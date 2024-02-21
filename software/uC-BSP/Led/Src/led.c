#include "../Inc/led.h"

void BSP_LED_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	/*Configure GPIO pins : LED7_Pin LED6_Pin LED5_Pin */
	GPIO_InitStruct.Pin = LED7_Pin | LED6_Pin | LED5_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED7_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pins : LED4_Pin LED3_Pin LED2_Pin LED1_Pin */
	GPIO_InitStruct.Pin = LED4_Pin | LED3_Pin | LED2_Pin | LED1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(LED4_GPIO_Port, &GPIO_InitStruct);

	/*Configure GPIO pin : LED0_Pin */
	GPIO_InitStruct.Pin = LED0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(LED0_GPIO_Port, &GPIO_InitStruct);

	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, LOW);
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, LOW);
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, LOW);
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, LOW);
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, LOW);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, LOW);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, LOW);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, LOW);
}

static void BSP_LED_On(unsigned int led) {
	switch (led) {
	case 0:
		HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, HIGH);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, HIGH);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, HIGH);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOC, LED4_Pin, HIGH);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED5_Pin, HIGH);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED6_Pin, HIGH);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin, HIGH);
		break;
	default:
		break;
	}
}

static void BSP_LED_Off(unsigned int led) {
	switch (led) {
	case 0:
		HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOC, LED1_Pin, LOW);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOC, LED2_Pin, LOW);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOC, LED3_Pin, LOW);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOC, LED4_Pin, LOW);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED5_Pin, LOW);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED6_Pin, LOW);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin, LOW);
		break;
	default:
		break;
	}
}

void BSP_LED_Toggle(unsigned int led) {
	switch (led) {
	case 0:
		HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);
		HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
		HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
		HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
		HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
		break;
	case 1:
		HAL_GPIO_TogglePin(GPIOC, LED1_Pin);
		break;
	case 2:
		HAL_GPIO_TogglePin(GPIOC, LED2_Pin);
		break;
	case 3:
		HAL_GPIO_TogglePin(GPIOC, LED3_Pin);
		break;
	case 4:
		HAL_GPIO_TogglePin(GPIOC, LED4_Pin);
		break;
	case 5:
		HAL_GPIO_TogglePin(GPIOB, LED5_Pin);
		break;
	case 6:
		HAL_GPIO_TogglePin(GPIOB, LED6_Pin);
		break;
	case 7:
		HAL_GPIO_TogglePin(GPIOB, LED7_Pin);
		break;
	default:
		break;
	}
}

void ledOut(uint8_t value) {
	int i;

	for (i = 0; i < LED_NUM; i++) {
		if (value & (1 << i)) {
			BSP_LED_On(i);
		} else {
			BSP_LED_Off(i);
		}
	}
}

