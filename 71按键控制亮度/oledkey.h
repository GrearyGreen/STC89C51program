#ifndef __OLEDKEY_H__
#define __OLEDKEY_H__

#include "reg52.h"

sbit key1 = P3^1;
sbit key2 = P3^0;
sbit key3 = P3^2;
sbit key4 = P3^3;

//��֧������
unsigned char keyscan();		//���������Ƿ��£�����1��2��3��4�ֱ�Ϊkey1,key2,key3,key4���µķ���ֵ��0Ϊû�а�������
void keydelay();				//�ӳ�����

#endif