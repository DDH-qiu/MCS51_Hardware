/**
Title:��������
Authors:DDH-qiu
Date:2022-4-12
Abstract:����������������ܵı仯
**/
#include"reg51.h"
sbit key0=P1^0;
unsigned char num=0;
unsigned char flag=0;
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


//��ʱ�Ӻ���ms����
// void delay(unsigned int n)
// {
// 	unsigned int i=0,j=0;
// 	for(i=0;i<n;i++)
// 	{
// 		for(j=0;j<120;j++);
// 	}
// }


//�����Ӻ���
void key()
{
	//��ʱ������ֻҪ���¾�һֱ��һ
	// if(key0==0)//��ⰴ���Ƿ���
	// {
	// 	delay(500);//��������
	// 	num++;
	// }

	//ͨ����־λflag���жϰ����Ƿ��£���һ��ֻ��һ
	if(key0==0&&flag==0)//�����ж�����
	{
		flag=1;
	}
	if(flag==1&&key0==1)
	{
		num++;
		flag=0;//����ʱ���flag��־λ
	}
}


//������Ӻ���
void seg()
{
	P2=s[num];
	if(num==10)//��num������10ʱ����
	{
		num=0;
	}
	
}



void main()
{
	while(1)
	{
		//�������������ӳ���
		key();
		seg();
	}
}

