#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTC_DATA_R       (*((volatile unsigned long *)0x400063FC))
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTE_DATA_R       (*((volatile unsigned long *)0x400243FC))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
unsigned char  DIO_ReadPort (unsigned char port_index,unsigned char pins_mask) 
{
	long int all[6]={GPIO_PORTA_DATA_R,GPIO_PORTB_DATA_R ,GPIO_PORTC_DATA_R ,GPIO_PORTD_DATA_R,GPIO_PORTE_DATA_R,GPIO_PORTF_DATA_R};
	
		return (all[port_index]&pins_mask);
	
}