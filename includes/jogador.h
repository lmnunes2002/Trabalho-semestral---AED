#ifndef JOGADOR_H
#define JOGADOR_H
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "fila_jogador.h"

//estrutura abstrata dos jogadores
typedef struct {
    int id;
    int pos;
    char nome[30];
    int pontuacao;
}tp_jogador;

//inicializa os jogadores, sendo obviamente, suas posições: iniciais, e com 0 pontos
void init_jogador(tp_jogador *jogador, int cod){
    jogador->pos = 0;
    jogador->pontuacao = 0;
    jogador->id = cod;
}

//função para alterar/adicionar um nome ao jogador
void mudar_nome(tp_jogador *jogador, char novo_nome[]){
    strcpy(jogador->nome, novo_nome);
}

void apresentar(tp_jogador *jogadores[]){
    for(int i = 0; i < 4; i++){
        if(strlen(jogadores[i]->nome) == 0) break;
        else printf("Jogador %d: %s\n", i + 1, jogadores[i]->nome);
    }
}
#endif