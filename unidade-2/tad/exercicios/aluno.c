#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[20];
    int matricula;
    float IRA;
};

Aluno * recebe_dados(){
    Aluno * estudante = (Aluno *) malloc(sizeof(Aluno));

    if (estudante == NULL){
        printf("Sem memória!\n");
        exit(1);
    }

    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", estudante->nome); 
    
    printf("Informe a matrícula do aluno: ");
    scanf("%d", &estudante->matricula);

    printf("Informe o IRA do aluno: ");
    scanf("%f", &estudante->IRA);

    return estudante;
}

void imprime(Aluno * estudante){
    printf("Nome: %s\n", estudante->nome);
    printf("Matrícula: %d\n", estudante->matricula);
    printf("IRA: %.2f\n", estudante->IRA);
}

void libera(Aluno * estudante){
    free(estudante);
}

Aluno ** matricula(int quantidade){
    
    Aluno ** estudantes = (Aluno **) malloc(quantidade * sizeof(Aluno *));

    if (estudantes == NULL){
        printf("Sem memória!\n");
        exit(1);
    }

    for (int index = 0; index < quantidade; index++) {
        printf("Matriculando aluno %d...\n", index+1);
        estudantes[index] = recebe_dados();
        printf("Aluno %d matriculado!\n", index+1);
    }
    
    return estudantes;
}