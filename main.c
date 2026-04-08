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

    // --- DIFICULDADE 1 (Fácil) ---

    // Pergunta 1: Ponteiros
    char *ops1[] = {"&", "*", "->", "#"};
    init_pergunta(&banco_perguntas[0], "Qual operador e usado para obter o endereco de uma variavel?", 1, 'A');
    init_opcoes(&banco_perguntas[0], ops1);
    banco_perguntas[0].id = 1;

    // Pergunta 2: Filas
    char *ops2[] = {"Push", "Pop", "Enqueue", "Top"};
    init_pergunta(&banco_perguntas[1], "Qual o termo tecnico para inserir um elemento em uma Fila?", 1, 'C');
    init_opcoes(&banco_perguntas[1], ops2);
    banco_perguntas[1].id = 2;

    // --- DIFICULDADE 2 (Média) ---

    // Pergunta 3: Pilhas
    char *ops3[] = {"Inverter uma string", "Escalonamento de processos", "Buffer de impressora", "Busca em largura (BFS)"};
    init_pergunta(&banco_perguntas[2], "Qual destas e uma aplicacao classica de uma Pilha?", 2, 'A');
    init_opcoes(&banco_perguntas[2], ops3);
    banco_perguntas[2].id = 3;

    // Pergunta 4: Ponteiros (Aritmética)
    char *ops4[] = {"1 byte", "Depende do tipo do dado", "4 bytes sempre", "Nao altera o endereco"};
    init_pergunta(&banco_perguntas[3], "Ao somar 1 a um ponteiro (p++), quanto o endereco avanca?", 2, 'B');
    init_opcoes(&banco_perguntas[3], ops4);
    banco_perguntas[3].id = 4;

    // --- DIFICULDADE 3 (Difícil) ---

    // Pergunta 5: Recursão
    char *ops5[] = {"Heap", "Stack (Pilha)", "Data Segment", "BSS"};
    init_pergunta(&banco_perguntas[4], "Em qual regiao da memoria as chamadas recursivas sao armazenadas?", 3, 'B');
    init_opcoes(&banco_perguntas[4], ops5);
    banco_perguntas[4].id = 5;

    // Pergunta 6: Ponteiros (Indireção)
    char *ops6[] = {"Um valor inteiro", "O endereco do ponteiro", "O valor apontado pelo ponteiro", "Um erro de sintaxe"};
    init_pergunta(&banco_perguntas[5], "O que a expressao '**ponteiro' (ponteiro para ponteiro) acessa?", 3, 'C');
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