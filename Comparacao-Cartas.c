#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

int main() {
    // Duas cartas já cadastradas (poderia vir do desafio anterior)
    Carta carta1 = {"Brasil", 213000000, 8516000.0, 22000.0, 50, 213000000 / 8516000.0};
    Carta carta2 = {"Argentina", 45000000, 2780000.0, 10000.0, 30, 45000000 / 2780000.0};

    int opcao;

    printf("=== Super Trunfo - Comparação de Cartas ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    printf("\nComparando %s x %s\n", carta1.nome, carta2.nome);

    switch(opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.populacao < carta2.populacao) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);

            if (carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.area < carta2.area) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões US$\n", carta1.nome, carta1.pib);
            printf("%s: %.2f bilhões US$\n", carta2.nome, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.pib < carta2.pib) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos Turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nome, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.pontosTuristicos < carta2.pontosTuristicos) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (MENOR vence)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidadeDemografica);

            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if (carta1.densidadeDemografica > carta2.densidadeDemografica) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
    }

    return 0;

}