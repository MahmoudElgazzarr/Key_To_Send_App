

/**
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "Keypad.h"

int main(void)
{
    uint8_t key = 0 ;
    Keypad_Init();

    /*add Code Here*/
    volatile uint32_t ui32Loop;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
    while(1)
    {
        // Turn on the LED.

       key = Keypad_GetPressedKey_Task();
       if(key == 7 || key == 1 || key == 4)
       {
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
           // Delay for a bit.
           //
           for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
           {
           }

          // Turn off the LED.
          //
          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
          // Delay for a bit.
          //
          for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
          {
          }
       }
       else if (key ==8|| key == 5 || key == 2)
       {
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
           // Delay for a bit.
           //
          for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
          {
          }
          //
          // Turn off the LED.
          //
         GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
         //
         // Delay for a bit.
         //
         for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
         {
         }
      }
      else if (key == 9|| key == 3 || key == 6)
      {
          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
          GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);

          //
         // Delay for a bit.
         //
         for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
         {
         }
         // Turn off the LED.
         //
         GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

         // Delay for a bit.
         //
         for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
         {
         }
      }
      else
      {

      }

     }
}
