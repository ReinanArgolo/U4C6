#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#define LED_BLUE_PIN 11
#define LED_RED_PIN 12
#define LED_GREEN_PIN 13
#define LED_MATRIZ_PIN 7
#define B1_PIN 5
#define B2_PIN 6

// I2C Pins TELA LCD
#define LCD_SDA_PIN 14
#define LCD_SCL_PIN 15


int main()
{
    stdio_init_all();
    gpio_init(LED_BLUE_PIN);
    gpio_init(LED_RED_PIN);
    gpio_init(LED_GREEN_PIN);
    gpio_init(LED_MATRIZ_PIN);
    gpio_init(B1_PIN);
    gpio_init(B2_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);
    gpio_set_dir(LED_MATRIZ_PIN, GPIO_OUT);
    gpio_set_dir(B1_PIN, GPIO_IN);
    gpio_set_dir(B2_PIN, GPIO_IN);

    


   

    while (true) {
       
        
    }
}
