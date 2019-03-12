/*
 * UART.h
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-016
 */

#ifndef UART_H_
#define UART_H_


#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "types.h"

#define UART0_BAUD_RATE 38400

void UART0_init(void);
uint8 UART0_receive(void);
void UART0_send(uint8 ch);
void UART0_disable(void);

#endif /* UART_H_ */
