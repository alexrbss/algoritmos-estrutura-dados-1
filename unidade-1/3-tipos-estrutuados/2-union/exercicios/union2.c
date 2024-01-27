#include <stdio.h>
#include <stdlib.h>

//estrutura do tipo union para armazenar um documento
typedef union documentos{
    char rg[15];
    char cpf[15];
}Documentos;

typedef struct pessoa {
    char nome[20];
    int idade;
    Documentos doc; //variável para armazenar o CPF ou RG
}Pessoa;

void dados_pessoais(Pessoa *p) {
    printf("Informe o nome: ");
    scanf(" %[^\n]", p->nome);

    printf("Informe a idade: ");
    scanf("%d", &p->idade);

    printf("\n");
    
    int opcao;

    printf("Digite 1 para CPF ou 0 para RG\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Informe o CPF: ");
        scanf(" %[^\n]", p->doc.cpf);
    } else {
        printf("Informe o RG: ");
        scanf(" %[^\n]", p->doc.rg);
    }
}

int main(void) {

    Pessoa *pessoa = malloc(sizeof(Pessoa));
    
    dados_pessoais(pessoa); //a função recebe o endereço da variável

    printf("CPF = %s \nRG = %s", pessoa->doc.cpf, pessoa->doc.rg);

    free(pessoa); 

    return 0;

}