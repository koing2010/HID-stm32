/**********************************************************************************
File_name:     storageManager.c
Version:		   0.0
Revised:       $Date:2015-8-28 to  ; $
Description:   bottom file.
Notes:         based on the usb hid device. 
Editor:        Mr.kon
**********************************************************************************/
#include "StorageManager.h"
#include "Flash.h"


#define DEFAULT_STORAGE_ADDRESS 	  0x08000000 + PAGE_SIZE*64    //
#define SYSTEM_ADDRESS 				      DEFAULT_STORAGE_ADDRESS + PAGE_SIZE	* 0
#define CONTROLLER_ADDRESS 	        DEFAULT_STORAGE_ADDRESS + PAGE_SIZE * 1
#define SLAVER_ADDRESS 	           	DEFAULT_STORAGE_ADDRESS + PAGE_SIZE * 2
#define SENSOR_ADDRESS 			      	DEFAULT_STORAGE_ADDRESS + PAGE_SIZE * 3
#define THEORY_ADDRESS 				      DEFAULT_STORAGE_ADDRESS + PAGE_SIZE * 4


#define REMOTE_CODE_ADDRESS         0x08000000 + PAGE_SIZE*100 //Ò£¿ØÂëÆðÊ¼
/*********************************************************************************
Function:     CompleteSend
Description:  add what you need.
Input:        None
Output:       None
Return:       None.
Others:       koing2010@2015/8/28
*********************************************************************************/
//bool ReadSystemInfo(PSYSTEM_STORAGE pSystemStorage)
//{
//	u32 readbyte;
//	u32 startAddr = SYSTEM_ADDRESS;
//	readbyte = ReadFlash(startAddr, (u8*) pSystemStorage,
//			sizeof(SYSTEM_STORAGE));
//	if (readbyte != sizeof(SYSTEM_STORAGE))
//	{
//		return FALSE;
//	}
//	return TRUE;
//}

//bool WriteSystemInfo()
//{
//	u32 writebyte;
//	u32 startAddr = SYSTEM_ADDRESS;
//	if(!EraseFlash(startAddr, 1))
//	{
//		return FALSE;
//	}
//	writebyte = WriteFlash(startAddr, (u8*) &system.systemStorage,
//			sizeof(SYSTEM_STORAGE));
//	if (writebyte != sizeof(SYSTEM_STORAGE))
//	{
//		return FALSE;
//	}
//	return TRUE;
//}

void ResetDefaultSetting()
{
	EraseFlash(SYSTEM_ADDRESS, 1);
	EraseFlash(CONTROLLER_ADDRESS, 1);
	EraseFlash(SLAVER_ADDRESS, 1);
	EraseFlash(SENSOR_ADDRESS, 1);
	EraseFlash(THEORY_ADDRESS, 1);	
}
