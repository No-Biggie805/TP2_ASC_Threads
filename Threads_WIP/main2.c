// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//   int *array;
//   int ArrSize;
// } Dados_t;

// void *PercorreArray(void *input) {
//   int i;
//   for (i = 0; i < ((Dados_t *)input)->ArrSize; i++)
//     printf("%d|[%d]", i, ((Dados_t *)input)->array[i]);
//   pthread_exit(NULL);
// }

// int main(void) {
//   int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//   int ArrSize = sizeof(array) / sizeof(int);

//   // Allocate memory for the struct
//   Dados_t *dados = (Dados_t *)malloc(sizeof(Dados_t));

//   // Populate the struct with data
//   // dados->array = array;

//   for (int i = 0; i < ArrSize; i++) {
//      dados->array = array;
//    }

//   dados->ArrSize = ArrSize;

//   // Create a thread and pass the struct as an argument
//   pthread_t thread;
//   pthread_create(&thread, NULL, PercorreArray, (void *)dados);

//   // Wait for the thread to finish
//   pthread_join(thread, NULL);

//   // Free the allocated memory
//   free(dados);

//   return 0;
// }
