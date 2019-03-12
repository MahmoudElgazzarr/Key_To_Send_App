/*
 * K2S.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-062
 */

#include "K2S.h"


void K2S_Task(void)
{

    if(Debounce_Flag >= 5)
    {
        DataToSend = Keypad_GetPressedKey();
        UART_Flag = 1 ;
    }
}
