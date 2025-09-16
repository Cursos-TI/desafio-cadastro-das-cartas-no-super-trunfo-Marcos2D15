#include <stdio.h>

int main (){
    // =============================
    // Movimentos da Torre (exemplo)
    // =============================
    printf("Movimento da Torre:\n");
    for(int i = 0; i < 3; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // =============================
    // Movimentos do Bispo (exemplo)
    // =============================
    printf("Movimento do Bispo:\n");
    int j = 0;
    while (j < 3) {
        printf("Diagonal Direita-Cima\n");
        j++;
    }
    
    printf("\n");

    // ==============================
    // Movimentos da Rainha (exemplo)
    // ==============================
    printf("Movimento da Rainha:\n");
    int k = 0;
    do{
        printf("Esquerda\n");
        k++;
    } while (k < 3);
    
    // ===============================
    // Movimento do Cavalo
    //================================
    printf("\nMovimento do Cavalo:\n");

    // O cavalo deve andar 2 casa para baixo e 1 paea a esquerda
    int movimentosBaixo = 2;
    int movimentosEsquerda = 1;

    // O loop FOR para percorrer as duas casas para baixo
    for (int i = 0; i < movimentosBaixo; i++) {
        printf("Baixo\n");

        // Dentro do loop usamos im WHILE apenas para ilustrar a aninhagem
        // (mesmo que aqui ele só rode 0 ou 1 vez dependendo da lógica).
        int aux = 0;
        while (aux < 0) {
            printf("Nada\n"); // Só exemplo, não será executado
            aux++;
        }    
    }

    // Depois, um loop WHILE para a casa á esquerda
    int cont = 0;
    while (cont < movimentosEsquerda) {
        printf("Esquerda\n");
        cont++;
    }
    
    return 0;
}