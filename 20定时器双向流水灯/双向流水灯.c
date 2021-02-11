#include "reg52.h"
#include "intrins.h"

#define Led P2

typedef unsigned int u16;
typedef unsigned char u8;

u8 code LED_Bus_data[] = {0xfe,0xfd,0xfb,0xf7,
0xef,0xdf,0xbf,0x7f};

void Time0_interrupt();

u8 j,k = 0;

void main()
{
	Time0_interrupt();
	while(1)
	{
		Led = LED_Bus_data[j];
	}
}

void Time0_interrupt()
{
	TMOD|=0x01;
    TH0 = 0xD8;
    TL0 = 0xF0;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void Time0() interrupt 1
{
	static u16 i = 0;
    TH0 = 0xD8;
    TL0 = 0xF0;
	i++;
	if(i == 20)
	{
		i = 0;
		if(j == 7)
		{
			k = 1;
		}else if(j == 0)
		{
			k = 0;
		}
		if(k == 0)
		{
			j++;
		}
		if(k == 1)
		{
			j--;
		}
	}
}
