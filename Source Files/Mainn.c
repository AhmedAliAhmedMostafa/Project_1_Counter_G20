#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */
#define c1 0x80
#define c2 0x81
#define c3 0x82
#include"TM4C123GH6PM.h"

typedef enum {STD_LOW,STD_HIGH}Dio_LevelType;
//char t;


uint8_t DIO_ReadPort (int  port_index,uint8_t pins_mask) { //port index , mask ,
	
	
//	portsel a =  port_index ; 
//	
//	
//	
//	uint32_t Port_DATA[] ={GPIO_PORTA_DIR_R,GPIO_PORTB_DATA_R ,GPIO_PORTC_DATA_R,GPIO_PORTD_DATA_R,GPIO_PORTE_DATA_R ,GPIO_PORTF_DATA_R} ;
//	Port_DATA[a]&pins_mask;
//	Port_SetPinDirection(port_index,port_mask,PORT_PIN_OUT);
	
		
		if     (port_index==0) {return GPIOA->DATA&pins_mask;}
		else if(port_index==1) {return GPIOB->DATA&pins_mask;}
		else if(port_index==2) {return GPIOC->DATA&pins_mask;}
		else if(port_index==3) {return GPIOD->DATA&pins_mask;}
		else if(port_index==4) {return GPIOE->DATA&pins_mask;}
		else if(port_index==5) { return GPIOF->DATA&pins_mask;}
		else{return 0x00;}
	}
#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTC_PUR_R        (*((volatile unsigned long *)0x40006510))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
void Port_SetPinPullUp_1 (unsigned char port_index,unsigned char pins_mask,unsigned char enable) 
{
	volatile unsigned long int * all[6]={(volatile unsigned long *)0x40004510,
(volatile unsigned long *)0x40005510,
(volatile unsigned long *)0x40006510,
(volatile unsigned long *)0x40007510,
(volatile unsigned long *)0x40024510,
(volatile unsigned long *)0x40025510};
	switch(enable)
	{
		case '1':
		if     (port_index==0) {GPIOA->CR|=pins_mask;GPIO_PORTA_PUR_R |=pins_mask;}
		else if(port_index==1) {GPIOB->CR|=pins_mask;GPIO_PORTB_PUR_R |=pins_mask;}
		else if(port_index==2) {GPIOC->CR|=pins_mask;GPIO_PORTC_PUR_R |=pins_mask;}
		else if(port_index==3) {GPIOD->CR|=pins_mask;GPIO_PORTD_PUR_R |=pins_mask;}
		else if(port_index==4) {GPIOE->CR|=pins_mask;GPIO_PORTE_PUR_R |=pins_mask;}
		else if(port_index==5) {GPIOF->CR|=pins_mask;GPIO_PORTF_PUR_R |=pins_mask;}
		else{return ;}
			break;
		case '0': 
		if     (port_index==0) {GPIOA->CR|=pins_mask;GPIO_PORTA_PUR_R &=~pins_mask;}
		else if(port_index==1) {GPIOB->CR|=pins_mask;GPIO_PORTB_PUR_R &=~pins_mask;}
		else if(port_index==2) {GPIOC->CR|=pins_mask;GPIO_PORTC_PUR_R &=~pins_mask;}
		else if(port_index==3) {GPIOD->CR|=pins_mask;GPIO_PORTD_PUR_R &=~pins_mask;}
		else if(port_index==4) {GPIOE->CR|=pins_mask;GPIO_PORTE_PUR_R &=~pins_mask;}
		else if(port_index==5) {GPIOF->CR|=pins_mask;GPIO_PORTF_PUR_R &=~pins_mask;}
		else{return ;}
			break;
	}

}
//A[6]->RW
//A[5]->RS
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define PORTA_RS 0x20
#define PORTA_RW 0x40

void control_signal(unsigned char rs,unsigned char rw)
{
	if (rs)
			GPIO_PORTA_DATA_R|=PORTA_RS;
	else
			GPIO_PORTA_DATA_R&=~PORTA_RS;
	if(rw)
		GPIO_PORTA_DATA_R|=PORTA_RW;
	else
		GPIO_PORTA_DATA_R&=~PORTA_RW;
		
}

	
void PortInit (uint8_t portIndex) // assume port [A:F] as [0:5]
	{
		if     (portIndex==0){GPIOA->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X01;/*GPIOA->DATA|=0X0;*/GPIOA->DEN=0XFF;return;}
		else if(portIndex==1){GPIOB->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X02;/*GPIOB->DATA|=0X0;*/GPIOB->DEN=0XFF;return;}
		else if(portIndex==2){GPIOC->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X04;/*GPIOC->DATA|=0X0;*/GPIOC->DEN=0XFF;return;}
		else if(portIndex==3){GPIOD->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X08;/*GPIOD->DATA|=0X0;*/GPIOD->DEN=0XFF;return;}
		else if(portIndex==4){GPIOE->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X10;/*GPIOE->DATA|=0X0;*/GPIOE->DEN=0XFF;return;}
		else if(portIndex==5){GPIOF->LOCK=0x4C4F434B;SYSCTL->RCGCGPIO|=0X20;/*GPIOF->DATA|=0X0;*/GPIOF->DEN=0XFF;return;}
		else {return;}
	}
