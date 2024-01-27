#include <stdio.h>

typedef enum genero{
    masculino,
    feminino
}Genero;

typedef struct pessoa{
    char nome[20];
    int idade;
    Genero genero_pessoa;
}Pessoa;

void get_dados(Pessoa *pessoa) {
    //função que preenche os dados de uma pessoa
    printf("Informe o nome: ");
    scanf(" %[^\n]", pessoa->nome);

    printf("Informe a idade: ");
    scanf("%d", &pessoa->idade);

    printf("Informe o genero: \n0 - Masculino \n1 - Feminino\n");
    scanf("%d", &pessoa->genero_pessoa);
}

void imprime_pessoa(Pessoa *pessoa) {
    printf("\nNome: %s \nIdade: %d \nGenero: %s", pessoa->nome, pessoa->idade, pessoa->genero_pessoa==masculino?"Masculino":"Feminino");
}

int main() {
    //Pessoa *pessoa = malloc(sizeof(Pessoa));

    Pessoa * pessoa_;
    get_dados(&pessoa_);
    imprime_pessoa(&pessoa_);

    //free(pessoa);

    return 0;
}