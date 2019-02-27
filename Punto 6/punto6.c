#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <wait.h>

int main() {

	int pid_h, pid_n;
	int status_h, status_n;

   	printf("Hola ");
   	fflush(stdout);
   	

   	pid_h = fork();

  	if(pid_h == 0) {
    	
    	printf("Mundo");
    	fflush(stdout);
    	

    	pid_n = fork();

    	if(pid_n==0) {
      	printf("!\n");
      	fflush(stdout); 
      	    
    	}else{
      		wait(&status_n); 
    	}
	}else{
		wait(&status_h);
	}

  return 0;
}