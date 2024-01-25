#include <stdio.h>
#include <stdlib.h>
#define CHAR_MAX 30

typedef struct funcionario {
    char nome[CHAR_MAX];
    float salario;
    int identificador;
    char cargo[CHAR_MAX];
} Funcionario;

void preenche(Funcionario *funcionarioUser) {
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionarioUser->nome);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionarioUser->salario);

    printf("Digite o identificador do funcionario: ");
    scanf("%d", &funcionarioUser->identificador);

    printf("Digite o cargo do funcionario: ");
    scanf(" %[^\n]", funcionarioUser->cargo);

    printf("\n");
}

void imprime(Funcionario *funcionarioUser) {
    printf("Nome: %s\n", funcionarioUser->nome);
    printf("Salario: %.2f\n", funcionarioUser->salario);
    printf("Identificador: %d\n", funcionarioUser->identificador);
    printf("Cargo: %s\n\n", funcionarioUser->cargo);
}

void alterarSalario(Funcionario *funcionarioUser, float novo_salario) {
    funcionarioUser->salario = novo_salario;
}

void salarioMaior(Funcionario *funcionarioUser, int num_funcionarios) {
    float maior_salario = funcionarioUser[0].salario;
    int id_func = 0;

    for (int i = 1; i < num_funcionarios; i++) {
        if (funcionarioUser[i].salario > maior_salario) {
            maior_salario = funcionarioUser[i].salario;
            id_func = i;
        }
    }

    printf("O funcionario com o maior salario no cargo de %s, recebe o valor total de R$%.2f.\n\n", funcionarioUser[id_func].cargo, maior_salario);
}

void salarioMenor(Funcionario *funcionarioUser, int num_funcionarios) {
    float menor_salario = funcionarioUser[0].salario;
    int id_func = 0;

    for (int i = 1; i < num_funcionarios; i++) {
        if (funcionarioUser[i].salario < menor_salario) {
            menor_salario = funcionarioUser[i].salario;
            id_func = i;
        }
    }

    printf("O funcionario com o menor salario no cargo de %s, recebe o valor total de R$%.2f.\n\n", funcionarioUser[id_func].cargo, menor_salario);
}

int main() {
    int num_funcionarios;

    printf("Digite o numero de funcionarios a serem cadastrados: ");
    scanf("%d", &num_funcionarios);

    Funcionario *funcionarioUser = (Funcionario*)malloc(num_funcionarios * sizeof(Funcionario));

    if (funcionarioUser == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    printf("\n----- INFORMACOES DOS FUNCIONARIOS -----\n");
    for (int i = 0; i < num_funcionarios; i++) {
        preenche(&funcionarioUser[i]);
    }

    printf("\n----- DADOS DOS FUNCIONARIOS -----\n");
    for (int i = 0; i < num_funcionarios; i++) {
        imprime(&funcionarioUser[i]);
    }

    printf("\n----- SALARIOS -----\n");
    salarioMaior(funcionarioUser, num_funcionarios);
    salarioMenor(funcionarioUser, num_funcionarios);

    free(funcionarioUser);

    return 0;

}
