#include "reg52.h"
#include "i2c.h"	

#define smg P0

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA=P2^4;
sbit LSB=P2^3;
sbit LSC=P2^2;

sbit k1=P3^1;	//控制EEPROM存储
sbit k2=P3^0;	//控制EEPROM读取
sbit k3=P3^2;	//数字加一
sbit k4=P3^3;	//数字清零

char E_data = 0;	//数码管显示的数字，存储的数据
u8 disp[3];		//个，十，百位上的数字
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,
				0x6d,0x7d,0x07,0x7f,0x6f};

void Delay();
void delay1ms();
void Keypros();
void datapros();	 
void DigDisplay();
					
void main()
{	
	while(1)
	{
		Keypros();	 
		datapros();	 
		DigDisplay();	
	}		
}

void Delay()
{
    u8 a,b,c;
    for(c=1;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}

void delay1ms()
{
    u8 a,b,c;
    for(c=1;c>0;c--)
        for(b=142;b>0;b--)
            for(a=2;a>0;a--);
}

void Keypros()
{
	if(k1==0)
	{
		Delay();
		if(k1==0)
		{
			E2Write(5,E_data);
		}
		while(!k1);
	}
	if(k2==0)
	{
		Delay();
		if(k2==0)
		{
			E_data = E2Read(5);
		}
		while(!k2);
	}
	if(k3==0)
	{
		Delay();
		if(k3==0)
		{
			E_data++;
			if(E_data>255)
				E_data=0;
		}
		while(!k3);		//防止重复加一
	}
	if(k4==0)
	{
		Delay();
		if(k4==0)
		{
			E_data = 0;
		}
		while(!k4);
	}		
}

void datapros()
{
	disp[0]=smgduan[E_data%10];
	disp[1]=smgduan[E_data/10%10];
	disp[2]=smgduan[E_data/100];		
}

void DigDisplay()
{
	//数码管显示
	u8 i;
	for(i=0;i<3;i++)
	{
		switch(i)
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;
			case(1):
				LSA=0;LSB=0;LSC=1; break;
			case(2):
				LSA=0;LSB=1;LSC=0; break;
		}
		smg = disp[i];
		delay1ms();
		smg = 0x00;
	}		
}