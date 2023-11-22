Nome dos participantes do grupo: Andre Franco Raineri 321.636-81 Luana Miho Yasuda 421.486-77 Lucas Kenzo Kawamoto 421.456-51

Como compilar o programa na plataforma disponibilizada? Resposta : gcc -o nome do arquivo

Como executar o programa? Resposta: Precisa colocar o ./ e o nome do programa

Como comprovar que os resultados propostos foram alcançados Resposta: esta demonstrado no printscreen


As bibliotecas incluídas no  código têm as seguintes funcionalidades:

#include <stdio.h>: Esta é a biblioteca padrão de entrada e saída em C. Ela fornece funções para entrada (como scanf) e saída (como printf) de dados.
#include <math.h>: Esta biblioteca fornece funções matemáticas em C. Algumas das funções comuns incluem operações matemáticas básicas, funções trigonométricas, funções exponenciais, logaritmos, etc. Neste código, a função pow não está sendo utilizada, mas ela faz parte dessa biblioteca.
#include <omp.h>: Esta é a biblioteca OpenMP, que é usada para programação paralela em C e outras linguagens. Ela fornece diretivas de compilação (por exemplo, #pragma omp) e funções de API para criar programas paralelos. Neste código, a função omp_get_wtime() é usada para medir o tempo de execução e as diretivas #pragma omp são utilizadas para criar uma região paralela.

