#include "Sensores.h"

// esta funcao tem como objectivo simular um sensor de temperatura.. Sensor 1 de
// temperatura
void *Sensor1_Lux(void *input) {
  ArrSize_Lux = sizeof(FIFO_Lux) / sizeof(FIFO_Lux[0]);
  FLAG_Lux = 0;

  ts.tv_sec =
      2; // tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0; // Tempo em nsegundos
  int i = 0, j;

  while (((Dados_t2 *)input)->Running) {
    // fazer o mutex_Lux na funcao, possivel ter de mudar!!
    
    nanosleep(&ts, NULL);
    
    pthread_mutex_lock(&mutex_Lux);
    
    fflush(stdout);
    i = i + 1;
    printf("Thread 2.1:\n");

    int random = rand() % (30 - 20 + 1) + 20;

    for (j = 0; j < TAM_Lux - 1; j++)
      FIFO_Lux[j] = FIFO_Lux[j + 1];
    FIFO_Lux[TAM_Lux - 1] = random;

    ((Dados_t2 *)input)->soma_Lux += FIFO_Lux[TAM_Lux - 1];

    for (j = 0; j < TAM_Lux; j++) {
      if (j == 0)
        printf("[%d", FIFO_Lux[j]);
      else if (j == TAM_Lux - 1)
        printf("|%d]\n", FIFO_Lux[j]);
      else
        printf("|%d", FIFO_Lux[j]);
    }

    printf("Novo Valor Adicionado,%d\n", random);
    Contador_Lux += 1;

    printf("soma: %d\n", ((Dados_t2 *)input)->soma_Lux);
    (((Dados_t2 *)input)->media_Lux) =
        (float)(((Dados_t2 *)input)->soma_Lux) / (float)ArrSize_Lux;

    // for (j = 0; j < TAM; j++)
    //   ((Dados_t2 *)input)->soma_Temperatura +=
    //       FIFO_Lux[j]; // adicionar valor à memória da soma

    ((Dados_t2 *)input)->soma_Lux -= FIFO_Lux[0];

    printf("Contagem:%d\n", Contador_Lux);
    printf("----------x---------\n");

    if (i == 20)
      ((Dados_t2 *)input)->Running = 0; // definir flag a 0
    pthread_mutex_unlock(&mutex_Lux);

    FLAG_Lux = 1; // sinalizar que acabou o thread no momento
    pthread_cond_signal(&condVar_Lux); // enviar o sinal para o thread 1.3
  }
  return NULL;
}

// Funcao do sensor2
void *Sensor2_Lux(void *input) {

  ArrSize_Lux = sizeof(FIFO_Lux) / sizeof(FIFO_Lux[0]);
  FLAG_Lux = 0;
  ts.tv_sec =
      2; // tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0; // Tempo em nsegundos
  int i = 0, j;

  while (((Dados_t2 *)input)->Running2) {
     
    nanosleep(&ts, NULL);

    pthread_mutex_lock(&mutex_Lux);
    
    fflush(stdout);
    
    i = i + 1;
    printf("Thread 2.2:\n");

    int random = rand() % (35 - 25 + 1) + 25;

    for (j = 0; j < TAM_Lux - 1; j++)
      FIFO_Lux[j] = FIFO_Lux[j + 1];
    FIFO_Lux[TAM_Lux - 1] = random;
    ((Dados_t2 *)input)->soma_Lux += FIFO_Lux[TAM_Lux - 1];

    // print do buffer
    for (j = 0; j < TAM_Lux; j++) {
      if (j == 0)
        printf("[%d", FIFO_Lux[j]);
      else if (j == TAM_Lux - 1)
        printf("|%d]\n", FIFO_Lux[j]);
      else
        printf("|%d", FIFO_Lux[j]);
    }
    
    printf("Novo Valor Adicionado,%d\n", random);
    Contador_Lux += 1;
    printf("soma: %d\n", ((Dados_t2 *)input)->soma_Lux);
    (((Dados_t2 *)input)->media_Lux) =
        (float)(((Dados_t2 *)input)->soma_Lux) / (float)ArrSize_Lux;

    // for (j = 0; j < TAM - 1; j++)
    //   ((Dados_t *)input)->soma_Temperatura +=
    //       FIFO_Lux[j]; // adicionar valor à memória da soma

    ((Dados_t2 *)input)->soma_Lux -= FIFO_Lux[0];

    printf("Contagem:%d\n", Contador_Lux);
    printf("----------x---------\n");

    if (i == 30) // fazer condiçao se passar de n valores
      ((Dados_t2 *)input)->Running2 = 0; // definir flag a 0

    pthread_mutex_unlock(&mutex_Lux);

    FLAG_Lux = 1; // sinalizar que acabou o thread no momento
    pthread_cond_signal(&condVar_Lux); // enviar o sinal para o thread 1.3
  }
  return NULL;
}

void *ThreadMedia_Lux(void *input) {

  while (1) {
    pthread_mutex_lock(&mutex_Lux);
    while (FLAG_Lux == 0) { // enquanto a flag for 0, ele espera pelo thread
      // esperando pelo thread
      pthread_cond_wait(&condVar_Lux, &mutex_Lux);
    } // Sendo 1, deixa de esperar e executa o thread 1.3
    // Executar o thread 1.3
    fflush(stdout);
    printf("Teste, teste, Sou o processso 2.3\n");
    // cálculo da média:
    printf("tamanho do array: %d\n", ArrSize_Lux);

    // float media2 = (float)(((Dados_t *)input)->soma_Temperatura) +
    // FIFO_Lux[0] / (float)ArrSize;

    printf("Media da memoria: %.2f\n", (((Dados_t2 *)input)->media_Lux));
    // printf("Media calculada localmente(teste): %.2f\n", media2);
    // int estado;
    // if ((((Dados_t2 *)input)->media_Lux) < 30)
    //   estado = 0;
    // else
    //   estado = 1;
    // controla_AC(estado);
    printf("\n");
    printf("---------x----------\n");

    if (Contador_Lux < 50) // Definir antes do lock flag 1
      FLAG_Lux = 0;
    else if (Contador_Lux == 50) // Senao 1, para quando voltar acima e descer
                                 // nao fazer condition wait
      return NULL;
    
    
    // printf("Teste, teste, Sou o processso 1.3");
    pthread_mutex_unlock(&mutex_Lux);
  }
  // return NULL;
}
