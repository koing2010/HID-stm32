/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_regs.h
* Author             : MCD Application Team
* Version            : V2.2.1
* Date               : 09/22/2008
* Description        : Interface prototype functions to USB cell registers
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_REGS_H
#define __USB_REGS_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef enum _EP_DBUF_DIR
{
  /* double buffered endpoint direction */
  EP_DBUF_ERR,
  EP_DBUF_OUT,
  EP_DBUF_IN
}EP_DBUF_DIR;

/* endpoint buffer number */
enum EP_BUF_NUM
{
  EP_NOBUF,
  EP_BUF0,
  EP_BUF1
};

/* Exported constants --------------------------------------------------------*/
#define RegBase  (0x40005C00L)  /* USB_IP Peripheral Registers base address */
#define PMAAddr  (0x40006000L)  /* USB_IP Packet Memory Area base address   */

/******************************************************************************/
/*                         General registers                                  */
/******************************************************************************/

/* Control register */
#define CNTR    ((volatile unsigned *)(RegBase + 0x40))
/* Interrupt status register */
#define ISTR    ((volatile unsigned *)(RegBase + 0x44))
/* Frame number register */
#define FNR     ((volatile unsigned *)(RegBase + 0x48))
/* Device address register */
#define DADDR   ((volatile unsigned *)(RegBase + 0x4C))
/* Buffer Table address register */
#define BTABLE  ((volatile unsigned *)(RegBase + 0x50))
/******************************************************************************/
/*                         Endpoint registers                                 */
/******************************************************************************/
#define EP0REG  ((volatile unsigned *)(RegBase)) /* endpoint 0 register address */

/* endpoints enumeration */
#define ENDP0   ((u8)0)
#define ENDP1   ((u8)1)
#define ENDP2   ((u8)2)
#define ENDP3   ((u8)3)
#define ENDP4   ((u8)4)
#define ENDP5   ((u8)5)
#define ENDP6   ((u8)6)
#define ENDP7   ((u8)7)
/******************************************************************************/
/*                       ISTR interrupt events                                */
/******************************************************************************/
//中断控制寄存器
#define ISTR_CTR    (0x8000) /* Correct TRansfer (clear-only bit)正确传输CTR中断屏蔽位 */
#define ISTR_DOVR   (0x4000) /* DMA OVeR/underrun (clear-only bit) 分组缓冲区溢出中断屏蔽位*/
#define ISTR_ERR    (0x2000) /* ERRor (clear-only bit) 出错中断屏蔽位*/
#define ISTR_WKUP   (0x1000) /* WaKe UP (clear-only bit)唤醒中断屏蔽位 */
#define ISTR_SUSP   (0x0800) /* SUSPend (clear-only bit)挂起中断屏蔽位 */
#define ISTR_RESET  (0x0400) /* RESET (clear-only bit) USB复位中断屏蔽位*/
#define ISTR_SOF    (0x0200) /* Start Of Frame (clear-only bit) 帧首中断屏蔽位*/
#define ISTR_ESOF   (0x0100) /* Expected Start Of Frame (clear-only bit)期望帧首中断屏蔽位 */

//状态寄存器
#define ISTR_DIR    (0x0010)  /* DIRection of transaction (read-only bit) 传输方向  0: IN   1: OUT*/
#define ISTR_EP_ID  (0x000F)  /* EndPoint IDentifier (read-only bit) 端点号 完成数据传输产生中断后硬件根据端点号写入*/

#define CLR_CTR    (~ISTR_CTR)   /* clear Correct TRansfer bit */
#define CLR_DOVR   (~ISTR_DOVR)  /* clear DMA OVeR/underrun bit*/
#define CLR_ERR    (~ISTR_ERR)   /* clear ERRor bit */
#define CLR_WKUP   (~ISTR_WKUP)  /* clear WaKe UP bit     */
#define CLR_SUSP   (~ISTR_SUSP)  /* clear SUSPend bit     */
#define CLR_RESET  (~ISTR_RESET) /* clear RESET bit      */
#define CLR_SOF    (~ISTR_SOF)   /* clear Start Of Frame bit   */
#define CLR_ESOF   (~ISTR_ESOF)  /* clear Expected Start Of Frame bit */

