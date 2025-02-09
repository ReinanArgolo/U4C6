#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "inc/font.h"
#include "src/init.h"
#include "hardware/clocks.h"
#include "inc/funcoesMatriz.h"

#include "ws2818b.pio.h"

// Global variable for the ssd object
ssd1306_t ssd;

#define DEBOUNCE_DELAY_MS 200

// Global variables for debouncing
absolute_time_t last_interrupt_time_b1 = {0};
absolute_time_t last_interrupt_time_b2 = {0};

// Function to handle button press interrupt
void button_callback(uint gpio, uint32_t events) {
    absolute_time_t current_time = get_absolute_time();
    if (gpio == B1_PIN) {
        if (absolute_time_diff_us(last_interrupt_time_b1, current_time) < DEBOUNCE_DELAY_MS * 1000) {
            return; // Ignore if within debounce delay
        }
        last_interrupt_time_b1 = current_time;
        printf("Botão 1 pressionado\n");
        gpio_put(LED_GREEN_PIN, !gpio_get(LED_GREEN_PIN));
        ssd1306_fill(&ssd, false); // Clear the display before drawing
        ssd1306_draw_string(&ssd, "LED VERDE", 0, 20);
        if(gpio_get(LED_GREEN_PIN)) {
            ssd1306_draw_string(&ssd, "LIGADO", 0, 40);
        } else {
            ssd1306_draw_string(&ssd, "DESLIGADO", 0, 40);

        }
        ssd1306_send_data(&ssd);
    } else if (gpio == B2_PIN) {
        if (absolute_time_diff_us(last_interrupt_time_b2, current_time) < DEBOUNCE_DELAY_MS * 1000) {
            return; // Ignore if within debounce delay
        }
        last_interrupt_time_b2 = current_time;
        printf("Botão 2 pressionado\n");
        gpio_put(LED_BLUE_PIN, !gpio_get(LED_BLUE_PIN));
        ssd1306_fill(&ssd, false); // Clear the display before drawing
        ssd1306_draw_string(&ssd, "LED AZUL", 0, 20);
        if(gpio_get(LED_BLUE_PIN)) {
            ssd1306_draw_string(&ssd, "LIGADO", 0, 40);
        } else {
            ssd1306_draw_string(&ssd, "DESLIGADO", 0, 40);
        }
        ssd1306_send_data(&ssd);
    }
}

int main()
{
    stdio_init_all();
    printf("Inicialização completa\n");

    npLED_t leds[LED_COUNT];

    init_buttons(); // incializa os botões
    init_led_matriz(); // inicializa a matriz de leds
    init_leds(); // inicializa os leds

    matrizInit(LED_PIN, leds); // Inicializa a matriz de leds
    
    // Inicializa a tela
    init_i2c(&ssd);

    // limpar buffer
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    // Configure button interrupts
    gpio_set_irq_enabled_with_callback(B1_PIN, GPIO_IRQ_EDGE_RISE, true, &button_callback);
    gpio_set_irq_enabled_with_callback(B2_PIN, GPIO_IRQ_EDGE_RISE, true, &button_callback);

    bool cor = true;

    while (true) {
        cor = !cor;

        // Debug print to check button state
        printf("Botão 1: %d\n", gpio_get(B1_PIN));
        printf("Botão 2: %d\n", gpio_get(B2_PIN));

        sleep_ms(100);

        if(stdio_usb_connected()) {
            char c;
            printf("Digite um caractere: ");
            scanf(" %c", &c); // Adicionado espaço antes de %c para consumir qualquer espaço em branco
            printf("Caractere lido: %c\n", c); // Print de depuração para verificar o caractere lido

            ssd1306_fill(&ssd, false); // Limpa o display antes de desenhar o novo caractere
            printf("Desenhando caractere...\n"); // Print de depuração antes de desenhar
            ssd1306_draw_char(&ssd, c, 60, 30);
            ssd1306_send_data(&ssd);

            if(c >= '0' && c <= '9') {
               writeNumberToMatrix(c, leds);
            } else {
                turnOffLEDs(leds);
            }

            printf("Caractere digitado: %c\n", c);

        }

        // Atualiza o conteúdo do display com animações
        ssd1306_send_data(&ssd); // Atualiza o display

        sleep_ms(1000);
    }
}
