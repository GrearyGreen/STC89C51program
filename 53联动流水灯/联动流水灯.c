#include "reg52.h"
#include "intrins.h"

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
	u8 k;
	P2 = 0xfe;
	delay(1);
	while(1)
	{
		for(k=0;k<7;k++)
		{
			P2 = _crol_(P2,1);
			delay(1);
		}
		for(k=0;k<7;k++)
		{
			P2 = _cror_(P2,1);
			delay(1);
		}
	}
}