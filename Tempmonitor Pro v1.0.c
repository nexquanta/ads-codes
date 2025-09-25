#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo constantes para melhor organização
#define MAX_DIAS 31

// Função para limpar o buffer do stdin
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir tela de boas-vindas
void exibirBoasVindas() {
    printf("===============================================\n");
    printf("        TEMPMONITOR PRO v1.0\n");
    printf("    Sistema de Monitoramento de Temperaturas\n");
    printf("-----------------------------------------------\n");
    printf("         Produzido por Rodrigo Correia Diniz\n");
    printf("           Análise e Desenvolvimento de Sistemas\n");
    printf("===============================================\n\n");
}

// Função para ler as temperaturas do usuário
void lerTemperaturas(float temperaturas[], int numDias, char nomeMes[]) {
    printf("\nENTRADA DE DADOS - %s (%d dias)\n", nomeMes, numDias);
    printf("-------------------------------------------\n");
    printf("Por favor, insira a temperatura máxima de cada dia:\n\n");
    
    // Loop principal para ler TODAS as temperaturas
    for (int i = 0; i < numDias; i++) {
        int leituraOk = 0;
        
        // Loop para garantir entrada válida para cada dia
        while (!leituraOk) {
            printf("Digite a temperatura máxima do dia %02d/%s: ", i + 1, nomeMes);
            fflush(stdout);
            
            if (scanf("%f", &temperaturas[i]) == 1) {
                // Validação da temperatura
                if (temperaturas[i] >= -50 && temperaturas[i] <= 60) {
                    leituraOk = 1; // Marca como leitura bem-sucedida
                    printf("OK - Temperatura do dia %02d: %.2f°C registrada!\n\n", i + 1, temperaturas[i]);
                } else {
                    printf("ERRO - Temperatura inválida! Digite um valor entre -50°C e 60°C.\n\n");
                }
            } else {
                printf("ERRO - Entrada inválida! Digite um número válido.\n\n");
            }
            
            // Limpa o buffer após cada tentativa
            limparBuffer();
        }
    }
    
    // Só depois de registrar TODAS as temperaturas, mostra o resumo
    printf("SUCESSO - Todas as %d temperaturas foram registradas!\n", numDias);
    printf("\nResumo das temperaturas inseridas:\n");
    printf("----------------------------------\n");
    for (int i = 0; i < numDias; i++) {
        printf("Dia %02d: %.2f°C\n", i + 1, temperaturas[i]);
    }
    
    printf("\nPressione Enter para continuar para o menu de análises...");
    // Aguarda especificamente por uma nova linha (Enter)
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\n");
}

// Função para calcular estatísticas
void calcularEstatisticas(float temperaturas[], int numDias, 
                         float *tempMedia, float *tempMax, float *tempMin,
                         int *diaMax, int *diaMin) {
    
    *tempMax = temperaturas[0];
    *tempMin = temperaturas[0];
    *diaMax = 1;
    *diaMin = 1;
    float soma = temperaturas[0];
    
    // Percorre o vetor calculando as estatísticas
    for (int i = 1; i < numDias; i++) {
        soma += temperaturas[i];
        
        // Verifica temperatura máxima
        if (temperaturas[i] > *tempMax) {
            *tempMax = temperaturas[i];
            *diaMax = i + 1;
        }
        
        // Verifica temperatura mínima
        if (temperaturas[i] < *tempMin) {
            *tempMin = temperaturas[i];
            *diaMin = i + 1;
        }
    }
    
    *tempMedia = soma / numDias;
}

// Função para contar dias acima da média
int contarDiasAcimaMedia(float temperaturas[], int numDias, float media) {
    int contador = 0;
    
    for (int i = 0; i < numDias; i++) {
        if (temperaturas[i] > media) {
            contador++;
        }
    }
    
    return contador;
}

