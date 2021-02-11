#include "DS18B20.h"

//延迟函数
void delay1ms();

//单片机对DS18B20温度传感器的操作
uchar DS18B20_Star();
void DS18B20_Write(uchar Send_data);
uchar DS18B20_Read();
//测量温度
void  DS18B20_measure();
//发出读取温度指令
void  DS18B20_ReadTemp();

//读取温度
int DS18B20_Temperature();

void delay1ms()
{
	uint x;
	for(x=110; x>0; x--);
}

uchar DS18B20_Star()
{
	uchar i;
	Serial_port = 0;
	i = 70;	
	while(i--);
	Serial_port = 1;
	i = 0;	
	while(Serial_port)
	{
		delay1ms();
		i++;
		return 0;
	}
	return 1;
}

void DS18B20_Write(uchar Send_data)
{
	uchar i,j;
	for(i=0; i<8; i++)
	{
		Serial_port = 0;
		j++;
		Serial_port = Send_data & 0x01;
		j=6;
		while(j--); 
		Serial_port = 1;
		Send_data >>= 1;
	}
}

uchar DS18B20_Read()
{
	uchar Read_byte, Read_bit;
	uint i,j;	
	for(i=8; i>0; i--)
	{
		Serial_port = 0;
		_nop_();
		Serial_port = 1;
		_nop_();
		_nop_();
		Read_bit = Serial_port;
		Read_byte = (Read_byte >> 1) | (Read_bit << 7);						  
		j = 4;
		while(j--);
	}				
	return Read_byte;
}

void  DS18B20_measure()
{
	DS18B20_Star();
	delay1ms();
	DS18B20_Write(0xcc);	 
	DS18B20_Write(0x44);
}

void  DS18B20_ReadTemp()
{	

	DS18B20_Star();
	delay1ms();
	DS18B20_Write(0xcc);
	DS18B20_Write(0xbe);
}

int DS18B20_Temperature()
{
	int temperature = 0;
	uchar temperature_high,temperature_low;
	DS18B20_measure();			 	
	DS18B20_ReadTemp();
	//16位数据是连续读取，先读取低八位，再读取高八位
	temperature_low = DS18B20_Read();		
	temperature_high = DS18B20_Read();
	//将数据整合成16位整型
	temperature = temperature_high;
	temperature <<= 8;//将高八位移入整形的高八位
	temperature |= temperature_low;//将低八位移入整形的低八位
	
	return temperature;
}