/******************************************************************************/
/*             CNTR control register bits definitions    USB控制寄存器位定义                     */
/******************************************************************************/
#define CNTR_CTRM   (0x8000) /* Correct TRansfer Mask 正确传输位 */
#define CNTR_DOVRM  (0x4000) /* DMA OVeR/underrun Mask 分组缓冲区溢出中断位*/
#define CNTR_ERRM   (0x2000) /* ERRor Mask 出错中断位*/
#define CNTR_WKUPM  (0x1000) /* WaKe UP Mask 唤醒中断位*/
#define CNTR_SUSPM  (0x0800) /* SUSPend Mask 挂起中断位*/
#define CNTR_RESETM (0x0400) /* RESET Mask   USB复位中断位*/
#define CNTR_SOFM   (0x0200) /* Start Of Frame Mask 帧首中断位*/
#define CNTR_ESOFM  (0x0100) /* Expected Start Of Frame Mask 期望帧首中断位*/


#define CNTR_RESUME (0x0010) /* RESUME request 唤醒请求*/
#define CNTR_FSUSP  (0x0008) /* Force SUSPend 强制挂起位*/
#define CNTR_LPMODE (0x0004) /* Low-power MODE 低功耗模式位*/
#define CNTR_PDWN   (0x0002) /* Power DoWN 断电模式*/
#define CNTR_FRES   (0x0001) /* Force USB RESet 强制USB复位*/

/******************************************************************************/
/*                FNR Frame Number Register bit definitions  USB帧编号寄存器                  */
/******************************************************************************/
#define FNR_RXDP (0x8000) /* status of D+ data line D+ 状态位用于检测D+的数据状态，可在挂起状态下唤醒*/
#define FNR_RXDM (0x4000) /* status of D- data line D- 状态位*/
#define FNR_LCK  (0x2000) /* LoCKed  锁定位 */
#define FNR_LSOF (0x1800) /* Lost SOF 帧首丢失标志位*/
#define FNR_FN  (0x07FF) /* Frame Number 帧编号 SOF 中断时更新*/
/******************************************************************************/
/*               DADDR Device ADDRess bit definitions USB设备地址寄存器                        */
/******************************************************************************/
#define DADDR_EF (0x80)
#define DADDR_ADD (0x7F)
/******************************************************************************/
/*                            Endpoint register   端点寄存器                            */
/******************************************************************************/
/* bit positions */
#define EP_CTR_RX      (0x8000) /* EndPoint Correct TRansfer RX 正确接收 */
#define EP_DTOG_RX     (0x4000) /* EndPoint Data TOGGLE RX 用于数据接收的数据翻转位*/
#define EPRX_STAT      (0x3000) /* EndPoint RX STATus bit field 用于数据接收的状态位*/
#define EP_SETUP       (0x0800) /* EndPoint SETUP 分组传输完成标志位*/
#define EP_T_FIELD     (0x0600) /* EndPoint TYPE 端点类型位*/
#define EP_KIND        (0x0100) /* EndPoint KIND 端点特殊类型位*/
#define EP_CTR_TX      (0x0080) /* EndPoint Correct TRansfer TX 正确发送标志位*/
#define EP_DTOG_TX     (0x0040) /* EndPoint Data TOGGLE TX 正确发送数据翻转位*/
#define EPTX_STAT      (0x0030) /* EndPoint TX STATus bit field 发送数据的状态位 */
#define EPADDR_FIELD   (0x000F) /* EndPoint ADDRess FIELD 端点地址*/

/* EndPoint REGister MASK (no toggle fields) */
#define EPREG_MASK     (EP_CTR_RX|EP_SETUP|EP_T_FIELD|EP_KIND|EP_CTR_TX|EPADDR_FIELD)

