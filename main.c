#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "includes/fila_jogador.h"
#include "banco_perguntas.c"

int main(void){
    srand(time(NULL));
    tp_fila f;
    tp_pilha p;

    inicializa_pilha(&p);
    inicializa_fila(&f);

    // Inicializa o banco de perguntas e armazena em um array para facilitar.
    tp_pergunta banco_perguntas[TOTAL_PERGUNTAS];
    inicializar_banco(banco_perguntas);

    // Embaralha as perguntas.
    embaralha_pilha(&p, banco_perguntas, TOTAL_PERGUNTAS);

    printf("Teste de desempilhamento:\n");
    tp_pergunta p_teste;

    while (!pilha_vazia(&p)) {
        pop(&p, &p_teste);
        printf("ID: %d | Pergunta: %s\n", p_teste.id, p_teste.pergunta);
    }

    // Comentado por enquanto
    // tp_jogador j1 = {1, 0, "Alice", 0};
    // tp_jogador j2 = {2, 0, "Bob", 0};

    // enfila(&f, j1);
    // enfila(&f, j2);

    // for(int i = 0; i < 5; i++) {
    //     printf("\n--- RODADA %d ---", i + 1);
    //     vez_jogador(&f); 
    // }

    printf("\n\nTeste concluido com sucesso!");
    return 0;
}