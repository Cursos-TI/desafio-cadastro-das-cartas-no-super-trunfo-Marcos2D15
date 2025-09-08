#include <stdio.h>

typedef struct {
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
} Carta;

int main(){
    Carta c1,c2;
    int escolha;

    printf("Digite o nome da cidade da carta 1: ");
    scanf(" %[^\n]", c1.nomeCidade);
    printf("População:");
    scanf("%lu", &c1.populacao);
    printf("Área: ");
    scanf("%f", &c1.area);
    printf("Pib: ");
    scanf("%f", &c1.pib);

    printf("\nDigite o nome da Cidade da carta 2: ");
    scanf(" %[^\n]", c2.nomeCidade);
    printf("População: ");
    scanf("%lu", &c2.populacao);
    printf("Área: ");
    scanf("%f", &c2.area);
    printf("Pib: ");
    scanf("%f", &c2.pib);

    printf("\nEscolha o atributo para comparar:\n");
    scanf("1 - populacao\n2 - area\n3 - pib\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.populacao > c1.populacao)
                printf("%s venceu!\n", c2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            if (c1.area > c2.area)
                printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.area > c1.area)
                printf("%s venceu!\n", c2.nomeCidade);
            else
                printf("Empate!\n");
        case 3:
            if (c1.pib > c2.pib)
                printf("%s venceu!\n", c1.nomeCidade);
            else if (c2.pib > c1.pib)
                printf("%s venceu!\n",c2.nomeCidade);
            else
                printf("Emapate.\n");
            break;
        
        default:
            printf("Opção invalida.\n");
    }

   return 0;  
}