#ifndef _I2C_H_
#define _I2C_H_

#include <reg52.h>

sbit SCL = P2^1;
sbit SDA = P2^0;
//板子上，24c20接在这两个管脚上
//八个管脚六个已焊死，地址接地，0，0，0
//一个电源一个接地，一个写保护接地（可读写）（接高时，只读）

void I2CStar();
unsigned char I2C_SendByte(unsigned char Send_data);
unsigned char I2C_ReadByte();
void I2CStop();

void E2Write(unsigned char address,unsigned char send_data);
//将数据写入EEPROM中
unsigned char E2Read(unsigned char address);
//将数据从EEPROM中读出

#endif