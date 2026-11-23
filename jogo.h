#ifndef JOGO_H
#define JOGO_H

#define MAX 100
#define TAM_TEXTO 50
#define ARQUIVO_DADOS "dados.txt"

typedef struct {
    int codigo;
    char titulo[TAM_TEXTO];
    char desenvolvedora[TAM_TEXTO];
    float preco;
    int horasJogadas;
} Jogo;

/* Funções da Joyce */
void inicializar(Jogo *vetor[]);
int cadastrar(Jogo *vetor[]);
void listar(Jogo *vetor[]);
Jogo *buscar(Jogo *vetor[], int codigo);

/* Funções do Gabriel */
int carregar(Jogo *vetor[]);
int salvar(Jogo *vetor[]);
void relatorio(Jogo *vetor[]);
void liberar(Jogo *vetor[]);

#endif
