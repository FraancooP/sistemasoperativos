#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int hijo;
    hijo = getpid();
    while (1) {
        printf("HOLA, HIJO: %d \n",hijo);
	exit(123);
    }
    return 0;
}
