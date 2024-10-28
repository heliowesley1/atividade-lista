#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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