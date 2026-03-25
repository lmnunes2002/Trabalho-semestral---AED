#include <stdio.h>
#include <stdlib.h>
#include "includes/fila.h"

int main(void){
    tp_fila f;

    incializa_fila_j(&f);
    enfila(&f, 1);
    enfila(&f, 2);
    enfila(&f, 3);
    enfila(&f, 4);


    return 0;
}