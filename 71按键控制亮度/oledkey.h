#ifndef __OLEDKEY_H__
#define __OLEDKEY_H__

#include "reg52.h"

sbit key1 = P3^1;
sbit key2 = P3^0;
sbit key3 = P3^2;
sbit key4 = P3^3;

//不支持连按
unsigned char keyscan();		//独立按键是否按下，返回1，2，3，4分别为key1,key2,key3,key4按下的返回值，0为没有按键按下
void keydelay();				//延迟消抖

#endif