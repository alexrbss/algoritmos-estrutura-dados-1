#include <stdio.h>

typedef struct {
    float preco;
    char local[20];
    char atracao[20];
}Ingresso;

void preenche(Ingresso *i) {
    printf("Informe o preco do ingresso: ");
    scanf("%f", &i->preco);

    printf("Informe o local do evento: ");
    scanf(" %[^\n]", i->local);

    printf("Informe a atracao do evento: ");
    scanf(" %[^\n]", i->atracao);
}

void imprime(Ingresso *i) {
    printf("Preco: R$ %.2f\n", i->preco);
    printf("Local: %s\n", i->local);
    printf("Atracao: %s\n", i->atracao);
}

void altera_preco(Ingresso *i, float valor) {
    i->preco = valor;
}

void imprime_menor_maior_preco(int n, Ingresso *vet) {
    Ingresso menorPreco = vet[0];
    Ingresso maiorPreco = vet[0];

    for (int i = 1; i < n; i++) {
        if (vet[i].preco < menorPreco.preco) {
            menorPreco = vet[i];
        }
        if (vet[i].preco > maiorPreco.preco) {
            maiorPreco = vet[i];
        }
    }

    printf("\nEvento de Ingresso Mais Barato:\n");
    imprime(&menorPreco);

    printf("\nEvento de Ingresso Mais Caro:\n");
    imprime(&maiorPreco);
}

int main() {
    
    int quantidadeIngressos;

    printf("Informe a quantidade ingressos para cadastro: ");
    scanf("%d", &quantidadeIngressos);

    Ingresso vetorIngressos[quantidadeIngressos];

    for (int i = 0; i < quantidadeIngressos; i++) {
        printf("\n----- Ingresso %d -----\n", i + 1);
        preenche(&vetorIngressos[i]);
    }

    printf("\n----- Detalhes dos Ingressos -----\n");
    for (int i = 0; i < quantidadeIngressos; i++) {
        imprime(&vetorIngressos[i]);
    }

    float novoPreco;
    printf("\nInforme o novo preço para o primeiro ingresso: ");
    scanf("%f", &novoPreco);
    altera_preco(&vetorIngressos[0], novoPreco);

    printf("\n--- Detalhes dos Ingressos após alteração ---\n");
    for (int i = 0; i < quantidadeIngressos; i++) {
        imprime(&vetorIngressos[i]);
    }

    imprime_menor_maior_preco(quantidadeIngressos, vetorIngressos);

    return 0;

}
