#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;
sbit key3 = P3^2;

void delay();
void inter0();

void main()
{
	inter0();
	while(1);
}

void delay()
{
	u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void inter0()
{
	//EA,EX0,IT0在文件reg52.h中均有定义，可直接使用
	//EA是总开关，EX0是外部中断开关，IT0是中断方式
	//IT0 = 0,低电平触发，IT0 = 1,下降沿触发
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}

void keyint0() interrupt 0 using 1
	//这个函数调用前不需要声明，运行interrupt0()后，即可启动外部中断的调用
{
	delay();
	if(key3 == 0)
	{
		led =~ led;
	}
}
