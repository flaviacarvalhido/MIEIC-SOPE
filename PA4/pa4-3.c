#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdbool.h> 

bool usr1=true, usr2=false;

void sigusr_handler(int signo) {
    if(signo == SIGUSR1){
        usr1=true;
        usr2=false;
    }
    if(signo == SIGUSR2){
        usr1=false;
        usr2=true;
    }
}

//send signal SIGUSR1 or SIGUSR2 to process using kill -USR1 [PID] or kill -USR2 [PID](ver pid usando ps u)

int main(void) {  
    
    int var = 0;
    

    while(true){


        printf("%d \n",var);
        sleep(1);

        signal(SIGUSR1,sigusr_handler);
        signal(SIGUSR2,sigusr_handler);

        if(usr1){
            var=var+1;
            usr1=true;
            usr2=false;
        }else if(usr2){
            var=var-1;
            usr1=false;
            usr2=true;
        }
        
    }
    exit(0);
    
}