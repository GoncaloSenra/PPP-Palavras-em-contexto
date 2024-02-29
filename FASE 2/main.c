/*
 * Trabalho final de Princípios de Programação Procedimental
 * Gonçalo Senra  nº 2020213750
 *
 *             FASE 2
 *
 * Este programa organiza as palavras fornecidas pela fase 1, numa árvore binária e posteriormente
 * permite que utilizador peça ao programa para ecrever uma determinada palavra em contexto, ou seja,
 * o programa vai procurar todas as ocorrências dessa palavra e escrever tanto a frase em que a mesma está contida,
 * como a frase anterior. Para além disso, o utilizador pode dar ao programa um conjunto de letras, e o programa devolverá
 * todas as palavras que comecem por essas letras.
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "lib-utf8.h"
#include "data_structure.h"

#define MAXTAM 100
#define MAXFRASE 1000


int main(){
    FILE *fich, *fichout;
    char nome[MAXTAM];
    char prefix[MAXTAM] = {'i', 'd', 'x', '_'};
    char *aux;


    while (true) {
        printf("\nNome do ficheiro: ");
        aux = fgets(nome, MAXTAM, stdin);
        if (aux == NULL) {
            fprintf(stderr, "Erro na leitura do nome do ficheiro.\n");
        }
        nome[strlen(nome) - 1] = '\0';
        fich = fopen(nome, "r");
        if (fich == NULL)
            printf("Ficheiro não encontrado.\n");
        else
            break;
    }
    strcat(prefix, nome);
    fichout = fopen(prefix, "r");
    if (fichout == NULL) {
        printf("Ficheiro não encontrado.\n");
        perror("Erro");
        return false;
    }

    char linha[MAXTAM] = "";
    char word[MAXTAM] = "";
    struct arvore_binaria arvbin;
    struct lista lst;
    struct no_lista node;
    inicializar(&arvbin, &lst);

    //ciclo de repetição que vai
    while (!feof(fichout)){
        fgets(linha, MAXTAM, fichout);
        char *token = strtok(linha, ";\n\r\t");
        while(token != NULL){
            if (token[0] >= '0' && token[0] <= '9')
                node.ocur = atoi(token);
            else
                strtobase_u8(lst.palavra, token);
            token = strtok(NULL, ";\n\r\t");
        }
        colocar_palavra(&arvbin, lst, node);
        for (int i = 0; i < MAXTAM; i++) {
            lst.palavra[i] = 0;
            word[i] = 0;
        }

    }
    //ciclo de repetição responsável pela apresentação do menu
    while (true){
        int opt;
        char palavra[MAXTAM] = "";
        char palavra_base[MAXTAM] = "";
        printf("\n1 - Palavra em contexto\n"
               "2 - Lote de palavras\n"
               "3 - Sair\n"
               "Opção: ");
        opt = getchar();
        getchar();

        if (opt == '1'){
            int ocorr[MAXTAM];
            printf("\nPalavra: ");
            gets(palavra);
            strtobase_u8(palavra_base, palavra);
            if (!encontra_palavra(&arvbin, palavra_base, ocorr)) {
                printf("Palavra não encontrada!\n");
                continue;
            }
            contexto(fich, ocorr);
        }else if (opt == '2'){
            printf("\nPalavra: ");
            gets(palavra);
            strtobase_u8(palavra_base, palavra);
            lote_palavras(&arvbin, palavra_base);
        }else if (opt == '3')
            return 0;
        else{
            printf("Escolha uma opção válida!\n");
            while(getchar() != '\n');
            continue;
        }
    }

}