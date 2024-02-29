#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "data_structure.h"

struct no *addtree(struct no *root, struct no *n, struct no_lista node);

bool colocar_ocorrencia(struct lista *lst, struct no_lista node);

bool colocar_palavra(struct arvore_binaria *arvbin, struct lista lst, struct no_lista node){
    //esta função cria un novo nó e adiciona-o à árvore binária através da fução addtree
    struct no *n;
    n = (struct no *) malloc(sizeof (struct no));
    if (n == NULL)
        return false;
    n->lst = lst;
    n->left = NULL;
    n->right = NULL;
    arvbin->raiz = addtree(arvbin->raiz, n, node);

    return true;
}

struct no *addtree(struct no *root, struct no *n, struct no_lista node){
    //esta função vai criando recursivamente sub-árvores mediante a orrdem alfabética
    int comp;
    if (root == NULL){
        root = n;
        colocar_ocorrencia(&root->lst, node);
    }else {
        if ((comp = strcmp(n->lst.palavra, root->lst.palavra)) > 0)
            root->right = addtree(root->right, n, node);
        else if ((comp = strcmp(n->lst.palavra, root->lst.palavra)) < 0)
            root->left = addtree(root->left, n, node);
        else{
            colocar_ocorrencia(&root->lst, node);
            return root;
        }
    }

    return root;
}

bool colocar_ocorrencia(struct lista *lst, struct no_lista node){
    //esta função coloca a ocorrência na lista ligada que se encontra no nó da árvore
    struct no_lista *auxnode, *ant, *seg;
    //cria novo nó
    auxnode = (struct no_lista *) malloc(sizeof(struct no_lista));
    if (auxnode == NULL)
        return false;

    auxnode->ocur = node.ocur;
    auxnode->pseg = NULL;

    if (lst->raiz == NULL){
        //inicio
        lst->raiz = auxnode;
    }else{
        if (lst->raiz->ocur > auxnode->ocur){
            auxnode->pseg = lst->raiz;
            lst->raiz = auxnode;
        }else{
            ant = lst->raiz;
            seg = lst->raiz->pseg;
            while (seg != NULL && seg->ocur < auxnode->ocur){
                ant = seg;
                seg = seg->pseg;
            }
            if (seg == NULL){
                //fim
                ant->pseg = auxnode;
            }else{
                //meio
                ant->pseg = auxnode;
                auxnode->pseg = seg;
            }
        }
    }

    return true;
}

void inicializar (struct arvore_binaria *arvbin, struct lista *lst){
    arvbin->raiz = NULL;
    lst->raiz = NULL;
}


