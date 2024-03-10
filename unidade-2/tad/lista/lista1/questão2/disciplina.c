#include <stdlib.h>
#include "disciplina.h"

Disciplina* cria_disciplina(char nome[], int codigo) {
  Disciplina* disciplina = (Disciplina*)malloc(sizeof(Disciplina));
  strcpy(disciplina->nome, nome);
  disciplina->codigo = codigo;
  return disciplina;
}

void exclui_disciplina(Disciplina* disciplina) {
  free(disciplina);
}
