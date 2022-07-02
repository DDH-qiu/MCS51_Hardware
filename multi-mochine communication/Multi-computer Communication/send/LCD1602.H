#ifndef __LCD1602_H_ 
#define __LCD1602_H_
#include"reg51.h"

sbit RS=P1^0;
sbit RW=P1^1;
sbit E=P1^2;
void writedat(unsigned char dat);
void writecom(unsigned char com);
void initlcd();
void delay(unsigned int t);
#endif