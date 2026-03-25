#include "fila.h"

typedef struct {
    int id;
    int pos[30];
    char name[30];
    int pontuacao;
} tp_jogador;

void init_jogador (tp_jogador *jogador){
    jogador->pos[0] = 0;
    jogador->pontuacao = 0;
}

int insere_fila_jogador(tp_fila *f, tp_jogador j){
    if(tamanho_fila(f) > 4){
        printf("Excedido o numero de jogadores");
        return 0;
    } 

    // Tirar duvida aqui!
    // enfila(f, j);
    return 1;
}