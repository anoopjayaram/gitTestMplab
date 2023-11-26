#include <pic18.h>
 
void delay();
void cmd(int);
void data(char);
void display(const char *p);
void special_char(unsigned char cgram_loc, unsigned char lcd_loc, unsigned char *data);
void main(void)
{
   void special_char(unsigned char, unsigned char, unsigned char *);
unsigned char data1[]={10,21,17,17,17,10,4,0}; // Bitmap values of ?heart? shape
unsigned char data2[]={12,18,1,2,4,8,0,8};
unsigned char data3[]={1,3,5,9,9,11,27,24};
    TRISA=0X00;
    TRISC=0x00;
    TRISD=0X00;
    TRISB=0X00;
    ADCON1=0X0F;
    cmd(0X38);
    cmd(0X80);
    cmd(0X01);
    cmd(0X06);
    cmd(0X0C);
special_char(64,0×82,data1); // Function call to store ?Heart? shape?s bitmap at 64th base address
// and print it at 0x82 location on LCD
delay();
special_char(80,0×86,data3);
delay();
delay();
            while(1);
   
}
void cmd(int a)
{
    
    PORTD=a;
    RC0=0;
    RC1=1;
    delay();
    RC1=0;
    
}
void data(char b)
{
    
    PORTD=b;
    RC0=1;
    RC1=1;
    delay();
    RC1=0;
      }

void display(const char *p)
{
	while(*p!='\0')
	{
		data(*p);
		p++;
	}
}
void delay()
{
int i,j;
for(i=0;i<50;i++)
for(j=0;j<50;j++);
}

void special_char(unsigned char cgram_loc, unsigned char lcd_loc, unsigned char *data)
{
unsigned int j=0;
lcdcmd(cgram_loc); // Send location of CGRAM
while(j<8)
{
lcddata(data[j]); // Send bitmap values of the character
j++;
}
lcdcmd(lcd_loc); // Send LCD location where the character is to displayed
lcddata((cgram_loc-64)/8); // ASCII value of corresponding base address
}    