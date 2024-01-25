#include <stdio.h>
#include <stdlib.h>

float media(int tamanho, int *vetor) {
    int soma = 0;
    int contador;

    for(contador = 0; contador < tamanho; contador ++) {
        soma = vetor[contador] + soma
    }

    return (soma/tamanho);

}