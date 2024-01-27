#include <stdio.h>
#include <stdlib.h>

struct funcionario {
    char nome[20];
    char cargo[20];
    int rg;
};

void preenche(struct funcionario *servidor){
    printf("Funcionarios publicos\n");
    
    printf("Digite o nome: ");
    scanf(" %[^\n]", servidor->nome);
    
    printf("Digite o cargo: ");
    scanf(" %[^\n]", servidor->cargo);
    
    printf("Digite o RG: ");
    scanf("%i", &servidor->rg);

    printf("\n");
}

void imprime(struct funcionario *servidor){
    printf("Nome: %s\n", servidor->nome);
    printf("Cargo: %s\n", servidor->cargo);
    printf("RG: %i\n", servidor->rg);
}

int main(){
    
    struct funcionario *servidor = (struct funcionario*) malloc(sizeof(struct funcionario));

    if(servidor == NULL){
        exit(1);
    }

    preenche(servidor);
    imprime(servidor);

    free(servidor);
    
    return 0;
}