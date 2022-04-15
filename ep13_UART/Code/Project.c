/**
Title:串口通信实践
Authors:DDH-qiu
Date:2022-4-15
Abstract:P3.0，p3.2串口通信实践
**/
#include"reg51.h"
unsigned char recdat=0;
unsigned char flag=0;
//波特率很重要
//串口通信初始化
void init_scon()
{
	SCON=0x50;//配置串口通信初始化
	TMOD=0x20;
	TH1=256-3;
	TL1=256-3;
	ES=1;
	EA=1;
	TR1=1;
}

//数据接收
void senddat()
{
	SBUF=recdat;
	while(!TI);//判断是否发送完成
	TI=0;//清除标志位
}

void main()
{
	init_scon();//串口通信初始化
	while(1)
	{
		if(flag==1)
		{
			senddat();//数据接收
			flag=0;//清除数据接收
		}
		
	}
}

//串口中断，接收中断RI=1
void scon_isr() interrupt 4
{
	recdat=SBUF;//读取数据(SBUF)
	RI=0;//清除数据接收标志位硬件置1，软件置0
	flag=1;//接收数据标志，自定义
}
