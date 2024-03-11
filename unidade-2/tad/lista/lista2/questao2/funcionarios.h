#include <stdio.h>

// Definição do tipo estruturado Funcionario
typedef struct funcionario Funcionario;

// Função que copia os dados do arquivo
void copia_dados(FILE * arquivo, int n, Funcionario ** pessoal);

// Função que imprime os dados da folha de pagamento
void imprime_folha_pagamento(int n, Funcionario** pessoal, char depto);