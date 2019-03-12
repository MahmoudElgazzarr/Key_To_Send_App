/*
 * Debouncing.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */
#include "Debouncing.h"
#include "Keypad.h"


uint32_t Debounce_Flag = 0 ;


void Debounce_Task(void)
{
    volatile static uint32_t status = 0;
    status = GPIOPinRead(KEYPADROW2PORT,KEYPADROW1PIN);
    if(!status)
    {
        Debounce_Flag ++ ;
    }
    else
    {
        Debounce_Flag = 0 ;
    }
 }
