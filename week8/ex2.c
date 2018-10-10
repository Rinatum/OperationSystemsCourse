#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mach/boolean.h>
#include <zconf.h>

int main() {
    for(int i = 0; i < 10; i++){
        void *mem = malloc(1 << 20);
        mem = memset(mem, 0, 4);
        sleep(1);
    }
}
