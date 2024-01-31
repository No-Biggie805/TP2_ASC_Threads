#include "Sensores.h"

// esta funcao tem como objectivo simular um sensor de temperatura.. Sensor 1 de
// temperatura
void *Sensor1(void *input) {
  ArrSize = sizeof(FIFO) / sizeof(FIFO[0]);
  FLAG = 0;
  ts.tv_sec =
      1; // tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0; // Tempo em nsegundos
  int i = 0, j;

  while (((Dados_t *)input)->Running) {
    // fazer o mutex na funcao, possivel ter de mudar!!
    nanosleep(&ts, NULL);
    
    pthread_mutex_lock(&mutex);
    fflush(stdout);
    i = i + 1;
    printf("Thread 1.1:\n");

    int random = rand() % (35 - 25 + 1) + 25;

    for (j = 0; j < TAM - 1; j++)
      FIFO[j] = FIFO[j + 1];
    FIFO[TAM - 1] = random;

    ((Dados_t *)input)->soma_Temperatura += FIFO[TAM - 1];

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
    printf("soma: %d\n", ((Dados_t *)input)->soma_Temperatura);
    (((Dados_t *)input)->media) =
        (float)(((Dados_t *)input)->soma_Temperatura) / (float)ArrSize;

    // for (j = 0; j < TAM; j++)
    //   ((Dados_t *)input)->soma_Temperatura +=
    //       FIFO[j]; // adicionar valor à memória da soma

    ((Dados_t *)input)->soma_Temperatura -= FIFO[0];

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
  ArrSize = sizeof(FIFO) / sizeof(FIFO[0]);

  // while (FLAG == 1) { // enquanto a flag for 0, ele espera pelo thread
  //   // esperando pelo thread
  //   pthread_cond_wait(&condVar, &mutex);
  // }
  FLAG = 0;
  ts.tv_sec =
      1; // tempo em segundos, mudar para 5, defenir 5s por cada intervalo
  ts.tv_nsec = 0; // Tempo em nsegundos
  int i = 0, j;

  // int random = (rand() %
  //   (upper - lower + 1)) + lower;

  while (((Dados_t *)input)->Running2) {
       
    nanosleep(&ts, NULL);
    
    pthread_mutex_lock(&mutex);
    fflush(stdout);

    i = i + 1;
    printf("Thread 1.2:\n");

    int random = rand() % (35 - 25 + 1) + 25;

    for (j = 0; j < TAM - 1; j++)
      FIFO[j] = FIFO[j + 1];
    FIFO[TAM - 1] = random;
    ((Dados_t *)input)->soma_Temperatura += FIFO[TAM - 1];

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
    printf("soma: %d\n", ((Dados_t *)input)->soma_Temperatura);

    (((Dados_t *)input)->media) =
        (float)(((Dados_t *)input)->soma_Temperatura) / (float)ArrSize;

    // for (j = 0; j < TAM - 1; j++)
    //   ((Dados_t *)input)->soma_Temperatura +=
    //       FIFO[j]; // adicionar valor à memória da soma


    
    ((Dados_t *)input)->soma_Temperatura -= FIFO[0]; //Problematico por causa do thread media..

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
int Ativado = 1;
  while (Ativado) {
    pthread_mutex_lock(&mutex);
    while (FLAG == 0) { // enquanto a flag for 0, ele espera pelo thread
      // esperando pelo thread
      pthread_cond_wait(&condVar, &mutex);
    } // Sendo 1, deixa de esperar e executa o thread 1.3
    // Executar o thread 1.3
    fflush(stdout);
    printf("Teste, teste, Sou o processso 1.3\n");
    // cálculo da média:
    printf("tamanho do array: %d\n", ArrSize);

    // float media2 = (float)(((Dados_t *)input)->soma_Temperatura) + FIFO[0] /
    // (float)ArrSize;

    printf("Media da memoria: %.2f\n", (((Dados_t *)input)->media));
    // printf("Media calculada localmente(teste): %.2f\n", media2);

    int estado;
    if ((((Dados_t *)input)->media) < 30)
      estado = 0;
    else
      estado = 1;

    controla_AC(estado);
    printf("\n");
    printf("---------x----------\n");

    if (Contador < 50) // Definir antes do lock flag 1
      FLAG = 0;
    else if (Contador == 50){ // Senao 1, para quando voltar acima e descer nao
                             // fazer condition wait
      FLAG = 1;
      Ativado = 0;
    
    }
    // fflush(stdout);
    
    // printf("Teste, teste, Sou o processso 1.3");
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}
