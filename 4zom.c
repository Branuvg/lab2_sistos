#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t hijo;
    
    hijo = fork();
    
    if(hijo == 0) {
        // PROCESO HIJO
        printf("Hijo: Mi PID es %d, mi padre es %d\n", getpid(), getppid());
        printf("Hijo: Termino mi ejecución\n");
        return 0;  // El hijo termina aquí
    }
    else {
        // PROCESO PADRE
        printf("Padre: Mi PID es %d, creé al hijo %d\n", getpid(), hijo);
        printf("Padre: Entrando en ciclo infinito...\n");
        
        // Ciclo infinito - el padre NUNCA hace wait()
        while(1) {
            sleep(1);  // Dormir 1 segundo para no saturar el CPU
        }
    }
    
    return 0;
}