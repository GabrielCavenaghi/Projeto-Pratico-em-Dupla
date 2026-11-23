#include <stdio.h>
#include "jogo.h"

static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    Jogo *vetor[MAX];
    int opcao, codigo;
    Jogo *j;

    inicializar(vetor);
    carregar(vetor);

    do {
        printf("\n===== CATALOGO DE JOGOS =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar todos\n");
        printf("3 - Buscar por codigo\n");
        printf("4 - Relatorio\n");
        printf("5 - Salvar e sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                if (cadastrar(vetor)) {
                    printf("Jogo cadastrado!\n");
                }
                break;
            case 2:
                listar(vetor);
                break;
            case 3:
                printf("Codigo: ");
                scanf("%d", &codigo);
                limparBuffer();
                j = buscar(vetor, codigo);
                if (j != NULL) {
                    printf("Codigo: %d\nTitulo: %s\nDesenvolvedora: %s\n"
                           "Preco: R$ %.2f\nHoras jogadas: %d\n",
                           j->codigo, j->titulo, j->desenvolvedora,
                           j->preco, j->horasJogadas);
                } else {
                    printf("Jogo nao encontrado.\n");
                }
                break;
            case 4:
                relatorio(vetor);
                break;
            case 5:
                salvar(vetor);
                liberar(vetor);
                printf("Dados salvos. Ate logo!\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
