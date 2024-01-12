#include "Sensores.h"

// esta funcao tem como objectivo simular um sensor de temperatura..
void *Sensor1(void *input) {
  ts.tv_sec = 1;    //tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0;    //Tempo em nsegundos
  int i = 0;

  while (((Dados_t *)input)->Running) {
    i = i + 1;
    int random = rand() % 40;
    array[i] = random;
    printf("%u\t, %d\n", random, array[i]);
    nanosleep(&ts, NULL);

    if (i == 20) // fazer condiçao se passar de n valores
      ((Dados_t *)input)->Running = 0; //definir flag a 0
  }
  return NULL;
}
