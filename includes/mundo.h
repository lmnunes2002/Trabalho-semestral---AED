#ifndef MUNDO_H
#define MUNDO_H

#include <stdio.h>
#include "jogador.h"
#include "fila_jogador.h"
#include "lista_tabuleiro.h"

void cadastrar_jogadores(tp_fila *jogadores){
    printf("\n--- CADASTRANDO OS JOGADORES ---\n");

    // 3. CADASTRO DE JOGADORES 100% DINÂMICO
    printf("--- CONFIGURAÇÃO DO JOGO ---\n");
    
    int num_jogadores = 0;
    while (num_jogadores < 2) {
        printf("Digite o número de jogadores: ");
        scanf("%d", &num_jogadores);
        
        if (num_jogadores < 2) {
            printf("Ops! O jogo precisa de pelo menos 2 participantes.\n\n");
        }
    }
    
    int i = 0;
    while (i < num_jogadores) {
        tp_jogador novo_jogador;
        char nome_buffer[30];

        printf("Digite o nome do Jogador %d: ", i + 1);
        scanf(" %29s", nome_buffer); // O espaço limpa buffers indesejados

        // Usa a sua função original de inicialização
        init_jogador(&novo_jogador, nome_buffer);
        
        // Define o ID dinamicamente baseado no contador do laço
        novo_jogador.id = i + 1; 

        // Enfila o jogador imediatamente
        enfila(jogadores, novo_jogador);
        
        i++;
    }
}

#endif