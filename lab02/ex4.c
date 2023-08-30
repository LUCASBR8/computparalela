/*
    Nome dos participantes do grupo:  
Andre Franco Raineri 321.636-81
Luana Miho Yasuda 421.486-77
Lucas Kenzo Kawamoto 421.456-51
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nome1[20], nome2[20], temp[20];
    int comparacao;

    printf(" Digite um nome\n");
    scanf("%s", nome1);
    printf("\n Digite outro nome:\n");
    scanf("%s", nome2);

    comparacao = strcmp(nome1, nome2);

    if (comparacao > 0)
    {
        // Se nome1 vem depois de nome2, troca os nomes
        strcpy(temp, nome1);
        strcpy(nome1, nome2);
        strcpy(nome2, temp);
    }

    printf("\nEm ordem alfabética ficariam: %s e %s\n", nome1, nome2);

    return 0;
}
