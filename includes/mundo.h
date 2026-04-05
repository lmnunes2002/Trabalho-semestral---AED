#ifndef MUNDO_H
#define MUNDO_H
#include <stdio.h>
#include "jogador.h"

//função que cadastra os jogadores, dando início ao jogo
void init_mundo(tp_jogador *jogadores[], tp_fila *jogadas){
    int n;
    printf("Registre a quantidade de jogadores (entre 2 e 4): ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        //Nome dentro do for para que a cada laço, a string seja limpada
        char nome[30];
        init_jogador(&jogadores[i]);
        printf("Digite um nome de até 30 caracteres para o jogador %d: ", i + 1);
        scanf(" %[^\n]", nome);
        mudar_nome(&jogadores[i], nome);
    }

}

#endif