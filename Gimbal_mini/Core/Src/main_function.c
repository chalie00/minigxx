//
// Created by SC Team on 2024-03-26.
//
#include "main_function.h"
#include "Define.h"

void check_byte_cmd(int fir_byte, int sec_byte, int read_byte,
                    UART_HandleTypeDef *rcv_uart, UART_HandleTypeDef *trn_uart) {
    //If data is 0xAA, store a data to buffer and check a sec_byte data whether it's 0x05
    //If sec_byte data is not 0x05, clear the buffer, if 0x05, store data in index 1
    //If not 0xAA, set the index 0
    if (!receptionStart) {
        if (read_byte == fir_byte) {
            uart2_rx_buffer[uart2_rx_index] = read_byte;
            uart2_rx_index++;
            HAL_UART_Receive_IT(rcv_uart, &uart2_rx_buffer[uart2_rx_index], 1);
        } else if (read_byte == sec_byte && uart2_rx_buffer[0] == fir_byte) {
            uart2_rx_buffer[uart2_rx_index] = read_byte;
            receptionStart = 1;
        } else {
            uart2_rx_index = 0;
        }
    } else {
        //if fir_byte buffer is 0xAA and sec_byte is 0x05, store 7 more bytes
        if (uart2_rx_index < UART2_BUFFER_SIZE) {
            uart2_rx_buffer[uart2_rx_index] = read_byte;

            //If receive 9 byte, send to uart4(IR) and clear the buffer
            if (uart2_rx_index == UART2_BUFFER_SIZE - 1) {
                //TODO: after verify data length and checksum, transit data
                HAL_UART_Transmit_IT(trn_uart, uart2_rx_buffer, UART2_BUFFER_SIZE);
                HAL_UART_Transmit_IT(rcv_uart, uart2_rx_buffer, UART2_BUFFER_SIZE);
                receptionStart = 0;
                uart2_rx_index = 0;
            }
        }
    }
    if (receptionStart) {
        uart2_rx_index++;
        HAL_UART_Receive_IT(rcv_uart, &uart2_rx_buffer[uart2_rx_index], 1);

    }
}
