#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "includes/fila_jogador.h"
<<<<<<< Updated upstream
=======
#include "banco_perguntas.c"
#include "includes/jogador.h"
#include "includes/mundo.h"
#include "includes/lista_tabuleiro.h"

>>>>>>> Stashed changes

int main(void){
    srand(time(NULL));
    tp_fila f;
<<<<<<< Updated upstream
    inicializa_fila(&f);

    tp_jogador j1 = {1, 0, "Alice", 0};
    tp_jogador j2 = {2, 0, "Bob", 0};
    tp_jogador j3 = {3, 0, "Joe", 0};

    enfila(&f, j1);
    enfila(&f, j2);

    for(int i = 0; i < 5; i++) {
        printf("\n--- RODADA %d ---", i + 1);
        vez_jogador(&f); 
    }

=======
    tp_pilha p;
	tp_fila jogadas;
	
    inicializa_pilha(&p);
    inicializa_fila(&f);
	inicializa_fila(&jogadas);
	
    // Inicializa o banco de perguntas e armazena em um array para facilitar.
    tp_pergunta banco_perguntas[TOTAL_PERGUNTAS];
    inicializar_banco(banco_perguntas);

    // Embaralha as perguntas.
    embaralha_pilha(&p, banco_perguntas, TOTAL_PERGUNTAS);
	
	// Apenas declara o vetor de tamanho maximo de forma limpa
    tp_jogador jogadores[4];
    
    // Cadastra os jogadores no vetor e retorna quantos foram registrados
    init_mundo(jogadores);
    
    int i;
    for (i = 0; i < 4; i++) {
        jogadores[i].id = i + 1;
        enfila(&jogadas, jogadores[i]);
    }

    printf("\n--- Ordem de jogadas inicializada ---\n");
    apresentar_nome(jogadores, 4);

    // Exemplo de execucao de um turno:
    printf("\n--- Executando Primeiro Turno ---");
    vez_jogador(&jogadas);


>>>>>>> Stashed changes
    printf("\n\nTeste concluido com sucesso!");
    return 0;
}
