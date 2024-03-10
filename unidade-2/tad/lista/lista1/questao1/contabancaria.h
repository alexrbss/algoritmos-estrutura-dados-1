// Definição da estrutura ContaBancaria
typedef struct {
    char titular[100]; 
    int numero; 
    double saldo; 
} ContaBancaria;

// Função para criar uma nova conta bancária
ContaBancaria* criaConta(const char* titular, int numero, double saldo);

// Função para depositar um valor na conta
void deposita(ContaBancaria* conta, double valor);

// Função para sacar um valor da conta
int saca(ContaBancaria* conta, double valor);

// Função para transferir um valor entre contas
int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor);

// Função para obter o saldo da conta
double saldo(ContaBancaria* conta);

// Função para excluir uma conta (libera a memória alocada)
void excluiConta(ContaBancaria* conta);