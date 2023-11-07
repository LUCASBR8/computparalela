#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(void) {
    int max_n = 1000;
    long double e = 1.0;
    int num_threads = 2;

    double start, end, par_time;

    start = omp_get_wtime();

    #pragma omp parallel num_threads(num_threads)
    {
        long double local_e = 0.0;
        #pragma omp for
        for (int n = 1; n <= max_n; n++) {
            long double term = 1.0;
            for (int i = 1; i <= n; i++) {
                term /= (long double)i;
            }
            local_e += term;
        }
        #pragma omp atomic
        e += local_e;
    }

    end = omp_get_wtime();
    par_time = end - start;

    printf("Valor estimado de e com n=%d: %.15Lf\n", max_n, e);
    printf("Tempo paralelo: %lf segundos\n", par_time);

    return 0;
}
