#include <stdio.h>
#include <stdlib.h>
#include <mach/boolean.h>
#include <string.h>

int open_console(){
    char command[50];
    while(1) {
        printf("=) : ");
        fgets(command, 50, stdin);
        system(command);
    }

}
int main(void) {
    open_console();
    return 0;
}
