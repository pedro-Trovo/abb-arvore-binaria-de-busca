#include "../include/abb.h"

void inicializa_abb(t_abb * a){
    a->raiz = NULL;
}

int esta_vazia(t_abb * a){
    return a->raiz == NULL;
}

// Recursao para inserir valor
void insere_rec(t_no * novo, t_no * atual){
    if(novo->info <= atual->info){
        if(atual->esq == NULL){
            atual->esq = novo;
        }
        else{
            insere_rec(novo, atual->esq);
        }
    }
    else{
        if(atual->dir == NULL){
            atual->dir = novo;
        }
        else{
            insere_rec(novo, atual->dir);
        }
    }
}

// Inserir valor na Arvore
void insere(int i, t_abb * a){
    t_no * novo = constroi_no(i);

    if(esta_vazia(a)){
        a->raiz = novo;
    }
    else{
        insere_rec(novo, a->raiz);
    }
}

// Exibicao em ordem
void exibe_in_order_rec(t_no * atual){
    if(atual != NULL){
        exibe_in_order_rec(atual->esq);
        mostrar_no(atual);
        exibe_in_order_rec(atual->dir);
    }
}

void exibe_in_order(t_abb * a){
    if(esta_vazia(a)){
        printf("A Arvore esta vazia!!");
    }
    else{
        exibe_in_order_rec(a->raiz);
    }
}


// Exibicao ordem reversa
void exibe_rev_order_rec(t_no * atual){
    if(atual != NULL){
        exibe_rev_order_rec(atual->dir);
        mostrar_no(atual);
        exibe_rev_order_rec(atual->esq);
    }
}

void exibe_rev_order(t_abb * a){
    if(esta_vazia(a)){
        printf("A Arvore esta vazia");
    }
    else{
        exibe_rev_order_rec(a->raiz);
    }
}


// Exibicao pre-ordem
void exibe_pre_order_rec(t_no * atual){
    if(atual != NULL){
        mostrar_no(atual);
        exibe_pre_order_rec(atual->esq);
        exibe_pre_order_rec(atual->dir);
    }
}

void exibe_pre_order(t_abb * a){
    if(esta_vazia(a)){
        printf("A Arvore esta vazia!!");
    }
    else{
        exibe_pre_order_rec(a->raiz);
    }
}


// Exibe maior valor
int exibe_maior(t_abb * a){
    if(esta_vazia(a)){
        return -1;
    }
    
    t_no * atual = (t_no *) malloc (sizeof(t_no));
    atual = a->raiz;

    while(atual->dir != NULL){
        atual = atual->dir;
    }

    return atual->info;
}


// Exibe o maior valor em uma Arvore NAO ordenada
int exibe_maior_arvore_nao_ordenada_rec(t_no * atual, int maior){
    if(atual->info > maior){
        maior = atual->info;
    }
    
    if(atual->esq != NULL){
        maior = exibe_maior_arvore_nao_ordenada_rec(atual->esq, maior);
    }

    if(atual->dir != NULL){
        maior = exibe_maior_arvore_nao_ordenada_rec(atual->dir, maior);
    }

    return maior;
}

int exibe_maior_arvore_nao_ordenada(t_abb * a){
     if(esta_vazia(a)){
        return -1;
    }

    exibe_maior_arvore_nao_ordenada_rec(a->raiz, 0);
}


// Exibe a Profundidade/Altura da Arvore
int exibe_profundidade_rec(t_no * atual){
    int nivel_esq = 0, nivel_dir = 0;

    if(atual->esq == NULL && atual->dir == NULL){
        return 0;
    }
    if(atual->esq != NULL){
        nivel_esq = exibe_profundidade_rec(atual->esq);
    }
    if(atual->dir != NULL){
        nivel_dir = exibe_profundidade_rec(atual->dir);
    }

    return nivel_esq > nivel_dir ? nivel_esq + 1 : nivel_dir + 1;
}

int exibe_profundidade(t_abb * a){
    if(esta_vazia(a)){
        return 0;
    }

    return exibe_profundidade_rec(a->raiz);
}


// Exibe a Quantidade de Nós em uma Arvore
int exibe_qtd_nos_rec(t_no * atual){
    if(atual == NULL){
        return 0;
    }

    if(atual->esq == NULL && atual->dir == NULL){
        return 1;
    }

    return exibe_qtd_nos_rec(atual->esq) + 1 + exibe_qtd_nos_rec(atual->dir);
}

int exibe_qtd_nos(t_abb * a){
    if(esta_vazia(a)){
        return 0;
    }

    return exibe_qtd_nos_rec(a->raiz);
}


// Exibe a Quantidade de Nós não-folha em uma Arvore 
int exibe_qtd_nos_nao_folha_rec(t_no * atual){
    if(atual == NULL || (atual->esq == NULL && atual->dir == NULL)){
        return 0;
    }

    return exibe_qtd_nos_nao_folha_rec(atual->esq) + 1 + exibe_qtd_nos_nao_folha_rec(atual->dir);
}

int exibe_qtd_nos_nao_folha(t_abb * a){
    if(esta_vazia(a)){
        return 0;
    }

    return exibe_qtd_nos_nao_folha_rec(a->raiz);
}


// Exibe a Quantidade de Nós Folha em uma Arvore
int exibe_qtd_nos_folha_rec(t_no * atual){
    if(atual == NULL){
        return 0;
    }

    if(atual->esq == NULL && atual->dir == NULL){
        return 1;
    }

    return exibe_qtd_nos_folha_rec(atual->esq) + exibe_qtd_nos_folha_rec(atual->dir);
}

int exibe_qtd_nos_folha(t_abb * a){
    if(esta_vazia(a)){
        return 0;
    }

    return exibe_qtd_nos_folha_rec(a->raiz);
}


// Buscar um numero em uma Arvore não ordenada
int busca_numero_arvore_nao_ordenada_rec(t_no * atual, int valor){
    int n=-1;
    if(atual->info == valor){
        return valor;
    }

    if(atual->esq != NULL){
        n = busca_numero_arvore_nao_ordenada_rec(atual->esq, valor);
        if(n == valor){
            return n;
        }
    }

    if(atual->dir != NULL){
        n = busca_numero_arvore_nao_ordenada_rec(atual->dir, valor);
        if(n == valor){
            return n;
        }
    }

    return -1;
}

int busca_numero_arvore_nao_ordenada(t_abb * a, int valor){
    if(esta_vazia(a)){
        return -1;
    }

    return busca_numero_arvore_nao_ordenada_rec(a->raiz, valor);
}