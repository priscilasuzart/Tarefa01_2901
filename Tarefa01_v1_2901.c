#include <stdio.h>
#include "pico/stdlib.h"   // Inclui a biblioteca padrão para funcionalidades básicas como GPIO, temporização e comunicação serial.
#include "hardware/timer.h" // Inclui a biblioteca para gerenciamento de temporizadores de hardware.

#define LED_PIN_GREEN 11
#define LED_PIN_YELLOW 12
#define LED_PIN_RED 13

typedef enum    {
    RED,
    YELLOW, 
    GREEN
} EstadoSemaforo;

EstadoSemaforo current_state = RED;

// Função de callback que será chamada repetidamente pelo temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDS antes de mudar para o próximo estado
    gpio_put(LED_PIN_RED, 0);
    gpio_put(LED_PIN_YELLOW, 0);
    gpio_put(LED_PIN_GREEN,0);

    //Muda o estado do semáforo
    switch (current_state) {
        case RED:
            current_state = YELLOW;
            gpio_put(LED_PIN_YELLOW, 1);
            break;
        case YELLOW:
            current_state = GREEN;
            gpio_put(LED_PIN_GREEN, 1);
            break;
        case GREEN:
            current_state = RED;
            gpio_put(LED_PIN_RED, 1);
            break;

    }
    
    // Retorna true para manter o temporizador repetindo. Se retornar false, o temporizador para.
    return true;
}

int main() {
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializar os pinos
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

   //Inicializa o semáforo com o LED vermelho aceso
   gpio_put(LED_PIN_RED, 1);
   
    // Declaração de uma estrutura de temporizador de repetição.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 1 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        // Imprime a mensagem a cada
        printf("Semáforo funcionando...\n");
        sleep_ms(1000);

    }
    return 0;
}
