#include <unistd.h>  
#include <string.h> 
#include <stdio.h> 
#include <sys/types.h> 



int main(void) {  
 
    pid_t pid;  

    pid=fork();  
    switch (pid) {          
        case -1:                               
            perror("fork"); 
            break;   

        case  0: //filho  

            //alinea a) 1-filho 2-pai             
            //printf("Hello ");                              
            //break;   

            //alinea b) 1-pai 2-filho
            printf("world!\n");
            break;
        
        default: //pai   

            //alinea a) 1-filho 2-pai
            //sleep(1);            
            //printf("world! \n"); 

            //alinea b) 1-pai 2-filho
            printf("Hello ");
            

    }  

    return 0; 
}