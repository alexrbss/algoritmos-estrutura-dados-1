#include <stdio.h>

#define CHAR_MAX 20

//enum para representar os tipos de produto
typedef enum {
    ALIMENTO,
    BEBIDA,
    ELETRONICO
}Categoria;

//union para armazenar os detalhes específicos de cada tipo de produto
typedef union {
    char tipoAlimento[CHAR_MAX];
    char tipoBebida[CHAR_MAX];
    char tipoEletronico[CHAR_MAX];
}Tipo;

//struct para representar um produto
typedef struct {
    char nome[30];
    float preco;
    Categoria tipo;
    Tipo especificacao;
}Produto;

//lendo os dados de um produto
void lerDados(Produto *produtoUser) {
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", produtoUser->nome);

    printf("Informe o preco do produto: ");
    scanf("%f", &produtoUser->preco);

    printf("Informe o tipo do produto:\n0 - ALIMENTO\n1 - BEBIDA\n2 - ELETRONICO\n");
    scanf("%d", (int*)&produtoUser->tipo);
}

//imprimindo os dados de um produto
void imprimeDados(const Produto *produto) {
    printf("\n----- DADOS DO PRODUTO -----\n");
    printf("Nome: %s\n", produto->nome);
    printf("Preco: R$ %.2f\n", produto->preco);

    //imprimindo os detalhes específicos com base no tipo de produto
    switch (produto->tipo) {
        case ALIMENTO:
            printf("Tipo: Alimento\n");
            break;

        case BEBIDA:
            printf("Tipo: Bebida\n");
            break;

        case ELETRONICO:
            printf("Tipo: Eletronico\n");
            break;

        default:
            printf("Tipo de produto invalido!\n");
            break;
    }
}

int main() {
    Produto produtoUser;

    lerDados(&produtoUser);

    imprimeDados(&produtoUser);

    return 0;
}
