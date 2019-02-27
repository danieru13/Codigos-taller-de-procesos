#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main () {
  pid_t pid_hijo1; 
  pid_t pid_hijo2; 
  pid_t pid_hijo3;
  int status_h1, status_h2, status_h3;

    pid_hijo1 = fork(); // Creo el primer hijo
    if (pid_hijo1 == 0) { // Hijo 1
      printf("Soy el hijo 1\n");
      
    } else {  // Padre
        wait(&status_h1); // Papa esperando un hijo
        pid_hijo2 = fork(); // Creo al segundo hijo
        if (pid_hijo2 == 0) { // Hijo 2
          printf("Soy el hijo 2\n");
          
        } else {  // Padre
            wait(&status_h2); // Papa esperando otro hijo
            pid_hijo3 = fork();  // Creo al tercer hijo
            if (pid_hijo3 == 0) { // Hijo 3
              printf("Soy el hijo 3\n");
              
            } else {  // Padre
         
         wait(&status_h3); // Papa esperando el ultimo hijo

         printf("Soy el padre\n");
         
       }
     }
   }


   return 0;
 }