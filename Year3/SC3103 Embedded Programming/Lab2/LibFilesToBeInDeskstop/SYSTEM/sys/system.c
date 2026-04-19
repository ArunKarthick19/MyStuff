#include "system.h"

extern volatile uint8_t g_rxChar;
extern volatile uint8_t g_newData;

// USART3 IRQ Handler
int USART3_IRQHandler(void)
{
    uint8_t Usart_Receive;
    
    if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) 
    {
        Usart_Receive = USART_ReceiveData(USART3);
        g_rxChar = Usart_Receive;
        g_newData = 1;  // Flag new data
    } 
    return 0;
}

// USART3 Send function
void usart3_send(u8 data)
{
    USART3->DR = (uint16_t)data; 
    while((USART3->SR & USART_FLAG_TC) == RESET);
}

// USART3 Initialization
void uart3_init(u32 bound)
{ 
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
    GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    USART_InitStructure.USART_BaudRate = bound;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART3, &USART_InitStructure);
    
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART3, ENABLE);
}

void systemInit(void)
{       
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    
    delay_init(168);
    
    LED_Init();
    BUZZER_Init();
    OLED_Init();
    uart3_init(115200);  // ? IMPORTANT!
	 BUTTON_Init(); 
}