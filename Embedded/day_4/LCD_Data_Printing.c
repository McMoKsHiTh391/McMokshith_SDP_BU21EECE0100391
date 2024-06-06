#include <reg51.h>
sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;
void delay(unsigned int);
void WriteCommandToLCD(unsigned char ch);
void WriteDataToLCD(unsigned char ch);
void WriteStringToLCD(unsigned char ch[]);

void main(void)
{
		// unsigned char ch[]="ES TRAINING";
		unsigned char ch1[]="GITAM UNIVERSITY, BANGLORE";
		unsigned int j,k;
		unsigned int MyData = 20;
	
	// LCD Initialization
		WriteCommandToLCD(0x38); // 2 lines and 5x7 matrix
		WriteCommandToLCD(0x01); // Clear display screen
		WriteCommandToLCD(0x0c); // Display ON, Cursor OFF
		WriteCommandToLCD(0x80); // Force cursor to begining (1st line)
		WriteCommandToLCD(0x06); // Increment cursor (shift cursor to right)
	
	// Sending Data to LCD
		WriteStringToLCD("ES TRAINING"); // Sending String to the LCD
		WriteCommandToLCD(0xc0); // Force cursor to the beginning (2nd line)
		for(j=0;ch1[j]!='\0';j++)
			{
				WriteDataToLCD(ch1[j]); // Sending one character to LCD
			}
		for(k=0;k<30;k++)
			{
				WriteCommandToLCD(0x1c); // Shift entire display right
			}
		while(1)
		{
			WriteCommandToLCD(0x01); // Clear display screen
			WriteCommandToLCD(0x80); // Force cursor to the beginning (1st line)
			WriteStringToLCD("CLASS STRENGTH"); // Sending string to LCD
			WriteCommandToLCD(0xc0); // Force cursor to the beginning (2nd line)
			WriteDataToLCD((MyData / 10) + 48); // Separating the first digit of Mydata
			WriteDataToLCD((MyData % 10) + 48); // Separating the second digit of Mydata
			WriteStringToLCD(" STUDENTS");
		}
}

void delay(unsigned int t) // Function for setting 1ms delay
{
	unsigned int i,j;
	for(i=0;i<t;i++)
	for(j=0;j<1275;j++);
}

void WriteCommandToLCD(unsigned char ch) // Function for sending command
{
	e=1;
	rs=0;
	rw=0;
	P1=ch;
	e=0;
	delay(20);
}

void WriteDataToLCD(unsigned char ch) // Function for sending Data
{
	e=1;
	rs=1;
	rw=0;
	P1=ch;
	e=0;
	delay(20);
}

void WriteStringToLCD(unsigned char ch[]) // Function for sending string
{
	int i;
	 for(i=0;ch[i]!='\0';i++)
		{
			WriteDataToLCD(ch[i]);
		}
}