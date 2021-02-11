#ifndef __PWM_H__
#define __PWM_H__

#include "reg52.h"

typedef unsigned int u16;
typedef unsigned char u8;

//通过五线四项电机输出，输出的电压值最大2.82V

sbit PWM0 = P1^0;
sbit PWM1 = P1^1;
sbit PWM2 = P1^2;
sbit PWM3 = P1^3;

extern u16 timer0,timer1;

void Timer0Init();					//初始化定时器
void Timer1Init();

//周期最大65535us,opp同样
bit Time0_Flag(u16 max,u16 opp);	//大于opp输出0，小于opp输出1，max,总周期
bit Time1_Flag(u16 max,u16 opp);	//返回值为当前的PWM电平

//常用的20ms方波
void duoji0(u8 baifenbi);			//百分比baifenbi不能超过100
void duoji1(u8 baifenbi);			//PWM的控制管脚如上方定义
									//舵机0控制PWM0,PWM1，舵机1控制PWM2,PWM3

#endif