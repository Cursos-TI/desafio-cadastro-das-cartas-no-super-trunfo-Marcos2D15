#include <stdio.h>

#define TAMANHO_TABULEIRO 10    // Tamanho fixo do tabuleiro (10x10)
#define TAMANHO_NAVIO 3         // Cada navio 3 posições
#define AGUA 0                // Representação da água no tabuleiro 
#define NAVIO 3               // Representação das partes dos navios

int main(){
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j;

    //===============================================
    // 1. Inicializar o tabuleiro com água (valor 0)
    //===============================================
    for (i = 0; i < TAMANHO_TABULEIRO; i++){
        for (j = 0; j < TAMANHO_TABULEIRO; j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    //==============================================
    // 2. Definir coordenadas iniciais dos navios
    //==============================================
    // Dois navios
    int navio1_linha = 1, navio1_coluna = 2;  //Horizontal
    int navio2_linha = 4, navio2_coluna = 6;  // Vertical

    // Dois navios diagonais
    int navio3_linha = 6, navio3_coluna = 1; // Diagonal Principal (\)
    int navio4_linha = 2, navio4_coluna = 8; // Diagonal secundária (/)
    
    // ======================================================
    // 3. Função para verificar sobreposição e inserir navio
    // ======================================================
    // Função simples que retorna 1 se houver sobreposição, 0 se estiver livre
    int sobreposicao = 0;

    //--- Navio 1 (horizontal)---
    if (navio1_coluna +  TAMANHO_NAVIO <= TAMANHO_TABULEIRO){
        for (j = 0; j < TAMANHO_NAVIO; j++){
            if (tabuleiro [navio1_linha][navio1_coluna + j ] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (j = 0; j < TAMANHO_NAVIO; j++)
                tabuleiro[navio1_linha][navio1_coluna + j] = NAVIO;
        }
    }   

    sobreposicao = 0; //Resetar para o próximo navio

    // --- Navio 2 (Vertical)---
    if (navio2_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha + i][navio2_coluna] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for(i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[navio2_linha + i][navio2_coluna] = NAVIO;
        }
    }

    sobreposicao = 0;

    // --- Navio 3 (diagonal principal \ ) ---
    if (navio3_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        navio3_coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for ( i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio3_linha + i][navio3_coluna + i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[navio3_linha +i][navio3_coluna + i] == NAVIO;
        }
    }

    sobreposicao = 0;

    // --- Navio 4 (diagonal secudária / ) ---
    if (navio4_linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO &&
        navio4_coluna - (TAMANHO_NAVIO - 1) >= 0) {
        for (i = 0; i <  TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio4_linha + i][navio4_coluna - i] == NAVIO)
                sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (i = 0; i < TAMANHO_NAVIO; i++)
                tabuleiro[navio4_linha + i][ navio4_coluna - i] == NAVIO;
        }
    }

    // ==========================================
    // 4. Exibir o tabuleiro completo no console
    // ==========================================
    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");
    printf("   ");
    for (j = 0;  j < TAMANHO_TABULEIRO; j++)
        printf("%d", j); // Cabeçalho de colunas
    printf("\n");

    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Índice da linha
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}