#include "reg52.h"
#include "intrins.h"

sbit DATA=P3^4;
sbit OUTPUT=P3^5;
sbit STORAGE=P3^6;

typedef unsigned int u16;
typedef unsigned char u8;

void delay(u16 n)
{
	u16 i,j;
	for(i=0;i<n;i++)
		for(j=0;j<54053;j++);
}

void main()
{
	u8 k,o;
	u8 x_data = 0xfe;
	u8 in_data = x_data;
	STORAGE = 0;
	OUTPUT = 0;
	while(1)
	{
		for(k=0;k<7;k++)
		{
			for(o=0;o<8;o++)
			{
				DATA = in_data>>7;
				in_data <<= 1;
				STORAGE = 1;
				_nop_();
				_nop_();
				STORAGE = 0;
			}
			OUTPUT = 1;
			_nop_();
			_nop_();
			OUTPUT = 0;
			x_data = _crol_(x_data,1);
			in_data = x_data;
			delay(1);
		}
		//x_data = 0x7f;
		for(k=0;k<7;k++)
		{
			for(o=0;o<8;o++)
			{
				DATA = in_data>>7;
				in_data <<= 1;
				STORAGE = 1;
				_nop_();
				_nop_();
				STORAGE = 0;
			}
			OUTPUT = 1;
			_nop_();
			_nop_();
			OUTPUT = 0;
			x_data = _cror_(x_data,1);
			in_data = x_data;
			delay(1);
		}
	}
}