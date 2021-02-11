#include "reg51.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA_138 = P2^4;
sbit LSB_138 = P2^3;
sbit LSC_138 = P2^2;

#define GPIO_KEY P1
#define GPIO_DIG P0

u8 KeyValue = 16;

u8 code Digital_tube_number[] = {0x70,0x07,0x7f,0x6f,
							0x40,0x66,0x6d,0x7d,
							0x76,0x06,0x5b,0x4f,
							0x49,0x80,0x3f,0x48,0x00};

void delay();
void Keydown();

void main()
{
	LSA_138 = 0;
	LSB_138 = 0;
	LSC_138 = 0;
	while(1)
	{
		Keydown();
		GPIO_DIG = Digital_tube_number[KeyValue];
	}
}

void delay()
{
	u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void Keydown()
{
	u8 a;
	GPIO_KEY = 0x0f;
	if(GPIO_KEY != 0x0f)
	{
		delay();
		if(GPIO_KEY != 0x0f)
		{
			GPIO_KEY = 0x0f;
			switch(GPIO_KEY)
			{
				case 0x07:KeyValue = 0;break;
				case 0x0b:KeyValue = 1;break;
				case 0x0d:KeyValue = 2;break;
				case 0x0e:KeyValue = 3;break;
			}
			GPIO_KEY = 0xf0;
			switch(GPIO_KEY)
			{
				case 0x70:KeyValue = KeyValue;break;
				case 0xb0:KeyValue = KeyValue + 4;break;
				case 0xd0:KeyValue = KeyValue + 8;break;
				case 0xe0:KeyValue = KeyValue + 12;break;
			}
			while((a<50)&&(GPIO_KEY != 0xf0))
			{
				delay();
				a++;
			}
		}
	}
}
