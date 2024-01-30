#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fp;

    //cria o arquivo: entrada_escrita.txt no modo "w" write
    fp = fopen("entrada_escrita.txt", "w");

    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    } else {
        printf("O arquivo foi criado!\n");
    }

    fputs("Hello world!", fp);

    //função para fechar o arquivo criado
    if (!fclose(fp)) {
        printf("Arquivo fechado com sucesso!\n");
    } 

    return 0;
}