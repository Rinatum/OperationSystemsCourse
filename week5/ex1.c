#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

void *myThreadFun(void* arg){
    printf("Thread !!! %d\n", (int)arg);
    pthread_exit(0);
}

int main(int argc, char*argv[]){

    pthread_t threads[N];
    for(int i=0; i < N; i++) {
        pthread_create(&threads[i], NULL, myThreadFun, i);
        pthread_join(threads[i], NULL);
    }
    return 0;
}
