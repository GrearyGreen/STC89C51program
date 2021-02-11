#ifndef _DS18B20_H_
#define _DS18B20_H_

#include <reg52.h>
#include <intrins.h>

//�����޷��ŵ�����
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit Serial_port=P3^7;
//ͨ�Źܽ���P3^7��

void delay1ms();

//��Ƭ����DS18B20�¶ȴ������Ĳ���
uchar DS18B20_Star();
void DS18B20_Write(uchar Send_data);
uchar DS18B20_Read();
//�����¶�
void  DS18B20_measure();
//������ȡ�¶�ָ��
void  DS18B20_ReadTemp();

//��ȡ�¶�
int DS18B20_Temperature();

#endif