// Função para exibir relatório estatístico
void exibirRelatorio(float temperaturas[], int numDias, char nomeMes[]) {
    float tempMedia, tempMax, tempMin;
    int diaMax, diaMin;
    
    // Calcula as estatísticas
    calcularEstatisticas(temperaturas, numDias, &tempMedia, &tempMax, 
                        &tempMin, &diaMax, &diaMin);
    
    int diasAcimaMedia = contarDiasAcimaMedia(temperaturas, numDias, tempMedia);
    
    printf("RELATÓRIO ESTATÍSTICO - %s\n", nomeMes);
    printf("==========================================\n");
    printf("Temperatura Média:      %.2f°C\n", tempMedia);
    printf("Temperatura Máxima:     %.2f°C (Dia %d)\n", tempMax, diaMax);
    printf("Temperatura Mínima:     %.2f°C (Dia %d)\n", tempMin, diaMin);
    printf("Amplitude Térmica:      %.2f°C\n", tempMax - tempMin);
    printf("Dias acima da média:    %d dias\n", diasAcimaMedia);
    printf("Dias abaixo da média:   %d dias\n", numDias - diasAcimaMedia);
    printf("==========================================\n\n");
}

// Função BÔNUS: Exibir gráfico de linha das temperaturas (otimizado para OnlineGDB)
void exibirGrafico(float temperaturas[], int numDias, char nomeMes[]) {
    printf("GRÁFICO DE TEMPERATURAS - %s\n", nomeMes);
    printf("================================================\n");
    
    // Encontra valores para normalização
    float tempMax = temperaturas[0], tempMin = temperaturas[0];
    for (int i = 1; i < numDias; i++) {
        if (temperaturas[i] > tempMax) tempMax = temperaturas[i];
        if (temperaturas[i] < tempMin) tempMin = temperaturas[i];
    }
    
    printf("Temperatura máxima: %.1f°C | Temperatura mínima: %.1f°C\n\n", tempMax, tempMin);
    
    // Gráfico simplificado em formato de barras horizontais
    printf("Gráfico de Barras (cada '*' representa ~2°C):\n");
    printf("Dia | Temp(°C) | Gráfico\n");
    printf("----|----------|");
    for(int i = 0; i < 30; i++) printf("-");
    printf("\n");
    
    for (int i = 0; i < numDias; i++) {
        int barras = (int)(temperaturas[i] / 2); // Escala: cada '*' = ~2°C
        if (barras < 1) barras = 1;
        if (barras > 30) barras = 30;
        
        printf("%2d  |  %6.1f  | ", i + 1, temperaturas[i]);
        for (int j = 0; j < barras; j++) {
            printf("*");
        }
        printf(" (%.1f°C)\n", temperaturas[i]);
    }
    
    printf("----|----------|");
    for(int i = 0; i < 30; i++) printf("-");
    printf("\n\n");
    
    // Gráfico de linha ASCII simplificado
    printf("Gráfico de Linha (conectando as temperaturas):\n");
    printf("°C  |");
    for(int i = 0; i < numDias && i < 30; i++) printf("----");
    printf("\n");
    
    // Desenha uma representação simples da linha
    for (int i = 0; i < numDias - 1 && i < 29; i++) {
        if (temperaturas[i+1] > temperaturas[i]) {
            printf("%.0f -> %.0f (subiu)\n", temperaturas[i], temperaturas[i+1]);
        } else if (temperaturas[i+1] < temperaturas[i]) {
            printf("%.0f -> %.0f (desceu)\n", temperaturas[i], temperaturas[i+1]);
        } else {
            printf("%.0f -> %.0f (estável)\n", temperaturas[i], temperaturas[i+1]);
        }
    }
    printf("\n");
}

