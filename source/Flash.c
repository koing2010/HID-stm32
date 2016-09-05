#include"Flash.h"

bool EraseFlash(u32 startAddr, u8 erasePage)
{
	volatile FLASH_Status FLASHStatus;
  int i;
	FLASH_Unlock();          //解锁函数

	FLASH_ClearFlag(
	FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

	for ( i = 0; i < erasePage; i++)
	{
		FLASHStatus = FLASH_ErasePage(startAddr + (PAGE_SIZE * i));
		if (FLASHStatus != FLASH_COMPLETE)
		{
			FLASH_Lock();
			return FALSE;
		}

	}
	FLASH_Lock();  
	return TRUE;
} 
u32 WriteFlash(u32 startAddr, u8 *pData, u32 size)
{
	u32 * pBuf = (u32 *)pData;
	volatile FLASH_Status FLASHStatus;
	u32 writeCount = 0;

	FLASH_Unlock();          //解锁函数

	FLASH_ClearFlag(
	FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

	while (writeCount < size / sizeof(int))
	{
		FLASHStatus = FLASH_ProgramWord(startAddr, pBuf[writeCount]);
		if (FLASHStatus != FLASH_COMPLETE)
		{
			FLASH_Lock();
			return 0;
		}
		writeCount += 1;
		startAddr += sizeof(int);
	}
	FLASH_Lock();
	return writeCount * sizeof(int);
}
//输入大小为几个4字节
u32 ReadFlash(u32 startAddr, u8 *pData, u32 size)
{
	int i = 0;
	u8 * pBuf = (u8 *)startAddr; 
	while (i < size)
	{
	*(pData + i) = *pBuf;
		pBuf++;
		i++;
	}
	return i;
}
