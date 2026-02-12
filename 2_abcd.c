// tiempo_secuencial.c
#include <stdio.h>
#include <time.h>

int main() {
    clock_t inicio, fin; // Parte b: Declarar dos variables de tipo clock_t
    
    inicio = clock(); // Parte b: Ejecutar clock() justo ANTES del primer ciclo
    
    // Parte a: Tres ciclos for consecutivos de un millón de iteraciones
    for(int i = 0; i < 1000000; i++) {
        // No hace nada
    }
    
    for(int i = 0; i < 1000000; i++) {
        // No hace nada
    }
    
    for(int i = 0; i < 1000000; i++) {
        // No hace nada
    }
 
    fin = clock();  // Parte b: Ejecutar clock() justo DESPUÉS del último ciclo
    
    double tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC; // Parte c: Calcular la diferencia y convertir a double
    
    printf("Tiempo transcurrido: %f segundos\n", tiempo_transcurrido); // Parte d: Desplegar el resultado con %f
    
    return 0;
}