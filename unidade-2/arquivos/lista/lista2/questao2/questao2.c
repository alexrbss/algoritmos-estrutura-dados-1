#include <stdio.h>

typedef struct aluno {
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
} Aluno;

void lerInformacoes(struct aluno *Aluno) {
    printf("Nome do aluno: ");
    scanf(" %[^\n]", Aluno->nome); 
    printf("Nota 1: ");
    scanf("%f", &Aluno->nota1);
    printf("Nota 2: ");
    scanf("%f", &Aluno->nota2);
    printf("Nota 3: ");
    scanf("%f", &Aluno->nota3);
}

void escreverNoArquivo(FILE *arquivo, const struct aluno *Aluno) {
    fprintf(arquivo, "Nome: %s\nNota 1: %.1f\nNota 2: %.1f\nNota 3: %.1f\n\n",
            Aluno->nome, Aluno->nota1, Aluno->nota2, Aluno->nota3);
}

int main() {
    int numAlunos;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &numAlunos);

    FILE *arquivo = fopen("alunos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int index = 0; index < numAlunos; index++) {
        struct aluno Aluno;

        printf("\nAluno %d:\n", index + 1);
        lerInformacoes(&Aluno);
        escreverNoArquivo(arquivo, &Aluno);
    }

    fclose(arquivo);

    printf("\nInformacoes armazenadas no arquivo 'alunos.txt'.\n");

    return 0;
}
