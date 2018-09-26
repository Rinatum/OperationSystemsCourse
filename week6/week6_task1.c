#include <zconf.h>
#include <string.h>
#include <printf.h>

int main(void){
    int fd[2];
    char str[] = "Kukarekuu\n";
    char buffer[20];
    pipe(fd);
    write(fd[1], str, strlen(str) + 1);
    close(fd[1]);
    read(fd[0], buffer, sizeof(buffer));
    close(fd[0]);
    printf(buffer);
}