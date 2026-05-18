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

    //Perguntas 7:
    char *ops7[] = {"Recursividade", "Busca binaria", "Quick sort", "Alocação de memoria dinamica"};
    init_pergunta(&banco_perguntas[6], "Os algoritmos de backtracking sao caracterizados por geralmente usarem:", 1, 'A');
    init_opcoes(&banco_perguntas[6], ops7);
    banco_perguntas[6].id = 7;

    
    //Perguntas 8:
    char *ops8[] = {"Um valor inteiro", "Si mesma", "Nulo", "Vetor auxiliar"};
    init_pergunta(&banco_perguntas[7], "Uma lista simplesmente encadeada para ser devidamente inicializada deve apontar para:", 1, 'C');
    init_opcoes(&banco_perguntas[7], ops8);
    banco_perguntas[7].id = 8;
    
    
    //Perguntas 9:
    char *ops9[] = {"tp_no *ini", "tp_no *fim", "int tamanho", "tp_item info"};
    init_pergunta(&banco_perguntas[8], "Qual das opcoes abaixo nao eh um membro de uma lista duplamente encadeada, seja ela CLASSICA ou MODERNA?", 2, 'D');
    init_opcoes(&banco_perguntas[8], ops9);
    banco_perguntas[8].id = 9;
    
    
    //Perguntas 10:
    char *ops10[] = {"Merge sort", "Heap sort", "Shell sort", "Insertion sort"};
    init_pergunta(&banco_perguntas[9], "Qual dos algoritmos abaixo segue a ideia usar árvores para realizar uma ordenação em um vetor?", 3, 'B');
    init_opcoes(&banco_perguntas[9], ops10);
    banco_perguntas[9].id = 10;
    
    
    //Perguntas 11:
    char *ops11[] = {"O(log(n)), O(1), O(log(n))", "O(n*log(n)), O(1), O(log(n))", "O(n²), O(n*log(n)), O(log(n))", "O(n*x), O(n) e O(log(n))"};
    init_pergunta(&banco_perguntas[10], "A busca binaria, um famoso algoritmo que divide um vetor em subvetores, costuma ter quais complexidades algoritmicas em seus pior, melhor e médio caso, respectivamente?", 2, 'A');
    init_opcoes(&banco_perguntas[10], ops11);
    banco_perguntas[10].id = 11;
    
    
    //Perguntas 12:
    char *ops12[] = {"stdio.h", "file.h", "csv.h", "stream.h"};
    init_pergunta(&banco_perguntas[11], "O tipo de dado 'FILE' pertence à biblioteca:", 3, 'A');
    init_opcoes(&banco_perguntas[11], ops12);
    banco_perguntas[11].id = 12;


}

int realizar_pergunta(tp_item_pilha pergunta){
    printf("\n PERGUNTA DE NÍVEL %d: %s\n", pergunta.dificuldade, pergunta.texto);

    printf("A) %s\n", pergunta.opcoes[0]);
    printf("B) %s\n", pergunta.opcoes[1]);
    printf("C) %s\n", pergunta.opcoes[2]);
    printf("D) %s\n", pergunta.opcoes[3]);

    char resp;
    printf("\n Sua resposta: ");
    scanf(" %c", &resp);

    if (resp >= 'a' && resp <= 'z') {
        resp -= 32; // Converte para maiúscula
    }

    if (resp == pergunta.resposta_certa) {
        printf("\nCORRETO! Você avançará!\n");
        return 1; 
    } else {
        printf("\nERRADO! A resposta certa era a alternativa %c.\n", pergunta.resposta_certa);
        return 0;
    }
}