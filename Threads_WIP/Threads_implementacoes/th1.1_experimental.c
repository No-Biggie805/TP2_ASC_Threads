
#include "Sensores.h"

int main(int argc, char *argv[]) {

  srand(time(NULL));
  Dados_t *getDados =
      (Dados_t *)malloc(sizeof(Dados_t) * 10); // alocacao dinamica

  // create thread
  pthread_t th1_1;

  int Running = 1;
  getDados->Running = Running;
  // int ArrSize = sizeof(array) / sizeof(int);
  // getDados->ArrSize = ArrSize;
  
  if (pthread_create(&th1_1, NULL, Sensor1, (void *)getDados) != 0)
    return 1;

  // Wait for the user input thread to finish
  if (pthread_join(th1_1, NULL) != 0)
    return 2;

  return 0;
}
