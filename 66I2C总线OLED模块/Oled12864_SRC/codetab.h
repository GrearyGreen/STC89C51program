#ifndef __CODETAB_H__ 
#define __CODETAB_H__ 
  
#define uint8_t unsigned char
  
/***************************16*16 Chinese, common gnd - column style - reverse output*********/  
extern uint8_t code F16x16_1[];//�����ַ�����1
extern uint8_t code F16x16_2[];//�����ַ�����2
//���룬����ʽ������80��������16������ʮ������������������ļ�����������������ո�ʽ�����ش�С��8��C51��ʽ
  
/************************************6*8************************************/  
extern const uint8_t code F6x8[][6];//�������ַ�
/****************************************8*16************************************/  
extern const uint8_t code F8X16[];//������256�������ַ� 
  
extern uint8_t code BMPimage[];//ͼƬ����
  
#endif  