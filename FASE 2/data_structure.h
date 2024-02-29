#include <stdio.h>
#include <stdbool.h>

#define MAXTAM 100
#define MAXFRASE 1000

struct no_lista {
    int ocur;
    struct no_lista * pseg;
};

struct lista {
    struct no_lista * raiz;
    char palavra[MAXTAM];
};

struct no {
    struct lista lst;
    struct no *left;
    struct no *right;
};

struct arvore_binaria {
    struct no * raiz;
};

bool colocar_palavra(struct arvore_binaria *arvbin, struct lista lst, struct no_lista node);

bool encontra_palavra(struct arvore_binaria *arvbin, char pal[], int *ocorrencias);

void contexto (FILE *fich, int nums[MAXTAM]);

void lote_palavras(struct arvore_binaria *pa, char pal[MAXTAM]);

void inicializar (struct arvore_binaria *arvbin, struct lista *lst);
