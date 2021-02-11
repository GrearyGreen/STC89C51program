#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;
sbit key3 = P3^2;

void delay();
void inter0();

void main()
{
	inter0();
	while(1);
}

void delay()
{
	u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void inter0()
{
	//EA,EX0,IT0���ļ�reg52.h�о��ж��壬��ֱ��ʹ��
	//EA���ܿ��أ�EX0���ⲿ�жϿ��أ�IT0���жϷ�ʽ
	//IT0 = 0,�͵�ƽ������IT0 = 1,�½��ش���
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}

void keyint0() interrupt 0 using 1
	//�����������ǰ����Ҫ����������interrupt0()�󣬼��������ⲿ�жϵĵ���
{
	delay();
	if(key3 == 0)
	{
		led =~ led;
	}
}
