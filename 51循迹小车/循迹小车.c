#include "reg52.h"
#include "PWM.h"

sbit IN_OUT1_R = P3^1;
sbit IN_OUT2_L = P3^0;

void main()
{
	while(1)
	{
		if((IN_OUT1_R == 0)&&(IN_OUT2_L == 0))
			stright();
		if((IN_OUT1_R == 1)&&(IN_OUT2_L == 0))
			right();
		if((IN_OUT1_R == 0)&&(IN_OUT2_L == 1))
			left();
		if((IN_OUT1_R == 1)&&(IN_OUT2_L == 1))
			stop();
	}
}