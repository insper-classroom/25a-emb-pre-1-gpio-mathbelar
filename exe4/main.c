#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int botao = 28;
const int led_vermelho = 5;
const int led_roxo = 8;
const int led_azul = 11;
const int led_amarelo = 15;


int main() {
  stdio_init_all();

  gpio_init(botao);
  gpio_set_dir(botao, GPIO_IN);
  gpio_pull_up(botao);  
  
  gpio_init(led_vermelho);
  gpio_set_dir(led_vermelho, GPIO_OUT);

  gpio_init(led_roxo);
  gpio_set_dir(led_roxo, GPIO_OUT);

  gpio_init(led_azul);
  gpio_set_dir(led_azul, GPIO_OUT);

  gpio_init(led_amarelo);
  gpio_set_dir(led_amarelo, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados

    if(!gpio_get(botao)){

      gpio_put(led_vermelho,1);
      sleep_ms(300);

      gpio_put(led_vermelho,0);

      gpio_put(led_roxo,1);
      sleep_ms(300);

      gpio_put(led_roxo,0);

      gpio_put(led_azul,1);
      sleep_ms(300);
      
      gpio_put(led_azul,0);

      gpio_put(led_amarelo,1);
      sleep_ms(300);

      gpio_put(led_amarelo,0);

      while (!gpio_get(botao)) {
      };



    }

    
    
  }
}
