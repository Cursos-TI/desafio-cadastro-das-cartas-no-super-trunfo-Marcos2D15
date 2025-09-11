#include <stdio.h>
#include <string.h>

// Definição da estrutura Carta
typedef struct {
    char estado;               // Letra de 'A' a 'H'
    char codigo[4];            // Ex: "A01"
    char nomeCidade[50];       // Nome da cidade
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

// Função para exibir o menu de atributos
void mostrarMenu(int excluir) {
    printf("\nEscolha um atributo para comparação:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
    printf("Opção: ");
}

// Função para obter o valor do atributo escolhido
float obterAtributo(Carta c, int opcao) {
    switch(opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        case 6: return c.pibPerCapita;
        default: return -1; // erro
    }
}

// Função para comparar atributos individuais
int compararAtributo(float v1, float v2, int atributo) {
    // Para densidade demográfica, o menor vence
    if (atributo == 5) {
        return (v1 < v2) ? 1 : (v1 > v2 ? 2 : 0);
    } else {
        return (v1 > v2) ? 1 : (v1 < v2 ? 2 : 0);
    }
}

int main() {
    // Duas cartas pré-cadastradas
    Carta c1 = {'A', "A01", "Cidade Alfa", 2000000, 500.5, 120000000.0, 12, 2000000/500.5, 120000000.0/2000000};
    Carta c2 = {'B', "B02", "Cidade Beta", 1500000, 600.0, 90000000.0, 10, 1500000/600.0, 90000000.0/1500000};

    int atributo1, atributo2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma1, soma2;

    printf("Comparando as cartas:\n");
    printf("1: %s\n", c1.nomeCidade);
    printf("2: %s\n", c2.nomeCidade);

    // Escolha do primeiro atributo
    mostrarMenu(0);
    scanf("%d", &atributo1);

    // Escolha do segundo atributo (dinâmico)
    mostrarMenu(atributo1);
    scanf("%d", &atributo2);

    // Obter valores
    valor1_c1 = obterAtributo(c1, atributo1);
    valor1_c2 = obterAtributo(c2, atributo1);
    valor2_c1 = obterAtributo(c1, atributo2);
    valor2_c2 = obterAtributo(c2, atributo2);

    // Comparações individuais
    int resultado1 = compararAtributo(valor1_c1, valor1_c2, atributo1);
    int resultado2 = compararAtributo(valor2_c1, valor2_c2, atributo2);

    // Soma dos atributos
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("%s vs %s\n", c1.nomeCidade, c2.nomeCidade);

    printf("\nAtributo %d: %.2f vs %.2f -> %s\n", atributo1, valor1_c1, valor1_c2,
           resultado1 == 1 ? c1.nomeCidade : (resultado1 == 2 ? c2.nomeCidade : "Empate"));

    printf("Atributo %d: %.2f vs %.2f -> %s\n", atributo2, valor2_c1, valor2_c2,
           resultado2 == 1 ? c1.nomeCidade : (resultado2 == 2 ? c2.nomeCidade : "Empate"));

    printf("\nSoma total: %.2f (%s) vs %.2f (%s)\n", soma1, c1.nomeCidade, soma2, c2.nomeCidade);

    // Resultado final
    if (soma1 > soma2) {
        printf("\nVencedor: %s\n", c1.nomeCidade);
    } else if (soma2 > soma1) {
        printf("\nVencedor: %s\n", c2.nomeCidade);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
