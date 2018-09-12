#include <stdio.h>
#include <zconf.h>
#include <unistd.h>
//
// Created by Ринат Муллахметов on 12/09/2018.
//
int main(){
    int n = 66;
    int pid = getpid();
    fork();
    if (pid == getpid())
        printf("Hello from parent %d\n", (pid - n));
    else
        printf("Hello from child %d\n", (getpid() - n));
    return 0;
}

