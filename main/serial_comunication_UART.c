#include <stdio.h>
#include "driver/uart.h"

#define TXD_PIN 43
#define RXD_PIN 44

#define RX_BUF_SIZE 1024 // Buffer size

void app_main(void)
{
    
    // for (int i=0;i<10;i++)
    // printf("Hello world!\n");

    uart_config_t uart_config = {

        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
    
    };

    uart_param_config(UART_NUM_0, &uart_config); //Passing uart port and config
    uart_set_pin(UART_NUM_0, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE); //set uart pin (tx:, rx:, RTS:, CTS: )
    uart_driver_install(UART_NUM_0,RX_BUF_SIZE, 0, 0, NULL, 0); //UART_Port, rx buff size, queue size, flag

    for (int i = 0; i < 10000; i++)
    {
        char message[] = "RAJ \n";
        uart_write_bytes(UART_NUM_0,message, sizeof(message));
    }
    

}