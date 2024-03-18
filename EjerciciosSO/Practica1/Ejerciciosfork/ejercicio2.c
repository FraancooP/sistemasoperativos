/**************************************************************\
 Autor Franco Heredia
 Practico: 2
 Objetivo: Escribir un buen encabezado.
 Fecha: ../../....
\**************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	int pid;
	pid = fork();
	if(pid==0){
		//Hijo
		printf("Este es el hijo %d\n",pid);
	}else{
		printf("Este es el padre %d\n",pid);
		//Padre
	}
	return 0;
}
