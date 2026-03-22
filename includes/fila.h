#ifndef FILA_H
#define FILA_H
#include <stdio.h>
#define MAX 101

typedef int tp_item;

typedef struct{
    int ini, fim;
    tp_item item[MAX];
} tp_fila;

// Utiliza uma posição vazia de sacrificio.
void incializa_filha(tp_fila *f){
    f->ini = f->fim = MAX - 1;
}

// Funções de verificação, importantes para o uso da fila.
int fila_vazia(tp_fila *f){
    if (f->ini == f->fim) return 1;
    return 0;
}

// Proxima posição no sentido horário, motor do comportamento circular.
int proximo(int pos){
    if (pos == MAX - 1) return 0;
    pos++;
    return pos;
}

int fila_cheia(tp_fila *f){
    if (proximo(f->fim) == f->ini) return 1;
    return 0;
}

// O ponteiro fim gira no sentido horário e o item é guardado.
int enfila(tp_fila *f, tp_item e){
    if (fila_cheia(f)) return 0;
    f->fim = proximo(f->fim);
    f->item[f->fim] = e;
    return 1;
}

// O ponteiro ini gira no sentido horário perseguindo o fim.
int desenfila(tp_fila *f, tp_item *e){
    if (fila_vazia(f)) return 0;
    f->ini = proximo(f->ini);
    *e = f->item[f->ini];
    return 1;
}

// Quantidade de elementos enfilhados.
int tamanho_fila(tp_fila *f){
    if (fila_vazia(f)) return 0;
    if (f->ini < f->fim) return f->fim - f->ini;
    return MAX - 1 - f->ini + f->fim +1;
}

// Não recebe ponteiro, realiza ações na copia.
void print_fila(tp_fila f){
    tp_item e;
    while(fila_vazia(&f)){
        desenfila(&f, &e);
        printf("%d\n", e);
    }
}

#endif