#include "reg52.h"
//digital tube 数码管

sbit LSA_138 = P2^4;
sbit LSB_138 = P2^3;
sbit LSC_138 = P2^2;

typedef unsigned int u16;
typedef unsigned char u8;

u8 code Didital_tube_number[] = {0x3f,0x06,0x5b,
			0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
/*0~9的数字在数码管上的16进制编码
code是指定将其存储到ROM
ROM:程序运行时，不可更改的数据的地方*/
//使用时，赋值给总线，
//例如P0 = Didital_tube_number[0];

void main()
{
	LSA_138 = 0;
	LSB_138 = 0;
	LSC_138 = 0;
	P0 = Didital_tube_number[0];
	while(1);
}