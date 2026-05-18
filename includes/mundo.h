#ifndef MUNDO_H
#define MUNDO_H

#include <stdio.h>
#include "jogador.h"
#include "fila_jogador.h"
#include "pilha_pergunta.h"
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

void hello_world(tp_pilha *pilha_perguntas, tp_fila *fila_jogadores, tp_listade *tabuleiro, tp_no *pos_atual){
    printf("\n--- TUDO PRONTO! INICIANDO O JOGO ---\n");

    int rodada = 1;
    
    // O jogo roda até a pilha acabar ou alguém vencer
    while (!pilha_vazia(pilha_perguntas)) {
        printf("\n========================");
        printf("\n--- RODADA %d ---", rodada++);
        printf("\n========================");

        tp_jogador jogador_da_vez;
        
        // Desenfila quem vai jogar agora (Funciona para qualquer quantidade de jogadores)
        desenfila(fila_jogadores, &jogador_da_vez);

        // Aguarda o input do jogador para rolar o dado
        printf("\n[Turno de %s] Pressione ENTER para rolar o dado...", jogador_da_vez.nome);
        getchar(); 

        // Rola o dado
        int dado = (rand() % 6) + 1;
        printf("-> %s rolou o dado e tirou: %d\n", jogador_da_vez.nome, dado);

        // Localiza onde este jogador estava usando o campo correto: '.pos'
        pos_atual = busca_casa(tabuleiro, jogador_da_vez.pos);

        // Espia o topo da pilha para descobrir a dificuldade antes de mover
        tp_item_pilha pergunta_topo;
        int dificuldade_atual = 1; 
        if (elemento_topo(pilha_perguntas, &pergunta_topo)) {
            dificuldade_atual = pergunta_topo.dificuldade;
        }

        // Move o jogador usando a sua função do tabuleiro
        pos_atual = jogada(tabuleiro, pos_atual, dado, dificuldade_atual);
        
        // Sincroniza a nova casa de voltar no campo '.pos' do jogador
        jogador_da_vez.pos = pos_atual->num_casa;
        
        printf("%s moveu para a Casa %d \n", jogador_da_vez.nome, jogador_da_vez.pos);

        // Condição de Vitória (Casa 30 ou superior)
        if (jogador_da_vez.pos >= 30) {
            printf("\n FIM DE JOGO! %s CHEGOU À CASA %d E VENCEU O JOGO! \n", jogador_da_vez.nome, jogador_da_vez.pos);
            break;
        }

        // 5. VERIFICAÇÃO DO TIPO DE CASA
        if (pos_atual->acao == CASA_PERGUNTA) {
            printf(" Casa %d possui um desafio!\n", pos_atual->num_casa);

            tp_item_pilha pergunta_vez;
            if (pop(pilha_perguntas, &pergunta_vez)) {
                
                // Executa a sua função de perguntas
                int acertou = realizar_pergunta(pergunta_vez);

                if (acertou) {
                    printf("Bônus aplicado: +%d casas!\n", pos_atual->modificador_acerto);
                    pos_atual = jogada(tabuleiro, pos_atual, pos_atual->modificador_acerto, dificuldade_atual);
                } else {
                    printf("Punição aplicada: %d casas!\n", pos_atual->modificador_erro);
                    
                    int passos = abs(pos_atual->modificador_erro);
                    for (int p = 0; p < passos; p++) {
                        if (pos_atual->ant != NULL) {
                            pos_atual = pos_atual->ant;
                        }
                    }
                }
                
                // Atualiza a posição final pós-desafio no jogador
                jogador_da_vez.pos = pos_atual->num_casa;
                printf("Posição reajustada de %s: Casa %d\n", jogador_da_vez.nome, jogador_da_vez.pos);
                
                // Limpa o 'Enter' deixado pelo scanf da resposta
                getchar(); 
            }
        } else {
            printf("Casa normal. Nada acontece.\n");
        }

        // Enfila o jogador de volta para aguardar o próximo turno dele (mantém a rotação infinita)
        enfila(fila_jogadores, jogador_da_vez);
    }
}

#endif