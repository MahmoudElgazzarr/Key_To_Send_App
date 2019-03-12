/*
 * Debouncing.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */
#include "Debouncing.h"
#include "Keypad.h"


uint8_t Debounce_Flag = 0 ;
static uint32_t Debounce_Count = 0 ;

void Debounce_Task(void)
{
    if((!GPIOPinRead(KEYPADROW1PORT,KEYPADROW1PIN)) || !GPIOPinRead(KEYPADROW2PORT,KEYPADROW2PIN) ||!GPIOPinRead(KEYPADROW3PORT,KEYPADROW3PIN))
    {
        Debounce_Count ++ ;
    }
    else
    {
        Debounce_Count = 0 ;
    }
    if(Debounce_Count >= 5)
    {
        Debounce_Flag = 1 ;
    }
    else
    {
        Debounce_Flag = 0 ;
    }

}
