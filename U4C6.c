#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "inc/font.h"
#include "src/init.h"

int main()
{
    stdio_init_all();

    init_buttons(); // incializa os botões
    init_led_matriz(); // inicializa a matriz de leds
    init_leds(); // inicializa os leds
    
    // Inicializa a tela
    ssd1306_t ssd;
    init_i2c(&ssd);

    // limpar buffer
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

    bool cor = true;

    while (true) {
        cor = !cor;

        if(stdio_usb_connected()) {
            char c;
            printf("Digite um caractere: ");
            scanf(" %c", &c); // Adicionado espaço antes de %c para consumir qualquer espaço em branco
            printf("Caractere lido: %c\n", c); // Print de depuração para verificar o caractere lido

            ssd1306_fill(&ssd, false); // Limpa o display antes de desenhar o novo caractere
            printf("Desenhando caractere...\n"); // Print de depuração antes de desenhar
            ssd1306_draw_char(&ssd, c, 60, 30);
            ssd1306_send_data(&ssd);

            printf("Caractere digitado: %c\n", c);
        }

        // Atualiza o conteúdo do display com animações
        ssd1306_send_data(&ssd); // Atualiza o display

        sleep_ms(1000);
    }
}
