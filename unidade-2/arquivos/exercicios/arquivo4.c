#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fp;

    fp = fopen("entrada.txt", "r");
    char c[20];

    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    } else {
        printf("O arquivo foi criado!\n");
    }

    fscanf(fp, "%s", c);
    printf("%s\n", c);

    //função para fechar o arquivo criado
    if (!fclose(fp)) {
        printf("Arquivo fechado com sucesso!\n");
    } 

    return 0;
}