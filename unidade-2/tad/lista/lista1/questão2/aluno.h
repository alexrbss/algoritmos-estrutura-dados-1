#include "disciplina.h"

// Definição do tipo estruturado Aluno
typedef struct Aluno {
  char nome[100];
  int matricula;
  Disciplina* disciplinas[10];
  int num_disciplinas;
} Aluno;

// Função que adiciona um novo aluno
Aluno* cria_aluno(char nome[], int matricula);

// Função que realiza a matricula do aluno na discplina
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);

// Função que exclui um aluno existente
void exclui_aluno(Aluno* aluno);