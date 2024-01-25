#include <stdio.h>
#include <stdlib.h>

int main () {

    int valor = 2;
    int *ponteiro;

    ponteiro = &valor;

    printf("valor: %d, endereco: %p", valor, ponteiro);

    return 0;
    
}