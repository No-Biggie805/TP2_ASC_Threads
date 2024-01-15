#include "Sensores.h"

// esta funcao tem como objectivo simular um sensor de temperatura.. Sensor 1 de
// temperatura
void *Sensor1(void *input) {
  ts.tv_sec =
      1; // tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0; // Tempo em nsegundos
  int i = 0, j;

  while (((Dados_t *)input)->Running) {
    // fazer o mutex na funcao, possivel ter de mudar!!

    // while (FLAG == 1) { // enquanto a flag for 0, ele espera pelo thread
    //   // esperando pelo thread
    //   pthread_cond_wait(&condVar, &mutex);
    // }
    FLAG = 0;
    nanosleep(&ts, NULL);
    pthread_mutex_lock(&mutex);
    i = i + 1;
    printf("Thread 1.1:\n");
    int random = rand() % 40;
    for (j = 0; j < TAM - 1; j++)
      FIFO[j] = FIFO[j + 1];
    FIFO[TAM - 1] = random;

    for (j = 0; j < TAM; j++) {
      if (j == 0)
        printf("[%d", FIFO[j]);
      else if (j == TAM - 1)
        printf("|%d]\n", FIFO[j]);
      else
        printf("|%d", FIFO[j]);
    }
    printf("Novo Valor Adicionado,%d\n", random);
    Contador += 1;
    printf("Contagem:%d\n", Contador);
    printf("----------x---------\n");

    if (i == 20)
      ((Dados_t *)input)->Running = 0; // definir flag a 0
    pthread_mutex_unlock(&mutex);

    FLAG = 1;                      // sinalizar que acabou o thread no momento
    pthread_cond_signal(&condVar); // enviar o sinal para o thread 1.3
  }
  return NULL;
}

// Funcao do sensor2
void *Sensor2(void *input) {

  // while (FLAG == 1) { // enquanto a flag for 0, ele espera pelo thread
  //   // esperando pelo thread
  //   pthread_cond_wait(&condVar, &mutex);
  // }
  FLAG = 0;
  ts.tv_sec =
      1; // tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0; // Tempo em nsegundos
  int i = 0, j;

  while (((Dados_t *)input)->Running2) {
    nanosleep(&ts, NULL);
    pthread_mutex_lock(&mutex);
    i = i + 1;
    printf("Thread 1.2:\n");
    int random = rand() % 40;
    for (j = 0; j < TAM - 1; j++)
      FIFO[j] = FIFO[j + 1];
    FIFO[TAM - 1] = random;

    // print do buffer
    for (j = 0; j < TAM; j++) {
      if (j == 0)
        printf("[%d", FIFO[j]);
      else if (j == TAM - 1)
        printf("|%d]\n", FIFO[j]);
      else
        printf("|%d", FIFO[j]);
    }
    printf("Novo Valor Adicionado,%d\n", random);
    Contador += 1;
    printf("Contagem:%d\n", Contador);
    printf("----------x---------\n");

    if (i == 30) // fazer condiçao se passar de n valores
      ((Dados_t *)input)->Running2 = 0; // definir flag a 0

    pthread_mutex_unlock(&mutex);

    FLAG = 1;                      // sinalizar que acabou o thread no momento
    pthread_cond_signal(&condVar); // enviar o sinal para o thread 1.3
  }
  return NULL;
}

void *ThreadMedia(void *input) {

  while (1) {
    pthread_mutex_lock(&mutex);
    while (FLAG == 0) { // enquanto a flag for 0, ele espera pelo thread
      // esperando pelo thread
      pthread_cond_wait(&condVar, &mutex);
    } // Sendo 1, deixa de esperar e executa o thread 1.3
    // Executar o thread 1.3
    printf("Teste, teste, Sou o processso 1.3\n");

    // FLAG = 0;
    
    if (Contador < 50) //Definir antes do lock flag 1
      FLAG = 0;
    else if(Contador == 50)     //Senao 1, para quando voltar acima e descer nao fazer condition wait
      return NULL;

    // printf("Teste, teste, Sou o processso 1.3");
    pthread_mutex_unlock(&mutex);
  }
  // return NULL;
}
