#ifndef __OLED_12864_H__
#define __OLED_12864_H__

#include <reg52.h>
#include "IIC.h"
#include "codetab.h"

#define uint8_t  unsigned char
#define uint16_t unsigned int

#define OLED_12864_Address 0x78		//�����ӵ��µĵ�ַ��ISPͨ�Ż��в�ͬ�ĵ�ַ
//ǰ��λ�������ӵ�ַ��оƬ�����ַ�����һλ�Ƕ�дλ��0��д�룬1����ȡ

bit OLED12864_Write_Commmand(uint8_t cmd, bit start, bit stop);
//bit OLED12864_Write_Data(uint8_t dat, bit start, bit stop);
bit OLED12864_Write_Continuous_Data(uint8_t* dat, uint8_t count, bit start, bit stop);
bit OLED12864_Write_Same_Continuous_Data(uint8_t dat, uint8_t count);
void OLED12864_SetPos(uint8_t x, uint8_t y);
void OLED12864_Fill(uint8_t fill_Data);
void OLED12864_CLS_LINE(uint8_t rowIndex);
void OLED12864_ON(void);
void OLED12864_OFF(void);
bit OLED12864_Initial();//��ʼ��
void OLED12864_CLS();//����
void OLED12864_ShowStr(uint8_t x, uint8_t y, uint8_t ch[], uint8_t TextSize);//�ַ���
//ע�⣺x:0~127;y:0~7;ch[]Ϊ�ַ��������޸Ĺ�������ֱ��Ӣ���ַ�������TextSize -- (1:6*8 ; 2:8*16)
void OLED12864_ShowChinese(uint8_t x, uint8_t y, uint8_t N, uint8_t CH_Array[]);//����
//x,yͬ�ϣ�N�����������еĵڼ������֣�CH_Array[]��codetab.h���ַ�����F16x16_1[]
void OLED12864_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t BMP[]);//ͼƬ
//ͨ��x0=0,y0=0,x1=128,y1=8,ȫ����ʾ��BMP[]����codetab.h�е�ͼƬ����

#endif
