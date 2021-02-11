#include <reg52.h>

sbit ENA = P1^0;
sbit IN1 = P1^1;
sbit IN2 = P1^2;
sbit IN3 = P1^3;
sbit IN4 = P1^4;
sbit ENB = P1^5;
sbit key = P3^2;

void delay(unsigned int z);
void keypot();

void main()
{
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
	while(1)
	{
		keypot();
	}
}

void keypot()
{
	if(key == 0)
	{
		delay(10);
		if(key == 0)
		{
			ENA = ~ENA;
			ENB = ~ENB;
		}
		while(!key);
	}
}

void delay(unsigned int z)
{
	unsigned int x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