/* EP_TYPE[1:0] EndPoint TYPE端点类型位 */
#define EP_TYPE_MASK   (0x0600) /* EndPoint TYPE Mask */
#define EP_BULK        (0x0000) /* EndPoint BULK 批量端点*/
#define EP_CONTROL     (0x0200) /* EndPoint CONTROL 控制端点*/
#define EP_ISOCHRONOUS (0x0400) /* EndPoint ISOCHRONOUS 同步端点*/
#define EP_INTERRUPT   (0x0600) /* EndPoint INTERRUPT 中断端点*/
#define EP_T_MASK      (~EP_T_FIELD & EPREG_MASK)


/* EP_KIND EndPoint KIND */
#define EPKIND_MASK    (~EP_KIND & EPREG_MASK)

/* STAT_TX[1:0] STATus for TX transfer */
#define EP_TX_DIS      (0x0000) /* EndPoint TX DISabled 忽略所有发送请求*/
#define EP_TX_STALL    (0x0010) /* EndPoint TX STALLed 端点以STALL分组相应所有发送请求*/
#define EP_TX_NAK      (0x0020) /* EndPoint TX NAKed 以NAK分组响应所有发送请求*/
#define EP_TX_VALID    (0x0030) /* EndPoint TX VALID 端点可用于发送*/
#define EPTX_DTOG1     (0x0010) /* EndPoint TX Data TOGgle bit1 */
#define EPTX_DTOG2     (0x0020) /* EndPoint TX Data TOGgle bit2 */
#define EPTX_DTOGMASK  (EPTX_STAT|EPREG_MASK)

/* STAT_RX[1:0] STATus for RX transfer */
#define EP_RX_DIS      (0x0000) /* EndPoint RX DISabled 忽略所有接受请求*/
#define EP_RX_STALL    (0x1000) /* EndPoint RX STALLed 端点以STALL分组响应所有接受请求*/
#define EP_RX_NAK      (0x2000) /* EndPoint RX NAKed 端点以NAK分组响应所有接受请求*/
#define EP_RX_VALID    (0x3000) /* EndPoint RX VALID 端点可用于接受*/
#define EPRX_DTOG1     (0x1000) /* EndPoint RX Data TOGgle bit1 */
#define EPRX_DTOG2     (0x2000) /* EndPoint RX Data TOGgle bit1 */
#define EPRX_DTOGMASK  (EPRX_STAT|EPREG_MASK)
/* Exported macro ------------------------------------------------------------*/
/* SetCNTR */
#define _SetCNTR(wRegValue)  (*CNTR   = (u16)wRegValue)    //写控制寄存器

/* SetISTR */
#define _SetISTR(wRegValue)  (*ISTR   = (u16)wRegValue)    //写中断状态寄存器

/* SetDADDR */
#define _SetDADDR(wRegValue) (*DADDR  = (u16)wRegValue)    //写设备地址寄存器

/* SetBTABLE */
#define _SetBTABLE(wRegValue)(*BTABLE = (u16)(wRegValue & 0xFFF8)) //写分组缓冲区描述表地址寄存器[15:3]

/* GetCNTR */
#define _GetCNTR()   ((u16) *CNTR)  //读控制寄存器

/* GetISTR */
#define _GetISTR()   ((u16) *ISTR)  //读中断状态寄存器

/* GetFNR */
#define _GetFNR()    ((u16) *FNR)   //读帧编号寄存器

/* GetDADDR */
#define _GetDADDR()  ((u16) *DADDR) //读设备地址寄存器

/* GetBTABLE */
#define _GetBTABLE() ((u16) *BTABLE) //读分组缓冲区描述表地址寄存器

/* SetENDPOINT */
#define _SetENDPOINT(bEpNum,wRegValue)  (*(EP0REG + bEpNum)= \
    (u16)wRegValue)    //写指定端点bEpNum

/* GetENDPOINT */
#define _GetENDPOINT(bEpNum)        ((u16)(*(EP0REG + bEpNum))) //读指定端点bEpNum

