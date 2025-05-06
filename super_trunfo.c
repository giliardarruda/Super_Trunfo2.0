#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM_CODIGO 10
#define TAM_NOME 100

// Função para imprimir população com separador de milhar (ex: 12.300.000)
void imprimirPopulacaoFormatada(unsigned long int valor) {
    char buffer[30];
    sprintf(buffer, "%lu", valor);
    int len = strlen(buffer);

    for (int i = 0; i < len; i++) {
        putchar(buffer[i]);
        if ((len - i - 1) % 3 == 0 && i != len - 1) {
            printf(".");
        }
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char buffer[100];

    // ---------------- Carta 1 ----------------
    char estado1;
    char codigo1[TAM_CODIGO];
    char nomeCidade1[TAM_NOME];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    printf("Cadastro da Carta 1\n");

    printf("Digite o estado (letra de A a H): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, " %c", &estado1);

    printf("Digite o código da carta (ex: A01): ");
    fgets(codigo1, TAM_CODIGO, stdin);
    codigo1[strcspn(codigo1, "\n")] = '\0';

    printf("Digite o nome da cidade: ");
    fgets(nomeCidade1, TAM_NOME, stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = '\0';

    printf("Digite a população: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lu", &populacao1);

    printf("Digite a área em km²: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &pib1);

    printf("Digite a quantidade de pontos turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &pontosTuristicos1);

    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;

    // ---------------- Carta 2 ----------------
    char estado2;
    char codigo2[TAM_CODIGO];
    char nomeCidade2[TAM_NOME];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;
    float densidade2, pibPerCapita2;

    printf("\nCadastro da Carta 2\n");

    printf("Digite o estado (letra de A a H): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, " %c", &estado2);

    printf("Digite o código da carta (ex: A02): ");
    fgets(codigo2, TAM_CODIGO, stdin);
    codigo2[strcspn(codigo2, "\n")] = '\0';

    printf("Digite o nome da cidade: ");
    fgets(nomeCidade2, TAM_NOME, stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = '\0';

    printf("Digite a população: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lu", &populacao2);

    printf("Digite a área em km²: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &pib2);

    printf("Digite a quantidade de pontos turísticos: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &pontosTuristicos2);

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // ---------------- Comparação de Cartas ----------------
    printf("\nComparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%c): ", nomeCidade1, estado1);
    imprimirPopulacaoFormatada(populacao1);
    printf("\n");

    printf("Carta 2 - %s (%c): ", nomeCidade2, estado2);
    imprimirPopulacaoFormatada(populacao2);
    printf("\n");

    if (populacao1 > populacao2) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
