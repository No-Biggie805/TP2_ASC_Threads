// /*Codigo processo filho 1, controlo de temperatura
// Consideracoes a ter:

// 1- Devera existir enquanto tiver threads em execucao
// 2- Possui um buffer, ou variavel global capaz de armazenar 10 valores de temperatura, e devera funcionar cm um FIFO armazenando os 10 mais recentes
// 3- Explicar que cada thread fara:
//     Thread 1.1: Recolher dados do sensor de temperatura #1, a cada 5s, armazena info no buffer, fechar no fim de 20 execucoes
//     Thread 1.2: Recolher dados do sensor de temperatura #2, a cada 5s,  armazena info no buffer, fechar no fim de 30 execucoes
//     Thread 1.3: Tomar decisoes com base nos dados de temp.(On/OFF), devera aguardar ate que um novo valor seja armazenado no buffer p/th1.1 ou 1.2.
// Para isso calcula a media dos 10 vals de temp., com base nos dados no buffer, a tomada de decisao sera por base do valor da media, encerramento assim que fecha th1.1 e th1.2
// */

// #include "temp.h"

// // funcao vai inserir os valores da temperatura no array da temperatura
// void StoreTemperatura(int TempVal)
// {
//     int i;

//     for (i = 0; i <= arr_temperatura[i]; i++)
//     {
//         arr_temperatura[i] = arr_temperatura[i] + TempVal;
        
//     }
// }