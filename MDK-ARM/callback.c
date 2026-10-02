#include "main.h"
#include "usart.h"

extern uint8_t rx_msg[UART_BUFFER_SIZE];

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size)
{
    if ((huart == &huart1) &&
        ((HAL_UARTEx_GetRxEventType(huart) == HAL_UART_RXEVENT_IDLE) ||
         (HAL_UARTEx_GetRxEventType(huart) == HAL_UART_RXEVENT_TC)))
    {
        HAL_UART_Transmit_IT(&huart1,rx_msg,Size);

        HAL_UARTEx_ReceiveToIdle_DMA(&huart1,rx_msg,UART_BUFFER_SIZE);
    }
}