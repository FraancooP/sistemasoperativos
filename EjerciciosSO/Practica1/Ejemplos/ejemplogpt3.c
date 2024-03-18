#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int signum) {
    printf("Se alcanzó el tiempo límite de ejecución.\n");
    exit(0);
}

int main() {
    int pid,status;
    
    signal(SIGALRM, handler); // Configurar el manejador de la señal de alarma
    
    pid = fork();
    
    if (pid == 0) {
	printf("Soy el hijo %d\n",pid);
        // Código ejecutado por el proceso hijo
        alarm(5); // Establecer una alarma de 5 segundos
        while (1) {} // Ciclo infinito para simular trabajo
    } else if (pid > 0) {
        // Código ejecutado por el proceso padre
        printf("Soy el proceso padre %d.\n",pid);
        wait(status); // Esperar a que el proceso hijo termine
        printf("El proceso hijo ha terminado.\n");
    } else {
        // Manejo de error
        perror("Error en fork");
        return 1;
    }
   //Usar ps aux | grep nombre_del_programa para verificar el tiempo. 
    return 0;
}
