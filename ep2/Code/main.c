#include"regx52.h"
sbit LED0=P2^0;


//延时子函数
void delay(unsigned int n)
{
	unsigned int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}


//灯的移位子函数
//实现LED灯的移位功能
void led()
{
	int i=0;
	for(i=0;i<8;i++)
	{
		P1=(0x01<<i);
		delay(50);
	}
}


//主函数
void main()
{
	while(1)
	{
		led();//调用LED灯移位子程序
	}	
}
