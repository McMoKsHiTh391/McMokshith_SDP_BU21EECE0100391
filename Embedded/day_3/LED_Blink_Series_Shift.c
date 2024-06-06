#include<reg51.h>

void delay(unsigned int);
void main(void)
{
	unsigned char k = 0x01;
	unsigned int n;
	while(1)
	{
		for( n=0;n<=7;n++){
		P1 = k;
		delay(5000);
			k=k<<1;
		}
		if(k==0){
			k=0x01;
		}
	}
}

void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);//1275 8051 will compute 1275 tiems in  1millisecond
}