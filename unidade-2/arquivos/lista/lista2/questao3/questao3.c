#include <stdio.h>
#include <stdlib.h>

struct fruta {
    char nome[100]; 
    float preco;    
} Fruta;

void solicitaDados(struct fruta *Fruta) {
    printf("Nome: ");
    scanf("%s", Fruta->nome);
    printf("Preco: R$");
    scanf("%f", &Fruta->preco);
}

void escreveArquivo(struct fruta *Frutas, int numFrutas) {
    FILE *arquivo = fopen("frutas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    for (int index = 0; index < numFrutas; index++) {
        fprintf(arquivo, "%s,%.2f\n", Frutas[index].nome, Frutas[index].preco);
    }

    fclose(arquivo);
}

int main() {
    int numFrutas; 

    printf("Quantas frutas você deseja cadastrar? ");
    scanf("%d", &numFrutas);

    struct fruta *Frutas = (struct fruta *)malloc(numFrutas * sizeof(struct fruta));

    for (int index = 0; index < numFrutas; index++) {
        printf("\nFruta %d:\n", index + 1);
        solicitaDados(&Frutas[index]);
    }

    escreveArquivo(Frutas, numFrutas);

    free(Frutas);

    printf("\nDados salvos no arquivo \"frutas.txt\".\n");
    printf("Encerrando o programa.\n");

    return 0;
}
