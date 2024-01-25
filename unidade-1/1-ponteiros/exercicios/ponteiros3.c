#include <stdio.h>
#include <stdlib.h>

int *cria_variavel() {
    int variavel = 5; //decalaração de uma variavel LOCAL do tipo int
    return &variavel;
}

int main() {

    int *ponteiro = cria_variavel();
    
    printf("Valor da variavel: %d", *ponteiro);
    
    return 0;
}