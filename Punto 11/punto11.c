#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>


int factorial(int n);

int main() {

	pid_t pid_1, pid_2, pid_3;
	int status_1, status_2, status_3;

	pid_1 = fork();

	if(pid_1 == 0){
		for(int i = 1; i <= 10; i++){
			int fact1 = factorial(i);
			printf("HIJO 1: fact(%d) = %d\n", i, fact1);
		}
	}else{
		wait(&status_1);
		pid_2 = fork();
		if(pid_2 == 0){
			for(int j = 1; j <= 10; j++){
				int fact2 = factorial(j);
				printf("HIJO 2: fact(%d) = %d\n", j, fact2);
			}
		}else{
			wait(&status_2);
			pid_3 = fork();
			if(pid_3 == 0){
				for(int k = 1; k <= 10; k++){
					int fact3 = factorial(k);
					printf("HIJO 3: fact(%d) = %d\n", k, fact3);
				}
			}else{
				wait(&status_3);
			}

		}
	}

	return 0;
}

int factorial(int n)
{
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}