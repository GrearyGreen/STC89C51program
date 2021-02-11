#include "reg52.h"
//digital tube �����

sbit LSA_138 = P2^4;
sbit LSB_138 = P2^3;
sbit LSC_138 = P2^2;

typedef unsigned int u16;
typedef unsigned char u8;

u8 code Didital_tube_number[] = {0x3f,0x06,0x5b,
			0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
/*0~9��������������ϵ�16���Ʊ���
code��ָ������洢��ROM
ROM:��������ʱ�����ɸ��ĵ����ݵĵط�*/
//ʹ��ʱ����ֵ�����ߣ�
//����P0 = Didital_tube_number[0];

void main()
{
	LSA_138 = 0;
	LSB_138 = 0;
	LSC_138 = 0;
	P0 = Didital_tube_number[0];
	while(1);
}