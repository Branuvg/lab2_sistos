#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    fork();
    fork();
    fork();
    fork();

    // Este mensaje se imprimirá 16 veces
    printf("Proceso PID: %d, Padre PID: %d\n", getpid(), getppid());
    
    // Pausa breve para que el sistema no mezcle los outputs inmediatamente
    sleep(1); 
    return 0;
}