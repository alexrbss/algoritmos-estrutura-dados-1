#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    int quantidade;

    printf("Digite a quantidade de alunos a serem matriculados: ");
    scanf("%d", &quantidade);

    Aluno ** estudantes = matricula(quantidade);

    if (estudantes == NULL) {
        printf("Erro na alocacao de memoria.\n");
        exit(1);
    }

    for (int index = 0; index < quantidade; index++) {
        
        printf("Dados do aluno %d\n", index+1);
        imprime(estudantes[index]);
    }    
    
    printf("Liberando a memória do vetor\n");

    for (int index = 0; index < quantidade; index++) {
        libera(estudantes[index]);
    }

    free(estudantes);

    return 0;
}