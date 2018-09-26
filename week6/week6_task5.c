#include <zconf.h>
#include <printf.h>
#include <mach/boolean.h>
#include <signal.h>

int main(void){
    pid_t   childpid;
    childpid = fork();
    if (childpid){
        sleep(10);
        kill(childpid, SIGTERM);
    }
    else{
        while(TRUE) {
            printf("I'm alive!!!");
            fflush(stdout);
            sleep(1);
        }
    }

}

