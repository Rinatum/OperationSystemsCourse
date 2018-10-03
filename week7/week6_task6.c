#include <zconf.h>
#include <printf.h>
#include <mach/boolean.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void){
    pid_t   childpid1, childpid2;
    int fd[2];
    pipe(fd);
    printf("Main process creates 2 child processes\n");
    childpid1 = fork();
    if (childpid1){
        childpid2 = fork();
        if (childpid2){
            printf("Main process sends pid of 2nd process to 1st process and waits for changes in 2nd process status\n");
            close(fd[0]);
            write(fd[1], &childpid2, sizeof(childpid2));
            close(fd[1]);
            int status;
            waitpid(childpid2, &status, 0);
            printf("Main process gets status %d from 2nd process \n", status);


        } else {
            close(fd[1]);
            close(fd[0]);
            printf("2nd process exits with status 0\n");
        }
    }
    else {
            printf("1st process waits 2 seconds...\n");
            int buffer;
            printf("1st process reads 2 process pid and stops it...\n");
            close(fd[1]);
            read(fd[0], &buffer, sizeof(buffer));
            printf("1st process gets pid %d from 2nd process\n", buffer);
            kill(buffer, SIGKILL);
            close(fd[0]);
        }
    }


