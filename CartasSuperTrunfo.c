#include <stdio.h>

#define TAM 2

// Definição da estrutura Carta
typedef struct {
    char estado;                       // Letra de 'A' a 'H'
    char codigo[4];                    // Ex: "A01"
    char nomeCidade[50];               // Nome da cidade
    unsigned long int populacao;       // Número de habitantes
    float area;                        // Área em km²
    double pib;                        // PIB em reais
    int pontosTuristicos;              // Número de pontos turísticos
    float densidadePop;                // População / Área
    float pibPerCapita;                // PIB / População
    float superPoder;                  // Soma dos atributos numéricos + 1/densidade
} Carta;

int main() {
    Carta cartas[TAM];

    // Leitura dos dados das cartas
    for (int i = 0; i < TAM; i++) {
        printf("\n--- Cadastro da Carta %d ---\n", i + 1);
        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Codigo (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("Populacao: ");
        scanf("%lu", &cartas[i].populacao);

        printf("Area (km2): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em reais): ");
        scanf("%lf", &cartas[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculos automáticos
        cartas[i].densidadePop = (float)cartas[i].populacao / cartas[i].area;
        cartas[i].pibPerCapita = (float)(cartas[i].pib / cartas[i].populacao);

        // Super Poder
        cartas[i].superPoder = (float)cartas[i].populacao 
                             + cartas[i].area 
                             + (float)cartas[i].pib 
                             + (float)cartas[i].pontosTuristicos
                             + cartas[i].pibPerCapita
                             + (1.0f / cartas[i].densidadePop); 
    }

    // Exibição dos dados completos das cartas
    for (int i = 0; i < TAM; i++) {
        printf("\n=== Dados da Carta %d ===\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Codigo: %s\n", cartas[i].codigo);
        printf("Cidade: %s\n", cartas[i].nomeCidade);
        printf("Populacao: %lu\n", cartas[i].populacao);
        printf("Area: %.2f km2\n", cartas[i].area);
        printf("PIB: %.2lf\n", cartas[i].pib);
        printf("Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km2\n", cartas[i].densidadePop);
        printf("PIB per Capita: %.2f\n", cartas[i].pibPerCapita);
        printf("Super Poder: %.2f\n", cartas[i].superPoder);
    }

    // Comparações
    printf("\n=== Comparacao de Cartas ===\n");

    // População
    printf("Populacao: Carta 1 venceu (%d)\n", cartas[0].populacao > cartas[1].populacao);

    // Área
    printf("Area: Carta 1 venceu (%d)\n", cartas[0].area > cartas[1].area);

    // PIB
    printf("PIB: Carta 1 venceu (%d)\n", cartas[0].pib > cartas[1].pib);

    // Pontos turísticos
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", cartas[0].pontosTuristicos > cartas[1].pontosTuristicos);

    // Densidade populacional (vence a menor)
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", cartas[0].densidadePop < cartas[1].densidadePop);

    // PIB per capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", cartas[0].pibPerCapita > cartas[1].pibPerCapita);

    // Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", cartas[0].superPoder > cartas[1].superPoder);

    return 0;
}



