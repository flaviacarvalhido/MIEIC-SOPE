//FOLHA 2 - p3a.c
//FILE COPY
//USAGE: copy source destination


//3b) não funciona


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
 int fd1, fd2, nr;
 unsigned char buffer[BUFFER_SIZE];


 fd1 = open(argv[1], O_RDONLY);
 
 if (fd1 == -1) {
  perror(argv[1]);
  return 2;
 }

 if(argc==3){
    fd2 = open(argv[2], O_WRONLY | O_EXCL, 0644);
 }

 //se não havia segundo argumento, escreve na consola
 while ((nr = read(fd1, buffer, BUFFER_SIZE)) > 0){
    //se tiver dois argumentos, redireciona a escrita na consola para o segundo ficheiro usando dup2()
    if(argc == 3){
        dup2(fd2,STDOUT_FILENO);
        write(fd2,buffer,nr);
        continue;
    }else{
        write(STDOUT_FILENO,buffer,nr);
    }
 }
 

 close(fd1);
 return 0;
}