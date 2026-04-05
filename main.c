#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "includes/fila_jogador.h"
#include "includes/pilha_pergunta.h"

int main(void){
    srand(time(NULL));
    tp_fila f;
    tp_pilha p;

    inicializa_pilha(&p);
    inicializa_fila(&f);

    int total_perguntas = 6;
    tp_pergunta banco_perguntas[total_perguntas];

    // --- PERGUNTA 1 ---
    char *ops1[] = {"Int", "Float", "Char"};
    init_pergunta(&banco_perguntas[0], "Qual tipo de dado armazena um unico caractere?", 1, 'C');
    init_opcoes(&banco_perguntas[0], ops1);
    banco_perguntas[0].id = 1;

    // --- PERGUNTA 2 ---
    char *ops2[] = {"LIFO", "FIFO", "Random"};
    init_pergunta(&banco_perguntas[1], "Qual a regra de organizacao de uma Pilha?", 2, 'A');
    init_opcoes(&banco_perguntas[1], ops2);
    banco_perguntas[1].id = 2;

    // --- PERGUNTA 3 ---
    char *ops3[] = {"Printf", "Scanf", "Main"};
    init_pergunta(&banco_perguntas[2], "Qual funcao e usada para exibir dados na tela?", 1, 'A');
    init_opcoes(&banco_perguntas[2], ops3);
    banco_perguntas[2].id = 3;

    // --- PERGUNTA 4 ---
    char *ops4[] = {"Asterisco (*)", "E comercial (&)", "Seta (->)"};
    init_pergunta(&banco_perguntas[3], "Qual simbolo representa um ponteiro em C?", 2, 'A');
    init_opcoes(&banco_perguntas[3], ops4);
    banco_perguntas[3].id = 4;

    // --- PERGUNTA 5 ---
    char *ops5[] = {"Stdlib.h", "String.h", "Stdio.h"};
    init_pergunta(&banco_perguntas[4], "Qual biblioteca contem a funcao strcpy?", 1, 'B');
    init_opcoes(&banco_perguntas[4], ops5);
    banco_perguntas[4].id = 5;

    // --- PERGUNTA 6 ---
    char *ops6[] = {"While", "For", "Do-While"};
    init_pergunta(&banco_perguntas[5], "Qual estrutura de repeticao executa o bloco de codigo pelo menos uma vez?", 2, 'C');
    init_opcoes(&banco_perguntas[5], ops6);
    banco_perguntas[5].id = 6;

    // Embaralha as perguntas.
    srand(time(NULL));
    embaralha_pilha(&p, banco_perguntas, total_perguntas);

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