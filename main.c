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

// int arr_temperatura[TAM];

//

#define BUFFER 10
typedef struct temp
{
    int arr_temperatura[BUFFER];

} temp_t;
void PrintTemperaturas(temp_t *arrayVal);

int main()
{
    int TempVal[] = {20, 22, 18, 35, 48, 26, 87, 70};

    temp_t array;
    
    // ver tammanho do nosso array local
    int length = sizeof(TempVal) / sizeof(TempVal[0]);

    // StoreTemperatura(TempVal);

    for (int i = 0; i < length; i++)
    {
        array.arr_temperatura[i] = TempVal[i];
    }

    printf("Printing array \n");
    PrintTemperaturas(&array);

    return 0;
}


