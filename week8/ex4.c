#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>
#include <time.h>
#include <sys/resource.h>

int main() {
    for(int i = 0; i < 10; i++){
        void *mem = malloc(1 << 20);
        mem = memset(mem, 0, 4);
        struct rusage info;
        getrusage(RUSAGE_SELF, &info);
        printf("%lu \n", info.ru_maxrss);
        sleep(1);
    }
}
