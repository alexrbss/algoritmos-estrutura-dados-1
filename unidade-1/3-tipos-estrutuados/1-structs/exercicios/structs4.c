#include <stdio.h>
#include <stdlib.h>

//exemplo de aninhamento de estruturas
typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno {
    char nome[20];
    int idade;
    int matricula;
    //aninhando a estrutura disciplina na estrutura aluno
    Disciplina * materias;
}Aluno;

int main(){
    
    Aluno * aluno = (Aluno*)malloc(sizeof(Aluno));
    
    if (aluno==NULL){
        exit(1);
    }
    
    aluno->materias = (Disciplina*)malloc(2*sizeof(Disciplina));
    
    if(aluno->materias==NULL){
        exit(1);
    }
    
    printf("Informe os dados do aluno: nome, idade e matricula\n");
    scanf(" %[^\n]", aluno->nome);
    scanf("%d %d", &aluno->idade, &aluno->matricula);
    
    
    int index;
    for(index = 0; index < 2; index++) {
        printf("Cadastro da Disciplina %d nome, codigo e nota:", index + 1);
        scanf(" %[^\n]", aluno->materias[index].nome);
        scanf("%d %f", &aluno->materias[index].codigo, &aluno->materias[index].nota);
    }
    
    return 0;
}