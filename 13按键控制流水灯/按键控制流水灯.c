#include "reg52.h"
#include "intrins.h"

sbit key = P3^1;
#define led P2

typedef unsigned int u16;
typedef unsigned char u8;

void delay1();
void delay2();
void delay3();
u8 keypoint();

void main()
{
	u8 k;
	led = 0xfe;
	delay1();
	if(keypoint() == 1)
			{
				delay2();
				while(key);
				delay2();
			}
	while(1)
	{
		for(k=0;k<7;k++)
		{
			led = _crol_(led,1);
			delay2();
			if(keypoint() == 1)
			{
				delay2();
				while(key);
				delay2();
			}
		}
		for(k=0;k<7;k++)
		{
			led = _cror_(led,1);
			delay2();
			if(keypoint() == 1)
			{
				delay2();
				while(key);
				delay2();
			}
		}
	}
}

void delay1(void)   //10ms
{
    u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void delay2(void)   //
{
    u8 a,b,c;
    for(c=7;c>0;c--)
        for(b=74;b>0;b--)
            for(a=95;a>0;a--);
}

void delay3(void)   
{
    u8 a,b,c;
    for(c=46;c>0;c--)
        for(b=152;b>0;b--)
            for(a=70;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}


u8 keypoint()
{
	if(key == 0)
	{
		delay1();
		if(key == 0)
		{
			return 1;
		}
		while(!key);
	}
	return 0;
}