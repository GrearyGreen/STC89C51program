#ifndef _DHT11_H_
#define _DHT11_H_

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

extern uchar U8FLAG;//��ֹ��ѭ���ļ�ʱ����
//2~255��u8������
extern uchar U8temp;//�����ݴ�
//��ȡ������
extern uchar	U8T_data_H,		//�¶ȵ�����λ
				U8T_data_L,		//�¶ȵ�С��λ
				U8RH_data_H,	//ʪ�ȵ�����λ
				U8RH_data_L,	//ʪ�ȵ�С��λ
				U8checkdata;	//У��λ
//У�������
extern uchar	U8T_data_H_temp,		//�¶ȵ�����λ
				U8T_data_L_temp,		//�¶ȵ�С��λ
				U8RH_data_H_temp,		//ʪ�ȵ�����λ
				U8RH_data_L_temp,		//ʪ�ȵ�С��λ
				U8checkdata_temp;		//У��λ
//ÿ8λ���ݵ��ݴ�����
extern uchar U8comdata;

void Delay(uint j);
void Delay_10us(void);

//��Ƭ����DHT11ʪ�ȴ������Ĳ���
//�ж�ͨ���е�0��1
void COM(void);
//��ȡ���ݣ��¶ȣ�ʪ��
void RH(void);

#endif