//FOLHA 2 - p4.c

//kinda weird

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

struct Student
{
    char* name[50];
    int grade;
};


int main(int argc, char *argv[]){
    struct Student st1,st2;

    printf("Write name of first student: ");
    scanf(st1.name);

    printf("Write first student's grade: ");
    scanf(st1.grade);

    printf("Write name of second student: ");
    scanf(st2.name);

    printf("Write second student's grade: ");
    scanf(st2.grade);

    return 0;
}
