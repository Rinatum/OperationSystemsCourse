#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <mach/boolean.h>
#include <zconf.h>

#define N 1000

time_t start;

int count = 0;
pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;

int produce_item(){
    return 1;
}

void insert_item(int item){
    printf("Item insertion");
}
void* producer(void* arg) {
    int item;
    while (TRUE) {
        pthread_mutex_lock(&the_mutex);
        item = produce_item();
        if (count == N) {
            pthread_cond_wait(&condp, &the_mutex);
        }
        insert_item(item);
        count = count + 1;
        if (count == 1){
            pthread_cond_signal(&condc);
            pthread_mutex_unlock(&the_mutex);
        }
    }
}

int remove_item(){
    return 1;
}

void consume_item(int item){
    printf("Item consumption");
}

void* consumer(void* arg) {
    int item;
    while (TRUE) {
//        if (count == 0) pthread_cond_wait();
//        item = remove_item();
//        count = count - 1;
//        if (count == N - 1) wakeup(producer);
//        consume_item(item);
        pthread_mutex_lock(&the_mutex);
        if (count == 0){
            pthread_cond_wait(&condc, &the_mutex);
        }
        consume_item(item);
        count--;
        if (count == N - 1){
            pthread_cond_signal(&condp);
            pthread_mutex_unlock(&the_mutex);
        }
    }
}


int main(int argc, char const *argv[]){
    start = time(NULL);
    pthread_t pro, con;
    pthread_mutex_init(&the_mutex, 0);
    pthread_cond_init(&condc, 0);
    pthread_cond_init(&condp, 0);
    pthread_create(&con, 0, consumer, 0);
    pthread_create(&pro, 0, producer, 0);
    pthread_join(pro, 0);
    pthread_join(con, 0);
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&the_mutex);
    return 0;

}
