#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

/* Funções auxiliares internas */
static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void removerQuebraLinha(char *str) {
    str[strcspn(str, "\r\n")] = '\0';
}

/* Retorna a primeira posição livre ou -1 se o vetor estiver cheio */
static int posicaoLivre(Jogo *vetor[]) {
    for (int i = 0; i < MAX; i++) {
        if (vetor[i] == NULL) {
            return i;
        }
    }
    return -1;
}

/* ================= FUNÇÕES DA JOYCE ================= */

void inicializar(Jogo *vetor[]) {
    for (int i = 0; i < MAX; i++) {
        vetor[i] = NULL;
    }
}

int cadastrar(Jogo *vetor[]) {
    int pos = posicaoLivre(vetor);
    if (pos == -1) {
        printf("Erro: catalogo cheio (limite de %d jogos).\n", MAX);
        return 0;
    }

    int codigo;
    printf("Codigo: ");
    if (scanf("%d", &codigo) != 1) {
        limparBuffer();
        printf("Codigo invalido.\n");
        return 0;
    }
    limparBuffer();

    if (buscar(vetor, codigo) != NULL) {
        printf("Erro: ja existe um jogo cadastrado com o codigo %d.\n", codigo);
        return 0;
    }

    vetor[pos] = (Jogo *)malloc(sizeof(Jogo));
    if (vetor[pos] == NULL) {
        printf("Erro: falha ao alocar memoria.\n");
        return 0;
    }

    vetor[pos]->codigo = codigo;

    printf("Titulo: ");
    fgets(vetor[pos]->titulo, TAM_TEXTO, stdin);
    removerQuebraLinha(vetor[pos]->titulo);

    printf("Desenvolvedora: ");
    fgets(vetor[pos]->desenvolvedora, TAM_TEXTO, stdin);
    removerQuebraLinha(vetor[pos]->desenvolvedora);

    printf("Preco (R$): ");
    if (scanf("%f", &vetor[pos]->preco) != 1) {
        limparBuffer();
        free(vetor[pos]);
        vetor[pos] = NULL;
        printf("Preco invalido.\n");
        return 0;
    }
    limparBuffer();

    printf("Horas jogadas: ");
    if (scanf("%d", &vetor[pos]->horasJogadas) != 1) {
        limparBuffer();
        free(vetor[pos]);
        vetor[pos] = NULL;
        printf("Quantidade de horas invalida.\n");
        return 0;
    }
    limparBuffer();

    return 1;
}

void listar(Jogo *vetor[]) {
    int encontrou = 0;

    printf("\n----- LISTA DE JOGOS -----\n");
    for (int i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            printf("[%d] %s | Dev: %s | R$ %.2f | %dh jogadas\n",
                   vetor[i]->codigo,
                   vetor[i]->titulo,
                   vetor[i]->desenvolvedora,
                   vetor[i]->preco,
                   vetor[i]->horasJogadas);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum jogo cadastrado.\n");
    }
}

Jogo *buscar(Jogo *vetor[], int codigo) {
    for (int i = 0; i < MAX; i++) {
        if (vetor[i] != NULL && vetor[i]->codigo == codigo) {
            return vetor[i];
        }
    }
    return NULL;
}

/* ================= FUNÇÕES DO GABRIEL ================= */

int carregar(Jogo *vetor[]) {
    FILE *fp = fopen(ARQUIVO_DADOS, "r");
    if (fp == NULL) {
        /* Na primeira execução o arquivo ainda não existe */
        return 0;
    }

    char linha[256];
    int carregados = 0;

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        int pos = posicaoLivre(vetor);
        if (pos == -1) {
            break;
        }

        Jogo temp;
        int lidos = sscanf(linha, "%d;%49[^;];%49[^;];%f;%d",
                           &temp.codigo,
                           temp.titulo,
                           temp.desenvolvedora,
                           &temp.preco,
                           &temp.horasJogadas);

        if (lidos == 5) {
            vetor[pos] = (Jogo *)malloc(sizeof(Jogo));
            if (vetor[pos] != NULL) {
                *vetor[pos] = temp;
                carregados++;
            }
        }
    }

    fclose(fp);
    return carregados;
}

int salvar(Jogo *vetor[]) {
    FILE *fp = fopen(ARQUIVO_DADOS, "w");
    if (fp == NULL) {
        printf("Erro ao abrir %s para gravacao.\n", ARQUIVO_DADOS);
        return 0;
    }

    for (int i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            fprintf(fp, "%d;%s;%s;%.2f;%d\n",
                    vetor[i]->codigo,
                    vetor[i]->titulo,
                    vetor[i]->desenvolvedora,
                    vetor[i]->preco,
                    vetor[i]->horasJogadas);
        }
    }

    fclose(fp);
    return 1;
}

void relatorio(Jogo *vetor[]) {
    int total = 0;
    float somaPreco = 0.0f;
    int somaHoras = 0;
    Jogo *maisJogado = NULL;

    for (int i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            total++;
            somaPreco += vetor[i]->preco;
            somaHoras += vetor[i]->horasJogadas;

            if (maisJogado == NULL || vetor[i]->horasJogadas > maisJogado->horasJogadas) {
                maisJogado = vetor[i];
            }
        }
    }

    printf("\n----- RELATORIO DO CATALOGO -----\n");
    if (total == 0) {
        printf("Nenhum jogo cadastrado para gerar relatorio.\n");
        return;
    }

    printf("Total de jogos cadastrados: %d\n", total);
    printf("Media de preco: R$ %.2f\n", somaPreco / total);
    printf("Total de horas jogadas: %d h\n", somaHoras);
    printf("Jogo com mais horas jogadas: %s (%s) - %d h\n",
           maisJogado->titulo,
           maisJogado->desenvolvedora,
           maisJogado->horasJogadas);
}

void liberar(Jogo *vetor[]) {
    for (int i = 0; i < MAX; i++) {
        if (vetor[i] != NULL) {
            free(vetor[i]);
            vetor[i] = NULL;
        }
    }
}
