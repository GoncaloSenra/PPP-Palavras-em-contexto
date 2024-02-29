#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "lib-utf8.h"
#include "data_structure.h"

struct no *finder(struct no *root, char *pal);

bool retira_ocorrencias(struct no *node, int *nums);

bool encontra_palavra(struct arvore_binaria *arvbin, char pal[], int *ocorrencias){
    struct no *ppa;
    char nome[MAXTAM];
    int aux_num[1];
    strtobase_u8(nome, pal);

    ppa = finder(arvbin->raiz, nome);

    if (ppa == NULL)
        return false;

    int i = 0;
    while (retira_ocorrencias(ppa, aux_num)){
        ocorrencias[i] = aux_num[0];
        i++;
    }
    ocorrencias[i] = -1;

    return true;
}

struct no *finder(struct no *root, char *pal){
    //esta função procura uma palavra na árvore pelo mesmo método da função addtree
    int aux;
    if (root == NULL)
        return NULL;

    if ((aux = strcmp(root->lst.palavra, pal)) == 0)
        return root;
    else if (aux > 0)
        return finder(root->left, pal);
    else
        return finder(root->right, pal);
}

bool retira_ocorrencias(struct no *node, int *nums){
    //esta função coloca as ocorrências numa matriz de inteiros
    if (node->lst.raiz == NULL)
        return false;

    nums[0] = node->lst.raiz->ocur;
    node->lst.raiz = node->lst.raiz->pseg;
    return true;
}

void contexto (FILE *fich, int nums[MAXTAM]){
    int i = 0;
    char c;
    char frase[MAXFRASE] = "";
    while (nums[i] != -1){
        int j = nums[i];
        int count = 0;
        fseek(fich, j, SEEK_SET);
        while (count < 2){
            //o ciclo "while" continua até encontrar 2 pontos, ou até chegar à posição zero
            if ((c = fgetc(fich)) == '.')
                count++;
            fseek(fich, -2, SEEK_CUR);
            if (ftell(fich) == 0)
                break;
        }
        int k = 0;
        if (count == 0){
            fseek(fich, 0, SEEK_SET);
            do {
                frase[k] = c;
            }while ((c = fgetc(fich)) == '.');
        }else if (count == 1){
            count = 0;
            fseek(fich, 0, SEEK_SET);
            while (count < 2) {
                if ((c = fgetc(fich)) == '.')
                    count++;
                frase[k] = c;
                k++;
            }
        }else {
            count = 0;
            fseek(fich, 2, SEEK_CUR);
            while (count < 2) {
                if ((c = fgetc(fich)) == '.')
                    count++;
                frase[k] = c;
                k++;
            }
        }
        puts(frase);
        printf("#####################\n");
        for (int l = 0; l < MAXFRASE; l++)
            frase[l] = 0;
        i++;
    }
}

