#include "system.h"
#include <stdio.h>

extern volatile uint32_t uart_number;
extern void usart3_send(u8 data);

void uart_task(void *pvParameters)
{
    char buffer[100];
    int i;
    
    while(1)
    {
        // Send message to Tera Term every 1 second
        sprintf(buffer, "I am blinking every %d seconds\r\n", uart_number);
        for(i = 0; buffer[i] != '\0'; i++) {
            usart3_send(buffer[i]);
        }
        
        vTaskDelay(pdMS_TO_TICKS(1000));  // Wait 1 second
    }
}