void DIO_WritePort (uint8_t port_index,uint8_t port_mask,Dio_LevelType pins_level)
{
	
	
	if(pins_level==STD_HIGH)
		{
		if     (port_index==0){GPIOA->DATA|=port_mask;}
		else if(port_index==1){GPIOB->DATA|=port_mask;}
		else if(port_index==2){GPIOC->DATA|=port_mask;}
		else if(port_index==3){GPIOD->DATA|=port_mask;}
		else if(port_index==4){GPIOE->DATA|=port_mask;}
		else if(port_index==5){GPIOF->DATA|=port_mask;}
		}
	else if(pins_level==STD_LOW)
	{
		if     (port_index==0){GPIOA->DATA&=~port_mask;}
		else if(port_index==1){GPIOB->DATA&=~port_mask;}
		else if(port_index==2){GPIOC->DATA&=~port_mask;}
		else if(port_index==3){GPIOD->DATA&=~port_mask;}
		else if(port_index==4){GPIOE->DATA&=~port_mask;}
		else if(port_index==5){GPIOF->DATA&=~port_mask;}			
	}

}
void delay_milli(int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3180; j++)
		{
		}
}

void delay_micro(int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
		{
		}
}
typedef  enum  {PORT_PIN_IN,PORT_PIN_OUT}Port_PinDirectionType;
//THE MASK SHOULD BE SET=1 AT THE DESIRED BITS
//char t;
void Port_SetPinDirection(uint8_t portIndex,uint8_t pins_mask,Port_PinDirectionType pins_direction)
{
	if(pins_direction)
		{
		//uint8_t Mask = 0XFF;
		if     (portIndex==0){GPIOA->DIR|=pins_mask;}
		else if(portIndex==1){GPIOB->DIR|=pins_mask;}
		else if(portIndex==2){GPIOC->DIR|=pins_mask;}
		else if(portIndex==3){GPIOD->DIR|=pins_mask;}
		else if(portIndex==4){GPIOE->DIR|=pins_mask;}
		else if(portIndex==5){GPIOF->DIR|=pins_mask;}
		}
	else if(~pins_direction)
	{
		if     (portIndex==0){GPIOA->DIR&~pins_mask;}
		else if(portIndex==1){GPIOB->DIR&~pins_mask;}
		else if(portIndex==2){GPIOC->DIR&~pins_mask;}
		else if(portIndex==3){GPIOD->DIR&~pins_mask;}
		else if(portIndex==4){GPIOE->DIR&~pins_mask;}
		else if(portIndex==5){GPIOF->DIR&~pins_mask;}			
	}

}
void counter_display (unsigned long count)
{
	
		// C1
		control_signal(0,0);
		GPIOB->DATA=c1;
		GPIOA->DATA|=EN;
		delay_micro(1);
		GPIOA->DATA&=~EN;
		delay_milli(3);
		control_signal(1,0);
		GPIOB->DATA=(count/100)+48;
		GPIOA->DATA|=EN;
		delay_micro(1);
		GPIOA->DATA&=~EN;
		// C2
		delay_milli(3);
		control_signal(0,0);
		GPIOB->DATA=c2;
		GPIOA->DATA|=EN;
		delay_micro(1);
		GPIOA->DATA&=~EN;
		delay_milli(3);
	  control_signal(1,0);
		GPIOB->DATA=((count/10)%10)+48;
		GPIOA->DATA|=EN;
		delay_micro(1);
		GPIOA->DATA&=~EN;
		// C3
		delay_milli(3);
		control_signal(0,0);
		GPIOB->DATA=c3;
		GPIOA->DATA|=EN;
		delay_micro(1);
		GPIOA->DATA&=~EN;
		delay_milli(3);
		control_signal(1,0);
		GPIOB->DATA=((count%100)%10)+48;
		GPIOA->DATA|=EN;
		delay_micro(1);
		GPIOA->DATA&=~EN;

	
}



int main (void){
	PortInit (0);
	Port_SetPinDirection(0,0xE0,PORT_PIN_OUT);
	PortInit (1);
	Port_SetPinDirection(0,0xFF,PORT_PIN_OUT);
	PortInit (4);
	Port_SetPinDirection(0,0x38,PORT_PIN_IN);
	Port_SetPinPullUp_1 (4,0x38,1); 

	unsigned long count=0;
	while (1)
	{	
		
		unsigned char incr = 0x20;
		unsigned char decr = 0x20;
		unsigned char reset = 0x20;

		
		int counter =0 ; 
		
		counter_display (count);
		control_signal(1,0);
		unsigned char flag2=0, flag1=0;
		if(DIO_ReadPort(4,incr)==0)/* can be changed if pull up is diffret */
			{ 
				delay_micro(1);
			  counter=(counter+1)%1000;
			  counter_display(counter);
			}
		else if(DIO_ReadPort(4,decr)==0&&flag1==0)
		     if (counter!=0)
			  {
				  counter=(counter-1)%1000;
				  counter_display(counter);
				  flag1=1;
			  }
		 else if(DIO_ReadPort(4,decr)==decr &&flag1==1)
		 flag1=0;
		 else if(DIO_ReadPort(4,reset)==0&&!flag2)
		 /* assert flag2  */flag2=1;
		 else if( DIO_ReadPort(4,reset)==reset&&flag2 )
		 {
			 counter=0;
			 counter_display(counter);
		 }
		 
		 


	}
}