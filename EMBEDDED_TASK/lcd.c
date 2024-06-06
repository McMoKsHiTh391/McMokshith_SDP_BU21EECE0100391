#include<reg51.h>

void delay(unsigned int);
void main(void)
{	
	while(1)
	{
		P1= 0x01;
		delay(100);
		P1 = 0x02;
		delay(100);
		P1 = 0x04;
		delay(100);
		P1 = 0x08;
		delay(100);
		p1 = 0x10;
		delay(100);
		P1 = 0x20;
		delay(100);
		P1 = 0x40;
		delay(100);
	}	
}
void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);//1275 8051 will compute 1275 tiems in  1millisecond
}