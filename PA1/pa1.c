#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])  { //recebe todos os nomes e um n no fim para repetir o print n vezes
    
    char name[100];
    int number=1;

    for(int i =1; i<argc-1;i++){ //indice 0 é o nome do programa!!
        strcat(name, " ");
        strcat(name, argv[i]);
        
        number++;
    }  
    for(int j =0; j<atoi(argv[number]);j++){
        printf("Hello%s!\n",name);   
    }
    return 0; 
}