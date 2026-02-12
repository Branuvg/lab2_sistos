// zombie_long.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t hijo;
    
    hijo = fork();
    
    if(hijo == 0) {
        // PROCESO HIJO
        printf("Hijo: Mi PID es %d, comenzando conteo...\n", getpid());
        
        // Conteo de 1 a 4,000,000 (o más si es muy rápido)
        for(int i = 1; i <= 4000000; i++) {
            if(i % 100000 == 0) {  // Imprimir cada 100,000 para ver progreso
                printf("Hijo: %d\n", i);
            }
        }
        
        printf("Hijo: Terminé el conteo, finalizando...\n");
        return 0;
    }
    else {
        // PROCESO PADRE
        printf("Padre: Mi PID es %d, hijo PID %d\n", getpid(), hijo);
        printf("Padre: Entrando en ciclo infinito (sin wait)...\n");
        
        // Ciclo infinito
        while(1) {
            sleep(1);
        }
    }
    
    return 0;
}