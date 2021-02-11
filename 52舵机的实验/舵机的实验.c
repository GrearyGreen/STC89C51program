#include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

sbit xia = P1^5;
sbit shang = P1^4;
sbit k3 = P3^5;
sbit k4 = P3^4;
sbit k5 = P3^3;

u8 jiaodu,count;

void delay();
void key();
void Time_interrupt_one();
void Time_interrupt_two();

void main()
{
	Time_interrupt_one();
	Time_interrupt_two();
	while(1)
	{
		key();
	}
}

void Time_interrupt_one()
{
	TMOD|=0x01;
	TH0 = 0xFE;
	TL0 = 0x33;
	ET0 = 1;
	EA = 1;
	TR0 = 1;
}

void Time_interrupt_two()
{
	TMOD|=0x10;
	TH0 = 0xFE;
	TL0 = 0x33;
	ET1 = 1;
	EA = 1;
	TR1 = 1;
}

void delay()
{
	u8 a,b;
    for(b=249;b>0;b--)
        for(a=17;a>0;a--);
}

void key()
{
	if(k3 == 0)
	{
		delay();
		if(k3 == 0)
		{
			jiaodu++;
			count = 0;
			if(jiaodu == 6)
			{
				jiaodu = 5;
			}
			while(k3 == 0);
		}
	}
	if(k4 == 0)
	{
		delay();
		if(k4 == 0)
		{
			jiaodu--;
			count = 0;
			if(jiaodu == 0)
			{
				jiaodu = 1;
			}
			while(k4 == 0);
		}
	}
}

void Time0() interrupt 1
{
	TH0 = 0xFE;
	TL0 = 0x33;
	
	if(count < jiaodu)
	{
		xia = 1;
	}else{
		xia = 0;
	}
	
	count += 1;
	count %= 40;
}

void Time1() interrupt 3
{
	static u16 i;
	TH1 = 0xFE;
	TL1 = 0x33;
	i++;
	if(i == 1000)
	{
		i = 0;
	}
}
