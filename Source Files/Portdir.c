#include"TM4C123GH6PM.h"
typedef  enum  {PORT_PIN_IN,PORT_PIN_OUT}Port_PinDirectionType;
//THE MASK SHOULD BE SET=1 AT THE DESIRED BITS
char t;
void Port_SetPinDirection(uint8_t portIndex,uint8_t pins_mask,Port_PinDirectionType pins_direction)
{
	if(pins_direction)
		{
		//uint8_t Mask = 0XFF;
	if		 (portIndex==0){GPIOA->DIR|=pins_mask;}
	else if(portIndex==1){GPIOB->DIR|=pins_mask;}
	else if(portIndex==2){GPIOC->DIR|=pins_mask;}
	else if(portIndex==3){GPIOD->DIR|=pins_mask;}
	else if(portIndex==4){GPIOE->DIR|=pins_mask;}
	else if(portIndex==5){GPIOF->DIR|=pins_mask;}
		}
		else if(!pins_direction)
		{
			if		 (portIndex==0){GPIOA->DIR&=!pins_mask;}
			else if(portIndex==1){GPIOB->DIR&=!pins_mask;}
			else if(portIndex==2){GPIOC->DIR&=!pins_mask;}
			else if(portIndex==3){GPIOD->DIR&=!pins_mask;}
			else if(portIndex==4){GPIOE->DIR&=!pins_mask;}
			else if(portIndex==5){GPIOF->DIR&=!pins_mask;}
		}

}
int main(void)
{
	Port_SetPinDirection(0,0x033,PORT_PIN_OUT);
	Port_SetPinDirection(0,0x033,PORT_PIN_IN);
	Port_SetPinDirection(0,0x0F,PORT_PIN_OUT);
	for(;;){ t=1;t=!t;}
}
void SystemInit(void){SCB->CPACR |= 0x00F00000;}