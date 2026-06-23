#ifndef REGISTRO_H
#define REGISTRO_H

#include <stdio.h>
#include "pergunta.h"

#define TURMA "CC2MA"
#define ID_JOGADOR "12345"
#define NOME_ARQUIVO "registro.csv"

void inicializar_registro() {
    FILE *f = fopen(NOME_ARQUIVO, "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo de registro!\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    if (ftell(f) == 0) {
        fprintf(f, "Turma;ID Jogador;ID Pergunta;Tema;Dificuldade;Resposta Marcada;Resposta Certa;Acerto\n");
    }

    fclose(f);
}

void registrar_resposta(tp_jogador *j, tp_pergunta *p, char resposta_marcada, int acertou) {
    FILE *f = fopen(NOME_ARQUIVO, "a");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo de registro!\n");
        return;
    }

    fprintf(f, "%s;%s;%d;%s;%d;%c;%c;%s\n",
        j->nome,
        ID_JOGADOR,
        p->id,
        p->tema,
        p->dificuldade,
        resposta_marcada,
        p->resposta_certa,
        acertou ? "Certo" : "Errado"
    );

    fclose(f);
}

#endif
