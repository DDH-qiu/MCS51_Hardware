#include"reg51.h"
#include"lcd1602.h"
unsigned char flag=0,count=0;
unsigned char recdat[12]={0};
unsigned char	str[]={"Received Data:"};

void initscon()
{
	SCON=0x50; //0101 0000
	TMOD=0x20; //0010 0000
	TH1=256-3;
	TL1=256-3;
	ES=1;
	EA=1;
	TR1=1;
}

void display()
{
	unsigned char i=0,j=0;
	writecom(0x80);
	delay(5);
	for(i=0;i<15;i++)
	{
		writedat(str[i]);
		delay(5);
	}
	if(flag==1)
	{
		writecom(0x80+0x40);
		delay(5);
		for(j=0;j<count;j++)
		{
			writedat(recdat[j]);
			delay(5);
		}
		count=0;
		flag=0;
	}
}
	
void main()
{
	initscon();
	initlcd();
	while(1)
	{
		display();
	}
}
	
void scon_isr() interrupt 4
{
	recdat[count++]=SBUF;
	RI=0;
	flag=1;
}