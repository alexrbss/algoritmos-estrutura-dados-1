#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 55
#define MAX_NOME 80

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char turma;
    float notas[3];
    float media;
}Aluno;

void inicializaAlunos(Aluno **alunos, int n) {
    for (int i = 0; i < n; i++) {
        alunos[i] = NULL;
    }
}

void matricula(int n, Aluno **alunos) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] == NULL) {
            alunos[i] = (Aluno *)malloc(sizeof(Aluno));

            printf("Informe a matricula do aluno: ");
            scanf("%d", &alunos[i]->matricula);

            printf("Informe o nome do aluno: ");
            scanf(" %[^\n]", alunos[i]->nome);

            printf("Informe a turma do aluno: ");
            scanf(" %c", &alunos[i]->turma);

            for (int j = 0; j < 3; j++) {
                alunos[i]->notas[j] = 0.0;
            }

            alunos[i]->media = 0.0;

            printf("Aluno matriculado com sucesso!\n");
            return;
        }
    }

    printf("Não ha vagas disponiveis para matricula.\n");
}

void lanca_notas(int n, Aluno **alunos) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL) {
            printf("Informe as três notas do aluno %s: ", alunos[i]->nome);
            for (int j = 0; j < 3; j++) {
                scanf("%f", &alunos[i]->notas[j]);
            }

            alunos[i]->media = (alunos[i]->notas[0] + alunos[i]->notas[1] + alunos[i]->notas[2]) / 3.0;
        }
    }

    printf("Notas lançadas e medias calculadas com sucesso.\n");
}

void imprime_tudo(int n, Aluno **alunos) {
    printf("\n----- Dados de Todos os Alunos -----\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL) {
            printf("Matrícula: %d, Nome: %s, Turma: %c, Média: %.2f\n",
                   alunos[i]->matricula, alunos[i]->nome, alunos[i]->turma, alunos[i]->media);
        }
    }
}

void imprime_turma(int n, Aluno **alunos, char turma) {
    printf("\n----- Dados da Turma %c -----\n", turma);
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL && alunos[i]->turma == turma) {
            printf("Matrícula: %d, Nome: %s, Média: %.2f\n",
                   alunos[i]->matricula, alunos[i]->nome, alunos[i]->media);
        }
    }
}

void imprime_turma_aprovados(int n, Aluno **alunos, char turma) {
    printf("\n----- Alunos Aprovados na Turma %c -----\n", turma);
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL && alunos[i]->turma == turma && alunos[i]->media >= 7.0) {
            printf("Matrícula: %d, Nome: %s, Média: %.2f\n",
                   alunos[i]->matricula, alunos[i]->nome, alunos[i]->media);
        }
    }
}

void libera_memoria(int n, Aluno **alunos) {
    for (int i = 0; i < n; i++) {
        free(alunos[i]);
    }
}

int main() {
    
    Aluno *alunos[MAX_ALUNOS];

    inicializaAlunos(alunos, MAX_ALUNOS);

    int opcao;
    char turma;

    do {
        printf("\n----- Menu -----\n");
        printf("1 - Matricular aluno\n");
        printf("2 - Lançar notas e calcular média\n");
        printf("3 - Imprimir dados de todos os alunos\n");
        printf("4 - Imprimir dados de uma turma\n");
        printf("5 - Imprimir alunos aprovados de uma turma\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                matricula(MAX_ALUNOS, alunos);
                break;
            case 2:
                lanca_notas(MAX_ALUNOS, alunos);
                break;
            case 3:
                imprime_tudo(MAX_ALUNOS, alunos);
                break;
            case 4:
                printf("Informe a turma (A, B, C, etc.): ");
                scanf(" %c", &turma);
                imprime_turma(MAX_ALUNOS, alunos, turma);
                break;
            case 5:
                printf("Informe a turma (A, B, C, etc.): ");
                scanf(" %c", &turma);
                imprime_turma_aprovados(MAX_ALUNOS, alunos, turma);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    libera_memoria(MAX_ALUNOS, alunos);

    return 0;
}
