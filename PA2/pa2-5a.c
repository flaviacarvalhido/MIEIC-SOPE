// PROGRAMA p5a.c

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int main(void) {
   int fd;   
   char *text1="AAAAA";   
   char *text2="BBBBB";   

   //ATENÇÃO ÁS CONDIÇÕES DOS IFS!!!!!!

   if((fd = open("f1.txt",O_EXCL|O_TRUNC|O_WRONLY|O_SYNC,0600)) == -1){
       return 1;
   }

   if( write(fd,text1,5)<=0 || write(fd,text2,5) <= 0){
       close(fd); 
       return 2;
   } 

   close(fd);   
   return 0;      
}