// PROGRAMA p2.c 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {  
    printf("1\n");  //o \n limpa o 1 do buffer (buffer partilhado entre pai e filho)
    if(fork() > 0) {    
        printf("2");    
        printf("3");  
    } else {    
        printf("4");    
        printf("5");  
    }  
    printf("\n");  
    return 0;
}
