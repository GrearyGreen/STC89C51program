#include "reg52.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit led = P2^0;
sbit key = P3^1;

void delay(void);
void keypoint();

void main()
{
	while(1)
	{
		keypoint();
	}
}

void delay(void)   //ÑÓÊ±10ms
{
    u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void keypoint()
{
	if(key == 0)
	{
		delay();
		if(key == 0)
		{
			led = ~led;
		}
		while(!key);
	}
}