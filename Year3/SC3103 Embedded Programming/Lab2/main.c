#include "system.h"
#include "show.h"
#include "oled.h"
#include "led.h"
#include "uart.h"

// ADD THIS LINE - Function declaration
void led_timer_callback(TimerHandle_t xTimer);

// Global variables
volatile uint8_t g_rxChar = 0;
volatile uint8_t g_newData = 0;
volatile uint32_t uart_number = 1;

#define START_TASK_PRIO     4
#define START_STK_SIZE     256
#define UART_TASK_PRIO      2
#define UART_STK_SIZE       256

TaskHandle_t StartTask_Handler; 
TimerHandle_t ledTimerHandle;

void start_task(void *pvParameters);

int main(void)
{
    systemInit();
    
    xTaskCreate((TaskFunction_t)start_task,
                (const char*)"start_task",
                (uint16_t)START_STK_SIZE,
                (void*)NULL,
                (UBaseType_t)START_TASK_PRIO,
                (TaskHandle_t*)&StartTask_Handler);
                
    vTaskStartScheduler();
}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();
    
    ledTimerHandle = xTimerCreate(
        "LED_Timer",
        pdMS_TO_TICKS(1000),
        pdTRUE,
        (void*)0,
        led_timer_callback
    );
    
    if(ledTimerHandle != NULL) {
        xTimerStart(ledTimerHandle, 0);
    }
    
    xTaskCreate(uart_task, "uart_task", UART_STK_SIZE, NULL, UART_TASK_PRIO, NULL);
    xTaskCreate(show_task, "show_task", SHOW_STK_SIZE, NULL, SHOW_TASK_PRIO, NULL);
    xTaskCreate(button_task, "button_task", BUTTON_STK_SIZE, NULL, BUTTON_TASK_PRIO, NULL);
    
    vTaskDelete(StartTask_Handler);
    taskEXIT_CRITICAL();
}