#include "no.h"

typedef struct abb{
    t_no * raiz;
} t_abb;

void inicializa_abb(t_abb *);
int esta_vazia(t_abb *);
void insere(int, t_abb *);
void exibe_in_order(t_abb *);
void exibe_rev_order(t_abb *);
void exibe_pre_order(t_abb *);
int exibe_maior(t_abb *);
int exibe_profundidade(t_abb *);
int exibe_qtd_nos(t_abb *);
int exibe_qtd_nos_nao_folha(t_abb *);
int exibe_qtd_nos_folha(t_abb *);
int busca_numero_arvore_nao_ordenada(t_abb *, int);
int exibe_maior_arvore_nao_ordenada(t_abb *);