/*
    Nome dos participantes do grupo:  
Andre Franco Raineri 321.636-81
Luana Miho Yasuda 421.486-77
Lucas Kenzo Kawamoto 421.456-51
*/

#include <stdio.h>

int main()
{
    int matriz[3][3], linha, coluna, numero;

    printf("Entre com os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Elemento a[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nEntre com um número para multiplicar uma LINHA: ");
    scanf("%d", &numero);
    printf("Entre com a linha que deseja multiplicar (de 1 a 3): ");
    scanf("%d", &linha);
    linha--; // índice do array
    for (int j = 0; j < 3; j++)
    {
        matriz[linha][j] *= numero;
    }

    printf("\nMatriz com a linha %d multiplicada por %d:\n", linha + 1, numero);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nEntre com um número para multiplicar uma COLUNA: ");
    scanf("%d", &numero);
    printf("Digite a coluna que deseja multiplicar (de 1 a 3): ");
    scanf("%d", &coluna);
    coluna--; // índice do array
    for (int i = 0; i < 3; i++)
    {
        matriz[i][coluna] *= numero;
    }

    printf("\nMatriz com a coluna %d multiplicada por %d:\n", coluna + 1, numero);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
