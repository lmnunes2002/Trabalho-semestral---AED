#include "includes/pilha_pergunta.h"

void inicializar_banco(tp_pergunta banco_perguntas[]) {
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

    // Pergunta 3: Pilhas
    char *ops3[] = {"Inverter uma string", "Escalonamento de processos", "Buffer de impressora", "Busca em largura (BFS)"};
    init_pergunta(&banco_perguntas[2], "Qual destas e uma aplicacao classica de uma Pilha?", 2, 'A');
    init_opcoes(&banco_perguntas[2], ops3);
    banco_perguntas[2].id = 3;

    // Pergunta 4: Ponteiros
    char *ops4[] = {"1 byte", "Depende do tipo do dado", "4 bytes sempre", "Nao altera o endereco"};
    init_pergunta(&banco_perguntas[3], "Ao somar 1 a um ponteiro (p++), quanto o endereco avanca?", 2, 'B');
    init_opcoes(&banco_perguntas[3], ops4);
    banco_perguntas[3].id = 4;

    // Pergunta 5: Recursão
    char *ops5[] = {"Heap", "Stack (Pilha)", "Data Segment", "BSS"};
    init_pergunta(&banco_perguntas[4], "Em qual regiao da memoria as chamadas recursivas sao armazenadas?", 3, 'B');
    init_opcoes(&banco_perguntas[4], ops5);
    banco_perguntas[4].id = 5;

    // Pergunta 6: Ponteiros
    char *ops6[] = {"Um valor inteiro", "O endereco do ponteiro", "O valor apontado pelo ponteiro", "Um erro de sintaxe"};
    init_pergunta(&banco_perguntas[5], "O que a expressao '**ponteiro' (ponteiro para ponteiro) acessa?", 3, 'C');
    init_opcoes(&banco_perguntas[5], ops6);
    banco_perguntas[5].id = 6;
}