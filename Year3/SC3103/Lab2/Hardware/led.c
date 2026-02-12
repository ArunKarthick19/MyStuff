#include "led.h"

extern volatile uint32_t uart_number;

//LED initialization
void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
  GPIO_InitStructure.GPIO_Pin =  LED_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(LED_PORT, &GPIO_InitStructure);
	GPIO_SetBits(LED_PORT,LED_PIN);  // Start OFF
}

// Software Timer Callback - Called when timer expires
void led_timer_callback(TimerHandle_t xTimer)
{
    static uint8_t led_state = 1;  // Track LED state (1=OFF, 0=ON)
    
    if(led_state == 1) {
        // LED is currently OFF, turn it ON
        LED = 0;  // Turn ON
        led_state = 0;
        
        // Change timer period to X seconds (ON time)
        xTimerChangePeriod(xTimer, pdMS_TO_TICKS(uart_number * 1000), 0);
    }
    else {
        // LED is currently ON, turn it OFF
        LED = 1;  // Turn OFF
        led_state = 1;
        
        // Change timer period to 1 second (OFF time)
        xTimerChangePeriod(xTimer, pdMS_TO_TICKS(1000), 0);
    }
}