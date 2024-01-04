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
<<<<<<< HEAD
=======
#define Led_test_Pin GPIO_PIN_5
#define Led_test_GPIO_Port GPIOA
>>>>>>> stable_version
#define LED7_Pin GPIO_PIN_13
#define LED7_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_14
#define LED6_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_15
#define LED5_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_6
#define LED4_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_7
#define LED3_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_8
#define LED2_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_9
#define LED1_GPIO_Port GPIOC
#define LED0_Pin GPIO_PIN_8
#define LED0_GPIO_Port GPIOA
<<<<<<< HEAD
#define BTN3_Pin GPIO_PIN_9
#define BTN3_GPIO_Port GPIOA
#define BTN2_Pin GPIO_PIN_10
#define BTN2_GPIO_Port GPIOA
#define BTN1_Pin GPIO_PIN_11
#define BTN1_GPIO_Port GPIOA
#define BTN0_Pin GPIO_PIN_12
#define BTN0_GPIO_Port GPIOA
=======
>>>>>>> stable_version

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
