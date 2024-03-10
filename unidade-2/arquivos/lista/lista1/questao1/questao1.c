#include <stdio.h>

int main() {
    FILE *entrada;
    FILE *saida;
    char nome[50];
    float nota1, nota2, nota3, media;

    entrada = fopen("entrada_q3.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    saida = fopen("saida_q3.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        fclose(entrada);
        return 1;
    }

    while (fscanf(entrada, "%s\t%f\t%f\t%f", nome, &nota1, &nota2, &nota3) != EOF) {
        media = (nota1 + nota2 + nota3) / 3.0;
        fprintf(saida, "%s\t%.1f\t%s\n", nome, media, (media >= 7.0) ? "Aprovado" : "Reprovado");
    }

    fclose(entrada);
    fclose(saida);

    printf("Resultados gravados no arquivo \"saida_q3.txt\".\n");

    return 0;
}