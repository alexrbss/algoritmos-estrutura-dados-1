#include <stdio.h>
#define CHAR_MAX 20

//union para armazenar os detalhes específicos de cada tipo de produto
typedef union {
    char ALIMENTO[CHAR_MAX];
    char BEBIDA[CHAR_MAX];
    char ELETRONICO[CHAR_MAX];
}Tipo;

//struct para representar um produto
typedef struct {
    char nome[30];
    float preco;
    int tipo; 
    Tipo especificacao;
}Produto;

//lendo os dados de um produto
void lerDados(Produto *produtoUser) {
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", produtoUser->nome);

    printf("Informe o preco do produto: ");
    scanf("%f", &produtoUser->preco);

    printf("Informe o tipo do produto \n0 - ALIMENTO \n1 - BEBIDA \n2 - ELETRONICO\n");
    scanf("%d", &produtoUser->tipo);

}

//imprimindo os dados de um produto
void imprimeDados(const Produto *produto) {
    printf("\n----- DADOS DO PRODUTO -----\n");
    printf("Nome: %s\n", produto->nome);
    printf("Preco: R$ %.2f\n", produto->preco);

    //imprimindo os detalhes específicos com base no tipo de produto
    switch (produto->tipo) {
        case 0:
            printf("Tipo: Alimento\n", produto->especificacao.ALIMENTO);
            break;

        case 1:
            printf("Tipo: Bebida\n", produto->especificacao.BEBIDA);
            break;

        case 2:
            printf("Tipo: Eletronico\n", produto->especificacao.ELETRONICO);
            break;

        default:
            printf("Tipo de produto inválido!\n");
            break;
    }
}

int main() {
    
    Produto produtoUser;

    lerDados(&produtoUser);

    imprimeDados(&produtoUser);

    return 0;
}