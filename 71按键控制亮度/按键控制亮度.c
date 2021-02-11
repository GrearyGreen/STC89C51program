#include "reg52.h"
#include "PWM.h"
#include "oledkey.h"

sbit LED = P1^0;

void main()
{
	u16 max,opp;
	Timer0Init();
	max = 1000;
	opp = 500;
	while(1)
	{
		LED = Time0_Flag(max,opp);
		switch(keyscan())
		{
			case 0:break;
			case 1:opp+=50;break;
			case 2:opp-=50;break;
			case 3:opp = 500;break;
			case 4:opp = 0;break;
			default:break;
		}
		if(opp < 100)
		{
			opp +=50;
		}
		if(opp > 900)
		{
			opp -=50;
		}
	}
}