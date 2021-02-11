#ifndef __OLED_12864_H__
#define __OLED_12864_H__

#include <reg52.h>
#include "IIC.h"
#include "codetab.h"

#define uint8_t  unsigned char
#define uint16_t unsigned int

#define OLED_12864_Address 0x78		//物理焊接导致的地址，ISP通信会有不同的地址
//前七位有物理焊接地址和芯片定义地址，最后一位是读写位，0，写入，1，读取

bit OLED12864_Write_Commmand(uint8_t cmd, bit start, bit stop);
//bit OLED12864_Write_Data(uint8_t dat, bit start, bit stop);
bit OLED12864_Write_Continuous_Data(uint8_t* dat, uint8_t count, bit start, bit stop);
bit OLED12864_Write_Same_Continuous_Data(uint8_t dat, uint8_t count);
void OLED12864_SetPos(uint8_t x, uint8_t y);
void OLED12864_Fill(uint8_t fill_Data);
void OLED12864_CLS_LINE(uint8_t rowIndex);
void OLED12864_ON(void);
void OLED12864_OFF(void);
bit OLED12864_Initial();//初始化
void OLED12864_CLS();//清屏
void OLED12864_ShowStr(uint8_t x, uint8_t y, uint8_t ch[], uint8_t TextSize);//字符串
//注意：x:0~127;y:0~7;ch[]为字符串，（修改过，可以直接英文字符串），TextSize -- (1:6*8 ; 2:8*16)
void OLED12864_ShowChinese(uint8_t x, uint8_t y, uint8_t N, uint8_t CH_Array[]);//中文
//x,y同上，N代表在数组中的第几个汉字，CH_Array[]是codetab.h中字符组名F16x16_1[]
void OLED12864_DrawBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t BMP[]);//图片
//通常x0=0,y0=0,x1=128,y1=8,全屏显示，BMP[]就是codetab.h中的图片数组

#endif
