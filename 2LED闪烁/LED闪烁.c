#include "reg52.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit led = P2^0;

void delay(u16 n)
{
	u16 i,j;
	for(i=0;i<n;i++)
		for(j=0;j<54053;j++);
}

void main()
{
		while(1)
	{
		led = 0;
		delay(1);
		led = 1;
		delay(1);
	}
}