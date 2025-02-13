#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int botao_vermelho = 28;
const int botao_verde = 26;

const int led_vermelho = 4;
const int led_verde = 6;



int main() {
  stdio_init_all();

  int status_vermelho = 0;
  int status_verde = 0;

  gpio_init(botao_vermelho);
  gpio_set_dir(botao_vermelho, GPIO_IN);
  gpio_pull_up(botao_vermelho);

  gpio_init(led_vermelho);
  gpio_set_dir(led_vermelho, GPIO_OUT);



  gpio_init(botao_verde);
  gpio_set_dir(botao_verde, GPIO_IN);
  gpio_pull_up(botao_verde);

  gpio_init(led_verde);
  gpio_set_dir(led_verde, GPIO_OUT);


  // while(true){

  //   // jeito que o corsi me mostrou mo daora
  //   if(!gpio_get(botao_vermelho) ){
  //     status_vermelho = !status_vermelho;  //sacada boa
  //     gpio_put(led_vermelho, status_vermelho);
  //     while (!gpio_get(botao_vermelho)) {
  //     };

  //   }

  // }

  while (true) {

    // esse if verifica se apertou o botao e o esta desligado o led
    if(!gpio_get(botao_vermelho) && status_vermelho == 0){

      gpio_put(led_vermelho,1);
      status_vermelho = 1;
      
      // while para soltar o botao
      while (!gpio_get(botao_vermelho)) {
      };

        
    }

    // if para caso o led esta ligado e quando vc aperta ele desliga o led
    if (!gpio_get(botao_vermelho) && status_vermelho == 1){

      gpio_put(led_vermelho,0);
      status_vermelho = 0;
      }

      while (!gpio_get(botao_vermelho)) {
      };


      //verde
    if(!gpio_get(botao_verde) && status_verde == 0){

      gpio_put(led_verde,1);
      status_verde = 1;


      while (!gpio_get(botao_verde)) {
      };

    }

    if (!gpio_get(botao_verde) && status_verde == 1){

      gpio_put(led_verde,0);
      status_verde = 0;
      }

      while (!gpio_get(botao_verde)) {
      };


  }
}
