#include <stdio.h>
#include "contabancaria.h"

int main() {
    ContaBancaria* minhaConta = criaConta("Maria", 12345, 1000.0);
    ContaBancaria* outraConta = criaConta("João", 54321, 500.0);

    deposita(minhaConta, 200.0);
    saca(minhaConta, 50.0);
    transfere(minhaConta, outraConta, 300.0);

    printf("Saldo da minha conta: %.2lf\n", saldo(minhaConta));
    printf("Saldo da outra conta: %.2lf\n", saldo(outraConta));

    excluiConta(minhaConta);
    excluiConta(outraConta);

    return 0;
}