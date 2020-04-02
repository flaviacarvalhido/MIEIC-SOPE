#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <stdbool.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


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

//father process sends signals to child randomly

int main(void) {  
    
    int var = 0;
    pid_t pid=fork();
    srand(time(0));
    
    if(pid==0){         //child process
        
        struct sigaction action; 
        action.sa_handler = sigusr_handler;   
        sigemptyset(&action.sa_mask);   
        action.sa_flags = 0;

        sigaction(SIGUSR1,&action,NULL);
        sigaction(SIGUSR2,&action,NULL);
        
        while(true){
            pause(); //waits for signal

            if(usr1){
                var=var+1;
                usr1=true;
                usr2=false;
            }else if(usr2){
                var=var-1;
                usr1=false;
                usr2=true;
            }

            printf("%d \n",var);
        }

    }else{          //father process
        printf("x");
        for(int i=0;i<50;i++){
            (rand() % 2 == 0) ? kill(pid, SIGUSR1) : kill(pid, SIGUSR2);
            sleep(1);       //sends one signal per second
        }
        kill(pid,SIGTERM);
    }
    
    exit(0);
    
}