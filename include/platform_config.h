/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : platform_config.h
* Author             : MCD Application Team
* Version            : V2.2.1
* Date               : 09/22/2008
* Description        : Evaluation board specific configuration file.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* Includes ------------------------------------------------------------------*/
//#include "stm32f10x_type.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/


  #define USB_DISCONNECT                      GPIOB  
  #define USB_DISCONNECT_PIN                  GPIO_Pin_12
  #define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOB

  #define RCC_APB2Periph_GPIO_TEMOTE          RCC_APB2Periph_GPIOB


  #define GPIO_REMOTE                         GPIOB


  #define GPIO_TV_PIN                        GPIO_Pin_7    /* PB.07 */ 
  #define GPIO_D0_PIN                        GPIO_Pin_6    /* PB.06 */ 
  #define GPIO_D1_PIN                        GPIO_Pin_5    /* PB.05 */ 
  #define GPIO_D2_PIN                        GPIO_Pin_4    /* PB.04 */ 
  #define GPIO_D3_PIN                        GPIO_Pin_3    /* PB.03 */ 
  #define GPIO_D4_PIN                        GPIO_Pin_15   /* PA.15 */ 
  

  
  #define GPIO_LED1_PIN                       GPIO_Pin_6   /* PC.06 */
  #define GPIO_LED2_PIN                       GPIO_Pin_7   /* PC.07 */ 
  #define GPIO_LED3_PIN                       GPIO_Pin_8   /* PC.08 */
  #define GPIO_LED4_PIN                       GPIO_Pin_9   /* PC.09 */ 

  #define GPIO_KEY_PORTSOURCE                 GPIO_PortSourceGPIOB
  #define GPIO_KEY_PINSOURCE                  GPIO_PinSource9
  #define GPIO_KEY_EXTI_Line                  EXTI_Line9

  #define GPIO_TAMPER_PORTSOURCE              GPIO_PortSourceGPIOC
  #define GPIO_TAMPER_PINSOURCE               GPIO_PinSource13
  #define GPIO_TAMPER_EXTI_Line               EXTI_Line13

  #define ADC_AIN_CHANNEL                     ADC_Channel_14



/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

