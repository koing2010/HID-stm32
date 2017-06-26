#ifndef __I2C_HAL__
#define __I2C_HAL__
#include "stm32f10x_lib.h"
#include "usb_type.h"

#define I2C_PORT     GPIOB
#define I2C_SDA_PIN  GPIO_Pin_11
#define I2C_SCL_PIN  GPIO_Pin_10


#define GPIO_PIN_SET  1


#define SCL_H         GPIO_SetBits(I2C_PORT, I2C_SCL_PIN);
#define SCL_L         GPIO_ResetBits(I2C_PORT, I2C_SCL_PIN);

#define SDA_H         GPIO_SetBits(I2C_PORT, I2C_SDA_PIN);
#define SDA_L         GPIO_ResetBits(I2C_PORT, I2C_SDA_PIN);

#define READ_SDA      GPIO_ReadInputDataBit(I2C_PORT, I2C_SDA_PIN)
#define READ_SCL      GPIO_ReadInputDataBit(I2C_PORT, I2C_SCL_PIN)

typedef unsigned char u8t; ///< range: 0 .. 255
typedef signed char i8t; ///< range: -128 .. +127
typedef unsigned short u16t; ///< range: 0 .. 65535
typedef signed short i16t; ///< range: -32768 .. +32767
typedef unsigned long u32t; ///< range: 0 .. 4'294'967'295
typedef signed long i32t; ///< range: -2'147'483'648 .. +2'147'483'647
typedef float ft; ///< range: +-1.18E-38 .. +-3.39E+38
typedef double dt; ///< range: .. +-1.79E+308
//typedef enum{
//  FALSE = 0,
//  TRUE = 1
//}bt;
typedef bool bt; 

// Error codes
typedef enum{
  NO_ERROR = 0x00, // no error
  ACK_ERROR = 0x01, // no acknowledgment error
  CHECKSUM_ERROR = 0x02, // checksum mismatch error
  TIMEOUT_ERROR = 0x04, // timeout error
  PARM_ERROR = 0x80, // parameter out of range error
}etError;

// I2C acknowledge
typedef enum{
  ACK = 0,
  NACK = 1,
}etI2cAck;


void delay_5us(void);
void delay_5ms(void);
unsigned char start_iic(void);
void stop_iic(void);
unsigned char iic_write_byte(unsigned char data);
unsigned char iic_read_byte(unsigned char ack);
unsigned char iic_wait_ack(void);
void  DelayMicroSeconds( unsigned long int nus);
etError I2c_ReadByte(u8t *rxByte, etI2cAck ack, u8t timeout);
etError I2c_GeneralCallReset(void);
etError I2c_WriteByte(u8t txByte);
void I2c_StartCondition(void);
void I2c_StopCondition(void);
#endif
