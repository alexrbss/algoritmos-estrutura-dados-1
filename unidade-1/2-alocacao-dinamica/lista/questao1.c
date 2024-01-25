#include <stdio.h>
#include <stdlib.h>

void leituraRespostas(int i, char *genero, int *opiniao) {
    
    printf("----- PESQUISA DE OPINIAO -----\n");
    printf("Entrevistado %d\n", i + 1);

    //lendo as respostas de gênero
    do {
        printf("Informe o seu genero:\n");
        printf("M - Masculino\n");
        printf("F - Feminino\n");
        scanf(" %c", &genero[i]);
    } while (genero[i] != 'M' && genero[i] != 'F');

    //lendo as respostas de opinião
    do {
        printf("Qual a sua opiniao sobre o produto?\n");
        printf("1 - Gostou\n");
        printf("2 - Nao Gostou\n");
        scanf("%d", &opiniao[i]);
    } while (opiniao[i] != 1 && opiniao[i] != 2);
}

int main() {
    int masculino = 0, masc_gostou = 0, feminino = 0, fem_naoGostou = 0;

    //definindo a quantidade de entrevistados
    int quantidade_entrevistados, i;
    printf("Informe a quantidade de pessoas que serao entrevistadas:\n");
    scanf("%d", &quantidade_entrevistados);

    //alocação de memória para os arrays de genero e opiniao
    char *genero = (char *)malloc(quantidade_entrevistados * sizeof(char));
    int *opiniao = (int *)malloc(quantidade_entrevistados * sizeof(int));

    //lendo as respostas
    for (i = 0; i < quantidade_entrevistados; i++) {
        leituraRespostas(i, genero, opiniao);
    }

    //calculando a porcentagem masculina
    for (i = 0; i < quantidade_entrevistados; i++) {
        if (genero[i] == 'M') {
            masculino++;
            if (opiniao[i] == 1) {
                masc_gostou++;
            }
        }
    }

    //calculando a porcentagem feminina
    for (i = 0; i < quantidade_entrevistados; i++) {
        if (genero[i] == 'F') {
            feminino++;
            if (opiniao[i] == 2) {
                fem_naoGostou++;
            }
        }
    }

    //exibindo porcentagem masculina que gostou
    if (masculino > 0) {
        float porcentagem_gostou = ((float)masc_gostou / masculino) * 100;
        printf("Porcentagem Masculina que Gostou: %.2f%%\n", porcentagem_gostou);
    } else {
        printf("Nenhum homem foi entrevistado.\n");
    }

    //exibindo porcentagem feminina que NÃO gostou
    if (feminino > 0) {
        float porcentagem_naoGostou = ((float)fem_naoGostou / feminino) * 100;
        printf("Porcentagem Feminina que Nao Gostou: %.2f%% \n", porcentagem_naoGostou);
    } else {
        printf("Nenhuma mulher foi entrevistada.\n");
    }

    //liberando memória
    free(genero);
    free(opiniao);

    return 0;
}