/*******************************************************************************
* Macro Name     : SetEPType  设置端点类型
* Description    : sets the type in the endpoint register(bits EP_TYPE[1:0])
* Input          : bEpNum: Endpoint Number. 
*                  wType
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPType(bEpNum,wType) (_SetENDPOINT(bEpNum,\
                                  ((_GetENDPOINT(bEpNum) & EP_T_MASK) | wType)))

/*******************************************************************************
* Macro Name     : GetEPType 读端点类型位
* Description    : gets the type in the endpoint register(bits EP_TYPE[1:0]) 
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : Endpoint Type
*******************************************************************************/
#define _GetEPType(bEpNum) (_GetENDPOINT(bEpNum) & EP_T_FIELD)

/*******************************************************************************
* Macro Name     : SetEPTxStatus   设置端点发送数据状态为，用于标示端点的当前状态
* Description    : sets the status for tx transfer (bits STAT_TX[1:0]).
* Input          : bEpNum: Endpoint Number. 
*                  wState: new state
* Output         : None.
* Return         : None. 写0无效 写1翻此位
*******************************************************************************/
#define _SetEPTxStatus(bEpNum,wState) {\
    register u16 _wRegVal;       \
    _wRegVal = _GetENDPOINT(bEpNum) & EPTX_DTOGMASK;\
    /* toggle first bit ? */     \
    if((EPTX_DTOG1 & wState)!= 0)      \
      _wRegVal ^= EPTX_DTOG1;        \
    /* toggle second bit ?  */         \
    if((EPTX_DTOG2 & wState)!= 0)      \
      _wRegVal ^= EPTX_DTOG2;        \
    _SetENDPOINT(bEpNum, _wRegVal);    \
  } /* _SetEPTxStatus */

/*******************************************************************************
* Macro Name     : SetEPRxStatus 写数据接收状态位，写0无效 写1翻此位
* Description    : sets the status for rx transfer (bits STAT_TX[1:0])
* Input          : bEpNum: Endpoint Number. 
*                  wState: new state.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPRxStatus(bEpNum,wState) {\
    register u16 _wRegVal;   \
    \
    _wRegVal = _GetENDPOINT(bEpNum) & EPRX_DTOGMASK;\
    /* toggle first bit ? */  \
    if((EPRX_DTOG1 & wState)!= 0) \
      _wRegVal ^= EPRX_DTOG1;  \
    /* toggle second bit ? */  \
    if((EPRX_DTOG2 & wState)!= 0) \
      _wRegVal ^= EPRX_DTOG2;  \
    _SetENDPOINT(bEpNum, _wRegVal); \
  } /* _SetEPRxStatus */
/*******************************************************************************
* Macro Name     : GetEPTxStatus / GetEPRxStatus 
* Description    : gets the status for tx/rx transfer (bits STAT_TX[1:0]
*                  /STAT_RX[1:0])
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : status .//读指定端点的数据发送 或者 接收状态
*******************************************************************************/
#define _GetEPTxStatus(bEpNum) ((u16)_GetENDPOINT(bEpNum) & EPTX_STAT)

#define _GetEPRxStatus(bEpNum) ((u16)_GetENDPOINT(bEpNum) & EPRX_STAT)

/*******************************************************************************
* Macro Name     : SetEPTxValid / SetEPRxValid 
* Description    : sets directly the VALID tx/rx-status into the enpoint register
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None. //写
*******************************************************************************/
#define _SetEPTxValid(bEpNum)     (_SetEPTxStatus(bEpNum, EP_TX_VALID))

#define _SetEPRxValid(bEpNum)     (_SetEPRxStatus(bEpNum, EP_RX_VALID))

/*******************************************************************************
* Macro Name     : GetTxStallStatus / GetRxStallStatus.
* Description    : checks stall condition in an endpoint.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : TRUE = endpoint in stall condition.
*******************************************************************************/
#define _GetTxStallStatus(bEpNum) (_GetEPTxStatus(bEpNum) \
                                   == EP_TX_STALL)
#define _GetRxStallStatus(bEpNum) (_GetEPRxStatus(bEpNum) \
                                   == EP_RX_STALL)

