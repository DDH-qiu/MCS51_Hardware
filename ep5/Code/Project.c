#include"reg51.h"
//sbit LED0=P2^0;
//sbit LED1=P1^0;��λIO��

//��ʱ
void delay(unsigned int n)//��ʱ�Ӻ���
{
	unsigned int j=0;
	unsigned int i=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

void led()
{
	int i=0;
	for(i=0;i<8;i++)
	{
		P2=~(0x01<<i);//0000 0001,<<��λ
		P1=0x01<<i;
		delay(50);
	}
}

void main()
{
	while(1){
		led();
	}
}

/**

һ�����ˮ��ʵ�ַ�ʽ

//ȡ�����е�����д��LED��
#include"reg51.h"
unsigned leddat[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//����������

void delay(unsigned int n)
{
	unsigned int i=0;j=0;
	for(i=0;i<n;i++)
	{
		P2=leddat[i];
		delay(100);
	}
}

void led()
{
	for(i=0;i<8;i++)
	{
		P2=leddat[i];
		delay(100);
	}
}

void main
{
	while(1)
	{
		led();
	}
	
}



**/
