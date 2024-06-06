#include <reg51.h>
 sbit ALE = P2^4;
 sbit OE = P2^5;
 sbit SC = P2^6;
 sbit EOC = P2^7; 
	//Declaring the input selection pin
 sbit ADDR_A = P2^0;
 sbit ADDR_B = P2^1;
 sbit ADDR_C = P2^2;
	//void MSDelay(unsigned int);
	void MSDelay(unsigned int delay) 
	{
		unsigned int i,j; 
		for(i=0;i<delay;i++)
		for(j=0;j<1275;j++); 
	}
	void main() 
	{ 
		unsigned char ADC_Value = 0;
		P1 = 0xFF; 
		EOC = 1;
		ALE = 0;
		OE = 0;
		SC = 0;
	 while(1)
		{ 
		ADDR_C = 0;
		ADDR_B = 0; 
		ADDR_A = 0; 
		MSDelay(10); 
		ALE = 1; 
		MSDelay(10); 
		SC = 1; 
		MSDelay(10);
		ALE = 0;
		SC = 0;
		while(EOC==1); 
		//while(EOC==0); 
		OE=1;
		MSDelay(10); 
		ADC_Value= P1; 
		P3 = ADC_Value; 
		OE = 0 ; 
		}
	} 