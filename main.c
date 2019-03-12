

/**
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
uint32_t count = 0;

void SysTickIntHandler();

int main(void)
{
    /*add Code Here*/
    volatile uint32_t ui32Loop;

    IntMasterEnable();
    SysTickIntEnable();

    SysTickIntRegister(SysTickIntHandler);

    SysTickPeriodSet(16000000UL);

    SysTickEnable();



    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    //
    // Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

    // Loop forever.
    //
    while(1)
    {
        //
        // Turn on the LED.
        //
        if(count < 1)
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        }
        if(count > 2)
        {
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
        }
        if(count > 3)
        {
            count = 0;
        }
        }
}
void SysTickIntHandler()
{
    count++;
}
