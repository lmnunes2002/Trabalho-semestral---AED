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

<<<<<<< Updated upstream
#endif
=======
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
                
                char resposta_marcada;
                int acertou = realizar_pergunta(pergunta_vez, &resposta_marcada);
                registrar_resposta(&jogador_da_vez, &pergunta_vez, resposta_marcada, acertou);

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


void apresentar_ranking() {
    FILE *f = fopen(NOME_ARQUIVO, "r");
    if (f == NULL) {
        printf("\nNenhum registro de jogo encontrado.\n");
        return;
    }

    char linha[256];
    // Pula o cabeçalho
    fgets(linha, sizeof(linha), f);

    typedef struct {
        char nome[30];
        int pontuacao;
        char detalhes[1024]; // Para armazenar perguntas e acertos/erros
    } tp_ranking;

    tp_ranking ranking[100];
    int num_jogadores = 0;

    while (fgets(linha, sizeof(linha), f)) {
        char nome[30], id_jog[20], tema[50], resp_m, resp_c, status[10];
        int id_perq, dific;

        // Formato: Turma/Nome;ID Jogador;ID Pergunta;Tema;Dificuldade;Resposta Marcada;Resposta Certa;Acerto
        sscanf(linha, "%[^;];%[^;];%d;%[^;];%d;%c;%c;%s", 
               nome, id_jog, &id_perq, tema, &dific, &resp_m, &resp_c, status);

        int achei = -1;
        for (int i = 0; i < num_jogadores; i++) {
            if (strcmp(ranking[i].nome, nome) == 0) {
                achei = i;
                break;
            }
        }

        if (achei == -1) {
            strcpy(ranking[num_jogadores].nome, nome);
            ranking[num_jogadores].pontuacao = 0;
            ranking[num_jogadores].detalhes[0] = '\0';
            achei = num_jogadores;
            num_jogadores++;
        }

        if (strcmp(status, "Certo") == 0) {
            ranking[achei].pontuacao += (dific * 10);
        }

        char info_pergunta[150];
        sprintf(info_pergunta, "  - Pergunta %d (%s): %s\n", id_perq, tema, status);
        strcat(ranking[achei].detalhes, info_pergunta);
    }
    fclose(f);

    // Ordena ranking (Bubble Sort simples para o trabalho)
    for (int i = 0; i < num_jogadores - 1; i++) {
        for (int j = 0; j < num_jogadores - i - 1; j++) {
            if (ranking[j].pontuacao < ranking[j + 1].pontuacao) {
                tp_ranking temp = ranking[j];
                ranking[j] = ranking[j + 1];
                ranking[j + 1] = temp;
            }
        }
    }

    printf("\n========== RANKING DOS JOGADORES ==========\n");
    for (int i = 0; i < num_jogadores; i++) {
        printf("%d. %s - Pontuacao: %d\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
        printf("   Historico:\n%s", ranking[i].detalhes);
        printf("-------------------------------------------\n");
    }
}

#endif
>>>>>>> Stashed changes
