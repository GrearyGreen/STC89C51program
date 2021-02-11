#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit ENA = P3^6;
sbit ENB = P3^7;

sbit IN1 = P2^7;
sbit IN2 = P2^6;
sbit IN3 = P2^5;
sbit IN4 = P2^4;

void delay_L_min();
void delay_L_max();
void delay_R_min();
void delay_R_max();
void left_run();
void right_run();

void main()
{
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
	while(1)
	{
	left_run();
	right_run();
	}
}

void delay_L_min(void)
	//14us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=3;a>0;a--);
}

void delay_R_min(void)
	//47us
{
    unsigned char a,b;
    for(b=9;b>0;b--)
        for(a=1;a>0;a--);
}

void delay_L_max(void)
	//86us
{
    unsigned char a;
    for(a=38;a>0;a--);
}

void delay_R_max(void)
	//53us
{
    unsigned char a;
    for(a=20;a>0;a--);
}

void left_run()
{
	u8 i;
	ENA = 1;
	for(i=0;i<100;i++)
	{
		delay_L_max();
		ENA = ~ENA;
		delay_L_min();
		ENA = ~ENA;
	}
}

void right_run()
{
	u8 i;
	ENB = 1;
	for(i=0;i<100;i++)
	{
		delay_R_min();
		ENB = ~ENB;
		delay_R_max();
		ENB = ~ENB;
	}
}
