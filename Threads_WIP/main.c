#include "string.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define TAM 10

typedef struct Dados {
  int array[TAM];
  int ArrSize;
} Dados_t;

void *PercorreArray(void *input) {
  int i;
  // int ArraySize = (Dados_t*)input->ArrSize;
  // printf("%d", )

  // (((Dados_t*)input)->ArrSize)
  for (i = 0; i < (((Dados_t *)input)->ArrSize); i++)
    printf("%d|[%d]", i,
           ((Dados_t *)input)->array[i]); // i representa a posicao no array
  // array[i] representa o valor na posicao

  pthread_exit(NULL);
}

// void *teste(void *insert) {
//   printf("teste\n");
//   printf("idade: %d\n", ((Dados_t *)insert)->idade);
// }

int main(void) {
  // Dados_t *dados = (Dados_t *)malloc(sizeof(Dados_t));

  Dados_t *alocDados = (Dados_t *)malloc(
      sizeof(Dados_t) *
      10); // alocacao dinamica, sizeof()*10 para alocar 10x mais
  int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  pthread_t th; // criar o thread

  int ArrSize = sizeof(array) / sizeof(int);
  alocDados->ArrSize = ArrSize;

  for (int i = 0; i < ArrSize; i++) {
    alocDados->array[i] = array[i];
  }
  if (pthread_create(&th, NULL, PercorreArray, (void *)alocDados) != 0)
    return 1;

  if (pthread_join(th, NULL))
    return 2;

  free(alocDados);
  return 0;
}
