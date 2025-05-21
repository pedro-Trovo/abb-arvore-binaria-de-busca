#include <time.h>
#include "../include/abb.h"

int main(){
    printf("\n\n\n\n\n");
    srand(time(0));

    t_abb abb;
    inicializa_abb(&abb);

    printf("Valores inseridos na arvore: ");
    for(int i=1; i<=12; i++){
        int n = rand() % 100;
        printf("%d ", n);

        insere(n, &abb);
    }

    printf("\n\n");

    printf("Exibicao da Arvore em ordem: ");
    exibe_in_order(&abb);
    printf("\n");

    printf("Exibicao da Arvore em ordem reversa: ");
    exibe_rev_order(&abb);
    printf("\n");

    printf("Exibicao da Arvore em pre ordem: ");
    exibe_pre_order(&abb);

    printf("\n\nMaior valor (arvore ordenada): %d\n", exibe_maior(&abb));
    printf("Maior valor (arvore NAO ordenada): %d\n", exibe_maior_arvore_nao_ordenada(&abb));
    printf("Profundidade da Arvore: %d\n", exibe_profundidade(&abb));
    printf("Quantidade de Nos na Arvore: %d\n", exibe_qtd_nos(&abb));
    printf("Quantidade de Nos nao-folha na Arvore: %d\n", exibe_qtd_nos_nao_folha(&abb));
    printf("Quantidade de Nos folha na Arvore: %d\n", exibe_qtd_nos_folha(&abb));

    int valor=0;
    printf("\n\nDigite um numero: ");
    scanf("%d", &valor);
    if(busca_numero_arvore_nao_ordenada(&abb, valor) != -1){
        printf("\nNumero encontrado!\n");
    }
    else{
        printf("\nNumero nao encontrado!\n");
    }


    printf("\n\n\n\n\n");
    return 0;
}