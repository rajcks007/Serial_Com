#include <stdio.h>
#include "driver/uart.h"
#include "esp_log.h"
#include "string.h"


#define TXD_PIN 43  //   13
#define RXD_PIN 44  //  12

#define RX_BUF_SIZE 512 // Buffer size

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

    for (int i = 0; i < 10; i++)
    {
        char message[] = "RAJ \n";
        uart_write_bytes(UART_NUM_0,message, sizeof(message));

        char incomming_message [RX_BUF_SIZE];
        memset(incomming_message,0,sizeof(incomming_message));
        uart_read_bytes(UART_NUM_0,(uint8_t *)incomming_message, RX_BUF_SIZE,pdMS_TO_TICKS(1000));
        printf("Recive : %s \n",incomming_message);
    }


}