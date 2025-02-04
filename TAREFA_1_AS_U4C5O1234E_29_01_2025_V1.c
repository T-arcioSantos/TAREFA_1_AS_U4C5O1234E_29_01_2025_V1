#include <stdio.h>
#include "pico/stdlib.h"   
#include "hardware/timer.h" 

#define LED_VERDE_PIN 11
#define LED_VERMELHO_PIN 13
#define LED_AMARELO_PIN 12

// Variável que armazena o estado atual do LED
int ledOP = 1;

// Função de callback que será chamada pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado do LED a cada chamada da função de callback
    if (ledOP == 0) {
        gpio_put(LED_VERMELHO_PIN, true);
        gpio_put(LED_AMARELO_PIN, false);
        gpio_put(LED_VERDE_PIN, false);
        printf("SINAL VERMELHO. PARE!\n");
    } else if (ledOP == 1) {
        gpio_put(LED_VERMELHO_PIN, false);
        gpio_put(LED_AMARELO_PIN,true);
        gpio_put(LED_VERDE_PIN, false);
        printf("SINAL AMARELO. ATENCAO!\n");
    } else {
        gpio_put(LED_VERMELHO_PIN, false);
        gpio_put(LED_AMARELO_PIN, false);
        gpio_put (LED_VERDE_PIN, true);
        printf("SINAL VERDE. CONTINUE!\n");
    }

    // Altera o estado do LED para a próxima chamada da função de callback
    ledOP = (ledOP + 1) % 3;

    // Retorna true para manter o temporizador em execução
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, true);
    gpio_init(LED_AMARELO_PIN);
    gpio_set_dir(LED_AMARELO_PIN, true);
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, true);

    // Inicializa o LED vermelho aceso e os demais apagados
    gpio_put(LED_VERMELHO_PIN, true);
    gpio_put(LED_AMARELO_PIN, false);
    gpio_put(LED_VERDE_PIN, false);
   

    // Estrutura que armazena o temporizador
    struct repeating_timer timer;

    // Inicializa o temporizador para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito
    while (true) {
        // Imprime a mensagem da tarefa A cada 1 segundo
        printf("Tarefa 1 - U4C5O1234E - 29/01/2025\n");
        sleep_ms(1000);
    }

    return 0;
}
