#include "reg52.h"
#include "intrins.h"

typedef unsigned int u16;
typedef unsigned char u8;

//发光二极管都接在P2口上，利用P2总线控制
//P2口的P要大写

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
			P2 = _crol_(P2,1);//将P2管脚的数据左移一位
			delay(1);
		}
		for(k=0;k<7;k++)
		{
			P2 = _cror_(P2,1);//将P2管脚的数据右移一位
			delay(1);
		}
	}
}