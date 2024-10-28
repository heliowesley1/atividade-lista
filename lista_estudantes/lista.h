#ifndef lista_h
#define lista_h

// Estrutura para armazenar os dados do estudante
typedef struct estudante {
    char nome[50];
    int idade;
    char curso[50];
    struct estudante* proximo;
} Estudante;

// Funções da lista
void inicializarLista(Estudante **cabeca);
Estudante* adicionarEstudante(Estudante **cabeca, char *nome, int idade, char *curso);
void adicionarEstudanteOrdenado(Estudante **cabeca, char *nome, int idade, char *curso);
Estudante* buscarEstudante(Estudante *cabeca, char *nome);
int listaEstaVazia(Estudante* estudante);
Estudante* removerEstudante(Estudante *cabeca, char *nome);
void exibirLista(Estudante *estudante);
void liberarLista(Estudante *cabeca);

#endif