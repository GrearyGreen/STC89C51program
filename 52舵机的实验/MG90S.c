#include "MG90S.h"

void run_0()
{
	unsigned char i;
	xia_hong = 1;
	xia_zong = 0;
	for(i = 0;i<100;i++)
	{
		xia_huang = 1;
		run_0();
		xia_huang = 0;
		delay_0();
	}
}

void delay0()
{
	unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=227;a>0;a--);
}

void delay_0()
{
	unsigned char a,b,c;
    for(c=16;c>0;c--)
        for(b=224;b>0;b--)
            for(a=1;a>0;a--);
}

void delay1()
{
	unsigned char a,b;
    for(b=102;b>0;b--)
        for(a=3;a>0;a--);
}
