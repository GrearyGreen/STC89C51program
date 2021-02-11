#ifndef __IIC_H__
#define __IIC_H__

#include <reg52.h>
#include <intrins.h>
#define uint8_t  unsigned char
#define uint16_t unsigned int

sbit SDA = P2^0;
sbit SCL = P2^1;
				   
void I2C_init();					//通信初始化
void I2C_start();					//通信开始
void I2C_stop();					//通信停止，或者一字节传输停止
bit Test_ack();						//是否应答
void I2C_send_byte(uint8_t byte);	//发送八位数据
				
#endif
