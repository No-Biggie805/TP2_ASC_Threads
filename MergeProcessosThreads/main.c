#include "Sensores.h"

int main(int argc, char *argv[]) {
  // Inicio dos Processos
  int pid1, pid2; // Identificador do processo

  srand(time(NULL));
  Dados_t *getDados =
      (Dados_t *)malloc(sizeof(Dados_t) * 10); // alocacao dinamica
  pid1 = fork();                               // Processo 1
  if (pid1 < 0)                                // Se o fork() retornou erro
  {
    perror(" Error: ");
    return -1;
  }
  if (pid1 == 0) // if in child1 process
  {
    printf(" Hello from child1\t\n");
    // create thread
    pthread_t th1_1, th1_2, th1_3;
    int Running = 1;
    getDados->Running = Running;
    getDados->Running2 = Running; // guarda o valor inteiro do main lel
    // int ArrSize = sizeof(array) / sizeof(int);
    // getDados->ArrSize = ArrSize;

    // parte de inicializacao dinamica dos mutexes
    pthread_mutex_init(&mutex, NULL); // inicializar o mutex normal
    pthread_cond_init(&condVar,
                      NULL); // inicializar condition waits para os mutexes

    if (pthread_create(&th1_1, NULL, Sensor1, (void *)getDados) != 0)
      return 1;
    if (pthread_create(&th1_2, NULL, Sensor2, (void *)getDados) != 0)
      return 2;
    if (pthread_create(&th1_3, NULL, ThreadMedia, (void *)getDados) != 0)
      return 5;

    if (pthread_join(th1_1, NULL) != 0)
      return 3;
    if (pthread_join(th1_2, NULL) != 0)
      return 4;
    if (pthread_join(th1_3, NULL) != 0)
      return 6;

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condVar);
    printf("\nmorreu o child1\n");
    exit(0);
  } else { // PARENT
    pid2 = fork();
    if (pid2 < 0) // Se o fork() retornou erro
    {
      perror(" Error: ");
      return -1;
    }

    if (pid2 == 0) {
      printf(" Hello from child2\t\n");


      
      printf("\nmorreu o child2\n");
      
      exit(0); //exit tem de tar aqui e implementar tudo antes do mesmo!!!!
    }
    // Pai esperar pelos dois filhos e terminar o programa.
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    printf(" hello from parent \n ");
    printf(" child1: %d\t\t child2: %d\n", pid1, pid2);
    printf(" Exit \n");
  }
  // printf("Exit\n");
  return 0;
}

