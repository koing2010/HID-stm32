/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_endp.c
* Author             : MCD Application Team
* Version            : V2.2.1
* Date               : 09/22/2008
* Description        : Endpoint routines
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "platform_config.h"
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "stm32f10x_gpio.h"
#include  "stdio.h"

//#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
//#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
//#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

//#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
//#define TRCENA          0x01000000

//struct __FILE { int handle; /* Add whatever you need here */ };
//FILE __stdout;
//FILE __stdin;

//int fputc(int ch, FILE *f) {
//  if (DEMCR & TRCENA) {
//    while (ITM_Port32(0) == 0);
//    ITM_Port8(0) = ch;
//  }
//  return(ch);
//}

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 Receive_Buffer[8];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP1_OUT_Callback.
* Description    : EP1 OUT Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_OUT_Callback(void)
{
  
 unsigned char i;
  
  PMAToUserBufferCopy(Receive_Buffer, ENDP1_RXADDR, 8);
  SetEPRxStatus(ENDP1, EP_RX_VALID);
  for( i = 0;i<8;i++)
  {
	// printf("rxdata %02x ",Receive_Buffer[i]);
   Receive_Buffer[i]++;
		
  }
	
    UserToPMABufferCopy(Receive_Buffer, ENDP1_TXADDR, 8);
    SetEPTxCount(ENDP1, 8);
    SetEPTxValid(ENDP1);
 
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

