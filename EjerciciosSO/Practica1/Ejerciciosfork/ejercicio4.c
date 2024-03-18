/**************************************************************\
 Autor: Franco Heredia
 Practico: 4
 Objetivo: Escribir un buen encabezado.
 Fecha: ../../....
\**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid, status,hijo,padre;
    hijo = getpid();
    padre = getppid();
    pid = fork();
    
    if (pid == 0) {
        /* Proceso hijo */
        printf("Soy el proceso hijo: %d\n",hijo);
        exit(0); // Salir con un estado de salida arbitrario
    } else if (pid > 0) {
        /* Proceso padre */
        printf("Soy el proceso padre: %d. Esperando a que termine el proceso hijo...\n",padre);
        wait(&status); // Esperar a que termine el proceso hijo y obtener su estado de salida
        if (WIFEXITED(status)) {
            printf("El proceso hijo terminó con un estado de salida: %d\n", WEXITSTATUS(status));
        } else {
            printf("El proceso hijo terminó de forma anormal.\n");
        }
    } else {
        /* Manejo de error */
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}
