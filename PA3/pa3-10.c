// PROGRAMA p10.c 

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[]) {
    pid_t pid; 
    int status=0,fd; 

    if (argc == 2) {      

        pid=fork();    
        if (pid > 0) {     
            printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);  

            sleep(2);

            waitpid(pid,&status,WNOHANG);

            printf("My child terminated with %d exit code\n",WEXITSTATUS(status));
            
            if(WIFSIGNALED(status)){
                printf("My child terminated with a signal...\n");
            }else{
                printf("My child terminated normally!\n");
            }

        } else if (pid == 0){      
            //execlp("ls","ls","-laR",argv[1],NULL);  //see how the arguments are called   

            //execl("/bin/ls","ls","-laR",argv[1],NULL);
            
            char *arg[]={"ls","-laR",argv[1],NULL}; 
            //execvp("ls",arg);
            
            //execv("/bin/ls",arg);

            execve("/bin/ls",arg,envp);  //envp=variaveis de ambiente
            
            printf("Command not executed !\n");      
            exit(1);    
        }    
    }
    else if(argc == 3){
        pid=fork();    
        if (pid > 0) {     
            printf("My child is going to execute command \"ls -laR %s\"\n", argv[1]);  

            sleep(2);

            waitpid(pid,&status,WNOHANG);

            printf("My child terminated with %d exit code\n",WEXITSTATUS(status));
            
            if(WIFSIGNALED(status)){
                printf("My child terminated with a signal...\n");
            }else{
                printf("My child terminated normally!\n");
            }

        } else if (pid == 0){   

            fd = open(argv[2], O_WRONLY | O_CREAT, 0644);



            //execlp("ls","ls","-laR",argv[1],NULL);  //see how the arguments are called   

            //execl("/bin/ls","ls","-laR",argv[1],NULL);
            
            char *arg[]={"ls","-laR",argv[1],NULL}; 
            //execvp("ls",arg);
            
            //execv("/bin/ls",arg);

            dup2(fd,STDOUT_FILENO);  //redirecionar output do exec para o fd (file dado pelo utilizador)

            execve("/bin/ls",arg,envp);  //envp=variaveis de ambiente
            
            printf("Command not executed !\n");      
            exit(1);    
        }    
    }
    exit(0); 
}