#include <stdio.h>
#include <stdlib.h>
#include "funcionarios.h"

int main(){
    FILE * arquivo = fopen("funcionarios.txt", "r");
    int n;
    fscanf(arquivo, "%d\n", &n);
    Funcionario ** pessoal = (Funcionario **) malloc(n * sizeof(Funcionario *));
    
    for(int i = 0; i < n; i++){
        pessoal[i] = (Funcionario *) malloc(sizeof(Funcionario));
    }

    copia_dados(arquivo, n, pessoal);
    
    imprime_folha_pagamento(n, pessoal, 'A');
    imprime_folha_pagamento(n, pessoal, 'B');
    imprime_folha_pagamento(n, pessoal, 'C');

    fclose(arquivo);

    for(int i = 0; i < n; i++){
        free(pessoal[i]);
    }
    free(pessoal);

    return 0;
}