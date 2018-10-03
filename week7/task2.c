//
// Created by Ринат Муллахметов on 03/10/2018.
//

#include <printf.h>
#include <stdlib.h>

int main(){
    int n;

    printf( "Enter a value :");
    scanf("%d",&n);
    int *array = calloc(n, sizeof(int));;
    for (int i = 0; i < n; i++){
        array[i] = i;
    }

    for (int i = 0; i < n; i++){
        printf("%d", array[i]);
    }

    free(array);
    return 0;
}