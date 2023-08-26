#include <stdio.h>

#define linhas 3
#define colunas 3

// FUNCAO CRIADA PARA O EXERCICIO
void transporMatriz(int matriz[linhas][colunas], int transposta[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            transposta[j][i] = matriz[i][j];
        }
    }
}

// TESTE
int main()
{
    int matriz[linhas][colunas], transposta[linhas][colunas];

    // Ler os elementos da matriz do teclado
    printf("Entre com os elementos da matriz %dx%d:\n", linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Elemento a[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calcular a transposta da matriz
    transporMatriz(matriz, transposta);

    // Imprimir a sua transposta
    printf("\nTransposta da matriz:\n");
    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
