#include <reg52.h>
//74H595Ϊ��λ�Ĵ������������룬�������
//ԭ���洢������8λ���ݺ�һ�����

sbit DATA = P3^4;//����
sbit OUTPUT = P3^5;//����ܽ�
sbit STORAGE = P3^6;//�洢�ܽ�

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
	STORAGE = 0;//�洢�ܽŵ͵�ƽ
	OUTPUT = 0;//����ܽŵ͵�ƽ
	while(1)
	{
		for(k=0;k<8;k++)
		{
			DATA = 1;//��������Ϊ�ߵ�ƽ
			STORAGE = 1;//�����أ����ݽ���洢��
			STORAGE = 0;//�ر����ݴ���
			OUTPUT = 1;//�����أ����ݴӴ洢�����
			OUTPUT = 0;//�ر��������
			delay(1);
		}
		for(k=0;k<8;k++)
		{
			DATA = 0;//��������Ϊ�͵�ƽ
			STORAGE = 1;//�����أ����ݽ���洢��
			STORAGE = 0;//�ر����ݴ���
			OUTPUT = 1;//�����أ����ݴӴ洢�����
			OUTPUT = 0;//�ر��������
			delay(1);
		}
	}
}