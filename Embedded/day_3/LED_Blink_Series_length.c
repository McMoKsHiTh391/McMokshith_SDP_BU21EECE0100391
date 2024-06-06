#include <reg51.h>

void delay(unsigned int);
void main(void)
{
	while(1)
	 {
		 P1=0x01;
		 delay(50);
		 P1=0x02;
		 delay(50);
		 P1=0x04;
		 delay(50);
		 P1=0x08;
		 delay(50);
		 P1=0x10;
		 delay(50);
		 P1=0x20;
		 delay(50);
		 P1=0x40;
		 delay(50);
		 P1=0x80;
		 delay(50);
   }
 }
void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++); // For 1ms, for loop need to iterate 1275 times.  
}