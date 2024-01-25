#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int a, b, c, d; 
    //declaração de 4 variáveis do tipo inteiro
    int *p1; 
    //declaração de um ponteiro "p1" do tipo inteiro
    int *p2 = &a;
    /* declaração de um ponteiro "p2" do tipo inteiro que irá  
    apontar para o endereço da variável "a" */
    int *p3 = &c;
    /* declaração de um ponteiro "p3" do tipo inteiro que irá  
    apontar para o endereço da variável "c" */
    p1 = p2;
    //atribui-se o valor apontado por "p2" a "p1"
    *p2 = 10;
    //atribui-se o valor 10 ao ponteiro "p2"
    b = 20;
    //atribui-se o valor 20 a "b"
    int **pp;
    //declaração de um ponteiro duplo "pp" do tipo inteiro
    pp = &p1;
    //atribui-se o endereço de "p1" a "pp"
    *p3 = **pp;
    //atribui-se o valor apontado por "pp" a "p3"
    int *p4 = &d;
    /* declaração de um ponteiro "p4" do tipo inteiro que irá
    apontar para o endereço da variável "d" */
    *p4 = b + (*p1)++;
    /* soma-se o valor de b ao de p1, resultando em 20 + 10 = 30
    e o conteúdo de p1 é incrementado, passando a valer 11 */

    printf("%d \t %d \t %d \t %d\n", a, b, c, d);
    //portanto, teremos a == 11, b == 20, c == 10 e d == 30

    return 0;

}