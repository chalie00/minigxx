//
// Created by SC Team on 2024-03-26.
//
#include "main_function.h"
#include "Define.h"
#include "stdio.h"

void check_byte_cmd(int read_byte, UART_HandleTypeDef *uart2,
                    UART_HandleTypeDef *eo_uart, UART_HandleTypeDef *ir_uart) {
    //If data is 0xAA or 0x81, store a data to buffer and check a sec_byte data whether it's 0x05 or 0x01
    //If sec_byte data is not 0x05 or 0x01, clear the buffer, if 0x05 or 0x01, store data in index 1
    //If not 0xAA or 0x81, set the index 0
    if (!receptionStart) {
        if (read_byte == 0xAA || read_byte == 0x81) {
            uart2_rx_buffer[uart2_rx_index] = read_byte;
            uart2_rx_index++;
            HAL_UART_Receive_IT(uart2, &uart2_rx_buffer[uart2_rx_index], 1);
        } else if (read_byte == 0x05 || read_byte == 0x01 &&
                                        uart2_rx_buffer[0] == 0xAA || uart2_rx_buffer[0] == 0x81) {
            uart2_rx_buffer[uart2_rx_index] = read_byte;
            receptionStart = 1;
        } else {
            uart2_rx_index = 0;
        }
    } else {
        //assign buffer size after check the first and second bytes of uart2
        int buf_size = check_buf_size(uart2_rx_buffer[0], uart2_rx_buffer[1]);
        //transmit after stored data that checked up to second byte of uart2
        store_after_second_byte(receptionStart, buf_size, &receptionStart, &uart2_rx_index,
                                read_byte, uart2, eo_uart, ir_uart);
    }
    if (receptionStart) {
        uart2_rx_index++;
        HAL_UART_Receive_IT(uart2, &uart2_rx_buffer[uart2_rx_index], 1);
    }
}


//Store a data after second byte on uart2
void store_after_second_byte(int progress, int buf_size, int *receptionStart, int *uart2_rx_index,
                             int read_byte, UART_HandleTypeDef *uart2,
                             UART_HandleTypeDef *eo_uart, UART_HandleTypeDef *ir_uart) {
    //if fir_byte buffer is 0xAA and sec_byte is 0x05, store 7 more bytes
    if (*uart2_rx_index < buf_size) {
        uart2_rx_buffer[*uart2_rx_index] = read_byte;

        //If receive 9 byte, send to uart4(IR) and clear the buffer
        if (*uart2_rx_index == buf_size - 1) {
            //TODO: after verify data length and checksum, transit data
//                HAL_UART_Transmit_IT(trn_uart, uart2_rx_buffer, UART2_BUFFER_SIZE);
            parse_on_uart2(eo_uart, ir_uart, (uint8_t *) uart2_rx_buffer);
            HAL_UART_Transmit_IT(uart2, uart2_rx_buffer, buf_size);
            *receptionStart = 0;
            *uart2_rx_index = 0;
        }
    }
}


//Assignment a buffer size after check the first, second byte
int check_buf_size(int fir_byte, int sec_byte) {
    //If received data is VISCA
    if (fir_byte == 0x81 && sec_byte == 0x01) {
        int buf_size = 6;
        return buf_size;
    } else if (fir_byte == 0xAA && sec_byte == 0x05) {

        int buf_size = 9;
        return buf_size;
    }
}


/* transmit a buffer data to per-uart after check on uart2 2bytes data
    * EO
      Pelco-D: FF 01(ID)
    * IR
      Color Palettes: AA 05
*/
void parse_on_uart2(UART_HandleTypeDef *eo_uart, UART_HandleTypeDef *ir_uart, u8 *receivedData) {
    u8 fir_byte = receivedData[0];
    u8 sec_byte = receivedData[1];
    //If received data is VISCA
    if (fir_byte == 0x81) {
        switch (sec_byte) {
            case 0x01:
                HAL_UART_Transmit_IT(eo_uart, receivedData, UART2_BUFFER_SIZE - 3);
                break;

            default:
                printf("Transmit is error");
        }
    } else if (fir_byte == 0xAA) {
        switch (sec_byte) {
            case 0x05:
                HAL_UART_Transmit_IT(ir_uart, receivedData, UART2_BUFFER_SIZE);
                break;

            default:
                printf("Transmit is error");
        }
    }
}


//check data with checksum
int cal_chk_sum(u8 *receivedData, int start_idx, int chk_idx) {
    u8 buf_sum = 0;
    for (start_idx; chk_idx - 1; start_idx++) {
        buf_sum += receivedData[start_idx];
    }
    if (buf_sum == receivedData[chk_idx]) {
        return true;
    } else {
        return false;
    }
}












