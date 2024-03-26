//
// Created by SC Team on 2024-03-26.
//

#ifndef GIMBAL_MINI_DEFINE_H
#define GIMBAL_MINI_DEFINE_H

#endif //GIMBAL_MINI_DEFINE_H

#ifndef DEFINE_H
#define DEFINE_H

/* typedef */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

/* Define */
//UART2
#define UART2_BUFFER_SIZE 9



/* Global Variables */

// UART2
extern u8 uart2_rx_buffer[UART2_BUFFER_SIZE];
extern int uart2_rx_index;
extern int receptionStart;


#endif