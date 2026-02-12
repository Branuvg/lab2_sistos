#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    for (int i = 0; i < 4; i++) {
        fork();
    }

    printf("Proceso PID: %d, Padre PID: %d\n", getpid(), getppid());

    sleep(1);
    return 0;
}