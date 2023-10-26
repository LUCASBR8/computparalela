#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x) {
return exp(x);
}

int main() {
double a = 0.0; // Limite inferior
double b = 1.0; // Limite superior
int n = 1000000; // Número de divisões
double h = (b - a) / n;
double approx = (f(a) + f(b)) / 2.0;

clock_t start_time, end_time;
start_time = clock();

for (int i = 1; i <= n - 1; i++) {
double x_i = a + i * h;
approx += f(x_i);
}

approx = h * approx;

end_time = clock();
double cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

printf("Resultado da integral aproximada: %lf\n", approx);
printf("Tempo de execução: %lf segundos\n", cpu_time_used);

return 0;
}
