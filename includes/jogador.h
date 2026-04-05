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
void init_jogador(tp_jogador *jogador){
    jogador->pos = 0;
    jogador->pontuacao = 0;
    jogador->id = 0;
}

//função para alterar/adicionar um nome ao jogador
void mudar_nome(tp_jogador *jogador, char novo_nome[]){
    strcpy(jogador->nome, novo_nome);
}

//mostra os jogadores que foram registrados
void apresentar_nome(tp_jogador *jogador){
    for(int i = 0; jogador[i].id == 0; i++){
        if(jogador[i].id == 0) printf("Nome do jogador %d: %s\n", i + 1, jogador[i].nome);
    }
}

#endif