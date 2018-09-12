#include <stdio.h>
#include <stdlib.h>
#include <mach/boolean.h>
#include <string.h>

int open_console(){
    char command[8];
    while (TRUE){
        printf("=) : ");
        scanf("%s", command);
        if (strcmp(command, "close") == 0){
            return 0;
        } else
            system(command);
    }
}
int main(void) {
    open_console();
    return 0;
}
