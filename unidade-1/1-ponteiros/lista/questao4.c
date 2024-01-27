#include <stdio.h>
#include <math.h>

void calcula_hexagono(float lado, float *area, float *perimetro) {
    *area = 3 * pow(lado, 2) * sqrt(3) / 2;
    *perimetro = 6 * lado;
}

int main () {

    float lado_user, area_user, perimetro_user;

    printf("Informe o comprimento do lado do hexagono: ");
    scanf("%f", &lado_user);

    calcula_hexagono(lado_user, &area_user, &perimetro_user);

    printf("Area do Hexagono: %.2f \nPerimetro do Hexagono: %.2f", area_user, perimetro_user);

    return 0;

} 

