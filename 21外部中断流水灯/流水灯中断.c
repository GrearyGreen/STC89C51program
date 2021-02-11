#include "reg52.h"
#include "intrins.h"

#define led P2
sbit key_3 = P3^2;

typedef unsigned int u16;
typedef unsigned char u8;

void key_interrupt();//�жϳ���
void delay();//�ӳ�0.5��ĳ���
void stopover();//�ӳ�10ms

void main()
{
	u8 i;
	key_interrupt();//�����ж�
	led = 0xfe;
	delay();
	while(1)
	{
		for(i = 0;i < 7;i++)
		{
			led = _crol_(P2,1);
			delay();
		}
		for(i = 0;i < 7;i++)
		{
			led = _cror_(P2,1);
			delay();
		}
	}
}

void key_interrupt()
{
	//�жϿ���
	EA = 1;
	EX0 = 1;
	IT0 = 1;
}

void delay()
{
	u8 a,b,c;
    for(c=205;c>0;c--)
        for(b=116;b>0;b--)
            for(a=9;a>0;a--);
}

void stopover()
{
	u8 a,b,c;
    for(c=5;c>0;c--)
        for(b=4;b>0;b--)
            for(a=248;a>0;a--);
}

void key3() interrupt 0		//���ö��壬ֱ��ʹ��
{
	if(key_3 == 0)//�жϵ�һ�ΰ���
	{
		stopover();
		if(key_3 == 0)
		{
			delay();//��ֹ��һ����ѭ����䱻ִ��
			while(key_3);
			delay();//��ֹһֱ�����ж�
			//while(key_3)�ǵȴ��ٴΰ���
			//���ǰ�����û���ӳٵĻ������ж�Ϊ��һ�ΰ���
			//�Ӷ����³�����ͣ����δ��ʼ��
		}
	}
}