// Função para exibir tabela de temperaturas
void exibirTabela(float temperaturas[], int numDias, char nomeMes[]) {
    printf("TABELA DE TEMPERATURAS - %s\n", nomeMes);
    printf("================================\n");
    printf(" Dia  | Temp.(°C) | Status\n");
    printf("------|-----------|----------\n");
    
    // Calcula média para status
    float soma = 0;
    for (int i = 0; i < numDias; i++) {
        soma += temperaturas[i];
    }
    float media = soma / numDias;
    
    // Exibe cada dia
    for (int i = 0; i < numDias; i++) {
        char status[12];
        if (temperaturas[i] > media + 5) {
            strcpy(status, "Muito Alto");
        } else if (temperaturas[i] > media) {
            strcpy(status, "Acima");
        } else if (temperaturas[i] < media - 5) {
            strcpy(status, "Muito Baixo");
        } else {
            strcpy(status, "Abaixo");
        }
        
        printf(" %2d   |   %6.2f  | %s\n", i + 1, temperaturas[i], status);
    }
    printf("================================\n\n");
}

// Função para pausar e aguardar entrada do usuário
void pausar() {
    printf("Pressione Enter para continuar...");
    limparBuffer();
    getchar();
    printf("\n");
}

// Função principal
int main() {
    // Declaração de variáveis
    float temperaturas[MAX_DIAS];
    char nomeMes[20];
    int numDias;
    int opcaoMenu;
    
    // Exibe tela de boas-vindas
    exibirBoasVindas();
    
    // Coleta informações básicas
    printf("Digite o nome do mês (ex: Janeiro, Fevereiro): ");
    scanf("%19s", nomeMes);
    
    printf("Digite o número de dias do mês (1-31): ");
    while (scanf("%d", &numDias) != 1) {
        printf("Entrada inválida! Digite um número entre 1 e 31: ");
        limparBuffer();
    }
    
    // Validação do número de dias
    while (numDias < 1 || numDias > 31) {
        printf("Número inválido! Digite entre 1 e 31 dias: ");
        while (scanf("%d", &numDias) != 1) {
            printf("Entrada inválida! Digite um número: ");
            limparBuffer();
        }
    }
    
    limparBuffer(); // Limpa o buffer antes de prosseguir
    
    // Debug: mostra os valores capturados
    printf("\nValores capturados:\n");
    printf("Mês: %s\n", nomeMes);
    printf("Número de dias: %d\n", numDias);
    
    // Mensagem clara sobre o próximo passo
    printf("\nAGORA VAMOS REGISTRAR AS TEMPERATURAS DIÁRIAS\n");
    printf("==============================================\n");
    
    // Lê as temperaturas - TODAS de uma vez
    lerTemperaturas(temperaturas, numDias, nomeMes);
    
    // Menu de opções - só aparece após TODAS as temperaturas serem inseridas
    do {
        printf("MENU DE ANÁLISES\n");
        printf("==================\n");
        printf("1. Exibir Relatório Estatístico\n");
        printf("2. Exibir Gráfico de Temperaturas\n");
        printf("3. Exibir Tabela Detalhada\n");
        printf("4. Inserir Novas Temperaturas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        
        while (scanf("%d", &opcaoMenu) != 1) {
            printf("Entrada inválida! Digite um número entre 1 e 5: ");
            limparBuffer();
        }
        limparBuffer();
        printf("\n");
        
        switch (opcaoMenu) {
            case 1:
                exibirRelatorio(temperaturas, numDias, nomeMes);
                break;
                
            case 2:
                exibirGrafico(temperaturas, numDias, nomeMes);
                break;
                
            case 3:
                exibirTabela(temperaturas, numDias, nomeMes);
                break;
                
            case 4:
                lerTemperaturas(temperaturas, numDias, nomeMes);
                break;
                
            case 5:
                printf("Obrigado por usar o TempMonitor Pro!\n");
                printf("Produzido por: Rodrigo Correia Diniz - ADS\n");
                printf("Sistema para análise eficiente de temperaturas.\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }
        
        if (opcaoMenu != 5 && opcaoMenu >= 1 && opcaoMenu <= 4) {
            pausar();
        }
        
    } while (opcaoMenu != 5);
    
    return 0;
}