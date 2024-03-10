#include <stdio.h>
#include "disciplina.h"
#include "aluno.h"

int main() {
  Disciplina* d1 = cria_disciplina("Estrutura de Dados I", 123);
  Disciplina* d2 = cria_disciplina("Algoritmos", 456);

  Aluno* a1 = cria_aluno("Alexandre Sousa", 123456);

  matricula_disciplina(a1, d1);
  matricula_disciplina(a1, d2);

  printf("Nome: %s\n", a1->nome);
  printf("Matricula: %d\n", a1->matricula);

  for (int index = 0; index < a1->num_disciplinas; index++) {
    printf("Disciplina %d: %s (codigo %d)\n", index + 1, a1->disciplinas[index]->nome, a1->disciplinas[index]->codigo);
  }

  exclui_aluno(a1);
  exclui_disciplina(d1);
  exclui_disciplina(d2);

  return 0;
}
