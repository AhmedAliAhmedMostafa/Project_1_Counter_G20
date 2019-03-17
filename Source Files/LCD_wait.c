#include"LCD_wait.h"

#define LCD_DATA GPIOB
#define LCD_CTRL GPIOA     //ASSUME RS,R/W,E AT PINS [5,6,7]
#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */

void waitLcd(void)  // this function will read busy flag in LCD (pin[7]in control reg)and wait until flag is not set
{
	Port_SetPinDirection(0,0xE0,PORT_PIN_OUT);
	LCD_CTRL->DATA = RW	;		// only PIN[6]SHOULD BE=1
	LCD_CTRL->DATA |= EN;     // sends Enable pulse
	Port_SetPinDirection(1,0x80,PORT_PIN_IN); // bit 7 in portB is now input
	
	LCD_CTRL->DATA &= ~EN;		// disable Enable 
	while((GPIOB->DATA&0X80)==1);
	// BUSY WAIT 

}


//int main(void)
//{
//	char t;
//	//Port_SetPinDirection(0,0x033,PORT_PIN_IN);
//	waitLcd();
//	for(;;){ t=1;t=!t;}

//}
//void SystemInit(void){SCB->CPACR |= 0x00F00000;}
