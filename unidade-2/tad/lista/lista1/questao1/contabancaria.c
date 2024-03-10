#include "contabancaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ContaBancaria* criaConta(const char* titular, int numero, double saldo) {
    ContaBancaria* novaConta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    if (novaConta) {
        strcpy(novaConta->titular, titular);
        novaConta->numero = numero;
        novaConta->saldo = saldo;
    }
    return novaConta;
}

void deposita(ContaBancaria* conta, double valor) {
    conta->saldo += valor;
}

int saca(ContaBancaria* conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        return 1; // Saque bem-sucedido
    }
    return 0; // Saldo insuficiente
}

int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor) {
    if (origem->saldo >= valor) {
        origem->saldo -= valor;
        destino->saldo += valor;
        return 1; // Transferência bem-sucedida
    }
    return 0; // Saldo insuficiente na conta de origem
}

double saldo(ContaBancaria* conta) {
    return conta->saldo;
}

void excluiConta(ContaBancaria* conta) {
    free(conta);
}