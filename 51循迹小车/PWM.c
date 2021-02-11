#include "PWM.h"

void delay_L_min(void)
	//14us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=13;a>0;a--);
}

void delay_R_min(void)
	//60us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=20;a>0;a--);
}

void delay_L_max(void)
	//86us
{
    unsigned char a;
    for(a=28;a>0;a--);
}

void delay_R_max(void)
	//40us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=20;a>0;a--);
}

void left_run()
{
	ENA = 1;
	delay_L_max();
	ENA = ~ENA;
	delay_L_min();
	ENA = ~ENA;
}

void right_run()
{
	ENB = 1;
	delay_R_min();
	ENB = ~ENB;
	delay_R_max();
	ENB = ~ENB;
}

void stop()
{
	ENA = 0;
	ENB = 0;
}

void stright()
{
	IN1 = 0;
	IN2 = 1;
	IN3 = 1;
	IN4 = 0;
	left_run();
	right_run();
	right_run();
	left_run();
}

void back()
{
	IN1 = 1;
	IN2 = 0;
	IN3 = 0;
	IN4 = 1;
	left_run();
	right_run();
	right_run();
	left_run();
}

void left()
{
	IN1 = 1;
	IN2 = 0;
	IN3 = 1;
	IN4 = 0;
	left_run();
	right_run();
	right_run();
	left_run();
}

void right()
{
	IN1 = 0;
	IN2 = 1;
	IN3 = 0;
	IN4 = 1;
	left_run();
	right_run();
	right_run();
	left_run();
}
