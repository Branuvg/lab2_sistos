// tiempo_secuencial_verbose.c (CORREGIDO)
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main() {
    struct timeval inicio, fin;
    
    gettimeofday(&inicio, NULL);
    
    // Primer ciclo con print
    for(int i = 0; i < 1000000; i++) {
        printf("Ciclo 1 - Iteración: %d\n", i);
    }
    
    // Segundo ciclo con print
    for(int i = 0; i < 1000000; i++) {
        printf("Ciclo 2 - Iteración: %d\n", i);
    }
    
    // Tercer ciclo con print
    for(int i = 0; i < 1000000; i++) {
        printf("Ciclo 3 - Iteración: %d\n", i);
    }
    
    gettimeofday(&fin, NULL);
    
    double tiempo_transcurrido = (fin.tv_sec - inicio.tv_sec) + 
                                 (fin.tv_usec - inicio.tv_usec) / 1000000.0;
    
    printf("\n=== Tiempo transcurrido: %f segundos ===\n", tiempo_transcurrido);
    
    return 0;
}