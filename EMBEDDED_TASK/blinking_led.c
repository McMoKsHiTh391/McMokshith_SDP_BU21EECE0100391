#include<reg51.h>
//sbit sw1 = P2^1;
//sbit sw2 = P2^2;
//void dealy(void);
void delay(unsigned int);
void main(void)
{
	unsigned char k = 0x01;
	unsigned int n;
	
	while(1)
	{
		for( n=0;n<=7;n++){
		P1 = k;
		delay(500);
			k=k<<1;
		}
		if(k==0){
			k=0x01;
		}
			
	}
	
	
	
	
	
	
	
 // sw1 =0;
 // sw2 = 0;
  /*/while(1)
	   {
	    /* if(sw1==0 && sw2 ==0 )
			 {
			  P1 = 0x00;
			 }
			  else if(sw1 ==0 && sw2==1)
				{
				P1 = 0xF0;
				delay(50);
				P1 = 0x00;
				delay(50);
				
				}
				else if(sw1 ==1 && sw2 == 0)
				{
				P1=0x0F;
				delay(50);
				P1 = 0x00;
				delay(50);
				}
				else if(sw1==1&& sw2==1)
				{
				P1 = 0xFF;
				delay(50); 
				P1 = 0x00;
				delay(50);*/
}
		
	

void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);//1275 8051 will compute 1275 tiems in  1millisecond
}