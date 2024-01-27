#include <stdio.h>

typedef struct ingresso {
    float preco;
    char local[20];
    char atracao[20];
}Ingresso;

void preenche(Ingresso *i) {
    printf("Informe o valor do ingresso: ");
    scanf("%f", &i->preco);

    printf("\nInforme o local do show: ");
    scanf(" %[^\n]", i->local);

    printf("\nInforme a atração: ");
    scanf(" %[^\n]", i->atracao);
}

void imprime(Ingresso *i) {
    printf("Valor do Ingresso: R$%.2f \nLocal do Show: %s \nAtração: %s");
}

void altera_preco(Ingresso *i, float novo_preco) {
    i->preco = novo_preco;
}

void imprime_menor_maior_preco(int n, Ingresso *vet) {
      
} 