//The switch controls whether an LED is turned on / off using negative logic.In particular, if the switch is pressed the LED is off, and if the switch is not pressed the LED is on.

// PD3 is an output to LED output, positive logic
// PD0 is an input from switch, positive logic
// to set the switch in the simulator type this into command window
// PORTD = 1 
// to release the switch in the simulator type this into command window
// PORTD = 0 
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
unsigned long in,out;

#include "TExaS.h"
#include "tm4c123gh6pm.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts


// PE0, PB0, or PA2 connected to positive logic momentary switch using 10 k ohm pull down resistor
// PE1, PB1, or PA3 connected to positive logic LED through 470 ohm current limiting resistor
void delay100ms(unsigned long numOf100msDelays)
{
	unsigned long i;
	while (numOf100msDelays > 0)
	{
		i = 1333333; //this number means 100ms
		while (i > 0)
		{
			i = i - 1;
		}
		//decrements every 100ms
		numOf100msDelays = numOf100msDelays - 1; 
	}
}
int main(void){
  unsigned long volatile delay;
	unsigned long dataRegIn = 0;
	
  TExaS_Init(SW_PIN_PE0, LED_PIN_PE1);  // activate grader and set system clock to 80 MHz
  
	
  EnableInterrupts();           // enable interrupts for the grader
  SYSCTL_RCGC2_R |= 0x10;           // Port E clock
  delay = SYSCTL_RCGC2_R;           // wait 3-5 bus cycles
  GPIO_PORTE_DIR_R |= 0x02;         // PE1 output
  GPIO_PORTE_DIR_R &= ~0x01;        // PE0 input 
  GPIO_PORTE_AFSEL_R &= ~0x03;      // not alternative
  GPIO_PORTE_AMSEL_R &= ~0x03;      // no analog
  GPIO_PORTE_PCTL_R &= ~0x000000FF; // bits for PE1, PE0
  GPIO_PORTE_DEN_R |= 0x03;         // enable PE1, PE0
	
	GPIO_PORTE_DATA_R |= 0x2; //start with LED on (PE1 = 1)
	while(1){
    delay100ms(1); //delay for (1) 100 ms interval
    in = (GPIO_PORTE_DATA_R&0x01); // in 0 if not pressed, 1 if pressed
		//If switch pressed (PE0=1), toggle LED once, else turn LED ON
    //out = (in xor 0x01) << 1 (shift to PE1 LED output)
		//so out = 1 if switch NOT pressed (0 xor 1 = 1 = LED ON)
		//and out = 0 if switch is pressed (1 xor 1 = 0)
		//this works since you can assume LED on all the time if
		//switch not pressed, so to toggle it, just xor it with in = 1
		//to toggle it off when switch pressed
		//did NOT work!  LED did not toggle
    //out = (in^0x01)<<1;   // out 2 if not pressed, 0 if switch pressed
    if (in == 0x01) //PE0 = switch = pressed
		{
			dataRegIn = GPIO_PORTE_DATA_R & 0x02;
			if (dataRegIn == 0) //PF2 = 0 = LED off
				{ //LED off, toggle LED once (turn it on)
					GPIO_PORTE_DATA_R |= 0x02; //turn LED on
				}
				else //LED on already
				{ //LED on, toggle LED once (turn off)
					GPIO_PORTE_DATA_R &= ~(0x02); //turn LED off
				}
		}
	else
			GPIO_PORTE_DATA_R |= 0x02; //turn LED on
	}
}