#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "includes/fila_jogador.h"

int main(void){
    srand(time(NULL));
    tp_fila f;
    inicializa_fila(&f);

    tp_jogador j1 = {1, 0, "Alice", 0};
    tp_jogador j2 = {2, 0, "Bob", 0};

    enfila(&f, j1);
    enfila(&f, j2);

    for(int i = 0; i < 5; i++) {
        printf("\n--- RODADA %d ---", i + 1);
        vez_jogador(&f); 
    }

    printf("\n\nTeste concluido com sucesso!");
    return 0;
}