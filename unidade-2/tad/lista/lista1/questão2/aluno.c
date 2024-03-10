#include <stdlib.h>
#include "aluno.h"

Aluno* cria_aluno(char nome[], int matricula) {
  Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));
  strcpy(aluno->nome, nome);
  aluno->matricula = matricula;
  aluno->num_disciplinas = 0;
  return aluno;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina) {
  if (aluno->num_disciplinas < 10) {
    aluno->disciplinas[aluno->num_disciplinas++] = disciplina;
  } else {
    printf("Limite de disciplinas excedido!\n");
  }
}

void exclui_aluno(Aluno* aluno) {
  for (int index = 0; index < aluno->num_disciplinas; index++) {
    exclui_disciplina(aluno->disciplinas[index]);
  }
  free(aluno);
}
