#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int     fd[2];
    pid_t   childpid;
    char    str[] = "Kukarekuu!\n";
    char    buffer[30];
    pipe(fd);
    childpid = fork();
    if(childpid < 0) {
        perror("fork error");
        exit(1);
    }

    if(childpid != 0) {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        close(fd[0]);
        printf("Received string: %s", buffer);
    }
    else {
        close(fd[0]);
        write(fd[1], str, (strlen(str)+1));
        close(fd[1]);
        exit(0);
    }
    return(0);
}