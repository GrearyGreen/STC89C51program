#include "i2c.h"

void Delay10us();
void I2CStar();
unsigned char I2C_SendByte(unsigned char Send_data);
unsigned char I2C_ReadByte();
void I2CStop();
void E2Write(unsigned char address,unsigned char send_data);
unsigned char E2Read(unsigned char address);

void E2Write(unsigned char address,unsigned char send_data)
{
	//写入EEPROM数据(一个字节)的函数
	I2CStar();//开始
	I2C_SendByte(0xa0);
	//发送机器地址
	//前四位1010，24c02芯片定义好的地址
	//后三位000，电路板上接地
	//最后一位，0，写入，1，读取
	I2C_SendByte(address);
	//发送EEPROM内部地址，0~255的地址
	//内部没存储一个数据，EEPROM内部会自动加一
	I2C_SendByte(send_data);
	//发送数据
	I2CStop();//结束
	//以上的发送是有返回值的如果担心发送失败，可以用if判定
}

unsigned char E2Read(unsigned char address)
{
	unsigned char Read_data;//存储数据的变量
	I2CStar();//开始
	I2C_SendByte(0xa0);
	//假写入，EEPROM不会主动向单片机发送数据
	//单片机先向EEPROM写入数据，建立通信
	//通信中没有内容，然后换成读取通信
	I2C_SendByte(address);
	//EEPROM中的地址
	//读取数据的地址，下面可读取数据。不用写写入数据的地址
	I2CStar();//开始
	I2C_SendByte(0xa1);
	//和上一个不一样，这个是写入，机器地址一样
	//所以是1010 0001
	Read_data = I2C_ReadByte();//用变量接受一个字节的数据
	I2CStop();//结束
	return Read_data;
}

void Delay10us(void)
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);
}

void I2CStar()
{
	SDA = 1;
	Delay10us();
	SCL = 1;
	Delay10us();
	SDA = 0;
	Delay10us();
	SCL = 0;
	Delay10us();
}

void I2CStop()
{
	SDA = 0;
	Delay10us();
	SCL = 1;
	Delay10us();
	SDA = 1;
	Delay10us();
}

unsigned char I2C_SendByte(unsigned char Send_data)
{
	//返回1，发送成功，返回0，发送失败
	unsigned char a = 0,b = 0;
	for(a = 0;a < 8;a++)
	{
		//可理解为下降沿发送(其实不是)
		SDA = Send_data>>7;
		Send_data = Send_data<<1;
		Delay10us();
		SCL = 1;
		Delay10us();
		SCL = 0;
		Delay10us();
	}
	SDA = 1;	//释放数据端口(应答是低电平)
	Delay10us();
	SCL = 1;	//释放始终端口
	
	//传输是否成功,是否应答
	//在时钟高电平时，4.7us后数据端口会自动拉低
	while(SDA)
	{
		b++;
		if(b>200)
		{
			SCL = 0;	//强制结束，等待下次传输
			Delay10us();
			return 0;//传输失败
		}
	}
	SCL = 0;	//结束，等待下次传输
	Delay10us();
	return 1;//传输成功
}

unsigned char I2C_ReadByte()
{
	//读取EEPROM中的数据，读取成功返回数据，读取失败返回0
	unsigned char a = 0,Read_data = 0;
	SDA=1;			//数据位置高电平
	Delay10us();
	for(a = 0;a < 8;a++)
	{
		//可以理解为下降沿触发
		SCL = 1;
		Delay10us();
		Read_data <<= 1;
		Read_data |= SDA;
		Delay10us();
		SCL = 0;			//更换为下一位数据
		Delay10us();
	}
	return Read_data;
}
