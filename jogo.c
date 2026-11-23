#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

/* Retorna a primeira posição livre ou -1 se o vetor estiver cheio */
static int posicaoLivre(Jogo *vetor[]) {
    /* TODO: percorrer de 0 a MAX-1 e retornar o índice do primeiro NULL */
}

void inicializar(Jogo *vetor[]) {
    /* TODO: for de 0 a MAX-1, vetor[i] = NULL */
}

int cadastrar(Jogo *vetor[]) {
    /* TODO:
       1. pos = posicaoLivre(vetor); se -1, avisar "vetor cheio" e retornar 0
       2. ler o código e usar buscar() para recusar código repetido
       3. vetor[pos] = malloc(sizeof(Jogo)); se NULL, avisar e retornar 0
       4. ler título e desenvolvedora (fgets), preço e horas jogadas (scanf)
       5. retornar 1 em caso de sucesso */
}

void listar(Jogo *vetor[]) {
    /* TODO: percorrer o vetor e imprimir só as posições != NULL.
       Se não houver nenhum, mostrar "Nenhum jogo cadastrado" */
}

Jogo *buscar(Jogo *vetor[], int codigo) {
    /* TODO: se vetor[i] != NULL e vetor[i]->codigo == codigo, retornar vetor[i];
       caso contrário, retornar NULL */
}