#include <stdio.h>
#define TAM 10 // tamanho do vetor

int main() {
    int vetor[TAM];
    int menor, maior;
    float soma = 0;
    int index;

    FILE *entrada = fopen("entrada_q2.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    for (index = 0; index < TAM; index++) {
        fscanf(entrada, "%d", &vetor[index]);
        soma += vetor[index]; 
    }

    fclose(entrada);

    menor = maior = vetor[0];

    for (index = 1; index < TAM; index++) {
        if (vetor[index] < menor) {
            menor = vetor[index];
        }
        if (vetor[index] > maior) {
            maior = vetor[index];
        }
    }

    float media = soma / TAM;

    FILE *saida = fopen("saida_q2.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return 1;
    }

    // Escrever os resultados no arquivo de saída
    fprintf(saida, "Menor elemento: %d\n", menor);
    fprintf(saida, "Maior elemento: %d\n", maior);
    fprintf(saida, "Média dos elementos: %.2f\n", media);

    // Fechar o arquivo de saída
    fclose(saida);

    printf("Resultados escritos no arquivo saida_q2.txt.\n");

    return 0;
}
