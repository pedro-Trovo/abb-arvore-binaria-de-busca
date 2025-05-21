#include "../include/no.h"

t_no * constroi_no(int i){
    t_no * novo = (t_no *) malloc (sizeof(t_no));

    novo->info = i;
    novo->esq = novo->dir = NULL;

    return novo;
}

void mostrar_no(t_no * no){
    printf("%d ", no->info);
}