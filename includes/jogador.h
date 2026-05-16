#include <time.h>
#include <stdlib.h>
#include "fila_jogador.h"

typedef struct {
    int id;
    int pos;
    char nome[30];
    int pontuacao;
} tp_jogador;

void init_jogador (tp_jogador *jogador){
    jogador->pos = 0;
    jogador->pontuacao = 0;
<<<<<<< Updated upstream
}
=======

    // Copia a string txt para a struct jogador.
    strcpy(jogador->nome, txt);
}
void mudar_nome(tp_jogador *jogador, char novo_nome[]) {
    strcpy(jogador->nome, novo_nome);
}

// Mostra os jogadores que foram registrados (Usa o ID correto como controle)
void apresentar_nome(tp_jogador *jogador, int qtd) {
    int i;
	for (i = 0; i < qtd; i++) {
        printf("Nome do jogador %d: %s\n", i + 1, jogador[i].nome);
    }
}
#endif
>>>>>>> Stashed changes
