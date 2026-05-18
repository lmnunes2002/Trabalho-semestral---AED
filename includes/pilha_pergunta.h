#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "pergunta.h"

typedef tp_pergunta tp_item_pilha;

typedef struct tp_no_pilha{
    tp_item_pilha pergunta;
    struct tp_no_pilha *prox;
} tp_no_pilha;

typedef struct{
    tp_no_pilha *topo;
} tp_pilha;

tp_pilha *inicializa_pilha(){
    tp_pilha *p=(tp_pilha*) malloc(sizeof(tp_pilha));
    p->topo = NULL;
    return p;
}

// Funções de verificação, importantes para o uso da pilha.
int pilha_vazia(tp_pilha *p){
    if (p->topo == NULL) return 1;
    return 0;
}

tp_no_pilha* aloca(){
    tp_no_pilha *pt;
    pt=(tp_no_pilha*) malloc (sizeof(tp_no_pilha));
    return pt;
}

int pilha_cheia(tp_pilha *p){
    tp_no_pilha *teste;
    teste=(tp_no_pilha*) malloc (sizeof(tp_no_pilha));
    
    // Não conseguiu alocar memória.
    if (teste == NULL){
        return 1;
    }
    
    // Desaloca o nó de teste;
    free(teste);
    return 0;
}

// Ações da pilha com robustez de verificação.
// Diferente do pop, não interessa retornar o elemento da função.
int push(tp_pilha *p, tp_item_pilha e) { 
    if (pilha_cheia(p)) return 0; 
    
    tp_no_pilha *novo_no = aloca();
    if (novo_no == NULL) return 0; 
    
    novo_no->pergunta = e; 
    novo_no->prox = p->topo; 
    p->topo = novo_no; 
    
    return 1;
}

// Recebe um ponteiro para retornar o elemento desempilhado.
int pop(tp_pilha *p, tp_item_pilha *e){ 
    if (pilha_vazia(p)) return 0;
    
    tp_no_pilha *aux; 
    
    *e = p->topo->pergunta; 
    aux = p->topo;
    p->topo = p->topo->prox;
    
    free(aux);
    aux = NULL; 
    
    return 1;
}

int elemento_topo(tp_pilha *p, tp_item_pilha *e) {
    if (pilha_vazia(p)) return 0; 
    *e = p->topo->pergunta;
    return 1; 
}

int altura_pilha(tp_pilha *p){
    tp_no_pilha *aux = p->topo;
    int cont = 0;
    
    while(aux != NULL){
        aux = aux->prox;
        cont++;
    }
    return cont;
}

void imprime_pilha(tp_pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    tp_no_pilha *aux = p->topo;
    printf("\nPerguntas na Pilha: \n");
    while (aux != NULL) {
        printf("ID: %d | %s\n", aux->pergunta.id, aux->pergunta.texto); 
        aux = aux->prox; 
    }
}

void destroi_pilha(tp_pilha *p) {
    tp_item_pilha e;
    while (!pilha_vazia(p))
        pop(p, &e);
    free(p);
}

// Protótipo da função que preenche o array de perguntas
void inicializar_banco(tp_pergunta banco_perguntas[]);

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