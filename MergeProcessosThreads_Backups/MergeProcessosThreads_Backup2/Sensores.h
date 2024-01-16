#include "string.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// Coisas do processo filho 1:
#define TAM 10
#define TAM_Lux 20

extern struct timespec ts;
extern int FIFO[TAM];
extern pthread_mutex_t mutex;
extern int Contador;
extern int FLAG;
extern pthread_cond_t condVar;
extern int ArrSize;

typedef struct Dados {
  int Running, Running2;
  int soma_Temperatura;
  float media;
  // int ArrSize;
} Dados_t;

// Threads do processo 1
void *Sensor1(void *input);
void *Sensor2(void *input);
void *ThreadMedia(void *input);
void controla_AC(int estado);

// Coisas do processo filho 2:
extern struct timespec ts_Lux;
extern int FIFO_Lux[TAM_Lux];
extern pthread_mutex_t mutex_Lux;
extern int Contador_Lux;
extern int FLAG_Lux;
extern pthread_cond_t condVar_Lux;
extern int ArrSize_Lux;

typedef struct Dados2 {
  int Running, Running2;
  int soma_Lux;
  float media_Lux;
  // int ArrSize;
} Dados_t2;

// Threads do processo 1
void *Sensor1_Lux(void *input);
void *Sensor2_Lux(void *input);
void *ThreadMedia_Lux(void *input);