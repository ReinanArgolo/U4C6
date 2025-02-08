#include <stdio.h>
#include "pico/stdlib.h"

#define LED_BLUE_PIN 11
#define LED_RED_PIN 12
#define LED_GREEN_PIN 13


int main()
{
    stdio_init_all();

    gpio_init(LED_BLUE_PIN);
    gpio_set_dir(LED_BLUE_PIN, GPIO_OUT);

    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);

    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_BLUE_PIN, true);
        sleep_ms(500);
        gpio_put(LED_BLUE_PIN, 0);
        sleep_ms(500);

        gpio_put(LED_RED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_RED_PIN, 0);
        sleep_ms(500);

        gpio_put(LED_GREEN_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_GREEN_PIN, 0);
        sleep_ms(500);
        
    }
}
