#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome [20];
    int idade;
    int matricula; 
    char email [50];
};
    
void preenche(struct aluno *estudante){
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", estudante->nome); 
    
    printf("Digite a idade: ");
    scanf("%d", &estudante->idade);
    
    printf("Digite a matricula: ");
    scanf("%d", &estudante->matricula);
    
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante->email);

    printf("\n");
}

void imprime(struct aluno *estudante){
    printf("Nome: %s \nIdade: %d \nMatricula: %d \nEmail: %s", estudante->nome, estudante->idade, estudante->matricula, estudante->email);
}

int main(){
    
    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));
    
    if(estudante == NULL){
        exit(1);
    }
    
    preenche(estudante);
    imprime(estudante);
    
    free(estudante);
    
    return 0;
}