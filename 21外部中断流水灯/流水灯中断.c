#include "reg52.h"
#include "intrins.h"

#define led P2
sbit key_3 = P3^2;

typedef unsigned int u16;
typedef unsigned char u8;

void key_interrupt();//中断程序
void delay();//延迟0.5秒的程序
void stopover();//延迟10ms

void main()
{
	u8 i;
	key_interrupt();//载入中断
	led = 0xfe;
	delay();
	while(1)
	{
		for(i = 0;i < 7;i++)
		{
			led = _crol_(P2,1);
			delay();
		}
		for(i = 0;i < 7;i++)
		{
			led = _cror_(P2,1);
			delay();
		}
	}
}

void key_interrupt()
{
	//中断开启
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}

void delay()
{
	u8 a,b,c;
    for(c=205;c>0;c--)
        for(b=116;b>0;b--)
            for(a=9;a>0;a--);
}

void stopover()
{
	u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void key3() interrupt 0		//不用定义，直接使用
{
	if(key_3 == 0)//判断第一次按键
	{
		stopover();
		if(key_3 == 0)
		{
			delay();//防止下一条死循环语句被执行
			while(key_3);
			delay();//防止一直进入中断
			//while(key_3)是等待再次按键
			//但是按键后，没有延迟的话，会判定为第一次按键
			//从而导致程序暂停，而未开始。
		}
	}
}
