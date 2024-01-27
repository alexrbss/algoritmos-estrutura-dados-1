#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //malloc reserva espaço de memória em tempo de execução
    int *vetor = malloc(3*sizeof(int));
    
    if(vetor == NULL) {
        printf("Erro na alocação de memória");
        exit(1);
    } else {
        printf("Alocacao bem sucedida!");
    }

    //deve-se sempre fazer a liberação de memória
    free(vetor);
    
    return 0;

}