#ifndef FILA_JOGADOR_H
#define FILA_JOGADOR_H

#include <stdio.h>
#include "jogador.h"

// Apelido tp_item para ser usado na fila
typedef tp_jogador tp_item;

// MAX = 4 jogadores + 1 posição de sacrifício
#define MAX 5 

typedef struct {
    int ini, fim;
    tp_item item[MAX]; 
} tp_fila;

// Inicializa a fila
void inicializa_fila(tp_fila *f) {
    f->ini = f->fim = MAX - 1;
}

int fila_vazia(tp_fila *f) {
    return (f->ini == f->fim);
}

int proximo(int pos) {
    if (pos == MAX - 1) return 0;
    return ++pos;
}

int fila_cheia(tp_fila *f) {
    return (proximo(f->fim) == f->ini);
}

// Enfileirar (aceita tp_item, que é um jogador)
int enfila(tp_fila *f, tp_item e) {
    if (fila_cheia(f)) return 0;
    f->fim = proximo(f->fim);
    f->item[f->fim] = e;
    return 1;
}

// Desenfileirar (retira um tp_item)
int desenfila(tp_fila *f, tp_item *e) {
    if (fila_vazia(f)) return 0;
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    return 1;
}

// Exibe os jogadores (acessando os campos da struct via tp_item)
void print_fila(tp_fila f) {
    tp_item e;
    printf("\n--- Fila de Jogadores ---\n");
    while (desenfila(&f, &e)) {
        printf("ID: %d | Nome: %s\n", e.id, e.nome);
    }
}

// Funções do jogador (provavel refatoracao).
// A funcao recebe uma fila de jogadores preenchida.
void vez_jogador(tp_fila *f){
    tp_jogador jogador_atual;

    // Logica de desenfilar o jogador para rolar o dado
    if(desenfila(f, &jogador_atual)){
        // A funcao rand gera numeros a partir do 0.
        int dado = (rand() % 6 + 1);
        // Incrementa a posicao do jogador.
        // Passamos a pos[0]
        jogador_atual.pos += dado;

        if (jogador_atual.pos >= 72) 
            printf("\nParabens jogador: %s, voce ganhou!", jogador_atual.nome);
        else
            printf("\nNova posicao: %d", jogador_atual.pos);

        printf("\nJogador %s tirou %d no dado.", jogador_atual.nome, dado);
    }

    // Reenfila o jogador no final da fila.
    enfila(f, jogador_atual);
}

#endif