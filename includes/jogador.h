#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    int id;
    int pos;
    char nome[30];
    int pontuacao;
} tp_jogador;

void init_jogador (tp_jogador *jogador){
    jogador->pos = 0;
    jogador->pontuacao = 0;
}

#endif