#include "reg52.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit led = P2^0;

void Time_interrupt();

void main()
{
	Time_interrupt();
	while(1);
}

void Time_interrupt()
{
	TMOD|=0x01;
	TH0 = 0xFC;		//定时1ms
	TL0 = 0x18;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void Time0() interrupt 1
{
	static u16 i;
	TH0 = 0xFC;
	TL0 = 0x18;
	i++;
	if(i == 1000)	//定时1s
	{
		i = 0;
		led =~ led;
	}
}
