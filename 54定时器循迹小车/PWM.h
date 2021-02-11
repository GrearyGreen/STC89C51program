#ifndef _PWM_H_
#define _PWM_H_

#include <reg52.h>

#define TEMP1 0XFF
#define TEMP2 0XA3

sbit ENA = P3^6;
sbit ENB = P3^7;

sbit IN1 = P2^7;
sbit IN2 = P2^6;
sbit IN3 = P2^5;
sbit IN4 = P2^4;

extern unsigned int left_time;
extern unsigned int right_time;

void int_time1();
void int_time2();

void stop();
void stright();
void back();
void left();
void right();

#endif