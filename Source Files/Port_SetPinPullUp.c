#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTC_PUR_R        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
void Port_SetPinPullUp (unsigned char port_index,unsigned char pin_mask,unsigned char enable) 
{
	long int all[6]={GPIO_PORTA_PUR_R,GPIO_PORTB_PUR_R ,GPIO_PORTC_PUR_R ,GPIO_PORTD_PUR_R,GPIO_PORTE_PUR_R,GPIO_PORTF_PUR_R};
	switch(enable)
	{
		case '0':all[port_index]&=~pin_mask;
			break;
		case '1': all[port_index]|=pin_mask;
			break;
	}

}