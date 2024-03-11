#include "funcionarios.h"
#include <stdlib.h>

typedef struct funcionario {
    char FuncionaID[4];
    char nome[51];
    char Departamento;
    float salario;
} Funcionario;

void copia_dados(FILE * arquivo, int n, Funcionario ** pessoal){
    for(int i = 0; i < n; i++){
        fscanf(arquivo, "%3s\t%50s\t%c\t%f\n", pessoal[i]->FuncionaID, pessoal[i]->nome, &pessoal[i]->Departamento, &pessoal[i]->salario);
    }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto){
    printf("FOLHA DE PAGAMENTO DEPARTAMENTO %c\n", depto);
    printf("ID\tNome\tDepto\tSalario\n");
    
    float total = 0;
    for(int i = 0; i < n; i++){
        if(pessoal[i]->Departamento == depto){
            printf("%s\t%s\t%c\t%.2f\n", pessoal[i]->FuncionaID, pessoal[i]->nome, pessoal[i]->Departamento, pessoal[i]->salario);
            total += pessoal[i]->salario;
        }
    }
    
    printf("VALOR TOTAL:\t\tR$%.2f\n", total);

}
