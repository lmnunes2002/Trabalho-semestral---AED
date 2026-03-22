#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#define MAX 100

typedef int tp_item;

typedef struct{
    int topo;
    tp_item item[MAX];
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
    if (p->topo == MAX - 1) return 1;
    return 0;
}

// Ações da pilha com robustez de verificação.
// Diferente do pop, não interessa retornar o elemento da função.
int push(tp_pilha *p, tp_item e){
    if (pilha_cheia(p)) return 0;
    p->topo++;
    p->item[p->topo] = e;
    return 1;
}

// Recebe um ponteiro para retornar o elemento desempilhado.
int pop(tp_pilha *p, tp_item *e){
    if (pilha_vazia(p)) return 0;
    *e = p->item[p->topo];
    p->topo--;
    return 1;
}

// Olha o elemento no topo da pilha.
int elemento_topo(tp_pilha *p, tp_item *e){
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
    tp_item e;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p, &e);
        printf("%d\n", e);
    }
}

#endif