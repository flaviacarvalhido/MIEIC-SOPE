// PROGRAMA p04a.c

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h> 


int main(void) {   
    pid_t pid;   
    int i, n;   
    
    for (i=1; i<=3; i++) {     
        pid=fork(); 
        
        if (pid == 0){       
            printf("CHILD no. %d (PID=%d) working ... \n",i,getpid());       
            //sleep(i*7); // child working ... 

            sleep(15); //5b      
            printf("CHILD no. %d (PID=%d) exiting ... \n",i,getpid());        
            exit(0);     
        }   
    }   
    
    for (i=1 ;i<=4; i++ ) {      
        printf("PARENT: working hard (task no. %d) ...\n",i);     
        n=20; 

        signal(SIGCHLD,SIG_IGN);//ignore sigchld as the child processes die!

        while((n=sleep(n))!=0){}

        printf("PARENT: end of task no. %d\n",i);     
        printf("PARENT: waiting for child no. %d ...\n",i);     
        
        


    }   
    
    exit(0); 
}