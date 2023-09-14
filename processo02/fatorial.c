#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);

    int total = 1;
    pid_t pid;

    for (int i = 1; i <= num; ++i) {
        pid = fork();
        if (pid < 0) {
            perror("Erro no fork");
            return 1;
        } else if (pid == 0) {
            // esse é o processo do filho 
            int fact = 1;
            for (int j = 1; j <= i; ++j) {
                fact *= j;
            }
            printf("Processo do filho %d: Fatorial de %d é %d\n", getpid(), i, fact);
            return 0;
        }
    }

    // Esse é o processo dos pais, precisa esperar do filho tambem
    int status;
    for (int i = 1; i <= num; ++i) {
        wait(&status);
    }

    printf("Todos os processos dos filhos foram completados.\n");

    return 0;
}
