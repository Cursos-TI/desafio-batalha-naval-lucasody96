#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    int i, j;
    // Nível Novato - Posicionamento dos Navios
    // Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro [10][10];
    int linha[10];
    char coluna[10];//vetores representando as linhas (numeros) e colunas (letras)


    //1 - preenchendo as colunas, linhas e tabuleiro
    //preenchendo as colunas
    for (i = 0; i < 10; i++)
    {
        coluna[i] = 'A'+i;
    }
    
    //preenchendo o vetor com as letras
    for (i = 0; i < 10; i++)
    {
        linha[i] = 1+i;
    }

    //preenchendo o tabuleiro com a água
    for (i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
        
    }
    // Introdução do jogo
    printf("############### Bem-vindo ao desafio Batalha Naval! ################\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    printf("Nesse primeiro momento, segue como é posicionado nosso tabuleiro!\n");
    printf("As letras representam as colunas e os números as linhas e o 0 a água\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

    //2 - imprimir em tela a coluna, linha e tabuleiro
    printf("   ");
    for (i = 0; i < 10; i++)
    {
        printf ("%c ", coluna[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf ("%2d ", linha[i]);// O formato '%2d' garante que o 10 (com 2 dígitos) não vai desalinhar o tabuleiro

        for (j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }
    printf("\n");

    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Veja os dois navios do tabuleiro representados por 3.\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");

     // Posicionando Navio 1 (Horizontal, 3 casas)
    // Na linha 3, colunas 2, 3 e 4
    tabuleiro[3][2] = 3;
    tabuleiro[3][3] = 3;
    tabuleiro[3][4] = 3;

    // Posicionando Navio 2 (Vertical, 3 casas)
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    printf("   ");
    for (i = 0; i < 10; i++)
    {
        printf ("%c ", coluna[i]);
    }
    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf ("%2d ", linha[i]);// O formato '%2d' garante que o 10 (com 2 dígitos) não vai desalinhar o tabuleiro

        for (j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);

        }
        printf("\n");
        
    }
    printf("\n");



    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
