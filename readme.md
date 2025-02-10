# Projeto CEPEDI U4C6

## Descrição
Este projeto utiliza uma variedade de componentes eletrônicos conectados a um Raspberry Pi Pico para demonstrar diversas funcionalidades.

## Componentes Utilizados
- **Raspberry Pi Pico** (`wokwi-pi-pico`)
- **Display OLED** (`board-ssd1306`)
- **Botões Push** (`wokwi-pushbutton`)
- **Matriz de LEDs NeoPixel** (`wokwi-neopixel-matrix`)
- **LED RGB** (`wokwi-rgb-led`)

## Funcionalidades
1. **Display OLED**:
   - Conectado aos pinos `GP14` (SDA) e `GP15` (SCL) do Raspberry Pi Pico.
   - Alimentação via `3V3` e `GND`.

2. **Botões Push**:
   - **Botão A**:
     - Conectado ao pino `GP5` do Raspberry Pi Pico.
     - Alimentação via `GND`.
   - **Botão B**:
     - Conectado ao pino `GP6` do Raspberry Pi Pico.
     - Alimentação via `GND`.

3. **Matriz de LEDs NeoPixel**:
   - Conectada ao pino `GP7` do Raspberry Pi Pico.
   - Alimentação via `VBUS` e `GND`.

4. **LED RGB**:
   - Conectado aos pinos `GP11` (G), `GP12` (B) e `GP13` (R) do Raspberry Pi Pico.
   - Alimentação via resistor de `1000 ohms` conectado ao `GND`.

## Conexões
As conexões entre os componentes e o Raspberry Pi Pico são detalhadas no arquivo `diagram.json`.

## Editor
Este projeto foi criado utilizando o editor Wokwi.

## Autor
Reinan Lopes Argolo

## Vídeo Demonstrativo
[Link para o vídeo](https://youtu.be/sZ5d_SakxSE)
