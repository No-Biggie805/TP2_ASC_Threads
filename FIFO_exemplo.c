// versao certa
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //necessário p/ função time()

#define TAM 10
int FIFO[TAM];
float soma = 0;
float media;
int contador;
float sizeFIFO = sizeof(FIFO) / sizeof(FIFO[0]);
void EscreverFIFO(int Running) {
  int i, j;

  while (Running) {
    // for (i = 0; i < 20; i++) { // iterar umas 20 vezes ja que havera valores
    // a ser removidos
    i = i + 1;
    int random = rand() % (35 - 25 + 1) + 25;
    
    for (j = 0; j < TAM - 1; j++)
      FIFO[j] = FIFO[j + 1];
    FIFO[TAM - 1] = random;
    printf("Novo Valor Adicionado,%d\n", random);
    
    soma += FIFO[TAM - 1];
    
    for (j = 0; j < TAM; j++) {
      if (j == 0)
        printf("[%d", FIFO[j]);
      else if (j == TAM - 1)
        printf("|%d]\n", FIFO[j]);
      else
        printf("|%d", FIFO[j]);
    }
    contador += 1;
    printf("soma: %.2f\n", soma);

    // for (j = 0; j < TAM - 1; j++){
    //   // if( j >= sizeFIFO)
    //    FIFO[j] = FIFO[j + 1];
    // }


    media = soma / sizeFIFO;
    printf("Media: %.2f\n", media);
    
    soma -= FIFO[0];
    
    
    
    if (i == 20)
      Running = 0;
  }
}

int main() {
  int i;
  int Running = 1;
  EscreverFIFO(Running);

  return 0;
}

// #include<stdio.h>

// #define N 5

// int main()
// {
//     int a[N], i, temp, pos, dir;

//     printf("Enter %d integer numbers\n", N);
//     for(i = 0; i < N; i++)
//         scanf("%d", &a[i]);

//     printf("Enter the number of positions to shift\n");
//     scanf("%d", &pos);

//     printf("Enter the direction of shifting ...\n");
//     printf("LEFT: 1 and RIGHT: 0\n");
//     scanf("%d", &dir);

//     while(pos)
//     {
//         if(dir)
//         {
//             temp = a[0];
//             for(i = 0; i < N - 1; i++)
//                 a[i] = a[i + 1];

//             a[N - 1] = temp;
//         }
//         else
//         {
//             temp = a[N - 1];
//             for(i = N - 1; i > 0; i--)
//                 a[i] = a[i - 1];

//             a[0] = temp;
//         }

//         pos--;
//     }

//     printf("Array after shift operation ...\n");
//     for(i = 0; i < N; i++)
//         printf("%d\n", a[i]);

//     printf("\n");

//     return 0;
// }
