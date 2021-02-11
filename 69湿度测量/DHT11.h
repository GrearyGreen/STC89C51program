#ifndef _DHT11_H_
#define _DHT11_H_

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

extern uchar U8FLAG;//防止死循环的计时器；
//2~255的u8计数器
extern uchar U8temp;//数据暂存
//读取的数据
extern uchar	U8T_data_H,		//温度的整数位
				U8T_data_L,		//温度的小数位
				U8RH_data_H,	//湿度的整数位
				U8RH_data_L,	//湿度的小数位
				U8checkdata;	//校验位
//校验的数据
extern uchar	U8T_data_H_temp,		//温度的整数位
				U8T_data_L_temp,		//温度的小数位
				U8RH_data_H_temp,		//湿度的整数位
				U8RH_data_L_temp,		//湿度的小数位
				U8checkdata_temp;		//校验位
//每8位数据的暂存数据
extern uchar U8comdata;

void Delay(uint j);
void Delay_10us(void);

//单片机对DHT11湿度传感器的操作
//判断通信中的0，1
void COM(void);
//读取数据，温度，湿度
void RH(void);

#endif