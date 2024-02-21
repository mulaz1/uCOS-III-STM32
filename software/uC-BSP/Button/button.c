#include "button.h"



unsigned int BSP_LED_GetState(unsigned int led)
{
    switch (led)
    {
        case 0:
            return HAL_GPIO_ReadPin(LED0_GPIO_Port, LED0_Pin) == GPIO_PIN_RESET;
            break;
        case 1:
            return HAL_GPIO_ReadPin(GPIOC, LED1_Pin) == GPIO_PIN_RESET;
            break;
        case 2:
            return HAL_GPIO_ReadPin(GPIOC, LED2_Pin) == GPIO_PIN_RESET;
            break;
        case 3:
            return HAL_GPIO_ReadPin(GPIOC, LED3_Pin) == GPIO_PIN_RESET;
            break;
        case 4:
            return HAL_GPIO_ReadPin(GPIOC, LED4_Pin) == GPIO_PIN_RESET;
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




void BSP_PB_Init(unsigned int button, ButtonMode_TypeDef ButtonMode)
{
    GPIO_InitTypeDef gpio_init;

    //static BSP_EXTI_LineCallback ButtonCallback[4] = {BUTTON_EXTI_Callback};
    //static uint32_t BSP_BUTTON_PRIO [4] = {BSP_BUTTON_USER_IT_PRIORITY};
    //static const uint32_t BUTTON_EXTI_LINE[4] = {BUTTON_USER_EXTI_LINE};

    __HAL_RCC_GPIOA_CLK_ENABLE();

    gpio_init.Pin = BTN3_Pin|BTN2_Pin|BTN1_Pin|BTN0_Pin;
    gpio_init.Pull = GPIO_NOPULL;
    gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;


    if (ButtonMode == BUTTON_MODE_GPIO)  /* Configure Button pin as input */
        gpio_init.Mode = GPIO_MODE_INPUT;
    else /* if (ButtonMode == BUTTON_MODE_EXTI) */
    { /* Configure Button pin as input with External interrupt */
        gpio_init.Mode = GPIO_MODE_IT_RISING;
        HAL_GPIO_EXTI_IRQHandler(BTN3_Pin|BTN2_Pin|BTN1_Pin|BTN0_Pin);
        HAL_GPIO_EXTI_Callback(BTN3_Pin|BTN2_Pin|BTN1_Pin|BTN0_Pin);
        /* Enable and set Button EXTI Interrupt to the configurable priority */
        HAL_NVIC_SetPriority((EXTI0_IRQn), 0x0F,0x00);  //__HAL_GPIO_EXTI_GET_IT
        HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    }

    HAL_GPIO_Init(GPIOA, &gpio_init);

}

int BSP_PB_GetState (unsigned int button)
{
 return HAL_GPIO_ReadPin(GPIOA, BTN3_Pin|BTN2_Pin|BTN1_Pin|BTN0_Pin);
}

