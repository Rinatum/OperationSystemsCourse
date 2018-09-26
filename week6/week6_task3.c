#include <mach/boolean.h>
#include <printf.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int sig)
{
    printf("User just has pressed Cntrl_C %d\n", sig);
    exit(0);
}
int main(void){
    signal(SIGINT, handle_sigint);
    while (TRUE) ;
    return 0;
}
