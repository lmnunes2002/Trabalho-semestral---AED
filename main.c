#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "includes/fila_jogador.h"
#include "banco_perguntas.c"

#define TOTAL_PERGUNTAS 6

// Protótipo para evitar warnings
void inicializar_banco(tp_pergunta banco_perguntas[]);

int main(void){
    srand(time(NULL));

    // Inicialização das Estruturas Dinâmicas (ambas retornam ponteiros)
    tp_pilha *p = inicializa_pilha();
    tp_fila *f = inicializa_fila();

    // Preparação do Banco de Perguntas
    tp_pergunta banco_perguntas[TOTAL_PERGUNTAS];
    inicializar_banco(banco_perguntas);

    // Popular a Pilha (Embaralhar e Empilhar)
    embaralha_pilha(p, banco_perguntas, TOTAL_PERGUNTAS);

    // Inicialização dos Jogadores
    tp_jogador j1 = {1, 0, "Alice", 0};
    tp_jogador j2 = {2, 0, "Bob", 0};

    enfila(f, j1);
    enfila(f, j2);

    printf("--- INICIO DO TESTE DINAMICO ---\n");
    printf("Jogadores na fila: \n");
    print_fila(f);

    for(int i = 0; i < 8; i++) {
        printf("\n========================");
        printf("\n--- RODADA %d ---", i + 1);
        printf("\n========================");

        // Mostra quem é o dono da vez e gira a fila
        vez_jogador(f); 

        // Desempilha uma pergunta para ilustrar o uso da pilha na rodada
        tp_item_pilha pergunta_da_vez;
        if (pop(p, &pergunta_da_vez)) {
            printf("\nPergunta sorteada -> ID: %d | %s\n", 
                    pergunta_da_vez.id, pergunta_da_vez.pergunta);
        } else {
            printf("\nA pilha de perguntas acabou!\n");
        }
    }

    printf("\n\n--- LIMPANDO MEMORIA ---");
    
    free(p);
    free(f);

    printf("\nTeste concluido com sucesso!\n");
    return 0;
}