#ifndef PERGUNTA_H
#define PERGUNTA_H

#define MAX_TEXTO 150
#define QTD_OPCOES 4

#include <string.h>

typedef struct{
    char pergunta[MAX_TEXTO];
    // Matriz 2d, usado como um lista de opcoes.
    char opcoes[QTD_OPCOES][MAX_TEXTO];
    char resposta_certa;
    int dificuldade;
    // Facilitar embaralhamento das perguntas.
    int id;
} tp_pergunta;

// Inicializa as perguntas com os parametros do TAD.
void init_pergunta(tp_pergunta *p, char *txt, int dific, char resp){
    strcpy(p->pergunta, txt);
    p->resposta_certa = resp;
    p->dificuldade = dific; 
}

// Inicializa opcoes de resposta.
// Recebe como parametro um vetor de alternativas separadas por virgula.
void init_opcoes(tp_pergunta *p, char *alternativas[]) {
    // Copia as alternativas para as opcoes.
    for (int i = 0; i < QTD_OPCOES; i++) {
        strcpy(p->opcoes[i], alternativas[i]);
    }
}

#endif