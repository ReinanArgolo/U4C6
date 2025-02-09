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
        sleep_ms(40);
        cor = !cor;

        if(stdio_usb_connected()) {
            char c;
            if(scanf("%c", &c) == 1) {
                ssd1306_draw_char(&ssd, c, 60, 30);
            }
        }

        
        // Atualiza o conteúdo do display com animações
        ssd1306_fill(&ssd, !cor); // Limpa o display
        ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
        ssd1306_draw_char(&ssd, 'a', 60, 30);
        ssd1306_send_data(&ssd); // Atualiza o display

        sleep_ms(1000);

    }
}
