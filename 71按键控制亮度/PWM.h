#ifndef __PWM_H__
#define __PWM_H__

#include "reg52.h"

typedef unsigned int u16;
typedef unsigned char u8;

//ͨ���������������������ĵ�ѹֵ���2.82V

sbit PWM0 = P1^0;
sbit PWM1 = P1^1;
sbit PWM2 = P1^2;
sbit PWM3 = P1^3;

extern u16 timer0,timer1;

void Timer0Init();					//��ʼ����ʱ��
void Timer1Init();

//�������65535us,oppͬ��
bit Time0_Flag(u16 max,u16 opp);	//����opp���0��С��opp���1��max,������
bit Time1_Flag(u16 max,u16 opp);	//����ֵΪ��ǰ��PWM��ƽ

//���õ�20ms����
void duoji0(u8 baifenbi);			//�ٷֱ�baifenbi���ܳ���100
void duoji1(u8 baifenbi);			//PWM�Ŀ��ƹܽ����Ϸ�����
									//���0����PWM0,PWM1�����1����PWM2,PWM3

#endif