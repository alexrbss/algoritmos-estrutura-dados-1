#include <stdio.h>
#include <stdlib.h>

float soma(int a, int b) {
    return a + b;
}

float subtracao(int a, int b) {
    return a - b;
}

float multiplicacao(int a, int b) {
    return a * b;
}

float divisao(int a, int b) {
    return a / b;
}

float calcula(int x, int y, int(*operacao)(int, int)) {
    return (*operacao)(x, y);
}

int main() {

    int x, y;

    printf("Informe o primeiro valor: \n");
    scanf("%d", &x);

    printf("Informe o segundo valor: \n");
    scanf("%d", &y);

    float resultado = calcula(x, y, divisao);
    printf("Resultado: %.2f", resultado);
    
    return 0;

}