#include <stdio.h>

#define TAM 2 //Quantidade de cartas

// Definição da Estrutura Carta.
typedef struct{
    char estado;                         // Letra de 'A' a 'H'
    char codigo[4];                     // Ex: "A01"
    char nomeCidade [50];              // Nome da Cidade
    int populacao;                     // Número de Habitantes
    float area;                       // Área em Km²
    float pib;                       // Produto Interno Bruto
    int pontosTuristicos;           // Quantidades de Pontos Turíscos 
    float densidadepopulacional;    // População / Área
    float pibpercapita;            //Pib / população
} Carta;

//Função para Cadastrar uma carta
void cadastrarCarta(Carta *carta, int numero){
    printf ("\n--- Cadastro da Carta %d--- \n", numero + 1);
    
    printf(" Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (Ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);   // Lê string com espaços

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->pib);

    printf("Pib: ");
    scanf("%f", &carta->pib);
    
    printf("Números de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    //---Cálculos Automáticos---
    carta->densidadepopulacional = carta->populacao / carta->area;
    carta->pibpercapita = (carta->pib *1000000000) / carta->populacao;

    //Exibe os Cálculos no mesmo padão
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadepopulacional);
    printf("Pib per Capita: %.2f reais\n", carta->pibpercapita);

}
//Função para Exibir Cartas
void exibirCarta(Carta carta, int numero){
    printf("\n=== Informações da Carta %d ===\n", numero + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n",carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km² \n", carta.area);
    printf("Pib: R$ %.2f bilhões\n", carta.pib);
    printf("Números de Pontos Turísticos: %d\n", carta.pontosTuristicos);   
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadepopulacional);
    printf("Pib per Capita: %.2f reais\n", carta.pibpercapita); 
}

int main () {
    Carta cartas[TAM]; //Vetor de Cartas

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