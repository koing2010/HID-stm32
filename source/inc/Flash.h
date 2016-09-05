#ifndef _FALSE_H_ 
#define _FALSE_H_
#define PAGE_SIZE 1024

#include "stm32f10x.h"
#include "usb_lib.h"
#include "stm32f10x_flash.h"
extern u32 WriteFlash(u32 startAddr, u8 *pData, u32 size);
extern u32 ReadFlash(u32 startAddr, u8 *pData, u32 size);
extern bool EraseFlash(u32 startAddr, u8 erasePage);
#endif

