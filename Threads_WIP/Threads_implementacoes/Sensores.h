#include "string.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define TAM 10

extern struct timespec ts;
extern int array[TAM];
extern pthread_mutex_t mutex;

typedef struct Dados {
  int Running;
  // int ArrSize;
} Dados_t;

void *Sensor1(void *input);
void *Sensor2(void *input);
