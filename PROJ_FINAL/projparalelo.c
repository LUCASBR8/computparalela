#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(void) {
    int max_n = 1000;
    long double e = 1.0;
    int num_threads = 2;

    double start_seq, end_seq, seq_time;
    double start_par, end_par, par_time;

    // Sequencial
    start_seq = omp_get_wtime();
    for (int n = 1; n <= max_n; n++) {
        long double term = 1.0;
        for (int i = 1; i <= n; i++) {
            term /= (long double)i;
        }
        e += term;
    }
    end_seq = omp_get_wtime();
    seq_time = end_seq - start_seq;

    // Paralelo
    start_par = omp_get_wtime();
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
    end_par = omp_get_wtime();
    par_time = end_par - start_par;

    // Calculando e exibindo o speedup
    double speedup = seq_time / par_time;

    printf("Valor estimado de e com n=%d: %.15Lf\n", max_n, e);
    printf("Tempo sequencial: %lf segundos\n", seq_time);
    printf("Tempo paralelo: %lf segundos\n", par_time);
    printf("Speedup: %.2lf\n", speedup);

    return 0;
}
