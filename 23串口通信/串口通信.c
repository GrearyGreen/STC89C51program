#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

void communications();

void main()
{
	communications();
	while(1);
}

void communications()
{
	//本次波特率为:4800
	TMOD |= 0X20;	//定时器中断方式控制 0010 0000
	TH1 = 0Xf3;		//10，选择的是定时器第三种模式，8位自动重装
	TL1 = 0XF3;		//高八位和低八位一样，数值的计算
					//串行口的工作方式位方式1
	//方式一的波特率计算 = （2^(SMOD)/32）*(T1的溢出率)
	//T1溢出率的计算方式 = （晶振/(12*(256 - TH1(或TH2)))）
	//综合计算，波特率(加倍) = (1M/16)*(256 - TH1(转换成十进制))
	//综合计算，TH1 = 256 - (1000000/波特率*16)
	//计算的值都取整数
	PCON = 0X80;	//串行口的波特率是否翻倍
	TR1 = 1;		//定时器开始工作
	SCON = 0X50;	//串行口的工作方式
	ES = 1;			//串口中断允许
	EA = 1;			//总中断允许
}

void request() interrupt 4
{
	//接收来自电脑的数据
	u8 receiveData;		//定义一个接收数据的变量
	receiveData = SBUF;	//从缓冲区中读取数据
	RI = 0;				//中断请求重置
	//发送给电脑的数据
	SBUF = receiveData;	//缓冲区存入发送的数据
	while(!TI);			//等待发送数据成功
	TI = 0;				//中断请求重置
}