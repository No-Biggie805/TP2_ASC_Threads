
#include "Sensores.h"

int main(int argc, char *argv[]) {

  srand(time(NULL));
  Dados_t *getDados =
      (Dados_t *)malloc(sizeof(Dados_t) * 10); // alocacao dinamica

  // create thread
  pthread_t th1_1, th1_2;

  int Running = 1;
  getDados->Running = Running;
  // int ArrSize = sizeof(array) / sizeof(int);
  // getDados->ArrSize = ArrSize;

  pthread_mutex_init (&mutex, NULL);
  
  if (pthread_create(&th1_1, NULL, Sensor1, (void *)getDados) != 0)
    return 1;
  if (pthread_create(&th1_2, NULL, Sensor2, (void *)getDados) != 0)
    return 2;

  if (pthread_join(th1_1, NULL) != 0)
    return 3;
  if (pthread_join(th1_2, NULL) != 0)
    return 4;
  
  pthread_mutex_destroy (&mutex);

  printf("Exit\n");
  return 0;
}
