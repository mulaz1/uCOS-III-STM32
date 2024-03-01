/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "uCOS-III/Source/os.h"
#include "uC-CPU/cpu_core.h"
#include "uC-BSP/Display/Inc/fonts.h"
#include "uC-BSP/Display/Inc/ILI9341.h"
#include "uC-BSP/Display/Inc/ILI9341_test.h"
#include "uC-BSP/Display/Inc/XPT2046.h"
#include "uC-BSP/Display/Inc/XPT2046_test.h"
#include "uC-BSP/Display/Inc/XPT2046_menu.h"


//LEDs and BUTTONs
#include "uC-BSP/Button/Inc/button.h"
#include "uC-BSP/Led/Inc/led.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
HAL_StatusTypeDef COM_port_serial_print(const uint8_t* data);
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TOUCH_CS_Pin GPIO_PIN_13
#define TOUCH_CS_GPIO_Port GPIOC
#define DISPL_DC_Pin GPIO_PIN_0
#define DISPL_DC_GPIO_Port GPIOC
#define TOUCH_MOSI_Pin GPIO_PIN_1
#define TOUCH_MOSI_GPIO_Port GPIOC
#define TOUCH_MISO_Pin GPIO_PIN_2
#define TOUCH_MISO_GPIO_Port GPIOC
#define TOUCH_INT_Pin GPIO_PIN_3
#define TOUCH_INT_GPIO_Port GPIOC
#define TOUCH_INT_EXTI_IRQn EXTI3_IRQn
#define DISPL_SCK_Pin GPIO_PIN_5
#define DISPL_SCK_GPIO_Port GPIOA
#define DISPL_MISO_Pin GPIO_PIN_6
#define DISPL_MISO_GPIO_Port GPIOA
#define DISPL_MOSI_Pin GPIO_PIN_7
#define DISPL_MOSI_GPIO_Port GPIOA
#define DISPL_CS_Pin GPIO_PIN_4
#define DISPL_CS_GPIO_Port GPIOC
#define TOUCH_SCK_Pin GPIO_PIN_10
#define TOUCH_SCK_GPIO_Port GPIOB
#define DISPL_RST_Pin GPIO_PIN_12
#define DISPL_RST_GPIO_Port GPIOB
#define LED7_Pin GPIO_PIN_13
#define LED7_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_14
#define LED5_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_15
#define LED4_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOC
#define LED6_Pin GPIO_PIN_7
#define LED6_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOC
#define LED0_Pin GPIO_PIN_8
#define LED0_GPIO_Port GPIOA
#define BTN3_Pin GPIO_PIN_9
#define BTN3_GPIO_Port GPIOA
#define BTN3_EXTI_IRQn EXTI9_5_IRQn
#define BTN2_Pin GPIO_PIN_10
#define BTN2_GPIO_Port GPIOA
#define BTN2_EXTI_IRQn EXTI15_10_IRQn
#define BTN1_Pin GPIO_PIN_11
#define BTN1_GPIO_Port GPIOA
#define BTN1_EXTI_IRQn EXTI15_10_IRQn
#define BTN0_Pin GPIO_PIN_12
#define BTN0_GPIO_Port GPIOA
#define BTN0_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
