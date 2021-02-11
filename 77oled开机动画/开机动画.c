#include "reg52.h"
#include "codetab.h"
#include "IIC.h"
#include "OLED_12864.h"

void main()
{
	OLED12864_Initial();
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[0]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[1]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[2]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[3]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[4]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[5]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[6]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[7]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[8]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[9]);
//	OLED12864_DrawBMP(0,0,128,8,OLEDimage[10]);
	while(1)
	{
		OLED12864_DrawBMP(0,0,128,8,BMPimage);
	}
}