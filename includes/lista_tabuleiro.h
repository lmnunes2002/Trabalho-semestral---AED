#ifndef LISTA_TABULEIRO_H
#define LISTA_TABULEIRO_H

#include <stdio.h>
#include <stdlib.h> 

#define CASA_PERGUNTA 1
#define CASA_NORMAL 0

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
    int total_casas;
} tp_listade;

tp_listade *inicializa_listade() {
    tp_listade *lista = (tp_listade *) malloc(sizeof(tp_listade)); 
    if (lista != NULL) {
        lista -> ini = NULL; 
        lista -> fim = NULL; 
        lista->total_casas = 0;
    }
    return lista; 
}

int listade_vazia(tp_listade *lista) {
    return (lista -> ini == NULL); 
}

tp_no *aloca_no_tabuleiro() {
    return (tp_no *) malloc(sizeof(tp_no)); 
}

// Insercao corrigida para usar os campos reais do struct
int insere_fim_tabuleiro(tp_listade *lista, int casa, int acao, int acerto, int erro) {
    tp_no *novo = aloca_no_tabuleiro(); 
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

// Definição dos tipos das casas e configuração de modificadores.
void casa_pergunta(tp_no *atu, int dificuldade){
    atu->acao = CASA_NORMAL;
    atu->modificador_acerto = 0;
    atu->modificador_erro = 0;

    // 30% de chance de uma casa possuir uma pergunta.
    if((rand() % 100) < 30){
        atu->acao = CASA_PERGUNTA;

        if(dificuldade == 1){
            atu->modificador_acerto = 2;
            atu->modificador_erro = -1;
        } else if (dificuldade == 2){
            atu->modificador_acerto = 3;
            atu->modificador_erro = -2;
        } else {
            atu->modificador_acerto = 4;
            atu->modificador_erro = -3;
        }
    }
}

// Avança jogador com alocação dinâmica de nós.
tp_no *jogada(tp_listade *tabuleiro, tp_no *jogador, int dado, int dificuldade){
    if (tabuleiro == NULL) return jogador;

    tp_no *pos = jogador;
    int cont = 0;

    while(cont < dado){
        // Final do tabuleiro ou início do jogo.
        if(pos == NULL || pos->prox == NULL){
            
            // Número máximo de casas atualmente.
            if(tabuleiro->total_casas >= 30) break;

            tabuleiro->total_casas++;
            int nova_casa = tabuleiro->total_casas;

            insere_fim_tabuleiro(tabuleiro, nova_casa, CASA_NORMAL, 0, 0);

            if(pos == NULL){
                pos = tabuleiro->ini;
            } else {
                pos = pos->prox;
            }

            casa_pergunta(pos, dificuldade);
        } else {
            // A casa já possuía memória alocada.
            pos = pos->prox;
        }
        cont++;
    }

    // Posição onde o jogador parou.
    return pos;
}

// Retira da memória todos os nós da lista e também o ponteiro inicial.
tp_listade *destroi_listad(tp_listade *lista){
    tp_no *atu;
    atu = lista->ini;

    while(atu != NULL){
        lista->ini = atu->prox;
        free(atu);
        atu=lista->ini;
    }
    free(lista);
    return NULL;
}

#endif