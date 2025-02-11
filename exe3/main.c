#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>
//aa
const int botao_vermelho = 28;
const int botao_verde = 26;

const int led_vermelho = 4;
const int led_verde = 6;

int main() {
  stdio_init_all();

  gpio_init(botao_vermelho);
  gpio_set_dir(botao_vermelho, GPIO_IN);
  gpio_pull_up(botao_vermelho);

  gpio_init(led_vermelho);
  gpio_set_dir(led_vermelho, GPIO_OUT);



  gpio_init(botao_verde);
  gpio_set_dir(botao_verde, GPIO_IN);
  gpio_pull_up(botao_verde);

  gpio_init(led_verde);
  gpio_set_dir(led_verde, GPIO_IN);


  while (true) {
    if(!gpio_get(botao_vermelho)){

      gpio_put(led_vermelho,1);
      sleep_ms(250);

      gpio_put(led_vermelho,0);
      while (!gpio_get(botao_vermelho)) {
      };
    }
    if(!gpio_get(botao_verde)){

      gpio_put(led_verde,1);
      sleep_ms(250)

      gpio_put(led_verde,0);
      while (!gpio_get(botao_vermelho)) {
      };

    }


  }
}
