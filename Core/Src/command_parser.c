#include "main.h"
#include "command_parser.h"
#include "uart_communication.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

extern UART_HandleTypeDef huart2; // Khai báo huart2
extern ADC_HandleTypeDef hadc1;    // Khai báo hadc1
#define MAX_BUFFER_SIZE 30
uint8_t request[] = {'!', 'R', 'S', 'T', '#'};
uint8_t ack[] = {'!', 'O', 'K', '#'};
uint8_t temp = '0';
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t send_signal = 0;
uint8_t finish_signal = 0;
uint8_t state1 =check_RST ;
int tempp=0;

void command_parser_fsm() {
    switch (state1) {
        case check_RST: {
            if (temp == '#') {
                int i = 4;
                tempp =1;

                while (i >= 0 ) {
                	if (index_buffer == 0) {
                	    index_buffer = 29; // Quay về cuối mảng
                	} else {
                	    index_buffer = index_buffer - 1; // Giảm giá trị đi 1
                	}
                    if (request[i] != buffer[index_buffer]) {
                        char *str1 = "\rKY TU NHAP LOI, NHAP LAI\r";
                        HAL_UART_Transmit(&huart2, (uint8_t*)str1, strlen(str1), 1000);
                        return;
                    }
                    i--;
                    if(i==0 && tempp==1)
                    {
                        send_signal = 1;
                        adc_val = HAL_ADC_GetValue(&hadc1);
                    }
                }


                state1 = check_OK;
            }
            break;
        }
        case check_OK: {
            if (temp == '#') {
                int i = 3;
                int tempp =2;
                while (i >= 0 ) {
                	if (index_buffer == 0) {
                	    index_buffer = 29; // Quay về cuối mảng
                	} else {
                	    index_buffer = index_buffer - 1; // Giảm giá trị đi 1
                	}
                    if (ack[i] != buffer[index_buffer]) {
                        char *str1 = "\rKY TU NHAP LOI, NHAP LAI\r";
                        HAL_UART_Transmit(&huart2, (uint8_t*)str1, strlen(str1), 1000);
                        return;
                    }
                    i--;
                    if(i==0 && tempp==2)
                    {
                        finish_signal = 1;
                    }
                }
                state1 = check_RST;
            }
            break;
        }
        default:
            break;
    }
}
