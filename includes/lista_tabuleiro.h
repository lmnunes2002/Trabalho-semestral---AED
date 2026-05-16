#ifndef LISTA_TABULEIRO_H
#define LISTA_TABULEIRO_H

#include <stdio.h>
#include <stdlib.h> 

typedef struct tp_no_aux {
    struct tp_no_aux *ant;  
    int num_casa;
    int acao;               
    int modificador_acerto;
    int modificador_erro;
    struct tp_no_aux *prox; 
} tp_no;

typedef struct {
    tp_no *ini; 
    tp_no *fim; 
} tp_listade;

tp_listade *inicializa_listade() {
    tp_listade *lista = (tp_listade *) malloc(sizeof(tp_listade)); 
    if (lista != NULL) {
        lista -> ini = NULL; 
        lista -> fim = NULL; 
    }
    return lista; 
}

int listade_vazia(tp_listade *lista) {
    return (lista -> ini == NULL); 
}

tp_no *aloca() {
    return (tp_no *) malloc(sizeof(tp_no)); 
}

// Insercao corrigida para usar os campos reais do struct
int insere_fim_tabuleiro(tp_listade *lista, int casa, int acao, int acerto, int erro) {
    tp_no *novo = aloca(); 
    if (novo == NULL) return 0;

    novo -> num_casa = casa; 
    novo -> acao = acao;
    novo -> modificador_acerto = acerto;
    novo -> modificador_erro = erro;
    novo -> prox = NULL; 
    
    if (listade_vazia(lista)) { 
        novo -> ant = NULL;
        lista -> ini = novo; 
    } else { 
        novo -> ant = lista -> fim;
        lista -> fim -> prox = novo; 
    }
    lista -> fim = novo; 
    return 1; 
}

// Busca baseada no numero da casa do tabuleiro
tp_no *busca_casa(tp_listade *lista, int numero) {
    tp_no *atu = lista -> ini;
    while (atu != NULL && atu -> num_casa != numero) {
        atu = atu -> prox;
    }
    return atu;
}

#endif