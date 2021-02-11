#include "reg52.h"

sbit LSA_138 = P2^4;
sbit LSB_138 = P2^3;
sbit LSC_138 = P2^2;

typedef unsigned int u16;
typedef unsigned char u8;

u8 code Digital_tube_number[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay(u16 i);
void Decoder_138();//从第一个数码管扫描到最后一个数码管

void main()
{
	while(1)
	{
		Decoder_138();
	}
}

void delay(u16 i)
{
	while(i--);
}

void Decoder_138()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case 0:
				LSA_138 = 0;LSB_138 = 0;LSC_138 = 0; break;
			case 1:
				LSA_138 = 0;LSB_138 = 0;LSC_138 = 1; break;
			case 2:
				LSA_138 = 0;LSB_138 = 1;LSC_138 = 0; break;
			case 3:
				LSA_138 = 0;LSB_138 = 1;LSC_138 = 1; break;
			case 4:
				LSA_138 = 1;LSB_138 = 0;LSC_138 = 0; break;
			case 5:
				LSA_138 = 1;LSB_138 = 0;LSC_138 = 1; break;
			case 6:
				LSA_138 = 1;LSB_138 = 1;LSC_138 = 0; break;
			case 7:
				LSA_138 = 1;LSB_138 = 1;LSC_138 = 1; break;
		}
		P0 = Digital_tube_number[i];
		delay(100);//延迟
		P0 = 0x00;//消影：以免和下一个指令重影
	}
}