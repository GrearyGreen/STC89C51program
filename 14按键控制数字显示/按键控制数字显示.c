#include "reg52.h"

sbit LSA_138 = P2^4;
sbit LSB_138 = P2^3;
sbit LSC_138 = P2^2;
//138ÒëÂëÆ÷

sbit key1=P3^1;
sbit key2=P3^0;
sbit key3=P3^2;
sbit key4=P3^3;
//¶ÀÁ¢°´¼ü

typedef unsigned int u16;
typedef unsigned char u8;

u8 code Didital_tube_number[] = {0x3f,0x06,0x5b,
			0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay();
u8 keypoint1();
u8 keypoint2();
u8 keypoint3();
u8 keypoint4();
void Decoder_138(u8 i,u8 j);

void main()
{
	u8 k=0,l=0;
	while(1)
	{
		Decoder_138(k,l);
		if(keypoint1())
			k += 1;
		delay();
		delay();
		Decoder_138(k,l);
		if(keypoint2())
			k -= 1;
		delay();
		delay();
		Decoder_138(k,l);
		if(keypoint3())
			l += 1;
		delay();
		delay();
		Decoder_138(k,l);
		if(keypoint4())
			l -= 1;
		delay();
		delay();
	}
}

void delay()
{
	u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

u8 keypoint1()
{
	if(key1 == 0)
	{
		delay();
		if(key1 == 0)
		{
			return 1;
		}
	}
	return 0;
}

u8 keypoint2()
{
	if(key2 == 0)
	{
		delay();
		if(key2 == 0)
		{
			return 1;
		}
	}
	return 0;
}

u8 keypoint3()
{
	if(key3 == 0)
	{
		delay();
		if(key3 == 0)
		{
			return 1;
		}
	}
	return 0;
}

u8 keypoint4()
{
	if(key4 == 0)
	{
		delay();
		if(key4 == 0)
		{
			return 1;
		}
	}
	return 0;
}

void Decoder_138(u8 i,u8 j)
{
	switch(i%8)
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
	P0 = Didital_tube_number[j%10];
	delay();
	P0 = 0x00;
}