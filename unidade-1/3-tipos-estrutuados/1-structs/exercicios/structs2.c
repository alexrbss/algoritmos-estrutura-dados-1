#include <stdio.h>
#include <stdlib.h>

struct professores {
    char nome [20];
    char email [50];
    char disciplina[50];
    int matricula;
};
    
void preenche(struct professores * docente){
    printf("Digite o nome do professor: ");
    scanf(" %[^\n]", docente->nome);
    
    printf("Digite o email do professor: ");
    scanf(" %[^\n]", docente->email);
    
    printf("Digite a disciplina: ");
    scanf(" %[^\n]", docente->disciplina);
    
    printf("Digite a matricula do professor ");
    scanf("%d", &docente->matricula);

    printf("\n");
}

void imprime(struct professores * docente){
    printf("Nome: %s \nEmail: %s \nDisciplina: %s \nMatricula: %d", docente->nome, docente->email, docente->disciplina, docente->matricula);
    }

int main(){
    struct professores *docente = (struct professores*) malloc(sizeof(struct professores));
    
    if(docente == NULL){
        exit(1);
    }
    
    preenche(docente);
    imprime(docente);
    
    free(docente);
    
    return 0;
}