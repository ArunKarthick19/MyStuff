#include "show.h"
#include <stdio.h>

#define RATE_1_HZ 1

extern volatile uint8_t g_rxChar;
extern volatile uint8_t g_newData;
extern volatile uint32_t uart_number;
extern void usart3_send(u8 data);  // ADD THIS

void show_task(void *pvParameters)
{
    u32 lastWakeTime = getSysTickCnt();
    char buffer[100];
    int i;
    
    while(1)
    {	
        vTaskDelayUntil(&lastWakeTime, F2T(RATE_1_HZ));
        
        // Check if new data received from UART
        if(g_newData) 
        {
            g_newData = 0;  // Clear flag
            
            // Clear OLED
            OLED_Clear();
            
            // Check if it's a digit (1-9)
            if(g_rxChar >= '1' && g_rxChar <= '9') 
            {
                // Convert character to number and store it
                uart_number = g_rxChar - '0';
                
                // ===== SEND MESSAGE TO TERA TERM =====
                sprintf(buffer, "I am blinking every %d seconds\r\n", uart_number);
                for(i = 0; buffer[i] != '\0'; i++) {
                    usart3_send(buffer[i]);
                }
                // ======================================
                
                // Line 1: "I will blink"
                sprintf(buffer, "I will blink");
                OLED_ShowString(0, 0, (uint8_t*)buffer);
                
                // Line 2: "for X sec"
                sprintf(buffer, "for %d sec", uart_number);
                OLED_ShowString(0, 16, (uint8_t*)buffer);
            }
            else 
            {
                // If not a digit, show error message
                sprintf(buffer, "Press 1-9");
                OLED_ShowString(0, 0, (uint8_t*)buffer);
                
                // Send error to Tera Term too
                sprintf(buffer, "Please enter a number 1-9\r\n");
                for(i = 0; buffer[i] != '\0'; i++) {
                    usart3_send(buffer[i]);
                }
            }
            
            // Refresh OLED to display
            OLED_Refresh_Gram();
        }
    }
}