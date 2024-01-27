#include <stdio.h>

//estrutura union 
typedef union tipodados {
    int meu_int;
    float meu_float;
}Dados;

int main(void) {

    Dados uniao;
    
    printf("Digite os dados: ");
    scanf("%d %f", &uniao.meu_int, &uniao.meu_float);

    printf("\nOs dados informados: \nmeu_int = %d \nmeu float = %f", uniao.meu_int, uniao.meu_float);

    return 0;
    
}