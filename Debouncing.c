/*
 * Debouncing.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */
#include "Debouncing.h"

uint8_t Deboune_Flag = 0 ;

void Debounce_Task()
{
    if(!GPIOPinRead(KEYPADROW1PORT,KEYPADROW1PIN | KEYPADROW2PIN | KEYPADROW3PIN))
        Debounce_Flag ++ ;
    else
        Debounce_Flag = 0 ;
    }
}
