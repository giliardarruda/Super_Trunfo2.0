#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM_CODIGO 10
#define TAM_NOME 100

// Função para imprimir população com separador de milhar
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

    printf("Bem-vindo ao jogo! :)\n");

    char buffer[100];

    // ------------- Cadastro das Cartas -------------

    // Carta 1
    char estado1, codigo1[TAM_CODIGO], nomeCidade1[TAM_NOME];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;
    float densidade1, pibPerCapita1;

    printf("\nCadastro da Carta 1\n");

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

    // Carta 2
    char estado2, codigo2[TAM_CODIGO], nomeCidade2[TAM_NOME];
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

    // --------- Loop para Rodadas ---------
    char jogarNovamente;
    do {
        int opcao1, opcao2;
        float valor1_c1 = 0, valor2_c1 = 0, valor1_c2 = 0, valor2_c2 = 0;

        // Menu de atributos
        printf("\nEscolha o primeiro atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos turísticos\n");
        printf("5 - Densidade demográfica\n");

        do {
            printf("Digite sua escolha (1 a 5): ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &opcao1);

            if (opcao1 < 1 || opcao1 > 5) {
                printf("Opção inválida! Tente novamente.\n");
            }
        } while (opcao1 < 1 || opcao1 > 5);

        // Segundo atributo (dinâmico)
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != opcao1) {
                switch (i) {
                    case 1: printf("%d - População\n", i); break;
                    case 2: printf("%d - Área\n", i); break;
                    case 3: printf("%d - PIB\n", i); break;
                    case 4: printf("%d - Pontos turísticos\n", i); break;
                    case 5: printf("%d - Densidade demográfica\n", i); break;
                }
            }
        }

        do {
            printf("Digite sua escolha (1 a 5): ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%d", &opcao2);

            if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5) {
                printf("Opção inválida! Tente novamente.\n");
            }
        } while (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5);

        // Obter valores para comparação
        for (int i = 1; i <= 2; i++) {
            int opcao = (i == 1) ? opcao1 : opcao2;
            switch (opcao) {
                case 1: // População
                    if (i == 1) { valor1_c1 = populacao1; valor1_c2 = populacao2; }
                    else       { valor2_c1 = populacao1; valor2_c2 = populacao2; }
                    break;
                case 2: // Área
                    if (i == 1) { valor1_c1 = area1; valor1_c2 = area2; }
                    else       { valor2_c1 = area1; valor2_c2 = area2; }
                    break;
                case 3: // PIB
                    if (i == 1) { valor1_c1 = pib1; valor1_c2 = pib2; }
                    else       { valor2_c1 = pib1; valor2_c2 = pib2; }
                    break;
                case 4: // Pontos turísticos
                    if (i == 1) { valor1_c1 = pontosTuristicos1; valor1_c2 = pontosTuristicos2; }
                    else       { valor2_c1 = pontosTuristicos1; valor2_c2 = pontosTuristicos2; }
                    break;
                case 5: // Densidade demográfica
                    if (i == 1) { valor1_c1 = densidade1; valor1_c2 = densidade2; }
                    else       { valor2_c1 = densidade1; valor2_c2 = densidade2; }
                    break;
            }
        }

        // Comparações - vamos utilizar a soma dos valores para determinar o vencedor
        // como está sendo feito na parte de exibição do resultado
        float soma1 = valor1_c1 + valor2_c1;
        float soma2 = valor1_c2 + valor2_c2;

        printf("\n--- Resultado da Comparação ---\n");
        
        // Formatação correta para os valores
        printf("%s: ", nomeCidade1);
        if (opcao1 == 1) {
            imprimirPopulacaoFormatada((unsigned long int)valor1_c1);
            printf(" + ");
        } else {
            printf("%.2f + ", valor1_c1);
        }
        
        if (opcao2 == 1) {
            imprimirPopulacaoFormatada((unsigned long int)valor2_c1);
            printf(" = ");
        } else {
            printf("%.2f = ", valor2_c1);
        }
        
        printf("%.2f\n", soma1);
        
        printf("%s: ", nomeCidade2);
        if (opcao1 == 1) {
            imprimirPopulacaoFormatada((unsigned long int)valor1_c2);
            printf(" + ");
        } else {
            printf("%.2f + ", valor1_c2);
        }
        
        if (opcao2 == 1) {
            imprimirPopulacaoFormatada((unsigned long int)valor2_c2);
            printf(" = ");
        } else {
            printf("%.2f = ", valor2_c2);
        }
        
        printf("%.2f\n", soma2);

        // Verifica e exibe o vencedor corretamente
        if (soma1 > soma2) {
            printf("\nVencedora: %s!\n", nomeCidade1);
        } else if (soma2 > soma1) {
            printf("\nVencedora: %s!\n", nomeCidade2);
        } else {
            printf("\nResultado: Empate!\n");
        }

        // Jogar novamente?
        printf("\nDeseja jogar outra rodada? (s/n): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, " %c", &jogarNovamente);

    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    printf("\nObrigado por jogar! Até a próxima. :)\n");

    return 0;
}