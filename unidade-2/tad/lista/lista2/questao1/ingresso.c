#include <stdio.h>
#include <stdlib.h>

typedef struct ingresso{
    float preco;
    char local[50];
    char atracao[50];
} Ingresso;

void preenche(Ingresso * i) {
    printf("Informe o preco: \t");
    scanf("%f", &i->preco);
    printf("Informe o local: \t");
    scanf(" %[^\n]", i->local);
    printf("Informe a atracao: \t");
    scanf(" %[^\n]", i->atracao);
}

void imprime(Ingresso * i){
    printf("Nome: %.2f\t\n", i->preco);
    printf("Local: %s\t\n", i->local);
    printf("Atracao: %s\t\n", i->atracao);
}

void altera_preco(Ingresso * i, float valor){
    i->preco = valor;
    printf("Novo valor: %.2f \n", i->preco);
}

void imprime_maior_e_menor(int n, Ingresso * vet){
    int contador;
    float maior = 0;
    float menor = vet[0].preco;

    for (contador = 0; contador < n; contador++){
        if (vet[contador].preco > maior){
            maior = vet[contador].preco;
        }
        if (vet[contador].preco < menor){
            menor = vet[contador].preco;
        }
    }
    
    printf("\nMenor valor: %.2f \nMaior valor: %.2f", menor, maior );
}