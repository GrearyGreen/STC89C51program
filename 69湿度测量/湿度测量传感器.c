#include "DHT11.h"
#include <reg52.h>

#define Num P0

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA = P2^4;
sbit LSB = P2^3;
sbit LSC = P2^2;

sbit key = P3^1;

u8 DisplayData[8];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,
				0x6d,0x7d,0x07,0x7f,0x6f};

uchar	U8T_data_H = 0,		//温度的整数位
		U8T_data_L = 0,		//温度的小数位
		U8RH_data_H = 0,	//湿度的整数位
		U8RH_data_L = 0,	//湿度的小数位
		U8checkdata = 0;	//校验位

void DigDisplay();
void datapros();
void delay(void);
void keypoint();

void main()
{
	while(1)
	{
		keypoint();
//		RH();
		DigDisplay();
		datapros();
		DigDisplay();
	}		
}

void datapros()
{
	int H_humidity,L_humidity;
	H_humidity = U8RH_data_H;
	L_humidity = U8RH_data_L>>4;
	L_humidity = L_humidity*625;
	
   	//DisplayData[0]是符号位，但是暂时没有读取符号位的方法
	DisplayData[1] = smgduan[H_humidity / 100];
	DisplayData[2] = smgduan[H_humidity % 100 / 10];
	DisplayData[3] = smgduan[H_humidity % 10] | 0x80;
	DisplayData[4] = smgduan[L_humidity / 1000];
	DisplayData[5] = smgduan[L_humidity % 1000 / 100];
	DisplayData[6] = smgduan[L_humidity % 100 / 10];
	DisplayData[7] = smgduan[L_humidity % 10];
}

void delay(void)   //延时10ms
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
			RH();
		}
		while(!key);
	}
}

void DigDisplay()
{
	u8 i;
	for(i=0;i<6;i++)
	{
		switch(i)
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;
			case(1):
				LSA=0;LSB=0;LSC=1; break;
			case(2):
				LSA=0;LSB=1;LSC=0; break;
			case(3):
				LSA=0;LSB=1;LSC=1; break;
			case(4):
				LSA=1;LSB=0;LSC=0; break;
			case(5):
				LSA=1;LSB=0;LSC=1; break;
			case(6):
				LSA=1;LSB=1;LSC=0; break;
			case(7):
				LSA=1;LSB=1;LSC=1; break;
		}
		Num = DisplayData[7-i];
		Delay(10);
		Num = 0x00;
	}		
}
