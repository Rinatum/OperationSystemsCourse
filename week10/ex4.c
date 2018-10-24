//
// Created by Ринат Муллахметов on 24/10/2018.
//
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <printf.h>
#include <stdlib.h>

int main() {

    DIR *dirp = opendir("tmp");
    struct dirent *dp;
    int size = 0;
    while ((dp = readdir(dirp)) != NULL) {
        size++;
    }
    closedir(dirp);
    dirp = opendir("tmp");
    struct dirent **arr = malloc(size * sizeof(struct dirent));
    bool mask[size];
    int index = 0;
    while ((dp = readdir(dirp)) != NULL) {
        arr[index++] = dp;
        mask[index] = false;
    }

    for (int i = 0; i < size; i++) {
        if (mask[i])
            continue;

        mask[i] = true;
        int count = 1;
        for (int j = i; j < size; j++) {
            if (arr[j]->d_ino == arr[i]->d_ino && !mask[j]) {
                printf("%s, ", arr[j]->d_name);
                mask[j] = true;
                count++;
            }
        }
        if (count > 1) {
            printf("%s -> ", arr[i]->d_name);
            printf("%llu \n", arr[i]->d_ino);
        }


    }
    return 0;
}
