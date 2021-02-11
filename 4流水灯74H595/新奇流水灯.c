#include <reg52.h>
//74H595为移位寄存器，串行输入，并行输出
//原本存储器存入8位数据后，一起输出

sbit DATA = P3^4;//数据
sbit OUTPUT = P3^5;//输出管脚
sbit STORAGE = P3^6;//存储管脚

typedef unsigned int u16;
typedef unsigned char u8;

void delay(u16 n)
{
	u16 i,j;
	for(i=0;i<n;i++)
		for(j=0;j<54053;j++);
}

void main()
{
	u8 k;
	STORAGE = 0;//存储管脚低电平
	OUTPUT = 0;//输出管脚低电平
	while(1)
	{
		for(k=0;k<8;k++)
		{
			DATA = 1;//设置数据为高电平
			STORAGE = 1;//上升沿：数据进入存储器
			STORAGE = 0;//关闭数据储存
			OUTPUT = 1;//上升沿：数据从存储器输出
			OUTPUT = 0;//关闭数据输出
			delay(1);
		}
		for(k=0;k<8;k++)
		{
			DATA = 0;//设置数据为低电平
			STORAGE = 1;//上升沿：数据进入存储器
			STORAGE = 0;//关闭数据储存
			OUTPUT = 1;//上升沿：数据从存储器输出
			OUTPUT = 0;//关闭数据输出
			delay(1);
		}
	}
}