// PROGRAMA p02a.c 

#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

//if you press ctrl+c, it goes into the handler and sleeps. if you press ctrl+c during that sleep, when it exits the handler it goes back in again because we pressed ctrl+c and it didnt handle (ctrl+c waited to be handled in a "buffer")
//in another terminal, if you execute kill -TERM <pid>, it terminates the program even if it is sleeping (before adding SIGTERM handler)
//handler sigterm stop the sigterm from ending the program

void sigint_handler(int signo) {   
    printf("Entering SIGINT handler ...\n");   
    sleep(10);   
    printf("Exiting SIGINT handler ...\n");  
} 

void sigterm_handler(int sigterm){
    printf("Entering sigterm handler...\n");
    sleep(10);
    printf("Exiting sigterm handler...\n");
}

int main(void) {  
    struct sigaction action;  
    action.sa_handler = sigint_handler;  
    sigemptyset(&action.sa_mask);  
    action.sa_flags = 0;  
    
    if (sigaction(SIGINT,&action,NULL) < 0)  {
        fprintf(stderr,"Unable to install SIGINT handler\n");        
        exit(1);  
    }

    if(signal(SIGTERM,sigterm_handler)<0){
        fprintf(stderr,"Unable to install SIGTERM handler\n");        
        exit(1); 
    }
    
    printf("Try me with CTRL-C ...\n");  
    
    while(1) 
        pause(); 

    exit(0); 
    
}