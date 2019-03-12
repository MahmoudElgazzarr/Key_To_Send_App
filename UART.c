/*
 * UART.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-016
 */
#include "UART.h"

volatile uint8_t UART_Flag = 0 ;
volatile uint8_t DataToSend = 0 ;
void UART0_init(void)
{
    //
        // Enable the UART0 module.
        //
        //
        // Enable the GPIOB peripheral
        //
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
        //
        // Wait for the GPIOB module to be ready.
        //
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
        {
        }

        /* Configure GPIO Port B pins 0 and 1 to be used as UART1.*/
        GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
        //
        // Enable UART1 functionality on GPIO Port B pins 0 and 1.
        //
        GPIOPinConfigure(GPIO_PA0_U0RX);
        GPIOPinConfigure(GPIO_PA1_U0TX);

        SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

        /* Wait for the UART0 module to be ready. */
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
        {
        }
        // Initialize the UART. Set the baud rate, number of data bits, turn off
        // parity, number of stop bits, and stick mode. The UART is enabled by the
        // function call.
        //
        UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 38400,
        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
        UART_CONFIG_PAR_NONE));
}


void UART0_Send_Task(void)
{
    if(UART_Flag == 1)
    {
        UARTCharPut(UART0_BASE, DataToSend);
        UART_Flag = 0 ;
    }
}