/*******************************************************************************
* Macro Name     : SetEP_KIND / ClearEP_KIND.
* Description    : set & clear EP_KIND bit.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEP_KIND(bEpNum)    (_SetENDPOINT(bEpNum, \
                                (_GetENDPOINT(bEpNum) | EP_KIND) & EPREG_MASK))
#define _ClearEP_KIND(bEpNum)  (_SetENDPOINT(bEpNum, \
                                (_GetENDPOINT(bEpNum) & EPKIND_MASK)))

/*******************************************************************************
* Macro Name     : Set_Status_Out / Clear_Status_Out.
* Description    : Sets/clears directly STATUS_OUT bit in the endpoint register.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _Set_Status_Out(bEpNum)    _SetEP_KIND(bEpNum)
#define _Clear_Status_Out(bEpNum)  _ClearEP_KIND(bEpNum)

/*******************************************************************************
* Macro Name     : SetEPDoubleBuff / ClearEPDoubleBuff.
* Description    : Sets/clears directly EP_KIND bit in the endpoint register.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPDoubleBuff(bEpNum)   _SetEP_KIND(bEpNum)
#define _ClearEPDoubleBuff(bEpNum) _ClearEP_KIND(bEpNum)

/*******************************************************************************
* Macro Name     : ClearEP_CTR_RX / ClearEP_CTR_TX.
* Description    : Clears bit CTR_RX / CTR_TX in the endpoint register.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _ClearEP_CTR_RX(bEpNum)   (_SetENDPOINT(bEpNum,\
                                   _GetENDPOINT(bEpNum) & 0x7FFF & EPREG_MASK))
#define _ClearEP_CTR_TX(bEpNum)   (_SetENDPOINT(bEpNum,\
                                   _GetENDPOINT(bEpNum) & 0xFF7F & EPREG_MASK))

/*******************************************************************************
* Macro Name     : ToggleDTOG_RX / ToggleDTOG_TX .
* Description    : Toggles DTOG_RX / DTOG_TX bit in the endpoint register.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _ToggleDTOG_RX(bEpNum)    (_SetENDPOINT(bEpNum, \
                                   EP_DTOG_RX | _GetENDPOINT(bEpNum) & EPREG_MASK))
#define _ToggleDTOG_TX(bEpNum)    (_SetENDPOINT(bEpNum, \
                                   EP_DTOG_TX | _GetENDPOINT(bEpNum) & EPREG_MASK))

/*******************************************************************************
* Macro Name     : ClearDTOG_RX / ClearDTOG_TX.
* Description    : Clears DTOG_RX / DTOG_TX bit in the endpoint register.
* Input          : bEpNum: Endpoint Number. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _ClearDTOG_RX(bEpNum)  if((_GetENDPOINT(bEpNum) & EP_DTOG_RX) != 0)\
    _ToggleDTOG_RX(bEpNum)
#define _ClearDTOG_TX(bEpNum)  if((_GetENDPOINT(bEpNum) & EP_DTOG_TX) != 0)\
    _ToggleDTOG_TX(bEpNum)
/*******************************************************************************
* Macro Name     : SetEPAddress.
* Description    : Sets address in an endpoint register.
* Input          : bEpNum: Endpoint Number.
*                  bAddr: Address. 
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPAddress(bEpNum,bAddr) _SetENDPOINT(bEpNum,\
    _GetENDPOINT(bEpNum) & EPREG_MASK | bAddr)

/*******************************************************************************
* Macro Name     : GetEPAddress.
* Description    : Gets address in an endpoint register.
* Input          : bEpNum: Endpoint Number.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _GetEPAddress(bEpNum) ((u8)(_GetENDPOINT(bEpNum) & EPADDR_FIELD))

#define _pEPTxAddr(bEpNum) ((u32 *)((_GetBTABLE()+bEpNum*8  )*2 + PMAAddr))
#define _pEPTxCount(bEpNum) ((u32 *)((_GetBTABLE()+bEpNum*8+2)*2 + PMAAddr))
#define _pEPRxAddr(bEpNum) ((u32 *)((_GetBTABLE()+bEpNum*8+4)*2 + PMAAddr))
#define _pEPRxCount(bEpNum) ((u32 *)((_GetBTABLE()+bEpNum*8+6)*2 + PMAAddr))

/*******************************************************************************
* Macro Name     : SetEPTxAddr / SetEPRxAddr.
* Description    : sets address of the tx/rx buffer.
* Input          : bEpNum: Endpoint Number.
*                  wAddr: address to be set (must be word aligned).
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPTxAddr(bEpNum,wAddr) (*_pEPTxAddr(bEpNum) = ((wAddr >> 1) << 1))
#define _SetEPRxAddr(bEpNum,wAddr) (*_pEPRxAddr(bEpNum) = ((wAddr >> 1) << 1))

/*******************************************************************************
* Macro Name     : GetEPTxAddr / GetEPRxAddr.
* Description    : Gets address of the tx/rx buffer.
* Input          : bEpNum: Endpoint Number.
* Output         : None.
* Return         : address of the buffer.
*******************************************************************************/
#define _GetEPTxAddr(bEpNum) ((u16)*_pEPTxAddr(bEpNum))
#define _GetEPRxAddr(bEpNum) ((u16)*_pEPRxAddr(bEpNum))

