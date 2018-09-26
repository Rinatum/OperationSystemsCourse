#include <signal.h>
#include <printf.h>
#include <zconf.h>
#include <mach/boolean.h>

//
// Created by Ринат Муллахметов on 26/09/2018.
//
void handle_sigkill(int sig){
    printf("Process has been killed %d \n",sig);
}

void handle_sigstop(int sig){
    printf("Process has been stopped %d \n",sig);
}

void handle_sigusr1(int sig){
    printf("Received SIGUSR1 signal %d \n",sig);
}
int main(void){
    signal(SIGKILL, handle_sigkill);
    signal(SIGSTOP, handle_sigstop);
    signal(SIGUSR1, handle_sigusr1);
    while (TRUE);
}