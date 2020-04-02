// PROGRAMA p01a.c 

#include <stdio.h> 
#include <signal.h> 
#include <unistd.h> 
#include <stdlib.h> 

//if you press ctrl+c(send SIGINT) during sleep(30) he does int the handler and skips sleeping time
//to send sigusr1,while running this program, open other terminal, execute "ps u" to see process pid and then execute "kill -USR1 <pid>"

void sigint_handler(int signo) {   
    printf("In SIGINT handler ...\n"); 
}

void sigusr1_handler(int signo){
    printf("Sigusr1 handler \n");
}

int main(void) {   

    //struct sigaction a;
    //a.sa_handler=sigint_handler;
    //sigemptyset(&a.sa_mask);
    //a.sa_flags=0;


    //if(sigaction(SIGINT,&a,NULL)<0){
    if (signal(SIGINT,sigint_handler) < 0)   {
        fprintf(stderr,"Unable to install SIGINT handler\n");     
        exit(1);   
    }   
        
    printf("Sleeping for 10 seconds ...\n"); 

    int i =0;
    while((i=sleep(10))){
        sleep(i);
    } 


    printf("Waking up ...\n");   
    exit(0); 
} 