/*
 * Trabalho final de Princípios de Programação Procedimental
 * Gonçalo Senra  nº 2020213750
 *
 *             FASE 1
 *
 * Este programa retira todas as palavras de um texto qualquer, e coloca-as noutro
 * ficheiro, "acompanhadas" com a sua posição nesse mesmo texto, separadas por ";".
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXTAM 100
#define MAXTEXTO 5000

void escreve_palavras(FILE *fich, FILE *fichout);

int main() {
    FILE *fich = NULL, *fichout = NULL;
    char nome[MAXTAM] = "";
    char prefix[MAXTAM] = {'i', 'd', 'x', '_'};
    char *aux;
    //ciclo de repetição que vai pedir o noome do ficheiro ao utilizador
    while (true) {
        printf("\nNome do ficheiro: ");
        aux = gets(nome);
        if (aux == NULL) {
            printf("Erro na leitura do nome do ficheiro.\n");
        }
        fich = fopen(nome, "r");
        if (fich == NULL)
            printf("Ficheiro não encontrado.\n");
        else
            break;
    }
    strcat(prefix, nome);
    fichout = fopen(prefix, "w");
    if (fichout == NULL) {
        printf("Ficheiro não encontrado.\n");
        return false;
    }

    escreve_palavras(fich, fichout);

    fclose(fich);
    fclose(fichout);

    return 0;
}
