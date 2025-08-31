#include <stdio.h>

#define TAM 2

// Definição da Estrutura Carta.
typedef struct{
    char estado;                         // Letra de 'A' a 'H'
    char codigo[4];                     // Ex: "A01"
    char nomeCidade [50];              // Nome da Cidade
    int populacao;                     // Número de Habitantes
    float area;                       // Área em Km²
    float pib;                        // Produto Interno Bruto
    int pontosTuristicos;            // Quantidades de Pontos Turíscos 
} Carta;

void cadastrarCartas (Carta *carta, int numero){
    printf ("\n--- Cadastro da Carta %d--- \n", numero + 1);
    
    printf(" Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (Ex: A01): ");
    scanf("%s",carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);   // Lê string com espaços

    printf("População: ");
    scanf("%d, &carta->populacao");

    printf("Área (em km²): ");
    scanf("%f", &carta->pib);

    printf("Pib: ");
    scanf("%f", &carta->pib);
    
    printf("Números de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirCarta(Carta carta, int numero){
    printf("\n=== Informações da Carta %d ===\n", numero + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n",carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km² \n", carta.area);
    printf("Pib: R$ %.2f bilhões\n", carta.pib);
    printf("Números de Pontos Turísticos: %d\n", carta.pontosTuristicos);    
}

int main () {
    Carta cartas[TAM];

    // Cadrasta as duas cartas
    for (int i = 0; i < TAM; i++) {
        cadastrarCarta(&cartas[i], i);
    }

    // Exiber as cartas cadastradas
    for (int i = 0; i < TAM; i++) {
        exibirCarta(cartas[i], i);
    }    

    return 0;

}
