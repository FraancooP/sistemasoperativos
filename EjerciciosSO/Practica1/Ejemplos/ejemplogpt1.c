#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, num = 10;
    
    pid = fork();
    
    if (pid == 0) {
        // Código ejecutado por el proceso hijo
        printf("Soy el proceso hijo %d. Calculando el cuadrado de %d: %d\n",pid , num, num * num);
    } else if (pid > 0) {
        // Código ejecutado por el proceso padre
        printf("Soy el proceso padre %d. Calculando el cubo de %d: %d\n",pid , num, num * num * num);
    } else {
        // Manejo de error
        perror("Error en fork");
        return 1;
    }
    
    return 0;
}

