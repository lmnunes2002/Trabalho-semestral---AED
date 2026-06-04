#ifndef FILA_JOGADOR_H
#define FILA_JOGADOR_H

#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"

// Apelido tp_item_fila
typedef tp_jogador tp_item_fila;

typedef struct tp_no_fila{
    tp_item_fila info;
    struct tp_no_fila *prox;
} tp_no_fila;

typedef struct {
    tp_no_fila *ini, *fim;
} tp_fila;

// Inicializa a fila (Aloca a estrutura da fila)
static tp_fila *inicializa_fila() {
    tp_fila *f = (tp_fila*) malloc(sizeof(tp_fila));
    if (f) f->ini = f->fim = NULL;
    return f;
}

static tp_no_fila *alocea_no_fila(){
    tp_no_fila *pt;
    pt = (tp_no_fila*) malloc (sizeof(tp_no_fila));
    return pt;
}

static int fila_vazia(tp_fila *f) {
    if (f->ini == NULL) return 1;
    return 0;
}

static int fila_cheia(tp_fila *f){
    tp_no_fila *teste;
    teste=(tp_no_fila*) malloc (sizeof(tp_no_fila));
    
    // Não conseguiu alocar memória.
    if (teste == NULL){
        return 1;
    }
    
    // Desaloca o nó de teste;
    free(teste);
    return 0;
}

// Enfileirar (Push back)
static int enfila(tp_fila *f, tp_item_fila e) {
    if (fila_cheia(f)) return 0;
    
    tp_no_fila *novo_no = alocea_no_fila();
    
    if (!novo_no) return 0;

    novo_no->info = e;
    novo_no->prox = NULL;

    if (fila_vazia(f)) {
        f->ini = novo_no;
    } else {
        f->fim->prox = novo_no;
    }
    f->fim = novo_no;
    return 1;
}

// Desenfileirar (Pop front)
static int desenfila(tp_fila *f, tp_item_fila *e) {
    if (fila_vazia(f)) return 0;

    tp_no_fila *aux;
    *e = f->ini->info;
    aux = f->ini;

    // f->ini = f->ini->prox;
    if (f->ini == f->fim)
        f->fim = f->fim = NULL;
    else
        f->ini=f->ini->prox;

    free(aux);
    return 1;
}

// Imprime sem destruir (Percorrendo os ponteiros)
static void print_fila(tp_fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    tp_no_fila *aux = f->ini;
    printf("\n Fila de Jogadores \n");
    while (aux != NULL) {
        printf("ID: %d | Nome: %s | Pos: %d\n", aux->info.id, aux->info.nome, aux->info.pos);
        aux = aux->prox;
    }
}

// Lógica de turno (Vez do Jogador)
static void vez_jogador(tp_fila *f) {
    tp_item_fila jogador_atual;

    if (desenfila(f, &jogador_atual)) {
        int dado = (rand() % 6 + 1);
        jogador_atual.pos += dado;

        printf("\n Jogador %s tirou %d no dado.", jogador_atual.nome, dado);

        if (jogador_atual.pos >= 72) {
            printf("\nPARABENS %s, VOCE GANHOU!\n", jogador_atual.nome);
        } else {
            printf("\nNova posicao de %s: %d\n", jogador_atual.nome, jogador_atual.pos);
        }

        // Reenfileira para o final (Garante o ciclo infinito de turnos)
        enfila(f, jogador_atual);
    }
}

// Libera toda a memória da fila
static void destroi_fila(tp_fila *f) {
    tp_item_fila e;
    while (!fila_vazia(f))
        desenfila(f, &e); 
    free(f); 
}

#endif