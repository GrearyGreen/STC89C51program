#include "reg52.h"
#include ".\\Oled12864_SRC\\IIC.h"
#include ".\\Oled12864_SRC\\OLED_12864.h"
#include ".\\Oled12864_SRC\\codetab.h"

//修改OLED管脚在IIC.H文件中
//修改字符库在codetab.h中
//main函数中主要调用的就是OLED_12864.h的函数

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