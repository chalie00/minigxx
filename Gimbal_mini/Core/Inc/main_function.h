//
// Created by SC Team on 2024-03-26.
//

#include "main.h"
#include "Define.h"

#ifndef GIMBAL_MINI_MAIN_FUNCTION_H
#define GIMBAL_MINI_MAIN_FUNCTION_H

#endif //GIMBAL_MINI_MAIN_FUNCTION_H

#ifndef MAIN_FUNCTION_H
#define MAIN_FUNCTION_H

void check_byte_cmd(int read_byte, UART_HandleTypeDef *uart2,
                    UART_HandleTypeDef *eo_uart, UART_HandleTypeDef *ir_uart);

void store_after_second_byte(int progress, int buf_size, int *receptionStart, int *uart2_rx_index,
                             int read_byte, UART_HandleTypeDef *uart2,
                             UART_HandleTypeDef *eo_uart, UART_HandleTypeDef *ir_uart);

int check_buf_size(int fir_byte, int sec_byte);

void parse_on_uart2(UART_HandleTypeDef *eo_uart, UART_HandleTypeDef *ir_uart, uint8_t *receivedData);


#endif /* MAIN_FUNCTION_H*/
