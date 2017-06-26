#include "i2c_hal.h"
void iic_ack(void);
void iic_nack(void);
unsigned char iic_wait_ack(void);
static etError I2c_WaitWhileClockStreching(u8t timeout);

void delay_5us(void)
{
	volatile u16 i = 0;
	for ( i=0; i < 10; i++) __ASM("NOP");
}

void delay_5ms(void)
{
  DelayMicroSeconds(5);
}

void  DelayMicroSeconds( unsigned long int nus)
{
	volatile u16 i = 0;
	for(; nus > 0; nus --)
		{
			for ( i =0; i< 200; i++) 
			delay_5us();
		}
}

unsigned char start_iic(void)
{
	SDA_H;
	SCL_H;
	delay_5us();

	if(!READ_SDA)
		{
			return 0;
		}
	SDA_L;
	delay_5us();

	if(READ_SDA)
		{
			return 0;
		}
	SCL_L;
	delay_5us();
	//SDA_H;

	return 1;
}

void stop_iic(void)
{
	SDA_L;
	SCL_L;
	delay_5us();
	SCL_H;
	delay_5us();
	SDA_L;
	delay_5us();
	SDA_H;
}

void iic_ack(void)
{
	SDA_L;
	SCL_L;
	delay_5us();
	SCL_H;
	delay_5us();
	SCL_L;

}

void iic_nack(void)
{
	SDA_H;
	SCL_L;
	delay_5us();
	SCL_H;
	delay_5us();
	SCL_L;

}

unsigned char iic_wait_ack(void)
{
	SCL_L;
	delay_5us();
	SDA_H;
	delay_5us();
	SCL_H;
	delay_5us();
	while(READ_SDA == GPIO_PIN_SET)
		{
			SCL_L;
			return 0;
		}
	SCL_L;
	return 1;
}


unsigned char iic_write_byte(unsigned char data)
{
	unsigned char loop8;


	for(loop8 =0; loop8<8; loop8++)
		{
			SCL_L;
			if((data & 0X80) == 0X00)
				{
					SDA_L;
				}
			else
				{
					SDA_H;
				}
			delay_5us();
			SCL_H;
			delay_5us();
			data = (data<<1);
		}
	SCL_L;
	return 1;
}

unsigned char iic_read_byte(unsigned char ack)
{
	volatile unsigned char loop8;
	volatile unsigned stat;
	volatile unsigned char read_data;
	(void)ack;

	SDA_H;
	for(loop8 = 0; loop8<8; loop8++)
		{
			SCL_L;

			delay_5us();
			SCL_H;
			delay_5us();
			read_data = (read_data<<1);
			stat = READ_SDA;
			if(stat == GPIO_PIN_SET)
				{
					read_data = read_data|0X01;
				}
		}
	SCL_L;
	delay_5us();
	if(ack)
		{
			iic_ack();
		}
	else
		{
			iic_nack();
		}
	return read_data;
}

//-----------------------------------------------------------------------------
void I2c_StartCondition(void)
{
	SDA_H;
	DelayMicroSeconds(1);
	SCL_H;
	DelayMicroSeconds(1);
	SDA_L;
	DelayMicroSeconds(10); // hold time start condition (t_HD;STA)
	SCL_L;
	DelayMicroSeconds(10);
// start_iic();
}
//-----------------------------------------------------------------------------
void I2c_StopCondition(void)
{
	SCL_L;
	DelayMicroSeconds(1);
	SDA_L;
	DelayMicroSeconds(1);
	SCL_H;
	DelayMicroSeconds(10); // set-up time stop condition (t_SU;STO)
	SDA_H;
	DelayMicroSeconds(10);
}
//-----------------------------------------------------------------------------
etError I2c_WriteByte(u8t txByte)
{
	etError error = NO_ERROR;
	u8t mask;
	for(mask = 0x80; mask > 0; mask >>= 1)// shift bit for masking (8 times)
		{
			if((mask & txByte) == 0)
				{
					SDA_L;  // masking txByte, write bit to SDA-Line
				}
			else
				{
					SDA_H;
				}
			DelayMicroSeconds(1); // data set-up time (t_SU;DAT)
			SCL_H; // generate clock pulse on SCL
			DelayMicroSeconds(5); // SCL high time (t_HIGH)
			SCL_L;
			DelayMicroSeconds(1); // data hold time(t_HD;DAT)
		}
	SDA_H; // release SDA-line

	SCL_H; // clk #9 for ack

	DelayMicroSeconds(1); // data set-up time (t_SU;DAT)
	if( READ_SDA ) error = ACK_ERROR; // check ack from i2c slave
	SCL_L;
	DelayMicroSeconds(20); // wait to see byte package on scope
	return error; // return error code
}


//-----------------------------------------------------------------------------
etError I2c_ReadByte(u8t *rxByte, etI2cAck ack, u8t timeout)
{
	etError error = NO_ERROR;
	u8t mask;
	*rxByte = 0x00;
	SDA_H; // release SDA-line
	for(mask = 0x80; mask > 0; mask >>= 1) // shift bit for masking (8 times)
		{
			SCL_H; // start clock on SCL-line
			DelayMicroSeconds(1); // clock set-up time (t_SU;CLK)
			error = I2c_WaitWhileClockStreching(timeout);// wait while clock streching
			DelayMicroSeconds(3); // SCL high time (t_HIGH)
			if(READ_SDA) *rxByte |= mask; // read bit
			SCL_L;
			DelayMicroSeconds(1); // data hold time(t_HD;DAT)
		}

	if(ack == ACK)
		{
			SDA_L; // send acknowledge if necessary
		}
	else
		{
			SDA_H;
		}

	DelayMicroSeconds(1); // data set-up time (t_SU;DAT)
	SCL_H; // clk #9 for ack
	DelayMicroSeconds(5); // SCL high time (t_HIGH)
	SCL_L;
	SDA_H; // release SDA-line
	DelayMicroSeconds(20); // wait to see byte package on scope
	return error; // return with no error

}
//-----------------------------------------------------------------------------
etError I2c_GeneralCallReset(void)
{
	etError error;
	start_iic();
	error = iic_write_byte(0x00);
	if(error == NO_ERROR) error = iic_write_byte(0x06);
	return error;
}
//-----------------------------------------------------------------------------
static etError I2c_WaitWhileClockStreching(u8t timeout)
{
	etError error = NO_ERROR;
	while( READ_SCL == 0)
		{
			if(timeout-- == 0) return TIMEOUT_ERROR;
			DelayMicroSeconds(1000);
		}
	return error;
}
