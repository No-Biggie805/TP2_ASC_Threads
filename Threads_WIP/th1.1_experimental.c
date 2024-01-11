#include "string.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define TAM 10
struct timespec ts;
int array[TAM];

typedef struct Dados {
  int Running;
} Dados_t;

//esta funcao tem como objectivo simular um sensor de temperatura..
void *Sensor1(void *input) 
{
  ts.tv_sec = 1;
  ts.tv_nsec = 0;
  int i = 0;

  while (((Dados_t*)input)->Running)
  {
      i = i+1;
      int random = rand() % 40;
      array[i] = random;
      printf("%u\t, %d\n", random,array[i]);
      nanosleep(&ts, NULL);
      
  if(i == 10) //fazer condiçao se passar de n valores
  ((Dados_t*)input)->Running = 0;
  }  
  return NULL;
}

int main(int argc, char *argv[]) {
  
  srand(time(NULL));
  Dados_t *getDados = (Dados_t *)malloc(sizeof(Dados_t) * 10); // alocacao dinamica

  // create thread
  pthread_t th1_1;

  int Running = 1;
  getDados->Running = Running;
  if (pthread_create(&th1_1, NULL, Sensor1, (void *)getDados) != 0)
    return 1;

  // Wait for the user input thread to finish
  if(pthread_join(th1_1, NULL) != 0) return 2;
  
  return 0;
}
