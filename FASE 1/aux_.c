#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib-utf8.h"

#define MAXTAM 100
#define MAXTEXTO 5000


static void reset_string(char *string) {
    for (int i = 0; i < MAXTAM; i++)
        string[i] = 0;
}

void escreve_palavras(FILE *fich, FILE *fichout){
    int i = 0;
    char c;
    unsigned long tam;
    unsigned long tam_total;
    unsigned long pos = 0;
    char palavras[MAXTAM] = "";
    char aux_palavras [MAXTEXTO] = "";
    bool igual = true;
    char c2[MAXTAM];
    //ciclo de repetição que vai retirar as palavras do texto (frase a frase), e colocá-las no ficheiro "idx_texto.txt",
    //e segidamente escrever a posição de cada palavra
    while ((c = fgetc(fich))) {
        if (c != '\n' && c != '\r' && c != '\t' && c != EOF) {
            palavras[i] = c;
            i++;
        } else {
            c2[0] = c;
            strcat(aux_palavras, palavras);
            strcat(aux_palavras, c2);
            tam_total = strlen(aux_palavras);
            tam = strlen(palavras);
            //depois de retirada a frase a função strtok vai separar a frase em palavras, retirando todos os caracteres indesejados
            char *token = strtok(palavras, " []()&,.:;_'?!\"#/0123456789<>«»");
            while (token != NULL) {
                //de seguida o ciclo "for" vai procurar a palavra na frase para poder encontar a posição da primrira letra
                for (int j = 0; j < tam; j++) {
                    if (palavras[j] == token[0]) {
                        for (int k = 0; k < strlen(token); k++) {
                            if (token[k] != palavras[j + k])
                                igual = false;
                        }
                        if (igual == true && strlen_u8(token) > 2)  //apenas as palavras com mais de dois caracteres serão escritas no ficheiro destino
                            fprintf(fichout, "%s;%d\n", token, (int)pos + j);
                            //para obter a verdadeira posição da palavra foi necessário somar a posição da palavra na frase
                            //com o número de bytes de todas as frases anteriores
                        else
                            igual = true;
                        for (int l = 0; l < j + strlen(token); l++){
                            palavras[l] = 0;
                        }
                    }
                }
                token = strtok(NULL, " []()&,.:;_'?!\"#/0123456789<>«»");
            }
            pos = tam_total;
            reset_string(palavras);
            i = 0;
        }

        if (c == EOF)
            break;
    }
}
