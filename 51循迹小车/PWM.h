#ifndef __PWM_H_
#define __PWM_H_

#include "reg52.h"

sbit ENA = P3^6;
sbit ENB = P3^7;

sbit IN1 = P2^7;
sbit IN2 = P2^6;
sbit IN3 = P2^5;
sbit IN4 = P2^4;

void stop();
void stright();
void back();
void left();
void right();

void delay_L_min();
void delay_L_max();
void delay_R_min();
void delay_R_max();
void left_run();
void right_run();

#endif