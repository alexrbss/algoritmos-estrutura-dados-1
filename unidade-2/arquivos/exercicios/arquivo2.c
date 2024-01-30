#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fp;

    fp = fopen("entrada.txt", "r");
    int c;

    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    } else {
        printf("O arquivo foi criado!\n");
    }

    c = fgetc(fp); //lendo um caracter do arquivo
    printf("%c\n", c); //imprimindo o caractere lido

    //função para fechar o arquivo criado
    if (!fclose(fp)) {
        printf("Arquivo fechado com sucesso!\n");
    } 

    return 0;
}