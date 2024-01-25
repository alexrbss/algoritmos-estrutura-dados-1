#include <stdio.h>
#include <stdlib.h>

int main () {

    int x, y, *p;

    y = 0; //atribui-se o valor 0 a "y"
    p = &y; //atribui-se o endereço de "y" a "p"
    x = *p; //atribui-se o valor apontado por "p" a "x"
    x = 4; //atribui-se o valor 4 a "x"
    (*p)++; //incrementa o valor apontado por "p", e agora passa a valer 1
    --x; //decrementa o valor de "x", passando a valer 3
    (*p) += x; //o valor apontado por "p" é somado ao valor de "x", resultando no valor 4

    //portanto, teremos teremos x == 3, y == 4 e p == enderço de y

} 