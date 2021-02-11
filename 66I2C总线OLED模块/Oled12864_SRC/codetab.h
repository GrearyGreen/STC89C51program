#ifndef __CODETAB_H__ 
#define __CODETAB_H__ 
  
#define uint8_t unsigned char
  
/***************************16*16 Chinese, common gnd - column style - reverse output*********/  
extern uint8_t code F16x16_1[];//中文字符字组1
extern uint8_t code F16x16_2[];//中文字符字组2
//阴码，列行式，点阵：80，索引：16，逆向，十六进制数，输出索引文件，输出精简格，输出紧凑格式，像素大小：8，C51格式
  
/************************************6*8************************************/  
extern const uint8_t code F6x8[][6];//不清晰字符
/****************************************8*16************************************/  
extern const uint8_t code F8X16[];//清晰的256个常用字符 
  
extern uint8_t code BMPimage[];//图片数据
  
#endif  