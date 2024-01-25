#include <stdio.h>
#include <stdlib.h>
#define QUANT_ALUNOS 10

void leituraGabarito(int quant_questoes, char *gabarito) {
    printf("----- GABARITO -----\n");

    //lendo o gabarito oficial
    for (int i = 0; i < quant_questoes; i++) {
        printf("Questao %d\n", i + 1);
        printf("Resposta: ");
        scanf(" %c", &gabarito[i]);
    }

    printf("Pressione ENTER para continuar\n");
    system("PAUSE");
    system("cls");
}

void respostasAluno(int quant_questoes, char *respostas) {
    //lendo o gabarito do aluno
    for (int i = 0; i < quant_questoes; i++) {
        printf("Questao %d\n", i + 1);
        printf("Resposta: ");
        scanf(" %c", &respostas[i]);
    }
}

int main() {

    int quant_questoes, aluno;

    //lendo o numero de questões
    printf("Informe o numero de questoes: ");
    scanf("%d", &quant_questoes);

    //alocação de memoria para o array de gabarito
    char *gabarito = (char *)malloc(quant_questoes * sizeof(char));

    //lendo o gabarito oficial
    leituraGabarito(quant_questoes, gabarito);

    //lendo o gabarito de cada aluno
    for (aluno = 1; aluno <= QUANT_ALUNOS; aluno++) {
        float nota = 0; 

        printf("Resposta do Aluno %d:\n", aluno);

        //alocação de memoria para o array de respostas
        char *respostas = (char *)malloc(quant_questoes * sizeof(char));

        //lendo as respostas dos alunos
        respostasAluno(quant_questoes, respostas);

        //calculando a nota
        char *gabarito_pont = gabarito;
        char *respostas_pont = respostas;

        for (int i = 0; i < quant_questoes; i++, gabarito_pont++, respostas_pont++) {
            if (*respostas_pont == *gabarito_pont) {
                nota += 10.0 / quant_questoes;  // Utiliza 10.0 para garantir a divisão correta
            }
        }

        //exibindo a nota
        printf("Nota do Aluno %d: %.2f\n\n", aluno, nota);

        //liberando memoria para respostas
        free(respostas);
    }

    //liberando memoria para gabarito
    free(gabarito);

    return 0;
}
