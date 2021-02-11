#include "reg52.h"
#include "DS18B20.h"

#include <reg52.h>

#define Num P0

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA = P2^4;
sbit LSB = P2^3;
sbit LSC = P2^2;

u8 DisplayData[8];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,
				0x6d,0x7d,0x07,0x7f,0x6f};

void DigDisplay();
void datapros(int temperature);

void main()
{	
	int DS_Tem;
	while(1)
	{
		DS_Tem = DS18B20_Temperature();
		DigDisplay();
		datapros(DS_Tem);
		DigDisplay();
	}		
}

void datapros(int temperature) 	 
{
	int H_temperature,L_temperature;
   	float tp;  
	if(temperature< 0)
  	{
		DisplayData[0] = 0x40;
		temperature = temperature-1;
		temperature = ~temperature;
		tp = temperature;
		temperature = tp*0.0625*100;
		H_temperature = tp*0.0625*1000;
		L_temperature = tp*0.0625*10000;
  	}
 	else
  	{			
		DisplayData[0] = 0x00;
		tp = temperature;
		temperature = tp*0.0625*100;
		H_temperature = tp*0.0625*1000;
		L_temperature = tp*0.0625*10000;
	}
	DisplayData[1] = smgduan[temperature / 10000];
	DisplayData[2] = smgduan[temperature % 10000 / 1000];
	DisplayData[3] = smgduan[temperature % 1000 / 100] | 0x80;
	DisplayData[4] = smgduan[temperature % 100 / 10];
	DisplayData[5] = smgduan[temperature % 10];
	DisplayData[6] = smgduan[H_temperature % 10];
	DisplayData[7] = smgduan[L_temperature % 10];
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
		delay1ms();
		Num = 0x00;
	}		
}
