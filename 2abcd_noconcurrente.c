// tiempo_secuencial_verbose.c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fin;
    
    inicio = clock();
    
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
    
    fin = clock();
    
    double tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Tiempo transcurrido: %f segundos ===\n", tiempo_transcurrido);
    
    return 0;
}