#ifndef _I2C_H_
#define _I2C_H_

#include <reg52.h>

sbit SCL = P2^1;
sbit SDA = P2^0;
//�����ϣ�24c20�����������ܽ���
//�˸��ܽ������Ѻ�������ַ�ӵأ�0��0��0
//һ����Դһ���ӵأ�һ��д�����ӵأ��ɶ�д�����Ӹ�ʱ��ֻ����

void I2CStar();
unsigned char I2C_SendByte(unsigned char Send_data);
unsigned char I2C_ReadByte();
void I2CStop();

void E2Write(unsigned char address,unsigned char send_data);
//������д��EEPROM��
unsigned char E2Read(unsigned char address);
//�����ݴ�EEPROM�ж���

#endif