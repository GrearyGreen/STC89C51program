#include "reg52.h"
#include "intrins.h"

sbit buzzer=P1^5;

typedef unsigned int u16;
typedef unsigned char u8;

void Do(void)   //中音 1 delay1ms912us
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=166;b>0;b--)
            for(a=10;a>0;a--);
}

void Re(void)   //中音 2 delay1ms703us
{
    unsigned char a,b;
    for(b=83;b>0;b--)
        for(a=19;a>0;a--);
}

void Mi(void)   //中音 3 delay1ms517us
{
    unsigned char a,b;
    for(b=7;b>0;b--)
        for(a=215;a>0;a--);
}

void Fa(void)   //中音 4 delay1ms432us
{
    unsigned char a,b;
    for(b=220;b>0;b--)
        for(a=5;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}

void Sol(void)   //中音 5 delay1ms275us
{
    unsigned char a,b;
    for(b=9;b>0;b--)
        for(a=140;a>0;a--);
}

void La(void)   //中音 6 delay1ms136us
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=206;b>0;b--)
            for(a=4;a>0;a--);
}

void Si(void)   //中音 7 delay1ms12us
{
    unsigned char a,b;
    for(b=47;b>0;b--)
        for(a=20;a>0;a--);
}

void H_Do(void)   //高音 1 delay956us
{
    unsigned char a,b;
    for(b=83;b>0;b--)
        for(a=10;a>0;a--);
}

void main()
{
	u16 i;
	while(1)
	{
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			Do();
		}
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			Re();
		}
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			Mi();
		}
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			Fa();
		}
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			Sol();
		}
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			La();
		}
		for(i=0;i<100;i++)
		{
			buzzer=~buzzer;
			H_Do();
		}
	}
}