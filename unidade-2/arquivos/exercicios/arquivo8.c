#include <stdio.h>

int main() {
    int c;
    int nlinhas = 0; //contador do numero de linhas
    FILE *fp;

    //abrindo arquivo para leitura
    fp = fopen("entrada.txt", "rt");
    if (fp == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    //lendo caractere a caractere
    //End Of File = constante que indica o final do arquivo
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n');
            nlinhas++;
    }

    //fechando o arquivo
    fclose(fp);

    //exibindo o resultado na tela
    printf("Numero de linhas = %d\n", nlinhas);

    return 0;
}