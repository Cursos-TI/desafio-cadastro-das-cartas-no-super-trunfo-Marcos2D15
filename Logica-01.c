#include <stdio.h>

typedef struct {
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
} Carta;

int main(){
    Carta c1,c2;

    printf("Digite o nome da Cidade da Carta 1: ");
    scanf("%[^\n]", c1.nomeCidade);
    printf("Digite a População da carta 1: ");
    scanf("%lu", &c1.populacao);



    printf("Digite o nome da Cidade da carta 2: ");
    scanf("%[^\n]", c2.nomeCidade);
    printf("Digite a População da carta 2: ");
    scanf("%lu", &c2.populacao);

    printf("\nComparando cartas pelo atributo População...\n");

    if (c1.populacao > c2.populacao) {
        printf("%s Venceu!\n", c1.nomeCidade);
    } else if (c2.populacao > c1.populacao) {
        printf("%s Venceu!\n", c2.nomeCidade);
    } else{
        printf("Empate!\n");
    }
    
    return 0;
    
}