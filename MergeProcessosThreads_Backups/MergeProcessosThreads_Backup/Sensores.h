#include "string.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

//Coisas do processo filho 1:
#define TAM 10

extern struct timespec ts;
extern int FIFO[TAM];
extern pthread_mutex_t mutex;
extern int Contador;
extern int FLAG;
extern pthread_cond_t condVar;

typedef struct Dados {
  int Running, Running2;
  // int ArrSize;
} Dados_t;

//Threads do processo 1
void *Sensor1(void *input);
void *Sensor2(void *input);
void *ThreadMedia(void *input);


//Coisas do processo filho 2: