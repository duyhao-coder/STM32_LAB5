
#ifndef INC_UART_COMMUNICATION_H_
#define INC_UART_COMMUNICATION_H_

#include "main.h"

extern uint32_t adc_val;

extern uint8_t state2;

void uart_communication_fsm();
#define INIT 1
#define send_ADC 2
#define send_END 3

#endif /* INC_UART_COMMUNICATION_H_ */
