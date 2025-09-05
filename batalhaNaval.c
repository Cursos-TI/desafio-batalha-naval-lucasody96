#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    int i, j, k;//controle do for
    int linha_h, coluna_h, linha_v, coluna_v, linha_dd, coluna_dd, linha_de, coluna_de;//váriaveis navios
    // Nível Novato - Posicionamento dos Navios
    // Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro [10][10];
    int linha[10];
    char coluna[10];//vetores representando as linhas (numeros) e colunas (letras)
    int sobreposicao = 0;// Flag para verificar sobreposição. Reiniciada para cada navio.


    //1 - preenchendo as colunas, linhas e tabuleiro
    //preenchendo as colunas com letras
    for (i = 0; i < 10; i++)
    {
        coluna[i] = 'A'+i;
        linha[i] = 1+i;
    }
    
    //preenchendo o tabuleiro com a água
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
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

    //Imprime o tabuleiro somente com água
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


    // Posicionando os 4 navios
    sobreposicao = 0;

    //Navio 1 (horizontal, 3 casas)
    linha_h = 4, coluna_h = 1;
    if (coluna_h + 3 <= 10)
    {
        for (k = 0; k < 3; k++)
        {
            tabuleiro[linha_h][coluna_h + k] = 3;
        } 
    }

    // Posicionando Navio 2 (Vertical, 3 casas)
    linha_v = 6, coluna_v = 8;
    sobreposicao = 0;

    if (linha_v + 3 <= 10)
    {
       for (k = 0; k < 3; k++)//validando a sobreposição primeiro
        {
            if (tabuleiro[linha_v + k][coluna_v] != 0)
            {
                sobreposicao = 1; 
                break;
            }
        }
         if (!sobreposicao)//Se não tiver sobreposição, posiciona
        {
            for (k = 0; k < 3; k++)
            {
                tabuleiro[linha_v + k][coluna_v] = 3;
            }
            
        } 
    }
    
    //Posicionando o navio 3 (diagonal para direita)
    linha_dd = 1, coluna_dd = 1;
    sobreposicao = 0;

    if ((linha_dd + 3 <= 10) && (coluna_dd + 3 <= 10))
    {

        for (k = 0; k < 3; k++)//validando a sobreposição primeiro
        {
            if (tabuleiro[linha_dd + k][coluna_dd + k] != 0)
            {
                sobreposicao = 1; 
                break;
            }
        }

         if (!sobreposicao)//Se não tiver sobreposição, posiciona
        {
            for (k = 0; k < 3; k++)
            {
                tabuleiro[linha_dd + k][coluna_dd + k] = 3;
            }
            
        } 
    }

    //posicionando o navio 4 (diagonal para esquerda)
    linha_de = 1, coluna_de = 8;
    sobreposicao = 0;

    if ((linha_de + 3 <= 10) && (coluna_de - (3-1) >= 0))
    {

        for (k = 0; k < 3; k++)//validando a sobreposição primeiro
        {
            if (tabuleiro[linha_de + k][coluna_de - k] != 0)
            {
                sobreposicao = 1; 
                break;
            }
        }

        if (!sobreposicao)//Se não tiver sobreposição, posiciona
        {
            for (k = 0; k < 3; k++)
            {
                tabuleiro[linha_de + k][coluna_de - k] = 3;
            }
            
        } 
    }



    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("Veja os navios do tabuleiro representados por 3.\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");

    //impressão do cabeçalho
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
