/**********************************************************************************
File_name:     RemoteInput.c
Version:		   0.0
Revised:       $Date:2015-8-28 to  ; $
Description:   scan telecontrol input data.
Notes:         based on the usb hid device.
Editor:        Mr.kon
**********************************************************************************/
#include "stm32f10x.h"
#include "platform_config.h"
#include "stm32f10x_gpio.h"
#include "RemoteInput.h"
#include "usb_lib.h"
#include "sht3x.h"

/*================================================================================
@ All functions  as follow
*/
static unsigned char remoteScan(void);
static void delay(unsigned long int Nms );

/*  */
etError    error; // error code
u32t       serialNumber;// serial number
regStatus  status; // sensor status
ft         temperature = 27.0; // temperature [C]
ft         humidity = 50.0; // relative humidity [%RH]


static void delay(unsigned long int ms ) 
{
  while(ms--);
}
/*********************************************************************************
Function:     remoteScan
Description:  .
Input:        None
Output:       None
Return:       the valuable data.
Others:       koing2010@2015/8/28
*********************************************************************************/
static unsigned char remoteScan(void)
{
    union
    {
        REMOTE remoteInput;
        unsigned char data;
    } wData;
    if(GPIO_ReadInputDataBit(GPIO_REMOTE,GPIO_TV_PIN))
    {
      delay(2000);
        if(!GPIO_ReadInputDataBit(GPIO_REMOTE,GPIO_TV_PIN))
            return 0;
        wData.remoteInput.D0 = GPIO_ReadInputDataBit(GPIO_REMOTE,GPIO_D0_PIN);
        wData.remoteInput.D1 = GPIO_ReadInputDataBit(GPIO_REMOTE,GPIO_D1_PIN);
        wData.remoteInput.D2 = GPIO_ReadInputDataBit(GPIO_REMOTE,GPIO_D2_PIN);
        wData.remoteInput.D3 = GPIO_ReadInputDataBit(GPIO_REMOTE,GPIO_D3_PIN);
        wData.remoteInput.D4 = GPIO_ReadInputDataBit(GPIOA      ,GPIO_D4_PIN);
        return  wData.data;
    }
    return 0;
}


/*********************************************************************************
Function:     SndRmtCmd
Description:  send remote command
Input:        None
Output:       None
Return:       None
Others:       koing2010@2015/8/28
*********************************************************************************/
void SndRmtCmd()
{
  unsigned char Send_Buffer[8] = {
	   /* frame IN */
    0x85, 0x03,            /*     REPORT_ID (7)              */
    0x00, 0x00,            /*     USAGE (frame IN)           */
		0x00,0x00,0x00,0x00
};

 if(Send_Buffer[1])
 {
  error = SHT3x_ReadSerialNumber(&serialNumber);

//  if(error != NO_ERROR){} // do error handling here
//  // demonstrate a single shot measurement with clock-stretching
//  error = SHT3X_GetTempAndHumi(&temperature, &humidity, REPEATAB_HIGH,
//                               MODE_CLKSTRETCH, 50);
  if(error != NO_ERROR){} // do error handling here
  // demonstrate a single shot measurement with polling and 50ms timeout
  error = SHT3X_GetTempAndHumi(&temperature, &humidity, REPEATAB_HIGH, MODE_POLLING,
                               50);
  if(error != NO_ERROR){} // do error handling here
		 Send_Buffer[2] = (u8)(temperature*100);
		 Send_Buffer[3] = ((u16)(temperature*100))>>8;
	   Send_Buffer[4] = (u8)(humidity*100);
		 Send_Buffer[5] = ((u16)(humidity*100))>>8;
     UserToPMABufferCopy(Send_Buffer, ENDP1_TXADDR, 8);
     SetEPTxCount(ENDP1, 8);
     SetEPTxValid(ENDP1);
	 
	 
    delay(0xFFFFFF);
 }

}












