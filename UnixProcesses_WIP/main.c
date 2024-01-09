/*
Fazer processo principal;
fazer processo filho 1, filho 2

Simulacao de leitura de dados realistas dos sensores de temperatura ee luminosidade, pode recorrer ao rand();
Aplicar logicas especificas de threads, para cada thread, baseadass nos valores dos sensores

*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int generateRandomNumbers(pthread_t userInputThread, int Running);
void *getUserInput(int Running);

int main(int argc, char *argv[])
{
  // Parte de gerar numeros:
  pthread_t userInputThread; // valor do tipo pthread_t, da libraria pthread!!
  int Running = 1;

  int res = generateRandomNumbers(userInputThread, Running);

  if (res == 0)
    // Wait for the user input thread to finish
    pthread_join(userInputThread, NULL);
  // Fim de gerador de numeros.

  // Inicio dos Processos
  //  int pid1, pid2; // Identificador do processo

  // pid1 = fork(); // Processo 1

  // int getPid1 = 0, getPid2 = 0;
  // if (pid1 < 0) // Se o fork() retornou erro
  // {
  //   perror(" Error: ");
  //   return -1;
  // }

  // if (pid1 == 0) // if in child1 process
  // {
  //   getPid1 = getpid();
  //   printf(" Hello from child1\t");
  //   printf("getPid1: %d\n", getPid1);
  //   exit(0);
  // }
  // else // PARENT
  // {
  //   pid2 = fork();
  //   if (pid2 < 0) // Se o fork() retornou erro
  //   {
  //     perror(" Error: ");
  //     return -1;
  //   }
  //   if (pid2 == 0)
  //   {
  //     getPid2 = getpid();
  //     printf(" Hello from child2\t");
  //     printf("getPid2: %d\n", getPid2);
  //     exit(0);
  //   }
  //   //   int getPid = getppid ();
  //   waitpid(pid1, NULL, 0);
  //   waitpid(pid2, NULL, 0);
  //   printf(" hello from parent \n ");
  //   printf(" child1: %d\t\t child2: %d\n", pid1, pid2);
  //   printf(" Exit \n");
  // }
  return 0;
}

int generateRandomNumbers(pthread_t userInputThread, int Running)
{
  struct timespec ts;

  // Parte de gerar numeros:
  ts.tv_sec = 1;
  ts.tv_nsec = 0;

  srand(time(NULL));

  // Create a thread for user input
  // pthread_t userInputThread;                                                    // valor do tipo pthread_t, da libraria pthread!!
  if (pthread_create(&userInputThread, NULL, getUserInput(Running), NULL) != 0) // if the pthread_create() function returns 0, the thread was created successfully,
  {                                                                             // otherwise, an error occurred
    fprintf(stderr, "Error creating thread\n");
    return 1;
  }

  while (Running) // If the user writes, 'q' on the string, the getUserInput function will proceed and the Running flag will be set to 0
  {
    int random = rand() % 40;
    printf("%d\n", random);
    nanosleep(&ts, NULL);
  }

  return 0;
}


void *getUserInput(int Running)
{
  char input[10];
  while (Running)
  {
    if (fgets(input, sizeof(input), stdin) != NULL) // fgets(char *s, int size, FILE *stream), tem a stream de informacao(tamanho sera da palavra, no caso "q"), o tamanho dessa informacao, e o apontador para a stream
                                                    // Se o fgets da informacao for diferente de NULL, inicia a comparacao e se for igual a "q", o programa ativa a flag de saida
    {
      if (strcmp(input, "q\n") == 0)
        Running = 0;
    }
  }
  return NULL; // return argument, as getUserInput()
}