#include <stdio.h>

int main()
{
    int matriz[3][3], transposta[3][3];

    // Ler a matriz de teclado
    printf("Entre com os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Elemento a[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Criar a transposta
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }

    // Imprimir a matriz transposta
    printf("\nMatriz transposta:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
