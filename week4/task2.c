#include <stdio.h>
#include <zconf.h>
#include <unistd.h>
//
// Created by Ринат Муллахметов on 12/09/2018.
//
int main(){
    for(int i = 0; i < 3; i++) {
        fork();
        sleep(5);
    }
    return 0;
}


