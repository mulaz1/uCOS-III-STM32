#include "led.h"

#define  BSP_LED_START_BIT  (13 - 1)                            /* LEDs[3:1] are sequentially connected to PTD[15:13].  */


void  BSP_LED_Init (void)
{
    GPIO_InitTypeDef  gpio_init;


    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();


    gpio_init.Pin   = GPIO_PIN_0|LED4_Pin|LED3_Pin|LED2_Pin|LED1_Pin|LED7_Pin|LED6_Pin|LED5_Pin;
    gpio_init.Speed = GPIO_SPEED_FREQ_LOW;
    gpio_init.Mode  = GPIO_MODE_OUTPUT_PP;
    gpio_init.Pull  = GPIO_NOPULL;

    HAL_GPIO_Init(GPIOB, &gpio_init);
    HAL_GPIO_Init(GPIOC, &gpio_init);
    HAL_GPIO_Init(LED0_GPIO_Port, &gpio_init);

    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|LED4_Pin|LED3_Pin|LED2_Pin|LED1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, LED7_Pin|LED6_Pin|LED5_Pin, GPIO_PIN_RESET);

}


void  BSP_LED_On (unsigned int led)
{
    switch (led) {
        case 0:
            HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOB, LED7_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOB, LED6_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOB, LED5_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOB, LED7_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOC, LED4_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOC, LED3_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOC, LED2_Pin, HIGH);
            HAL_GPIO_WritePin(GPIOC, LED1_Pin, HIGH);
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




void  BSP_LED_Off (unsigned int led)
{
    switch (led) {
        case 0:
        	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, LOW);
            HAL_GPIO_WritePin(GPIOB, LED7_Pin, LOW);
            HAL_GPIO_WritePin(GPIOB, LED6_Pin, LOW);
            HAL_GPIO_WritePin(GPIOB, LED5_Pin, LOW);
            HAL_GPIO_WritePin(GPIOB, LED7_Pin, LOW);
            HAL_GPIO_WritePin(GPIOC, LED4_Pin, LOW);
            HAL_GPIO_WritePin(GPIOC, LED3_Pin, LOW);
            HAL_GPIO_WritePin(GPIOC, LED2_Pin, LOW);
            HAL_GPIO_WritePin(GPIOC, LED1_Pin, LOW);
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





void  BSP_LED_Toggle (unsigned int led)
{
    switch (led) {
        case 0:
            HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
            HAL_GPIO_TogglePin(GPIOC, LED1_Pin);
            HAL_GPIO_TogglePin(GPIOC, LED2_Pin);
            HAL_GPIO_TogglePin(GPIOC, LED3_Pin);
            HAL_GPIO_TogglePin(GPIOC, LED4_Pin);
            HAL_GPIO_TogglePin(GPIOB, LED5_Pin);
            HAL_GPIO_TogglePin(GPIOB, LED6_Pin);
            HAL_GPIO_TogglePin(GPIOB, LED7_Pin);
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

