/*
 * Keypad.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */

#include "Keypad.h"

/*******************************************************************/
/* Keypad_Init                                                     */
/* Parameters : N/A                                                */
/* I/p : N/A                                                       */
/* O/p : N/A                                                       */
/* Return : void                                                   */
/* Function that initalize Keypad                                  */
/*******************************************************************/
void Keypad_Init(void)
{
    /* Set ROWS and Cols Pins off keypad peripheral clock (PORT A,D,B) */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

    /* Set Cols pins to O/P */
    GPIOPinTypeGPIOOutput(KEYPADCOL1PORT, KEYPADCOL1PIN);
    GPIOPinTypeGPIOOutput(KEYPADCOL2PORT, KEYPADCOL2PIN);
    GPIOPinTypeGPIOOutput(KEYPADCOL3PORT, KEYPADCOL3PIN);

    /* Set Rows pins to I/P */
}
