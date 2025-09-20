#include <stdio.h>

/* ==========================
   Funções recursivas
   ========================== */

   // Torre: anda apenas em linha reta (exemplo: para cima)
   void moverTorre(int casas) {
        if (casas == 0) return; // condição de parada
        printf("Cima\n");
        moverTorre(casas - 1); // chamada recursiva
   }

// Rainha: combina a Torre + Bispo, aqui simularemos ela andando para a direita
void moverRainha(int casas) {
     if (casas == 0) return; // condição de parada
     printf("Direita\n");
     moverRainha(casas - 1);  // chamada recursiva
}  

//Bispo: anda na diagonal. Aqui usamos recursividade + loops aninhados
void moverBispo(int casas, int passo) {
     if (casas == 0) return;  // condição de parada

    //Loop aninhado: primeiro sobe (vertical), depois anda (horizontal)
    for (int i = 0; i < 1; i++) {  // movimento vertical
        printf("Cima\n");
        for (int j = 0; j < 1; j++) { // movimento horizontal
            printf("Direita\n");
        }
    }
    
    moverBispo(casas - 1, passo + 1); // chamada recursiva 
}

/* ============================
    Cavalo com loops aninhados
   ============================
   O cavalo move em "L": duas casas para cima e uma para a direita.
   Vamos usar loops aninhados e controlar com continue/break.
   */
void moverCavalo(int movimentos) {
     int cont = 0;
     for(int i = 1; i <= movimentos; i++) {  // controla movimentos
        for(int j = 0; j < 3; j++) {  //controle interno
            if(j < 2) {
                printf("Cima\n");  // duas casas para cima
            } else {
                printf("Direita\n");  // uma para direita
                break; // movimento concluído
            }
        }
        cont++;
        if (cont >= movimentos) continue; // próximo movimento
     } 
}   

/* ===========================
   Função principal
   ===========================*/
int main(){
    // Quantidade de casas/movimentos para cada peça
    int casasTorre = 3;
    int casasRainha = 4;
    int casasBispo = 3;
    int movimentosCavalo = 2;

    printf("=== Movimento da Torre ===\n");
    moverTorre(casasTorre);

    printf("\n=== Movimento da Rainha ===\n");
    moverRainha(casasRainha);

    printf("\n=== Movimento do Bispo ===\n");
    moverBispo(casasBispo, 1);

    printf("\n=== Movimento do Cavalo ===\n");
    moverCavalo(movimentosCavalo);

    return 0;
}
