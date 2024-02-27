/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define HEAT_EN_Pin GPIO_PIN_14
#define HEAT_EN_GPIO_Port GPIOC
#define FAN_EN_Pin GPIO_PIN_15
#define FAN_EN_GPIO_Port GPIOC
#define THM_CAM_EN_Pin GPIO_PIN_0
#define THM_CAM_EN_GPIO_Port GPIOC
#define COL_CAM_EN_Pin GPIO_PIN_1
#define COL_CAM_EN_GPIO_Port GPIOC
#define LRF_EN_Pin GPIO_PIN_2
#define LRF_EN_GPIO_Port GPIOC
#define TEST_EN_Pin GPIO_PIN_3
#define TEST_EN_GPIO_Port GPIOC
#define PA0_ADC_Temp_Pin GPIO_PIN_0
#define PA0_ADC_Temp_GPIO_Port GPIOA
#define TXD2_Pin GPIO_PIN_2
#define TXD2_GPIO_Port GPIOA
#define RXD2_Pin GPIO_PIN_3
#define RXD2_GPIO_Port GPIOA
#define TXD3_Pin GPIO_PIN_10
#define TXD3_GPIO_Port GPIOB
#define RXD3_Pin GPIO_PIN_11
#define RXD3_GPIO_Port GPIOB
#define TXD1_Pin GPIO_PIN_9
#define TXD1_GPIO_Port GPIOA
#define RXD1_Pin GPIO_PIN_10
#define RXD1_GPIO_Port GPIOA
#define TXD4_Pin GPIO_PIN_10
#define TXD4_GPIO_Port GPIOC
#define RXD4_Pin GPIO_PIN_11
#define RXD4_GPIO_Port GPIOC
#define TXD5_Pin GPIO_PIN_12
#define TXD5_GPIO_Port GPIOC
#define RXD5_Pin GPIO_PIN_2
#define RXD5_GPIO_Port GPIOD
#define SCL1_Pin GPIO_PIN_6
#define SCL1_GPIO_Port GPIOB
#define SDA1_Pin GPIO_PIN_7
#define SDA1_GPIO_Port GPIOB
#define DE1_Pin GPIO_PIN_8
#define DE1_GPIO_Port GPIOB
#define DE5_Pin GPIO_PIN_9
#define DE5_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
