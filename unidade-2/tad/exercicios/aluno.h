/* Definição de novo tipo: Aluno */
typedef struct aluno Aluno;

/* Função que aloca memória para um struct aluno */
Aluno * recebe_dados(void);

/* Função que imprime os dados de um aluno */
void imprime(Aluno * estudante);

/* Função que libera a memória */
void libera(Aluno * estudante);

/* Função que matricula alunos */
Aluno** matricula(int quantidade);