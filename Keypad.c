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

    /* Set Rows To I/p */
    GPIOPinTypeGPIOInput(KEYPADROW1PORT, KEYPADROW1PIN);
    GPIOPinTypeGPIOInput(KEYPADROW2PORT, KEYPADROW2PIN);
    GPIOPinTypeGPIOInput(KEYPADROW3PORT, KEYPADROW3PIN);

    /* Set Internal Pull Ups */
    GPIOPadConfigSet(KEYPADROW1PORT,KEYPADROW1PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(KEYPADROW2PORT,KEYPADROW2PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
    GPIOPadConfigSet(KEYPADROW3PORT,KEYPADROW3PIN,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
}
