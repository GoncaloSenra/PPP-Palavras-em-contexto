# Palavras em Contexto - Projeto de Príncipios de Programação Procedimental (PPP)

Este projeto foi desenvolvido como parte do currículo da disciplina de Príncipios de Programação Procedimental (PPP).

## Enunciado

O objetivo deste projeto é criar um sistema capaz de procurar palavras em um texto em português codificado em utf-8 e exibi-las em contexto. O trabalho consiste em duas fases, cada uma implementada por um programa independente:

### Primeira Fase:
- O programa solicita ao utilizador o nome do arquivo de texto a ser processado.
- Em seguida, percorre o arquivo de texto, isolando cada palavra e registrando a posição em que a palavra aparece no texto (número de bytes desde o início do arquivo onde a palavra começa).
- As palavras consideradas são aquelas compostas apenas por letras e hífenes, ignorando todos os outros caracteres.
- Somente palavras com mais de dois caracteres são consideradas.
- Cada palavra identificada é escrita em um arquivo, preservando maiúsculas/minúsculas, acentos e cedilhas, acompanhada de sua posição no texto.
- O nome do arquivo onde as palavras são escritas segue o padrão: "idx_" + nome do arquivo de texto.

### Segunda Fase:
- O programa solicita ao utilizador o nome do arquivo de texto.
- Um arquivo com os pares palavra-posição é lido, seguindo a mesma lógica da primeira fase.
- O programa então constrói um índice na forma de uma árvore binária, onde cada nó contém uma lista ligada com todas as posições em que a palavra ocorre.
- Palavras com diferenças apenas em acentos, cedilhas ou maiúsculas/minúsculas são consideradas iguais.
- O índice é construído utilizando memória dinâmica.
- Para cada palavra escolhida pelo utilizador, todas as ocorrências são exibidas em seu contexto, por ordem crescente de posição no arquivo.
- O contexto consiste na frase em que a palavra está presente, juntamente com a frase anterior (as frases são delimitadas pelo caractere '.').
- O texto não é lido integralmente para a memória; em vez disso, a posição de cada palavra no índice é utilizada para ler diretamente do arquivo de texto a parte a ser exibida como contexto.
- O utilizador também pode solicitar a listagem de todas as palavras que começam por uma determinada letra ou intervalo de letras, sem repetições ou contexto.

## Execução dos Programas

### Fase 1
* gcc -std=c11 main.c lib-utf8.c aux_.c -o [nome do executável]

### Fase 2
* gcc -std=c11 main.c lib-utf8.c data_structure.h aux_structure.c aux_context.c aux_many_words.c -o [nome do executável]

## Autores

Este projeto foi desenvolvido por [GoncaloSenra](https://github.com/GoncaloSenra).


