#include <stdio.h>

typedef struct funcionario {
    int id;
    char nome[100];
    float salario;
} Funcionario;

void lerInformacoes(struct funcionario *Funcionario) {
    printf("ID: ");
    scanf("%d", &Funcionario->id);
    printf("Nome: ");
    scanf(" %[^\n]", Funcionario->nome);
    printf("Salario: R$");
    scanf("%f", &Funcionario->salario);
}

void escreveArquivo(FILE *arquivo, const struct funcionario *Funcionario) {
    fprintf(arquivo, "ID: %d\nNome: %s\nSalario: R$%.2f\n\n", Funcionario->id, Funcionario->nome, Funcionario->salario);
}

int main() {
    int numFuncionarios;

    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &numFuncionarios);

    FILE *arquivo = fopen("funcionarios.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        struct funcionario Funcionario;

        printf("\nFuncionario %d:\n", i + 1);
        lerInformacoes(&Funcionario);
        escreveArquivo(arquivo, &Funcionario);
    }

    fclose(arquivo);

    printf("\nInformacoes armazenadas no arquivo 'funcionarios.txt'.\n");

    return 0;
}
