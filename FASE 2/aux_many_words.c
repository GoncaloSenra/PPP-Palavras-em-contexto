#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "data_structure.h"

bool no_seguinte(struct arvore_binaria * arvbin, struct lista * lst);

struct no *find_next(struct no *root, char *ant, struct no *aux_node);

void lote_palavras(struct arvore_binaria *pa, char pal[MAXTAM]) {
    //esta função escreve todas as palavras que começem com as letras fornecidas pelo utilizador
    struct lista lst;
    char *c;
    int count = 0;
    lst.palavra[0] = 0;
    while (no_seguinte(pa, &lst)) {
        //a palavra só é printada se e só se pal esteja contida na palavra encontrada (strstr)
        //e se pal corresponder às primeiras letras da palavra
        if (((c = strstr(lst.palavra, pal)) != NULL) && (strcmp(lst.palavra, c) == 0)) {
            printf("%s\n", lst.palavra);
            count++;
        }
    }
    if (count == 0)
        printf("Não houve correspondência!\n");
}

bool no_seguinte(struct arvore_binaria * arvbin, struct lista * lst) {
    struct no *node;
    node = find_next(arvbin->raiz, lst->palavra, NULL);
    if (node == NULL)
        return false;
    //caso a árvore tenha "chegado ao fim" retorna falso
    *lst = node->lst;

    return true;
}

struct no *find_next(struct no *root, char *ant, struct no *aux_node) {
    //encontra um nó "ideal" cujo nó seguinte seja nulo
    if (root == NULL)
        return aux_node;

    if (strcmp(ant, root->lst.palavra) >= 0)
        return find_next(root->right, ant, aux_node);
    else
        return find_next(root->left, ant, root);
}
