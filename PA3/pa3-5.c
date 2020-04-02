#include <unistd.h>  
#include <string.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h>

//pais ESPERAM pelos filhos

int main(void) {  
 
    pid_t pid,pid2;  

    pid=fork();  
    switch (pid) {          
        case -1:                               
            perror("fork"); 
            break;   

        case  0: //filho  (vai ter outro filho)
            pid2 =fork();

            if(pid2==0){
                printf("Hello");
            }else{
                wait(NULL);
                printf(" my ");
            }

            break;
        
        default: //pai   

            wait(NULL);
            printf("friends! \n");
            
            

    }  

    return 0; 
}