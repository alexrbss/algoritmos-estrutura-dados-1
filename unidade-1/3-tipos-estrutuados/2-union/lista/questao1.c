#include <stdio.h>
#include <stdlib.h>

typedef union genero{
    char masculino[20];
    char feminino[20];
}Genero;

typedef struct pessoa {
    char nome[20];
    int idade;
    Genero genero;
}Pessoa;

void lerDados(Pessoa *pessoaUser) {
    printf("Informe o nome: ");
    scanf(" %[^\n]", pessoaUser->nome);

    printf("Informe a idade: ");
    scanf("%d", pessoaUser->idade);

    int opcao;

    printf("Informe o genero: ");
    printf("1 - MASCULINO \n 2 - FEMININO\n");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
        scanf(" %[^\n]", pessoaUser->genero.masculino);

    case 2:
        scanf(" %[^\n]", pessoaUser->genero.feminino);
        break;
    
    default:
        printf("Opcao Invalida!\n");
        break;
    }
}

int main() {

    Pessoa *pessoaUser = malloc(sizeof(Pessoa));
    lerDados(pessoaUser);

    printf("Nome: %s \nIdade: %d \nGenero: %s\n", pessoaUser->nome, pessoaUser->idade, pessoaUser->genero);

    free(pessoaUser);

    return 0;

}