#ifndef _MG90S_H_
#define _MG90S_H_

#include <reg52.h>

sbit shang_huang = P3^0;
sbit shang_hong = P3^1;
sbit shang_zong = P3^2;
sbit xia_huang = P3^3;
sbit xia_hong = P3^4;
sbit xia_zong = P3^5;

void delay0();
void delay_0();
void delay1();
void delay2();
void delay3();
void delay4();

void run_0();
void run_45();
void run_90();
void run_135();
void run_180();

#endif