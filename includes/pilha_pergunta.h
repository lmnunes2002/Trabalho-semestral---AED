#ifndef PILHA_H
#define PILHA_H
#define MAX_PILHA 10

#include <stdio.h>
#include "pergunta.h"

typedef tp_pergunta tp_item_pilha;

typedef struct{
    int topo;
    tp_item_pilha item[MAX_PILHA];
} tp_pilha;

void inicializa_pilha(tp_pilha *p){
    p->topo = -1;
}

// Funções de verificação, importantes para o uso da pilha.
int pilha_vazia(tp_pilha *p){
    if (p->topo == -1) return 1;
    return 0;
}

int pilha_cheia(tp_pilha *p){
    if (p->topo == MAX_PILHA - 1) return 1;
    return 0;
}

// Ações da pilha com robustez de verificação.
// Diferente do pop, não interessa retornar o elemento da função.
int push(tp_pilha *p, tp_item_pilha e){
    if (pilha_cheia(p)) return 0;
    p->topo++;
    p->item[p->topo] = e;
    return 1;
}

// Recebe um ponteiro para retornar o elemento desempilhado.
int pop(tp_pilha *p, tp_item_pilha *e){
    if (pilha_vazia(p)) return 0;
    *e = p->item[p->topo];
    p->topo--;
    return 1;
}

// Olha o elemento no topo da pilha.
int elemento_topo(tp_pilha *p, tp_item_pilha *e){
    if (pilha_vazia(p)) return 0;
    *e = p->item[p->topo];
    return 1;
}

// Quantidade de elementos empilhados.
int altura_pilha(tp_pilha *p){
    return p->topo+1;
}

// Não recebe ponteiro, realiza ações na copia.
void print_pilha(tp_pilha p){
    tp_item_pilha e;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p, &e);
        printf("ID: %d | %s\n", e.id, e.pergunta);
    }
}

// Embaralha os vetores de perguntas, em seguinda empilha
void embaralha_pilha(tp_pilha *p, tp_pergunta banco_perguntas[], int total_perguntas){
    tp_item_pilha temp;

    // Algoritmo de Fisher-Yates moderno.
    for (int i = total_perguntas - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Utiliza uma variavel auxiliar para trocar as perguntas de lugar.
        tp_pergunta temp = banco_perguntas[i];
        banco_perguntas[i] = banco_perguntas[j];
        banco_perguntas[j] = temp;
    }

    // Empilha as perguntas embaralhadas na pilha.
    for (int i = 0; i < total_perguntas; i++) {
        push(p, banco_perguntas[i]);
    }
}

#endif