#include <stdio.h>
#include <stdlib.h>

//estrutura para armazenar um documento
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
    /* função que preenche os dados de uma variável do tipo pessoa (struct) */
    printf("Informe o nome: \t");
    scanf(" %[^\n]", p->nome);

    printf("\nInforme a idade: \t");
    scanf("%d", &p->idade);

    int opcao;

    printf("Digite 1 para CPF ou 0 para RG\n");
    scanf("%d", &opcao);

    if(opcao == 1) {
        scanf(" %[^\n]", p->doc.cpf);
    } else {
        scanf(" %[^\n]", p->doc.rg);
    }
}

int main(void) {

    Pessoa *pessoa = malloc(sizeof(Pessoa));
    dados_pessoais(pessoa); //a função recebe o endereço da variável

    printf("CPF = %s \n RG = %s", pessoa->doc.cpf, pessoa->doc.rg);

    free(pessoa); 

    return 0;

}

//estrutura union 
// typedef union tipodados {
//     int meu_int;
//     float meu_float;
// }Dados;

// int main(void) {

//     Dados uniao;
//     printf("Digite os dados: \t");
//     scanf("%f %d", &uniao.meu_int, &uniao.meu_float);

//     printf("Os dados informados: meu_int = %d meu float = %f", uniao.meu_int, uniao.meu_float);

//     return 0;
// }