#include"regx52.h"
sbit LED0=P2^0;


//��ʱ�Ӻ���
void delay(unsigned int n)
{
	unsigned int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}


//�Ƶ���λ�Ӻ���
//ʵ��LED�Ƶ���λ����
void led()
{
	int i=0;
	for(i=0;i<8;i++)
	{
		P1=(0x01<<i);
		delay(50);
	}
}


//������
void main()
{
	while(1)
	{
		led();//����LED����λ�ӳ���
	}	
}
