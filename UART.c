/*
 * UART.c
 *
 * Created: 2/27/2019 1:16:53 PM
 *  Author: AVE-LAP-016
 */ 
#include "../includes/UART.h"

 void UART_Init(void)
 {
	 
	 S_UART_config uart_object = {BAUDRATE,NO_STOPBITS,PARITYMODE,DATASIZE,SPEEDMODE};
	 /* calculate baud rate */
	 uint16 ubbr = (F_CPU/(16*uart_object.baud_rate)) - 1 ;
	 uint8 ucsrc = 0 ;

	 /* set baud rate */
	 _UBBRH = (uint8)((0xFF00 & ubbr)>>8) ;
	 _UBBRL = (uint8)(0x00FF & ubbr) ;
	 
	
	  Set_Bit(ucsrc,_URSEL);
	 /* enable transmit and receive */
	 _UCSRB = (1<<_RXEN)|(1<<_TXEN) ;
	 
  /* speed mode */
  switch(uart_object.speed_mode)
  {
	case DISABLED :
	  Clear_Bit(_UCSRA,_U2X);
	  break;
	  
	case ENABLED :
	  Set_Bit(_UCSRA,_U2X);
	  break;
  }
  /* number of stop bits */
  switch(uart_object.no_of_stop_bits)
  {
	 case ONE_STOP_BIT :
	         Clear_Bit(ucsrc,_USBS);
			 break;
	 case TWO_STOP_BITS :
	         Set_Bit(ucsrc,_USBS);
	         break;
  }
  
   /* data_size */
  switch (uart_object.data_size)
   {
	case FIVE_BITS :
		 Clear_Bit(ucsrc,_UCSZ0);
		 Clear_Bit(ucsrc,_UCSZ1);
		 Clear_Bit(_UCSRB,_UCSZ2);
		break ;
		
	case SIX_BITS :
		 Set_Bit(ucsrc,_UCSZ0);
		 Clear_Bit(ucsrc,_UCSZ1);
		 Clear_Bit(_UCSRB,_UCSZ2);
		break;
		
	case SEVEN_BITS :
		 Clear_Bit(ucsrc,_UCSZ0);
		 Set_Bit(ucsrc,_UCSZ1);
		 Clear_Bit(_UCSRB,_UCSZ2);
		 break;
	case EIGHT_BITS :
	     Set_Bit(ucsrc,_UCSZ0);
	     Set_Bit(ucsrc,_UCSZ1);
		 Clear_Bit(_UCSRB,_UCSZ2);
	    break;
	case NINE_BITS :
	     Set_Bit(ucsrc,_UCSZ0);
	     Set_Bit(ucsrc,_UCSZ1);
		 Set_Bit(_UCSRB,_UCSZ2);
	    break;
   }
	
   
	/* setting parity mode */
	switch (uart_object.parity_mode)
	{
		case NO_PARITY :
		     Clear_Bit(ucsrc,_UPM0);
		     Clear_Bit(ucsrc,_UPM1);
			 break ;
		case EVEN_PARITY :
		     Clear_Bit(ucsrc,_UPM0);
		     Set_Bit(ucsrc,_UPM1);
		     break;
		case ODD_PARITY :
		     Set_Bit(ucsrc,_UPM0);
		     Set_Bit(ucsrc,_UPM1);
			 break;
	}
	
		_UCSRC = ucsrc ;
	

 }
 
 void UART_Transmit(uint8 Data)
 {
	  while( Get_Bit(_UCSRA,_UDRE) == 0 ); 
	  
	 _UDR = Data ;
 }

uint8 UART_Receive()
{
	/* Wait for data to be received */
	while ( Get_Bit(_UCSRA,_RXC) == 0  );
	
	/* Get and return received data from buffer */
	return _UDR;
}