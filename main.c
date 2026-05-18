#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "includes/mundo.h"
#include "banco_perguntas.c"

#define TOTAL_PERGUNTAS 12

// Protótipos para evitar warnings de compilação
void inicializar_banco(tp_pergunta banco_perguntas[]);
int realizar_pergunta(tp_item_pilha pergunta);

int main(void) {
    srand(time(NULL));

    // 1. Inicialização das Estruturas Dinâmicas
    tp_pilha *pilha_perguntas = inicializa_pilha();
    tp_fila *fila_jogadores = inicializa_fila();
    tp_listade *tabuleiro = inicializa_listade();

    // 2. Preparação das Perguntas
    tp_pergunta banco[TOTAL_PERGUNTAS];
    inicializar_banco(banco);
    embaralha_pilha(pilha_perguntas, banco, TOTAL_PERGUNTAS);

    // 3. CADASTRO DE JOGADORES 100% DINÂMICO
    cadastrar_jogadores(fila_jogadores);

    // Limpa o buffer do teclado para o getchar() do jogo funcionar perfeitamente
    getchar(); 

    // Ponteiro para monitorar a posição física no tabuleiro
    tp_no *pos_atual = NULL;

    hello_world(pilha_perguntas, fila_jogadores, tabuleiro, pos_atual);

    // 6. Limpeza Geral de Memória Dinâmica
    printf("\n\n--- LIMPANDO MEMÓRIA E ENCERRANDO ---");
    destroi_listad(tabuleiro);
    destroi_pilha(pilha_perguntas);
    destroi_fila(fila_jogadores);

    printf("\nSistema encerrado com sucesso.\n");
    return 0;
}