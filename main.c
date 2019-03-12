

/**
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>

#include "UART.h"

int main(void)
{

    //
    // Check for characters. Spin here until a character is placed
    // into the receive FIFO.
    //
    uart0_init();


    //
    // Get the character(s) in the receive FIFO.

    //
    UARTCharPut(UART0_BASE, 'A');
    while(1)
    {
        /*while(!UARTCharsAvail(UART0_BASE));

        if(UARTCharGetNonBlocking(UART0_BASE) != 'B')
        {
            UARTCharPut(UART0_BASE, 'C');

        }*/

    }
    //
    // Put a character in the output buffer.
    //
    //
    // Disable the UART.
    //
    UARTDisable(UART0_BASE);
}
