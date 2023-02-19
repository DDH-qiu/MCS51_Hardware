/**
Title:动态数码管显示
Authors:DDH-qiu
Date:2022-4-12
Abstract:采用74LS138通过三位IO口控制数码管显示
**/
#include"reg51.h"
unsigned char str[]={0x76,0x79,0x38,0x38,0x3f};//hello����
unsigned char wei[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};//λ��

void delay(unsigned int n)
{
	unsigned int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}

void seg()
{
	int i=0;
	for(i=0;i<5;i++)
	{
		P3=wei[i];
		P2=str[i];
		delay(5);
	}
}

void main()
{
	while(1)
	{
		seg();
	}
}
