#include <stdio.h>
#include <stdlib.h>

void incrementa(int *ponteiro) {
    (*ponteiro)++;
}

int main(void){

    int variavel = 5;
    
    incrementa(&variavel);

    printf("Valor da variavel: %d", variavel);

    return 0;

}