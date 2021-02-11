#ifndef __IIC_H__
#define __IIC_H__

#include <reg52.h>
#include <intrins.h>
#define uint8_t  unsigned char
#define uint16_t unsigned int

sbit SDA = P2^0;
sbit SCL = P2^1;
				   
void I2C_init();					//ͨ�ų�ʼ��
void I2C_start();					//ͨ�ſ�ʼ
void I2C_stop();					//ͨ��ֹͣ������һ�ֽڴ���ֹͣ
bit Test_ack();						//�Ƿ�Ӧ��
void I2C_send_byte(uint8_t byte);	//���Ͱ�λ����
				
#endif
