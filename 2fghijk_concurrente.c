// tiempo_concurrente_verbose.c
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t hijo, nieto, bisnieto;
    clock_t inicio, fin;
    
    inicio = clock();
    
    hijo = fork();
    
    if(hijo == 0) {
        // PROCESO HIJO
        nieto = fork();
        
        if(nieto == 0) {
            // PROCESO NIETO
            bisnieto = fork();
            
            if(bisnieto == 0) {
                // PROCESO BISNIETO
                for(int i = 0; i < 1000000; i++) {
                    printf("Bisnieto - Iteración: %d\n", i);
                }
                return 0;
            }
            else {
                // PROCESO NIETO
                for(int i = 0; i < 1000000; i++) {
                    printf("Nieto - Iteración: %d\n", i);
                }
                wait(NULL);
                return 0;
            }
        }
        else {
            // PROCESO HIJO
            for(int i = 0; i < 1000000; i++) {
                printf("Hijo - Iteración: %d\n", i);
            }
            wait(NULL);
            return 0;
        }
    }
    else {
        // PROCESO PADRE
        wait(NULL);
        fin = clock();
        double tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
        printf("\n=== Tiempo transcurrido (concurrente): %f segundos ===\n", tiempo_transcurrido);
    }
    
    return 0;
}