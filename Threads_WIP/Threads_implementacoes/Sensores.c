#include "Sensores.h"

// esta funcao tem como objectivo simular um sensor de temperatura.. Sensor 1 de temperatura
void *Sensor1(void *input) {
  
  ts.tv_sec = 1;    //tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0;    //Tempo em nsegundos
  int i = 0;

  while (((Dados_t *)input)->Running) {
    //fazer o mutex na funcao, possivel ter de mudar!!
    pthread_mutex_lock (&mutex);
    
    i = i + 1;
    int random = rand() % 40;
    array[i] = random;
    printf("%u\t, %d\n", random, array[i]);
    nanosleep(&ts, NULL);

    if (i == 20) // fazer condiçao se passar de n valores
      ((Dados_t *)input)->Running = 0; //definir flag a 0
    
    pthread_mutex_unlock (&mutex);
  }
  return NULL;
}


//Funcao do sensor2
void *Sensor2(void *input) {
   
  ts.tv_sec = 1;    //tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0;    //Tempo em nsegundos
  int i = 0;

  while (((Dados_t *)input)->Running) {
    pthread_mutex_lock (&mutex);
    i = i + 1;
    int random = rand() % 40;
    array[i] = random;
    printf("%u\t, %d\n", random, array[i]);
    nanosleep(&ts, NULL);

    if (i == 30) // fazer condiçao se passar de n valores
      ((Dados_t *)input)->Running = 0; //definir flag a 0
    
    pthread_mutex_unlock (&mutex);
  }
  return NULL;
}
