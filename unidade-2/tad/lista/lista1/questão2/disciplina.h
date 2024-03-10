// Definição do tipo estruturado Disciplina
typedef struct Disciplina {
  char nome[100];
  int codigo;
} Disciplina;

// Função que cria uma nova disciplina
Disciplina* cria_disciplina(char nome[], int codigo);

// Função que exclui uma disciplina existente
void exclui_disciplina(Disciplina* disciplina);
