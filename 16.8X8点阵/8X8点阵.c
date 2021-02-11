#include "reg52.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit DATA = P3^4;
sbit Storage = P3^6;
sbit Output = P3^5;

fang_arrays[] = {0x00,0x12,0x14,0x5D,0x15,0x16,0x10,0x00};
fang_line[] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
#define LED P0

void delay();
void Send(u8 fractional_data);

void main()
{
	u8 i;
	while(1)
	{
		P0 = 0x7f;
		for(i=0;i<8;i++)
		{
			P0 = fang_line[i];
			Send(fang_arrays[i]);
			delay();
			Send(0x00);
		}
	}
}

void delay()
{
	u8 a,b;
    for(b=19;b>0;b--)
        for(a=1;a>0;a--);
}

void Send(u8 fractional_data)
{
	u8 a;
	Storage = 0;
	Output = 0;
	for(a=0;a<8;a++)
	{
		DATA = fractional_data>>7;
		fractional_data <<= 1;
		Storage = 1;
		_nop_();
		_nop_();
		Storage = 0;
	}
	Output = 1;
	_nop_();
	_nop_();
	Output = 0;
}
