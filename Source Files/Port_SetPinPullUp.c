
#include "stdint.h"
#define GPIO_PORTA_PUR_R        (*((volatile uint32_t *)0x40004510))
#define GPIO_PORTB_PUR_R        (*((volatile uint32_t *)0x40005510))
#define GPIO_PORTC_PUR_R        (*((volatile uint32_t *)0x40006510))
#define GPIO_PORTD_PUR_R        (*((volatile uint32_t *)0x40007510))
#define GPIO_PORTE_PUR_R        (*((volatile uint32_t *)0x40024510))
#define GPIO_PORTF_PUR_R        (*((volatile uint32_t *)0x40025510))


typedef enum ports{PA,PB,PC,PD,PE,PF} selPort ;

void Port_SetPinPullUp(uint8_t port_index ,uint8_t pins_mask , uint8_t enable){
uint32_t PUR[] ={GPIO_PORTA_PUR_R ,GPIO_PORTB_PUR_R ,GPIO_PORTC_PUR_R,GPIO_PORTD_PUR_R,GPIO_PORTE_PUR_R ,GPIO_PORTF_PUR_R} ;

selPort pt =port_index  ;

if(enable) PUR[pt] |=pins_mask ; //assuming that the nth pin position = 1 means selected.

PUR[pt] ^=pins_mask ;


}
