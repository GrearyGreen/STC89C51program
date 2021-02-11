#include "IIC.h"

void delay5us()		
{
	//调用函数和使用的时间大约是5us
	unsigned char a;
    for(a=1;a>0;a--);
}

void I2C_init()				   //初始化
{
	SDA = 1;
	_nop_();
	SCL = 1;
	_nop_();                //空闲时，两条线均为高电平	 
}

/*I2C通信起始信号*/
void I2C_start()
{
	SCL = 1;   //此时主机有总线控制权，先把SCL线拉高
	_nop_();   //稳定一下
	SDA = 1;   //把SDA线拉高，以便发出起始信号（不确定是否为高）
	delay5us();//通信协议规定延时大于4.7us
	SDA = 0;   //拉低SDA线，制造下降沿的起始信号
	delay5us();//通信协议规定延时大于4us
}
				  
/*I2C通信终止信号*/
void I2C_stop()
{
	SDA = 0;   //拉低SDA线，以便发出终止信号
	_nop_();   //稳定一下
	SCL = 1;   //拉高SCL线
	delay5us();//通信协议规定延时大于4us
	SDA = 1;   //拉高SDA线
	delay5us();//通信协议规定延时大于4.7us
}

/*从机应答检测*/
bit Test_ack()
{
	SCL = 1;	
	//拉高SCL线，以便主机读取从机发出的应答或非应答信号
	delay5us();//通信协议规定延时大于4us
	if(SDA)	   
	//主机读取的SDA线为高，说明从机发送了一个非应答信号
	{
		SCL = 0;/*接下来准备发送停止信号，所以让时钟总线SCL拉低，
				让I2C_stop();函数中的SDA可变为0*/
		_nop_();//稳定总线
		I2C_stop();
		return 0;//结束检测从机应答函数
	}	
	else
	//主机读取的SDA线为低，说明从机发送了一个应答信号
	{
		SCL = 0;/*将时钟总线SCL拉低，此时SDA上数据的变化才有效，
				因为接下来会继续发数据*/
		_nop_();//稳定总线
		return 1;
	}
}

/*I2C通信：发送一个字节*/
void I2C_send_byte(uint8_t byte)
{
	uint8_t i;//声明一个计数变量i
	for(i = 0; i < 8; i++)//一个字节有8位，发8次
	{
		SCL = 0;//拉低SCL，让数据总线SDA变化有效
		_nop_();//稳定总线
		if(byte & 0x80)//1000 0000 & byte
/*如果（要发送数据的当前传输位）byte的最高位为1，执行该if语句，
  如果（要发送数据的当前传输位）byte的最高位为0，不执行该if语句*/
		{
			SDA = 1;   
			//（当前传输位）byte的最高位为1，即把1放到SDA线上
			_nop_();//稳定总线
		}	
		else
		//如果（当前发送位）byte的最高位为0（不为1），给SDA送0
		{
			SDA = 0;
			_nop_();//稳定总线
		}
		SCL = 1;//拉高SCL线，使从机能够从SDA线上读取到当前的数据
		_nop_();//稳定总线
		byte <<= 1;
/*使byte左移一位，即原来已被发送到SDA线上的最高位被移除，
第七位（还未发送的数据位）变成最高位变为下一次循环的当前发送位*/
	}
	SCL = 0;
	//发送完数据之后，将SCL拉低，以便从机改变SDA线，发出应答信号
	_nop_();//稳定总线
	SDA = 1;//释放总线控制权
	_nop_();//稳定总线
}
