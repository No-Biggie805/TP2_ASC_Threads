/*
Fazer processo principal;
fazer processo filho 1, filho 2

Simulacao de leitura de dados realistas dos sensores de temperatura ee luminosidade, pode recorrer ao rand();
Aplicar logicas especificas de threads, para cada thread, baseadass nos valores dos sensores

*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// #include "temp.h"

// // int arr_temperatura[TAM];

// //

// #define BUFFER 10
// typedef struct temp
// {
//     int arr_temperatura[BUFFER];

// } temp_t;
// void PrintTemperaturas(temp_t *arrayVal);

// int main()
// {
//     int TempVal[] = {20, 22, 18, 35, 48, 26, 87, 70};

//     temp_t array;
    
//     // ver tammanho do nosso array local
//     int length = sizeof(TempVal) / sizeof(TempVal[0]);

//     // StoreTemperatura(TempVal);

//     for (int i = 0; i < length; i++)
//     {
//         array.arr_temperatura[i] = TempVal[i];
//     }

//     printf("Printing array \n");
//     PrintTemperaturas(&array);

//     return 0;
// }


// void PrintTemperaturas(temp_t *arrayVal)
// {
//     int i;
//     int Array_size = sizeof(arrayVal->arr_temperatura) / sizeof(arrayVal->arr_temperatura[0]);
//     for (i = 0; i <= Array_size; i++)
//     {
//         printf("%d\n", arrayVal->arr_temperatura[i]);
//     }
// }


int main()
{
    // int random;
    srand(time(NULL)); // seed // time elapsed since 1970 january 1

    int Running = 1;

    while (Running == 1)
    {
        
        int random = rand() % 40; //%2 define entre [0,1] se meter 10 será [0,9]
        printf("%d\n", random);
        sleep(1);

        char input[10];
        if (fgets(input, sizeof(input), stdin) == NULL) //if input is null, exit
        {
            if (strcmp(input, "0") == 0) // compares input to "0" string, if equal set Running to 0 to exit loop
                printf("%s", input);
                Running = 0; // exit while loop
        }
        return 0; 
    }
}