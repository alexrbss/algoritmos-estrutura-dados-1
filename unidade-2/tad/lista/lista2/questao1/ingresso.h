// Definição do tipo estruturado Ingresso
typedef struct ingresso Ingresso;

// Função que preenche os dados de um ingresso
void preenche(Ingresso * i);

// Função que imprime os dados de um ingresso
void imprime(Ingresso * i);

// Função que altera o preço de um ingresso
void altera_preco(Ingresso * i, float valor);

// Função que imprime o maior e o menor preço dos ingressos
void imprime_maior_e_menor(int n, Ingresso * vet);