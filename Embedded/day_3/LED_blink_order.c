#include <reg51.h>
#include <stdio.h>

void delay(unsigned int);
void main(void)
{
	unsigned int A[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
   int k=0;
	while(1)
	 {
		 for(k=0; k<=7; k++)
		 {
			 P1=A[k];
			 delay(50);
     }
   }
}
void delay(unsigned int t)
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++); // For 1ms, for loop need to iterate 1275 times.  
}