#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t hijo, nieto, bisnieto;  // Parte f: Declarar tres variables pid_t
    clock_t inicio, fin;  // Parte f: Declarar dos clock_t
    
    inicio = clock(); // Parte g: Llamada a clock() justo ANTES del fork()
    
    // Parte g: Primer fork() - crea el proceso hijo
    hijo = fork();
    
    if(hijo == 0) {
        // PROCESO HIJO
        
        nieto = fork();  // Parte h: El hijo hace otro fork() - crea el proceso nieto
        
        if(nieto == 0) {
            // PROCESO NIETO
            
            bisnieto = fork(); // Parte h: El nieto hace otro fork() - crea el proceso bisnieto
            
            if(bisnieto == 0) {
                // PROCESO BISNIETO
                for(int i = 0; i < 1000000; i++) { // Parte i: El bisnieto ejecuta un ciclo for de 1 millón de iteraciones
                }

                return 0;
            }
            // PROCESO NIETO (continuación después del else del if bisnieto)
            else {
                for(int i = 0; i < 1000000; i++) { // Parte i: El nieto ejecuta su propio ciclo for (EXCLUSIVAMENTE)
                }
                
                wait(NULL); // Parte i: El nieto espera a que termine el bisnieto
                
                return 0;
            }
        }
        // PROCESO HIJO (continuación después del else del if nieto)
        else {
            for(int i = 0; i < 1000000; i++) { // Parte j: El hijo ejecuta su propio ciclo for (EXCLUSIVAMENTE)

            }
            wait(NULL);  // Parte j: El hijo espera a que termine el nieto
            
            return 0;
        }
    }
    else {
        
        wait(NULL); // Parte k: El padre espera a que termine el hijo
        
        fin = clock(); // Parte k: Después de que el hijo termine, ejecutar clock()
        
        double tiempo_transcurrido = (double)(fin - inicio) / CLOCKS_PER_SEC;
        
        printf("Tiempo transcurrido (concurrente): %f segundos\n", tiempo_transcurrido);
    }
    
    return 0;
}