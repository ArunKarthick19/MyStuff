#include "playSong.h"
#include "buzzer.h"

static u8* song = (uint8_t*)"e2,d2,e2,d2,e2,B2,d2,c2,A2_C2,E2,A2,B2_E2,G2,B2,c4_E2,e2,d2,e2,d2,e2,B2,d2,c2,A2_C2,E2,A2,B2_E2,c2,B2,A4";

static u32 notes[] = {
    2272, // A - 440 Hz
    2024, // B - 494 Hz
    3822, // C - 261 Hz
    3401, // D - 294 Hz
    3030, // E - 330 Hz
    2865, // F - 349 Hz
    2551, // G - 392 Hz
    1136, // a - 880 Hz
    1012, // b - 988 Hz
    1912, // c - 523 Hz
    1703, // d - 587 Hz
    1517, // e - 659 Hz
    1432, // f - 698 Hz
    1275, // g - 784 Hz
};

void BUTTON_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = BUTTON_PIN;	
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BUTTON_PORT, &GPIO_InitStructure);
}

uint32_t getNote(uint8_t ch)
{
    if (ch >= 'A' && ch <= 'G')
        return notes[ch - 'A'];
    if (ch >= 'a' && ch <= 'g')
        return notes[ch - 'a' + 7];
    return 0;
}

uint32_t getDuration(uint8_t ch)
{
    if (ch < '0' || ch > '9')
        return 500;
    return (ch - '0') * 250;
}

uint32_t getPause(uint8_t ch)
{
    switch (ch) {
        case '+': return 0;
        case ',': return 5;
        case '.': return 20;
        case '_': return 30;
        default: return 5;
    }
}

uint8_t playNote(uint32_t note, uint32_t durationMs)
{
    uint32_t t = 0;
    uint32_t elapsed = 0;
    
    if (note > 0) {
        while (t < (durationMs*1000)) {
            if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON_PIN) != 0) {
                BUZZER = 0;
                return 0;
            }
            
            BUZZER = 1;
            delay_us(note/2);
            BUZZER = 0;
            delay_us(note/2);
            t += note;
        }
    }
    else {
        elapsed = 0;
        while(elapsed < durationMs) {
            if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON_PIN) != 0) {
                return 0;
            }
            delay_xms(1);
            elapsed++;
        }
    }
    
    return 1;
}

void playSong(uint8_t *song) 
{
    uint32_t note = 0;
    uint32_t dur = 0;
    uint32_t pause = 0;
    uint32_t p = 0;
    
    while(*song != '\0') {
        note = getNote(*song++);
        if (*song == '\0')
            break;
        dur = getDuration(*song++);
        if (*song == '\0')
            break;
        pause = getPause(*song++);
        
        if(playNote(note, dur) == 0) {
            BUZZER = 0;
            return;
        }
        
        p = 0;
        while(p < pause) {
            if(GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON_PIN) != 0) {
                BUZZER = 0;
                return;
            }
            delay_us(1);
            p++;
        }
    }
    
    BUZZER = 0;
}

void button_task(void *pvParameters)
{
    uint8_t button_current = 1;
    
    while(1)
    {
        button_current = GPIO_ReadInputDataBit(BUTTON_PORT, BUTTON_PIN);
        
        if(button_current == 0)
        {
            playSong(song);
        }
        
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}