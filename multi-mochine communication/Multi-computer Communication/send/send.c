#include"reg51.h"
#include"lcd1602.h"
unsigned char flag=3,count=0,lenth=12,flagready=0;
unsigned char recdat[12]={0};
unsigned char str[]={"0123456789"};
unsigned char str1[]={"Ready!    "};
unsigned char str2[]={"Not Ready!"};

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

void initex0()
{
	IE0=1;
	EX0=1;
}
	
void senddat_function()
{
	unsigned char i=0;
	if(flag==1)
	{
		for(i=0;i<lenth;i++)
		{
			SBUF=recdat[i];
			while(!TI);
			TI=0;
		}
		flag=2;
	}
	if(flag==2)
	{
		for(i=0;i<lenth;i++)
		{
			recdat[i]=0x00;
		}
		count=0;
		flag=3;
		flagready=0;
	}
}

void display()
{
	unsigned char i=0,j=0,k=0;
	if(flag==3)
	{
		writecom(0x80);
		delay(1);
		for(i=0;i<lenth;i++)
		{
			writedat(recdat[i]);
			delay(1);
		}
		writecom(0x80+0x40);
		delay(1);
		if(flagready==0||count!=0)
		{
			while(str2[j]!='\0')
			{
				writedat(str2[j]);
				delay(1);
				j++;
			}
		}
		else if(flagready==1&&count==0)
		{
			while(str1[k]!='\0')
			{
				writedat(str1[k]);
				delay(1);
				k++;
			}
		}
	}
}
	
void main()
{
	initscon();
	initex0();
	initlcd();
	while(1)
	{
		senddat_function();
		display();
	}
}

void ex0_isr() interrupt 0
{
	flag=1;
}
	
void scon_isr() interrupt 4
{
	recdat[count++]=SBUF;
	RI=0;
	flag=3;
	if(count==lenth)
	{
		count=0;
		flagready=1;
	}
}