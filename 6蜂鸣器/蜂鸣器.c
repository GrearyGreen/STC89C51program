#include <reg52.h>

sbit buzzer=P1^5;

typedef unsigned int u16;
typedef unsigned char u8;

void delay(u16 n)
{
	while(n--);
}

void main()
{
	u16 i;
	while(1)
	{
		for(i=200;i>0;i--)
		{
			buzzer=~buzzer;
			delay(100);
		}
		for(i=300;i>0;i--)
		{
			buzzer=~buzzer;
			delay(200);
		}
	}
}