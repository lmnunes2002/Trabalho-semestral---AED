#ifndef MUNDO_H
#define MUNDO_H
#include <stdio.h>
#include "jogador.h"

//fun��oo que cadastra os jogadores, dando início ao jogo, recebendo o vetor na main como parâmetro
void init_mundo(tp_jogador *jogadores){
    //Quantidade de jogadores
    int n, i;

    /*Laço para registrar os jogadores, tentei deixá-lo robusto, diferente do último commit, focarei mais em dar robustez
    ao invés de continuar criando mais funções*/
    do{
        printf("Digite a quantidade de jogadores (entre 2 e 4): ");
    }while(scanf("%d", &n) != 1  || n < 2 || n > 4);

    //Laço para registrar o nome dos jogadores a cada variável
	for(i = 0; i < n; i++){
        //Nome dentro do for para que a cada laço, a string seja limpada
        char novo_nome[30] = "";



        //Registro dos nomes dos jogadores
        printf("Digite um nome de até 30 caracteres para o jogador %d: ", i + 1);
        scanf(" %[^\n]", novo_nome);
        strcpy(jogadores[i].nome, novo_nome);
        
        //Fun��o que inicializa cada jogador durante o la�o
        init_jogador(&jogadores[i], jogadores[i].nome);
    }

}

#endif