/*******************************************************************************
* Macro Name     : SetEPCountRxReg.
* Description    : Sets counter of rx buffer with no. of blocks.
* Input          : pdwReg: pointer to counter.
*                  wCount: Counter.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _BlocksOf32(dwReg,wCount,wNBlocks) {\
    wNBlocks = wCount >> 5;\
    if((wCount & 0x1f) == 0)\
      wNBlocks--;\
    *pdwReg = (u32)((wNBlocks << 10) | 0x8000);\
  }/* _BlocksOf32 */

#define _BlocksOf2(dwReg,wCount,wNBlocks) {\
    wNBlocks = wCount >> 1;\
    if((wCount & 0x1) != 0)\
      wNBlocks++;\
    *pdwReg = (u32)(wNBlocks << 10);\
  }/* _BlocksOf2 */

#define _SetEPCountRxReg(dwReg,wCount)  {\
    u16 wNBlocks;\
    if(wCount > 62){_BlocksOf32(dwReg,wCount,wNBlocks);}\
    else {_BlocksOf2(dwReg,wCount,wNBlocks);}\
  }/* _SetEPCountRxReg */



#define _SetEPRxDblBuf0Count(bEpNum,wCount) {\
    u32 *pdwReg = _pEPTxCount(bEpNum); \
    _SetEPCountRxReg(pdwReg, wCount);\
  }
/*******************************************************************************
* Macro Name     : SetEPTxCount / SetEPRxCount.
* Description    : sets counter for the tx/rx buffer.
* Input          : bEpNum: endpoint number.
*                  wCount: Counter value.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPTxCount(bEpNum,wCount) (*_pEPTxCount(bEpNum) = wCount)
#define _SetEPRxCount(bEpNum,wCount) {\
    u32 *pdwReg = _pEPRxCount(bEpNum); \
    _SetEPCountRxReg(pdwReg, wCount);\
  }
/*******************************************************************************
* Macro Name     : GetEPTxCount / GetEPRxCount.
* Description    : gets counter of the tx buffer.
* Input          : bEpNum: endpoint number.
* Output         : None.
* Return         : Counter value.
*******************************************************************************/
#define _GetEPTxCount(bEpNum)((u16)(*_pEPTxCount(bEpNum)) & 0x3ff)
#define _GetEPRxCount(bEpNum)((u16)(*_pEPRxCount(bEpNum)) & 0x3ff)

