#include"reg51.h"
//sbit LED0=P2^0;
//sbit LED1=P1^0;置位IO口

//延时
void delay(unsigned int n)//延时子函数
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
		P2=~(0x01<<i);//0000 0001,<<移位
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

一般的流水灯实现方式

//取数组中的数据写入LED灯
#include"reg51.h"
unsigned leddat[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//共阴极连接

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
