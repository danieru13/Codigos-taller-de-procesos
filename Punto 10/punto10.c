#include <syscall.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

#include <string.h>

void tree();

int main() {

	pid_t pid_2, pid_3, pid_4, pid_5;
	int status_2, status_3, status_4, status_5;


  printf("Padre: Mi PID: %d\n",(int)getpid());
  printf("Padre: PID de mi padre: %d\n",(int)getppid());
  printf("\n");
    
   	

  pid_2 = fork();    

  if(pid_2 == 0) {
    	
  printf("Creación de proceso 2 satisfactoria\n");

  printf("Hijo: Mi PID: %d\n",(int)getpid());
  printf("Hijo: PID del padre: %d\n",(int)getppid());
  printf("\n");
  }else{

    wait(&status_2);
    pid_3 = fork();

    if(pid_3 == 0) {

      printf("Creación de proceso 3 satisfactoria\n");

      printf("Hijo: Mi PID: %d\n",(int)getpid());
      printf("Hijo: PID del padre: %d\n",(int)getppid());
      printf("\n");
      
      pid_4 = fork();

      if(pid_4 == 0){

        printf("Creación de proceso 4 satisfactoria\n");

        printf("Hijo: Mi PID: %d\n",(int)getpid());
        printf("Hijo: PID del padre: %d\n",(int)getppid());
        printf("\n");
        
        
      }else{
        wait(&status_4);
        pid_5 = fork();

        if(pid_5 == 0){

          printf("Creación de proceso 5 satisfactoria\n");

          printf("Hijo: Mi PID: %d\n",(int)getpid());
          printf("Hijo: PID del padre: %d\n",(int)getppid());
          printf("\n");
        
          
        }else{
          wait(&status_5);
        }
      }
    }else{

      tree();
      wait(&status_3);
      
    }    
  }
  return 0;
}


//función que llama a pstree a partir del pid()
void tree(){
  const char base[] = "pstree "; 
    char command[50];
    long id = getpid();

    sprintf(command, "%s%ld", base, id);

    system(command);

}
