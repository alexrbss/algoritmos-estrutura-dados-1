#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float raio;
}Circulo;

typedef struct {
    float base;
    float altura;
}Retangulo;

Retangulo* ret_circunscrito(Circulo *c, float h) {
    if (h >= 2 * c->raio) {
        printf("A altura deve ser menor que o diâmetro do círculo.\n");
        return NULL;
    }

    Retangulo* retanguloCircunscrito = (Retangulo*)malloc(sizeof(Retangulo));

    retanguloCircunscrito->base = 2 * c->raio;

    retanguloCircunscrito->altura = h;

    return retanguloCircunscrito;
}

Circulo* circ_interno(Retangulo *r) {
    Circulo* circuloInterno = (Circulo*)malloc(sizeof(Circulo));

    circuloInterno->raio = fmin(r->base, r->altura) / 2;

    return circuloInterno;
}

void libera_memoria(void *figura) {
    free(figura);
}

int main() {
    
    Circulo circuloUser;
    Retangulo retanguloUser;

    printf("Informe o raio do circulo: ");
    scanf("%f", &circuloUser.raio);

    printf("Informe a base do retangulo: ");
    scanf("%f", &retanguloUser.base);

    printf("Informe a altura do retangulo: ");
    scanf("%f", &retanguloUser.altura);

    Retangulo* retanguloCircunscrito = ret_circunscrito(&circuloUser, 5.0);

    if (retanguloCircunscrito != NULL) {
        printf("\nMaior retangulo circunscrito ao círculo:\n");
        printf("Base: %.2f\n", retanguloCircunscrito->base);
        printf("Altura: %.2f\n", retanguloCircunscrito->altura);

        libera_memoria(retanguloCircunscrito);
    }

    Circulo* circuloInterno = circ_interno(&retanguloUser);

    printf("\nMaior circulo interno ao retangulo:\n");
    printf("Raio: %.2f\n", circuloInterno->raio);

    libera_memoria(circuloInterno);

    return 0;
}