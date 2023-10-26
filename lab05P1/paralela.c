#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double f(double x) {
return exp(x);
}

double trapezoidal_rule_parallel(double a, double b, int n) {
double h = (b - a) / n;
double sum = 0.0;

#pragma omp parallel for reduction(+:sum)
for (int i = 1; i < n; i++) {
double x = a + i * h;
sum += f(x);
}
sum +=(f(a)+f(b))/2.0;
return sum * h;
}

int main() {
double a = 0.0; // Limit inferior
double b = 1.0; // Limit superior
int n = 1000000; // Número de subdivisões

double result = trapezoidal_rule_parallel(a, b, n);
printf("Resultado: %f\n", result);

return 0;
}

