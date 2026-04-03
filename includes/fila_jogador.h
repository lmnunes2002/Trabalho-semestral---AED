#ifndef FILA_JOGADOR_H
#define FILA_JOGADOR_H

#include <stdio.h>
#include "jogador.h"
#include "tabuleiro.h"

typedef tp_jogador tp_item;         // Apelido tp_item para ser usado na fila

#define MAX 5                       // MAX = 4 jogadores + 1 posição de sacrifício

typedef struct {
    int ini, fim;
    tp_item item[MAX]; 
} tp_fila;

void inicializa_fila(tp_fila *f) {          // Inicializa a fila
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

int enfila(tp_fila *f, tp_item e) {         // Enfileirar (aceita tp_item, que é um jogador)
    if (fila_cheia(f)) return 0;
    f->fim = proximo(f->fim);
    f->item[f->fim] = e;
    return 1;
}

int desenfila(tp_fila *f, tp_item *e) {     // Desenfileirar (retira um tp_item) 
    if (fila_vazia(f)) return 0;
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    return 1;
}

void print_fila(tp_fila f) {                // Exibe os jogadores (acessando os campos da struct via tp_item)
    tp_item e;
    printf("\n--- Fila de Jogadores ---\n");
    while (desenfila(&f, &e)) {
        printf("ID: %d | Nome: %s\n", e.id, e.nome);
    }
}

void vez_jogador(tp_fila *f){               // A funcao recebe uma fila de jogadores preenchida.
    tp_jogador jogador_atual;

    if(desenfila(f, &jogador_atual)){       // Logica de desenfilar o jogador para rolar o dado
        int dado = (rand() % 6 + 1);        // A funcao rand gera numeros a partir do 0.
        jogador_atual.pos += dado;          // Incrementa a posicao do jogador, passamos a pos.

        if (verificar_casa(&jogador_atual) == CASA_QUIZ){       // Verifica se e uma casa de pergunta.
            printf("\n%s, prepare-se para responder: ", jogador_atual.nome);
            // Chamada de funcao de pergunta a ser implementada.
        }

        if (jogador_atual.pos >= 57) printf("\nParabens jogador: %s, voce ganhou!", jogador_atual.nome);
        else printf("\nNova posicao: %d", jogador_atual.pos);

        printf("\nJogador %s tirou %d no dado.", jogador_atual.nome, dado);
    }

    enfila(f, jogador_atual);               // Reenfila o jogador no final da fila.
}

#endif