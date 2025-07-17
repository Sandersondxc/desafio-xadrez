
#include <stdio.h>

#define TAM_TABULEIRO 8

void mover_bispo(int linha, int coluna) {
    printf("Movimentos do Bispo a partir de (%d, %d):\n", linha, coluna);
    for (int i = 1; i < TAM_TABULEIRO; i++) {
        if (linha + i < TAM_TABULEIRO && coluna + i < TAM_TABULEIRO)
            printf("(%d, %d)\n", linha + i, coluna + i);
        if (linha - i >= 0 && coluna - i >= 0)
            printf("(%d, %d)\n", linha - i, coluna - i);
        if (linha + i < TAM_TABULEIRO && coluna - i >= 0)
            printf("(%d, %d)\n", linha + i, coluna - i);
        if (linha - i >= 0 && coluna + i < TAM_TABULEIRO)
            printf("(%d, %d)\n", linha - i, coluna + i);
    }
}

void mover_torre(int linha, int coluna) {
    printf("Movimentos da Torre a partir de (%d, %d):\n", linha, coluna);
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (i != linha) printf("(%d, %d)\n", i, coluna);
        if (i != coluna) printf("(%d, %d)\n", linha, i);
    }
}

void mover_rainha(int linha, int coluna) {
    printf("Movimentos da Rainha a partir de (%d, %d):\n", linha, coluna);
    mover_bispo(linha, coluna);
    mover_torre(linha, coluna);
}

void mover_cavalo(int linha, int coluna) {
    printf("Movimentos do Cavalo a partir de (%d, %d):\n", linha, coluna);
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int nova_linha = linha + movimentos[i][0];
        int nova_coluna = coluna + movimentos[i][1];
        if (nova_linha >= 0 && nova_linha < TAM_TABULEIRO &&
            nova_coluna >= 0 && nova_coluna < TAM_TABULEIRO) {
            printf("(%d, %d)\n", nova_linha, nova_coluna);
        }
    }
}

int main() {
    int linha = 3, coluna = 3;

    mover_bispo(linha, coluna);
    mover_torre(linha, coluna);
    mover_rainha(linha, coluna);
    mover_cavalo(linha, coluna);

    return 0;
}
