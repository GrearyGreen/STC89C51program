#include "reg52.h"
#include "USE.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit LED = P2;

void main()
{
	u8 led = LED;
	light(&led);
}