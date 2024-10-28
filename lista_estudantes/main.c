#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estudante {
    char nome[50];
    int idade;
    char curso[50];
    struct estudante* proximo;
} Estudante;

// Função para criar a lista
void inicializarLista(Estudante **cabeca) {
    *cabeca = NULL; 
}

// Função para inserir estudante na lista
Estudante* adicionarEstudante(Estudante **cabeca, char *nome, int idade, char *curso) {
    Estudante* novoEstudante = (Estudante*) malloc(sizeof(Estudante));
    if (novoEstudante == NULL) {
        printf("Erro de alocação\n");
        return NULL;
    }
    strcpy(novoEstudante->nome, nome);
    novoEstudante->idade = idade;
    strcpy(novoEstudante->curso, curso);
    novoEstudante->proximo = *cabeca;
    *cabeca = novoEstudante;
    return novoEstudante;
}

// Função para inserir estudante em ordem alfabética
void adicionarEstudanteOrdenado(Estudante **cabeca, char *nome, int idade, char *curso) {
    Estudante *novoEstudante = (Estudante*) malloc(sizeof(Estudante));
    
    if (novoEstudante) {
        // Inicializa os campos do novo estudante
        strcpy(novoEstudante->nome, nome);
        novoEstudante->idade = idade;
        strcpy(novoEstudante->curso, curso);
        novoEstudante->proximo = NULL;

        // Caso a lista esteja vazia
        if (*cabeca == NULL) {
            *cabeca = novoEstudante; 
        }
        else if (strcmp(novoEstudante->nome, (*cabeca)->nome) < 0) {
            novoEstudante->proximo = *cabeca; 
            *cabeca = novoEstudante; 
        } else {
            Estudante *atual = *cabeca; 
            Estudante *anterior = NULL; 

            // Percorre a lista para encontrar a posição correta
            while (atual != NULL && strcmp(atual->nome, novoEstudante->nome) <= 0) {
                anterior = atual; 
                atual = atual->proximo; 
            }
            
            novoEstudante->proximo = atual; 
            if (anterior != NULL) {
                anterior->proximo = novoEstudante; 
            }
        }
    } else {
        printf("Erro ao alocar memória\n");
    }
}

// Exibe os conteúdos dentro da lista
void exibirLista(Estudante *estudante) {
    printf("\nLista:\n");
    while (estudante != NULL) {
        printf("Nome: %s | Idade: %d | Curso: %s\n", estudante->nome, estudante->idade, estudante->curso);
        estudante = estudante->proximo;
    }
    printf("NULL\n");  // Indica o final da lista
}

// Verifica se a lista está vazia
int listaEstaVazia(Estudante* estudante) {
    return estudante == NULL;
}

// Função para buscar um estudante pelo nome
Estudante* buscarEstudante(Estudante *cabeca, char *nome) {
    Estudante *atual = cabeca;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para remover estudante da lista pelo nome
Estudante* removerEstudante(Estudante *cabeca, char *nome) {
    Estudante *anterior = NULL;
    Estudante *atual = cabeca;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                cabeca = atual->proximo; 
            } else {
                anterior->proximo = atual->proximo; 
            }
            free(atual); 
            printf("Estudante removido: %s\n", nome);
            return cabeca; 
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return cabeca;
}

// Função para liberar a lista
void liberarLista(Estudante *cabeca) {
    Estudante *atual = cabeca;
    Estudante *proximo;

    while (atual != NULL) {
        proximo = atual->proximo; // Guarda o próximo nó
        free(atual); // Libera o nó atual
        atual = proximo; // Avança para o próximo nó
    }
}

// Função principal
int main() {
    Estudante* lista;
    inicializarLista(&lista);

    adicionarEstudanteOrdenado(&lista, "Mariana", 22, "Biologia");
    adicionarEstudanteOrdenado(&lista, "Lucas", 19, "Arquitetura");
    adicionarEstudanteOrdenado(&lista, "Fernanda", 29, "Matemática");
    adicionarEstudante(&lista, "Carlos", 24, "Química");

    exibirLista(lista);

    // Exemplo de remoção
    lista = removerEstudante(lista, "Lucas");
    exibirLista(lista);

    // Liberar a lista ao final
    liberarLista(lista);

    return 0;
}