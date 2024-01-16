/*Este ficheiro Contem Variaveis globais*/

#include "Sensores.h"

//Coisas do Processo filho 1:
struct timespec ts;
int FIFO[TAM];
pthread_mutex_t mutex;
int Contador, FLAG;
pthread_cond_t condVar;
int ArrSize;

//Coisas do Processo filho 2:
struct timespec ts_Lux;
int FIFO_Lux[TAM_Lux];
pthread_mutex_t mutex_Lux;
int Contador_Lux, FLAG_Lux;
pthread_cond_t condVar_Lux;
int ArrSizeLux;

void controla_AC(int estado){
  if(estado == 0)
    printf("AC [OFF]");
  else
    printf("AC [ON]");
}