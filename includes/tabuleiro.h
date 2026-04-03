#define CASA_COMUM 0
#define CASA_QUIZ 1

#include "jogador.h"

int verificar_casa(tp_jogador *j){
    int mapa[58] = {CASA_COMUM};            // Incializando todas as casas como comuns.
    
    mapa[4]=CASA_QUIZ;                      // Definindo as casas de pergunta do tabuleiro.
    mapa[11]=CASA_QUIZ; 
    mapa[17]=CASA_QUIZ;
    mapa[24]=CASA_QUIZ; 
    mapa[30]=CASA_QUIZ; 
    mapa[37]=CASA_QUIZ; 
    mapa[43]=CASA_QUIZ; 
    mapa[50]=CASA_QUIZ; 
    mapa[57]=CASA_QUIZ;

    if (pos_atual) return CASA_COMUM;       // Se o jogador ja ganhou, retorna CASA_COMUM;

    return mapa[pos_atual];                 // Retorna o valor que esta guardado na posicao do array.
}