#include "reg52.h"
#include ".\\Oled12864_SRC\\IIC.h"
#include ".\\Oled12864_SRC\\OLED_12864.h"
#include ".\\Oled12864_SRC\\codetab.h"

//�޸�OLED�ܽ���IIC.H�ļ���
//�޸��ַ�����codetab.h��
//main��������Ҫ���õľ���OLED_12864.h�ĺ���

void main()
{
	OLED12864_Initial();
	OLED12864_CLS();
	while(1)
	{
		OLED12864_ShowStr(0,0,"beautifully",1);
		OLED12864_ShowStr(0,1,"beautifully",2);
		OLED12864_ShowChinese(0,3,0,F16x16_2);
		OLED12864_ShowChinese(16,3,1,F16x16_2);
		OLED12864_ShowChinese(32,3,2,F16x16_2);
		OLED12864_ShowChinese(48,3,3,F16x16_2);
//		
//		OLED12864_ShowChinese(0,5,4,F16x16_2);
//		OLED12864_ShowChinese(16,5,5,F16x16_2);
//		OLED12864_ShowChinese(32,5,6,F16x16_2);
//		OLED12864_ShowChinese(48,5,7,F16x16_2);
//		OLED12864_ShowStr(0,7,"beautifully",1);
		
//		OLED12864_DrawBMP(0,0,128,8,BMPimage);
//		OLED12864_ShowStr(0,6,"ZHEJIANG UNIVERSITY",1);
//		OLED12864_ShowStr(0,7,"OF SCIENCE&TECHNOLOGY",1);
//		OLED12864_ShowStr(0,0,"beautifully",1);
	}
}