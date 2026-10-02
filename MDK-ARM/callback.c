#include "main.h"
#include "usart.h"
#include <string.h>

extern uint8_t rx_msg[UART_BUFFER_SIZE];
extern uint8_t tx_msg[UART_BUFFER_SIZE];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        memcpy(tx_msg,rx_msg,UART_BUFFER_SIZE);

        HAL_UART_Transmit_IT(&huart1,tx_msg,UART_BUFFER_SIZE);

        HAL_UART_Receive_DMA(&huart1,rx_msg,UART_BUFFER_SIZE);
    }
}