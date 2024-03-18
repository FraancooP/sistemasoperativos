/**************************************************************\
 Autor: Franco Heredia
 Practico: 3
 Objetivo: Escribir un buen encabezado.
 Fecha: ../../....
\**************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int pid;
    
    pid = fork();
    
    if (pid == 0) {
        /* Proceso hijo */
        printf("Soy el proceso hijo. Mi PID es %d y el PID de mi padre es %d ESO ES FORK EN HIJO %d\n", getpid(), getppid() , pid);
    } else if (pid > 0) {
        /* Proceso padre */
        printf("Soy el proceso padre. Mi PID es %d y el PID de mi hijo es %d ESTO ES FORK EN PADRE %d\n", getpid(), pid, pid);
    } else {
        /* Manejo de error */
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}
