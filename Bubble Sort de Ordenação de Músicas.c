/*
===============================================================
                    SISTEMA DE ORDENACAO
                  Algoritmo: Bubble Sort
              Aplicado em Audiencia de Musicas
===============================================================
 Desenvolvido por: Rodrigo Correia Diniz
 Data: Setembro 2025
 Linguagem: C
 Proposito: Demonstracao do algoritmo Bubble Sort em dados
            de audiencia de musicas com ordenacao crescente
            e decrescente
===============================================================
*/

#include <stdio.h>
#include <stdlib.h>

// Função para exibir o vetor de forma formatada
void exibirVetor(int vetor[], int tamanho, char* titulo) {
    printf("\n%s\n", titulo);
    printf("===============================================================\n");
    
    for(int i = 0; i < tamanho; i++) {
        printf("Musica %d: %d reproducoes\n", i+1, vetor[i]);
    }
    printf("===============================================================\n");
}

// Função que implementa o algoritmo Bubble Sort em ordem crescente
void bubbleSortCrescente(int vetor[], int tamanho) {
    printf("\nAplicando Bubble Sort em ordem CRESCENTE...\n");
    
    // Loop externo: controla o numero de passadas
    for(int i = 0; i < tamanho - 1; i++) {
        
        // Loop interno: compara elementos adjacentes
        for(int j = 0; j < tamanho - 1 - i; j++) {
            
            // Se o elemento atual for maior que o proximo, troca as posicoes
            if(vetor[j] > vetor[j + 1]) {
                
                // Processo de troca usando variavel auxiliar
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                
                printf("   Trocou: %d <-> %d\n", vetor[j+1], vetor[j]);
            }
        }
    }
    printf("Ordenacao crescente concluida!\n");
}

// Função que implementa o algoritmo Bubble Sort em ordem decrescente
void bubbleSortDecrescente(int vetor[], int tamanho) {
    printf("\nAplicando Bubble Sort em ordem DECRESCENTE...\n");
    
    // Loop externo: controla o numero de passadas
    for(int i = 0; i < tamanho - 1; i++) {
        
        // Loop interno: compara elementos adjacentes
        for(int j = 0; j < tamanho - 1 - i; j++) {
            
            // Se o elemento atual for menor que o proximo, troca as posicoes
            if(vetor[j] < vetor[j + 1]) {
                
                // Processo de troca usando variavel auxiliar
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                
                printf("   Trocou: %d <-> %d\n", vetor[j+1], vetor[j]);
            }
        }
    }
    printf("Ordenacao decrescente concluida!\n");
}

// Função para copiar um vetor (para preservar os dados originais)
void copiarVetor(int origem[], int destino[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    // Definindo constante para o tamanho do vetor
    #define TAMANHO 10
    
    // Vetor com dados de audiencia de musicas (numero de reproducoes)
    // Dados simulados representando diferentes niveis de popularidade
    int audienciaOriginal[TAMANHO] = {
        15420,  // Musica 1
        8930,   // Musica 2
        25670,  // Musica 3
        3450,   // Musica 4
        19800,  // Musica 5
        12300,  // Musica 6
        7650,   // Musica 7
        31200,  // Musica 8
        9870,   // Musica 9
        18540   // Musica 10
    };
    
    // Vetores auxiliares para preservar os dados originais
    int audienciaCrescente[TAMANHO];
    int audienciaDecrescente[TAMANHO];
    
    // Copiando dados originais para os vetores auxiliares
    copiarVetor(audienciaOriginal, audienciaCrescente, TAMANHO);
    copiarVetor(audienciaOriginal, audienciaDecrescente, TAMANHO);
    
    // Cabecalho do programa
    printf("===============================================================\n");
    printf("           SISTEMA DE ORDENACAO - AUDIENCIA DE MUSICAS        \n");
    printf("                    Algoritmo: Bubble Sort                    \n");
    printf("---------------------------------------------------------------\n");
    printf("              Desenvolvido por: Rodrigo Correia Diniz         \n");
    printf("                        Setembro 2025                         \n");
    printf("===============================================================\n");
    
    // 1. Exibindo dados originais
    exibirVetor(audienciaOriginal, TAMANHO, "DADOS ORIGINAIS - Numero de reproducoes por musica:");
    
    // 2. Aplicando Bubble Sort em ordem crescente
    bubbleSortCrescente(audienciaCrescente, TAMANHO);
    exibirVetor(audienciaCrescente, TAMANHO, "DADOS ORDENADOS - Ordem CRESCENTE (menor para maior):");
    
    // 3. Aplicando Bubble Sort em ordem decrescente
    bubbleSortDecrescente(audienciaDecrescente, TAMANHO);
    exibirVetor(audienciaDecrescente, TAMANHO, "DADOS ORDENADOS - Ordem DECRESCENTE (maior para menor):");
    
    // Analise dos resultados
    printf("\nANALISE DOS RESULTADOS:\n");
    printf("===============================================================\n");
    printf("Musica mais ouvida: %d reproducoes\n", audienciaDecrescente[0]);
    printf("Musica menos ouvida: %d reproducoes\n", audienciaCrescente[0]);
    
    // Calculando media de reproducoes
    int soma = 0;
    for(int i = 0; i < TAMANHO; i++) {
        soma += audienciaOriginal[i];
    }
    printf("Media de reproducoes: %.1f\n", (float)soma / TAMANHO);
    
    printf("\nO algoritmo Bubble Sort compara pares de elementos adjacentes\n");
    printf("e os troca quando estao fora da ordem desejada, repetindo\n");
    printf("esse processo ate que todos estejam organizados.\n");
    
    printf("\n===============================================================\n");
    printf("           Programa desenvolvido por: Rodrigo Correia Diniz    \n");
    printf("                         Setembro 2025                        \n");
    printf("===============================================================\n");
    
    return 0;
}