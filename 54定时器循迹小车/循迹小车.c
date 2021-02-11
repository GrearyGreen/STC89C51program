#include "reg52.h"
#include "PWM.h"

sbit IN_OUT1_R = P3^1;
sbit IN_OUT2_L = P3^0;

unsigned int left_time = 60;
unsigned int right_time = 80;

void main()
{
	int_time1();
	int_time2();
	while(1)
	{
		if((IN_OUT1_R == 0)&&(IN_OUT2_L == 0))
			stop();
		if((IN_OUT1_R == 1)&&(IN_OUT2_L == 0))
			left();
		if((IN_OUT1_R == 0)&&(IN_OUT2_L == 1))
			right();
		if((IN_OUT1_R == 1)&&(IN_OUT2_L == 1))
			stright();
	}
}