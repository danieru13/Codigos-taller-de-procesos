#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main() {

	pid_t pid_hijo;
	//int status;
	char programa[50];

	printf("Introduzca el nombre del programa a ejecutar: ");
	scanf("%s", programa);

	printf("Ejecutando %s\n",programa);

	pid_hijo = fork();

	if(pid_hijo == 0){
		execlp(programa , " ", NULL);
		exit(0);
	}
	return 0;

}