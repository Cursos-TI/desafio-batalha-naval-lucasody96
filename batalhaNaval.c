#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

// A lógica cria um triângulo que se expande, limitado a altura para 3 linhas.
void gerarHabilidadeCone(int matriz[5][5]) {
    int centro = 5 / 2; // coluna central
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Preenche só até a linha 2 (3 níveis do cone)
            if (i <= 2 && abs(j - centro) <= i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para gerar a matriz da habilidade em Cruz
// afeta a linha central e a coluna central.
void gerarHabilidadeCruz(int matriz[5][5]) {
    int i, j;
    int centro = 5 / 2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // A condição é verdadeira se o ponto estiver na linha central OU na coluna central.
            if (i == centro || j == centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Função para gerar a matriz da habilidade em Octaedro (Losango)
// Um losango é definido pela distância do centro. 
void gerarHabilidadeOctaedro(int matriz[5][5]) {
    int i, j;
    int centro = 5 / 2;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // A soma das distâncias vertical e horizontal do centro deve ser <= ao raio (centro).
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int origem_linha, int origem_coluna) {
    int i_hab, j_hab;
    int centro_hab = 5 / 2;

    for (i_hab = 0; i_hab < 5; i_hab++) {
        for (j_hab = 0; j_hab < 5; j_hab++) {
            if (habilidade[i_hab][j_hab] == 1) {
                int offset_linha = i_hab - centro_hab;
                int offset_coluna = j_hab - centro_hab;

                int linha_no_tabuleiro = origem_linha + offset_linha;
                int coluna_no_tabuleiro = origem_coluna + offset_coluna;

                if ((linha_no_tabuleiro >= 0 && linha_no_tabuleiro < 10) &&
                    (coluna_no_tabuleiro >= 0 && coluna_no_tabuleiro < 10)) {
                    
                    // Marca qualquer coisa (0 ou 3) como 5 → mostrando dano
                    tabuleiro[linha_no_tabuleiro][coluna_no_tabuleiro] = 5;
                }
            }
        }
    }
}



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

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("Tabuleiro aventureiro em que o 0 representa a água e 3 os navios!\n");
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    // Posicionando os 4 navios 
    sobreposicao = 0;

    //Navio 1 
    linha_h = 4, coluna_h = 1;
    if (coluna_h + 3 <= 10)
    {
        for (k = 0; k < 3; k++)
        {
            tabuleiro[linha_h][coluna_h + k] = 3;
        } 
    }

    // Navio 2 
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
    
    //Posicionando o navio 3
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

    // Nível Mestre - Habilidades Especiais com Matrizes
    // 1. Criar as matrizes de habilidade (5x5)
    int hab_cone[5][5];
    int hab_cruz[5][5];
    int hab_octaedro[5][5];

    // 2. Gerar os padrões de efeito dinamicamente usando as funções
    gerarHabilidadeCone(hab_cone);
    gerarHabilidadeCruz(hab_cruz);
    gerarHabilidadeOctaedro(hab_octaedro);

    // 3. Definir pontos de origem e aplicar as habilidades no tabuleiro
    // As coordenadas de origem são o CENTRO onde a habilidade será aplicada.
    aplicarHabilidade(tabuleiro, hab_cone, 2, 4);      // Ponta do cone, na linha 1
    aplicarHabilidade(tabuleiro, hab_cruz, 7, 3);      // Cruz na parte de baixo
    aplicarHabilidade(tabuleiro, hab_octaedro, 3, 7);  // Octaedro (losango) perto da borda


    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("Tabuleiro nível mestre em que o 0 representa a água e 3 os navios e 5 as habilidades especiais!\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
    //impressão do cabeçalho
    printf("   ");
    for (i = 0; i < 10; i++)
    {
        printf ("%c ", coluna[i]);
    }
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("%2d ", i + 1);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
