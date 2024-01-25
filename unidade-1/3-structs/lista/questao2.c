#include <stdio.h>
#include <stdlib.h>
#define CHAR_MAX 30

typedef struct pessoa {
    char nome[CHAR_MAX];
    float documento;
    int idade;
} dadosPessoais;

void preenche(dadosPessoais *dadosUser) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", dadosUser->nome);

    printf("Digite o numero do documento: ");
    scanf("%.0f", &dadosUser->documento);

    printf("Digite o idade: ");
    scanf("%d", &dadosUser->idade);

    printf("\n");
}

void imprime(dadosPessoais *dadosUser) {
    printf("Nome: %s\n", dadosUser->nome);
    printf("Documento: %.0f\n", dadosUser->documento);
    printf("Idade: %d\n\n", dadosUser->idade);
}

void idadeMaior(dadosPessoais *dadosUser, int num_pessoas) {
    int maior_idade = dadosUser[0].idade;
    int id_pessoa = 0;

    for (int i = 1; i < num_pessoas; i++) {
        if (dadosUser[i].idade > maior_idade) {
            maior_idade = dadosUser[i].idade;
            id_pessoa = i;
        }
    }

    printf("Nome da pessoa mais velha: %s\n", dadosUser[id_pessoa].nome);
}

void idadeMenor(dadosPessoais *dadosUser, int num_pessoas) {
    int menor_idade = dadosUser[0].idade;
    int id_pessoa = 0;

    for (int i = 1; i < num_pessoas; i++) {
        if (dadosUser[i].idade < menor_idade) {
            menor_idade = dadosUser[i].idade;
            id_pessoa = i;
        }
    }

    printf("Nome da pessoa mais nova: %s\n", dadosUser[id_pessoa].nome);
}

int main() {
    int num_pessoas;

    printf("Digite o numero de pessoas a serem cadastradas: ");
    scanf("%d", &num_pessoas);

    dadosPessoais *dadosUser = (dadosPessoais *)malloc(num_pessoas * sizeof(dadosPessoais));

    if (dadosUser == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("\n----- INFORMACOES PESSOAIS -----\n");
    for (int i = 0; i < num_pessoas; i++) {
        preenche(&dadosUser[i]);
    }

    printf("\n----- DADOS DAS PESSOAS -----\n");
    for (int i = 0; i < num_pessoas; i++) {
        imprime(&dadosUser[i]);
    }

    printf("\n----- IDADES -----\n");
    idadeMaior(dadosUser, num_pessoas);
    idadeMenor(dadosUser, num_pessoas);

    free(dadosUser);

    return 0;
    
}
