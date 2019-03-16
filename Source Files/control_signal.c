//A[6]->RW
//A[5]->RS
#define GPIO_PORTA_DATA_R
#define PORTA_RS 0x20
#define PORTA_RW 0x40

oid control_signal(unsigned char RS,unsigned char RW)
{
	if (RS)
			GPIO_PORTA_DATA_R|=PORTA_RS;
	else
			GPIO_PORTA_DATA_R&=~PORTA_RS;
	if(RW)
		GPIO_PORTA_DATA_R|=PORTA_RW;
	else
		GPIO_PORTA_DATA_R&=~PORTA_RW;
		
}