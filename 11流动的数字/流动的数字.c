#include "reg52.h"

sbit LSA_138 = P2^4;
sbit LSB_138 = P2^3;
sbit LSC_138 = P2^2;

typedef unsigned int u16;
typedef unsigned char u8;

u8 code Digital_tube_number[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void delay(void);
void decoder_138(u8 i);

void main()
{
	u8 h;
	//数码管前期有空白
	for(h=0;h<10;h++)
	{
		decoder_138(h);
	}
	while(1)
	{
		//进入循环，0-9循环显示
		for(h=10;h<20;h++)
		{
			decoder_138(h);
		}
	}
}

void decoder_138(u8 i)
{
	u8 k,n,j;
	if(i<7)
	{
		//前期数码管有空白，不能全部刷新数码管
		k=i+1;
	}else{
		k=8;
	}
	for(j=0;j<20;j++)
	{
		//使数字在数码管上停留一段时间
		for(n=0;n<k;n++)
		{
			switch(n)
			{
				case 0:
					LSA_138 = 0;LSB_138 = 0;LSC_138 = 0;break;
				case 1:
					LSA_138 = 0;LSB_138 = 0;LSC_138 = 1;break;
				case 2:
					LSA_138 = 0;LSB_138 = 1;LSC_138 = 0;break;
				case 3:
					LSA_138 = 0;LSB_138 = 1;LSC_138 = 1;break;
				case 4:
					LSA_138 = 1;LSB_138 = 0;LSC_138 = 0;break;
				case 5:
					LSA_138 = 1;LSB_138 = 0;LSC_138 = 1;break;
				case 6:
					LSA_138 = 1;LSB_138 = 1;LSC_138 = 0;break;
				case 7:
					LSA_138 = 1;LSB_138 = 1;LSC_138 = 1;break;
			}
			P0 = Digital_tube_number[(i-n)%10];//对与大于10的数字处理
			delay();//延迟
			P0 = 0x00;//消影
		}
	}
}

void delay(void)   //延迟1ms
{
    u8 a,b;
    for(b=133;b>0;b--)
        for(a=6;a>0;a--);
}