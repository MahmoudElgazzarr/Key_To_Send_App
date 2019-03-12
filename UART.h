/*
 * UART.h
 *
 * Created: 2/27/2019 1:17:19 PM
 *  Author: AVE-LAP-016
 */ 


#ifndef UART_H_
#define UART_H_
#include "../includes/types.h"
#include "../includes/bitwiseOperations.h"
#include "../includes/DIO.h"
#include "../includes/Config_UART.h"


#define  _UDR    *((volatile uint8*) (0x2C)) 

#define  _UBBRL  *((volatile uint8*) (0x29))

#define  _UBBRH  *((volatile uint8*) (0x40))

#define  _UCSRC  *((volatile uint8*) (0x40))
#define _UPM0 4
#define _UPM1 5
#define _URSEL 7
#define _UCSZ0 1
#define _UCSZ1 2

#define  _UCSRA  *((volatile uint8*) (0x2B))
#define _UDRE 5
#define _TXC 6
#define  _UCSRB  *((volatile uint8*) (0x2A))
#define _RXEN 4
#define _TXEN 3

typedef struct S_UART_config 
{
	uint32 baud_rate ;
	uint8 no_of_stop_bits ;
	uint8 parity_mode ;
	uint8 data_size ;
	uint8 speed_mode ;
}S_UART_config;

void UART_Init(void);
void UART_Transmit(uint8 Data);
uint8 UART_Receive(void);
void UART_TransmitString(uint8* String ,uint8 Size);



#endif /* UART_H_ */