#include "DHT11.h"

//uchar U8FLAG;
//uchar U8temp;
//uchar	U8T_data_H_temp,		//�¶ȵ�����λ
//		U8T_data_L_temp,		//�¶ȵ�С��λ
//		U8RH_data_H_temp,		//ʪ�ȵ�����λ
//		U8RH_data_L_temp,		//ʪ�ȵ�С��λ
//		U8checkdata_temp;		//У��λ
//uchar U8comdata;

void Delay(uint j)
{
	//�ӳ�100us
	uchar i;
	for(;j>0;j--)
	{ 	
		for(i=0;i<27;i++);
	}
}

void Delay_10us(void)
{
	//10us
	uchar i;
	i--;
	i--;
	i--;
	i--;
	i--;
	i--;
}
	
void COM(void)
{
	//�ж�����������0������1
    uchar i;
	//8λһ������
    for(i=0;i<8;i++)	   
	{
		//����ÿλ����ǰ
		U8FLAG=2;	
	   	while((!Serial_port)&&U8FLAG++);
		Delay_10us();
		Delay_10us();
		Delay_10us();
	  	U8temp=0;
	    if(Serial_port)
			U8temp=1;
		U8FLAG=2;
		while((Serial_port)&&U8FLAG++);
	   	//��ʱ������forѭ��		  
		if(U8FLAG==1)
			break;
	   	//�ж�����λ��0����1	 
	   	   
		// ����ߵ�ƽ�߹�Ԥ��0�ߵ�ƽֵ������λΪ 1 
	   	 
		U8comdata<<=1;
		U8comdata|=U8temp;        //0
	}//rof
}

	//--------------------------------
	//-----ʪ�ȶ�ȡ�ӳ��� ------------
	//--------------------------------
	//----���±�����Ϊȫ�ֱ���--------
	//----�¶ȸ�8λ== U8T_data_H------
	//----�¶ȵ�8λ== U8T_data_L------
	//----ʪ�ȸ�8λ== U8RH_data_H-----
	//----ʪ�ȵ�8λ== U8RH_data_L-----
	//----У�� 8λ == U8checkdata-----
	//----��������ӳ�������----------
	//---- Delay();Delay_10us();COM(); 
	//--------------------------------

void RH(void)
{
	//��������18ms 
	Serial_port=0;
	Delay(180);
	Serial_port=1;
	//������������������ ������ʱ20us
	Delay_10us();
	Delay_10us();
	Delay_10us();
	Delay_10us();
	//������Ϊ���� �жϴӻ���Ӧ�ź� 
	Serial_port=1;
	//�жϴӻ��Ƿ��е͵�ƽ��Ӧ�ź� �粻��Ӧ����������Ӧ����������	  
	if(!Serial_port)		 //T !	  
	{
		U8FLAG=2;
		//�жϴӻ��Ƿ񷢳� 80us �ĵ͵�ƽ��Ӧ�ź��Ƿ����	 
		while((!Serial_port)&&U8FLAG++);
		U8FLAG=2;
		//�жϴӻ��Ƿ񷢳� 80us �ĸߵ�ƽ���緢����������ݽ���״̬
		while((Serial_port)&&U8FLAG++);
		//���ݽ���״̬		 
		COM();
		U8RH_data_H_temp=U8comdata;
		COM();
		U8RH_data_L_temp=U8comdata;
		COM();
		U8T_data_H_temp=U8comdata;
		COM();
		U8T_data_L_temp=U8comdata;
		COM();
		U8checkdata_temp=U8comdata;
		Serial_port=1;
		//����У�� 
		U8temp=(U8T_data_H_temp+U8T_data_L_temp+U8RH_data_H_temp+U8RH_data_L_temp);
		//�������û�����⣬����������ת�����ݱ���
		if(U8temp==U8checkdata_temp)
		{
			U8RH_data_H=U8RH_data_H_temp;
			U8RH_data_L=U8RH_data_L_temp;
			U8T_data_H=U8T_data_H_temp;
			U8T_data_L=U8T_data_L_temp;
			U8checkdata=U8checkdata_temp;
		}//fi
	}//fi
}