#include <stdio.h>

//constantes em C
// #define TRUE 0
// #define FALSE 1

//enumeração (outra forma de definir constantes em C)
typedef enum bool {
    true, //a primeira variável assume o valor 0
    false //a enumerção segue em sequência com false assumindo o valor de 1 e assim por diante...
}Bool;

int main(void) {
    Bool resposta;

    printf("Voce gosta de algoritmos? \n0 - True \n1 - False\n");
    scanf("%d", &resposta);

    if (resposta == true) {
        printf("Boa escolha\n");
    } 
    else if (resposta == false) {
        printf("Que pena! \n");
    }

    return 0;
    
}