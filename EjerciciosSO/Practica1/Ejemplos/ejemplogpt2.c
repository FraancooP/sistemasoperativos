#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int pid, status;
    
    pid = fork();
    
    if (pid == 0) {
        // Código ejecutado por el proceso hijo
        printf("Soy el proceso hijo %d.\n",pid);
	wait(&status);
	printf("ESTADO: %d\n",status);
    } else if (pid > 0) {
        // Código ejecutado por el proceso padre
        printf("Soy el proceso padre %d.\n",pid);
        wait(&status); // Espera a que el proceso hijo termine
        printf("El proceso hijo ha terminado.\n");
	printf("ESTADO %d\n",status);
    } else {
        // Manejo de error
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}
