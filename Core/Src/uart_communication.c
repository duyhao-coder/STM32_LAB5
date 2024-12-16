#include "uart_communication.h"
#include "command_parser.h"
#include "sofware_timer.h"
#include "main.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

extern UART_HandleTypeDef huart2; // Khai báo huart2
extern ADC_HandleTypeDef hadc1;    // Khai báo hadc1

uint32_t adc_val = 0;
uint8_t state2 = INIT;

void uart_communication_fsm() {
    switch (state2) {
        case INIT: {
            if (send_signal==1) {
                state2 =send_ADC ;
            }
            if(finish_signal==1)
            {
            	state2=send_END;
            }
            break;
        }
        case send_END: {
            if (finish_signal==1) {
                char *str = "\rFINISH\r";
                HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);

                send_signal = 0;
                finish_signal = 0;
            }
            state2=INIT;
            break;
        case send_ADC:
            if (send_signal==1) {
                if(finish_signal==1)
                {
                	state2=send_END;
                	break;
                }
                HAL_UART_Transmit(&huart2, (uint8_t*)"\r!ADC=", 6, 1000);
                char str[12];
                HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(itoa(adc_val, str, 10)), 1000);
                HAL_UART_Transmit(&huart2, (uint8_t*)" ", 1, 1000);
                HAL_UART_Transmit(&huart2, (uint8_t*)"#\r", 2, 1000);
                send_signal = 0;

                setTimer(1500);
            }

            if (timer_flag==1) {
                send_signal = 1;
            }
            break;
        }
        default:
            break;
    }
}
