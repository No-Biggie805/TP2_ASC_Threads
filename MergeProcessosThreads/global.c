/*Este ficheiro Contem Variaveis globais*/

#include "Sensores.h"

struct timespec ts;
int FIFO[TAM];
pthread_mutex_t mutex;
int Contador, FLAG;
pthread_cond_t condVar;