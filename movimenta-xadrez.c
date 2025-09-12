#include <stdio.h>

int main (){
    //===============================
    //Movimentoda TORRE (usando for)
    //===============================
    int casasTorre = 5; //Qnautidade de casas que a torre vai andar para a direita
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= casasTorre; i++){
        printf("Direita\n"); //Torre anda só para a direita caso
    }

    printf("\n");

    //===============================
    //Movimento do BISPO (usando while)
    //===============================
    int casasBispo = 5; //Quantidade de casas que o Bispo vai andar
    int i = 1;          //Contador do while
    printf("Movimento do Bispo:\n");
    while (i <= casasBispo){
        printf("Cima, Direita\n"); //Movimento na diagonal
        i++; //Incremta o contador
    }

    printf("\n");

    //===============================
    //Movimento da RAINHA (usando do while)
    //===============================
    int casasRainha = 8; // Quantidade de casa que a Rainha vai andar
    int j = 1;           //Contador do do while
    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");  // Rainha anda só para a esquerda neste caso
        j++;
    } while (j <= casasRainha);

    return 0;
}