/*******************************************************************************
* Macro Name     : SetEPDblBuf0Addr / SetEPDblBuf1Addr.
* Description    : Sets buffer 0/1 address in a double buffer endpoint.
* Input          : bEpNum: endpoint number.
*                : wBuf0Addr: buffer 0 address.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPDblBuf0Addr(bEpNum,wBuf0Addr) {_SetEPTxAddr(bEpNum, wBuf0Addr);}
#define _SetEPDblBuf1Addr(bEpNum,wBuf1Addr) {_SetEPRxAddr(bEpNum, wBuf1Addr);}

/*******************************************************************************
* Macro Name     : SetEPDblBuffAddr.
* Description    : Sets addresses in a double buffer endpoint.
* Input          : bEpNum: endpoint number.
*                : wBuf0Addr: buffer 0 address.
*                : wBuf1Addr = buffer 1 address.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPDblBuffAddr(bEpNum,wBuf0Addr,wBuf1Addr) { \
    _SetEPDblBuf0Addr(bEpNum, wBuf0Addr);\
    _SetEPDblBuf1Addr(bEpNum, wBuf1Addr);\
  } /* _SetEPDblBuffAddr */

/*******************************************************************************
* Macro Name     : GetEPDblBuf0Addr / GetEPDblBuf1Addr.
* Description    : Gets buffer 0/1 address of a double buffer endpoint.
* Input          : bEpNum: endpoint number.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _GetEPDblBuf0Addr(bEpNum) (_GetEPTxAddr(bEpNum))
#define _GetEPDblBuf1Addr(bEpNum) (_GetEPRxAddr(bEpNum))

/*******************************************************************************
* Macro Name     : SetEPDblBuffCount / SetEPDblBuf0Count / SetEPDblBuf1Count.
* Description    : Gets buffer 0/1 address of a double buffer endpoint.
* Input          : bEpNum: endpoint number.
*                : bDir: endpoint dir  EP_DBUF_OUT = OUT 
*                                      EP_DBUF_IN  = IN 
*                : wCount: Counter value    
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _SetEPDblBuf0Count(bEpNum, bDir, wCount)  { \
    if(bDir == EP_DBUF_OUT)\
      /* OUT endpoint */ \
    {_SetEPRxDblBuf0Count(bEpNum,wCount);} \
    else if(bDir == EP_DBUF_IN)\
      /* IN endpoint */ \
      *_pEPTxCount(bEpNum) = (u32)wCount;  \
  } /* SetEPDblBuf0Count*/

#define _SetEPDblBuf1Count(bEpNum, bDir, wCount)  { \
    if(bDir == EP_DBUF_OUT)\
      /* OUT endpoint */ \
    {_SetEPRxCount(bEpNum,wCount);}\
    else if(bDir == EP_DBUF_IN)\
      /* IN endpoint */\
      *_pEPRxCount(bEpNum) = (u32)wCount; \
  } /* SetEPDblBuf1Count */

#define _SetEPDblBuffCount(bEpNum, bDir, wCount) {\
    _SetEPDblBuf0Count(bEpNum, bDir, wCount); \
    _SetEPDblBuf1Count(bEpNum, bDir, wCount); \
  } /* _SetEPDblBuffCount  */

/*******************************************************************************
* Macro Name     : GetEPDblBuf0Count / GetEPDblBuf1Count.
* Description    : Gets buffer 0/1 rx/tx counter for double buffering.
* Input          : bEpNum: endpoint number.
* Output         : None.
* Return         : None.
*******************************************************************************/
#define _GetEPDblBuf0Count(bEpNum) (_GetEPTxCount(bEpNum))
#define _GetEPDblBuf1Count(bEpNum) (_GetEPRxCount(bEpNum))


/* External variables --------------------------------------------------------*/
extern volatile u16 wIstr;  /* ISTR register last read value */

