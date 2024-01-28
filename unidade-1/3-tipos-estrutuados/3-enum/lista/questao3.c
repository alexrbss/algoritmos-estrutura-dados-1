#include <stdio.h>

typedef enum {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
}Meses;

typedef struct {
    int dia;
    Meses mes;
    int ano;
}Data;

void lerDados(Data *dataUser) {
    printf("Informe o dia: ");
    scanf("%d", &dataUser->dia);

    printf("Informe o mes: ");
    scanf("%d", (int*)&dataUser->mes);

    printf("Informe o ano: ");
    scanf("%d", &dataUser->ano);
}

void imprimeDados(const Data *dataUser) {
    printf("\nData: %02d/%02d/%04d\n", dataUser->dia, (int)dataUser->mes, dataUser->ano);
}

int main() {
    
    Data dataUser;

    lerDados(&dataUser);
    imprimeDados(&dataUser);

    return 0;
}
