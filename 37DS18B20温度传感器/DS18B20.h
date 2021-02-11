#ifndef _DS18B20_H_
#define _DS18B20_H_

#include <reg52.h>
#include <intrins.h>

//定义无符号的类型
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit Serial_port=P3^7;
//通信管脚在P3^7口

void delay1ms();

//单片机对DS18B20温度传感器的操作
uchar DS18B20_Star();
void DS18B20_Write(uchar Send_data);
uchar DS18B20_Read();
//测量温度
void  DS18B20_measure();
//发出读取温度指令
void  DS18B20_ReadTemp();

//读取温度
int DS18B20_Temperature();

#endif