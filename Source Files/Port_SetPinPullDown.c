
#include "stdint.h"


#define GPIO_PORTA_PDR_R        (*((volatile uint32_t *)0x40004514))
#define GPIO_PORTB_PDR_R        (*((volatile uint32_t *)0x40005514))
#define GPIO_PORTC_PDR_R        (*((volatile uint32_t *)0x40006514))
#define GPIO_PORTD_PDR_R        (*((volatile uint32_t *)0x40007514))
#define GPIO_PORTE_PDR_R        (*((volatile uint32_t *)0x40024514))
#define GPIO_PORTF_PDR_R        (*((volatile uint32_t *)0x40025514))

typedef enum ports{PA,PB,PC,PD,PE,PF} selPort ;


void Port_SetPinPullDown(uint8_t port_index ,uint8_t pins_mask , uint8_t enable){
uint32_t PDR[] ={GPIO_PORTA_PDR_R,GPIO_PORTB_PDR_R ,GPIO_PORTC_PDR_R,GPIO_PORTD_PDR_R,GPIO_PORTE_PDR_R ,GPIO_PORTF_PDR_R} ;
selPort pt =port_index  ;

if(enable)
PDR[pt] |=pins_mask ; //assuming that the nth pin position = 1 means selected.

else 
PDR[pt] ^=pins_mask ;


}
