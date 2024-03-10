#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int funcional;
    char nome[50];
    char departamento;
    float salario;
} Funcionario;

void copia_dados(FILE* fl, int n, Funcionario** pessoal);
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto);

int main() {
    FILE *arquivo;
    int num_funcionarios;

    arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(arquivo, "%d", &num_funcionarios);

    Funcionario **pessoal = malloc(num_funcionarios * sizeof(Funcionario*));

    copia_dados(arquivo, num_funcionarios, pessoal);

    fclose(arquivo);

    imprime_folha_pagamento(num_funcionarios, pessoal, 'A');
    imprime_folha_pagamento(num_funcionarios, pessoal, 'B');

    free(pessoal);

    return 0;
}

void copia_dados(FILE* fl, int n, Funcionario** pessoal) {
    for (int i = 0; i < n; i++) {
        pessoal[i] = malloc(sizeof(Funcionario));
        fscanf(fl, "%d\t%s\t %c\t%f\n", &pessoal[i]->funcional, pessoal[i]->nome, &pessoal[i]->departamento, &pessoal[i]->salario);
    }
}

void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        if (pessoal[i]->departamento == depto) {
            total += pessoal[i]->salario;
        }
    }
    printf("Valor gasto com a folha de pagamento do departamento %c: %.2f\n", depto, total);
}
