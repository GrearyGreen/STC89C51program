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
	//д��EEPROM����(һ���ֽ�)�ĺ���
	I2CStar();//��ʼ
	I2C_SendByte(0xa0);
	//���ͻ�����ַ
	//ǰ��λ1010��24c02оƬ����õĵ�ַ
	//����λ000����·���Ͻӵ�
	//���һλ��0��д�룬1����ȡ
	I2C_SendByte(address);
	//����EEPROM�ڲ���ַ��0~255�ĵ�ַ
	//�ڲ�û�洢һ�����ݣ�EEPROM�ڲ����Զ���һ
	I2C_SendByte(send_data);
	//��������
	I2CStop();//����
	//���ϵķ������з���ֵ��������ķ���ʧ�ܣ�������if�ж�
}

unsigned char E2Read(unsigned char address)
{
	unsigned char Read_data;//�洢���ݵı���
	I2CStar();//��ʼ
	I2C_SendByte(0xa0);
	//��д�룬EEPROM����������Ƭ����������
	//��Ƭ������EEPROMд�����ݣ�����ͨ��
	//ͨ����û�����ݣ�Ȼ�󻻳ɶ�ȡͨ��
	I2C_SendByte(address);
	//EEPROM�еĵ�ַ
	//��ȡ���ݵĵ�ַ������ɶ�ȡ���ݡ�����дд�����ݵĵ�ַ
	I2CStar();//��ʼ
	I2C_SendByte(0xa1);
	//����һ����һ���������д�룬������ַһ��
	//������1010 0001
	Read_data = I2C_ReadByte();//�ñ�������һ���ֽڵ�����
	I2CStop();//����
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
	//����1�����ͳɹ�������0������ʧ��
	unsigned char a = 0,b = 0;
	for(a = 0;a < 8;a++)
	{
		//�����Ϊ�½��ط���(��ʵ����)
		SDA = Send_data>>7;
		Send_data = Send_data<<1;
		Delay10us();
		SCL = 1;
		Delay10us();
		SCL = 0;
		Delay10us();
	}
	SDA = 1;	//�ͷ����ݶ˿�(Ӧ���ǵ͵�ƽ)
	Delay10us();
	SCL = 1;	//�ͷ�ʼ�ն˿�
	
	//�����Ƿ�ɹ�,�Ƿ�Ӧ��
	//��ʱ�Ӹߵ�ƽʱ��4.7us�����ݶ˿ڻ��Զ�����
	while(SDA)
	{
		b++;
		if(b>200)
		{
			SCL = 0;	//ǿ�ƽ������ȴ��´δ���
			Delay10us();
			return 0;//����ʧ��
		}
	}
	SCL = 0;	//�������ȴ��´δ���
	Delay10us();
	return 1;//����ɹ�
}

unsigned char I2C_ReadByte()
{
	//��ȡEEPROM�е����ݣ���ȡ�ɹ��������ݣ���ȡʧ�ܷ���0
	unsigned char a = 0,Read_data = 0;
	SDA=1;			//����λ�øߵ�ƽ
	Delay10us();
	for(a = 0;a < 8;a++)
	{
		//�������Ϊ�½��ش���
		SCL = 1;
		Delay10us();
		Read_data <<= 1;
		Read_data |= SDA;
		Delay10us();
		SCL = 0;			//����Ϊ��һλ����
		Delay10us();
	}
	return Read_data;
}
