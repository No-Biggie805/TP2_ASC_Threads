/*Codigo processo filho 1, controlo de temperatura

1- Devera existir enquanto tiver threads em execucao
2- Possui um buffer, ou variavel global capaz de armazenar 10 valores de lux(intensidade luminosa), e devera funcionar cm um FIFO armazenando os 20 mais recentes, lanca depois 3threads
3- Explicar que cada thread fara:
    Thread 2.1: Recolher dados do sensor de luminosidade #1, a cada 10s, armazena info no buffer, fechar no fim de 20 execucoes
    Thread 2.2: Recolher dados do sensor de luminosidade #2, a cada 10s,  armazena info no buffer, fechar no fim de 30 execucoes
    Thread 2.3: Tomar decisoes com base nos dados de temp.(On/OFF), devera aguardar ate que um novo valor seja armazenado no buffer p/th1.1 ou 1.2. 
Para isso calcula a media dos 10 vals de temp., com base nos dados no buffer, a tomada de decisao sera por base do valor da media, encerramento assim que fecha th1.1 e th1.2
*/