#include <stdio.h>

int main() {

    int n;

    do
    {
        printf(" Digite um número ímpar: ");
        scanf("%d", &n);
    }
    while (n % 2 == 0);

    for (int i = 0; i <= (n / 2) + 1; i++)
    {
        for (int j = i + 1; j <= n - i; j++)
        {
            printf("%d ", j);
        }

        printf("\n");

        for (int j = 0; j < (i + 1) * 2; j++)
            printf(" ");
    }

    return 0;
}
