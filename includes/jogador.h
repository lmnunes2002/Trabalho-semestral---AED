#ifndef JOGADOR_H
#define JOGADOR_H

#include <string.h>

typedef struct {
    int id;
    int pos;
    char nome[30];
    int pontuacao;
} tp_jogador;

// Inicializa jogador com pos e pontuacao 0
void init_jogador (tp_jogador *jogador, char *txt){
    jogador->pos = 0;
    jogador->pontuacao = 0;

    // Copia a string txt para a struct jogador.
    strcpy(jogador->nome, txt);
}

#endif