#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo union Genero
typedef union {
    char masculino[20];
    char feminino[20];
}Genero;

//definindo struct Pessoa
typedef struct {
    char nome[50];
    int idade;
    char genero[20]; //string para representar o gênero
    Genero generoUser;
}Pessoa;

//lendo os dados da pessoa
void lerDados(Pessoa *pessoa) {
    printf("Informe o nome: ");
    scanf(" %[^\n]", pessoa->nome);

    printf("Informe a idade: ");
    scanf("%d", &pessoa->idade);

    printf("Informe o genero (MASCULINO ou FEMININO): ");
    scanf(" %[^\n]", pessoa->genero);
}

//imprimindo os dados da pessoa
void imprimeDados(const Pessoa *pessoa) {
    printf("\n----- DADOS PESSOAIS -----\n");
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);

    //imprimindo o gênero com base na escolha feita
    if (strcmp(pessoa->genero, "MASCULINO") == 0) {
        printf("Genero: Masculino\n");
    } else if (strcmp(pessoa->genero, "FEMININO") == 0) {
        printf("Genero: Feminino\n");
    }
}

int main() {
    //alocando dinamicamente uma variável do tipo Pessoa
    Pessoa *usuario = (Pessoa *)malloc(sizeof(Pessoa));

    //verifcando se a alocação foi bem-sucedida
    if (usuario == NULL) {
        printf("Erro de alocação de memoria.\n");
        return 1;
    }

    lerDados(usuario);
    imprimeDados(usuario);

    //liberando memória
    free(usuario);

    return 0;
}