/* Exported functions ------------------------------------------------------- */
void SetCNTR(u16 /*wRegValue*/);
void SetISTR(u16 /*wRegValue*/);
void SetDADDR(u16 /*wRegValue*/);
void SetBTABLE(u16 /*wRegValue*/);
void SetBTABLE(u16 /*wRegValue*/);
u16 GetCNTR(void);
u16 GetISTR(void);
u16 GetFNR(void);
u16 GetDADDR(void);
u16 GetBTABLE(void);
void SetENDPOINT(u8 /*bEpNum*/, u16 /*wRegValue*/);
u16 GetENDPOINT(u8 /*bEpNum*/);
void SetEPType(u8 /*bEpNum*/, u16 /*wType*/);
u16 GetEPType(u8 /*bEpNum*/);
void SetEPTxStatus(u8 /*bEpNum*/, u16 /*wState*/);
void SetEPRxStatus(u8 /*bEpNum*/, u16 /*wState*/);
void SetDouBleBuffEPStall(u8 /*bEpNum*/, u8 bDir);
u16 GetEPTxStatus(u8 /*bEpNum*/);
u16 GetEPRxStatus(u8 /*bEpNum*/);
void SetEPTxValid(u8 /*bEpNum*/);
void SetEPRxValid(u8 /*bEpNum*/);
u16 GetTxStallStatus(u8 /*bEpNum*/);
u16 GetRxStallStatus(u8 /*bEpNum*/);
void SetEP_KIND(u8 /*bEpNum*/);
void ClearEP_KIND(u8 /*bEpNum*/);
void Set_Status_Out(u8 /*bEpNum*/);
void Clear_Status_Out(u8 /*bEpNum*/);
void SetEPDoubleBuff(u8 /*bEpNum*/);
void ClearEPDoubleBuff(u8 /*bEpNum*/);
void ClearEP_CTR_RX(u8 /*bEpNum*/);
void ClearEP_CTR_TX(u8 /*bEpNum*/);
void ToggleDTOG_RX(u8 /*bEpNum*/);
void ToggleDTOG_TX(u8 /*bEpNum*/);
void ClearDTOG_RX(u8 /*bEpNum*/);
void ClearDTOG_TX(u8 /*bEpNum*/);
void SetEPAddress(u8 /*bEpNum*/, u8 /*bAddr*/);
u8 GetEPAddress(u8 /*bEpNum*/);
void SetEPTxAddr(u8 /*bEpNum*/, u16 /*wAddr*/);
void SetEPRxAddr(u8 /*bEpNum*/, u16 /*wAddr*/);
u16 GetEPTxAddr(u8 /*bEpNum*/);
u16 GetEPRxAddr(u8 /*bEpNum*/);
void SetEPCountRxReg(u32 * /*pdwReg*/, u16 /*wCount*/);
void SetEPTxCount(u8 /*bEpNum*/, u16 /*wCount*/);
void SetEPRxCount(u8 /*bEpNum*/, u16 /*wCount*/);
u16 GetEPTxCount(u8 /*bEpNum*/);
u16 GetEPRxCount(u8 /*bEpNum*/);
void SetEPDblBuf0Addr(u8 /*bEpNum*/, u16 /*wBuf0Addr*/);
void SetEPDblBuf1Addr(u8 /*bEpNum*/, u16 /*wBuf1Addr*/);
void SetEPDblBuffAddr(u8 /*bEpNum*/, u16 /*wBuf0Addr*/, u16 /*wBuf1Addr*/);
u16 GetEPDblBuf0Addr(u8 /*bEpNum*/);
u16 GetEPDblBuf1Addr(u8 /*bEpNum*/);
void SetEPDblBuffCount(u8 /*bEpNum*/, u8 /*bDir*/, u16 /*wCount*/);
void SetEPDblBuf0Count(u8 /*bEpNum*/, u8 /*bDir*/, u16 /*wCount*/);
void SetEPDblBuf1Count(u8 /*bEpNum*/, u8 /*bDir*/, u16 /*wCount*/);
u16 GetEPDblBuf0Count(u8 /*bEpNum*/);
u16 GetEPDblBuf1Count(u8 /*bEpNum*/);
EP_DBUF_DIR GetEPDblBufDir(u8 /*bEpNum*/);
void FreeUserBuffer(u8 bEpNum/*bEpNum*/, u8 bDir);
u16 ToWord(u8, u8);
u16 ByteSwap(u16);

#endif /* __USB_REGS_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
